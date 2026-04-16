/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Kinematics_C.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

/* Include Files */
#include "Kinematics_C.h"
#include "SPART_C_data.h"
#include "SPART_C_emxutil.h"
#include "SPART_C_initialize.h"
#include "SPART_C_types.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double R0[9]
 *                const double r0[3]
 *                const emxArray_real_T *qm
 *                double nLinksJoints
 *                const emxArray_struct0_T *robotJoints
 *                const emxArray_struct1_T *robotLinks
 *                emxArray_real_T *RJ
 *                emxArray_real_T *RL
 *                emxArray_real_T *rJ
 *                emxArray_real_T *rL
 *                emxArray_real_T *e
 *                emxArray_real_T *g
 * Return Type  : void
 */
void Kinematics_C(const double R0[9], const double r0[3],
                  const emxArray_real_T *qm, double nLinksJoints,
                  const emxArray_struct0_T *robotJoints,
                  const emxArray_struct1_T *robotLinks, emxArray_real_T *RJ,
                  emxArray_real_T *RL, emxArray_real_T *rJ, emxArray_real_T *rL,
                  emxArray_real_T *e, emxArray_real_T *g)
{
  static const signed char b_iv[16] = {1, 0, 0, 0, 0, 1, 0, 0,
                                       0, 0, 1, 0, 0, 0, 0, 1};
  __m128d r;
  __m128d r1;
  cell_wrap_0 *TJ_data;
  cell_wrap_0 *TL_data;
  emxArray_cell_wrap_0 *TJ;
  emxArray_cell_wrap_0 *TL;
  const struct0_T *robotJoints_data;
  const struct1_T *robotLinks_data;
  double T0[16];
  double T_qm[16];
  double b_TJ[16];
  double q[4];
  const double *qm_data;
  double b;
  double b_tmp;
  double *RJ_data;
  double *RL_data;
  double *e_data;
  double *g_data;
  double *rJ_data;
  double *rL_data;
  int T0_tmp;
  int b_i;
  int c_i;
  int d_i;
  int g_tmp;
  int i;
  int loop_ub;
  int unnamed_idx_1;
  if (!isInitialized_SPART_C) {
    SPART_C_initialize();
  }
  robotLinks_data = robotLinks->data;
  robotJoints_data = robotJoints->data;
  qm_data = qm->data;
  emxInit_cell_wrap_0(&TJ);
  T0_tmp = TJ->size[0] * TJ->size[1];
  TJ->size[0] = 1;
  i = (int)nLinksJoints;
  TJ->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_0(TJ, T0_tmp);
  TJ_data = TJ->data;
  emxInit_cell_wrap_0(&TL);
  T0_tmp = TL->size[0] * TL->size[1];
  TL->size[0] = 1;
  TL->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_0(TL, T0_tmp);
  TL_data = TL->data;
  for (b_i = 0; b_i < i; b_i++) {
    for (c_i = 0; c_i < 16; c_i++) {
      T0_tmp = b_iv[c_i];
      TJ_data[b_i].f1[c_i] = T0_tmp;
      TL_data[b_i].f1[c_i] = T0_tmp;
    }
  }
  T0_tmp = rJ->size[0] * rJ->size[1];
  rJ->size[0] = 3;
  rJ->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(rJ, T0_tmp);
  rJ_data = rJ->data;
  loop_ub = 3 * (int)nLinksJoints;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    rJ_data[b_i] = 0.0;
  }
  T0_tmp = rL->size[0] * rL->size[1];
  rL->size[0] = 3;
  rL->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(rL, T0_tmp);
  rL_data = rL->data;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    rL_data[b_i] = 0.0;
  }
  T0_tmp = e->size[0] * e->size[1];
  e->size[0] = 3;
  e->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(e, T0_tmp);
  e_data = e->data;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    e_data[b_i] = 0.0;
  }
  T0_tmp = g->size[0] * g->size[1];
  g->size[0] = 3;
  g->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(g, T0_tmp);
  g_data = g->data;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    g_data[b_i] = 0.0;
  }
  for (b_i = 0; b_i < 3; b_i++) {
    T0_tmp = b_i << 2;
    T0[T0_tmp] = R0[3 * b_i];
    T0[T0_tmp + 1] = R0[3 * b_i + 1];
    T0[T0_tmp + 2] = R0[3 * b_i + 2];
    T0[b_i + 12] = r0[b_i];
  }
  T0[3] = 0.0;
  T0[7] = 0.0;
  T0[11] = 0.0;
  T0[15] = 1.0;
  for (d_i = 0; d_i < i; d_i++) {
    __m128d r2;
    if (robotJoints_data[d_i].parent_link == 0.0) {
      b_tmp = robotJoints_data[d_i].id;
      for (b_i = 0; b_i < 4; b_i++) {
        T0_tmp = b_i << 2;
        TJ_data[(int)b_tmp - 1].f1[T0_tmp] = 0.0;
        TJ_data[(int)b_tmp - 1].f1[T0_tmp + 1] = 0.0;
        TJ_data[(int)b_tmp - 1].f1[T0_tmp + 2] = 0.0;
        TJ_data[(int)b_tmp - 1].f1[T0_tmp + 3] = 0.0;
        for (c_i = 0; c_i < 4; c_i++) {
          loop_ub = c_i << 2;
          r = _mm_loadu_pd(&T0[loop_ub]);
          r1 = _mm_loadu_pd(&TJ_data[(int)b_tmp - 1].f1[T0_tmp]);
          r2 = _mm_set1_pd(robotJoints_data[d_i].T[c_i + T0_tmp]);
          _mm_storeu_pd(&TJ_data[(int)b_tmp - 1].f1[T0_tmp],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&T0[loop_ub + 2]);
          r1 = _mm_loadu_pd(&TJ_data[(int)b_tmp - 1].f1[T0_tmp + 2]);
          _mm_storeu_pd(&TJ_data[(int)b_tmp - 1].f1[T0_tmp + 2],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        }
      }
    } else {
      b_tmp = robotJoints_data[d_i].id;
      for (b_i = 0; b_i < 4; b_i++) {
        T0_tmp = b_i << 2;
        TJ_data[(int)b_tmp - 1].f1[T0_tmp] = 0.0;
        TJ_data[(int)b_tmp - 1].f1[T0_tmp + 1] = 0.0;
        TJ_data[(int)b_tmp - 1].f1[T0_tmp + 2] = 0.0;
        TJ_data[(int)b_tmp - 1].f1[T0_tmp + 3] = 0.0;
        for (c_i = 0; c_i < 4; c_i++) {
          loop_ub = (int)robotJoints_data[d_i].parent_link - 1;
          g_tmp = c_i << 2;
          r = _mm_loadu_pd(&TL_data[loop_ub].f1[g_tmp]);
          r1 = _mm_loadu_pd(&TJ_data[(int)b_tmp - 1].f1[T0_tmp]);
          r2 = _mm_set1_pd(robotJoints_data[d_i].T[c_i + T0_tmp]);
          _mm_storeu_pd(&TJ_data[(int)b_tmp - 1].f1[T0_tmp],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&TL_data[loop_ub].f1[g_tmp + 2]);
          r1 = _mm_loadu_pd(&TJ_data[(int)b_tmp - 1].f1[T0_tmp + 2]);
          _mm_storeu_pd(&TJ_data[(int)b_tmp - 1].f1[T0_tmp + 2],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        }
      }
    }
    if (robotJoints_data[d_i].type == 1.0) {
      double T_qm_tmp;
      double b_T_qm_tmp;
      double c_T_qm_tmp;
      double d_T_qm_tmp;
      double e_T_qm_tmp;
      /*  Revolute */
      /* Provides the Direction Cosine Matrix (DCM) from a Euler axis
       * e=[e1,e2,e3] */
      /* and angle alpha. */
      /* Create quaternion */
      b_tmp = qm_data[(int)robotJoints_data[d_i].q_id - 1] / 2.0;
      b = sin(b_tmp);
      q[3] = cos(b_tmp);
      /* Convert quaternion to DCM */
      /* Provides the Direction Cosine Matrix (DCM) from a quaterionion (q) */
      /*  */
      /*  q = [q1;q2;q3;q4] -> With q4 being the scalar part of the quaternion.
       */
      _mm_storeu_pd(&q[0],
                    _mm_mul_pd(_mm_loadu_pd(&robotJoints_data[d_i].axis[0]),
                               _mm_set1_pd(b)));
      _mm_storeu_pd(&T_qm[12], _mm_set1_pd(0.0));
      q[2] = robotJoints_data[d_i].axis[2] * b;
      T_qm[14] = 0.0;
      T_qm_tmp = q[2] * q[2];
      b_T_qm_tmp = q[1] * q[1];
      T_qm[0] = 1.0 - 2.0 * (b_T_qm_tmp + T_qm_tmp);
      b_tmp = q[0] * q[1];
      b = q[2] * q[3];
      T_qm[1] = 2.0 * (b_tmp + b);
      c_T_qm_tmp = q[0] * q[2];
      d_T_qm_tmp = q[1] * q[3];
      T_qm[2] = 2.0 * (c_T_qm_tmp - d_T_qm_tmp);
      T_qm[4] = 2.0 * (b_tmp - b);
      e_T_qm_tmp = q[0] * q[0];
      T_qm[5] = 1.0 - 2.0 * (e_T_qm_tmp + T_qm_tmp);
      b_tmp = q[1] * q[2];
      b = q[0] * q[3];
      T_qm[6] = 2.0 * (b_tmp + b);
      T_qm[8] = 2.0 * (c_T_qm_tmp + d_T_qm_tmp);
      T_qm[9] = 2.0 * (b_tmp - b);
      T_qm[10] = 1.0 - 2.0 * (e_T_qm_tmp + b_T_qm_tmp);
      T_qm[3] = 0.0;
      T_qm[7] = 0.0;
      T_qm[11] = 0.0;
      T_qm[15] = 1.0;
    } else if (robotJoints_data[d_i].type == 2.0) {
      /*  Prismatic */
      for (b_i = 0; b_i < 3; b_i++) {
        T0_tmp = b_i << 2;
        T_qm[T0_tmp] = iv[3 * b_i];
        T_qm[T0_tmp + 1] = iv[3 * b_i + 1];
        T_qm[T0_tmp + 2] = iv[3 * b_i + 2];
        T_qm[b_i + 12] = robotJoints_data[d_i].axis[b_i] *
                         qm_data[(int)robotJoints_data[d_i].q_id - 1];
      }
      T_qm[3] = 0.0;
      T_qm[7] = 0.0;
      T_qm[11] = 0.0;
      T_qm[15] = 1.0;
    } else {
      for (b_i = 0; b_i < 16; b_i++) {
        T_qm[b_i] = b_iv[b_i];
      }
    }
    memset(&b_TJ[0], 0, sizeof(double) << 4);
    for (b_i = 0; b_i < 4; b_i++) {
      T0_tmp = b_i << 2;
      for (c_i = 0; c_i < 4; c_i++) {
        loop_ub = c_i + T0_tmp;
        g_tmp = (int)robotJoints_data[d_i].id - 1;
        unnamed_idx_1 = c_i << 2;
        r = _mm_loadu_pd(&TJ_data[g_tmp].f1[unnamed_idx_1]);
        r1 = _mm_loadu_pd(&b_TJ[T0_tmp]);
        r2 = _mm_set1_pd(T_qm[loop_ub]);
        _mm_storeu_pd(&b_TJ[T0_tmp], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        r = _mm_loadu_pd(&TJ_data[g_tmp].f1[unnamed_idx_1 + 2]);
        r1 = _mm_loadu_pd(&b_TJ[T0_tmp + 2]);
        _mm_storeu_pd(&b_TJ[T0_tmp + 2], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        TL_data[(int)robotLinks_data[(int)robotJoints_data[d_i].child_link - 1]
                    .id -
                1]
            .f1[loop_ub] = 0.0;
      }
    }
    T0_tmp = (int)robotJoints_data[d_i].child_link - 1;
    b_tmp = robotLinks_data[T0_tmp].id;
    for (b_i = 0; b_i < 4; b_i++) {
      loop_ub = b_i << 2;
      for (c_i = 0; c_i < 4; c_i++) {
        g_tmp = c_i << 2;
        r = _mm_loadu_pd(&b_TJ[g_tmp]);
        r1 = _mm_loadu_pd(&TL_data[(int)b_tmp - 1].f1[loop_ub]);
        r2 = _mm_set1_pd(robotLinks_data[T0_tmp].T[c_i + loop_ub]);
        _mm_storeu_pd(&TL_data[(int)b_tmp - 1].f1[loop_ub],
                      _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        r = _mm_loadu_pd(&b_TJ[g_tmp + 2]);
        r1 = _mm_loadu_pd(&TL_data[(int)b_tmp - 1].f1[loop_ub + 2]);
        _mm_storeu_pd(&TL_data[(int)b_tmp - 1].f1[loop_ub + 2],
                      _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      }
    }
  }
  /*  Preallocate 2D matrices for rotations (3 x 3*n) */
  b_tmp = 3.0 * nLinksJoints;
  T0_tmp = RJ->size[0] * RJ->size[1];
  RJ->size[0] = 3;
  RJ->size[1] = (int)b_tmp;
  emxEnsureCapacity_real_T(RJ, T0_tmp);
  RJ_data = RJ->data;
  loop_ub = 3 * (int)b_tmp;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    RJ_data[b_i] = 0.0;
  }
  T0_tmp = RL->size[0] * RL->size[1];
  RL->size[0] = 3;
  RL->size[1] = (int)b_tmp;
  emxEnsureCapacity_real_T(RL, T0_tmp);
  RL_data = RL->data;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    RL_data[b_i] = 0.0;
  }
  for (c_i = 0; c_i < i; c_i++) {
    double c_TJ[9];
    b_tmp = 3.0 * (((double)c_i + 1.0) - 1.0) + 1.0;
    b = 3.0 * ((double)c_i + 1.0);
    if (b_tmp > b) {
      g_tmp = 0;
      T0_tmp = 0;
    } else {
      g_tmp = (int)b_tmp - 1;
      T0_tmp = (int)b;
    }
    for (b_i = 0; b_i < 3; b_i++) {
      loop_ub = b_i << 2;
      c_TJ[3 * b_i] = TJ_data[c_i].f1[loop_ub];
      c_TJ[3 * b_i + 1] = TJ_data[c_i].f1[loop_ub + 1];
      c_TJ[3 * b_i + 2] = TJ_data[c_i].f1[loop_ub + 2];
    }
    unnamed_idx_1 = T0_tmp - g_tmp;
    for (b_i = 0; b_i < unnamed_idx_1; b_i++) {
      T0_tmp = g_tmp + b_i;
      RJ_data[3 * T0_tmp] = c_TJ[3 * b_i];
      RJ_data[3 * T0_tmp + 1] = c_TJ[3 * b_i + 1];
      RJ_data[3 * T0_tmp + 2] = c_TJ[3 * b_i + 2];
    }
    if (b_tmp > b) {
      g_tmp = 0;
      T0_tmp = 0;
    } else {
      g_tmp = (int)b_tmp - 1;
      T0_tmp = (int)b;
    }
    for (b_i = 0; b_i < 3; b_i++) {
      loop_ub = b_i << 2;
      c_TJ[3 * b_i] = TL_data[c_i].f1[loop_ub];
      c_TJ[3 * b_i + 1] = TL_data[c_i].f1[loop_ub + 1];
      c_TJ[3 * b_i + 2] = TL_data[c_i].f1[loop_ub + 2];
    }
    unnamed_idx_1 = T0_tmp - g_tmp;
    for (b_i = 0; b_i < unnamed_idx_1; b_i++) {
      T0_tmp = g_tmp + b_i;
      RL_data[3 * T0_tmp] = c_TJ[3 * b_i];
      RL_data[3 * T0_tmp + 1] = c_TJ[3 * b_i + 1];
      RL_data[3 * T0_tmp + 2] = c_TJ[3 * b_i + 2];
    }
    rJ_data[3 * c_i] = TJ_data[c_i].f1[12];
    rL_data[3 * c_i] = TL_data[c_i].f1[12];
    e_data[3 * c_i] = 0.0;
    T0_tmp = 3 * c_i + 1;
    rJ_data[T0_tmp] = TJ_data[c_i].f1[13];
    rL_data[T0_tmp] = TL_data[c_i].f1[13];
    e_data[T0_tmp] = 0.0;
    loop_ub = 3 * c_i + 2;
    rJ_data[loop_ub] = TJ_data[c_i].f1[14];
    rL_data[loop_ub] = TL_data[c_i].f1[14];
    e_data[loop_ub] = 0.0;
    r = _mm_loadu_pd(&TJ_data[c_i].f1[0]);
    r1 = _mm_loadu_pd(&e_data[3 * c_i]);
    _mm_storeu_pd(
        &e_data[3 * c_i],
        _mm_add_pd(r1,
                   _mm_mul_pd(r, _mm_set1_pd(robotJoints_data[c_i].axis[0]))));
    e_data[loop_ub] += robotJoints_data[c_i].axis[0] * TJ_data[c_i].f1[2];
    g_tmp = (int)robotLinks_data[c_i].parent_joint - 1;
    g_data[3 * c_i] = rL_data[3 * c_i] - rJ_data[3 * g_tmp];
    r = _mm_loadu_pd(&TJ_data[c_i].f1[4]);
    r1 = _mm_loadu_pd(&e_data[3 * c_i]);
    _mm_storeu_pd(
        &e_data[3 * c_i],
        _mm_add_pd(r1,
                   _mm_mul_pd(r, _mm_set1_pd(robotJoints_data[c_i].axis[1]))));
    e_data[loop_ub] += robotJoints_data[c_i].axis[1] * TJ_data[c_i].f1[6];
    g_data[T0_tmp] = rL_data[T0_tmp] - rJ_data[3 * g_tmp + 1];
    r = _mm_loadu_pd(&TJ_data[c_i].f1[8]);
    r1 = _mm_loadu_pd(&e_data[3 * c_i]);
    _mm_storeu_pd(
        &e_data[3 * c_i],
        _mm_add_pd(r1,
                   _mm_mul_pd(r, _mm_set1_pd(robotJoints_data[c_i].axis[2]))));
    e_data[loop_ub] += robotJoints_data[c_i].axis[2] * TJ_data[c_i].f1[10];
    g_data[loop_ub] = rL_data[loop_ub] - rJ_data[3 * g_tmp + 2];
  }
  emxFree_cell_wrap_0(&TL);
  emxFree_cell_wrap_0(&TJ);
}

/*
 * File trailer for Kinematics_C.c
 *
 * [EOF]
 */
