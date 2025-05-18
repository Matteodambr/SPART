function [t0dot, tLdot] = Accelerations_casadi(t0, tL, P0, pm, Bi0, Bij, u0, um, u0dot, umdot, robot)
% Computes operational-space accelerations (twist-rate) using CasADi-compatible data structures.
%
% All 3D matrices (Bi0, Bij, Omegam) are replaced with cell arrays for CasADi compatibility.

n = robot.n_links_joints;

%--- Omega matrices ---%
% Base-link
Omega0 = [SkewSym(t0(1:3)), zeros(3,3); 
          zeros(3,3),      zeros(3,3)];

% Pre-allocate cell array for Omegam
Omegam = cell(1, n);

% Compute Omega for manipulator links
for i = 1:n
    skew_omega = SkewSym(tL(1:3, i));
    Omegam{i} = [skew_omega, zeros(3,3); 
                 zeros(3,3), skew_omega];
end

%--- Twist Rate ---%
% Base-link acceleration
t0dot = Omega0 * P0 * u0 + P0 * u0dot;

% Pre-allocate for manipulator
tLdot = zeros(6, n, 'like', t0);

% Forward recursion
for i = 1:n
    if robot.joints(i).parent_link == 0
        % First link (connected to base)
        tLdot(:, i) = Bi0{i} * t0dot + ...
                      [zeros(3,6); SkewSym(t0(4:6) - tL(4:6, i)), zeros(3,3)] * t0;
    else
        j = robot.joints(i).parent_link;
        tLdot(:, i) = Bij{i, j} * tLdot(:, j) + ...
                      [zeros(3,6); SkewSym(tL(4:6, j) - tL(4:6, i)), zeros(3,3)] * tL(:, j);
    end

    % Add joint contribution
    if robot.joints(i).type ~= 0
        qid = robot.joints(i).q_id;
        tLdot(:, i) = tLdot(:, i) + ...
                      Omegam{i} * pm(:, i) * um(qid) + ...
                      pm(:, i) * umdot(qid);
    end
end

end
