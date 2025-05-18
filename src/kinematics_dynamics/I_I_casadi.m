function [I0, Im] = I_I_casadi(R0, RL, robot)

n = robot.n_links_joints;

I0 = R0 * robot.base_link.inertia * R0';

% Pre-allocate Im as a cell array of 3x3 matrices
Im = cell(1, n);

for i = 1:n
    % Extract 3x3 block from RL
    RL_block = RL(:, (3*(i-1)+1):(3*i));
    
    % Compute inertia projection
    Im{i} = RL_block * robot.links(i).inertia * RL_block';
end

end
