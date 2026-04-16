/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SPART_SPACEROBOT_ODE_C.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

/* Include Files */
#include "SPART_SPACEROBOT_ODE_C.h"
#include "Accelerations_C.h"
#include "DiffKinematics_C.h"
#include "FD_C.h"
#include "ID_C.h"
#include "I_I_C.h"
#include "Kinematics_C.h"
#include "SPART_C_data.h"
#include "SPART_C_emxutil.h"
#include "SPART_C_initialize.h"
#include "SPART_C_types.h"
#include "Velocities_C.h"
#include "mldivide.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Derivation:
 *  2ND order ODE system of 6+N_joints equations needs to be written as a
 *  system of 2*(6+N_joints) first-order ODEs, for Matlab integrators.
 *
 *  Define state variable transformation:
 *    y0a = q0 = [R0; r0]
 *    y0b = q0_dot = [w0_body, r0]
 *    yma = qm
 *    ymb = qm_dot
 *    y = [y0a; y0b; yma; ymb] = [R0; r0; w0_body; r0_dot; qm; qm_dot] --> For
 * integration
 *
 *    y_dot = [R0_dot; r0_dot; w0_body_dot; r0_ddot; qm_dot; qm_ddot] --> Final
 * equation that needs to be integrated where:
 *           - The spart Forward Dynamics is used to compute u0dot =
 * [w0_body_dot; r0_ddot] and umdot = qm_ddot
 *           - R0_dot comes from DCM kinematics integration, starting from the
 * input w0_body.
 *           - The remainder of the equations are directly from the inputted
 * state.
 *           - R0_dot is the only exception, since y_dot contains R0_dot and
 *           not w0_body! Otherwise, R0 cannot be computed throughout the
 *           integration.
 *
 * Arguments    : unsigned long t
 *                const emxArray_real_T *y
 *                const emxArray_real_T *tau
 *                double nLinksJoints
 *                const emxArray_struct0_T *robotJoints
 *                const emxArray_struct1_T *robotLinks
 *                const emxArray_real_T *robotConBranch
 *                const double robotBaseInertia[9]
 *                double nQ
 *                const struct2_T *robotBaseLink
 *                const emxArray_real_T *robotConChild
 *                const emxArray_real_T *robotConChildBase
 *                emxArray_real_T *dydt
 * Return Type  : void
 */
void SPART_SPACEROBOT_ODE_C(
    unsigned long t, const emxArray_real_T *y, const emxArray_real_T *tau,
    double nLinksJoints, const emxArray_struct0_T *robotJoints,
    const emxArray_struct1_T *robotLinks, const emxArray_real_T *robotConBranch,
    const double robotBaseInertia[9], double nQ, const struct2_T *robotBaseLink,
    const emxArray_real_T *robotConChild,
    const emxArray_real_T *robotConChildBase, emxArray_real_T *dydt)
{
  __m128d r;
  __m128d r1;
  __m128d r3;
  __m128d r4;
  cell_wrap_1 *Bi0_data;
  cell_wrap_1 *Bij_data;
  cell_wrap_1 *M_hat_data;
  cell_wrap_2 *Im_data;
  cell_wrap_3 *eta_data;
  cell_wrap_3 *psi_data;
  cell_wrap_3 *psi_hat_data;
  emxArray_cell_wrap_1 *Bi0;
  emxArray_cell_wrap_1 *Bij;
  emxArray_cell_wrap_1 *M_hat;
  emxArray_cell_wrap_2 *Im;
  emxArray_cell_wrap_3 *b_psi;
  emxArray_cell_wrap_3 *eta;
  emxArray_cell_wrap_3 *psi_hat;
  emxArray_real_T *RL;
  emxArray_real_T *a__1;
  emxArray_real_T *a__2;
  emxArray_real_T *b_pm;
  emxArray_real_T *e;
  emxArray_real_T *g;
  emxArray_real_T *phi_hat;
  emxArray_real_T *phi_tilde;
  emxArray_real_T *qm_dot;
  emxArray_real_T *r2;
  emxArray_real_T *rL;
  emxArray_real_T *tL;
  emxArray_real_T *tmdot;
  const struct0_T *robotJoints_data;
  const struct1_T *robotLinks_data;
  double M_hat0[36];
  double P0[36];
  double b_Bij[36];
  double b_M_hat[36];
  double b_M_hat0[36];
  double q0[12];
  double I0[9];
  double R0_I2body[9];
  double R0_body2I[9];
  double eta0[6];
  double phi_tilde0[6];
  double psi[6];
  double q0_dot[6];
  double tau0_0ddot[6];
  const double *robotConChildBase_data;
  const double *robotConChild_data;
  const double *tau_data;
  const double *y_data;
  double c_i;
  double pm;
  double *phi_hat_data;
  double *phi_tilde_data;
  double *pm_data;
  double *qm_dot_data;
  int R0_body2I_tmp;
  int b_i;
  int b_loop_ub;
  int c_loop_ub;
  int d_i;
  int d_loop_ub;
  int e_i;
  int e_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int j;
  int loop_ub;
  (void)t;
  if (!isInitialized_SPART_C) {
    SPART_C_initialize();
  }
  robotConChildBase_data = robotConChildBase->data;
  robotConChild_data = robotConChild->data;
  robotLinks_data = robotLinks->data;
  robotJoints_data = robotJoints->data;
  tau_data = tau->data;
  y_data = y->data;
  /*  SPART_SPACEROBOT_ODE computes the time derivative of the state vector for
   * a space robot system. The 6+N second order ordinary differential equations
   * are transformed into a 2*(6+N) system, to be compatible with Matlab's
   * integrators. */
  /*  */
  /*    dydt = SPART_SPACEROBOT_ODE(t, y, n_joints_manipulator, robot) */
  /*  */
  /*    Inputs: */
  /*        t                    - Current time (scalar) */
  /*        y                    - State vector [R0; r0; w0_body; r0_dot; qm;
   * qm_dot] */
  /*        n_joints_manipulator - Number of manipulator joints (scalar) */
  /*        robot                - Robot structure containing kinematic and
   * dynamic parameters */
  /*  */
  /*    Output: */
  /*        dydt                 - Time derivative of the state vector */
  /*  */
  /*    The function unpacks the state vector, processes kinematics and
   * dynamics, */
  /*    and computes the forward dynamics for the space robot. It is designed to
   */
  /*    be used with ODE solvers for simulating the motion of a free-floating */
  /*    space robot with a manipulator. */
  /*  */
  /*    Author: Matteo D'Ambrosio */
  /*    Date: 2026-02-24 */
  /*  Unpack variables */
  /*  For 6-dof base + 7-dof manipulator, y needs to have 32 elements */
  for (i = 0; i < 12; i++) {
    q0[i] = y_data[i];
  }
  /*  R0(3x3) + r0(3,1); total 12 elements to be reshaped */
  for (i = 0; i < 6; i++) {
    q0_dot[i] = y_data[i + 12];
  }
  if ((nQ + 19.0) - 1.0 < 19.0) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = 18;
    b_loop_ub = (int)((nQ + 19.0) - 1.0);
  }
  pm = (2.0 * nQ + 19.0) - 1.0;
  if (nQ + 19.0 > pm) {
    b_i = 0;
    i1 = 0;
  } else {
    b_i = (int)(nQ + 19.0) - 1;
    i1 = (int)pm;
  }
  emxInit_real_T(&qm_dot, 1);
  c_loop_ub = i1 - b_i;
  R0_body2I_tmp = qm_dot->size[0];
  qm_dot->size[0] = c_loop_ub;
  emxEnsureCapacity_real_T(qm_dot, R0_body2I_tmp);
  qm_dot_data = qm_dot->data;
  for (i = 0; i < c_loop_ub; i++) {
    qm_dot_data[i] = y_data[b_i + i];
  }
  /*  Further unpacking */
  memcpy(&R0_I2body[0], &q0[0], 9U * sizeof(double));
  /*  The derivative of these values is y0b_dot = u0_dot = q0_ddot =
   * [w0_body_dot; r0_ddot] */
  /*  Process inputs */
  memset(&R0_body2I[0], 0, 9U * sizeof(double));
  for (i = 0; i < 3; i++) {
    pm = R0_I2body[i];
    r = _mm_loadu_pd(&R0_I2body[0]);
    r1 = _mm_loadu_pd(&R0_body2I[3 * i]);
    _mm_storeu_pd(&R0_body2I[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(pm))));
    R0_body2I_tmp = 3 * i + 2;
    R0_body2I[R0_body2I_tmp] += R0_I2body[2] * pm;
    pm = R0_I2body[i + 3];
    r = _mm_loadu_pd(&R0_I2body[3]);
    r1 = _mm_loadu_pd(&R0_body2I[3 * i]);
    _mm_storeu_pd(&R0_body2I[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(pm))));
    R0_body2I[R0_body2I_tmp] += R0_I2body[5] * pm;
    pm = R0_I2body[i + 6];
    r = _mm_loadu_pd(&R0_I2body[6]);
    r1 = _mm_loadu_pd(&R0_body2I[3 * i]);
    _mm_storeu_pd(&R0_body2I[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(pm))));
    R0_body2I[R0_body2I_tmp] += R0_I2body[8] * pm;
  }
  r = _mm_loadu_pd(&R0_body2I[0]);
  r1 = _mm_set1_pd(0.5);
  _mm_storeu_pd(&R0_body2I[0], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&R0_body2I[2]);
  _mm_storeu_pd(&R0_body2I[2], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&R0_body2I[4]);
  _mm_storeu_pd(&R0_body2I[4], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&R0_body2I[6]);
  _mm_storeu_pd(&R0_body2I[6], _mm_mul_pd(r1, r));
  R0_body2I[8] *= 0.5;
  for (i = 0; i < 3; i++) {
    double d;
    pm = R0_body2I[i];
    c_i = R0_body2I[i + 3];
    d = R0_body2I[i + 6];
    for (d_i = 0; d_i < 3; d_i++) {
      R0_body2I_tmp = i + 3 * d_i;
      I0[R0_body2I_tmp] =
          1.5 * R0_I2body[R0_body2I_tmp] -
          ((pm * R0_I2body[3 * d_i] + c_i * R0_I2body[3 * d_i + 1]) +
           d * R0_I2body[3 * d_i + 2]);
    }
  }
  memcpy(&R0_I2body[0], &I0[0], 9U * sizeof(double));
  /*  Apply one step of orthonormalization to R0_I2body */
  for (i = 0; i < 3; i++) {
    R0_body2I[3 * i] = I0[i];
    R0_body2I[3 * i + 1] = I0[i + 3];
    R0_body2I[3 * i + 2] = I0[i + 6];
  }
  /*  Compute input to SPART library */
  /*  Control */
  if (tau->size[0] < 7) {
    i2 = 0;
    d_loop_ub = 0;
  } else {
    i2 = 6;
    d_loop_ub = tau->size[0];
  }
  /*  Kinematics */
  /*  Compute forward kinematics of multibody system */
  emxInit_real_T(&phi_hat, 1);
  b_loop_ub -= loop_ub;
  R0_body2I_tmp = phi_hat->size[0];
  phi_hat->size[0] = b_loop_ub;
  emxEnsureCapacity_real_T(phi_hat, R0_body2I_tmp);
  phi_hat_data = phi_hat->data;
  for (i = 0; i < b_loop_ub; i++) {
    phi_hat_data[i] = y_data[loop_ub + i];
  }
  emxInit_real_T(&a__1, 2);
  emxInit_real_T(&a__2, 2);
  emxInit_real_T(&RL, 2);
  emxInit_real_T(&rL, 2);
  emxInit_real_T(&e, 2);
  emxInit_real_T(&g, 2);
  Kinematics_C(R0_body2I, &q0[9], phi_hat, nLinksJoints, robotJoints,
               robotLinks, a__1, RL, a__2, rL, e, g);
  emxFree_real_T(&a__2);
  emxFree_real_T(&a__1);
  /*  Compute differential kinematics (twist propagation matrices and vectors)
   * of multibody system */
  emxInit_cell_wrap_1(&Bij, 2);
  emxInit_cell_wrap_1(&Bi0, 1);
  emxInit_real_T(&b_pm, 2);
  DiffKinematics_C(R0_body2I, &q0[9], rL, e, g, nLinksJoints, robotConBranch,
                   robotJoints, Bij, Bi0, P0, b_pm);
  pm_data = b_pm->data;
  Bi0_data = Bi0->data;
  Bij_data = Bij->data;
  emxFree_real_T(&g);
  emxFree_real_T(&e);
  emxFree_real_T(&rL);
  /*  Compute operational-space velocities (twists) of the multibody system */
  emxInit_real_T(&tL, 2);
  Velocities_C(Bij, Bi0, P0, b_pm, q0_dot, qm_dot, nLinksJoints, robotJoints,
               eta0, tL);
  /*  Project link inertias to the inertial CCS */
  emxInit_cell_wrap_2(&Im, 2);
  I_I_C(R0_body2I, RL, nLinksJoints, robotBaseInertia, robotLinks, I0, Im);
  Im_data = Im->data;
  emxFree_real_T(&RL);
  /*  Dynamics */
  /*  Forward dynamics */
  /*  u0 = q0_dot ; */
  /*  um = qm_dot ; */
  /*  DIFFERENCE BETWEEN wF and tau: */
  /*    - wF are wrenches, i.e. external forces applied to each single body, in
   */
  /*    terms of force and torque. These could represent things like gravity, */
  /*    etc. */
  /*    - tau are generalized forces, i.e. forces directly acting on each joint
   */
  /*    of the system. Think of this as control commands that you send to your
   */
  /*    base and to your manipulator joints. */
  /*    - You can convert between the two representations, but it is easier to
   */
  /*    apply forces separated in this way, especially if you have different */
  /*    actions acting in a combined way, without the need to convert any. */
  /* === Inverse Dynamics with zero accelerations ===% */
  emxInit_real_T(&tmdot, 2);
  b_Accelerations_C(eta0, tL, P0, b_pm, Bi0, Bij, q0_dot, qm_dot, nLinksJoints,
                    robotJoints, phi_tilde0, tmdot);
  for (i = 0; i < 6; i++) {
    psi[i] = 0.0;
  }
  emxInit_real_T(&r2, 2);
  R0_body2I_tmp = r2->size[0] * r2->size[1];
  r2->size[0] = 6;
  e_loop_ub = (int)nQ;
  r2->size[1] = (int)nQ;
  emxEnsureCapacity_real_T(r2, R0_body2I_tmp);
  phi_hat_data = r2->data;
  R0_body2I_tmp = 6 * (int)nQ;
  for (i = 0; i < R0_body2I_tmp; i++) {
    phi_hat_data[i] = 0.0;
  }
  b_ID_C(psi, r2, eta0, tL, phi_tilde0, tmdot, P0, b_pm, I0, Im, Bij, Bi0,
         nLinksJoints, nQ, robotBaseLink->mass, robotLinks, robotConChild,
         robotConChildBase, robotJoints, tau0_0ddot, qm_dot);
  emxFree_real_T(&r2);
  emxFree_real_T(&tmdot);
  emxFree_real_T(&tL);
  /* === Forward Dynamics ===% */
  loop_ub = d_loop_ub - i2;
  if (loop_ub == qm_dot->size[0]) {
    R0_body2I_tmp = qm_dot->size[0];
    qm_dot->size[0] = loop_ub;
    emxEnsureCapacity_real_T(qm_dot, R0_body2I_tmp);
    qm_dot_data = qm_dot->data;
    R0_body2I_tmp = (loop_ub / 2) << 1;
    b_loop_ub = R0_body2I_tmp - 2;
    for (i = 0; i <= b_loop_ub; i += 2) {
      r = _mm_loadu_pd(&qm_dot_data[i]);
      _mm_storeu_pd(&qm_dot_data[i],
                    _mm_sub_pd(_mm_loadu_pd(&tau_data[i2 + i]), r));
    }
    for (i = R0_body2I_tmp; i < loop_ub; i++) {
      qm_dot_data[i] = tau_data[i2 + i] - qm_dot_data[i];
    }
  } else {
    binary_expand_op(qm_dot, tau, i2, d_loop_ub - 1);
    qm_dot_data = qm_dot->data;
  }
  /*  Allocate and pre-initialize (required for code generation) */
  d_loop_ub = (int)nLinksJoints;
  emxInit_cell_wrap_1(&M_hat, 1);
  R0_body2I_tmp = M_hat->size[0];
  M_hat->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(M_hat, R0_body2I_tmp);
  M_hat_data = M_hat->data;
  emxInit_cell_wrap_3(&psi_hat);
  R0_body2I_tmp = psi_hat->size[0];
  psi_hat->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_3(psi_hat, R0_body2I_tmp);
  psi_hat_data = psi_hat->data;
  emxInit_cell_wrap_3(&b_psi);
  R0_body2I_tmp = b_psi->size[0];
  b_psi->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_3(b_psi, R0_body2I_tmp);
  psi_data = b_psi->data;
  for (d_i = 0; d_i < d_loop_ub; d_i++) {
    for (i = 0; i < 36; i++) {
      M_hat_data[d_i].f1[i] = 0.0;
    }
    for (i = 0; i < 6; i++) {
      psi_hat_data[d_i].f1[i] = 0.0;
      psi_data[d_i].f1[i] = 0.0;
    }
  }
  /* === Backward recursion for M_hat, psi_hat, psi ===% */
  loop_ub = (int)-((-1.0 - nLinksJoints) + 1.0);
  for (e_i = 0; e_i < loop_ub; e_i++) {
    c_i = nLinksJoints - (double)e_i;
    /*  cell: {3x3} */
    for (i = 0; i < 3; i++) {
      M_hat_data[(int)c_i - 1].f1[6 * i] = Im_data[(int)c_i - 1].f1[3 * i];
      b_loop_ub = 6 * (i + 3);
      M_hat_data[(int)c_i - 1].f1[b_loop_ub] = 0.0;
      M_hat_data[(int)c_i - 1].f1[6 * i + 3] = 0.0;
      pm = robotLinks_data[(int)c_i - 1].mass;
      M_hat_data[(int)c_i - 1].f1[b_loop_ub + 3] = pm * (double)iv[3 * i];
      R0_body2I_tmp = 3 * i + 1;
      M_hat_data[(int)c_i - 1].f1[6 * i + 1] =
          Im_data[(int)c_i - 1].f1[R0_body2I_tmp];
      M_hat_data[(int)c_i - 1].f1[b_loop_ub + 1] = 0.0;
      M_hat_data[(int)c_i - 1].f1[6 * i + 4] = 0.0;
      M_hat_data[(int)c_i - 1].f1[b_loop_ub + 4] =
          pm * (double)iv[R0_body2I_tmp];
      R0_body2I_tmp = 3 * i + 2;
      M_hat_data[(int)c_i - 1].f1[6 * i + 2] =
          Im_data[(int)c_i - 1].f1[R0_body2I_tmp];
      M_hat_data[(int)c_i - 1].f1[b_loop_ub + 2] = 0.0;
      M_hat_data[(int)c_i - 1].f1[6 * i + 5] = 0.0;
      M_hat_data[(int)c_i - 1].f1[b_loop_ub + 5] =
          pm * (double)iv[R0_body2I_tmp];
    }
    for (j = 0; j < d_loop_ub; j++) {
      if (robotConChild_data[j + robotConChild->size[0] * ((int)c_i - 1)] !=
          0.0) {
        r = _mm_set1_pd(0.0);
        for (i3 = 0; i3 < 6; i3++) {
          r1 = _mm_loadu_pd(&psi_hat_data[j].f1[0]);
          r3 = _mm_loadu_pd(&M_hat_data[j].f1[6 * i3]);
          r4 = _mm_set1_pd(psi_data[j].f1[i3]);
          _mm_storeu_pd(&b_M_hat[6 * i3],
                        _mm_sub_pd(r3, _mm_add_pd(r, _mm_mul_pd(r1, r4))));
          r1 = _mm_loadu_pd(&psi_hat_data[j].f1[2]);
          R0_body2I_tmp = 6 * i3 + 2;
          r3 = _mm_loadu_pd(&M_hat_data[j].f1[R0_body2I_tmp]);
          _mm_storeu_pd(&b_M_hat[R0_body2I_tmp],
                        _mm_sub_pd(r3, _mm_add_pd(r, _mm_mul_pd(r1, r4))));
          r1 = _mm_loadu_pd(&psi_hat_data[j].f1[4]);
          R0_body2I_tmp = 6 * i3 + 4;
          r3 = _mm_loadu_pd(&M_hat_data[j].f1[R0_body2I_tmp]);
          _mm_storeu_pd(&b_M_hat[R0_body2I_tmp],
                        _mm_sub_pd(r3, _mm_add_pd(r, _mm_mul_pd(r1, r4))));
          for (i = 0; i < 6; i++) {
            pm = 0.0;
            for (d_i = 0; d_i < 6; d_i++) {
              pm +=
                  Bij_data[j + Bij->size[0] * ((int)c_i - 1)].f1[d_i + 6 * i] *
                  b_M_hat[d_i + 6 * i3];
            }
            b_Bij[i + 6 * i3] = pm;
          }
        }
        for (d_i = 0; d_i < 6; d_i++) {
          for (i3 = 0; i3 < 6; i3++) {
            pm = 0.0;
            for (i = 0; i < 6; i++) {
              pm += b_Bij[d_i + 6 * i] *
                    Bij_data[j + Bij->size[0] * ((int)c_i - 1)].f1[i + 6 * i3];
            }
            R0_body2I_tmp = d_i + 6 * i3;
            M_hat_data[(int)c_i - 1].f1[R0_body2I_tmp] += pm;
          }
        }
      }
    }
    if (robotJoints_data[(int)c_i - 1].type == 0.0) {
      for (i = 0; i < 6; i++) {
        psi_hat_data[(int)c_i - 1].f1[i] = 0.0;
        psi_data[(int)c_i - 1].f1[i] = 0.0;
      }
    } else {
      for (i = 0; i < 6; i++) {
        psi_hat_data[(int)c_i - 1].f1[i] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        r = _mm_loadu_pd(&M_hat_data[(int)c_i - 1].f1[6 * i]);
        r1 = _mm_loadu_pd(&psi_hat_data[(int)c_i - 1].f1[0]);
        r3 = _mm_set1_pd(pm_data[i + 6 * ((int)c_i - 1)]);
        _mm_storeu_pd(&psi_hat_data[(int)c_i - 1].f1[0],
                      _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&M_hat_data[(int)c_i - 1].f1[6 * i + 2]);
        r1 = _mm_loadu_pd(&psi_hat_data[(int)c_i - 1].f1[2]);
        _mm_storeu_pd(&psi_hat_data[(int)c_i - 1].f1[2],
                      _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&M_hat_data[(int)c_i - 1].f1[6 * i + 4]);
        r1 = _mm_loadu_pd(&psi_hat_data[(int)c_i - 1].f1[4]);
        _mm_storeu_pd(&psi_hat_data[(int)c_i - 1].f1[4],
                      _mm_add_pd(r1, _mm_mul_pd(r, r3)));
      }
      pm = 0.0;
      for (i = 0; i < 6; i++) {
        pm +=
            pm_data[i + 6 * ((int)c_i - 1)] * psi_hat_data[(int)c_i - 1].f1[i];
      }
      r = _mm_loadu_pd(&psi_hat_data[(int)c_i - 1].f1[0]);
      r1 = _mm_set1_pd(pm);
      _mm_storeu_pd(&psi_data[(int)c_i - 1].f1[0], _mm_div_pd(r, r1));
      r = _mm_loadu_pd(&psi_hat_data[(int)c_i - 1].f1[2]);
      _mm_storeu_pd(&psi_data[(int)c_i - 1].f1[2], _mm_div_pd(r, r1));
      r = _mm_loadu_pd(&psi_hat_data[(int)c_i - 1].f1[4]);
      _mm_storeu_pd(&psi_data[(int)c_i - 1].f1[4], _mm_div_pd(r, r1));
    }
  }
  emxFree_cell_wrap_2(&Im);
  /* === Base link M_hat0 ===% */
  for (i = 0; i < 3; i++) {
    M_hat0[6 * i] = I0[3 * i];
    b_loop_ub = 6 * (i + 3);
    M_hat0[b_loop_ub] = 0.0;
    M_hat0[6 * i + 3] = 0.0;
    M_hat0[b_loop_ub + 3] = robotBaseLink->mass * (double)iv[3 * i];
    R0_body2I_tmp = 3 * i + 1;
    M_hat0[6 * i + 1] = I0[R0_body2I_tmp];
    M_hat0[b_loop_ub + 1] = 0.0;
    M_hat0[6 * i + 4] = 0.0;
    M_hat0[b_loop_ub + 4] = robotBaseLink->mass * (double)iv[R0_body2I_tmp];
    R0_body2I_tmp = 3 * i + 2;
    M_hat0[6 * i + 2] = I0[R0_body2I_tmp];
    M_hat0[b_loop_ub + 2] = 0.0;
    M_hat0[6 * i + 5] = 0.0;
    M_hat0[b_loop_ub + 5] = robotBaseLink->mass * (double)iv[R0_body2I_tmp];
  }
  for (j = 0; j < d_loop_ub; j++) {
    if (robotConChildBase_data[j] != 0.0) {
      r = _mm_set1_pd(0.0);
      for (i3 = 0; i3 < 6; i3++) {
        r1 = _mm_loadu_pd(&psi_hat_data[j].f1[0]);
        r3 = _mm_loadu_pd(&M_hat_data[j].f1[6 * i3]);
        r4 = _mm_set1_pd(psi_data[j].f1[i3]);
        _mm_storeu_pd(&b_M_hat[6 * i3],
                      _mm_sub_pd(r3, _mm_add_pd(r, _mm_mul_pd(r1, r4))));
        r1 = _mm_loadu_pd(&psi_hat_data[j].f1[2]);
        R0_body2I_tmp = 6 * i3 + 2;
        r3 = _mm_loadu_pd(&M_hat_data[j].f1[R0_body2I_tmp]);
        _mm_storeu_pd(&b_M_hat[R0_body2I_tmp],
                      _mm_sub_pd(r3, _mm_add_pd(r, _mm_mul_pd(r1, r4))));
        r1 = _mm_loadu_pd(&psi_hat_data[j].f1[4]);
        R0_body2I_tmp = 6 * i3 + 4;
        r3 = _mm_loadu_pd(&M_hat_data[j].f1[R0_body2I_tmp]);
        _mm_storeu_pd(&b_M_hat[R0_body2I_tmp],
                      _mm_sub_pd(r3, _mm_add_pd(r, _mm_mul_pd(r1, r4))));
        for (i = 0; i < 6; i++) {
          pm = 0.0;
          for (d_i = 0; d_i < 6; d_i++) {
            pm += Bi0_data[j].f1[d_i + 6 * i] * b_M_hat[d_i + 6 * i3];
          }
          b_Bij[i + 6 * i3] = pm;
        }
      }
      for (d_i = 0; d_i < 6; d_i++) {
        for (i3 = 0; i3 < 6; i3++) {
          pm = 0.0;
          for (i = 0; i < 6; i++) {
            pm += b_Bij[d_i + 6 * i] * Bi0_data[j].f1[i + 6 * i3];
          }
          R0_body2I_tmp = d_i + 6 * i3;
          M_hat0[R0_body2I_tmp] += pm;
        }
      }
    }
  }
  emxFree_cell_wrap_1(&M_hat);
  /* === eta, phi_hat, phi_tilde ===% */
  emxInit_cell_wrap_3(&eta);
  R0_body2I_tmp = eta->size[0];
  eta->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_3(eta, R0_body2I_tmp);
  eta_data = eta->data;
  for (i = 0; i < d_loop_ub; i++) {
    for (d_i = 0; d_i < 6; d_i++) {
      eta_data[i].f1[d_i] = 0.0;
    }
  }
  R0_body2I_tmp = phi_hat->size[0];
  phi_hat->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(phi_hat, R0_body2I_tmp);
  phi_hat_data = phi_hat->data;
  for (i = 0; i < d_loop_ub; i++) {
    phi_hat_data[i] = 0.0;
  }
  emxInit_real_T(&phi_tilde, 1);
  R0_body2I_tmp = phi_tilde->size[0];
  phi_tilde->size[0] = (int)nQ;
  emxEnsureCapacity_real_T(phi_tilde, R0_body2I_tmp);
  phi_tilde_data = phi_tilde->data;
  for (i = 0; i < e_loop_ub; i++) {
    phi_tilde_data[i] = 0.0;
  }
  for (j = 0; j < loop_ub; j++) {
    c_i = nLinksJoints - (double)j;
    for (i = 0; i < d_loop_ub; i++) {
      if (robotConChild_data[i + robotConChild->size[0] * ((int)c_i - 1)] !=
          0.0) {
        r = _mm_loadu_pd(&psi_data[i].f1[0]);
        r1 = _mm_loadu_pd(&eta_data[i].f1[0]);
        r3 = _mm_set1_pd(phi_hat_data[i]);
        _mm_storeu_pd(&psi[0], _mm_add_pd(_mm_mul_pd(r, r3), r1));
        r = _mm_loadu_pd(&psi_data[i].f1[2]);
        r1 = _mm_loadu_pd(&eta_data[i].f1[2]);
        _mm_storeu_pd(&psi[2], _mm_add_pd(_mm_mul_pd(r, r3), r1));
        r = _mm_loadu_pd(&psi_data[i].f1[4]);
        r1 = _mm_loadu_pd(&eta_data[i].f1[4]);
        _mm_storeu_pd(&psi[4], _mm_add_pd(_mm_mul_pd(r, r3), r1));
        for (d_i = 0; d_i < 6; d_i++) {
          pm = 0.0;
          for (i3 = 0; i3 < 6; i3++) {
            pm += Bij_data[i + Bij->size[0] * ((int)c_i - 1)].f1[i3 + 6 * d_i] *
                  psi[i3];
          }
          eta_data[(int)c_i - 1].f1[d_i] += pm;
        }
      }
    }
    pm = 0.0;
    for (i = 0; i < 6; i++) {
      pm += -pm_data[i + 6 * ((int)c_i - 1)] * eta_data[(int)c_i - 1].f1[i];
    }
    phi_hat_data[(int)c_i - 1] = pm;
    if (robotJoints_data[(int)c_i - 1].type != 0.0) {
      R0_body2I_tmp = (int)robotJoints_data[(int)c_i - 1].q_id - 1;
      phi_hat_data[(int)c_i - 1] += qm_dot_data[R0_body2I_tmp];
      pm = 0.0;
      for (i = 0; i < 6; i++) {
        pm +=
            pm_data[i + 6 * ((int)c_i - 1)] * psi_hat_data[(int)c_i - 1].f1[i];
      }
      phi_tilde_data[R0_body2I_tmp] = phi_hat_data[(int)c_i - 1] / pm;
    }
  }
  /* === Base-link phi_tilde0 ===% */
  for (i = 0; i < 6; i++) {
    eta0[i] = 0.0;
  }
  for (i = 0; i < d_loop_ub; i++) {
    if (robotConChildBase_data[i] != 0.0) {
      r = _mm_loadu_pd(&psi_data[i].f1[0]);
      r1 = _mm_loadu_pd(&eta_data[i].f1[0]);
      r3 = _mm_set1_pd(phi_hat_data[i]);
      _mm_storeu_pd(&psi[0], _mm_add_pd(_mm_mul_pd(r, r3), r1));
      r = _mm_loadu_pd(&psi_data[i].f1[2]);
      r1 = _mm_loadu_pd(&eta_data[i].f1[2]);
      _mm_storeu_pd(&psi[2], _mm_add_pd(_mm_mul_pd(r, r3), r1));
      r = _mm_loadu_pd(&psi_data[i].f1[4]);
      r1 = _mm_loadu_pd(&eta_data[i].f1[4]);
      _mm_storeu_pd(&psi[4], _mm_add_pd(_mm_mul_pd(r, r3), r1));
      for (d_i = 0; d_i < 6; d_i++) {
        pm = 0.0;
        for (i3 = 0; i3 < 6; i3++) {
          pm += Bi0_data[i].f1[i3 + 6 * d_i] * psi[i3];
        }
        eta0[d_i] += pm;
      }
    }
  }
  emxFree_real_T(&phi_hat);
  emxFree_cell_wrap_3(&eta);
  for (i = 0; i < 6; i++) {
    for (d_i = 0; d_i < 6; d_i++) {
      b_M_hat[d_i + 6 * i] = P0[i + 6 * d_i];
    }
  }
  memset(&b_M_hat0[0], 0, 36U * sizeof(double));
  memset(&b_Bij[0], 0, 36U * sizeof(double));
  for (d_i = 0; d_i < 6; d_i++) {
    pm = 0.0;
    R0_body2I_tmp = 6 * d_i + 2;
    b_loop_ub = 6 * d_i + 4;
    for (i = 0; i < 6; i++) {
      pm += b_M_hat[d_i + 6 * i] * eta0[i];
      r = _mm_loadu_pd(&M_hat0[6 * i]);
      r1 = _mm_loadu_pd(&b_M_hat0[6 * d_i]);
      r3 = _mm_set1_pd(P0[i + 6 * d_i]);
      _mm_storeu_pd(&b_M_hat0[6 * d_i], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
      r = _mm_loadu_pd(&M_hat0[6 * i + 2]);
      r1 = _mm_loadu_pd(&b_M_hat0[R0_body2I_tmp]);
      _mm_storeu_pd(&b_M_hat0[R0_body2I_tmp],
                    _mm_add_pd(r1, _mm_mul_pd(r, r3)));
      r = _mm_loadu_pd(&M_hat0[6 * i + 4]);
      r1 = _mm_loadu_pd(&b_M_hat0[b_loop_ub]);
      _mm_storeu_pd(&b_M_hat0[b_loop_ub], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    }
    phi_tilde0[d_i] = (tau_data[d_i] - tau0_0ddot[d_i]) - pm;
    R0_body2I_tmp = 6 * d_i + 2;
    b_loop_ub = 6 * d_i + 4;
    for (i = 0; i < 6; i++) {
      r = _mm_loadu_pd(&b_M_hat[6 * i]);
      r1 = _mm_loadu_pd(&b_Bij[6 * d_i]);
      r3 = _mm_set1_pd(b_M_hat0[i + 6 * d_i]);
      _mm_storeu_pd(&b_Bij[6 * d_i], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
      r = _mm_loadu_pd(&b_M_hat[6 * i + 2]);
      r1 = _mm_loadu_pd(&b_Bij[R0_body2I_tmp]);
      _mm_storeu_pd(&b_Bij[R0_body2I_tmp], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
      r = _mm_loadu_pd(&b_M_hat[6 * i + 4]);
      r1 = _mm_loadu_pd(&b_Bij[b_loop_ub]);
      _mm_storeu_pd(&b_Bij[b_loop_ub], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    }
  }
  mldivide(b_Bij, phi_tilde0);
  /* === Forward recursion for manipulator acceleration ===% */
  R0_body2I_tmp = psi_hat->size[0];
  psi_hat->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_3(psi_hat, R0_body2I_tmp);
  psi_hat_data = psi_hat->data;
  for (i = 0; i < d_loop_ub; i++) {
    for (d_i = 0; d_i < 6; d_i++) {
      psi_hat_data[i].f1[d_i] = 0.0;
    }
  }
  R0_body2I_tmp = qm_dot->size[0];
  qm_dot->size[0] = (int)nQ;
  emxEnsureCapacity_real_T(qm_dot, R0_body2I_tmp);
  qm_dot_data = qm_dot->data;
  for (i = 0; i < e_loop_ub; i++) {
    qm_dot_data[i] = 0.0;
  }
  for (d_i = 0; d_i < d_loop_ub; d_i++) {
    if (robotJoints_data[d_i].parent_link == 0.0) {
      memset(&psi[0], 0, 6U * sizeof(double));
      for (i = 0; i < 6; i++) {
        r = _mm_loadu_pd(&P0[6 * i]);
        r1 = _mm_loadu_pd(&psi[0]);
        r3 = _mm_set1_pd(phi_tilde0[i]);
        _mm_storeu_pd(&psi[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&P0[6 * i + 2]);
        r1 = _mm_loadu_pd(&psi[2]);
        _mm_storeu_pd(&psi[2], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&P0[6 * i + 4]);
        r1 = _mm_loadu_pd(&psi[4]);
        _mm_storeu_pd(&psi[4], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        psi_hat_data[d_i].f1[i] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        r = _mm_loadu_pd(&Bi0_data[d_i].f1[6 * i]);
        r1 = _mm_loadu_pd(&psi_hat_data[d_i].f1[0]);
        r3 = _mm_set1_pd(psi[i]);
        _mm_storeu_pd(&psi_hat_data[d_i].f1[0],
                      _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&Bi0_data[d_i].f1[6 * i + 2]);
        r1 = _mm_loadu_pd(&psi_hat_data[d_i].f1[2]);
        _mm_storeu_pd(&psi_hat_data[d_i].f1[2],
                      _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&Bi0_data[d_i].f1[6 * i + 4]);
        r1 = _mm_loadu_pd(&psi_hat_data[d_i].f1[4]);
        _mm_storeu_pd(&psi_hat_data[d_i].f1[4],
                      _mm_add_pd(r1, _mm_mul_pd(r, r3)));
      }
    } else {
      for (i = 0; i < 6; i++) {
        eta0[i] =
            psi_hat_data[(int)robotJoints_data[d_i].parent_link - 1].f1[i];
      }
      R0_body2I_tmp = (int)robotJoints_data[d_i].parent_link - 1;
      if (robotJoints_data[R0_body2I_tmp].type != 0.0) {
        r = _mm_loadu_pd(&pm_data[6 * R0_body2I_tmp]);
        r1 = _mm_loadu_pd(&psi_hat_data[R0_body2I_tmp].f1[0]);
        r3 = _mm_set1_pd(
            qm_dot_data[(int)robotJoints_data[R0_body2I_tmp].q_id - 1]);
        _mm_storeu_pd(&eta0[0], _mm_add_pd(_mm_mul_pd(r, r3), r1));
        r = _mm_loadu_pd(&pm_data[6 * R0_body2I_tmp + 2]);
        r1 = _mm_loadu_pd(&psi_hat_data[R0_body2I_tmp].f1[2]);
        _mm_storeu_pd(&eta0[2], _mm_add_pd(_mm_mul_pd(r, r3), r1));
        r = _mm_loadu_pd(&pm_data[6 * R0_body2I_tmp + 4]);
        r1 = _mm_loadu_pd(&psi_hat_data[R0_body2I_tmp].f1[4]);
        _mm_storeu_pd(&eta0[4], _mm_add_pd(_mm_mul_pd(r, r3), r1));
      }
      for (i = 0; i < 6; i++) {
        psi_hat_data[d_i].f1[i] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        r = _mm_loadu_pd(&Bij_data[d_i + Bij->size[0] * (d_i - 1)].f1[6 * i]);
        r1 = _mm_loadu_pd(&psi_hat_data[d_i].f1[0]);
        r3 = _mm_set1_pd(eta0[i]);
        _mm_storeu_pd(&psi_hat_data[d_i].f1[0],
                      _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(
            &Bij_data[d_i + Bij->size[0] * (d_i - 1)].f1[6 * i + 2]);
        r1 = _mm_loadu_pd(&psi_hat_data[d_i].f1[2]);
        _mm_storeu_pd(&psi_hat_data[d_i].f1[2],
                      _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(
            &Bij_data[d_i + Bij->size[0] * (d_i - 1)].f1[6 * i + 4]);
        r1 = _mm_loadu_pd(&psi_hat_data[d_i].f1[4]);
        _mm_storeu_pd(&psi_hat_data[d_i].f1[4],
                      _mm_add_pd(r1, _mm_mul_pd(r, r3)));
      }
    }
    if (robotJoints_data[d_i].type != 0.0) {
      pm = 0.0;
      for (i = 0; i < 6; i++) {
        pm += psi_data[d_i].f1[i] * psi_hat_data[d_i].f1[i];
      }
      R0_body2I_tmp = (int)robotJoints_data[d_i].q_id - 1;
      qm_dot_data[R0_body2I_tmp] = phi_tilde_data[R0_body2I_tmp] - pm;
    }
  }
  emxFree_real_T(&phi_tilde);
  emxFree_cell_wrap_3(&b_psi);
  emxFree_cell_wrap_3(&psi_hat);
  emxFree_real_T(&b_pm);
  emxFree_cell_wrap_1(&Bi0);
  emxFree_cell_wrap_1(&Bij);
  /*  DCM kinematics */
  /*  One step of orthonormalization applied above to R0_I2body, before any
   * computation. */
  /*  Compute DCM kinematics */
  /*  Computes the skew-symmetric matrix of a vector, which is also the */
  /*  left-hand-side matricial equivalent of the vector cross product */
  /*  */
  /*  [x_skew] = SkewSym(x) */
  /*  */
  /*  :parameters: */
  /* 	* x -- [3x1] column matrix (the vector). */
  /*  */
  /*  :return: */
  /* 	* x_skew -- [3x3] skew-symmetric matrix of x. */
  /*  Find dydt */
  I0[0] = -0.0;
  I0[3] = y_data[14];
  I0[6] = -y_data[13];
  I0[1] = -y_data[14];
  I0[4] = -0.0;
  I0[7] = y_data[12];
  I0[2] = y_data[13];
  I0[5] = -y_data[12];
  I0[8] = -0.0;
  memset(&R0_body2I[0], 0, 9U * sizeof(double));
  for (i = 0; i < 3; i++) {
    pm = R0_I2body[3 * i];
    r = _mm_loadu_pd(&I0[0]);
    r1 = _mm_loadu_pd(&R0_body2I[3 * i]);
    _mm_storeu_pd(&R0_body2I[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(pm))));
    R0_body2I_tmp = 3 * i + 2;
    R0_body2I[R0_body2I_tmp] += I0[2] * pm;
    pm = R0_I2body[3 * i + 1];
    r = _mm_loadu_pd(&I0[3]);
    r1 = _mm_loadu_pd(&R0_body2I[3 * i]);
    _mm_storeu_pd(&R0_body2I[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(pm))));
    R0_body2I[R0_body2I_tmp] += I0[5] * pm;
    pm = R0_I2body[R0_body2I_tmp];
    r = _mm_loadu_pd(&I0[6]);
    r1 = _mm_loadu_pd(&R0_body2I[3 * i]);
    _mm_storeu_pd(&R0_body2I[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(pm))));
    R0_body2I[R0_body2I_tmp] += -0.0 * pm;
  }
  R0_body2I_tmp = dydt->size[0];
  dydt->size[0] = (c_loop_ub + qm_dot->size[0]) + 18;
  emxEnsureCapacity_real_T(dydt, R0_body2I_tmp);
  phi_hat_data = dydt->data;
  for (i = 0; i < 9; i++) {
    phi_hat_data[i] = R0_body2I[i];
  }
  phi_hat_data[9] = q0_dot[3];
  phi_hat_data[10] = q0_dot[4];
  phi_hat_data[11] = q0_dot[5];
  for (i = 0; i < 6; i++) {
    phi_hat_data[i + 12] = phi_tilde0[i];
  }
  for (i = 0; i < c_loop_ub; i++) {
    phi_hat_data[i + 18] = y_data[b_i + i];
  }
  for (i = 0; i < e_loop_ub; i++) {
    phi_hat_data[((i + i1) - b_i) + 18] = qm_dot_data[i];
  }
  emxFree_real_T(&qm_dot);
}

/*
 * File trailer for SPART_SPACEROBOT_ODE_C.c
 *
 * [EOF]
 */
