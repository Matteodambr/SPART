function DCM = quat_DCM_casadi(q)
    import casadi.*

    % Ensure q is symbolic (e.g. SX or MX)
    q = SX.sym('q', 4);  % if needed outside, remove this line and ensure q is already symbolic when calling

    q1 = q(1);
    q2 = q(2);
    q3 = q(3);
    q4 = q(4);

    DCM = [ 1 - 2*(q2^2 + q3^2),     2*(q1*q2 + q3*q4),     2*(q1*q3 - q2*q4);
            2*(q2*q1 - q3*q4),     1 - 2*(q1^2 + q3^2),     2*(q2*q3 + q1*q4);
            2*(q3*q1 + q2*q4),     2*(q3*q2 - q1*q4),     1 - 2*(q1^2 + q2^2) ];
end
