function [I0,Im]=I_I(R0_body2I,RL,robot)
% Projects the link inertias in the inertial CCS.
%
% [I0,Im]=I_I(R0_body2I,RL,robot)
%
% :parameters: 
%   * R0_body2I -- Active rotation from the base-link body CCS to the inertial CCS [3x3].
%                  V_I = R0_body2I * V_B  (maps body-frame vectors to the inertial frame).
%                  NOTE: This is the BODY->INERTIAL active rotation, i.e. the transpose of
%                  the inertial->body rotation stored in the ODE state vector.
%   * RL -- Links CCS 3x3 rotation matrices (body-to-inertial) with respect to the inertial CCS -- as a [3x3xn] matrix.
%   * robot -- Robot model (see :doc:`/Tutorial_Robot`).
%
% :return: 
%   * I0 -- Base-link inertia matrix, projected in the inertial CCS -- as a [3x3] matrix.
%   * Im -- Links inertia matrices, projected in the inertial CCS -- as a [3x3xn] matrix.
%
% See also: :func:`src.kinematics_dynamics.MCB`. 

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

%=== CODE ===%

%Base-link inertia
% Similarity transform: I_inertial = R * I_body * R'
I0 = R0_body2I*robot.base_link.inertia*R0_body2I';

%Pre-allocate inertias
Im=zeros(3,3,robot.n_links_joints,'like',R0_body2I);

%Inertias of the links
for i=1:(robot.n_links_joints)
    Im(1:3,1:3,i)=RL(1:3,1:3,i)*robot.links(i).inertia*RL(1:3,1:3,i)';
end

end
