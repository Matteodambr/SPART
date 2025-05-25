function [p_ee, R_ee_I2body] = compute_EE_state_casadi(R0_I2body, r0, qm, robot)


[~, RL, ~, rL, ~, ~] = Kinematics_casadi(R0_I2body', r0, qm, robot) ;

% Retrieve EE state
p_ee = rL(1:3, robot.n_links_joints) ;
R_ee_I2body = RL(1:3, end-2:end)' ;


end