robot = urdf2robot('floating_7dof_manipulator.urdf') ;

R0 = [0.9986, 0, 0.0523; 0, 1.0, 0; -0.0523, 0, 0.9986] ;
r0 = [3;1;3] ;
qm = deg2rad([30,20,30,20,30,20,30]') ;

% Test kinematics
[RJ, RL, rJ, rL, e, g] = Kinematics_C(R0, r0, qm, robot.n_links_joints, robot.joints, robot.links) 