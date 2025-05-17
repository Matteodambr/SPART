function [t0, tL] = Velocities_casadi(Bij, Bi0, P0, pm, u0, um, robot)
    import casadi.*

    n = robot.n_links_joints;

    % Pre-allocate tL as SX matrix 6 x n
    tL = SX.zeros(6, n);

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
