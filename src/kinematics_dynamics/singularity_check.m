function isSingular = singularity_check(H0, H0m, J0ee, Jmee, PARAM_Chaser)
% SINGULARITY_CHECK Checks for arm singularity in a space manipulator.
%
%   isSingular = SINGULARITY_CHECK(H0, H0m, J0ee, Jmee, PARAM_Chaser)
%   checks for arm singularity in a space manipulator using the specified
%   parameters.
%
%   Inputs:
%       H0 - Transformation matrix of the base.
%       H0m - Transformation matrix of the manipulator.
%       J0ee - Jacobian matrix of the end-effector.
%       Jmee - Jacobian matrix of the manipulator.
%       PARAM_Chaser - Structure containing chaser parameters, including
%                      the singularity threshold.
%
%   Outputs:
%       isSingular - Boolean indicating if the manipulator is in a singular
%                    configuration.
%
%   Example:
%       isSingular = singularity_check(H0, H0m, J0ee, Jmee, PARAM_Chaser);
%
%   See also: Jstar, svd

% Check for arm singularity:
% On the Nature of Control Algorithms for Free-Floating Space Manipulators - Papadopoulos, Dubowsky
% This reference says that singular configurations are found when det(J*)=0
% As this is extremely inefficient to compute at each timestep, the check
% on singularity is done by checking the minimum Singular Value (SV) of the matrix at each timestep.
% Note: SVD is used since it works for non-square matrices, but maybe more efficient methods can be used???
jstar = Jstar(H0, H0m, J0ee, Jmee) ;
minSingularVal = min(svd(jstar)) ;
distanceFromSingularity = minSingularVal - PARAM_Chaser.singularity.threshold ;
isSingular = false ;
if distanceFromSingularity < 0 
    
    % First condition: Singularity check on Jacobian, to check for ANY
    % singularities
    isSingular = true ;

end