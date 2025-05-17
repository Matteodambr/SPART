function x_skew = SkewSym_casadi(x)
% Computes the skew-symmetric matrix of a 3x1 vector using CasADi symbolic variables.
%
% Input:
%   x -- [3x1] CasADi SX or MX vector
%
% Output:
%   x_skew -- [3x3] skew-symmetric matrix of x

import casadi.*

x_skew = SX.zeros(3,3);

x_skew(1,2) = -x(3);
x_skew(1,3) =  x(2);

x_skew(2,1) =  x(3);
x_skew(2,3) = -x(1);

x_skew(3,1) = -x(2);
x_skew(3,2) =  x(1);

end
