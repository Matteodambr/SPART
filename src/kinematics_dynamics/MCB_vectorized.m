function [M0_tilde, Mm_tilde] = MCB_vectorized(I0, Im, Bij, Bi0, robot)
% Computes the Mass Composite Body Matrix (MCB) of the multibody system.
%
% [M0_tilde, Mm_tilde] = MCB_vectorized(I0, Im, Bij, Bi0, robot)
%
% Parameters:
%   I0   -- Base-link inertia matrix (3x3)
%   Im   -- Links inertia matrices (3x3xn)
%   Bij  -- Twist-propagation matrices for i>0 and j>0 (6x6xn matrix where each page
%           corresponds to a given link-child relation)
%   Bi0  -- Twist-propagation matrices for i>0 and j=0 (6x6xn)
%   robot-- Robot model (see :doc:`/Tutorial_Robot`)
%
% Returns:
%   M0_tilde -- Base-link mass composite body matrix (6x6)
%   Mm_tilde -- Manipulator mass composite body matrices (6x6xn)
%
% See also: I_I.

% Number of links/joints
n = robot.n_links_joints;

% Pre-allocate manipulator composite matrices
Mm_tilde = zeros(6,6,n, 'like', I0);

% Precompute the base inertia + mass matrix for each link
base_MM = zeros(6,6,n, 'like', I0);
for i = 1:n
    base_MM(:,:,i) = [ Im(:,:,i), zeros(3,3); 
                       zeros(3,3), robot.links(i).mass * eye(3) ];
end

% Backwards recursion
for i = n:-1:1
    % Start with the base matrix for link i.
    M_i = base_MM(:,:,i);
    
    % Find all children of link i
    childs = find(robot.con.child(:,i))';
    
    if ~isempty(childs)
        % Extract the batch of transformation matrices for these children: 6x6xN.
        Bij_batch = Bij(1:6,1:6,childs,i); 
        % Compute contributions using pagemtimes with explicit permutation for transposition.
        tmp = pagemtimes(permute(Bij_batch, [2,1,3]), Mm_tilde(1:6,1:6,childs));
        contributions = pagemtimes(tmp, Bij_batch);
        % Sum the contributions along the third dimension.
        M_i = M_i + sum(contributions, 3);
    end
    
    Mm_tilde(1:6,1:6,i) = M_i;
end

% Base-link M tilde initialization
M0_tilde = [ I0, zeros(3,3); 
             zeros(3,3), robot.base_link.mass * eye(3) ];

% Process contributions from the children of the base link
childs_base = find(robot.con.child_base)';
if ~isempty(childs_base)
    % Extract the batch of transformation matrices for the base link: 6x6xN.
    Bi0_batch = Bi0(1:6,1:6,childs_base); 
    tmp = pagemtimes(permute(Bi0_batch, [2,1,3]), Mm_tilde(1:6,1:6,childs_base));
    contributions_base = pagemtimes(tmp, Bi0_batch);
    M0_tilde = M0_tilde + sum(contributions_base, 3);
end

end