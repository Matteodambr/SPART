function [H0, H0m, Hm] = GIM_vectorized(M0_tilde,Mm_tilde,Bij,Bi0,P0,pm,robot)
% Computes the Generalized Inertia Matrix (GIM) H of the multibody vehicle.
%
% [H0, H0m, Hm] = GIM(M0_tilde,Mm_tilde,Bij,Bi0,P0,pm,robot)
%
% Parameters:
%   M0_tilde   -- [6x6] base-link mass composite body matrix.
%   Mm_tilde   -- [6x6xn] manipulator mass composite body matrices.
%   Bij        -- [6x6xnxn] twist-propagation matrices among manipulators.
%   Bi0        -- [6x6xn] twist-propagation matrices from base-link.
%   P0         -- [6x6] base-link twist-propagation matrix.
%   pm         -- [6xn] manipulator twist-propagation vectors.
%   robot      -- robot model structure; robot.joints must contain fields
%                 "type" and "q_id", and robot.n_q and robot.n_links_joints.
%
% Returns:
%   H0   -- [6x6] base-link inertia matrix.
%   H0m  -- [6xn_q] base-link/manipulator coupling inertia matrix.
%   Hm   -- [n_qxn_q] manipulator inertia matrix.

%{  
    LICENSE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
%}

%--- Number of links and joints ---%
n_q = robot.n_q;
n   = robot.n_links_joints;

%--- Base-link inertia matrix ---%
H0 = P0' * M0_tilde * P0;

%--- Pre-allocate matrices ---%
H0m = zeros(6, n_q, 'like', M0_tilde);

%--- Identify active joints ---%
active = find(arrayfun(@(j) j.type~=0, robot.joints));  
% Get actual q indices for active joints.
q_ids = arrayfun(@(j) j.q_id, robot.joints(active));  

%--- Vectorized computation of coupling inertia matrix H0m ---%
% We compute for each active joint:
%   temp = (pm(1:6,i)' * Mm_tilde(1:6,1:6,i) * Bi0(1:6,1:6,i) * P0)';  (6×1)
%
% Use pagemtimes on each active page in a cell loop.
tempH0m = cell(1, numel(active));
for k = 1:numel(active)
    i = active(k);
    % Compute: 1x6 = pm(:,i)' * Mm_tilde(:,:,i)
    temp = pagemtimes(pm(1:6,i)', Mm_tilde(1:6,1:6,i));  
    % Multiply with Bi0(:,:,i) => 1x6
    temp = pagemtimes(temp, Bi0(1:6,1:6,i));  
    % Multiply with P0 => 1x6. Then transpose to get 6x1.
    tempH0m{k} = pagemtimes(temp, P0)';
    % Assign the result into the corresponding column.
    H0m(:, q_ids(k)) = tempH0m{k};
end    

%Pre-allocate Hm
Hm=zeros(n_q,n_q,'like',M0_tilde);

% BUG: This is the code currently used to implement Hm, which is not vectorized.
% Manipulator inertia matrix Hm
for j=1:n
    for i=j:n
        if robot.joints(i).type~=0 && robot.joints(j).type~=0
            Hm(robot.joints(i).q_id,robot.joints(j).q_id)=pm(1:6,i)'*Mm_tilde(1:6,1:6,i)*Bij(1:6,1:6,i,j)*pm(1:6,j);
            Hm(robot.joints(j).q_id,robot.joints(i).q_id)=Hm(robot.joints(i).q_id,robot.joints(j).q_id);
        end
    end
end

end