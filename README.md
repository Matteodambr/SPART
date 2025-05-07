# SPART

![GitHub last commit](https://img.shields.io/github/last-commit/Matteodambr/SPART) ![GitHub forks](https://img.shields.io/github/forks/NPS-SRL/SPART?style=social) ![GitHub SPART stars](https://img.shields.io/github/stars/NPS-SRL/SPART?style=social) ![GitHub contributors](https://img.shields.io/github/contributors/Matteodambr/SPART) ![Open Issues](https://img.shields.io/github/issues-raw/NPS-SRL/SPART) ![Top Language](https://img.shields.io/github/languages/top/Matteodambr/SPART) ![Code Size](https://img.shields.io/github/languages/code-size/Matteodambr/SPART) ![GitHub issues](https://img.shields.io/github/issues/NPS-SRL/SPART) ![GitHub pull requests](https://img.shields.io/github/issues-pr/NPS-SRL/SPART)

> [!IMPORTANT]  
> The main changes conducted to the original repository consist in updating some of the kinematics/dynamics functions, updating some inputs, and mexing them for increased execution speed, as well as adding some custom URDF space robot files.

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


