function [x_ee, y_ee, angee] = compute_EE_state_planar_casadi(ang0, x0, y0, qm, robot)

% p_ee = [x_ee, y_ee, z_ee = 0]
% R_ee = planar_z_angle_to_dcm_rad(angee)

% Outputs:
% x_ee [m]
% y_ee [m]
% angee [rad]

% Compute full DCM
R0_I2body = planar_z_angle_to_dcm_rad(ang0) ;

% Compute forward kinematics
[~, RL, ~, rL, ~, ~] = Kinematics_casadi(R0_I2body', [x0; y0; 0], qm, robot) ;

% Retrieve EE state
x_ee = rL(1, robot.n_links_joints) ;
y_ee = rL(2, robot.n_links_joints) ;
Angles321 = DCM_Angles321(RL(1:3, end-2:end)) ;
angee = -Angles321(3) ; % - sign is because SPART computes the R_ee_body2I matrix (RL), that needs to be inverted. Same as inverting the sign of the angle around the z-axis.

end