from PySPART import load_robot
import numpy as np

robot = load_robot('URDF_models/floating_7dof_manipulator.urdf')
print(robot)
print('n_q:', robot.n_q)
print()
print('--- Joints ---')
for j in robot.joints: print(j)
print()
print('--- Links ---')
for l in robot.links: print(l)

print(robot.joints[0].T)   # 4x4 transform, column-major
print(robot.links[0].inertia)  # 3x3 inertia matrix

R0 = np.array([[0.9986, 0, 0.0523],
               [0, 1.0, 0],
               [-0.0523, 0, 0.9986]])
r0 = np.array([[3],
               [1],
               [3]])
qm = np.array([[np.deg2rad(30)],
               [np.deg2rad(20)],
               [np.deg2rad(30)],
               [np.deg2rad(20)],
               [np.deg2rad(30)],
               [np.deg2rad(20)],
               [np.deg2rad(30)]])

# --- Forward Kinematics via Kinematics_C.so ---
from PySPART import kinematics

RJ, RL, rJ, rL, e, g = kinematics(robot, R0, r0.flatten(), qm.flatten())

print('--- Kinematics ---')
print(f'RJ (joint rotations, 3x{3*robot.n_links_joints}):')
print(RJ)
print()
print(f'RL (link rotations,  3x{3*robot.n_links_joints}):')
print(RL)
print()
print(f'rJ (joint positions, 3x{robot.n_links_joints}):')
print(rJ)
print()
print(f'rL (link positions,  3x{robot.n_links_joints}):')
print(rL)
print()
print(f'e  (joint axes,      3x{robot.n_links_joints}):')
print(e)
print()
print(f'g  (joint-to-CoM,    3x{robot.n_links_joints}):')
print(g)
