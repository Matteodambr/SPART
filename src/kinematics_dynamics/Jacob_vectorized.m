function [J0, Jm] = Jacob_vectorized(rp, r0, rL, P0, pm, i, robot)
    % Computes the geometric Jacobian of a point `p`.
    %
    % [J0, Jm]=Jacob_vectorized(rp,r0,rL,P0,pm,i,robot)
    %
    % Parameters:
    %   rp    - Position of the point of interest, [3x1]
    %   r0    - Position of the base-link, [3x1]
    %   rL    - Positions of the links, [3xn]
    %   P0    - Base-link twist-propagation matrix, [6x6]
    %   pm    - Manipulator twist-propagation matrix, [6xn]
    %   i     - Link id where the point `p` is located (int, 0 to n)
    %   robot - Robot model structure containing joints and connectivity info
    %
    % Returns:
    %   J0    - Base-link geometric Jacobian, [6x6]
    %   Jm    - Manipulator geometric Jacobian, [6xn_q]
    
    % Compute Base-link Jacobian
    J0 = [eye(3), zeros(3, 3); SkewSym(r0 - rp), eye(3)] * P0;
    
    % Pre-allocate manipulator Jacobian
    Jm = zeros(6, robot.n_q, 'like', rp);
    
    % Process all joints from 1 to i
    jointsIdx = 1:i;
    jointTypes = [robot.joints(jointsIdx).type];
    activeMask = (jointTypes ~= 0) & (robot.con.branch(i, jointsIdx) == 1);
    
    if ~any(activeMask)
        return;
    end
    
    activeIndices = jointsIdx(activeMask);
    q_ids = [robot.joints(activeIndices).q_id];
    
    % Compute difference between link positions and rp for active joints
    delta = rL(1:3, activeIndices) - rp;
    
    % Extract twist components for active joints
    v = pm(1:3, activeIndices);
    w = pm(4:6, activeIndices);
    
    % Compute cross product manually in a vectorized way
    cp = [ delta(2,:) .* v(3,:) - delta(3,:) .* v(2,:);
           delta(3,:) .* v(1,:) - delta(1,:) .* v(3,:);
           delta(1,:) .* v(2,:) - delta(2,:) .* v(1,:)];
    
    % Assemble the manipulator Jacobian
    Jm(1:3, q_ids) = v;
    Jm(4:6, q_ids) = cp + w;
end