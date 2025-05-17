function [Bij, Bi0, P0, pm] = DiffKinematics_casadi(R0, r0, rL, e, g, robot)
    import casadi.*

    n = robot.n_links_joints;

    % Preallocate Bij as a cell array of size n x n, each element 6x6 SX
    Bij = cell(n, n);

    % Compute Bij
    for j = 1:n
        for i = 1:n
            if robot.con.branch(i, j) == 1
                % Links are in the same branch
                skew_mat = SkewSym_casadi(rL(:, j) - rL(:, i));
                Bij{i, j} = [eye(3), zeros(3, 3); skew_mat, eye(3)];
            else
                % Links are not in the same branch
                Bij{i, j} = SX.zeros(6, 6);
            end
        end
    end

    % Preallocate Bi0 as cell array n x 1
    Bi0 = cell(n, 1);

    % Compute Bi0
    for i = 1:n
        skew_mat = SkewSym_casadi(r0 - rL(:, i));
        Bi0{i} = [eye(3), zeros(3, 3); skew_mat, eye(3)];
    end

    % Twist-propagation vectors
    pm = SX.zeros(6, n);

    % Base-link twist-propagation matrix
    P0 = [R0, zeros(3, 3); zeros(3, 3), eye(3)];

    for i = 1:n
        if robot.joints(i).type == 1  % Revolute
            pm(:, i) = [e(:, i); cross(e(:, i), g(:, i))];
        elseif robot.joints(i).type == 2  % Prismatic
            pm(:, i) = [zeros(3, 1); e(:, i)];
        elseif robot.joints(i).type == 0  % Fixed
            pm(:, i) = zeros(6, 1);
        end
    end
end

% Helper function for skew symmetric matrix compatible with CasADi
function S = SkewSym_casadi(v)
    % v is a 3x1 vector (SX)
    S = [    0, -v(3),  v(2);
          v(3),     0, -v(1);
         -v(2),  v(1),    0];
end
