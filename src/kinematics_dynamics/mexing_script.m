% Script using all functions to be mexed, for code generation

%% NOTE: WHEN MEXING FUNCTIONS, ANY DIMENSION THAT IS VARIABLE MUST BE SET 
%        TO INF, AND NOT TO A SPECIFIC NUMBER. OTHERWISE THE FUNCTION WILL
%        ONLY WORK FOR THAT SPECIFIC SIZE.

% Inputs
robot = urdf2robot('floating_planar_4dof_manipulator.urdf') ;

% Example variables
R0 = eye(3, 3) ;
r0 = rand(3, 1) ;
qm = rand(robot.n_q, 1) ;
q0_dot = rand(6, 1) ;
qm_dot = rand(robot.n_q, 1) ;

% Kinematics
[RJ, RL, rJ, rL, e, g] = Kinematics(R0, r0, qm, robot) ;

% Diff kinematics
[Bij, Bi0, P0, pm] = DiffKinematics(R0, r0, rL, e, g, robot) ;

% Velocities
u0 = q0_dot ; % q0_dot = [w0_body; v0] (rad/s, m/s)
um = qm_dot ; % joint angles
[t0, tL] = Velocities(Bij, Bi0, P0, pm, u0, um, robot) ;

% Inertias
[ I0, Im ] = I_I( R0, RL, robot ) ;

% Retrieve end-effector state from computed values
p_ee = rL(1:3, end) ;
or_ee = RL(1:3, 1:3, end) ;
v_ee = tL(4:6,end) ;
w_ee = tL(1:3,end) ;

% Manipulator jacobian
[ J0ee, Jmee ] = Jacob( p_ee, r0, rL, P0, pm, robot.n_links_joints, robot ) ; 

% Compute mass composite body matrix of the multibody system
[M0_tilde, Mm_tilde] = MCB(I0, Im, Bij, Bi0, robot) ;

% Compute generalized inertia matrix H of the multibody system
[H0, H0m, Hm] = GIM(M0_tilde, Mm_tilde, Bij, Bi0, P0, pm, robot) ;
H = [H0, H0m; H0m', Hm] ;

% Compute generalized convective inertia matrix of the multibody system
[C0, C0m, Cm0, Cm] = CIM(t0, tL, I0, Im, M0_tilde, Mm_tilde, Bij, Bi0, P0, pm, robot) ;
C = [C0, C0m; Cm0, Cm] ;

% Compute generalized jacobian
jstar = Jstar(H0, H0m, J0ee, Jmee) ;
