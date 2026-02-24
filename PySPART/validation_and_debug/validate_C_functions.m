% validate_C_functions.m
%
% Validates that the _C (and _casadi) variants of each kinematics/dynamics
% function produce numerically identical results to the original base functions.
%
% Three pipelines are run with the same random inputs:
%   ref    -- original base functions  (Kinematics, DiffKinematics, ...)
%   casadi -- _casadi variants
%   C      -- _C variants
%
% For each output variable, two comparisons are printed:
%   casadi vs ref  and  C vs ref
%
% Runs on the floating_7dof_manipulator URDF.
% Each comparison is printed and an overall PASS / FAIL is reported.

clear; clc;

SPART2path;   % add SPART source tree to the MATLAB path

TOL = 1e-10;   % absolute tolerance for element-wise comparison

%% -----------------------------------------------------------------------
%  Load robot
%% -----------------------------------------------------------------------
urdf = fullfile(fileparts(mfilename('fullpath')), ...
                '..', '..', 'URDF_models', 'floating_7dof_manipulator.urdf');

[robot, ~] = urdf2robot(urdf);
n  = robot.n_links_joints;
nq = robot.n_q;

%% -----------------------------------------------------------------------
%  Random inputs (same pattern as Load_SerialURDFRobot)
%% -----------------------------------------------------------------------
rng(42);   % reproducible

R0  = Angles321_DCM(-pi + 2*pi*rand(3,1));
r0  = -1 + 2*rand(3,1);
qm  = -pi/2 + pi*rand(nq, 1);
u0  = [-pi/2 + pi*rand(3,1); -1 + 2*rand(3,1)];
um  = -pi/2 + pi*rand(nq, 1);
u0dot_in  = [-pi/2 + pi*rand(3,1); -1 + 2*rand(3,1)];
umdot_in  = -pi/2 + pi*rand(nq, 1);
wF0 = (-1 + 2*rand(6,1))  / 10;
wFm = (-1 + 2*rand(6,n))  / 10;
tau0_in = (-1 + 2*rand(6,1))  / 10;
taum_in = (-1 + 2*rand(nq,1)) / 10;

%% -----------------------------------------------------------------------
%  Convenience: shorthand robot fields for _C functions
%% -----------------------------------------------------------------------
nLJ         = robot.n_links_joints;
joints      = robot.joints;
links       = robot.links;
baseLink    = robot.base_link;
conBranch   = robot.con.branch;
conChild    = robot.con.child;
conChildBase= robot.con.child_base;

%% -----------------------------------------------------------------------
%  1. Kinematics
%% -----------------------------------------------------------------------
fprintf('=== Kinematics ===\n');

% base: RJ/RL are [3x3xn] (3-D); casadi/C: [3x3n] (2-D flat)
[RJ_ref, RL_ref, rJ_ref, rL_ref, e_ref, g_ref] = Kinematics(R0, r0, qm, robot);

[RJ_cas, RL_cas, rJ_cas, rL_cas, e_cas, g_cas] = Kinematics_casadi(R0, r0, qm, robot);

[RJ_c, RL_c, rJ_c, rL_c, e_c, g_c] = Kinematics_C(R0, r0, qm, nLJ, joints, links);

% Convert base [3x3xn] → [3x3n] for comparison
RJ_ref_flat = reshape(RJ_ref, 3, 3*n);
RL_ref_flat = reshape(RL_ref, 3, 3*n);

fprintf('  casadi vs ref:\n');
chk('    RJ', RJ_ref_flat, RJ_cas, TOL);
chk('    RL', RL_ref_flat, RL_cas, TOL);
chk('    rJ', rJ_ref, rJ_cas, TOL);
chk('    rL', rL_ref, rL_cas, TOL);
chk('    e ', e_ref,  e_cas,  TOL);
chk('    g ', g_ref,  g_cas,  TOL);
fprintf('  C vs ref:\n');
chk('    RJ', RJ_ref_flat, RJ_c, TOL);
chk('    RL', RL_ref_flat, RL_c, TOL);
chk('    rJ', rJ_ref, rJ_c, TOL);
chk('    rL', rL_ref, rL_c, TOL);
chk('    e ', e_ref,  e_c,  TOL);
chk('    g ', g_ref,  g_c,  TOL);

%% -----------------------------------------------------------------------
%  2. DiffKinematics
%% -----------------------------------------------------------------------
fprintf('=== DiffKinematics ===\n');

% base: Bij is [6x6xnxn] (4-D), Bi0 is [6x6xn] (3-D); casadi/C: {nxn} and {nx1} cells
[Bij_ref, Bi0_ref, P0_ref, pm_ref] = DiffKinematics(R0, r0, rL_ref, e_ref, g_ref, robot);

[Bij_cas, Bi0_cas, P0_cas, pm_cas] = DiffKinematics_casadi(R0, r0, rL_cas, e_cas, g_cas, robot);

[Bij_c, Bi0_c, P0_c, pm_c] = DiffKinematics_C(R0, r0, rL_c, e_c, g_c, nLJ, conBranch, joints);

fprintf('  casadi vs ref:\n');
chk_cell_vs_4d('    Bij', Bij_cas, Bij_ref, n, TOL);
chk_cell_vs_3d('    Bi0', Bi0_cas, Bi0_ref, n, TOL);
chk('    P0 ', P0_ref, P0_cas, TOL);
chk('    pm ', pm_ref, pm_cas, TOL);
fprintf('  C vs ref:\n');
chk_cell_vs_4d('    Bij', Bij_c, Bij_ref, n, TOL);
chk_cell_vs_3d('    Bi0', Bi0_c, Bi0_ref, n, TOL);
chk('    P0 ', P0_ref, P0_c, TOL);
chk('    pm ', pm_ref, pm_c, TOL);

%% -----------------------------------------------------------------------
%  3. Velocities
%% -----------------------------------------------------------------------
fprintf('=== Velocities ===\n');

[t0_ref, tL_ref] = Velocities(Bij_ref, Bi0_ref, P0_ref, pm_ref, u0, um, robot);

[t0_cas, tL_cas] = Velocities_casadi(Bij_cas, Bi0_cas, P0_cas, pm_cas, u0, um, robot);

[t0_c, tL_c] = Velocities_C(Bij_c, Bi0_c, P0_c, pm_c, u0, um, nLJ, joints);

fprintf('  casadi vs ref:\n');
chk('    t0', t0_ref, t0_cas, TOL);
chk('    tL', tL_ref, tL_cas, TOL);
fprintf('  C vs ref:\n');
chk('    t0', t0_ref, t0_c, TOL);
chk('    tL', tL_ref, tL_c, TOL);

%% -----------------------------------------------------------------------
%  4. I_I
%% -----------------------------------------------------------------------
fprintf('=== I_I ===\n');

% base: Im is [3x3xn] (3-D); casadi/C: {1xn} cell
[I0_ref, Im_ref] = I_I(R0, RL_ref, robot);

[I0_cas, Im_cas] = I_I_casadi(R0, RL_cas, robot);

[I0_c, Im_c] = I_I_C(R0, RL_c, nLJ, baseLink.inertia, links);

fprintf('  casadi vs ref:\n');
chk('    I0', I0_ref, I0_cas, TOL);
chk_cell_vs_3d33('    Im', Im_cas, Im_ref, n, TOL);
fprintf('  C vs ref:\n');
chk('    I0', I0_ref, I0_c, TOL);
chk_cell_vs_3d33('    Im', Im_c, Im_ref, n, TOL);

%% -----------------------------------------------------------------------
%  5. Accelerations
%% -----------------------------------------------------------------------
fprintf('=== Accelerations ===\n');

[t0dot_ref, tLdot_ref] = Accelerations(t0_ref, tL_ref, P0_ref, pm_ref, Bi0_ref, Bij_ref, ...
                                        u0, um, u0dot_in, umdot_in, robot);

[t0dot_cas, tLdot_cas] = Accelerations_casadi(t0_cas, tL_cas, P0_cas, pm_cas, Bi0_cas, Bij_cas, ...
                                               u0, um, u0dot_in, umdot_in, robot);

[t0dot_c, tLdot_c] = Accelerations_C(t0_c, tL_c, P0_c, pm_c, Bi0_c, Bij_c, ...
                                      u0, um, u0dot_in, umdot_in, nLJ, joints);

fprintf('  casadi vs ref:\n');
chk('    t0dot', t0dot_ref, t0dot_cas, TOL);
chk('    tLdot', tLdot_ref, tLdot_cas, TOL);
fprintf('  C vs ref:\n');
chk('    t0dot', t0dot_ref, t0dot_c, TOL);
chk('    tLdot', tLdot_ref, tLdot_c, TOL);

%% -----------------------------------------------------------------------
%  6. ID (Inverse Dynamics)
%% -----------------------------------------------------------------------
fprintf('=== ID ===\n');

[tau0_ref, taum_ref] = ID(wF0, wFm, t0_ref, tL_ref, t0dot_ref, tLdot_ref, ...
                          P0_ref, pm_ref, I0_ref, Im_ref, Bij_ref, Bi0_ref, robot);

[tau0_cas, taum_cas] = ID_casadi(wF0, wFm, t0_cas, tL_cas, t0dot_cas, tLdot_cas, ...
                                 P0_cas, pm_cas, I0_cas, Im_cas, Bij_cas, Bi0_cas, robot);

[tau0_c, taum_c] = ID_C(wF0, wFm, t0_c, tL_c, t0dot_c, tLdot_c, ...
                         P0_c, pm_c, I0_c, Im_c, Bij_c, Bi0_c, ...
                         nLJ, nq, baseLink, links, conChild, conChildBase, joints);

fprintf('  casadi vs ref:\n');
chk('    tau0', tau0_ref, tau0_cas, TOL);
chk('    taum', taum_ref, taum_cas, TOL);
fprintf('  C vs ref:\n');
chk('    tau0', tau0_ref, tau0_c, TOL);
chk('    taum', taum_ref, taum_c, TOL);

%% -----------------------------------------------------------------------
%  7. FD (Forward Dynamics)
%% -----------------------------------------------------------------------
fprintf('=== FD ===\n');

[u0dot_ref, umdot_ref] = FD(tau0_in, taum_in, wF0, wFm, t0_ref, tL_ref, ...
                             P0_ref, pm_ref, I0_ref, Im_ref, Bij_ref, Bi0_ref, u0, um, robot);

[u0dot_cas, umdot_cas] = FD_casadi(tau0_in, taum_in, wF0, wFm, t0_cas, tL_cas, ...
                                    P0_cas, pm_cas, I0_cas, Im_cas, Bij_cas, Bi0_cas, u0, um, robot);

[u0dot_c, umdot_c] = FD_C(tau0_in, taum_in, wF0, wFm, t0_c, tL_c, ...
                           P0_c, pm_c, I0_c, Im_c, Bij_c, Bi0_c, u0, um, ...
                           nLJ, nq, baseLink, links, conChild, conChildBase, joints);

fprintf('  casadi vs ref:\n');
chk('    u0dot', u0dot_ref, u0dot_cas, TOL);
chk('    umdot', umdot_ref, umdot_cas, TOL);
fprintf('  C vs ref:\n');
chk('    u0dot', u0dot_ref, u0dot_c, TOL);
chk('    umdot', umdot_ref, umdot_c, TOL);

%% -----------------------------------------------------------------------
%  Summary
%% -----------------------------------------------------------------------
fprintf('\n========================================\n');
fprintf('VALIDATION SUMMARY\n');
fprintf('========================================\n');


%% -----------------------------------------------------------------------
%  Helper functions
%% -----------------------------------------------------------------------

function chk(label, ref, got, tol)
    max_err = max(abs(ref(:) - got(:)));
    if max_err < tol
        fprintf('%s  PASS  (max err = %.2e)\n', label, max_err);
    else
        fprintf('%s  FAIL  (max err = %.2e)\n', label, max_err);
    end
end

function chk_cell(label, ref, got, tol)
    errs = cellfun(@(a,b) max(abs(a(:)-b(:))), ref, got);
    max_err = max(errs(:));
    if max_err < tol
        fprintf('%s  PASS  (max err = %.2e)\n', label, max_err);
    else
        fprintf('%s  FAIL  (max err = %.2e)\n', label, max_err);
    end
end

function chk_cell_vs_4d(label, cell_arr, arr4d, n, tol)
    % Compare {nxn} cell vs [6x6xnxn] 4-D array (Bij format)
    max_err = 0;
    for ii = 1:n
        for jj = 1:n
            ref_slice = arr4d(:,:,ii,jj);
            e = max(abs(cell_arr{ii,jj}(:) - ref_slice(:)));
            if e > max_err; max_err = e; end
        end
    end
    if max_err < tol
        fprintf('%s  PASS  (max err = %.2e)\n', label, max_err);
    else
        fprintf('%s  FAIL  (max err = %.2e)\n', label, max_err);
    end
end

function chk_cell_vs_3d(label, cell_arr, arr3d, n, tol)
    % Compare {nx1} cell vs [6x6xn] 3-D array (Bi0 format)
    max_err = 0;
    for ii = 1:n
        ref_slice = arr3d(:,:,ii);
        e = max(abs(cell_arr{ii}(:) - ref_slice(:)));
        if e > max_err; max_err = e; end
    end
    if max_err < tol
        fprintf('%s  PASS  (max err = %.2e)\n', label, max_err);
    else
        fprintf('%s  FAIL  (max err = %.2e)\n', label, max_err);
    end
end

function chk_cell_vs_3d33(label, cell_arr, arr3d, n, tol)
    % Compare {1xn} cell vs [3x3xn] 3-D array (Im format)
    max_err = 0;
    for ii = 1:n
        ref_slice = arr3d(:,:,ii);
        e = max(abs(cell_arr{ii}(:) - ref_slice(:)));
        if e > max_err; max_err = e; end
    end
    if max_err < tol
        fprintf('%s  PASS  (max err = %.2e)\n', label, max_err);
    else
        fprintf('%s  FAIL  (max err = %.2e)\n', label, max_err);
    end
end
