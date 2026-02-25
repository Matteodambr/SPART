"""
test_urdf2robot.py
==================

Verifies that the native Python URDF loader (SPARTpy._parse_urdf /
SPARTpy.load_robot and the standalone urdf2robot.py) produces results
that are numerically identical to the MATLAB engine path
(SPARTpy._load_robot_matlab), and validates internal consistency
(1-based indexing, connectivity-map shape and logical content, etc.).

Running
-------
From the repository root::

    python -m pytest SPARTpy/tests/test_urdf2robot.py -v

Or directly::

    cd SPARTpy/tests
    python test_urdf2robot.py

MATLAB comparison tests are automatically skipped when matlab.engine is not
installed, so the suite runs without a MATLAB licence.
"""

import os
import sys
import types
import unittest
import numpy as np

# ---------------------------------------------------------------------------
# Path setup — allow importing SPARTpy.py and urdf2robot.py without install
# ---------------------------------------------------------------------------
_HERE       = os.path.dirname(os.path.abspath(__file__))
_SPART_PY   = os.path.dirname(_HERE)                           # SPARTpy/
_REPO_ROOT  = os.path.dirname(_SPART_PY)                      # SPART/
_URDF_DIR   = os.path.join(_REPO_ROOT, 'URDF_models')

# Add SPARTpy package directory to sys.path
if _SPART_PY not in sys.path:
    sys.path.insert(0, _SPART_PY)
if _REPO_ROOT not in sys.path:
    sys.path.insert(0, _REPO_ROOT)

# ---------------------------------------------------------------------------
# Imports — SPARTpy import is deferred + guarded so that missing libiomp5.so
# or other C-level deps do not break the URDF-parsing tests.
# ---------------------------------------------------------------------------

# Import the standalone urdf2robot module
import urdf2robot as _u2r_standalone

# Import SPARTpy functions — we import from the module directly (not just the
# package __init__) so that private functions (_parse_urdf, _load_robot_matlab)
# are accessible for comparison tests.
from SPARTpy.SPARTpy import (  # noqa: E402
    load_robot       as _load_robot,
    _parse_urdf      as _load_robot_fast,
    _load_robot_matlab,
)

# Check MATLAB availability once
_MATLAB_AVAILABLE = False
try:
    import matlab.engine  # noqa: F401
    _MATLAB_AVAILABLE = True
except (ImportError, ModuleNotFoundError):
    pass

# ---------------------------------------------------------------------------
# URDF files to exercise
# ---------------------------------------------------------------------------
_URDFS = {
    # name                              : path, expected_n_q, expected_n_links_joints
    'floating_7dof':   (os.path.join(_URDF_DIR, 'floating_7dof_manipulator.urdf'),        7, 8),
    'floating_4dof':   (os.path.join(_URDF_DIR, 'floating_planar_4dof_manipulator.urdf'),  4, 5),
    'kuka_iiwa':       (os.path.join(_URDF_DIR, 'kuka_iiwa.urdf'),    7, 7),
    'kuka_lwr':        (os.path.join(_URDF_DIR, 'kuka_lwr.urdf'),     7, 7),
    'SC_3DoF':         (os.path.join(_URDF_DIR, 'SC_3DoF.urdf'),      3, 5),
    'simple_sc':       (os.path.join(_URDF_DIR, 'Simple_Spacecraft.urdf'), 0, 3),
}

# URDFs that are intentionally malformed (used by TestMissingInertialError).
# Each entry maps to the link name that is missing its <inertial> block.
_INVALID_URDFS = {
    'fixed_4dof': (os.path.join(_URDF_DIR, 'fixed_planar_4dof_manipulator.urdf'), 'base'),
}

# Filter out files not present on disk
_URDFS         = {k: v for k, v in _URDFS.items()         if os.path.isfile(v[0])}
_INVALID_URDFS = {k: v for k, v in _INVALID_URDFS.items() if os.path.isfile(v[0])}


def _robot_fields_equal(r1, r2, tol=1e-10, tag=''):
    """Assert that two RobotModel instances have identical numeric content."""
    assert r1.n_q            == r2.n_q,            f"{tag} n_q mismatch: {r1.n_q} != {r2.n_q}"
    assert r1.n_links_joints == r2.n_links_joints, (
        f"{tag} n_links_joints mismatch: {r1.n_links_joints} != {r2.n_links_joints}")
    assert r1.name           == r2.name,           f"{tag} name mismatch"

    n = r1.n_links_joints
    np.testing.assert_allclose(r1.base_link_mass,    r2.base_link_mass,    atol=tol,
                                err_msg=f"{tag} base_link_mass")
    np.testing.assert_allclose(r1.base_link_inertia, r2.base_link_inertia, atol=tol,
                                err_msg=f"{tag} base_link_inertia")
    np.testing.assert_allclose(r1.con_branch,        r2.con_branch,        atol=tol,
                                err_msg=f"{tag} con_branch")
    np.testing.assert_allclose(r1.con_child,         r2.con_child,         atol=tol,
                                err_msg=f"{tag} con_child")
    np.testing.assert_allclose(r1.con_child_base,    r2.con_child_base,    atol=tol,
                                err_msg=f"{tag} con_child_base")

    for i in range(n):
        j1, j2 = r1.joints[i], r2.joints[i]
        np.testing.assert_allclose(j1.id,          j2.id,          atol=tol,
                                    err_msg=f"{tag} joints[{i}].id")
        np.testing.assert_allclose(j1.type,        j2.type,        atol=tol,
                                    err_msg=f"{tag} joints[{i}].type")
        np.testing.assert_allclose(j1.q_id,        j2.q_id,        atol=tol,
                                    err_msg=f"{tag} joints[{i}].q_id")
        np.testing.assert_allclose(j1.parent_link, j2.parent_link, atol=tol,
                                    err_msg=f"{tag} joints[{i}].parent_link")
        np.testing.assert_allclose(j1.child_link,  j2.child_link,  atol=tol,
                                    err_msg=f"{tag} joints[{i}].child_link")
        np.testing.assert_allclose(j1.axis, j2.axis, atol=tol,
                                    err_msg=f"{tag} joints[{i}].axis")
        np.testing.assert_allclose(j1.T, j2.T, atol=tol,
                                    err_msg=f"{tag} joints[{i}].T")

        l1, l2 = r1.links[i], r2.links[i]
        np.testing.assert_allclose(l1.id,           l2.id,           atol=tol,
                                    err_msg=f"{tag} links[{i}].id")
        np.testing.assert_allclose(l1.parent_joint, l2.parent_joint, atol=tol,
                                    err_msg=f"{tag} links[{i}].parent_joint")
        np.testing.assert_allclose(l1.mass,         l2.mass,         atol=tol,
                                    err_msg=f"{tag} links[{i}].mass")
        np.testing.assert_allclose(l1.inertia, l2.inertia, atol=tol,
                                    err_msg=f"{tag} links[{i}].inertia")
        np.testing.assert_allclose(l1.T, l2.T, atol=tol,
                                    err_msg=f"{tag} links[{i}].T")


# ===========================================================================
# Test cases
# ===========================================================================

class TestMissingInertialError(unittest.TestCase):
    """
    Verify that a clear ValueError is raised when any link is missing its
    <inertial> element, and that the error message names the offending link.
    """

    def _check(self, path, bad_link_name):
        with self.assertRaises(ValueError) as ctx:
            _load_robot(path)
        msg = str(ctx.exception)
        self.assertIn(bad_link_name, msg,
                      f"Error message should mention the offending link '{bad_link_name}'")
        self.assertIn('<inertial>', msg,
                      "Error message should mention the missing tag")

    def test_missing_inertial(self):
        for label, (path, bad_link) in _INVALID_URDFS.items():
            with self.subTest(urdf=label):
                self._check(path, bad_link)


class TestBasicFields(unittest.TestCase):
    """Smoke: load each URDF and check expected n_q / n_links_joints."""

    def _check(self, path, exp_n_q, exp_n_lj):
        robot = _load_robot(path)
        self.assertEqual(robot.n_q,            exp_n_q,  f"n_q for {path}")
        self.assertEqual(robot.n_links_joints, exp_n_lj, f"n_links_joints for {path}")
        self.assertIsInstance(robot.name, str)
        self.assertEqual(len(robot.joints), exp_n_lj)
        self.assertEqual(len(robot.links),  exp_n_lj)
        if exp_n_lj > 0:
            self.assertGreater(len(robot.joints), 0)

    def test_urdf_files(self):
        for label, (path, n_q, n_lj) in _URDFS.items():
            with self.subTest(urdf=label):
                self._check(path, n_q, n_lj)


class TestOneBasedIndexing(unittest.TestCase):
    """
    Verify that all joint/link numeric ids are 1-based (matching MATLAB).

    MATLAB convention:
      joint.id          in {1, 2, …, n}
      joint.q_id        in {1, 2, …, n_q}  (or –1 for fixed joints)
      joint.child_link  in {1, 2, …, n}
      joint.parent_link in {0, 1, …, n}   (0 = base)
      link.id           in {1, 2, …, n}
      link.parent_joint in {1, 2, …, n}
    """

    def _check(self, path):
        robot = _load_robot(path)
        n     = robot.n_links_joints
        seen_q_ids = set()

        for k, joint in enumerate(robot.joints):
            self.assertEqual(joint.id, k + 1,
                             f"joint[{k}].id should be {k+1} (1-based)")
            self.assertIn(joint.type, (0.0, 1.0, 2.0),
                          f"joint[{k}].type must be 0/1/2")
            if joint.type > 0:
                self.assertGreaterEqual(joint.q_id, 1.0,
                                        f"joint[{k}].q_id must be >= 1")
                self.assertNotIn(joint.q_id, seen_q_ids,
                                 f"duplicate q_id {joint.q_id}")
                seen_q_ids.add(joint.q_id)
            else:
                self.assertEqual(joint.q_id, -1.0,
                                 f"fixed joint[{k}].q_id must be -1")

            self.assertGreaterEqual(joint.parent_link, 0.0,
                                    f"joint[{k}].parent_link must be >= 0")
            self.assertGreater(joint.child_link, 0.0,
                               f"joint[{k}].child_link must be >= 1")

        for k, link in enumerate(robot.links):
            self.assertEqual(link.id, k + 1,
                             f"link[{k}].id should be {k+1} (1-based)")
            self.assertGreaterEqual(link.parent_joint, 1.0,
                                    f"link[{k}].parent_joint must be >= 1")
            self.assertLessEqual(link.parent_joint, n,
                                 f"link[{k}].parent_joint must be <= n={n}")

    def test_indexing(self):
        for label, (path, *_) in _URDFS.items():
            with self.subTest(urdf=label):
                self._check(path)


class TestConnectivityMap(unittest.TestCase):
    """
    Validate structural properties of the connectivity maps.

    Expected properties (from ConnectivityMap.m documentation):
      branch[i,i] == 1                  for all i  (diagonal)
      branch is lower-triangular        (depth-first numbering)
      sum(child_base) + col_sum(child) == 1 per link  (unique parent)
      each link has exactly one parent (base or other link)
    """

    def _check(self, path):
        robot = _load_robot(path)
        n     = robot.n_links_joints
        B     = robot.con_branch        # (n, n)
        C     = robot.con_child         # (n, n)
        Cb    = robot.con_child_base    # (n,)

        self.assertEqual(B.shape,  (n, n))
        self.assertEqual(C.shape,  (n, n))
        self.assertEqual(Cb.shape, (n,))

        # Diagonal of branch must be all ones
        np.testing.assert_array_equal(np.diag(B), np.ones(n),
                                      err_msg="branch diagonal must be all 1")

        # Branch is lower-triangular (depth-first: parent always has lower index)
        upper_tri = np.triu(B, k=1)
        np.testing.assert_array_equal(upper_tri, np.zeros_like(upper_tri),
                                      err_msg="branch must be lower-triangular")

        # Each link has exactly one parent: either the base (Cb[i]=1) or
        # another link (exactly one C[i,j]=1 for some j).
        for i in range(n):
            n_parents = int(Cb[i]) + int(C[i, :].sum())
            self.assertEqual(n_parents, 1,
                             f"link {i+1} must have exactly 1 parent, got {n_parents}")

        # con_branch and con_child contain only 0s and 1s
        self.assertTrue(np.all((B == 0) | (B == 1)), "branch values must be 0 or 1")
        self.assertTrue(np.all((C == 0) | (C == 1)), "child values must be 0 or 1")
        self.assertTrue(np.all((Cb == 0) | (Cb == 1)), "child_base values must be 0 or 1")

    def test_connectivity(self):
        for label, (path, *_) in _URDFS.items():
            with self.subTest(urdf=label):
                self._check(path)


class TestStandaloneVsSPARTpy(unittest.TestCase):
    """
    Verify that the standalone urdf2robot.py and SPARTpy._parse_urdf give
    numerically identical results for every available URDF.
    """

    def _robot_to_arrays(self, robot):
        """Flatten a robot into a dict of numpy arrays for comparison."""
        n   = robot.n_links_joints
        j_T = np.stack([r.T.flatten(order='F') for r in robot.joints])   # (n,16)
        l_T = np.stack([r.T.flatten(order='F') for r in robot.links])    # (n,16)
        return {
            'n_q':            robot.n_q,
            'n_lj':           n,
            'base_mass':      robot.base_link_mass,
            'base_inertia':   robot.base_link_inertia.flatten(),
            'joint_ids':      [j.id       for j in robot.joints],
            'joint_types':    [j.type     for j in robot.joints],
            'joint_q_ids':    [j.q_id     for j in robot.joints],
            'joint_plinks':   [j.parent_link for j in robot.joints],
            'joint_clinks':   [j.child_link  for j in robot.joints],
            'joint_axes':     np.stack([j.axis for j in robot.joints]),
            'joint_T':        j_T,
            'link_ids':       [l.id           for l in robot.links],
            'link_pjoints':   [l.parent_joint for l in robot.links],
            'link_mass':      [l.mass         for l in robot.links],
            'link_inertia':   np.stack([l.inertia.flatten() for l in robot.links]),
            'link_T':         l_T,
            'con_branch':     robot.con_branch,
            'con_child':      robot.con_child,
            'con_child_base': robot.con_child_base,
        }

    def _check(self, path):
        r_standalone, _ = _u2r_standalone.urdf2robot(path)
        r_spart,      _ = _load_robot_fast(path)

        a1 = self._robot_to_arrays(r_standalone)
        a2 = self._robot_to_arrays(r_spart)

        self.assertEqual(a1['n_q'],  a2['n_q'],  "n_q")
        self.assertEqual(a1['n_lj'], a2['n_lj'], "n_links_joints")
        self.assertAlmostEqual(a1['base_mass'], a2['base_mass'], places=12,
                               msg="base_link_mass")
        np.testing.assert_allclose(a1['base_inertia'], a2['base_inertia'], atol=1e-12)

        for key in ('joint_ids', 'joint_types', 'joint_q_ids',
                    'joint_plinks', 'joint_clinks'):
            self.assertEqual(a1[key], a2[key], key)

        for key in ('joint_axes', 'joint_T', 'link_inertia', 'link_T',
                    'con_branch', 'con_child', 'con_child_base'):
            np.testing.assert_allclose(a1[key], a2[key], atol=1e-12,
                                       err_msg=f"mismatch in {key}")

        for key in ('link_ids', 'link_pjoints'):
            self.assertEqual(a1[key], a2[key], key)

        np.testing.assert_allclose(a1['link_mass'], a2['link_mass'], atol=1e-12)

    def test_standalone_vs_spart(self):
        for label, (path, *_) in _URDFS.items():
            with self.subTest(urdf=label):
                self._check(path)


@unittest.skipUnless(_MATLAB_AVAILABLE,
                     "matlab.engine not installed — skipping MATLAB comparison")
class TestNativePythonVsMATLAB(unittest.TestCase):
    """
    Compare the native Python loader against the MATLAB engine loader for
    every available URDF file.

    These tests are automatically skipped when matlab.engine is not present.

    Notes
    -----
    ``fixed_planar_4dof_manipulator.urdf`` is excluded from this comparison
    because it contains a root link with no ``<inertial>`` element.  The Python
    loader handles this gracefully (defaults to zero mass/inertia), while the
    original MATLAB ``urdf2robot.m`` crashes with a null-pointer error on such
    links — a pre-existing upstream bug that is out of scope here.
    """

    # URDFs that the MATLAB engine cannot parse due to pre-existing bugs
    _MATLAB_SKIP: set = set()  # all valid URDFs are now parseable by MATLAB

    def _check(self, path):
        r_py  = _load_robot(path)
        r_mat = _load_robot_matlab(os.path.abspath(path))
        _robot_fields_equal(r_py, r_mat, tol=1e-10,
                            tag=f"native-Python vs MATLAB ({os.path.basename(path)})")

    def test_vs_matlab(self):
        for label, (path, *_) in _URDFS.items():
            with self.subTest(urdf=label):
                self._check(path)


# ---------------------------------------------------------------------------
# Quick CLI runner
# ---------------------------------------------------------------------------

if __name__ == '__main__':
    import textwrap

    available = list(_URDFS.keys())
    print(f"Found {len(available)} URDF file(s): {available}")
    print(f"MATLAB engine available: {_MATLAB_AVAILABLE}")
    print()
    unittest.main(verbosity=2)
