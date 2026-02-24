robot = urdf2robot('floating_7dof_manipulator.urdf') ;

R0 = [0.9986, 0, 0.0523; 0, 1.0, 0; -0.0523, 0, 0.9986] ;
r0 = [3;1;3] ;
qm = deg2rad([30,20,30,20,30,20,30]') ;
u0 = [0.1; 0.2; 0.3; 0.4; 0.5; 0.6] ;
um = [0.1; 0.2; 0.3; 0.4; 0.5; 0.6; 0.7] ;
u0dot = [0.01; 0.02; 0.03; 0.04; 0.05; 0.06] ;
umdot = [0.01; 0.02; 0.03; 0.04; 0.05; 0.06; 0.07] ;
wF0 = zeros(6, 1) ;
wFm = zeros(6, robot.n_links_joints) ;

nLinksJoints    = robot.n_links_joints ;
robotJoints     = robot.joints ;
robotLinks      = robot.links ;
robotConBranch  = robot.con.branch ;
robotBaseLink   = robot.base_link ;
nQ              = robot.n_q ;
robotBaseInertia = robot.base_link.inertia ;
robotConChild   = robot.con.child ;
robotConChildBase = robot.con.child_base ;

%% --- Kinematics_C ---
[RJ, RL, rJ, rL, e, g] = Kinematics_C(R0, r0, qm, nLinksJoints, robotJoints, robotLinks)

%% --- DiffKinematics_C ---
[Bij, Bi0, P0, pm] = DiffKinematics_C(R0, r0, rL, e, g, nLinksJoints, robotConBranch, robotJoints)

%% --- Velocities_C ---
[t0, tL] = Velocities_C(Bij, Bi0, P0, pm, u0, um, nLinksJoints, robotJoints)

%% --- I_I_C ---
[I0, Im] = I_I_C(R0, RL, nLinksJoints, robotBaseInertia, robotLinks)

%% --- Accelerations_C ---
[t0dot, tLdot] = Accelerations_C(t0, tL, P0, pm, Bi0, Bij, u0, um, u0dot, umdot, nLinksJoints, robotJoints)

%% --- ID_C ---
[tau0, taum] = ID_C(wF0, wFm, t0, tL, t0dot, tLdot, P0, pm, I0, Im, Bij, Bi0, nLinksJoints, nQ, robotBaseLink, robotLinks, robotConChild, robotConChildBase, robotJoints)

%% --- FD_C ---
[u0dot_out, umdot_out] = FD_C(tau0, taum, wF0, wFm, t0, tL, P0, pm, I0, Im, Bij, Bi0, u0, um, nLinksJoints, nQ, robotBaseLink, robotLinks, robotConChild, robotConChildBase, robotJoints)
