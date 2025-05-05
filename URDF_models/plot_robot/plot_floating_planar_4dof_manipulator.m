function plot_floating_planar_4dof_manipulator(config)
    % plotPlanarRobott Visualizes a 2D floating-base planar 4-DOF manipulator.
    %
    %   Input:
    %       config - [x(m), y(m), theta(rad), q1(rad), q2(rad), q3(rad), q4(rad)]
    
        % Validate input
        if numel(config) ~= 7
            error('Expected 7-element config: [x, y, theta, q1, q2, q3, q4]');
        end
        if any(config(3:end)>2*pi | config(3:end)<2*pi)
            warning('Detected angles >2pi or <2pi. Make sure inputs to plot_floating_planar_4dof_manipulator.m are in radians!') ;
        end
        x = config(1); y = config(2); theta = config(3);
        q = config(4:end)';
    
        % Define URDF path
        urdfPath = fullfile('src', 'SPART', 'URDF_models', 'floating_planar_4dof_manipulator.urdf');
        if ~isfile(urdfPath)
            error('URDF file not found: %s', urdfPath);
        end
    
        % Load robot
        robot = importrobot(urdfPath);
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
        figure; hold on; axis equal; grid on;
        plot(base2D(1,:), base2D(2,:), 'k-', 'LineWidth', 2);         % base
        plot(points(1,:), points(2,:), 'k-', 'LineWidth', 1.5);       % links
        scatter(joints(:,1), joints(:,2), 50, 'k', 'filled');         % joints
    
        % Labels
        title('Planar Floating-Base Robot');
        xlabel('X (m)'); ylabel('Y (m)');
        all_x = [points(1,:), base2D(1,:)];
        all_y = [points(2,:), base2D(2,:)];
        padding = 0.5;
        xlim([min(all_x)-padding, max(all_x)+padding]);
        ylim([min(all_y)-padding, max(all_y)+padding]);
        hold off;
    end
    