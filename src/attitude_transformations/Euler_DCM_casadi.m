function DCM = Euler_DCM_casadi(e, alpha)
    import casadi.*

    % Ensure symbolic inputs
    % e is 3x1 symbolic vector, alpha is a symbolic scalar

    % Create quaternion: q = [vector_part; scalar_part]
    q = [e * sin(alpha/2); cos(alpha/2)];

    % Convert to DCM using CasADi-compatible quaternion DCM function
    DCM = quat_DCM_casadi(q);
end
