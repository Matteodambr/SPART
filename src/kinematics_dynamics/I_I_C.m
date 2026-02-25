function [I0, Im] = I_I_C(R0_body2I, RL, nLinksJoints, robotBaseInertia, robotLinks)
% Projects the link inertia tensors from the body CCS to the inertial CCS.
%
% :parameters:
%   * R0_body2I  -- Active rotation from the base-link body CCS to the inertial CCS [3x3].
%                   V_I = R0_body2I * V_B  (maps body-frame vectors to the inertial frame).
%   * RL         -- Link rotation matrices (body-to-inertial) stored as [3 x 3n].
%   * nLinksJoints, robotBaseInertia, robotLinks -- Robot model parameters.

n = nLinksJoints;

% Similarity transform: I_inertial = R * I_body * R'
I0 = R0_body2I * robotBaseInertia * R0_body2I';

% Pre-allocate Im as a cell array of 3x3 matrices
Im = cell(1, n);

for i = 1:n
    % Extract 3x3 block from RL
    RL_block = RL(:, (3*(i-1)+1):(3*i));

    % Compute inertia projection
    Im{i} = RL_block * robotLinks(i).inertia * RL_block';
end

end
