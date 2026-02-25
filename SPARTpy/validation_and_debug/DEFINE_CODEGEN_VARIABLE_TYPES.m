robot = urdf2robot('floating_7dof_manipulator.urdf') ;
% robot = urdf2robot('floating_planar_4dof_manipulator.urdf') ;

% R0_body2I: active rotation, body CCS → inertial CCS  (V_I = R0_body2I * V_B)
% R0_I2body: active rotation, inertial CCS → body CCS   (V_B = R0_I2body * V_I)
% Relationship: R0_I2body = R0_body2I'
R0_body2I = [0.9986, 0, 0.0523; 0, 1.0, 0; -0.0523, 0, 0.9986] ;
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

t = 1 ;
% ODE state stores R0_I2body (active I→B), not R0_body2I
y = [R0_body2I'(:); r0; u0; qm; um] ;
tau = [1;2;3;4;5;6;1*ones(nQ,1)] ;

%% --- Kinematics_C ---
[RJ, RL, rJ, rL, e, g] = Kinematics_C(R0_body2I, r0, qm, nLinksJoints, robotJoints, robotLinks)

%% --- DiffKinematics_C ---
[Bij, Bi0, P0, pm] = DiffKinematics_C(R0_body2I, r0, rL, e, g, nLinksJoints, robotConBranch, robotJoints)

%% --- Velocities_C ---
[t0, tL] = Velocities_C(Bij, Bi0, P0, pm, u0, um, nLinksJoints, robotJoints)

%% --- I_I_C ---
[I0, Im] = I_I_C(R0_body2I, RL, nLinksJoints, robotBaseInertia, robotLinks)

%% --- Accelerations_C ---
[t0dot, tLdot] = Accelerations_C(t0, tL, P0, pm, Bi0, Bij, u0, um, u0dot, umdot, nLinksJoints, robotJoints)

%% --- ID_C ---
[tau0, taum] = ID_C(wF0, wFm, t0, tL, t0dot, tLdot, P0, pm, I0, Im, Bij, Bi0, nLinksJoints, nQ, robotBaseLink, robotLinks, robotConChild, robotConChildBase, robotJoints)

%% --- FD_C ---
[u0dot_out, umdot_out] = FD_C(tau0, taum, wF0, wFm, t0, tL, P0, pm, I0, Im, Bij, Bi0, u0, um, nLinksJoints, nQ, robotBaseLink, robotLinks, robotConChild, robotConChildBase, robotJoints)

%% --- SPART_SPACEROBOT_ODE_C ---
dydt = SPART_SPACEROBOT_ODE_C(t, y, tau, nLinksJoints, robotJoints, robotLinks, robotConBranch, robotBaseInertia, nQ, robotBaseLink, robotConChild, robotConChildBase)

%% =========================================================
%  Benchmark — 5000 runs each
%  =========================================================
N = 5000;
fn_names = {'Kinematics_C','DiffKinematics_C','Velocities_C','I_I_C','Accelerations_C','ID_C','FD_C','SPART_SPACEROBOT_ODE_C'};
times = zeros(1, numel(fn_names));

% 1. Kinematics_C
t_bench = tic;
for k = 1:N
    [RJ_b, RL_b, rJ_b, rL_b, e_b, g_b] = Kinematics_C(R0_body2I, r0, qm, nLinksJoints, robotJoints, robotLinks);
end
times(1) = toc(t_bench);

% 2. DiffKinematics_C
t_bench = tic;
for k = 1:N
    [Bij_b, Bi0_b, P0_b, pm_b] = DiffKinematics_C(R0_body2I, r0, rL, e, g, nLinksJoints, robotConBranch, robotJoints);
end
times(2) = toc(t_bench);

% 3. Velocities_C
t_bench = tic;
for k = 1:N
    [t0_b, tL_b] = Velocities_C(Bij, Bi0, P0, pm, u0, um, nLinksJoints, robotJoints);
end
times(3) = toc(t_bench);

% 4. I_I_C
t_bench = tic;
for k = 1:N
    [I0_b, Im_b] = I_I_C(R0_body2I, RL, nLinksJoints, robotBaseInertia, robotLinks);
end
times(4) = toc(t_bench);

% 5. Accelerations_C
t_bench = tic;
for k = 1:N
    [t0dot_b, tLdot_b] = Accelerations_C(t0, tL, P0, pm, Bi0, Bij, u0, um, u0dot, umdot, nLinksJoints, robotJoints);
end
times(5) = toc(t_bench);

% 6. ID_C
t_bench = tic;
for k = 1:N
    [tau0_b, taum_b] = ID_C(wF0, wFm, t0, tL, t0dot, tLdot, P0, pm, I0, Im, Bij, Bi0, nLinksJoints, nQ, robotBaseLink, robotLinks, robotConChild, robotConChildBase, robotJoints);
end
times(6) = toc(t_bench);

% 7. FD_C
tau0_fd = tau0;  taum_fd = taum;
t_bench = tic;
for k = 1:N
    [u0dot_b, umdot_b] = FD_C(tau0_fd, taum_fd, wF0, wFm, t0, tL, P0, pm, I0, Im, Bij, Bi0, u0, um, nLinksJoints, nQ, robotBaseLink, robotLinks, robotConChild, robotConChildBase, robotJoints);
end
times(7) = toc(t_bench);

% 8. SPART_SPACEROBOT_ODE_C
t_bench = tic;
for k = 1:N
    dydt_b = SPART_SPACEROBOT_ODE_C(1, y, tau, nLinksJoints, robotJoints, robotLinks, robotConBranch, robotBaseInertia, nQ, robotBaseLink, robotConChild, robotConChildBase);
end
times(8) = toc(t_bench);

% --- Print table ---
col_w = 20;
fprintf('\nBenchmark — %d runs each  (%s)\n', N, robot.name);
fprintf('%s\n', repmat('-', 1, 52));
fprintf('%-*s  %10s  %14s\n', col_w, 'Function', 'Total (s)', 'Per call (us)');
fprintf('%s\n', repmat('-', 1, 52));
for i = 1:numel(fn_names)
    fprintf('%-*s  %10.4f  %12.1f us\n', col_w, fn_names{i}, times(i), times(i)/N*1e6);
end
fprintf('%s\n', repmat('-', 1, 52));
fprintf('%-*s  %10.4f  %12.1f us\n', col_w, 'TOTAL (pipeline)', sum(times), sum(times)/N*1e6);
fprintf('\n');
