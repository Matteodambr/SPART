function [t0, tL] = Velocities_C(Bij, Bi0, P0, pm, u0, um, nLinksJoints, robotJoints)

    zeros6n = @(m,n) zeros(m,n);

    n = nLinksJoints;

    % Pre-allocate tL as 6 x n
    tL = zeros6n(6, n);

    % Base-link twist
    t0 = P0 * u0;

    for i = 1:n
        if robotJoints(i).parent_link == 0
            % First link
            tL(:, i) = Bi0{i} * t0;
        else
            % Subsequent links
            tL(:, i) = Bij{i, i-1} * tL(:, i-1);
        end

        % Add joint contribution if joint is not fixed
        if robotJoints(i).type ~= 0
            tL(:, i) = tL(:, i) + pm(:, i) * um(robotJoints(i).q_id);
        end
    end
end
