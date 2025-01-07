function Jstar = Jstar(H0, H0m, J0, Jm)
% This is formula 45.6 in "Handbook of Robotics" - Siciliano, Springer

h = H0\H0m ;
Jstar = Jm - J0*h ;

end
