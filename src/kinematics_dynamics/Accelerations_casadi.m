function [t0dot, tLdot] = Accelerations_casadi(t0, tL, P0, pm, Bi0, Bij, u0, um, u0dot, umdot, robot)
    import casadi.*

    n = robot.n_links_joints;

    %--- Base-link Omega matrix ---%
    Omega0 = [SkewSym_casadi(t0(1:3)), SX.zeros(3,3);
              SX.zeros(3,3),    SX.zeros(3,3)];

    %--- Precompute Omegam as cell array ---%
    Omegam = cell(1,n);
    for i = 1:n
        S = SkewSym_casadi(tL(1:3,i));
        Omegam{i} = [S, SX.zeros(3,3);
                     SX.zeros(3,3), S];
    end

    %--- Base-link twist rate ---%
    t0dot = Omega0 * P0 * u0 + P0 * u0dot;

    %--- Preallocate manipulator twist rate ---%
    tLdot = SX.zeros(6,n);

    %--- Forward recursion over links ---%
    for i = 1:n
        parent = robot.joints(i).parent_link;

        if parent == 0
            skew_term = SkewSym_casadi(t0(4:6) - tL(4:6,i));
            tLdot(:,i) = Bi0{i} * t0dot + ...
                         [SX.zeros(3,6); skew_term, SX.zeros(3,3)] * t0;
        else
            skew_term = SkewSym_casadi(tL(4:6,parent) - tL(4:6,i));
            tLdot(:,i) = Bij{i,parent} * tLdot(:,parent) + ...
                         [SX.zeros(3,6); skew_term, SX.zeros(3,3)] * tL(:,parent);
        end

        % Joint contribution
        if robot.joints(i).type ~= 0
            qid = robot.joints(i).q_id;
            tLdot(:,i) = tLdot(:,i) + Omegam{i} * pm(:,i) * um(qid) + pm(:,i) * umdot(qid);
        end
    end
end
