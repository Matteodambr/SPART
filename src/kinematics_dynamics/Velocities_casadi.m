function [t0, tL] = Velocities_casadi(Bij, Bi0, P0, pm, u0, um, robot)

    % Determine if inputs are symbolic (casadi) or numeric
    is_symbolic = isa(P0, 'casadi.SX') || isa(P0, 'casadi.MX') || isa(u0, 'casadi.SX') || isa(u0, 'casadi.MX');

    if is_symbolic
        zeros6n = @(m,n) casadi.SX.zeros(m,n);
    else
        zeros6n = @(m,n) zeros(m,n);
    end

    n = robot.n_links_joints;

    % Pre-allocate tL as 6 x n
    tL = zeros6n(6, n);

    % Base-link twist
    t0 = P0 * u0;

    for i = 1:n
        if robot.joints(i).parent_link == 0
            % First link
            tL(:, i) = Bi0{i} * t0;
        else
            % Subsequent links
            % Note: The original code used Bij(:,:,i,i-1), but you might need to adjust
            % indices depending on the branch connectivity.
            tL(:, i) = Bij{i, i-1} * tL(:, i-1);
        end

        % Add joint contribution if joint is not fixed
        if robot.joints(i).type ~= 0
            tL(:, i) = tL(:, i) + pm(:, i) * um(robot.joints(i).q_id);
        end
    end
end
