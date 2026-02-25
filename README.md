# SPART-2.0

![GitHub last commit](https://img.shields.io/github/last-commit/Matteodambr/SPART) ![GitHub forks](https://img.shields.io/github/forks/NPS-SRL/SPART?style=social) ![GitHub SPART stars](https://img.shields.io/github/stars/NPS-SRL/SPART?style=social) ![GitHub contributors](https://img.shields.io/github/contributors/Matteodambr/SPART) ![Open Issues](https://img.shields.io/github/issues-raw/NPS-SRL/SPART) ![Top Language](https://img.shields.io/github/languages/top/Matteodambr/SPART) ![Code Size](https://img.shields.io/github/languages/code-size/Matteodambr/SPART) ![GitHub issues](https://img.shields.io/github/issues/NPS-SRL/SPART) ![GitHub pull requests](https://img.shields.io/github/issues-pr/NPS-SRL/SPART)

This repository builds on the original SPART library ([link](https://github.com/NPS-SRL/SPART)) that is no longer maintained, adding additional functionalities and modules that are useful when dealing with floating-base systems. Many of the original SPART functions have been updated for compatibility with Matlab code generation and their relevant C files have been generated as dynamic libraries, so that they can be linked to other projects, while maintaining full flexibility for any inputted URDF model without the need to rebuild the scripts. Finally, the biggest update has been to create a Python module to automatically call the code-generated SPART C/C++ functions directly in Python, demonstrating the overall higher efficiency in the function calls with respect to the native Matlab execution. This is used for a smoother integration within Python robotics/AI modules and research projects that are currently ongoing.

The main updates to this repo are the following:
1. Development of a Python module (`SPARTpy`) to directly use highly efficient SPART code-generated C functions in Python — faster than direct calls in MATLAB, even accounting for all Python overhead.
2. Added new space robot URDF models: a 3D system with a 7-DoF manipulator, and a 2D system with a 4-DoF manipulator, both redundant and easily customizable from their respective URDF files.
3. Added ODE functions for integrating the dynamics of the space robot, both in Simulink and MATLAB (WIP: Python ODE).
4. Added initial condition generation and postprocessing functions for simpler handling of dynamics integration.
5. Homogenized input handling of SPART functions to make conventions consistent and more user-friendly.

---

## SPARTpy — Python Package

### Installation

```bash
pip install spartpy
```

The package ships the MATLAB Coder-generated C sources. On the first import on a new machine, `gcc` is called automatically to compile them into a shared library (`SPART_C.so`).

**Requirements:**
- `gcc` with OpenMP: `sudo apt install gcc`
- Intel OpenMP runtime (`libiomp5.so`): included with any MATLAB installation, or install via `conda install -c intel openmp`

See the [SPARTpy README](SPARTpy/README.md) for full details on the build process.

### Quick Start

```python
import os
import numpy as np
from SPARTpy import SPART

# Load a URDF model
urdf = os.path.join('URDF_models', 'floating_7dof_manipulator.urdf')
spart = SPART(urdf)

# Robot state
R0    = np.eye(3)                                          # base orientation (DCM)
r0    = np.array([0., 0., 0.])                            # base position [m]
qm    = np.deg2rad([30., 20., 30., 20., 30., 20., 30.])  # joint angles [rad]
u0    = np.array([0.1, 0.2, 0.3, 0.4, 0.5, 0.6])        # base twist [m/s, rad/s]
um    = np.array([0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7])   # joint rates [rad/s]
u0dot = np.zeros(6)   # base acceleration
umdot = np.zeros(7)   # joint acceleration
wF0   = np.zeros(6)   # external wrench on base
wFm   = np.zeros((6, spart.robot.n_links_joints))  # external wrenches on links

# Kinematics
RJ, RL, rJ, rL, e, g = spart.kinematics(R0, r0, qm)

# Differential kinematics
Bij, Bi0, P0, pm = spart.diff_kinematics(R0, r0, rL, e, g)

# Velocities
t0, tL = spart.velocities(Bij, Bi0, P0, pm, u0, um)

# Inertias in inertial frame
I0, Im = spart.i_i(R0, RL)

# Accelerations
t0dot, tLdot = spart.accelerations(t0, tL, P0, pm, Bi0, Bij, u0, um, u0dot, umdot)

# Inverse dynamics
tau0, taum = spart.inverse_dynamics(wF0, wFm, t0, tL, t0dot, tLdot, P0, pm, I0, Im, Bij, Bi0)

# Forward dynamics
u0dot_out, umdot_out = spart.forward_dynamics(
    tau0, taum, wF0, wFm, t0, tL, P0, pm, I0, Im, Bij, Bi0, u0, um)

# Trajectory integration (requires scipy)
from scipy.integrate import solve_ivp

tau0_traj = np.zeros((6, 1))                         # no base torque
taum_traj = np.array([2., 1., 0.5, 0., 0., 0., 0.]) # joint torques [Nm]

_, y0, tau_ode = spart.space_robot_ode_input(
    0.0, R0, r0, np.zeros(6), qm, np.zeros(7), tau0_traj, taum_traj)

sol = solve_ivp(
    fun=lambda t, y: spart.space_robot_ode(t, y, tau_ode),
    t_span=(0.0, 10.0), y0=y0, method='RK45', max_step=0.05)

# Animate result (requires yourdfpy or matplotlib)
spart.animate_trajectory(sol.t, sol.y.T, fps=30, backend='matplotlib')
```

---

# Copy of the Original SPART README:

[Read the Docs - README](https://spart.readthedocs.io/en/latest/)

[Github - README](https://github.com/NPS-SRL/SPAR)

SPART is an open-source modeling and control toolkit for mobile-base robotic multibody systems with kinematic tree topologies (*i.e.*, open-loop multi-branched systems).
SPART is MATLAB-based and ROS-compatible, allowing to prototype in simulation and deploy to hardware controllers for robotic systems.

Given a URDF description of a multibody system, SPART computes the system's:

* Kinematics -- pose of the links and joints (`i.e.`, rotation matrices and position vectors).
* Differential kinematics -- operational space velocities and accelerations, as well as the geometric Jacobians and their time derivatives.
* Dynamics -- generalized inertia and convective inertia matrices.
* Forward/Inverse dynamics -- solves both problems, including the floating-base case.

SPART supports symbolic computation and analytic expressions for all kinematic and dynamic quantities can be obtained.

One of the main benefits of SPART is the following, "In addition to modeling the kinematics and dynamics, the resulting Simulink models are suitable for code generation and thus can be readily compiled and executed into embedded hardware or integrated with third party tools, and includes tools to help the user create control and analysis applications."

## Installation

Just clone or download the toolkit and run the `SPART2path.m` script. This will add all the SPART MATLAB functions and the Simulink library to the path and save it. Then you can use it as any other MATLAB toolbox.

To run an example go to `Examples/URDF_Tutorial` and run:

	URDF_Tutorial

## Documentation

Up to date documentation and tutorials are available at [spart.readthedocs.org](http://spart.readthedocs.org).

## Examples

Here is an example of a planar Desired-Reaction-Maneuver, where the kinematic redundancy of a manipulator is exploited to make the floating base point towards the end-effector, while this one is moving along a prescribed path.

![DRM](docs/source/Figures/DRM.gif "Desired-Reaction-Maneuver")

SPART can also be used to control real manipulators. Here is an example of resolved motion-rate control of the R5D3 manipulator (the tip of the end-effector is describing a triangle in space).

![R5D3](docs/source/Figures/R5D3.gif "R5D3 resolved motion-rate control")

## License

This software is released under the LGPLv3 license.


