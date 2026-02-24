function [I0, Im] = I_I_C(R0, RL, nLinksJoints, robotBaseInertia, robotLinks)

n = nLinksJoints;

I0 = R0 * robotBaseInertia * R0';

% Pre-allocate Im as a cell array of 3x3 matrices
Im = cell(1, n);

for i = 1:n
    % Extract 3x3 block from RL
    RL_block = RL(:, (3*(i-1)+1):(3*i));

    % Compute inertia projection
    Im{i} = RL_block * robotLinks(i).inertia * RL_block';
end

end
