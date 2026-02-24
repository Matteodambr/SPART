import os
import numpy as np
from PySPART import SPART


# ---------------------------------------------------------------------------
# Inputs  (identical to example_robot_import_matlabCheck.m)
# ---------------------------------------------------------------------------
urdf = os.path.join('URDF_models', 'floating_7dof_manipulator.urdf')
spart = SPART(urdf)

R0    = np.array([[0.9986,  0.0,  0.0523],
                  [0.0,     1.0,  0.0   ],
                  [-0.0523, 0.0,  0.9986]])
r0    = np.array([3., 1., 3.])
qm    = np.deg2rad([30., 20., 30., 20., 30., 20., 30.])
u0    = np.array([0.1, 0.2, 0.3, 0.4, 0.5, 0.6])
um    = np.array([0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7])
u0dot = np.array([0.01, 0.02, 0.03, 0.04, 0.05, 0.06])
umdot = np.array([0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07])
wF0   = np.zeros(6)
wFm   = np.zeros((6, spart.robot.n_links_joints))

n  = spart.robot.n_links_joints
nq = spart.robot.n_q

def _sep(title):
    print()
    print('=' * 60)
    print(f'  {title}')
    print('=' * 60)

# ---------------------------------------------------------------------------
# Kinematics
# ---------------------------------------------------------------------------
_sep('Kinematics_C')
RJ, RL, rJ, rL, e, g = spart.kinematics(R0, r0, qm)
print(f'RJ  (3 x {3*n}):') ; print(RJ)
print(f'RL  (3 x {3*n}):') ; print(RL)
print(f'rJ  (3 x {n}):')   ; print(rJ)
print(f'rL  (3 x {n}):')   ; print(rL)
print(f'e   (3 x {n}):')   ; print(e)
print(f'g   (3 x {n}):')   ; print(g)

# ---------------------------------------------------------------------------
# Differential Kinematics
# ---------------------------------------------------------------------------
_sep('DiffKinematics_C')
Bij, Bi0, P0, pm = spart.diff_kinematics(R0, r0, rL, e, g)
print(f'Bij ({n} x {n} x 6 x 6) — Bij[0,0]:') ; print(Bij[0, 0])
print(f'Bi0 ({n} x 6 x 6)       — Bi0[0]  :') ; print(Bi0[0])
print(f'P0  (6 x 6):')                          ; print(P0)
print(f'pm  (6 x {n}):')                        ; print(pm)

# ---------------------------------------------------------------------------
# Velocities
# ---------------------------------------------------------------------------
_sep('Velocities_C')
t0, tL = spart.velocities(Bij, Bi0, P0, pm, u0, um)
print(f't0  (6,):')       ; print(t0)
print(f'tL  (6 x {n}):') ; print(tL)

# ---------------------------------------------------------------------------
# Inertia in Inertial Frame
# ---------------------------------------------------------------------------
_sep('I_I_C')
I0, Im = spart.i_i(R0, RL)
print(f'I0  (3 x 3):')            ; print(I0)
print(f'Im  ({n} x 3 x 3) — Im[0]:') ; print(Im[0])

# ---------------------------------------------------------------------------
# Accelerations
# ---------------------------------------------------------------------------
_sep('Accelerations_C')
t0dot, tLdot = spart.accelerations(t0, tL, P0, pm, Bi0, Bij, u0, um, u0dot, umdot)
print(f't0dot  (6,):')       ; print(t0dot)
print(f'tLdot  (6 x {n}):') ; print(tLdot)

# ---------------------------------------------------------------------------
# Inverse Dynamics
# ---------------------------------------------------------------------------
_sep('ID_C')
tau0, taum = spart.inverse_dynamics(wF0, wFm, t0, tL, t0dot, tLdot, P0, pm, I0, Im, Bij, Bi0)
print(f'tau0  (6,):')       ; print(tau0)
print(f'taum  ({nq},):')    ; print(taum)

# ---------------------------------------------------------------------------
# Forward Dynamics
# ---------------------------------------------------------------------------
_sep('FD_C')
u0dot_out, umdot_out = spart.forward_dynamics(
    tau0, taum, wF0, wFm, t0, tL, P0, pm, I0, Im, Bij, Bi0, u0, um)
print(f'u0dot  (6,):')      ; print(u0dot_out)
print(f'umdot  ({nq},):')   ; print(umdot_out)

# ---------------------------------------------------------------------------
# Space-Robot ODE
# ---------------------------------------------------------------------------
_sep('SPART_SPACEROBOT_ODE_C')
# Build state vector: y = [R0_flat(9,col-major); r0(3); u0(6); qm(nq); um(nq)]
R0_flat = R0.flatten(order='F')
y_ode   = np.concatenate([R0_flat, r0, u0, qm, um])
tau_ode = np.concatenate([[1, 2, 3, 4, 5, 6], np.ones(nq)])
dydt    = spart.space_robot_ode(0.0, y_ode, tau_ode)
print(f'y     ({len(y_ode)},): {y_ode}')
print(f'dydt  ({len(dydt)},): {dydt}')

# Benchmark
spart.benchmark(n_runs=5000)
