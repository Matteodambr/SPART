% Compare kinematics to vectorized kinematics function
clearvars ; close all ; clc ; beep off ; format long g ;
addpath(genpath('URDF_models')) ;
addpath(genpath('src')) ;
robot = urdf2robot('kuka_iiwa.urdf') ; % Example on this manipulator
num_tests = 1000 ;

%% Check that the outputs remain the same, applying random inputs

% Check that the functions produce the same outputs from random inputs
for k = 1:num_tests

    % Inputs
    R0 = quat2dcm(randrot()) ;
    qm = rand(robot.n_links_joints, 1) ;
    r0 = rand(3, 1) ;

    % Kinematics
    [RJ1, RL1, rJ1, rL1, e1, g1] = Kinematics(R0,r0,qm,robot) ;
    [RJ2, RL2, rJ2, rL2, e2, g2] = Kinematics_vectorized(R0,r0,qm,robot) ;
    assert(isequal(RJ1, RJ2)) ;
    assert(isequal(RL1, RL2)) ;
    assert(isequal(rJ1, rJ2)) ;
    assert(isequal(rL1, rL2)) ;
    assert(isequal(e1, e2)) ;
    assert(isequal(g1, g2)) ;

    % Differential kinematics
    [Bij1, Bi01, P01, pm1] = DiffKinematics(R0, r0, rL1, e1, g1, robot) ;
    [Bij2, Bi02, P02, pm2] = DiffKinematics_vectorized(R0, r0, rL1, e1, g1, robot) ;
    assert(isequal(Bij1, Bij2)) ;
    assert(isequal(Bi01, Bi02)) ;
    assert(isequal(P01, P02)) ;
    assert(isequal(pm1, pm2)) ;

    % More inputs
    u0 = rand(6, 1) ;
    um = rand(robot.n_links_joints, 1) ;

    % Velocities
    [t01,tL1] = Velocities(Bij1,Bi01,P01,pm1,u0,um,robot) ;
    [t02,tL2] = Velocities_vectorized(Bij1,Bi01,P01,pm1,u0,um,robot) ;
    assert(isequal(t01, t02)) ;
    assert(isequal(tL1, tL2)) ;

    % I_I
    tol = 1e-14 ;
    [I01,Im1]=I_I(R0,RL1,robot) ;
    [I02,Im2]=I_I_vectorized(R0,RL1,robot) ;
    assert(isequal(I01, I02)) ;
    assert(all(abs(Im1 - Im2) < tol, 'all')) ;

    % Jacob
    rp = rand(3,1) ;
    [J01, Jm1] = Jacob(rp, r0, rL1, P01, pm1, 1, robot) ;
    [J02, Jm2] = Jacob_vectorized(rp, r0, rL1, P01, pm1, 1, robot) ;
    assert(isequal(J01, J02)) ;
    assert(isequal(Jm1, Jm2)) ;

    % MCB
    [M0_tilde1,Mm_tilde1]=MCB(I01,Im1,Bij1,Bi01,robot) ;
    [M0_tilde2,Mm_tilde2]=MCB_vectorized(I01,Im1,Bij1,Bi01,robot) ;
    assert(all(abs(M0_tilde1 - M0_tilde2) < tol, 'all')) ;
    assert(all(abs(Mm_tilde1 - Mm_tilde2) < tol, 'all')) ;

    % GIM
    [H01, H0m1, Hm1] = GIM(M0_tilde1,Mm_tilde1,Bij1,Bi01,P01,pm1,robot) ;
    [H02, H0m2, Hm2] = GIM_vectorized(M0_tilde1,Mm_tilde1,Bij1,Bi01,P01,pm1,robot) ;
    assert(isequal(H01, H02)) ;
    assert(isequal(H0m1, H0m2)) ;
    assert(isequal(Hm1, Hm2)) ;

    % CIM
    [C01, C0m1, Cm01, Cm1] = CIM(t01,tL1,I01,Im1,M0_tilde1,Mm_tilde1,Bij1,Bi01,P01,pm1,robot) ;
    [C02, C0m2, Cm02, Cm2] = CIM_vectorized(t01,tL1,I01,Im1,M0_tilde1,Mm_tilde1,Bij1,Bi01,P01,pm1,robot) ;
    assert(isequal(C01, C02)) ;
    assert(isequal(C0m1, C0m2)) ;
    assert(isequal(Cm01, Cm02)) ;
    assert(isequal(Cm1, Cm2)) ;

    % Jacobian
    p_ee = rL1(1:3, end) ;
    or_ee = RL1(1:3, 1:3, end) ;
    v_ee = tL1(4:6,end) ;
    w_ee = tL1(1:3,end) ;
    [ J0ee, Jmee ] = Jacob( p_ee, r0, rL1, P01, pm1, robot.n_links_joints, robot ) ;

    % singularity_check
    PARAM_Chaser.singularity.threshold = 0.02 ;
    isSingular1 = singularity_check_vectorized(H01, H0m1, J0ee, Jmee, PARAM_Chaser) ;
    isSingular2 = singularity_check_vectorized(H02, H0m2, J0ee, Jmee, PARAM_Chaser) ;
    assert(isequal(isSingular1, isSingular2)) ;

end
disp('Vectorized functions checked and produce the same outputs.') ;

%% Kinematics

% Time the two functions
disp('Timing Kinematics functions...') ;
diff_kinematics = zeros(num_tests,1) ;
for k = 1:num_tests
    t_kin = timeit(@() Kinematics(R0, r0, qm, robot)) ;
    t_kin_vec = timeit(@() Kinematics_vectorized(R0, r0, qm, robot)) ;
    diff_kinematics(k) = t_kin - t_kin_vec ; % Positive if t_kin_vec is faster
end

%% Differential kinematics

% Time the two functions
disp('Timing Diff Kinematics functions...') ;
diff_diff_kinematics = zeros(num_tests,1) ;
for k = 1:num_tests
    t_kin = timeit(@() DiffKinematics(R0, r0, rL1, e1, g1, robot)) ;
    t_kin_vec = timeit(@() DiffKinematics_vectorized(R0, r0, rL1, e1, g1, robot)) ;
    diff_diff_kinematics(k) = t_kin - t_kin_vec ; % Positive if t_kin_vec is faster
end

%% Velocities

% Time the two functions
disp('Timing Velocities functions...') ;
diff_velocities = zeros(num_tests,1) ;
for k = 1:num_tests
    t_kin = timeit(@() Velocities(Bij1,Bi01,P01,pm1,u0,um,robot) ) ;
    t_kin_vec = timeit(@() Velocities_vectorized(Bij1,Bi01,P01,pm1,u0,um,robot) ) ;
    diff_velocities(k) = t_kin - t_kin_vec ; % Positive if t_kin_vec is faster
end

%% I_I

% Time the two functions
disp('Timing I_I functions...') ;
diff_I_I = zeros(num_tests,1) ;
for k = 1:num_tests
    t_kin = timeit(@() I_I(R0,RL1,robot) ) ;
    t_kin_vec = timeit(@() I_I_vectorized(R0,RL1,robot) ) ;
    diff_I_I(k) = t_kin - t_kin_vec ; % Positive if t_kin_vec is faster
end

%% Jacob

% Time the two functions
disp('Timing Jacob functions...') ;
diff_Jacob = zeros(num_tests,1) ;
for k = 1:num_tests
    t_kin = timeit(@() Jacob(rp, r0, rL1, P01, pm1, 1, robot) ) ;
    t_kin_vec = timeit(@() Jacob_vectorized(rp, r0, rL1, P01, pm1, 1, robot) ) ;
    diff_Jacob(k) = t_kin - t_kin_vec ; % Positive if t_kin_vec is faster
end

%% MCB

% Time the two functions
disp('Timing MCB functions...') ;
diff_MCB = zeros(num_tests,1) ;
for k = 1:num_tests
    t_kin = timeit(@() MCB(I01,Im1,Bij1,Bi01,robot) ) ;
    t_kin_vec = timeit(@() MCB_vectorized(I01,Im1,Bij1,Bi01,robot) ) ;
    diff_MCB(k) = t_kin - t_kin_vec ; % Positive if t_kin_vec is faster
end

%% GIM

% Time the two functions
disp('Timing GIM functions...') ;
diff_GIM = zeros(num_tests,1) ;
for k = 1:num_tests
    t_kin = timeit(@() GIM(M0_tilde1,Mm_tilde1,Bij1,Bi01,P01,pm1,robot) ) ;
    t_kin_vec = timeit(@() GIM_vectorized(M0_tilde1,Mm_tilde1,Bij1,Bi01,P01,pm1,robot) ) ;
    diff_GIM(k) = t_kin - t_kin_vec ; % Positive if t_kin_vec is faster
end

%% CIM

% Time the two functions
disp('Timing CIM functions...') ;
diff_CIM = zeros(num_tests,1) ;
for k = 1:num_tests
    t_kin = timeit(@() CIM(t01,tL1,I01,Im1,M0_tilde1,Mm_tilde1,Bij1,Bi01,P01,pm1,robot) ) ;
    t_kin_vec = timeit(@() CIM_vectorized(t01,tL1,I01,Im1,M0_tilde1,Mm_tilde1,Bij1,Bi01,P01,pm1,robot) ) ;
    diff_CIM(k) = t_kin - t_kin_vec ; % Positive if t_kin_vec is faster
end

%% singularity_check

% Time the two functions
disp('Timing singularity functions...') ;
diff_sing = zeros(num_tests,1) ;
for k = 1:num_tests
    t_kin = timeit(@() singularity_check(H01, H0m1, J0ee, Jmee, PARAM_Chaser) ) ;
    t_kin_vec = timeit(@() singularity_check_vectorized(H01, H0m1, J0ee, Jmee, PARAM_Chaser) ) ;
    diff_sing(k) = t_kin - t_kin_vec ; % Positive if t_kin_vec is faster
end

%% Summary
training_episodes = 5000 ;
training_steps = 420 ;
fprintf('Mean time gained after vectorization (single function evaluation): \n') ;
tot_time_saved = 0 ;

% Kinematics
fprintf('Kinematics - %.10f s gained (single run), %.1f s in 1 training\n', mean(diff_kinematics), mean(diff_kinematics)*training_episodes*training_steps/0.3) ;
tot_time_saved = tot_time_saved + mean(diff_kinematics)*training_episodes*training_steps/0.3 ;

% Diff Kinematics
fprintf('Diff Kinematics - %.10f s gained (single run), %.1f s in 1 training\n', mean(diff_diff_kinematics), mean(diff_diff_kinematics)*training_episodes*training_steps/0.3) ;
tot_time_saved = tot_time_saved + mean(diff_diff_kinematics)*training_episodes*training_steps/0.3 ;

% % Velocities
% fprintf('Velocities - %.10f s gained (single run), %.1f s in 1 training\n', mean(diff_velocities), mean(diff_velocities)*training_episodes*training_steps/0.3) ;
% tot_time_saved = tot_time_saved + mean(diff_velocities)*training_episodes*training_steps/0.3 ;

% % I_I
% fprintf('I_I - %.10f s gained (single run), %.1f s in 1 training\n', mean(diff_I_I), mean(diff_I_I)*training_episodes*training_steps/0.3) ;
% tot_time_saved = tot_time_saved + mean(diff_I_I)*training_episodes*training_steps/0.3 ;

% % Jacob
% fprintf('Jacob - %.10f s gained (single run), %.1f s in 1 training\n', mean(diff_Jacob), mean(diff_Jacob)*training_episodes*training_steps/0.3) ;
% tot_time_saved = tot_time_saved + mean(diff_Jacob)*training_episodes*training_steps/0.3 ;

% % MCB
% fprintf('MCB - %.10f s gained (single run), %.1f s in 1 training\n', mean(diff_MCB), mean(diff_MCB)*training_episodes*training_steps/0.3) ;
% tot_time_saved = tot_time_saved + mean(diff_MCB)*training_episodes*training_steps/0.3 ;

% % GIM
% fprintf('GIM - %.10f s gained (single run), %.1f s in 1 training\n', mean(diff_GIM), mean(diff_GIM)*training_episodes*training_steps/0.3) ;
% tot_time_saved = tot_time_saved + mean(diff_GIM)*training_episodes*training_steps/0.3 ;

% % CIM
% fprintf('CIM - %.10f s gained (single run), %.1f s in 1 training\n', mean(diff_CIM), mean(diff_CIM)*training_episodes*training_steps/0.3) ;
% tot_time_saved = tot_time_saved + mean(diff_CIM)*training_episodes*training_steps/0.3 ;

% % singularity check
% fprintf('SINGULARITY - %.10f s gained (single run), %.1f s in 1 training\n', mean(diff_sing), mean(diff_sing)*training_episodes*training_steps/0.3) ;
% tot_time_saved = tot_time_saved + mean(diff_sing)*training_episodes*training_steps/0.3 ;

% Total time saved
fprintf('\n\nThe approximate time saved with optimization is %.1f seconds (%.1f minutes).', tot_time_saved, tot_time_saved/60) ;
