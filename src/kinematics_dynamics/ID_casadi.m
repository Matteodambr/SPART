function [tau0, taum] = ID_casadi(wF0, wFm, t0, tL, t0dot, tLdot, P0, pm, I0, Im, Bij, Bi0, robot)
    import casadi.*

    % Determine type: symbolic (SX) or numeric (double)
    is_symbolic = isa(wF0, 'casadi.SX') || isa(wFm, 'casadi.SX') || ...
                  isa(t0, 'casadi.SX') || isa(tL, 'casadi.SX') || ...
                  isa(t0dot, 'casadi.SX') || isa(tLdot, 'casadi.SX') || ...
                  isa(P0, 'casadi.SX') || isa(pm, 'casadi.SX');

    % Use SX or double zeros depending on input type
    if is_symbolic
        Z = @(varargin) SX.zeros(varargin{:});
    else
        Z = @(varargin) zeros(varargin{:});
    end

    n = robot.n_links_joints;
    n_active = robot.n_q;

    %--- Mdot ---%
    Mdot0 = [SkewSym(t0(1:3)) * I0, Z(3,3);
             Z(3,3),               Z(3,3)];

    Mdot = cell(1,n);
    for i = 1:n
        Mdot{i} = [SkewSym(tL(1:3,i)) * Im{i}, Z(3,3);
                   Z(3,3),                    Z(3,3)];
    end

    %--- Forces ---%
    wq0 = [I0, Z(3,3);
           Z(3,3), robot.base_link.mass * eye(3)] * t0dot + ...
           Mdot0 * t0 - wF0;

    wq = Z(6, n);
    for i = 1:n_active
        link_mass = robot.links(i).mass;
        inertia = Im{i};
        wq(:,i) = [inertia, Z(3,3);
                   Z(3,3), link_mass * eye(3)] * tLdot(:,i) + ...
                   Mdot{i} * tL(:,i) - wFm(:,i);
    end

    %--- Backward recursion ---%
    wq_tilde = Z(6, n);
    for i = n:-1:1
        wq_tilde(:,i) = wq(:,i);
        for j = 1:n
            if robot.con.child(j,i) ~= 0
                wq_tilde(:,i) = wq_tilde(:,i) + Bij{j,i}' * wq_tilde(:,j);
            end
        end
    end

    wq_tilde0 = wq0;
    for j = 1:n
        if robot.con.child_base(j) ~= 0
            wq_tilde0 = wq_tilde0 + Bi0{j}' * wq_tilde(:,j);
        end
    end

    %--- Joint Forces ---%
    tau0 = P0' * wq_tilde0;
    taum = Z(robot.n_q, 1);
    for i = 1:n
        if robot.joints(i).type ~= 0
            qid = robot.joints(i).q_id;
            taum(qid) = pm(:,i)' * wq_tilde(:,i);
        end
    end
end
