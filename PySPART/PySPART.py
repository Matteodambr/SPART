import matlab.engine
import numpy as np
import ctypes
import os

# ---------------------------------------------------------------------------
# MATLAB engine (lazy-started on first use)
# ---------------------------------------------------------------------------
_engine = None

def _get_engine():
    """Return the shared MATLAB engine, starting it if necessary."""
    global _engine
    if _engine is None:
        _engine = matlab.engine.start_matlab()
        # Add the SPART source tree to the MATLAB path
        spart_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
        _engine.addpath(_engine.genpath(spart_root), nargout=0)
    return _engine


# ---------------------------------------------------------------------------
# Data classes
# ---------------------------------------------------------------------------

class JointData:
    """Mirrors struct0_T from SPART_C_types.h"""
    __slots__ = ('id', 'type', 'q_id', 'parent_link', 'child_link', 'axis', 'T')

    def __init__(self, id, type, q_id, parent_link, child_link, axis, T):
        self.id          = float(id)
        self.type        = float(type)
        self.q_id        = float(q_id)
        self.parent_link = float(parent_link)
        self.child_link  = float(child_link)
        self.axis        = np.asarray(axis, dtype=np.float64).flatten()   # (3,)
        self.T           = np.asarray(T,    dtype=np.float64, order='F')  # (4,4) col-major

    def __repr__(self):
        return (f"JointData(id={self.id}, type={self.type}, q_id={self.q_id}, "
                f"parent_link={self.parent_link}, child_link={self.child_link})")


class LinkData:
    """Mirrors struct1_T from SPART_C_types.h"""
    __slots__ = ('id', 'parent_joint', 'T', 'mass', 'inertia')

    def __init__(self, id, parent_joint, T, mass, inertia):
        self.id           = float(id)
        self.parent_joint = float(parent_joint)
        self.T            = np.asarray(T,       dtype=np.float64, order='F')  # (4,4)
        self.mass         = float(mass)
        self.inertia      = np.asarray(inertia, dtype=np.float64, order='F')  # (3,3)

    def __repr__(self):
        return (f"LinkData(id={self.id}, parent_joint={self.parent_joint}, "
                f"mass={self.mass})")


class RobotModel:
    """Python equivalent of the SPART robot structure."""
    __slots__ = ('name', 'n_q', 'n_links_joints', 'joints', 'links',
                 'con_branch', 'con_child', 'con_child_base',
                 'base_link_mass', 'base_link_inertia')

    def __init__(self, name, n_q, n_links_joints, joints, links,
                 con_branch, con_child, con_child_base,
                 base_link_mass, base_link_inertia):
        self.name               = name
        self.n_q                = int(n_q)
        self.n_links_joints     = int(n_links_joints)
        self.joints             = joints    # list of JointData
        self.links              = links     # list of LinkData
        self.con_branch         = np.asarray(con_branch,     dtype=np.float64)  # (n, n)
        self.con_child          = np.asarray(con_child,      dtype=np.float64)  # (n, n)
        self.con_child_base     = np.asarray(con_child_base, dtype=np.float64).flatten()  # (n,)
        self.base_link_mass     = float(base_link_mass)
        self.base_link_inertia  = np.asarray(base_link_inertia, dtype=np.float64, order='F').reshape(3, 3, order='F')

    def __repr__(self):
        return (f"RobotModel(name='{self.name}', n_q={self.n_q}, "
                f"n_links_joints={self.n_links_joints})")


# ---------------------------------------------------------------------------
# ctypes layout for SPART_C.so
# ---------------------------------------------------------------------------

class _CJoint(ctypes.Structure):         # struct0_T
    _fields_ = [
        ('id',          ctypes.c_double),
        ('type',        ctypes.c_double),
        ('q_id',        ctypes.c_double),
        ('parent_link', ctypes.c_double),
        ('child_link',  ctypes.c_double),
        ('axis',        ctypes.c_double * 3),
        ('T',           ctypes.c_double * 16),   # 4x4 col-major
    ]

class _CLink(ctypes.Structure):          # struct1_T
    _fields_ = [
        ('id',           ctypes.c_double),
        ('parent_joint', ctypes.c_double),
        ('T',            ctypes.c_double * 16),  # 4x4 col-major
        ('mass',         ctypes.c_double),
        ('inertia',      ctypes.c_double * 9),   # 3x3 col-major
    ]

class _CCellWrap1(ctypes.Structure):     # cell_wrap_1  — 6×6 matrix (f1[36] col-major)
    _fields_ = [('f1', ctypes.c_double * 36)]

class _CCellWrap2(ctypes.Structure):     # cell_wrap_2  — 3×3 matrix (f1[9] col-major)
    _fields_ = [('f1', ctypes.c_double * 9)]

class _CBaseLink(ctypes.Structure):      # struct2_T
    _fields_ = [
        ('mass',    ctypes.c_double),
        ('inertia', ctypes.c_double * 9),   # 3×3 col-major
    ]

class _EmxReal(ctypes.Structure):        # emxArray_real_T
    _fields_ = [
        ('data',          ctypes.POINTER(ctypes.c_double)),
        ('size',          ctypes.POINTER(ctypes.c_int32)),
        ('allocatedSize', ctypes.c_int32),
        ('numDimensions', ctypes.c_int32),
        ('canFreeData',   ctypes.c_uint8),
    ]

class _EmxCellWrap1(ctypes.Structure):   # emxArray_cell_wrap_1
    _fields_ = [
        ('data',          ctypes.POINTER(_CCellWrap1)),
        ('size',          ctypes.POINTER(ctypes.c_int32)),
        ('allocatedSize', ctypes.c_int32),
        ('numDimensions', ctypes.c_int32),
        ('canFreeData',   ctypes.c_uint8),
    ]

class _EmxCellWrap2(ctypes.Structure):   # emxArray_cell_wrap_2
    _fields_ = [
        ('data',          ctypes.POINTER(_CCellWrap2)),
        ('size',          ctypes.POINTER(ctypes.c_int32)),
        ('allocatedSize', ctypes.c_int32),
        ('numDimensions', ctypes.c_int32),
        ('canFreeData',   ctypes.c_uint8),
    ]

_CODEGEN_ROOT = os.path.join(
    os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
    'codegen', 'dll'
)

# ---------------------------------------------------------------------------
# Preload Intel OpenMP runtime (libiomp5.so) required by MATLAB Coder .so
# ---------------------------------------------------------------------------
_LIBIOMP5_CANDIDATES = [
    # MATLAB installations — prefer newest first
    '/usr/local/MATLAB/R2025a/sys/os/glnxa64/libiomp5.so',
    '/usr/local/MATLAB/R2024b/sys/os/glnxa64/libiomp5.so',
    '/usr/local/MATLAB/R2024a/sys/os/glnxa64/libiomp5.so',
    '/usr/local/MATLAB/R2023b/sys/os/glnxa64/libiomp5.so',
    # System / Intel MKL paths
    '/usr/lib/x86_64-linux-gnu/libiomp5.so',
    '/usr/lib/libiomp5.so',
    '/usr/local/lib/libiomp5.so',
]

def _preload_libiomp5():
    """Load libiomp5.so with RTLD_GLOBAL so that SPART_C.so can resolve it."""
    # Also search Anaconda environments
    candidates = list(_LIBIOMP5_CANDIDATES)
    for root in [os.environ.get('CONDA_PREFIX', ''), os.path.expanduser('~')]:
        if root:
            candidates.append(os.path.join(root, 'lib', 'libiomp5.so'))

    for path in candidates:
        if os.path.isfile(path):
            try:
                ctypes.CDLL(path, mode=ctypes.RTLD_GLOBAL)
                return path
            except OSError:
                continue
    raise OSError(
        "libiomp5.so not found. Add its directory to LD_LIBRARY_PATH or install "
        "Intel OpenMP (e.g. `conda install -c intel openmp`)."
    )

_preload_libiomp5()

# Cache of loaded libraries: {so_path: ctypes.CDLL}
_libs = {}


def _find_matlab_include(src_dir):
    """
    Return the path to MATLAB's extern/include directory, or None if not found.

    Search order:
    1. MATLAB_ROOT environment variable
    2. MATLAB_ROOT value parsed from SPART_C_rtw.mk (generated at Coder time)
    3. Common installation prefixes (/usr/local/MATLAB/R*, /opt/matlab/R*)
    """
    import glob, re

    candidates = []

    # 1. Env var
    env_root = os.environ.get('MATLAB_ROOT', '')
    if env_root:
        candidates.append(os.path.join(env_root, 'extern', 'include'))

    # 2. Parse .mk file
    mk = os.path.join(src_dir, 'SPART_C_rtw.mk')
    if os.path.isfile(mk):
        with open(mk) as fh:
            for line in fh:
                m = re.match(r'MATLAB_ROOT\s*=\s*(.+)', line)
                if m:
                    candidates.append(os.path.join(m.group(1).strip(), 'extern', 'include'))
                    break

    # 3. Common prefixes
    for pattern in ['/usr/local/MATLAB/R*/extern/include',
                    '/opt/matlab/R*/extern/include',
                    os.path.expanduser('~/MATLAB/R*/extern/include')]:
        candidates.extend(sorted(glob.glob(pattern), reverse=True))  # newest first

    # 4. Local fallback — tmwtypes.h manually placed alongside the C sources
    candidates.append(src_dir)

    for path in candidates:
        if os.path.isfile(os.path.join(path, 'tmwtypes.h')):
            return path
    return None


def _build_spart_so(so_path):
    """
    Compile SPART_C.so from its bundled C sources using gcc.

    Called automatically when:
    - The .so file does not exist
    - The .so is older than any .c source file in the same directory
    - Loading the existing .so raises an OSError (e.g. wrong architecture)

    Requirements: gcc with OpenMP support (-fopenmp).  No MATLAB needed —
    all headers (including rtwtypes.h) are shipped alongside the .c files.
    """
    import subprocess, shutil

    src_dir = os.path.dirname(os.path.abspath(so_path))

    # Verify gcc is available
    if not shutil.which('gcc'):
        raise RuntimeError(
            "gcc not found on PATH.  Install gcc (e.g. `sudo apt install gcc`) "
            "to allow automatic rebuild of SPART_C.so."
        )

    c_sources = [f for f in os.listdir(src_dir) if f.endswith('.c')]
    if not c_sources:
        raise RuntimeError(f"No .c source files found in {src_dir}")

    # Locate MATLAB extern/include for tmwtypes.h (included by rtwtypes.h)
    matlab_inc = _find_matlab_include(src_dir)
    if matlab_inc and matlab_inc != src_dir:
        # Cache tmwtypes.h locally so future rebuilds work without MATLAB
        local_copy = os.path.join(src_dir, 'tmwtypes.h')
        if not os.path.isfile(local_copy):
            import shutil as _shutil
            _shutil.copy2(os.path.join(matlab_inc, 'tmwtypes.h'), local_copy)
    extra_inc = [f'-I{matlab_inc}'] if matlab_inc and matlab_inc != src_dir else []
    if not matlab_inc:
        import warnings
        warnings.warn(
            "MATLAB extern/include not found and no local tmwtypes.h present; "
            "build may fail.  Set MATLAB_ROOT env var, or copy tmwtypes.h from "
            "MATLAB's extern/include into codegen/dll/SPART_C/.",
            RuntimeWarning, stacklevel=3
        )

    cmd = (
        ['gcc', '-shared', '-fPIC', '-fopenmp', '-O2',
         '-msse2', '-fwrapv', '-fno-predictive-commoning',
         f'-I{src_dir}'] + extra_inc
        + ['-o', so_path]
        + [os.path.join(src_dir, f) for f in c_sources]
        + ['-lm']
    )

    print(f"[PySPART] Building SPART_C.so from source in {src_dir} …")
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        raise RuntimeError(
            f"SPART_C.so build failed (exit {result.returncode}):\n"
            f"{result.stderr.strip()}"
        )
    print("[PySPART] Build succeeded.")


def _so_needs_rebuild(so_path):
    """Return True if the .so is missing or older than any .c source."""
    if not os.path.isfile(so_path):
        return True
    so_mtime = os.path.getmtime(so_path)
    src_dir  = os.path.dirname(os.path.abspath(so_path))
    for fname in os.listdir(src_dir):
        if fname.endswith('.c'):
            if os.path.getmtime(os.path.join(src_dir, fname)) > so_mtime:
                return True
    return False


def _load_so(so_path, init_fn, fn_name, fn_argtypes):
    """
    Load a MATLAB Coder-generated shared library (once) and register its symbols.

    Parameters
    ----------
    so_path    : absolute path to the .so file
    init_fn    : name of the initialise function  (e.g. 'SPART_C_initialize')
    fn_name    : name of the main C function      (e.g. 'Kinematics_C')
    fn_argtypes: list of ctypes argument types for fn_name

    Returns
    -------
    The loaded ctypes.CDLL instance.
    """
    if so_path in _libs:
        return _libs[so_path]

    # Rebuild if missing or sources are newer
    if _so_needs_rebuild(so_path):
        _build_spart_so(so_path)

    # Load — if it fails (e.g. wrong arch on a fresh checkout), rebuild and retry
    try:
        lib = ctypes.CDLL(so_path)
    except OSError as exc:
        print(f"[PySPART] Failed to load {so_path} ({exc}); attempting rebuild …")
        _build_spart_so(so_path)
        lib = ctypes.CDLL(so_path)

    getattr(lib, init_fn)()

    # --- emxAPI — present in every MATLAB Coder C library ---
    _p  = ctypes.c_void_p
    _pd = ctypes.POINTER(ctypes.c_double)
    _i  = ctypes.c_int
    lib.emxCreateWrapper_real_T.restype     = _p
    lib.emxCreateWrapper_real_T.argtypes    = [_pd, _i, _i]
    lib.emxCreateWrapper_struct0_T.restype  = _p
    lib.emxCreateWrapper_struct0_T.argtypes = [_p, _i, _i]
    lib.emxCreateWrapper_struct1_T.restype  = _p
    lib.emxCreateWrapper_struct1_T.argtypes = [_p, _i, _i]
    lib.emxCreate_real_T.restype            = _p
    lib.emxCreate_real_T.argtypes           = [_i, _i]
    lib.emxDestroyArray_real_T.restype      = None
    lib.emxDestroyArray_real_T.argtypes     = [_p]
    lib.emxDestroyArray_struct0_T.restype   = None
    lib.emxDestroyArray_struct0_T.argtypes  = [_p]
    lib.emxDestroyArray_struct1_T.restype   = None
    lib.emxDestroyArray_struct1_T.argtypes  = [_p]

    # --- cell_wrap emxAPI ---
    lib.emxCreateWrapper_cell_wrap_1.restype     = _p
    lib.emxCreateWrapper_cell_wrap_1.argtypes    = [_p, _i, _i]
    lib.emxCreateWrapper_cell_wrap_2.restype     = _p
    lib.emxCreateWrapper_cell_wrap_2.argtypes    = [_p, _i, _i]
    lib.emxCreateWrapperND_cell_wrap_1.restype   = _p
    lib.emxCreateWrapperND_cell_wrap_1.argtypes  = [_p, _i, ctypes.POINTER(_i)]
    lib.emxCreateWrapperND_cell_wrap_2.restype   = _p
    lib.emxCreateWrapperND_cell_wrap_2.argtypes  = [_p, _i, ctypes.POINTER(_i)]
    lib.emxCreate_cell_wrap_1.restype            = _p
    lib.emxCreate_cell_wrap_1.argtypes           = [_i, _i]
    lib.emxCreate_cell_wrap_2.restype            = _p
    lib.emxCreate_cell_wrap_2.argtypes            = [_i, _i]
    lib.emxDestroyArray_cell_wrap_1.restype      = None
    lib.emxDestroyArray_cell_wrap_1.argtypes     = [_p]
    lib.emxDestroyArray_cell_wrap_2.restype      = None
    lib.emxDestroyArray_cell_wrap_2.argtypes     = [_p]
    lib.emxCreate_struct1_T.restype              = _p
    lib.emxCreate_struct1_T.argtypes             = [_i, _i]
    # ND variants (needed to create 1-D output cell arrays, e.g. Bi0)
    lib.emxCreateND_cell_wrap_1.restype          = _p
    lib.emxCreateND_cell_wrap_1.argtypes         = [_i, ctypes.POINTER(_i)]
    lib.emxCreateND_real_T.restype               = _p
    lib.emxCreateND_real_T.argtypes              = [_i, ctypes.POINTER(_i)]

    # --- register the main function ---
    fn = getattr(lib, fn_name)
    fn.restype  = None
    fn.argtypes = fn_argtypes

    _libs[so_path] = lib
    return lib


def _get_kinematics_lib():
    """Load SPART_C.so and register all compiled SPART functions."""
    _p  = ctypes.c_void_p
    _pd = ctypes.POINTER(ctypes.c_double)
    lib = _load_so(
        so_path     = os.path.join(_CODEGEN_ROOT, 'SPART_C', 'SPART_C.so'),
        init_fn     = 'SPART_C_initialize',
        fn_name     = 'Kinematics_C',
        fn_argtypes = [
            _pd,              # R0[9]
            _pd,              # r0[3]
            _p,               # qm          (emxArray_real_T*)
            ctypes.c_double,  # nLinksJoints
            _p,               # robotJoints (emxArray_struct0_T*)
            _p,               # robotLinks  (emxArray_struct1_T*)
            _p, _p, _p, _p, _p, _p,  # RJ, RL, rJ, rL, e, g  (emxArray_real_T*)
        ]
    )
    # Register additional functions (idempotent after first load)
    if not hasattr(lib, '_spart_extra_registered'):
        # DiffKinematics_C(R0[9], r0[3], rL*, e*, g*, n, conBranch*, joints*,
        #                  Bij* out, Bi0* out, P0[36] out, pm* out)
        lib.DiffKinematics_C.restype  = None
        lib.DiffKinematics_C.argtypes = [
            _pd, _pd, _p, _p, _p, ctypes.c_double, _p, _p, _p, _p, _pd, _p]

        # Velocities_C(Bij*, Bi0*, P0[36], pm*, u0[6], um*, n, joints*,
        #              t0[6] out, tL* out)
        lib.Velocities_C.restype  = None
        lib.Velocities_C.argtypes = [
            _p, _p, _pd, _p, _pd, _p, ctypes.c_double, _p, _pd, _p]

        # Accelerations_C(t0[6], tL*, P0[36], pm*, Bi0*, Bij*, u0[6], um*,
        #                 u0dot[6], umdot*, n, joints*, t0dot[6] out, tLdot* out)
        lib.Accelerations_C.restype  = None
        lib.Accelerations_C.argtypes = [
            _pd, _p, _pd, _p, _p, _p, _pd, _p, _pd, _p,
            ctypes.c_double, _p, _pd, _p]

        # I_I_C(R0[9], RL*, n, baseInertia[9], links*, I0[9] out, Im* out)
        lib.I_I_C.restype  = None
        lib.I_I_C.argtypes = [_pd, _p, ctypes.c_double, _pd, _p, _pd, _p]

        # ID_C(wF0[6], wFm*, t0[6], tL*, t0dot[6], tLdot*, P0[36], pm*,
        #      I0[9], Im*, Bij*, Bi0*, n, nQ, baseLink*, links*,
        #      conChild*, conChildBase*, joints*, tau0[6] out, taum* out)
        lib.ID_C.restype  = None
        lib.ID_C.argtypes = [
            _pd, _p, _pd, _p, _pd, _p, _pd, _p,
            _pd, _p, _p, _p, ctypes.c_double, ctypes.c_double,
            _p, _p, _p, _p, _p, _pd, _p]

        # FD_C(tau0[6], taum*, wF0[6], wFm*, t0[6], tL*, P0[36], pm*,
        #      I0[9], Im*, Bij*, Bi0*, u0[6], um*, n, nQ, baseLink*, links*,
        #      conChild*, conChildBase*, joints*, u0dot[6] out, umdot* out)
        lib.FD_C.restype  = None
        lib.FD_C.argtypes = [
            _pd, _p, _pd, _p, _pd, _p, _pd, _p,
            _pd, _p, _p, _p, _pd, _p, ctypes.c_double, ctypes.c_double,
            _p, _p, _p, _p, _p, _pd, _p]

        # SPART_SPACEROBOT_ODE_C(t, y*, tau*, nLinksJoints, joints*, links*,
        #      conBranch*, baseInertia[9], nQ, baseLink*, conChild*, conChildBase*,
        #      dydt* out)
        lib.SPART_SPACEROBOT_ODE_C.restype  = None
        lib.SPART_SPACEROBOT_ODE_C.argtypes = [
            ctypes.c_ulong,   # t
            _p,               # y
            _p,               # tau
            ctypes.c_double,  # nLinksJoints
            _p,               # robotJoints
            _p,               # robotLinks
            _p,               # robotConBranch
            _pd,              # robotBaseInertia[9]
            ctypes.c_double,  # nQ
            _p,               # robotBaseLink
            _p,               # robotConChild
            _p,               # robotConChildBase
            _p,               # dydt (output)
        ]

        lib._spart_extra_registered = True
    return lib



# ---------------------------------------------------------------------------
# Reusable helpers for struct packing
# ---------------------------------------------------------------------------

def _pack_joints(robot):
    """Pack robot.joints into a C struct0_T array."""
    n = robot.n_links_joints
    c_joints = (_CJoint * n)()
    for i, j in enumerate(robot.joints):
        c_joints[i].id          = j.id
        c_joints[i].type        = j.type
        c_joints[i].q_id        = j.q_id
        c_joints[i].parent_link = j.parent_link
        c_joints[i].child_link  = j.child_link
        T_flat = j.T.flatten(order='F')
        for k in range(3):  c_joints[i].axis[k] = float(j.axis[k])
        for k in range(16): c_joints[i].T[k]    = float(T_flat[k])
    return c_joints


def _pack_links(robot):
    """Pack robot.links into a C struct1_T array."""
    n = robot.n_links_joints
    c_links = (_CLink * n)()
    for i, l in enumerate(robot.links):
        c_links[i].id           = l.id
        c_links[i].parent_joint = l.parent_joint
        c_links[i].mass         = l.mass
        T_flat = l.T.flatten(order='F')
        I_flat = l.inertia.flatten(order='F')
        for k in range(16): c_links[i].T[k]       = float(T_flat[k])
        for k in range(9):  c_links[i].inertia[k] = float(I_flat[k])
    return c_links


def _read_emx(ptr):
    """Copy data out of any C-allocated emxArray_real_T into a numpy array."""
    emx = ctypes.cast(ptr, ctypes.POINTER(_EmxReal)).contents
    nd  = emx.numDimensions
    shape = tuple(emx.size[i] for i in range(nd))
    total = 1
    for s in shape: total *= s
    arr = np.ctypeslib.as_array(emx.data, shape=(total,)).copy()
    return arr.reshape(shape, order='F')   # column-major → correct row/col layout


def _pack_bij(Bij_arr, n):
    """
    Pack a (n, n, 6, 6) numpy array into a flat C array of _CCellWrap1.
    MATLAB Coder col-major indexing: Bij{i,j} -> data[j*n + i] (0-indexed).
    Each 6x6 block stored col-major: f1[col*6+row] = Bij[i,j,row,col].
    """
    c_data = (_CCellWrap1 * (n * n))()
    arr = np.asarray(Bij_arr, dtype=np.float64)           # (n, n, 6, 6)
    # transpose(1,0,3,2) → (j, i, col, row), C-reshape → flat[j*n+i, col*6+row]
    flat = arr.transpose(1, 0, 3, 2).reshape(n * n, 36)  # always returns a copy
    ctypes.memmove(c_data, flat.ctypes.data, flat.nbytes)
    return c_data


def _pack_bi0(Bi0_arr, n):
    """
    Pack a (n, 6, 6) numpy array into a flat C array of _CCellWrap1.
    Bi0{i} -> data[i] (0-indexed).
    Each 6x6 block stored col-major: f1[col*6+row] = Bi0[i,row,col].
    """
    c_data = (_CCellWrap1 * n)()
    arr = np.asarray(Bi0_arr, dtype=np.float64)   # (n, 6, 6)
    # transpose(0,2,1) → (i, col, row), C-reshape → flat[i, col*6+row]
    flat = arr.transpose(0, 2, 1).reshape(n, 36)  # always returns a copy
    ctypes.memmove(c_data, flat.ctypes.data, flat.nbytes)
    return c_data


def _pack_im(Im_arr, n):
    """
    Pack a (n, 3, 3) numpy array into a flat C array of _CCellWrap2.
    Im{i} -> data[i] (0-indexed).
    Each 3x3 block stored col-major: f1[col*3+row] = Im[i,row,col].
    """
    c_data = (_CCellWrap2 * n)()
    arr = np.asarray(Im_arr, dtype=np.float64)   # (n, 3, 3)
    # transpose(0,2,1) → (i, col, row), C-reshape → flat[i, col*3+row]
    flat = arr.transpose(0, 2, 1).reshape(n, 9)  # always returns a copy
    ctypes.memmove(c_data, flat.ctypes.data, flat.nbytes)
    return c_data


def _read_emx_cw1(ptr, n):
    """
    Read a C emxArray_cell_wrap_1 back into a numpy array.
    Returns:
      (n, n, 6, 6) when the emx is 2-D [n, n]   (Bij)
      (n,    6, 6) when the emx is 1-D [n]       (Bi0)
    Uses ctypes.string_at for a safe single byte-copy of the C buffer.
    """
    emx = ctypes.cast(ptr, ctypes.POINTER(_EmxCellWrap1)).contents
    nd    = emx.numDimensions
    shape = tuple(emx.size[i] for i in range(nd))
    n_elem = 1
    for s in shape: n_elem *= s

    if n_elem == 0:
        if len(shape) == 2 and shape[1] > 1:
            return np.zeros((shape[0], shape[1], 6, 6))
        return np.zeros((shape[0], 6, 6))

    # Safe byte-copy: each cell_wrap_1 contains 36 doubles (288 bytes)
    data_addr = ctypes.cast(emx.data, ctypes.c_void_p).value
    raw = ctypes.string_at(data_addr, n_elem * 36 * 8)
    flat = np.frombuffer(raw, dtype=np.float64).reshape(n_elem, 36)

    if len(shape) == 2 and shape[1] > 1:
        rows, cols = shape
        # flat[r + c*rows, col*6+row] = Bij[r,c,row,col]
        # reshape(rows*cols,6,6) → tmp[r+c*rows, col, row]; transpose → (r+c*rows, row, col)
        # reshape(cols,rows,6,6) → [c,r,row,col]; transpose(1,0,2,3) → [r,c,row,col]
        tmp = flat.reshape(rows * cols, 6, 6).transpose(0, 2, 1).reshape(cols, rows, 6, 6)
        return tmp.transpose(1, 0, 2, 3).copy()
    else:
        n_items = shape[0]
        # flat[i, col*6+row] = cell[row,col]; reshape(n,6,6)→[i,col,row]; transpose→[i,row,col]
        return flat.reshape(n_items, 6, 6).transpose(0, 2, 1).copy()


def _read_emx_cw2(ptr):
    """
    Read a C emxArray_cell_wrap_2 back into a (n, 3, 3) numpy array.
    Uses ctypes.string_at for a safe single byte-copy of the C buffer.
    """
    emx = ctypes.cast(ptr, ctypes.POINTER(_EmxCellWrap2)).contents
    nd    = emx.numDimensions
    shape = tuple(emx.size[i] for i in range(nd))
    n_items = max(shape) if shape else 0

    if n_items == 0:
        return np.zeros((0, 3, 3))

    # Safe byte-copy: each cell_wrap_2 contains 9 doubles (72 bytes)
    data_addr = ctypes.cast(emx.data, ctypes.c_void_p).value
    raw = ctypes.string_at(data_addr, n_items * 9 * 8)
    flat = np.frombuffer(raw, dtype=np.float64).reshape(n_items, 9)

    # flat[i, col*3+row] = Im[i,row,col]; reshape(n,3,3)→[i,col,row]; transpose→[i,row,col]
    return flat.reshape(n_items, 3, 3).transpose(0, 2, 1).copy()


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------

def load_robot(urdf_path):
    """
    Load a SPART robot model from a URDF file via the MATLAB engine.

    Parameters
    ----------
    urdf_path : str
        Absolute path to the URDF file.

    Returns
    -------
    RobotModel
        A Python RobotModel containing lists of JointData and LinkData,
        matching the struct0_T / struct1_T layout expected by SPART_C.so.
    """
    eng = _get_engine()

    # Call urdf2robot_py — returns plain numeric matrices (no struct arrays)
    # jointsMatrix:  [24 x n]
    # linksMatrix:   [28 x n]
    # conBranch:     [n  x n]
    # conChild:      [n  x n]
    # conChildBase:  [n  x 1]
    # baseMass:      scalar
    # baseInertia:   [9  x 1] col-major
    (n_links_joints, n_q_ml, robot_name,
     ml_joints, ml_links,
     ml_con_branch, ml_con_child, ml_con_child_base,
     ml_base_mass, ml_base_inertia) = eng.urdf2robot_py(urdf_path, nargout=10)
    n = int(n_links_joints)

    joints_arr = np.array(ml_joints)  # (24, n)
    links_arr  = np.array(ml_links)   # (28, n)

    # --- Parse joints ---
    joints = []
    for i in range(n):
        col = joints_arr[:, i]
        joints.append(JointData(
            id          = col[0],
            type        = col[1],
            q_id        = col[2],
            parent_link = col[3],
            child_link  = col[4],
            axis        = col[5:8],
            T           = col[8:24].reshape(4, 4, order='F'),
        ))

    # --- Parse links ---
    links = []
    for i in range(n):
        col = links_arr[:, i]
        links.append(LinkData(
            id           = col[0],
            parent_joint = col[1],
            T            = col[2:18].reshape(4, 4, order='F'),
            mass         = col[18],
            inertia      = col[19:28].reshape(3, 3, order='F'),
        ))

    name = str(robot_name)
    n_q  = int(n_q_ml)

    return RobotModel(
        name               = name,
        n_q                = n_q,
        n_links_joints     = n,
        joints             = joints,
        links              = links,
        con_branch         = np.array(ml_con_branch),
        con_child          = np.array(ml_con_child),
        con_child_base     = np.array(ml_con_child_base).flatten(),
        base_link_mass     = float(ml_base_mass),
        base_link_inertia  = np.array(ml_base_inertia).reshape(3, 3, order='F'),
    )


# ---------------------------------------------------------------------------
# SPART class — robot-bound interface with cached C structs
# ---------------------------------------------------------------------------

class SPART:
    """
    Robot-bound interface to the SPART compiled functions.

    Instantiate with a URDF path or an already-loaded RobotModel.
    The C struct arrays are packed once at construction (or when the robot
    is reassigned via the ``robot`` property) and reused on every call.

    Examples
    --------
    >>> spart = SPART('URDF_models/floating_7dof_manipulator.urdf')
    >>> RJ, RL, rJ, rL, e, g = spart.kinematics(R0, r0, qm)
    >>> Bij, Bi0, P0, pm     = spart.diff_kinematics(R0, r0, rL, e, g)
    >>> t0, tL               = spart.velocities(Bij, Bi0, P0, pm, u0, um)
    >>> I0, Im               = spart.i_i(R0, RL)

    # Switch robot — C structs are rebuilt automatically
    >>> spart.robot = 'URDF_models/kuka_iiwa.urdf'
    """

    def __init__(self, robot):
        """
        Parameters
        ----------
        robot : str or RobotModel
            Either a path to a URDF file or an already-loaded RobotModel.
        """
        self._robot         = None
        self._c_joints      = None
        self._c_links       = None
        self._c_base_link   = None
        self._c_con_branch  = None   # flat numpy F-order for con_branch
        self._c_con_child   = None   # flat numpy F-order for con_child
        self._c_con_cb      = None   # flat numpy for con_child_base
        self.robot = robot           # triggers the property setter

    # ------------------------------------------------------------------
    # robot property
    # ------------------------------------------------------------------

    @property
    def robot(self):
        """The currently active RobotModel."""
        return self._robot

    @robot.setter
    def robot(self, value):
        """Assign a new robot; accepts a URDF path (str) or a RobotModel."""
        if isinstance(value, str):
            value = load_robot(value)
        if not isinstance(value, RobotModel):
            raise TypeError("robot must be a URDF path (str) or a RobotModel instance")
        self._robot = value
        self._c_joints = _pack_joints(value)
        self._c_links  = _pack_links(value)

        # Base-link struct (struct2_T)
        bl = _CBaseLink()
        bl.mass = value.base_link_mass
        I_flat  = value.base_link_inertia.flatten(order='F')
        for k in range(9):
            bl.inertia[k] = float(I_flat[k])
        self._c_base_link = bl

        # Connectivity matrices (flat F-order numpy, used as pointer inputs)
        self._c_con_branch = np.asarray(value.con_branch, dtype=np.float64, order='F')
        self._c_con_child  = np.asarray(value.con_child,  dtype=np.float64, order='F')
        self._c_con_cb     = np.asarray(value.con_child_base, dtype=np.float64).flatten()

    # ------------------------------------------------------------------
    # Internal helpers
    # ------------------------------------------------------------------

    def _make_emx_joints(self, lib):
        n = self._robot.n_links_joints
        return lib.emxCreateWrapper_struct0_T(
            ctypes.cast(self._c_joints, ctypes.c_void_p),
            ctypes.c_int(1), ctypes.c_int(n))

    def _make_emx_links(self, lib):
        n = self._robot.n_links_joints
        return lib.emxCreateWrapper_struct1_T(
            ctypes.cast(self._c_links, ctypes.c_void_p),
            ctypes.c_int(1), ctypes.c_int(n))

    def _make_emx_real_wrap(self, lib, arr):
        """Wrap a 1-D or 2-D numpy array in an emxArray_real_T."""
        c = np.asarray(arr, dtype=np.float64, order='F')
        ptr = c.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
        if c.ndim == 1:
            return lib.emxCreateWrapper_real_T(ptr, ctypes.c_int(len(c)), ctypes.c_int(1)), c
        else:
            rows, cols = c.shape
            return lib.emxCreateWrapper_real_T(ptr, ctypes.c_int(rows), ctypes.c_int(cols)), c

    def _make_emx_cw1_wrap(self, lib, c_data, rows, cols):
        """Wrap a flat _CCellWrap1 C array in an emxArray_cell_wrap_1 (2D)."""
        sizes = (ctypes.c_int * 2)(rows, cols)
        return lib.emxCreateWrapperND_cell_wrap_1(
            ctypes.cast(c_data, ctypes.c_void_p),
            ctypes.c_int(2), sizes)

    def _make_emx_cw2_wrap(self, lib, c_data, n):
        """Wrap a flat _CCellWrap2 C array in an emxArray_cell_wrap_2 (1xn)."""
        return lib.emxCreateWrapper_cell_wrap_2(
            ctypes.cast(c_data, ctypes.c_void_p),
            ctypes.c_int(1), ctypes.c_int(n))

    # ------------------------------------------------------------------
    # Kinematics
    # ------------------------------------------------------------------

    def kinematics(self, R0, r0, qm):
        """
        Compute forward kinematics via the compiled SPART_C.so.

        Parameters
        ----------
        R0  : (3,3) array  – base rotation matrix
        r0  : (3,)  array  – base position vector
        qm  : (n_q,) array – joint angles

        Returns
        -------
        RJ, RL : (3, 3*n)  rotation matrices of joints / links
        rJ, rL : (3,  n)   positions of joints / links
        e      : (3,  n)   joint axes in inertial frame
        g      : (3,  n)   vector from joint to link CoM
        """
        lib = _get_kinematics_lib()
        n   = self._robot.n_links_joints

        R0_c = np.asarray(R0, dtype=np.float64, order='F').flatten(order='F')
        r0_c = np.asarray(r0, dtype=np.float64).flatten()
        qm_c = np.asarray(qm, dtype=np.float64).flatten()

        R0_ptr = R0_c.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
        r0_ptr = r0_c.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
        qm_ptr = qm_c.ctypes.data_as(ctypes.POINTER(ctypes.c_double))

        emx_qm     = lib.emxCreateWrapper_real_T(qm_ptr, ctypes.c_int(len(qm_c)), ctypes.c_int(1))
        emx_joints = self._make_emx_joints(lib)
        emx_links  = self._make_emx_links(lib)

        emx_RJ = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
        emx_RL = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
        emx_rJ = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
        emx_rL = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
        emx_e  = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
        emx_g  = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))

        lib.Kinematics_C(
            R0_ptr, r0_ptr, emx_qm, ctypes.c_double(n),
            emx_joints, emx_links,
            emx_RJ, emx_RL, emx_rJ, emx_rL, emx_e, emx_g)

        RJ = _read_emx(emx_RJ); RL = _read_emx(emx_RL)
        rJ = _read_emx(emx_rJ); rL = _read_emx(emx_rL)
        e  = _read_emx(emx_e);  g  = _read_emx(emx_g)

        lib.emxDestroyArray_real_T(emx_RJ);  lib.emxDestroyArray_real_T(emx_RL)
        lib.emxDestroyArray_real_T(emx_rJ);  lib.emxDestroyArray_real_T(emx_rL)
        lib.emxDestroyArray_real_T(emx_e);   lib.emxDestroyArray_real_T(emx_g)
        lib.emxDestroyArray_real_T(emx_qm)
        lib.emxDestroyArray_struct0_T(emx_joints)
        lib.emxDestroyArray_struct1_T(emx_links)

        return RJ, RL, rJ, rL, e, g

    # ------------------------------------------------------------------
    # Differential Kinematics
    # ------------------------------------------------------------------

    def diff_kinematics(self, R0, r0, rL, e, g):
        """
        Compute the motion-propagation matrices via DiffKinematics_C.

        Parameters
        ----------
        R0  : (3,3)   – base rotation matrix
        r0  : (3,)    – base position
        rL  : (3, n)  – link CoM positions  (from kinematics)
        e   : (3, n)  – joint axes          (from kinematics)
        g   : (3, n)  – joint-to-CoM vectors (from kinematics)

        Returns
        -------
        Bij : (n, n, 6, 6) – relative twist-propagation matrices between links
        Bi0 : (n,    6, 6) – twist propagation from base to each link
        P0  : (6, 6)       – base-link motion subspace (as a numpy (6,6) array)
        pm  : (6, n)       – joint motion subspace
        """
        lib  = _get_kinematics_lib()
        n    = self._robot.n_links_joints
        _pd  = ctypes.POINTER(ctypes.c_double)

        R0_c = np.asarray(R0, dtype=np.float64, order='F').flatten(order='F')
        r0_c = np.asarray(r0, dtype=np.float64).flatten()

        R0_ptr = R0_c.ctypes.data_as(_pd)
        r0_ptr = r0_c.ctypes.data_as(_pd)

        emx_rL, _rL = self._make_emx_real_wrap(lib, rL)
        emx_e,  _e  = self._make_emx_real_wrap(lib, e)
        emx_g,  _g  = self._make_emx_real_wrap(lib, g)
        emx_cb, _cb = self._make_emx_real_wrap(lib, self._c_con_branch)
        emx_joints  = self._make_emx_joints(lib)

        P0_c   = (ctypes.c_double * 36)()
        emx_Bij = lib.emxCreate_cell_wrap_1(ctypes.c_int(0), ctypes.c_int(0))
        # Bi0 is 1-D in C (only size[0] is set) — must create as 1D or emxEnsureCapacity
        # computes 0 elements and never allocates, causing heap corruption.
        _bi0_sz = (ctypes.c_int * 1)(0)
        emx_Bi0 = lib.emxCreateND_cell_wrap_1(ctypes.c_int(1), _bi0_sz)
        emx_pm  = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))

        lib.DiffKinematics_C(
            R0_ptr, r0_ptr,
            emx_rL, emx_e, emx_g,
            ctypes.c_double(n),
            emx_cb, emx_joints,
            emx_Bij, emx_Bi0,
            P0_c, emx_pm)

        Bij = _read_emx_cw1(emx_Bij, n)
        Bi0 = _read_emx_cw1(emx_Bi0, n)
        P0  = np.array(P0_c, dtype=np.float64).reshape(6, 6, order='F')
        pm  = _read_emx(emx_pm)

        lib.emxDestroyArray_cell_wrap_1(emx_Bij)
        lib.emxDestroyArray_cell_wrap_1(emx_Bi0)
        lib.emxDestroyArray_real_T(emx_pm)
        lib.emxDestroyArray_real_T(emx_rL)
        lib.emxDestroyArray_real_T(emx_e)
        lib.emxDestroyArray_real_T(emx_g)
        lib.emxDestroyArray_real_T(emx_cb)
        lib.emxDestroyArray_struct0_T(emx_joints)

        return Bij, Bi0, P0, pm

    # ------------------------------------------------------------------
    # Velocities
    # ------------------------------------------------------------------

    def velocities(self, Bij, Bi0, P0, pm, u0, um):
        """
        Compute link twist vectors via Velocities_C.

        Parameters
        ----------
        Bij : (n, n, 6, 6) – from diff_kinematics
        Bi0 : (n,    6, 6) – from diff_kinematics
        P0  : (6, 6)       – from diff_kinematics
        pm  : (6, n)       – from diff_kinematics
        u0  : (6,)  – base-link generalised velocity [omega; v]
        um  : (n_q,) – joint velocities

        Returns
        -------
        t0 : (6,)    – base-link twist
        tL : (6, n)  – link twist matrix
        """
        lib = _get_kinematics_lib()
        n   = self._robot.n_links_joints
        _pd = ctypes.POINTER(ctypes.c_double)

        c_bij = _pack_bij(Bij, n)
        c_bi0 = _pack_bi0(Bi0, n)
        emx_Bij = self._make_emx_cw1_wrap(lib, c_bij, n, n)
        emx_Bi0 = self._make_emx_cw1_wrap(lib, c_bi0, n, 1)

        P0_c = np.asarray(P0, dtype=np.float64, order='F').flatten(order='F')
        P0_ptr = P0_c.ctypes.data_as(_pd)

        emx_pm, _pm = self._make_emx_real_wrap(lib, pm)

        u0_c  = np.asarray(u0, dtype=np.float64).flatten()
        u0_ptr = u0_c.ctypes.data_as(_pd)
        emx_um, _um = self._make_emx_real_wrap(lib, np.asarray(um, dtype=np.float64).flatten())
        emx_joints = self._make_emx_joints(lib)

        t0_c  = (ctypes.c_double * 6)()
        emx_tL = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))

        lib.Velocities_C(
            emx_Bij, emx_Bi0,
            P0_ptr, emx_pm,
            u0_ptr, emx_um,
            ctypes.c_double(n), emx_joints,
            t0_c, emx_tL)

        t0 = np.array(t0_c, dtype=np.float64)
        tL = _read_emx(emx_tL)

        lib.emxDestroyArray_cell_wrap_1(emx_Bij)
        lib.emxDestroyArray_cell_wrap_1(emx_Bi0)
        lib.emxDestroyArray_real_T(emx_pm)
        lib.emxDestroyArray_real_T(emx_um)
        lib.emxDestroyArray_real_T(emx_tL)
        lib.emxDestroyArray_struct0_T(emx_joints)

        return t0, tL

    # ------------------------------------------------------------------
    # Accelerations
    # ------------------------------------------------------------------

    def accelerations(self, t0, tL, P0, pm, Bi0, Bij, u0, um, u0dot, umdot):
        """
        Compute link twist-rate vectors via Accelerations_C.

        Parameters
        ----------
        t0    : (6,)    – base-link twist        (from velocities)
        tL    : (6, n)  – link twists            (from velocities)
        P0    : (6, 6)  – base motion subspace   (from diff_kinematics)
        pm    : (6, n)  – joint motion subspace  (from diff_kinematics)
        Bi0   : (n,    6, 6) – from diff_kinematics
        Bij   : (n, n, 6, 6) – from diff_kinematics
        u0    : (6,)    – base generalised velocity
        um    : (n_q,)  – joint velocities
        u0dot : (6,)    – base generalised acceleration
        umdot : (n_q,)  – joint accelerations

        Returns
        -------
        t0dot : (6,)    – base-link twist rate
        tLdot : (6, n)  – link twist-rate matrix
        """
        lib = _get_kinematics_lib()
        n   = self._robot.n_links_joints
        _pd = ctypes.POINTER(ctypes.c_double)

        def _fp(arr):
            a = np.asarray(arr, dtype=np.float64).flatten()
            return a.ctypes.data_as(_pd), a

        t0_ptr,    _t0    = _fp(t0)
        u0_ptr,    _u0    = _fp(u0)
        u0dot_ptr, _u0dot = _fp(u0dot)
        P0_ptr,    _P0    = _fp(np.asarray(P0, dtype=np.float64, order='F').flatten(order='F'))

        emx_tL,   _tL   = self._make_emx_real_wrap(lib, tL)
        emx_pm,   _pmc  = self._make_emx_real_wrap(lib, pm)
        emx_um,   _umc  = self._make_emx_real_wrap(lib, np.asarray(um,    dtype=np.float64).flatten())
        emx_umdot, _umd = self._make_emx_real_wrap(lib, np.asarray(umdot, dtype=np.float64).flatten())

        c_bij = _pack_bij(Bij, n);  emx_Bij = self._make_emx_cw1_wrap(lib, c_bij, n, n)
        c_bi0 = _pack_bi0(Bi0, n);  emx_Bi0 = self._make_emx_cw1_wrap(lib, c_bi0, n, 1)
        emx_joints = self._make_emx_joints(lib)

        t0dot_c  = (ctypes.c_double * 6)()
        emx_tLdot = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))

        lib.Accelerations_C(
            t0_ptr, emx_tL,
            P0_ptr, emx_pm,
            emx_Bi0, emx_Bij,
            u0_ptr, emx_um,
            u0dot_ptr, emx_umdot,
            ctypes.c_double(n), emx_joints,
            t0dot_c, emx_tLdot)

        t0dot = np.array(t0dot_c, dtype=np.float64)
        tLdot = _read_emx(emx_tLdot)

        lib.emxDestroyArray_cell_wrap_1(emx_Bij); lib.emxDestroyArray_cell_wrap_1(emx_Bi0)
        lib.emxDestroyArray_real_T(emx_tL);   lib.emxDestroyArray_real_T(emx_pm)
        lib.emxDestroyArray_real_T(emx_um);   lib.emxDestroyArray_real_T(emx_umdot)
        lib.emxDestroyArray_real_T(emx_tLdot)
        lib.emxDestroyArray_struct0_T(emx_joints)

        return t0dot, tLdot

    # ------------------------------------------------------------------
    # Inertia in inertial frame
    # ------------------------------------------------------------------

    def i_i(self, R0, RL):
        """
        Compute inertia tensors expressed in the inertial frame via I_I_C.

        Parameters
        ----------
        R0 : (3,3)    – base rotation matrix
        RL : (3, 3*n) – link rotation matrices  (from kinematics)

        Returns
        -------
        I0 : (3,3)    – base-link inertia in inertial frame
        Im : (n, 3,3) – per-link inertia tensors in inertial frame
        """
        lib  = _get_kinematics_lib()
        n    = self._robot.n_links_joints
        _pd  = ctypes.POINTER(ctypes.c_double)

        R0_c   = np.asarray(R0, dtype=np.float64, order='F').flatten(order='F')
        R0_ptr = R0_c.ctypes.data_as(_pd)

        base_I_c = np.asarray(self._robot.base_link_inertia, dtype=np.float64, order='F').flatten(order='F')
        base_I_ptr = base_I_c.ctypes.data_as(_pd)

        emx_RL, _RL = self._make_emx_real_wrap(lib, RL)
        emx_links   = self._make_emx_links(lib)

        I0_c   = (ctypes.c_double * 9)()
        emx_Im = lib.emxCreate_cell_wrap_2(ctypes.c_int(0), ctypes.c_int(0))

        lib.I_I_C(
            R0_ptr, emx_RL,
            ctypes.c_double(n),
            base_I_ptr, emx_links,
            I0_c, emx_Im)

        I0 = np.array(I0_c, dtype=np.float64).reshape(3, 3, order='F')
        Im = _read_emx_cw2(emx_Im)

        lib.emxDestroyArray_real_T(emx_RL)
        lib.emxDestroyArray_struct1_T(emx_links)
        lib.emxDestroyArray_cell_wrap_2(emx_Im)

        return I0, Im

    # ------------------------------------------------------------------
    # Inverse Dynamics
    # ------------------------------------------------------------------

    def inverse_dynamics(self, wF0, wFm, t0, tL, t0dot, tLdot, P0, pm, I0, Im, Bij, Bi0):
        """
        Compute generalised forces via ID_C (inverse dynamics).

        Parameters
        ----------
        wF0   : (6,)    – external wrench on base
        wFm   : (6, n)  – external wrenches on links
        t0    : (6,)    – base twist
        tL    : (6, n)  – link twists
        t0dot : (6,)    – base twist rate
        tLdot : (6, n)  – link twist rates
        P0    : (6, 6)  – base motion subspace
        pm    : (6, n)  – joint motion subspace
        I0    : (3,3)   – base inertia in inertial frame
        Im    : (n,3,3) – link inertias in inertial frame
        Bij   : (n,n,6,6)
        Bi0   : (n,6,6)

        Returns
        -------
        tau0 : (6,)    – base generalised force
        taum : (n_q,)  – joint torques
        """
        lib = _get_kinematics_lib()
        n   = self._robot.n_links_joints
        _pd = ctypes.POINTER(ctypes.c_double)

        def _fp(arr):
            a = np.asarray(arr, dtype=np.float64, order='F').flatten(order='F')
            return a.ctypes.data_as(_pd), a

        wF0_ptr, _wF0 = _fp(wF0)
        t0_ptr,  _t0  = _fp(t0)
        t0d_ptr, _t0d = _fp(t0dot)
        P0_ptr,  _P0  = _fp(P0)
        I0_ptr,  _I0  = _fp(I0)

        emx_wFm,  _wFm  = self._make_emx_real_wrap(lib, wFm)
        emx_tL,   _tLc  = self._make_emx_real_wrap(lib, tL)
        emx_tLdot, _tLd = self._make_emx_real_wrap(lib, tLdot)
        emx_pm,   _pmc  = self._make_emx_real_wrap(lib, pm)

        c_im  = _pack_im(Im, n);   emx_Im  = self._make_emx_cw2_wrap(lib, c_im, n)
        c_bij = _pack_bij(Bij, n); emx_Bij = self._make_emx_cw1_wrap(lib, c_bij, n, n)
        c_bi0 = _pack_bi0(Bi0, n); emx_Bi0 = self._make_emx_cw1_wrap(lib, c_bi0, n, 1)

        emx_cc,  _cc  = self._make_emx_real_wrap(lib, self._c_con_child)
        emx_ccb, _ccb = self._make_emx_real_wrap(lib, self._c_con_cb)
        emx_joints    = self._make_emx_joints(lib)
        emx_links     = self._make_emx_links(lib)

        tau0_c  = (ctypes.c_double * 6)()
        _taum_sz = (ctypes.c_int * 1)(0)
        emx_taum = lib.emxCreateND_real_T(ctypes.c_int(1), _taum_sz)

        lib.ID_C(
            wF0_ptr, emx_wFm,
            t0_ptr,  emx_tL,
            t0d_ptr, emx_tLdot,
            P0_ptr,  emx_pm,
            I0_ptr,  emx_Im,
            emx_Bij, emx_Bi0,
            ctypes.c_double(n), ctypes.c_double(self._robot.n_q),
            ctypes.cast(ctypes.addressof(self._c_base_link), ctypes.c_void_p),
            emx_links,
            emx_cc, emx_ccb,
            emx_joints,
            tau0_c, emx_taum)

        tau0 = np.array(tau0_c, dtype=np.float64)
        taum = _read_emx(emx_taum).flatten()

        lib.emxDestroyArray_real_T(emx_wFm);  lib.emxDestroyArray_real_T(emx_tL)
        lib.emxDestroyArray_real_T(emx_tLdot); lib.emxDestroyArray_real_T(emx_pm)
        lib.emxDestroyArray_cell_wrap_2(emx_Im)
        lib.emxDestroyArray_cell_wrap_1(emx_Bij); lib.emxDestroyArray_cell_wrap_1(emx_Bi0)
        lib.emxDestroyArray_real_T(emx_cc);  lib.emxDestroyArray_real_T(emx_ccb)
        lib.emxDestroyArray_struct0_T(emx_joints)
        lib.emxDestroyArray_struct1_T(emx_links)
        lib.emxDestroyArray_real_T(emx_taum)

        return tau0, taum

    # ------------------------------------------------------------------
    # Forward Dynamics
    # ------------------------------------------------------------------

    def forward_dynamics(self, tau0, taum, wF0, wFm, t0, tL, P0, pm, I0, Im, Bij, Bi0, u0, um):
        """
        Compute generalised accelerations via FD_C (forward dynamics).

        Parameters
        ----------
        tau0 : (6,)    – base generalised force
        taum : (n_q,)  – joint torques
        wF0  : (6,)    – external wrench on base
        wFm  : (6, n)  – external wrenches on links
        t0   : (6,)    – base twist
        tL   : (6, n)  – link twists
        P0   : (6, 6)  – base motion subspace
        pm   : (6, n)  – joint motion subspace
        I0   : (3,3)   – base inertia in inertial frame
        Im   : (n,3,3) – link inertias in inertial frame
        Bij  : (n,n,6,6)
        Bi0  : (n,6,6)
        u0   : (6,)    – base generalised velocity
        um   : (n_q,)  – joint velocities

        Returns
        -------
        u0dot  : (6,)    – base generalised acceleration
        umdot  : (n_q,)  – joint accelerations
        """
        lib = _get_kinematics_lib()
        n   = self._robot.n_links_joints
        _pd = ctypes.POINTER(ctypes.c_double)

        def _fp(arr):
            a = np.asarray(arr, dtype=np.float64, order='F').flatten(order='F')
            return a.ctypes.data_as(_pd), a

        tau0_ptr, _tau0 = _fp(tau0)
        wF0_ptr,  _wF0  = _fp(wF0)
        t0_ptr,   _t0   = _fp(t0)
        P0_ptr,   _P0   = _fp(P0)
        I0_ptr,   _I0   = _fp(I0)
        u0_ptr,   _u0   = _fp(u0)

        emx_taum, _taumc = self._make_emx_real_wrap(lib, np.asarray(taum, dtype=np.float64).flatten())
        emx_wFm,  _wFm   = self._make_emx_real_wrap(lib, wFm)
        emx_tL,   _tLc   = self._make_emx_real_wrap(lib, tL)
        emx_pm,   _pmc   = self._make_emx_real_wrap(lib, pm)
        emx_um,   _umc   = self._make_emx_real_wrap(lib, np.asarray(um, dtype=np.float64).flatten())

        c_im  = _pack_im(Im, n);   emx_Im  = self._make_emx_cw2_wrap(lib, c_im, n)
        c_bij = _pack_bij(Bij, n); emx_Bij = self._make_emx_cw1_wrap(lib, c_bij, n, n)
        c_bi0 = _pack_bi0(Bi0, n); emx_Bi0 = self._make_emx_cw1_wrap(lib, c_bi0, n, 1)

        emx_cc,  _cc  = self._make_emx_real_wrap(lib, self._c_con_child)
        emx_ccb, _ccb = self._make_emx_real_wrap(lib, self._c_con_cb)
        emx_joints    = self._make_emx_joints(lib)
        emx_links     = self._make_emx_links(lib)

        u0dot_c  = (ctypes.c_double * 6)()
        _umdot_sz = (ctypes.c_int * 1)(0)
        emx_umdot = lib.emxCreateND_real_T(ctypes.c_int(1), _umdot_sz)

        lib.FD_C(
            tau0_ptr, emx_taum,
            wF0_ptr,  emx_wFm,
            t0_ptr,   emx_tL,
            P0_ptr,   emx_pm,
            I0_ptr,   emx_Im,
            emx_Bij,  emx_Bi0,
            u0_ptr,   emx_um,
            ctypes.c_double(n), ctypes.c_double(self._robot.n_q),
            ctypes.cast(ctypes.addressof(self._c_base_link), ctypes.c_void_p),
            emx_links,
            emx_cc, emx_ccb,
            emx_joints,
            u0dot_c, emx_umdot)

        u0dot = np.array(u0dot_c, dtype=np.float64)
        umdot = _read_emx(emx_umdot).flatten()

        lib.emxDestroyArray_real_T(emx_taum); lib.emxDestroyArray_real_T(emx_wFm)
        lib.emxDestroyArray_real_T(emx_tL);  lib.emxDestroyArray_real_T(emx_pm)
        lib.emxDestroyArray_real_T(emx_um)
        lib.emxDestroyArray_cell_wrap_2(emx_Im)
        lib.emxDestroyArray_cell_wrap_1(emx_Bij); lib.emxDestroyArray_cell_wrap_1(emx_Bi0)
        lib.emxDestroyArray_real_T(emx_cc);  lib.emxDestroyArray_real_T(emx_ccb)
        lib.emxDestroyArray_struct0_T(emx_joints)
        lib.emxDestroyArray_struct1_T(emx_links)
        lib.emxDestroyArray_real_T(emx_umdot)

        return u0dot, umdot

    # ------------------------------------------------------------------
    # Space-Robot ODE
    # ------------------------------------------------------------------

    def space_robot_ode(self, t, y, tau):
        """
        Compute the ODE time derivative for a free-floating space robot.

        The state vector ``y`` is laid out as::

            y = [R0_flat(9, col-major); r0(3); w0_body(3); r0_dot(3); qm(nQ); qm_dot(nQ)]

        total length = 18 + 2*nQ.

        Parameters
        ----------
        t   : float
            Current simulation time.
        y   : (18 + 2*nQ,) array
            State vector as described above.
        tau : (6 + nQ,) array
            Generalised forces: ``[tau0(6); taum(nQ)]``.

        Returns
        -------
        dydt : (18 + 2*nQ,) array
            Time derivative of the state vector.
        """
        lib = _get_kinematics_lib()
        n   = self._robot.n_links_joints
        nq  = self._robot.n_q
        _pd = ctypes.POINTER(ctypes.c_double)

        y_c   = np.asarray(y,   dtype=np.float64).flatten()
        tau_c = np.asarray(tau, dtype=np.float64).flatten()

        emx_y,   _yc   = self._make_emx_real_wrap(lib, y_c)
        emx_tau, _tauc = self._make_emx_real_wrap(lib, tau_c)

        base_I_c   = np.asarray(self._robot.base_link_inertia,
                                dtype=np.float64, order='F').flatten(order='F')
        base_I_ptr = base_I_c.ctypes.data_as(_pd)

        emx_cb,  _cb  = self._make_emx_real_wrap(lib, self._c_con_branch)
        emx_cc,  _cc  = self._make_emx_real_wrap(lib, self._c_con_child)
        emx_ccb, _ccb = self._make_emx_real_wrap(lib, self._c_con_cb)
        emx_joints    = self._make_emx_joints(lib)
        emx_links     = self._make_emx_links(lib)

        _dydt_sz = (ctypes.c_int * 1)(0)
        emx_dydt = lib.emxCreateND_real_T(ctypes.c_int(1), _dydt_sz)

        lib.SPART_SPACEROBOT_ODE_C(
            ctypes.c_ulong(int(t)),
            emx_y,
            emx_tau,
            ctypes.c_double(n),
            emx_joints,
            emx_links,
            emx_cb,
            base_I_ptr,
            ctypes.c_double(nq),
            ctypes.cast(ctypes.addressof(self._c_base_link), ctypes.c_void_p),
            emx_cc,
            emx_ccb,
            emx_dydt)

        dydt = _read_emx(emx_dydt).flatten()

        lib.emxDestroyArray_real_T(emx_y)
        lib.emxDestroyArray_real_T(emx_tau)
        lib.emxDestroyArray_real_T(emx_cb)
        lib.emxDestroyArray_real_T(emx_cc)
        lib.emxDestroyArray_real_T(emx_ccb)
        lib.emxDestroyArray_struct0_T(emx_joints)
        lib.emxDestroyArray_struct1_T(emx_links)
        lib.emxDestroyArray_real_T(emx_dydt)

        return dydt

    def benchmark(self, n_runs=1000, R0=None, r0=None, qm=None,
                  u0=None, um=None, u0dot=None, umdot=None,
                  wF0=None, wFm=None, tau0=None, taum=None):
        """
        Time each SPART function over ``n_runs`` iterations and print a summary.

        Default inputs are zeros (identity rotation for R0) unless supplied.

        Parameters
        ----------
        n_runs : int
            Number of repetitions per function (default 1000).
        R0, r0, qm, u0, um, u0dot, umdot, wF0, wFm, tau0, taum : array-like, optional
            Override the default zero inputs.
        """
        import timeit as _timeit

        nq = self._robot.n_q
        n  = self._robot.n_links_joints

        # --- Default inputs ---
        if R0    is None: R0    = np.eye(3)
        if r0    is None: r0    = np.zeros(3)
        if qm    is None: qm    = np.zeros(nq)
        if u0    is None: u0    = np.zeros(6)
        if um    is None: um    = np.zeros(nq)
        if u0dot is None: u0dot = np.zeros(6)
        if umdot is None: umdot = np.zeros(nq)
        if wF0   is None: wF0   = np.zeros(6)
        if wFm   is None: wFm   = np.zeros((6, n))
        if tau0  is None: tau0  = np.zeros(6)
        if taum  is None: taum  = np.zeros(nq)

        results = {}

        # 1. kinematics
        def _run_kin():
            return self.kinematics(R0, r0, qm)
        t = _timeit.timeit(_run_kin, number=n_runs)
        results['kinematics'] = t
        RJ, RL, rJ, rL, e, g = _run_kin()

        # 2. diff_kinematics
        def _run_dk():
            return self.diff_kinematics(R0, r0, rL, e, g)
        t = _timeit.timeit(_run_dk, number=n_runs)
        results['diff_kinematics'] = t
        Bij, Bi0, P0, pm = _run_dk()

        # 3. velocities
        def _run_vel():
            return self.velocities(Bij, Bi0, P0, pm, u0, um)
        t = _timeit.timeit(_run_vel, number=n_runs)
        results['velocities'] = t
        t0, tL = _run_vel()

        # 4. i_i
        def _run_ii():
            return self.i_i(R0, RL)
        t = _timeit.timeit(_run_ii, number=n_runs)
        results['i_i'] = t
        I0, Im = _run_ii()

        # 5. accelerations
        def _run_acc():
            return self.accelerations(t0, tL, P0, pm, Bi0, Bij, u0, um, u0dot, umdot)
        t = _timeit.timeit(_run_acc, number=n_runs)
        results['accelerations'] = t
        t0dot, tLdot = _run_acc()

        # 6. inverse_dynamics
        def _run_id():
            return self.inverse_dynamics(wF0, wFm, t0, tL, t0dot, tLdot, P0, pm, I0, Im, Bij, Bi0)
        t = _timeit.timeit(_run_id, number=n_runs)
        results['inverse_dynamics'] = t

        # 7. forward_dynamics
        def _run_fd():
            return self.forward_dynamics(tau0, taum, wF0, wFm, t0, tL, P0, pm, I0, Im, Bij, Bi0, u0, um)
        t = _timeit.timeit(_run_fd, number=n_runs)
        results['forward_dynamics'] = t

        # 8. space_robot_ode
        # Build the state vector y = [R0_flat(9); r0(3); u0(6); qm(nq); um(nq)]
        R0_flat = np.asarray(R0, dtype=np.float64).flatten(order='F')
        _y_ode  = np.concatenate([R0_flat, r0, u0, qm, um])
        _tau_ode = np.concatenate([tau0, taum])
        def _run_ode():
            return self.space_robot_ode(0.0, _y_ode, _tau_ode)
        t = _timeit.timeit(_run_ode, number=n_runs)
        results['space_robot_ode'] = t

        # --- Print table ---
        col_w = 20
        print(f"\nBenchmark — {n_runs} runs each  ({self._robot.name})")
        print("─" * 52)
        print(f"{'Function':<{col_w}}  {'Total (s)':>10}  {'Per call (µs)':>14}")
        print("─" * 52)
        for name, total in results.items():
            per_call_us = total / n_runs * 1e6
            print(f"{name:<{col_w}}  {total:>10.4f}  {per_call_us:>12.1f} µs")
        print("─" * 52)
        total_all = sum(results.values())
        print(f"{'TOTAL (pipeline)':<{col_w}}  {total_all:>10.4f}  {total_all/n_runs*1e6:>12.1f} µs")
        print()

    def __repr__(self):
        return f"SPART(robot={self._robot!r})"
