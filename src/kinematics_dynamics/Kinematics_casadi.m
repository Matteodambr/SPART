function [RJ, RL, rJ, rL, e, g] = Kinematics_casadi(R0, r0, qm, robot)
    import casadi.*

    n = robot.n_links_joints;

    TJ = cell(1, n);
    TL = cell(1, n);

    rJ = SX.zeros(3, n);
    rL = SX.zeros(3, n);
    e  = SX.zeros(3, n);
    g  = SX.zeros(3, n);

    T0 = [R0, r0; SX.zeros(1, 3), SX(1)];

    for i = 1:n
        cjoint = robot.joints(i);

        if cjoint.parent_link == 0
            TJ{cjoint.id} = T0 * cjoint.T;
        else
            TJ{cjoint.id} = TL{cjoint.parent_link} * cjoint.T;
        end

        if cjoint.type == 1  % Revolute
            T_qm = [Euler_DCM_casadi(cjoint.axis, qm(cjoint.q_id))', SX.zeros(3,1); SX.zeros(1,3), SX(1)];
        elseif cjoint.type == 2  % Prismatic
            T_qm = [SX.eye(3), cjoint.axis * qm(cjoint.q_id); SX.zeros(1,3), SX(1)];
        else
            T_qm = SX.eye(4);
        end

        clink = robot.links(cjoint.child_link);
        TL{clink.id} = TJ{clink.parent_joint} * T_qm * clink.T;
    end

    % Preallocate 2D matrices for rotations (3 x 3*n)
    RJ = SX.zeros(3, 3*n);
    RL = SX.zeros(3, 3*n);

    for i = 1:n
        RJ_i = TJ{i}(1:3, 1:3);
        RL_i = TL{i}(1:3, 1:3);

        RJ(:, 3*(i-1)+1 : 3*i) = RJ_i;
        RL(:, 3*(i-1)+1 : 3*i) = RL_i;

        rJ(:, i) = TJ{i}(1:3, 4);
        rL(:, i) = TL{i}(1:3, 4);
        e(:, i)  = RJ_i * robot.joints(i).axis;
        g(:, i)  = rL(:, i) - rJ(:, robot.links(i).parent_joint);
    end
end
