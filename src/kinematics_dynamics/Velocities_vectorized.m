function [t0,tL] = Velocities_vectorized(Bij,Bi0,P0,pm,u0,um,robot)
% Computes the operational-space velocities of the multibody system.
%
% [t0,tL]=Velocities(Bij,Bi0,P0,pm,u0,um,robot)
%
% :parameters:
%   * Bij -- Twist-propagation matrix (for manipulator i>0 and j>0) -- as a [6x6xn] matrix.
%   * Bi0 -- Twist-propagation matrix (for i>0 and j=0) -- as a [6x6xn] matrix.
%   * P0 -- Base-link twist-propagation "vector" -- as a [6x6] matrix.
%   * pm -- Manipulator twist-propagation "vector" -- as a [6xn] matrix.
%   * u0 -- Base-link velocities [ω, rdot] (angular velocity projected in the body-fixed CCS,
%           linear velocity in the inertial CCS) -- as a [6x1] vector.
%   * um -- Joint velocities -- as a [n_q x 1] vector.
%   * robot -- Robot model.
%
% :return:
%   * t0 -- Base-link twist [ω, rdot] projected in the inertial CCS -- as a [6x1] vector.
%   * tL -- Manipulator twists [ω, rdot] projected in the inertial CCS -- as a [6xn] matrix.
%
% Note: The recursive propagation cannot be fully vectorized because each link’s
% twist depends on the previous one. Here, we use cell arrays (and vectorized joint
% contribution) to hide part of the recursion.
    
% Number of links (and joints)
n = robot.n_links_joints;

% Compute base-link twist.
t0 = P0 * u0;

% Preallocate cell array for cumulative twists.
T = cell(1, n);

% Precompute joint-related data.
% Get the joint type and q_id from each joint.
% (type==0 for fixed joints, type==1 (revolute) and type==2 (prismatic))
types = [robot.joints.type];
q_ids = arrayfun(@(j) j.q_id, robot.joints);

% Ensure um(q_ids) is a row vector so that multiplication with pm (6xn) is column-wise.
joint_vel = um(q_ids(:))';  % 1xn row vector

% Compute the joint contribution for each joint (6x1), scaled by its velocity.
% For fixed joints (type==0) the contribution is zero.
joint_contrib = pm .* repmat(joint_vel, 6, 1);

% Create a cell array of the propagation matrices for each joint.
% For each joint i, if its parent link is 0 then use Bi0(:,:,i) (first link);
% otherwise use Bij(:,:,i,i-1).
M = cell(1, n);
for i = 1:n
    if robot.joints(i).parent_link == 0
        M{i} = Bi0(:,:,i);
    else
        M{i} = Bij(:,:,i,i-1);
    end
end

% Compute the cumulative twist propagation.
% For the first joint:
T{1} = M{1} * t0 + (types(1) ~= 0) * joint_contrib(:,1);
% For joints 2 to n, propagate sequentially.
for i = 2:n
    T{i} = M{i} * T{i-1} + (types(i) ~= 0) * joint_contrib(:,i);
end

% Convert the cell array into a 6xn matrix.
tL = cell2mat(T);  % Each cell is 6x1, arranged horizontally.
    
end