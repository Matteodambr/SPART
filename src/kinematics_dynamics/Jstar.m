function Jstar = Jstar(H0, H0m, J0, Jm)
% This is formula 45.6 in "Handbook of Robotics" - Siciliano, Springer

% SAME GENERALIZED JACOBIAN ALSO IMPLEMENTED IN SIMULINK, IN THE COMPONENTS
% LIBRARY. THE ONLY DIFFERENT TO THEIR IMPLEMENTATION IS THAT h =
% inv(H0)*H0m. Check this.

h = H0\H0m ;
Jstar = Jm - J0*h ;

end
