function [RJ, RL, rJ, rL, e, g] = Kinematics_casadi(R0, r0, qm, robot)

% Determine if inputs are symbolic (casadi) or numeric
is_symbolic = isa(R0, 'casadi.SX') || isa(R0, 'casadi.MX') || isa(r0, 'casadi.SX') || isa(r0, 'casadi.MX') || ...
    isa(qm, 'casadi.SX') || isa(qm, 'casadi.MX');

if is_symbolic
    zeros3n = @(m,n) casadi.SX.zeros(m,n);
    zeros1n = @(m,n) casadi.SX.zeros(m,n);
    eye3 = @() casadi.SX.eye(3);
    eye4 = @() casadi.SX.eye(4);
    sx1 = @() casadi.SX(1);
else
    zeros3n = @(m,n) zeros(m,n);
    zeros1n = @(m,n) zeros(m,n);
    eye3 = @() eye(3);
    eye4 = @() eye(4);
    sx1 = @() 1;
end

n = robot.n_links_joints;

TJ = cell(1, n);
TL = cell(1, n);

rJ = zeros3n(3, n);
rL = zeros3n(3, n);
e  = zeros3n(3, n);
g  = zeros3n(3, n);

T0 = [R0, r0; zeros1n(1, 3), sx1()];

for i = 1:n
    cjoint = robot.joints(i);

    if cjoint.parent_link == 0
        TJ{cjoint.id} = T0 * cjoint.T;
    else
        TJ{cjoint.id} = TL{cjoint.parent_link} * cjoint.T;
    end

    if cjoint.type == 1  % Revolute
        T_qm = [Euler_DCM(cjoint.axis, qm(cjoint.q_id))', zeros3n(3,1); zeros1n(1,3), sx1()];

    elseif cjoint.type == 2  % Prismatic
        T_qm = [eye3(), cjoint.axis * qm(cjoint.q_id); zeros1n(1,3), sx1()];

    else
        T_qm = eye4();
    end

    clink = robot.links(cjoint.child_link);
    TL{clink.id} = TJ{cjoint.id} * T_qm * clink.T;
end

% Preallocate 2D matrices for rotations (3 x 3*n)
RJ = zeros3n(3, 3*n);
RL = zeros3n(3, 3*n);

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
