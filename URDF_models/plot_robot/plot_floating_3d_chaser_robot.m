function plot_floating_3d_chaser_robot(R0_I2body, r0, qm, robot_matlab, color, linestyle, urdf_path)
% PLOT_FLOATING_3D_CHASER_ROBOT  Visualize the 3D floating-base space robot.
%
%   Inputs:
%       R0_I2body    - 3x3 DCM (inertial-to-body) of the spacecraft base
%       r0           - 3x1 or 1x3 base position in inertial frame [m]
%       qm           - Nx1 joint angles [rad]
%       robot_matlab - MATLAB rigidBodyTree loaded from floating_7dof_manipulator.urdf
%       color        - 1x3 RGB color for links and base wireframe
%       linestyle    - Line style string (e.g. '-', '--')
%       urdf_path    - (optional) full path to the URDF file; auto-detected if omitted

if nargin < 7 || isempty(urdf_path)
    urdf_path = which('floating_7dof_manipulator.urdf') ;
    if isempty(urdf_path)
        urdf_path = which('ChaserRobot.urdf') ;   % legacy fallback
    end
end

r0 = r0(:) ;    % ensure column
qm = qm(:) ;    % ensure column

robot_matlab.DataFormat = 'column' ;
robot_matlab.Gravity    = [0 0 0] ;

% R0_I2body is body-from-inertial → world-from-base rotation is transpose
R_world_from_base = R0_I2body' ;
T_base = eye(4) ;
T_base(1:3, 1:3) = R_world_from_base ;
T_base(1:3, 4)   = r0 ;

%% Base wireframe box -------------------------------------------------------
% The Chaser_Base link has no <visual> geometry in the URDF, and MATLAB's
% rigidBodyTree.Base does not expose Mass/Inertia.
% Parse the URDF XML directly to read the base inertial properties, then
% recover box half-dims assuming a solid rectangular box:
%   Ixx = m(b²+c²)/3,  Iyy = m(a²+c²)/3,  Izz = m(a²+b²)/3
[m_base, Ixx, Iyy, Izz] = parse_urdf_base_inertia(urdf_path, robot_matlab.BaseName) ;
a = sqrt(max(0, (Iyy + Izz - Ixx) * 3 / (2 * m_base))) ;  % x half-dim
b = sqrt(max(0, (Ixx + Izz - Iyy) * 3 / (2 * m_base))) ;  % y half-dim
c = sqrt(max(0, (Ixx + Iyy - Izz) * 3 / (2 * m_base))) ;  % z half-dim

% 8 corners in the base body frame
sx = [-1  1  1 -1 -1  1  1 -1] * a ;
sy = [-1 -1  1  1 -1 -1  1  1] * b ;
sz = [-1 -1 -1 -1  1  1  1  1] * c ;
corners_body = [sx ; sy ; sz ; ones(1,8)] ;    % 4×8 homogeneous

% Transform corners to world frame
corners_world = T_base * corners_body ;         % 4×8
cx = corners_world(1,:) ;
cy = corners_world(2,:) ;
cz = corners_world(3,:) ;

% 12 edges as index pairs (corners numbered 1..8 following the order above)
edges = [1 2; 2 3; 3 4; 4 1; ...   % bottom face
         5 6; 6 7; 7 8; 8 5; ...   % top face
         1 5; 2 6; 3 7; 4 8] ;     % vertical pillars

for e = 1:size(edges, 1)
    i = edges(e, 1) ;  j = edges(e, 2) ;
    plot3([cx(i) cx(j)], [cy(i) cy(j)], [cz(i) cz(j)], ...
        linestyle, 'Color', color, 'LineWidth', 1.5, 'HandleVisibility', 'off') ;
end

%% Manipulator links --------------------------------------------------------
n_bodies = numel(robot_matlab.Bodies) ;
link_origins = zeros(3, n_bodies) ;
for b_idx = 1:n_bodies
    T_body_local = getTransform(robot_matlab, qm, robot_matlab.Bodies{b_idx}.Name) ;
    T_body_world = T_base * T_body_local ;
    link_origins(:, b_idx) = T_body_world(1:3, 4) ;
end

p_base = r0 ;   % 3×1

% Line from base origin → Link_1 → ... → EE
chain_points = [p_base, link_origins] ;   % 3×(n_bodies+1)
plot3(chain_points(1,:), chain_points(2,:), chain_points(3,:), ...
    linestyle, 'Color', color, 'LineWidth', 2, 'HandleVisibility', 'off') ;

% Joint dots (all except the fixed EE joint)
n_moving = size(link_origins, 2) - 1 ;
scatter3(link_origins(1, 1:n_moving), ...
         link_origins(2, 1:n_moving), ...
         link_origins(3, 1:n_moving), ...
         40, color, 'filled', 'HandleVisibility', 'off') ;

% End-effector dot
scatter3(link_origins(1, end), link_origins(2, end), link_origins(3, end), ...
    80, 'r', 'filled', 'HandleVisibility', 'off') ;

end
