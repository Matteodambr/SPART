function [p_ee, R_ee_I2body] = compute_EE_state_C(R0_I2body, r0, qm, nLinksJoints, robotJoints, robotLinks)

[~, RL, ~, rL, ~, ~] = Kinematics_C(R0_I2body', r0, qm, nLinksJoints, robotJoints, robotLinks) ;

% Retrieve EE state
p_ee = rL(1:3, nLinksJoints) ;
R_ee_I2body = RL(1:3, end-2:end)' ;

end
