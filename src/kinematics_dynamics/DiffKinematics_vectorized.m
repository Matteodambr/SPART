function [Bij,Bi0,P0,pm] = DiffKinematics_vectorized(R0,r0,rL,e,g,robot)
% Computes the differential kinematics of the multibody system.
%
% [Bij,Bi0,P0,pm]=DiffKinematics(R0,r0,rL,e,g,robot)
% 
% :parameters:
%   * R0 -- Rotation matrix from the base-link CCS to the inertial CCS -- [3x3].
%   * r0 -- Position of the base-link center-of-mass with respect to the origin of the inertial frame, projected in the inertial CCS -- [3x1].
%   * rL -- Positions of the links, projected in the inertial CCS -- as a [3xn] matrix.
%   * e -- Joint rotation/sliding axes, projected in the inertial CCS -- as a [3xn] matrix.
%   * g -- Vector from the origin of the ith joint CCS to the origin of the ith link CCS, projected in the inertial CCS -- as a [3xn] matrix.
%   * robot -- Robot model (see :doc:`/Tutorial_Robot`).
%
% :return:
%   * Bij -- Twist-propagation matrix (for manipulator i>0 and j>0) -- as a [6x6xn×n] matrix.
%   * Bi0 -- Twist-propagation matrix (for i>0 and j=0) -- as a [6x6xn] matrix.
%   * P0 -- Base-link twist-propagation "vector" -- as a [6x6] matrix.
%   * pm -- Manipulator twist-propagation "vector" -- as a [6xn] matrix.
%
% See also: :func:`src.kinematics_dynamics.Kinematics` and :func:`src.kinematics_dynamics.Jacob`.

%% Number of links
n = robot.n_links_joints;

%% Compute Bij (6x6xn×n)
% Pre-allocate Bij
Bij = zeros(6,6,n,n,'like',R0);
I3 = eye(3,'like',R0);

% Create mask of links in same branch (n×n)
branchMask = robot.con.branch;  % assumed numeric 0/1 or logical

% Compute differences for all pairs (i,j): 
% rL_diff(:,i,j) = rL(:,j) - rL(:,i)
rL_exp_j = reshape(rL, [3,1,n]);  % broadcast dimension for j
rL_exp_i = reshape(rL, [3,n,1]);  % broadcast dimension for i
rL_diff = rL_exp_j - rL_exp_i;    % 3 x n x n; rL_diff(:,i,j)=rL(:,j)-rL(:,i)

% Compute skew-symmetric matrices for all differences.
% We'll build a 3x3xn×n array S such that S(:,:,i,j)=SkewSym(rL(:,j)-rL(:,i))
v1 = squeeze(rL_diff(1,:,:));  % n x n
v2 = squeeze(rL_diff(2,:,:));
v3 = squeeze(rL_diff(3,:,:));
% Pre-allocate S (3x3xn×n)
S = zeros(3,3,n,n,'like',rL);
% Set components
% Note: vX are [n×n] so we need to assign into each page.
S(1,2,:,:) = -v3;
S(1,3,:,:) =  v2;
S(2,1,:,:) =  v3;
S(2,3,:,:) = -v1;
S(3,1,:,:) = -v2;
S(3,2,:,:) =  v1;

% Now form the 6x6 block for each (i,j): 
% For indices (i,j) where branchMask(i,j)==1, 
% Bij(:,:,i,j) = [I3, zeros(3); S(:,:,i,j), I3]
mask = reshape(branchMask, [1,1,n,n]);  % broadcasting mask

% Create repeated identity blocks for all (i,j)
I3_block = repmat(I3, [1,1,n,n]);
% Set upper left block
Bij(1:3,1:3,:,:) = I3_block .* mask;
% Upper right is already zeros.
% Set lower left block (skew block)
Bij(4:6,1:3,:,:) = S .* mask;
% Set lower right block
Bij(4:6,4:6,:,:) = I3_block .* mask;

%% Compute Bi0 (6x6xn)
% For each link i, Bi0(:,:,i) = [I3, zeros(3); SkewSym(r0-rL(:,i)), I3]
d0 = r0 - rL;  % 3xn differences
% Compute skew-symmetric for each column: S0(:,:,i) = SkewSym(d0(:,i))
v1_0 = d0(1,:); v2_0 = d0(2,:); v3_0 = d0(3,:);
S0 = zeros(3,3,n,'like',d0);
S0(1,2,:) = -v3_0;
S0(1,3,:) =  v2_0;
S0(2,1,:) =  v3_0;
S0(2,3,:) = -v1_0;
S0(3,1,:) = -v2_0;
S0(3,2,:) =  v1_0;

Bi0 = zeros(6,6,n,'like',R0);
% Upper left block: identity for all i.
Bi0(1:3,1:3,:) = repmat(I3, [1,1,n]);
% Upper right block remains zero.
% Lower left block: skew matrices S0.
Bi0(4:6,1:3,:) = S0;
% Lower right block: identity
Bi0(4:6,4:6,:) = repmat(I3, [1,1,n]);

%% Compute twist-propagation "vector" pm (6xn) and base twist-propagation P0 (6x6)
pm = zeros(6,n,'like',R0);
% Base-link twist-propagation vector
P0 = [R0, zeros(3,3,'like',R0); zeros(3,3,'like',R0), eye(3,'like',R0)];

% For each joint i, set pm(:,i) according to joint type.
% Gather joint types into a row vector.
types = [robot.joints.type];  % 1xn
% Logical indices
isRev = (types==1);
isPris = (types==2);

% For revolute joints: pm = [e; cross(e, g)]
if any(isRev)
    crossEG = cross(e(:,isRev), g(:,isRev));  % 3xn_rev (cross works columnwise)
    pm(:,isRev) = [e(:,isRev); crossEG];
end
% For prismatic joints: pm = [zeros(3,1); e]
if any(isPris)
    pm(:,isPris) = [zeros(3,sum(isPris),'like',R0); e(:,isPris)];
end

% Fixed joints remain zeros.

end