function robot = robot_totalMass(robot)
%
% 1. PROTOTYPE:
% robot = robot_totalMass(robot)
%
% 2. DESCRIPTION:
% Function adds total mass field to robot structure 
%
% 3. INPUT    [type]     DESCRIPTION
%    robot    [struct]   robot structure obtained from urdf2robot.m
%
% 4. INPUT    [type]     DESCRIPTION
%    robot    [struct]   robot structure obtained from urdf2robot.m, with mass appended in robot.totalMass
%
% 5. CHANGELOG
% 28/03/2023 - Matteo D'Ambrosio - Created function
%
% 6. DEPENDENCIES
% -None
%

%% Function code

robot.totalMass = robot.base_link.mass + sum([robot.links.mass]) ; 

end

