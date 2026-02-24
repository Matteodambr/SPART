% SPART_SPACEROBOT_ODE computes the time derivative of the state vector for a space robot system. The 6+N second order ordinary differential equations are transformed into a 2*(6+N) system, to be compatible with Matlab's integrators.
%
%   dydt = SPART_SPACEROBOT_ODE(t, y, n_joints_manipulator, robot)
%
%
%
%   Inputs:
%       t                    - Current time (scalar)
%       y                    - State vector [R0; r0; w0_body; r0_dot; qm; qm_dot]
%       n_joints_manipulator - Number of manipulator joints (scalar)
%       robot                - Robot structure containing kinematic and dynamic parameters
%
%   Output:
%       dydt                 - Time derivative of the state vector
%
%   The function unpacks the state vector, processes kinematics and dynamics,
%   and computes the forward dynamics for the space robot. It is designed to
%   be used with ODE solvers for simulating the motion of a free-floating
%   space robot with a manipulator.
%
%   Author: Matteo D'Ambrosio
%   Date: 2026-02-24

function dydt = SPART_SPACEROBOT_ODE_C(t, y, tau, nLinksJoints, robotJoints, robotLinks, robotConBranch, robotBaseInertia, nQ, robotBaseLink, robotConChild, robotConChildBase)

% Derivation:
% 2ND order ODE system of 6+N_joints equations needs to be written as a
% system of 2*(6+N_joints) first-order ODEs, for Matlab integrators.
%
% Define state variable transformation:
%   y0a = q0 = [R0; r0]
%   y0b = q0_dot = [w0_body, r0]
%   yma = qm
%   ymb = qm_dot
%   y = [y0a; y0b; yma; ymb] = [R0; r0; w0_body; r0_dot; qm; qm_dot] --> For integration
%
%   y_dot = [R0_dot; r0_dot; w0_body_dot; r0_ddot; qm_dot; qm_ddot] --> Final equation that needs to be integrated
%       where:
%          - The spart Forward Dynamics is used to compute u0dot = [w0_body_dot; r0_ddot] and umdot = qm_ddot
%          - R0_dot comes from DCM kinematics integration, starting from the input w0_body.
%          - The remainder of the equations are directly from the inputted state.
%          - R0_dot is the only exception, since y_dot contains R0_dot and
%          not w0_body! Otherwise, R0 cannot be computed throughout the
%          integration.

%% Unpack variables
% For 6-dof base + 7-dof manipulator, y needs to have 32 elements
q0 = y(1:12) ; % R0(3x3) + r0(3,1); total 12 elements to be reshaped
q0_dot = y(13:18) ;
qm = y(19:19 + nQ - 1) ;
qm_dot = y(19 + nQ:19 + 2*nQ - 1) ;

% Further unpacking
R0_I2body = reshape(q0(1:9), 3, 3) ;
r0 = q0(10:12) ;
w0_body = q0_dot(1:3) ; % The derivative of these values is y0b_dot = u0_dot = q0_ddot = [w0_body_dot; r0_ddot]
r0_dot = q0_dot(4:6) ; % The derivative of these values is y0b_dot = u0_dot = q0_ddot = [w0_body_dot; r0_ddot]

%% Process inputs
R0_I2body = 1.5 * R0_I2body - 0.5 * (R0_I2body * R0_I2body.') * R0_I2body ; % Apply one step of orthonormalization to R0_I2body
R0_body2I = R0_I2body.' ; % Compute input to SPART library

%% Control
tau0 = tau(1:6) ;
taum = tau(7:end) ;
wF0 = zeros(6, 1) ;
wFm = zeros(6, nQ) ;

%% Kinematics

% Compute forward kinematics of multibody system
[ ~, RL, ~, rL, e, g ] = Kinematics_C( R0_body2I, r0, qm, nLinksJoints, robotJoints, robotLinks ) ;

% Compute differential kinematics (twist propagation matrices and vectors) of multibody system
[ Bij, Bi0, P0, pm ] = DiffKinematics_C( R0_body2I, r0, rL, e, g, nLinksJoints, robotConBranch, robotJoints ) ;

% Compute operational-space velocities (twists) of the multibody system
[ t0, tL ] = Velocities_C( Bij, Bi0, P0, pm, q0_dot, qm_dot, nLinksJoints, robotJoints ) ;

% Project link inertias to the inertial CCS
[ I0, Im ] = I_I_C( R0_body2I, RL, nLinksJoints, robotBaseInertia, robotLinks ) ;

%% Dynamics

% Forward dynamics
% u0 = q0_dot ;
% um = qm_dot ;
% DIFFERENCE BETWEEN wF and tau:
%   - wF are wrenches, i.e. external forces applied to each single body, in
%   terms of force and torque. These could represent things like gravity,
%   etc.
%   - tau are generalized forces, i.e. forces directly acting on each joint
%   of the system. Think of this as control commands that you send to your
%   base and to your manipulator joints.
%   - You can convert between the two representations, but it is easier to
%   apply forces separated in this way, especially if you have different
%   actions acting in a combined way, without the need to convert any.
[u0dot, umdot] = FD_C(tau0, taum, wF0, wFm, t0, tL, P0, pm, I0, Im, Bij, Bi0, q0_dot, qm_dot, nLinksJoints, nQ, robotBaseLink, robotLinks, robotConChild, robotConChildBase, robotJoints) ;

%% DCM kinematics

% One step of orthonormalization applied above to R0_I2body, before any computation.

% Compute DCM kinematics
R0_I2body_dot = -SkewSym(w0_body) * R0_I2body ;

%% Find dydt

dydt = [reshape(R0_I2body_dot, 9, 1); r0_dot; u0dot; qm_dot; umdot] ;

end