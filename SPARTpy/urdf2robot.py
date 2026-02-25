"""
urdf2robot.py — Native Python URDF loader for SPART.

Produces a RobotModel whose numeric fields exactly match the output of the
MATLAB urdf2robot.m / ConnectivityMap.m functions (1-based joint / q / link
indexing, same connectivity-map algorithm).

This module is intentionally self-contained and importable without SPARTpy.py.
The same logic is also embedded inside SPARTpy.py so that no extra import is
required there.
"""

import xml.etree.ElementTree as ET
import numpy as np

# --- Data Structures ---

class JointData:
    """Python equivalent for individual joint structure (struct0_T).

    All numeric ids use 1-based indexing to match MATLAB / C-codegen output:
      - id          : 1-based joint index
      - q_id        : 1-based joint-variable index (or -1 for fixed joints)
      - parent_link : 0 = base link, otherwise 1-based
      - child_link  : 1-based link index
    """
    __slots__ = ('id', 'type', 'q_id', 'parent_link', 'child_link', 'axis', 'T')

    def __init__(self, id, type, q_id, parent_link, child_link, axis, T):
        self.id          = float(id)
        self.type        = float(type)
        self.q_id        = float(q_id)
        self.parent_link = float(parent_link)
        self.child_link  = float(child_link)
        self.axis        = np.asarray(axis, dtype=np.float64).flatten()    # (3,)
        self.T           = np.asarray(T,    dtype=np.float64, order='F')   # (4,4)

    def __repr__(self):
        return (f"JointData(id={self.id}, type={self.type}, q_id={self.q_id}, "
                f"parent_link={self.parent_link}, child_link={self.child_link})")


class LinkData:
    """Python equivalent for individual link structure (struct1_T).

    - id           : 1-based link index
    - parent_joint : 1-based joint index
    """
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
        self.con_branch         = np.asarray(con_branch,     dtype=np.float64)
        self.con_child          = np.asarray(con_child,      dtype=np.float64)
        self.con_child_base     = np.asarray(con_child_base, dtype=np.float64).flatten()
        self.base_link_mass     = float(base_link_mass)
        self.base_link_inertia  = np.asarray(base_link_inertia, dtype=np.float64, order='F').reshape(3, 3, order='F')

    def __repr__(self):
        return (f"RobotModel(name='{self.name}', n_q={self.n_q}, "
                f"n_links_joints={self.n_links_joints})")

# --- Helper Functions ---

def _str_to_vec(s):
    """Converts a space-separated string to a numpy array."""
    if not s: return np.zeros(3)
    return np.array([float(x) for x in s.split()])

def _rpy_to_dcm(rpy):
    """Converts URDF Roll-Pitch-Yaw to a Direction Cosine Matrix."""
    r, p, y = rpy
    Rx = np.array([[1, 0, 0],
                   [0, np.cos(r), -np.sin(r)],
                   [0, np.sin(r), np.cos(r)]])
    Ry = np.array([[np.cos(p), 0, np.sin(p)],
                   [0, 1, 0],
                   [-np.sin(p), 0, np.cos(p)]])
    Rz = np.array([[np.cos(y), -np.sin(y), 0],
                   [np.sin(y), np.cos(y), 0],
                   [0, 0, 1]])
    # URDF standard uses fixed-axis Roll (X), then Pitch (Y), then Yaw (Z).
    return Rz @ Ry @ Rx

def _get_transform(origin_elem):
    """Extracts a 4×4 homogeneous transform from an <origin> XML element."""
    T = np.eye(4)
    if origin_elem is not None:
        if 'xyz' in origin_elem.attrib:
            T[:3, 3] = _str_to_vec(origin_elem.attrib['xyz'])
        if 'rpy' in origin_elem.attrib:
            T[:3, :3] = _rpy_to_dcm(_str_to_vec(origin_elem.attrib['rpy']))
    return T


# --- Connectivity Map (port of ConnectivityMap.m) ---

def _connectivity_map(robot):
    """
    Compute the branch / child / child_base connectivity maps.

    Direct Python port of ConnectivityMap.m.  All link and joint indices inside
    the structures are 1-based; link id 0 denotes the base link (no parent).

    Parameters
    ----------
    robot : RobotModel
        Must have joints and links populated with 1-based ids.

    Returns
    -------
    branch     : ndarray (n, n)  — lower-triangular; [i,j]=1 ↔ same branch
    child      : ndarray (n, n)  — [i,j]=1 ↔ link i is a direct child of link j
    child_base : ndarray (n,)    — element i=1 ↔ link i+1 is a child of the base
    """
    n = robot.n_links_joints

    # --- branch map ---
    branch = np.zeros((n, n))
    for i in range(n, 0, -1):          # i = n … 1  (1-based link id)
        last = i
        branch[i - 1, i - 1] = 1.0
        while True:
            pj          = int(robot.links[last - 1].parent_joint)   # 1-based joint id
            parent_link = int(robot.joints[pj - 1].parent_link)     # 0 or 1-based link id
            if parent_link == 0:
                break
            branch[i - 1, parent_link - 1] = 1.0
            last = parent_link

    # --- child / child_base maps ---
    child      = np.zeros((n, n))
    child_base = np.zeros(n)
    for i in range(n, 0, -1):
        pj          = int(robot.links[i - 1].parent_joint)
        parent_link = int(robot.joints[pj - 1].parent_link)
        if parent_link != 0:
            child[i - 1, parent_link - 1] = 1.0
        else:
            child_base[i - 1] = 1.0

    return branch, child, child_base


# --- Main Parsing Function ---

def urdf2robot(filename, verbose_flag=False):
    """
    Creates a SPART robot model from a URDF file natively in Python.
    Returns: (RobotModel, dict of robot_keys)
    """
    tree = ET.parse(filename)
    root = tree.getroot()

    if root.tag != 'robot':
        raise ValueError("URDF contains more than one robot or no robot tag.")

    robot_name = root.attrib.get('name', 'unnamed')

    # Keep only direct children of <robot>
    links_urdf = [child for child in root if child.tag == 'link']
    joints_urdf = [child for child in root if child.tag == 'joint']

    n_links_joints = len(links_urdf)
    if verbose_flag:
        print(f"Number of links: {n_links_joints} (including the base link)")

    # Temporary maps for parsing structure
    links_map = {}
    joints_map = {}

    # Iterate over links
    for link_xml in links_urdf:
        name = link_xml.attrib['name']
        link_T = np.eye(4)
        mass_val = 0.0
        inertia_mat = np.zeros((3, 3))

        inertial = link_xml.find('inertial')
        if inertial is None:
            raise ValueError(
                f"Link '{name}' is missing an <inertial> element.  "
                f"SPART requires mass and inertia data for every link.  "
                f"Add an <inertial> block to this link in the URDF."
            )

        origin = inertial.find('origin')
        link_T = _get_transform(origin)

        mass = inertial.find('mass')
        if mass is not None and 'value' in mass.attrib:
            mass_val = float(mass.attrib['value'])

        inertia = inertial.find('inertia')
        if inertia is not None:
            ixx = float(inertia.attrib.get('ixx', 0))
            iyy = float(inertia.attrib.get('iyy', 0))
            izz = float(inertia.attrib.get('izz', 0))
            ixy = float(inertia.attrib.get('ixy', 0))
            iyz = float(inertia.attrib.get('iyz', 0))
            ixz = float(inertia.attrib.get('ixz', 0))
            inertia_mat = np.array([
                [ixx, ixy, ixz],
                [ixy, iyy, iyz],
                [ixz, iyz, izz]
            ])

        links_map[name] = {
            'name': name,
            'T': link_T,
            'mass': mass_val,
            'inertia': inertia_mat,
            'parent_joint': [],
            'child_joint': []
        }

    # Iterate over joints
    for joint_xml in joints_urdf:
        name = joint_xml.attrib['name']
        j_type_name = joint_xml.attrib.get('type', 'fixed')

        if j_type_name in ('revolute', 'continuous'):
            j_type = 1
        elif j_type_name == 'prismatic':
            j_type = 2
        elif j_type_name == 'fixed':
            j_type = 0
        else:
            raise ValueError(f"Joint type '{j_type_name}' not supported.")

        origin = joint_xml.find('origin')
        joint_T = _get_transform(origin)

        axis = joint_xml.find('axis')
        axis_vec = np.zeros(3)
        if axis is not None and 'xyz' in axis.attrib:
            axis_vec = _str_to_vec(axis.attrib['xyz'])
        elif j_type != 0:
            raise ValueError(f"{name} is a moving joint and requires a joint axis.")

        # Resolve parent
        parent_link = ""
        parent = joint_xml.find('parent')
        if parent is not None:
            parent_link = parent.attrib.get('link', '')
            if parent_link in links_map:
                links_map[parent_link]['child_joint'].append(name)

        # Resolve child
        child_link = ""
        child = joint_xml.find('child')
        if child is not None:
            child_link = child.attrib.get('link', '')
            if child_link in links_map:
                links_map[child_link]['parent_joint'].append(name)

        # MATLAB's: joint.T = parent.T \ joint.T
        if parent_link in links_map:
            parent_T = links_map[parent_link]['T']
            joint_T = np.linalg.inv(parent_T) @ joint_T

        joints_map[name] = {
            'name': name,
            'type': j_type,
            'parent_link': parent_link,
            'child_link': child_link,
            'axis': axis_vec,
            'T': joint_T
        }

    # Identify base link
    base_link = None
    for lname, ldata in links_map.items():
        if not ldata['parent_joint']:
            base_link = lname
            if verbose_flag:
                print(f"Base link: {base_link}")
            break

    if base_link is None:
        raise ValueError("Robot has no single base link!")

    # Set up final mapping logic
    robot_keys = {'link_id': {}, 'joint_id': {}, 'q_id': {}}
    robot_keys['link_id'][base_link] = 0

    n_links_joints -= 1 # Remove base link from standard tally
    clink = links_map[base_link]
    base_link_mass = clink['mass']
    base_link_inertia = clink['inertia']

    robot_joints = []
    robot_links = []

    # Counters (0-based internally; converted to 1-based when stored —
    # matches MATLAB's nl=-1/nj=-1/nq=1 convention after first recursion step)
    counters = {'nl': 0, 'nj': 0, 'nq': 0}

    # Recursive Tree Traversal (mirrors urdf2robot_recursive.m)
    def recurse(c_joint_name):
        cj = joints_map[c_joint_name]

        # 1-based ids — matches MATLAB robot.joints(nj+1).id = nj+1
        j_id = counters['nj'] + 1
        counters['nj'] += 1

        j_type = cj['type']
        if j_type > 0:
            q_id = counters['nq'] + 1   # 1-based q_id
            robot_keys['q_id'][cj['name']] = q_id
            counters['nq'] += 1
        else:
            q_id = -1

        l_id = counters['nl'] + 1       # 1-based link id
        counters['nl'] += 1

        robot_joints.append(JointData(
            id          = j_id,
            type        = j_type,
            q_id        = q_id,
            parent_link = robot_keys['link_id'][cj['parent_link']],
            child_link  = l_id,
            axis        = cj['axis'],
            T           = cj['T'],
        ))

        child_l = links_map[cj['child_link']]
        robot_links.append(LinkData(
            id           = l_id,
            parent_joint = j_id,        # 1-based — matches MATLAB parent_joint=nj+1
            T            = child_l['T'],
            mass         = child_l['mass'],
            inertia      = child_l['inertia'],
        ))

        robot_keys['joint_id'][cj['name']]    = j_id
        robot_keys['link_id'][child_l['name']] = l_id

        # Recurse into children
        for next_j in child_l['child_joint']:
            recurse(next_j)

    # Start recursion from base link's child joints
    for root_j in clink['child_joint']:
        recurse(root_j)

    n_q = counters['nq']
    if verbose_flag:
        print(f"Number of joint variables: {n_q}")

    # Build partial robot so _connectivity_map can traverse it
    robot_partial = RobotModel(
        name              = robot_name,
        n_q               = n_q,
        n_links_joints    = n_links_joints,
        joints            = robot_joints,
        links             = robot_links,
        con_branch        = np.zeros((n_links_joints, n_links_joints)),
        con_child         = np.zeros((n_links_joints, n_links_joints)),
        con_child_base    = np.zeros(n_links_joints),
        base_link_mass    = base_link_mass,
        base_link_inertia = base_link_inertia,
    )

    branch, child, child_base = _connectivity_map(robot_partial)

    robot = RobotModel(
        name              = robot_name,
        n_q               = n_q,
        n_links_joints    = n_links_joints,
        joints            = robot_joints,
        links             = robot_links,
        con_branch        = branch,
        con_child         = child,
        con_child_base    = child_base,
        base_link_mass    = base_link_mass,
        base_link_inertia = base_link_inertia,
    )

    return robot, robot_keys