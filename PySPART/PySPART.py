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
    """Mirrors struct0_T from Kinematics_C_types.h"""
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
    """Mirrors struct1_T from Kinematics_C_types.h"""
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
    __slots__ = ('name', 'n_q', 'n_links_joints', 'joints', 'links')

    def __init__(self, name, n_q, n_links_joints, joints, links):
        self.name            = name
        self.n_q             = int(n_q)
        self.n_links_joints  = int(n_links_joints)
        self.joints          = joints   # list of JointData
        self.links           = links    # list of LinkData

    def __repr__(self):
        return (f"RobotModel(name='{self.name}', n_q={self.n_q}, "
                f"n_links_joints={self.n_links_joints})")


# ---------------------------------------------------------------------------
# ctypes layout for Kinematics_C.so
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

class _EmxReal(ctypes.Structure):        # emxArray_real_T
    _fields_ = [
        ('data',          ctypes.POINTER(ctypes.c_double)),
        ('size',          ctypes.POINTER(ctypes.c_int32)),
        ('allocatedSize', ctypes.c_int32),
        ('numDimensions', ctypes.c_int32),
        ('canFreeData',   ctypes.c_uint8),
    ]

_CODEGEN_ROOT = os.path.join(
    os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
    'codegen', 'dll'
)

# Cache of loaded libraries: {so_path: ctypes.CDLL}
_libs = {}

def _load_so(so_path, init_fn, fn_name, fn_argtypes):
    """
    Load a MATLAB Coder-generated shared library (once) and register its symbols.

    Parameters
    ----------
    so_path    : absolute path to the .so file
    init_fn    : name of the initialise function  (e.g. 'Kinematics_C_initialize')
    fn_name    : name of the main C function      (e.g. 'Kinematics_C')
    fn_argtypes: list of ctypes argument types for fn_name

    Returns
    -------
    The loaded ctypes.CDLL instance.
    """
    if so_path in _libs:
        return _libs[so_path]

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

    # --- register the main function ---
    fn = getattr(lib, fn_name)
    fn.restype  = None
    fn.argtypes = fn_argtypes

    _libs[so_path] = lib
    return lib


def _get_kinematics_lib():
    """Load Kinematics_C.so with its argument types."""
    _p  = ctypes.c_void_p
    _pd = ctypes.POINTER(ctypes.c_double)
    return _load_so(
        so_path    = os.path.join(_CODEGEN_ROOT, 'Kinematics_C', 'Kinematics_C.so'),
        init_fn    = 'Kinematics_C_initialize',
        fn_name    = 'Kinematics_C',
        fn_argtypes= [
            _pd,              # R0[9]
            _pd,              # r0[3]
            _p,               # qm          (emxArray_real_T*)
            ctypes.c_double,  # nLinksJoints
            _p,               # robotJoints (emxArray_struct0_T*)
            _p,               # robotLinks  (emxArray_struct1_T*)
            _p, _p, _p, _p, _p, _p,  # RJ, RL, rJ, rL, e, g  (emxArray_real_T*)
        ]
    )


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
        matching the struct0_T / struct1_T layout expected by Kinematics_C.so.
    """
    eng = _get_engine()

    # Call urdf2robot_py — returns plain numeric matrices (no struct arrays)
    # jointsMatrix: [24 x n]  [id; type; q_id; parent_link; child_link; axis(3); T(16)]
    # linksMatrix:  [28 x n]  [id; parent_joint; T(16); mass; inertia(9)]
    n_links_joints, n_q_ml, robot_name, ml_joints, ml_links = eng.urdf2robot_py(
        urdf_path, nargout=5
    )
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
        name           = name,
        n_q            = n_q,
        n_links_joints = n,
        joints         = joints,
        links          = links,
    )


def kinematics(robot, R0, r0, qm):
    """
    Compute forward kinematics via the compiled Kinematics_C.so.

    Parameters
    ----------
    robot : RobotModel   (from load_robot)
    R0    : (3,3) array  – base rotation matrix (column-major)
    r0    : (3,)  array  – base position vector
    qm    : (n_q,) array – joint angles

    Returns
    -------
    RJ : (3, 3*n) – rotation matrices of each joint
    RL : (3, 3*n) – rotation matrices of each link
    rJ : (3,  n)  – positions of each joint
    rL : (3,  n)  – positions of each link
    e  : (3,  n)  – joint axes in inertial frame
    g  : (3,  n)  – vector from joint to link CoM
    """
    lib = _get_kinematics_lib()
    n   = robot.n_links_joints

    # --- Pack inputs ---
    R0_c  = np.asarray(R0, dtype=np.float64, order='F').flatten(order='F')
    r0_c  = np.asarray(r0, dtype=np.float64).flatten()
    qm_c  = np.asarray(qm, dtype=np.float64).flatten()

    R0_ptr = R0_c.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
    r0_ptr = r0_c.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
    qm_ptr = qm_c.ctypes.data_as(ctypes.POINTER(ctypes.c_double))

    c_joints = _pack_joints(robot)
    c_links  = _pack_links(robot)

    # --- Create emxArray wrappers for inputs ---
    emx_qm = lib.emxCreateWrapper_real_T(
        qm_ptr, ctypes.c_int(len(qm_c)), ctypes.c_int(1)
    )
    emx_joints = lib.emxCreateWrapper_struct0_T(
        ctypes.cast(c_joints, ctypes.c_void_p), ctypes.c_int(1), ctypes.c_int(n)
    )
    emx_links = lib.emxCreateWrapper_struct1_T(
        ctypes.cast(c_links, ctypes.c_void_p), ctypes.c_int(1), ctypes.c_int(n)
    )

    # --- Create empty output emxArrays (C will allocate/resize) ---
    emx_RJ = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
    emx_RL = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
    emx_rJ = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
    emx_rL = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
    emx_e  = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))
    emx_g  = lib.emxCreate_real_T(ctypes.c_int(0), ctypes.c_int(0))

    # --- Call the C function ---
    lib.Kinematics_C(
        R0_ptr, r0_ptr, emx_qm, ctypes.c_double(n),
        emx_joints, emx_links,
        emx_RJ, emx_RL, emx_rJ, emx_rL, emx_e, emx_g
    )

    # --- Read results into numpy arrays before freeing ---
    RJ = _read_emx(emx_RJ)
    RL = _read_emx(emx_RL)
    rJ = _read_emx(emx_rJ)
    rL = _read_emx(emx_rL)
    e  = _read_emx(emx_e)
    g  = _read_emx(emx_g)

    # --- Free C-managed memory ---
    lib.emxDestroyArray_real_T(emx_RJ)
    lib.emxDestroyArray_real_T(emx_RL)
    lib.emxDestroyArray_real_T(emx_rJ)
    lib.emxDestroyArray_real_T(emx_rL)
    lib.emxDestroyArray_real_T(emx_e)
    lib.emxDestroyArray_real_T(emx_g)
    lib.emxDestroyArray_real_T(emx_qm)
    lib.emxDestroyArray_struct0_T(emx_joints)
    lib.emxDestroyArray_struct1_T(emx_links)

    return RJ, RL, rJ, rL, e, g
