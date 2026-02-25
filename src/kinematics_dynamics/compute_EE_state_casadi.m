function [p_ee, R_ee_I2body] = compute_EE_state_casadi(R0_I2body, r0, qm, robot)
% Computes the end-effector position and orientation (CasADi-compatible).
%
% :parameters:
%   * R0_I2body -- Active rotation from the inertial CCS to the base-link body CCS [3x3].
%                  V_B = R0_I2body * V_I  (maps inertial-frame vectors to the body frame).
%                  NOTE: This is the INERTIAL->BODY active rotation, the transpose of R0_body2I
%                  that the core SPART Kinematics/DiffKinematics functions expect.  It is
%                  transposed internally before being forwarded to Kinematics_casadi.
%
% :return:
%   * p_ee       -- End-effector CoM position in the inertial frame [3x1].
%   * R_ee_I2body -- Active rotation from the inertial CCS to the end-effector body CCS [3x3].
%                    V_ee = R_ee_I2body * V_I.


[~, RL, ~, rL, ~, ~] = Kinematics_casadi(R0_I2body', r0, qm, robot) ;

% Retrieve EE state
p_ee = rL(1:3, robot.n_links_joints) ;
R_ee_I2body = RL(1:3, end-2:end)' ;


end