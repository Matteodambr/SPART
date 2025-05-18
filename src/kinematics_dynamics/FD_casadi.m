function [u0dot, umdot] = FD_casadi(tau0, taum, wF0, wFm, t0, tm, P0, pm, I0, Im, Bij, Bi0, u0, um, robot)

n = robot.n_links_joints;
n_q = robot.n_q;

%=== Inverse Dynamics with zero accelerations ===%
[t0dot, tmdot] = Accelerations_casadi(t0, tm, P0, pm, Bi0, Bij, u0, um, zeros(6,1), zeros(n_q,1), robot);
[tau0_0ddot, taum_0ddot] = ID_casadi(wF0, wFm, t0, tm, t0dot, tmdot, P0, pm, I0, Im, Bij, Bi0, robot);

%=== Forward Dynamics ===%
phi0 = tau0 - tau0_0ddot;
phi = taum - taum_0ddot;

% Allocate
M_hat = cell(n, 1);
psi_hat = cell(n, 1);
psi = cell(n, 1);

%=== Backward recursion for M_hat, psi_hat, psi ===%
for i = n:-1:1
    m_i = robot.links(i).mass;
    I_i = Im{i};  % cell: {3x3}

    M_hat{i} = [I_i, zeros(3,3); zeros(3,3), m_i*eye(3)];

    for j = 1:n
        if robot.con.child(j, i) ~= 0
            Bij_ji = Bij{j, i};
            psi_j = psi{j};
            psi_hat_j = psi_hat{j};
            M_hat_ji = M_hat{j} - psi_hat_j * psi_j';
            M_hat{i} = M_hat{i} + Bij_ji' * M_hat_ji * Bij_ji;
        end
    end

    if robot.joints(i).type == 0
        psi_hat{i} = zeros(6,1);
        psi{i} = zeros(6,1);
    else
        psi_hat{i} = M_hat{i} * pm(:, i);
        psi{i} = psi_hat{i} / (pm(:, i)' * psi_hat{i});
    end
end

%=== Base link M_hat0 ===%
m0 = robot.base_link.mass;
M_hat0 = [I0, zeros(3,3); zeros(3,3), m0 * eye(3)];

for j = 1:n
    if robot.con.child_base(j) ~= 0
        Bi0j = Bi0{j};
        psi_hat_j = psi_hat{j};
        psi_j = psi{j};
        M_hat0 = M_hat0 + Bi0j' * (M_hat{j} - psi_hat_j * psi_j') * Bi0j;
    end
end

psi_hat0 = M_hat0 * P0;

%=== eta, phi_hat, phi_tilde ===%
eta = cell(n, 1);
phi_hat = casadi.SX.zeros(n,1);
phi_tilde = casadi.SX.zeros(n_q,1);

for i = n:-1:1
    eta{i} = casadi.SX.zeros(6,1);
    for j = 1:n
        if robot.con.child(j, i) ~= 0
            Bij_ji = Bij{j, i};
            eta{i} = eta{i} + Bij_ji' * (psi{j} * phi_hat(j) + eta{j});
        end
    end
    phi_hat(i) = -pm(:, i)' * eta{i};
    if robot.joints(i).type ~= 0
        phi_hat(i) = phi_hat(i) + phi(robot.joints(i).q_id);
        phi_tilde(robot.joints(i).q_id) = phi_hat(i) / (pm(:, i)' * psi_hat{i});
    end
end

%=== Base-link phi_tilde0 ===%
eta0 = casadi.SX.zeros(6,1);
for j = 1:n
    if robot.con.child_base(j) ~= 0
        eta0 = eta0 + Bi0{j}' * (psi{j} * phi_hat(j) + eta{j});
    end
end
phi_hat0 = phi0 - P0' * eta0;
phi_tilde0 = solve(P0' * psi_hat0, phi_hat0);  % Better for symbolic safety

u0dot = phi_tilde0;

%=== Forward recursion for manipulator acceleration ===%
mu = cell(n,1);
umdot = casadi.SX.zeros(n_q,1);

for i = 1:n
    if robot.joints(i).parent_link == 0
        mu{i} = Bi0{i} * (P0 * u0dot);
    else
        parent_id = robot.joints(i).parent_link;
        parent_joint = robot.joints(parent_id);
        mu_aux = mu{parent_id};
        if parent_joint.type ~= 0
            mu_aux = pm(:, parent_id) * umdot(parent_joint.q_id) + mu_aux;
        end
        mu{i} = Bij{i, i-1} * mu_aux;
    end

    if robot.joints(i).type ~= 0
        umdot(robot.joints(i).q_id) = phi_tilde(robot.joints(i).q_id) - psi{i}' * mu{i};
    end
end

%=== Convert symbolic outputs to numeric if all inputs are numeric ===%
if ~isa(tau0, 'casadi.SX') && ~isa(taum, 'casadi.SX') && ...
   ~isa(wF0, 'casadi.SX') && ~isa(wFm, 'casadi.SX') && ...
   ~isa(t0, 'casadi.SX') && ~isa(tm, 'casadi.SX') && ...
   ~isa(P0, 'casadi.SX') && ~isa(pm, 'casadi.SX') && ...
   ~isa(I0, 'casadi.SX') && ~any(cellfun(@(c) isa(c, 'casadi.SX'), Im)) && ...
   ~any(cellfun(@(c) isa(c, 'casadi.SX'), Bij(:))) && ...
   ~any(cellfun(@(c) isa(c, 'casadi.SX'), Bi0(:))) && ...
   ~isa(u0, 'casadi.SX') && ~isa(um, 'casadi.SX')

    % Convert to full numeric output
    u0dot = full(evalf(u0dot)) ;
    umdot = full(evalf(umdot)) ;
end


end
