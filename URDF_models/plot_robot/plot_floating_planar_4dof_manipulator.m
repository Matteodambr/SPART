function plot_floating_planar_4dof_manipulator(config, robot, color, FLAG_CREATE_NEW_FIG, varargin)
% plotPlanarRobott Visualizes a 2D floating-base planar 4-DOF manipulator.
%   Input:
%       config - [x(m), y(m), theta(rad), q1(rad), q2(rad), q3(rad), q4(rad)]
%       EEcolor (optional, name-value) - color for end-effector (default: 'r')
%       linestyle (optional, name-value) - line style for links/base (default: '-')
%       plotCollisionSpheres (optional, name-value) - flag to plot collision spheres (default: false)

% Parse optional arguments
p = inputParser;
p.addRequired('config', @(x) isnumeric(x) && numel(x)==7);
p.addRequired('robot');
p.addRequired('color');
p.addRequired('FLAG_CREATE_NEW_FIG', @(x) islogical(x) || isnumeric(x));
p.addParameter('EEcolor', 'r');
p.addParameter('linestyle', '-');
p.addParameter('plotCollisionSpheres', false); % Optional flag
p.KeepUnmatched = true;
p.parse(config, robot, color, FLAG_CREATE_NEW_FIG, varargin{:});
EEcolor = p.Results.EEcolor;
linestyle = p.Results.linestyle;
plotCollisionSpheres = p.Results.plotCollisionSpheres;

% Validate input
if any(config(3:end)>2*pi | config(3:end)<-2*pi)
    warning('Detected angles >2pi or <2pi. Make sure inputs to plot_floating_planar_4dof_manipulator.m are in radians!') ;
end
x = config(1); y = config(2); theta = config(3);
q = config(4:end)';

% Load robot
robot.DataFormat = 'column';
robot.Gravity = [0 0 0];

% Compute base transform manually (planar SE(2) to SE(3))
T_base = trvec2tform([x, y, 0]) * axang2tform([0 0 1 theta]);

% Get link transforms in base frame (default robot base at origin)
T1 = getTransform(robot, q, 'Link_1');
T2 = getTransform(robot, q, 'Link_2');
T3 = getTransform(robot, q, 'Link_3');
T4 = getTransform(robot, q, 'Link_4');

% Compose world transforms manually using base
T1w = T_base * T1;
T2w = T_base * T2;
T3w = T_base * T3;
T4w = T_base * T4;

% Define local positions of key points
p_j1 = T_base * [0.25; 0; 0; 1];
p_j2 = T1w * [0.5; 0; 0; 1];
p_j3 = T2w * [0.5; 0; 0; 1];
p_j4 = T3w * [0.5; 0; 0; 1];
p_ee = T4w * [0.5; 0; 0; 1];

% Collect 2D points
points = [p_j1(1:2), p_j2(1:2), p_j3(1:2), p_j4(1:2), p_ee(1:2)];
joints = points(:, 1:4)';

% Draw base square manually transformed
base_size = 0.5;
half = base_size / 2;
base_local = [
    -half, -half, 0, 1;
    half, -half, 0, 1;
    half,  half, 0, 1;
    -half,  half, 0, 1;
    -half, -half, 0, 1;
    ]';
base_world = T_base * base_local;
base2D = base_world(1:2, :);

% Plotting
if FLAG_CREATE_NEW_FIG
    figure;
end
hold on;
plot(base2D(1,:), base2D(2,:), linestyle, 'LineWidth', 2, Color=color, HandleVisibility='off');         % base
plot(points(1,:), points(2,:), linestyle, 'LineWidth', 1.5, Color=color, HandleVisibility='off');       % links
scatter(joints(:,1), joints(:,2), 50, color, 'filled', HandleVisibility='off');         % joints
hold on ;
scatter(points(1,end), points(2,end), 80, EEcolor, 'filled', HandleVisibility='off');     % end-effector as colored dot

% Plot collision spheres if requested
if plotCollisionSpheres
    % For each body (excluding base)
    for i = 1:length(robot.Bodies)
        body = robot.Bodies{i};
        % Get transform for this body
        T_body = getTransform(robot, q, body.Name);
        T_body_world = T_base * T_body;
        % For each collision object
        for j = 1:length(body.Collisions)
            c = body.Collisions{j};
            if isa(c, 'collisionSphere')
                % Get sphere center in body frame
                center = tform2trvec(c.Pose); % 1x3
                center_hom = [center 1]';
                % Transform to world
                center_world = T_body_world * center_hom;
                % Plot sphere (project to XY)
                viscircles(center_world(1:2)', c.Radius, 'Color', color, 'LineStyle', '--', 'LineWidth', 1, 'EnhanceVisibility', false);
            end
        end
    end
end

% Labels
if FLAG_CREATE_NEW_FIG
    title('Planar Floating-Base Robot');
    xlabel('X (m)'); ylabel('Y (m)');
    all_x = [points(1,:), base2D(1,:)];
    all_y = [points(2,:), base2D(2,:)];
    padding = 0.4;
    xlim([min(all_x)-padding, max(all_x)+padding]);
    ylim([min(all_y)-padding, max(all_y)+padding]);
    axis equal; grid on;
end

end
