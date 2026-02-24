function [nLinksJoints, nq, robotName, jointsMatrix, linksMatrix, ...
          conBranch, conChild, conChildBase, baseMass, baseInertia] = urdf2robot_py(filename)
% Returns robot data as plain numeric matrices for use with the Python engine.
%
% jointsMatrix:  [24 x n]  [id; type; q_id; parent_link; child_link; axis(3x1); T(16x1)]
% linksMatrix:   [28 x n]  [id; parent_joint; T(16x1); mass; inertia(9x1)]
% conBranch:     [n  x n]  robot.con.branch connectivity matrix
% conChild:      [n  x n]  robot.con.child  connectivity matrix
% conChildBase:  [n  x 1]  robot.con.child_base connectivity vector
% baseMass:      scalar    robot.base_link.mass
% baseInertia:   [9  x 1]  robot.base_link.inertia(:) column-major

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

conBranch    = robot.con.branch ;
conChild     = robot.con.child ;
conChildBase = robot.con.child_base(:) ;
baseMass     = robot.base_link.mass ;
baseInertia  = robot.base_link.inertia(:) ;

end