function [tau0, taum] = ID_C(wF0, wFm, t0, tL, t0dot, tLdot, P0, pm, I0, Im, Bij, Bi0, nLinksJoints, nQ, robotBaseLink, robotLinks, robotConChild, robotConChildBase, robotJoints)

    Z = @(varargin) zeros(varargin{:});

    n = nLinksJoints;
    n_active = nQ;

    %--- Mdot ---%
    Mdot0 = [SkewSym(t0(1:3)) * I0, Z(3,3);
             Z(3,3),                 Z(3,3)];

    Mdot = cell(1,n);
    for i = 1:n
        Mdot{i} = [SkewSym(tL(1:3,i)) * Im{i}, Z(3,3);
                   Z(3,3),                      Z(3,3)];
    end

    %--- Forces ---%
    wq0 = [I0, Z(3,3);
           Z(3,3), robotBaseLink.mass * eye(3)] * t0dot + ...
           Mdot0 * t0 - wF0;

    wq = Z(6, n);
    for i = 1:n_active
        link_mass = robotLinks(i).mass;
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
            if robotConChild(j,i) ~= 0
                wq_tilde(:,i) = wq_tilde(:,i) + Bij{j,i}' * wq_tilde(:,j);
            end
        end
    end

    wq_tilde0 = wq0;
    for j = 1:n
        if robotConChildBase(j) ~= 0
            wq_tilde0 = wq_tilde0 + Bi0{j}' * wq_tilde(:,j);
        end
    end

    %--- Joint Forces ---%
    tau0 = P0' * wq_tilde0;
    taum = Z(nQ, 1);
    for i = 1:n
        if robotJoints(i).type ~= 0
            qid = robotJoints(i).q_id;
            taum(qid) = pm(:,i)' * wq_tilde(:,i);
        end
    end
end
