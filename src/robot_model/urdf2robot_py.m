function [nLinksJoints, nq, robotName, jointsMatrix, linksMatrix] = urdf2robot_py(filename)
% Returns robot data as plain numeric matrices for use with the Python engine.
%
% jointsMatrix: [24 x n] each column = [id; type; q_id; parent_link; child_link; axis(3x1); T(16x1)]
% linksMatrix:  [28 x n] each column = [id; parent_joint; T(16x1); mass; inertia(9x1)]

[robot, ~] = urdf2robot(filename) ;

nLinksJoints = robot.n_links_joints ;
nq           = robot.n_q ;
robotName    = robot.name ;
n            = nLinksJoints ;

jointsMatrix = zeros(24, n) ;
for i = 1:n
    j = robot.joints(i) ;
    jointsMatrix(:, i) = [j.id; j.type; j.q_id; j.parent_link; j.child_link; ...
                          j.axis(:); j.T(:)] ;
end

linksMatrix = zeros(28, n) ;
for i = 1:n
    l = robot.links(i) ;
    linksMatrix(:, i) = [l.id; l.parent_joint; l.T(:); l.mass; l.inertia(:)] ;
end

end