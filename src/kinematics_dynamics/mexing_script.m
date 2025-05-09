% Script using all functions to be mexed, for code generation

clearvars ; close all ; clc ; beep off ; 

%% NOTE: WHEN MEXING FUNCTIONS, ANY DIMENSION THAT IS VARIABLE MUST BE SET 
%        TO INF, AND NOT TO A SPECIFIC NUMBER. OTHERWISE THE FUNCTION WILL
%        ONLY WORK FOR THAT SPECIFIC SIZE.

% TESTS ARE CONDUCTED ON TWO DIFFERENT ROBOT MODELS

robot_models = {'floating_planar_4dof_manipulator.urdf', 'ChaserRobot.urdf', 'kuka_iiwa.urdf', 'kuka_lwr.urdf', 'SC_3DoF.urdf', 'Simple_Spacecraft.urdf'} ;

% Tolerance for comparison
tol = 1e-10;
all_passed = true;

for k = 1:length(robot_models)
    model_passed = true;
    disp(['Testing model: ', robot_models{k}]);
    
    robot = urdf2robot(robot_models{k}) ;

    % Example variables
    R0 = eye(3, 3) ;
    r0 = rand(3, 1) ;
    qm = rand(robot.n_q, 1) ;
    q0_dot = rand(6, 1) ;
    qm_dot = rand(robot.n_q, 1) ;

    % Kinematics
    [RJ, RL, rJ, rL, e, g] = Kinematics(R0, r0, qm, robot) ;
    [RJ_mex, RL_mex, rJ_mex, rL_mex, e_mex, g_mex] = Kinematics_mex(R0, r0, qm, robot) ;
    
    % Check Kinematics outputs
    if ~isapprox(RJ, RJ_mex, tol) || ~isapprox(RL, RL_mex, tol) || ~isapprox(rJ, rJ_mex, tol) || ...
       ~isapprox(rL, rL_mex, tol) || ~isapprox(e, e_mex, tol) || ~isapprox(g, g_mex, tol)
        disp('  ❌ Kinematics and Kinematics_mex outputs differ');
        model_passed = false;
    else
        disp('  ✅ Kinematics: PASSED');
    end

    % Diff kinematics
    [Bij, Bi0, P0, pm] = DiffKinematics(R0, r0, rL, e, g, robot) ;
    [Bij_mex, Bi0_mex, P0_mex, pm_mex] = DiffKinematics_mex(R0, r0, rL, e, g, robot) ;
    
    % Check DiffKinematics outputs
    if ~isapprox(Bij, Bij_mex, tol) || ~isapprox(Bi0, Bi0_mex, tol) || ...
       ~isapprox(P0, P0_mex, tol) || ~isapprox(pm, pm_mex, tol)
        disp('  ❌ DiffKinematics and DiffKinematics_mex outputs differ');
        model_passed = false;
    else
        disp('  ✅ DiffKinematics: PASSED');
    end

    % Velocities
    u0 = q0_dot ; % q0_dot = [w0_body; v0] (rad/s, m/s)
    um = qm_dot ; % joint angles
    [t0, tL] = Velocities(Bij, Bi0, P0, pm, u0, um, robot) ;
    [t0_mex, tL_mex] = Velocities_mex(Bij, Bi0, P0, pm, u0, um, robot) ;
    
    % Check Velocities outputs
    if ~isapprox(t0, t0_mex, tol) || ~isapprox(tL, tL_mex, tol)
        disp('  ❌ Velocities and Velocities_mex outputs differ');
        model_passed = false;
    else
        disp('  ✅ Velocities: PASSED');
    end

    % Continue with similar checks for all remaining function pairs...
    % ... (remaining function checks follow the same pattern)
    
    % Inertias
    [I0, Im] = I_I(R0, RL, robot);
    [I0_mex, Im_mex] = I_I_mex(R0, RL, robot);
    
    if ~isapprox(I0, I0_mex, tol) || ~isapprox(Im, Im_mex, tol)
        disp('  ❌ I_I and I_I_mex outputs differ');
        model_passed = false;
    else
        disp('  ✅ I_I: PASSED');
    end
    
    % Retrieve end-effector state from computed values
    p_ee = rL(1:3, end) ;
    or_ee = RL(1:3, 1:3, end) ;
    v_ee = tL(4:6,end) ;
    w_ee = tL(1:3,end) ;

    % Manipulator jacobian
    [J0ee, Jmee] = Jacob(p_ee, r0, rL, P0, pm, robot.n_links_joints, robot);
    [J0ee_mex, Jmee_mex] = Jacob_mex(p_ee, r0, rL, P0, pm, robot.n_links_joints, robot);
    
    % Check Jacob outputs
    if ~isapprox(J0ee, J0ee_mex, tol) || ~isapprox(Jmee, Jmee_mex, tol)
        disp('  ❌ Jacob and Jacob_mex outputs differ');
        model_passed = false;
    else
        disp('  ✅ Jacob: PASSED');
    end

    % Mass composite body matrix
    [M0_tilde, Mm_tilde] = MCB(I0, Im, Bij, Bi0, robot);
    [M0_tilde_mex, Mm_tilde_mex] = MCB_mex(I0, Im, Bij, Bi0, robot);
    
    % Check MCB outputs
    if ~isapprox(M0_tilde, M0_tilde_mex, tol) || ~isapprox(Mm_tilde, Mm_tilde_mex, tol)
        disp('  ❌ MCB and MCB_mex outputs differ');
        model_passed = false;
    else
        disp('  ✅ MCB: PASSED');
    end

    % Generalized inertia matrix
    [H0, H0m, Hm] = GIM(M0_tilde, Mm_tilde, Bij, Bi0, P0, pm, robot);
    [H0_mex, H0m_mex, Hm_mex] = GIM_mex(M0_tilde, Mm_tilde, Bij, Bi0, P0, pm, robot);
    
    % Check GIM outputs
    if ~isapprox(H0, H0_mex, tol) || ~isapprox(H0m, H0m_mex, tol) || ~isapprox(Hm, Hm_mex, tol)
        disp('  ❌ GIM and GIM_mex outputs differ');
        model_passed = false;
    else
        disp('  ✅ GIM: PASSED');
    end

    % Convective inertia matrix
    [C0, C0m, Cm0, Cm] = CIM(t0,tL,I0,Im,M0_tilde,Mm_tilde,Bij,Bi0,P0,pm,robot);
    [C0_mex, C0m_mex, Cm0_mex, Cm_mex] = CIM_mex(t0,tL,I0,Im,M0_tilde,Mm_tilde,Bij,Bi0,P0,pm,robot);
    
    % Check CIM outputs
    if ~isapprox(C0, C0_mex, tol) || ~isapprox(C0m, C0m_mex, tol) || ...
       ~isapprox(Cm0, Cm0_mex, tol) || ~isapprox(Cm, Cm_mex, tol)
        disp('  ❌ CIM and CIM_mex outputs differ');
        model_passed = false;
    else
        disp('  ✅ CIM: PASSED');
    end

    % Dynamic Jstar
    jstar = Jstar(H0, H0m, J0ee, Jmee);
    jstar_mex = Jstar_mex(H0_mex, H0m_mex, J0ee_mex, Jmee_mex);
    
    % Check Jstar outputs
    if ~isapprox(jstar, jstar_mex, tol)
        disp('  ❌ Jstar and Jstar_mex outputs differ');
        model_passed = false;
    else
        disp('  ✅ Jstar: PASSED');
    end
    
    % Print overall result for this model
    if model_passed
        disp(['✅ All checks with model ', robot_models{k}, ' PASSED', newline]);
    else
        disp(['❌ Some tests FAILED for model ', robot_models{k}, newline]);
        all_passed = false;
    end

end

% Display final overall result
if all_passed
    disp('✅ ALL TESTS PASSED FOR ALL MODELS');
else
    disp('❌ SOME TESTS FAILED');
end

% Add helper function for approximate comparison
function result = isapprox(A, B, tol)
    if isequal(size(A), size(B))
        result = all(abs(A(:) - B(:)) < tol);
    else
        result = false;
        disp(['Size mismatch: ', mat2str(size(A)), ' vs ', mat2str(size(B))]);
    end
end

