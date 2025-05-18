function [Bij, Bi0, P0, pm] = DiffKinematics_casadi(R0, r0, rL, e, g, robot)

    % Determine if inputs are symbolic (casadi) or numeric
    is_symbolic = isa(R0, 'casadi.SX') || isa(R0, 'casadi.MX') || isa(r0, 'casadi.SX') || isa(r0, 'casadi.MX') || ...
                  isa(rL, 'casadi.SX') || isa(rL, 'casadi.MX') || isa(e, 'casadi.SX') || isa(e, 'casadi.MX') || ...
                  isa(g, 'casadi.SX') || isa(g, 'casadi.MX');

    if is_symbolic
        zeros6n = @(m,n) casadi.SX.zeros(m,n);
        zeros3n = @(m,n) casadi.SX.zeros(m,n);
        eye3 = @() casadi.SX.eye(3);
    else
        zeros6n = @(m,n) zeros(m,n);
        zeros3n = @(m,n) zeros(m,n);
        eye3 = @() eye(3);
    end
    cross_fn = @(a,b) cross(a,b);

    n = robot.n_links_joints;

    % Preallocate Bij as a cell array of size n x n, each element 6x6
    Bij = cell(n, n);

    % Compute Bij
    for j = 1:n
        for i = 1:n
            if robot.con.branch(i, j) == 1
                % Links are in the same branch
                skew_mat = SkewSym(rL(:, j) - rL(:, i));
                Bij{i, j} = [eye3(), zeros3n(3, 3); skew_mat, eye3()];
            else
                Bij{i, j} = zeros6n(6, 6);
            end
        end
    end

    % Preallocate Bi0 as cell array n x 1
    Bi0 = cell(n, 1);

    % Compute Bi0
    for i = 1:n
        skew_mat = SkewSym(r0 - rL(:, i));
        Bi0{i} = [eye3(), zeros3n(3, 3); skew_mat, eye3()];
    end

    % Twist-propagation vectors
    pm = zeros6n(6, n);

    % Base-link twist-propagation matrix
    P0 = [R0, zeros3n(3, 3); zeros3n(3, 3), eye3()];

    for i = 1:n
        if robot.joints(i).type == 1  % Revolute
            pm(:, i) = [e(:, i); cross_fn(e(:, i), g(:, i))];
        elseif robot.joints(i).type == 2  % Prismatic
            pm(:, i) = [zeros3n(3, 1); e(:, i)];
        elseif robot.joints(i).type == 0  % Fixed
            pm(:, i) = zeros6n(6, 1);
        end
    end
end