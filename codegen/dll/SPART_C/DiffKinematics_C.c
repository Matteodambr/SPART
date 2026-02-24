/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: DiffKinematics_C.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

/* Include Files */
#include "DiffKinematics_C.h"
#include "SPART_C_data.h"
#include "SPART_C_emxutil.h"
#include "SPART_C_initialize.h"
#include "SPART_C_types.h"
#include "omp.h"
#include <emmintrin.h>

/* Function Definitions */
/*
 * Arguments    : const double R0[9]
 *                const double r0[3]
 *                const emxArray_real_T *rL
 *                const emxArray_real_T *e
 *                const emxArray_real_T *g
 *                double nLinksJoints
 *                const emxArray_real_T *robotConBranch
 *                const emxArray_struct0_T *robotJoints
 *                emxArray_cell_wrap_1 *Bij
 *                emxArray_cell_wrap_1 *Bi0
 *                double P0[36]
 *                emxArray_real_T *pm
 * Return Type  : void
 */
void DiffKinematics_C(const double R0[9], const double r0[3],
                      const emxArray_real_T *rL, const emxArray_real_T *e,
                      const emxArray_real_T *g, double nLinksJoints,
                      const emxArray_real_T *robotConBranch,
                      const emxArray_struct0_T *robotJoints,
                      emxArray_cell_wrap_1 *Bij, emxArray_cell_wrap_1 *Bi0,
                      double P0[36], emxArray_real_T *pm)
{
  static const signed char b_iv[18] = {1, 0, 0, 0, 1, 0, 0, 0, 1,
                                       0, 0, 0, 0, 0, 0, 0, 0, 0};
  static const signed char iv1[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      1, 0, 0, 0, 1, 0, 0, 0, 1};
  __m128d r;
  __m128d r1;
  cell_wrap_1 *Bij_data;
  const struct0_T *robotJoints_data;
  double x[3];
  const double *e_data;
  const double *g_data;
  const double *rL_data;
  const double *robotConBranch_data;
  double d;
  double d1;
  double d2;
  double d3;
  double d4;
  double d5;
  double *pm_data;
  int P0_tmp;
  int b_i;
  int c_i;
  int d_i;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int j;
  int loop_ub;
  if (!isInitialized_SPART_C) {
    SPART_C_initialize();
  }
  robotJoints_data = robotJoints->data;
  robotConBranch_data = robotConBranch->data;
  g_data = g->data;
  e_data = e->data;
  rL_data = rL->data;
  /*  Preallocate Bij as a cell array of size n x n, each element 6x6 */
  i = (int)nLinksJoints;
  P0_tmp = Bij->size[0] * Bij->size[1];
  Bij->size[0] = (int)nLinksJoints;
  Bij->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(Bij, P0_tmp);
  Bij_data = Bij->data;
  /*  Compute Bij */
  for (j = 0; j < i; j++) {
    for (b_i = 0; b_i < i; b_i++) {
      if (robotConBranch_data[b_i + robotConBranch->size[0] * j] == 1.0) {
        /*  Links are in the same branch */
        _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&rL_data[3 * j]),
                                        _mm_loadu_pd(&rL_data[3 * b_i])));
        x[2] = rL_data[3 * j + 2] - rL_data[3 * b_i + 2];
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
        for (i1 = 0; i1 < 6; i1++) {
          Bij_data[b_i + Bij->size[0] * j].f1[6 * i1] = b_iv[3 * i1];
          Bij_data[b_i + Bij->size[0] * j].f1[6 * i1 + 1] = b_iv[3 * i1 + 1];
          Bij_data[b_i + Bij->size[0] * j].f1[6 * i1 + 2] = b_iv[3 * i1 + 2];
        }
        Bij_data[b_i + Bij->size[0] * j].f1[3] = 0.0;
        Bij_data[b_i + Bij->size[0] * j].f1[9] = -x[2];
        Bij_data[b_i + Bij->size[0] * j].f1[15] = x[1];
        Bij_data[b_i + Bij->size[0] * j].f1[4] = x[2];
        Bij_data[b_i + Bij->size[0] * j].f1[10] = 0.0;
        Bij_data[b_i + Bij->size[0] * j].f1[16] = -x[0];
        Bij_data[b_i + Bij->size[0] * j].f1[5] = -x[1];
        Bij_data[b_i + Bij->size[0] * j].f1[11] = x[0];
        Bij_data[b_i + Bij->size[0] * j].f1[17] = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          P0_tmp = 6 * (i1 + 3);
          Bij_data[b_i + Bij->size[0] * j].f1[P0_tmp + 3] = iv[3 * i1];
          Bij_data[b_i + Bij->size[0] * j].f1[P0_tmp + 4] = iv[3 * i1 + 1];
          Bij_data[b_i + Bij->size[0] * j].f1[P0_tmp + 5] = iv[3 * i1 + 2];
        }
      } else {
        for (i1 = 0; i1 < 36; i1++) {
          Bij_data[b_i + Bij->size[0] * j].f1[i1] = 0.0;
        }
      }
    }
  }
  /*  Preallocate Bi0 as cell array n x 1 */
  /*  Compute Bi0 */
  loop_ub = (int)nLinksJoints;
  P0_tmp = Bi0->size[0];
  Bi0->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(Bi0, P0_tmp);
  Bij_data = Bi0->data;
  if ((int)nLinksJoints * 18 < 1600) {
    for (c_i = 0; c_i < i; c_i++) {
      _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&r0[0]),
                                      _mm_loadu_pd(&rL_data[3 * c_i])));
      x[2] = r0[2] - rL_data[3 * c_i + 2];
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
      for (i2 = 0; i2 < 6; i2++) {
        Bij_data[c_i].f1[6 * i2] = b_iv[3 * i2];
        Bij_data[c_i].f1[6 * i2 + 1] = b_iv[3 * i2 + 1];
        Bij_data[c_i].f1[6 * i2 + 2] = b_iv[3 * i2 + 2];
      }
      Bij_data[c_i].f1[3] = 0.0;
      Bij_data[c_i].f1[9] = -x[2];
      Bij_data[c_i].f1[15] = x[1];
      Bij_data[c_i].f1[4] = x[2];
      Bij_data[c_i].f1[10] = 0.0;
      Bij_data[c_i].f1[16] = -x[0];
      Bij_data[c_i].f1[5] = -x[1];
      Bij_data[c_i].f1[11] = x[0];
      Bij_data[c_i].f1[17] = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        P0_tmp = 6 * (i2 + 3);
        Bij_data[c_i].f1[P0_tmp + 3] = iv[3 * i2];
        Bij_data[c_i].f1[P0_tmp + 4] = iv[3 * i2 + 1];
        Bij_data[c_i].f1[P0_tmp + 5] = iv[3 * i2 + 2];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        r, r1, x, i2, i6)

    for (c_i = 0; c_i < loop_ub; c_i++) {
      r1 = _mm_loadu_pd(&r0[0]);
      r = _mm_loadu_pd(&rL_data[3 * c_i]);
      r = _mm_sub_pd(r1, r);
      _mm_storeu_pd(&x[0], r);
      x[2] = r0[2] - rL_data[3 * c_i + 2];
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
      for (i2 = 0; i2 < 6; i2++) {
        Bij_data[c_i].f1[6 * i2] = b_iv[3 * i2];
        Bij_data[c_i].f1[6 * i2 + 1] = b_iv[3 * i2 + 1];
        Bij_data[c_i].f1[6 * i2 + 2] = b_iv[3 * i2 + 2];
      }
      Bij_data[c_i].f1[3] = 0.0;
      Bij_data[c_i].f1[9] = -x[2];
      Bij_data[c_i].f1[15] = x[1];
      Bij_data[c_i].f1[4] = x[2];
      Bij_data[c_i].f1[10] = 0.0;
      Bij_data[c_i].f1[16] = -x[0];
      Bij_data[c_i].f1[5] = -x[1];
      Bij_data[c_i].f1[11] = x[0];
      Bij_data[c_i].f1[17] = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        i6 = 6 * (i2 + 3);
        Bij_data[c_i].f1[i6 + 3] = iv[3 * i2];
        Bij_data[c_i].f1[i6 + 4] = iv[3 * i2 + 1];
        Bij_data[c_i].f1[i6 + 5] = iv[3 * i2 + 2];
      }
    }
  }
  /*  Twist-propagation vectors */
  P0_tmp = pm->size[0] * pm->size[1];
  pm->size[0] = 6;
  pm->size[1] = i;
  emxEnsureCapacity_real_T(pm, P0_tmp);
  pm_data = pm->data;
  loop_ub = 6 * (int)nLinksJoints;
  for (i1 = 0; i1 < loop_ub; i1++) {
    pm_data[i1] = 0.0;
  }
  /*  Base-link twist-propagation matrix */
  for (i1 = 0; i1 < 3; i1++) {
    P0[6 * i1] = R0[3 * i1];
    P0_tmp = 6 * (i1 + 3);
    P0[P0_tmp] = 0.0;
    P0[6 * i1 + 1] = R0[3 * i1 + 1];
    P0[P0_tmp + 1] = 0.0;
    P0[6 * i1 + 2] = R0[3 * i1 + 2];
    P0[P0_tmp + 2] = 0.0;
  }
  for (i1 = 0; i1 < 6; i1++) {
    P0[6 * i1 + 3] = iv1[3 * i1];
    P0[6 * i1 + 4] = iv1[3 * i1 + 1];
    P0[6 * i1 + 5] = iv1[3 * i1 + 2];
  }
  if (loop_ub < 1600) {
    for (d_i = 0; d_i < i; d_i++) {
      if (robotJoints_data[d_i].type == 1.0) {
        /*  Revolute */
        pm_data[6 * d_i] = e_data[3 * d_i];
        P0_tmp = 3 * d_i + 1;
        pm_data[6 * d_i + 1] = e_data[P0_tmp];
        loop_ub = 3 * d_i + 2;
        pm_data[6 * d_i + 2] = e_data[loop_ub];
        d4 = e_data[P0_tmp];
        d5 = e_data[loop_ub];
        d3 = g_data[loop_ub];
        d2 = g_data[P0_tmp];
        pm_data[6 * d_i + 3] = d4 * d3 - d2 * d5;
        d1 = e_data[3 * d_i];
        d = g_data[3 * d_i];
        pm_data[6 * d_i + 4] = d * d5 - d1 * d3;
        pm_data[6 * d_i + 5] = d1 * d2 - d * d4;
      } else if (robotJoints_data[d_i].type == 2.0) {
        /*  Prismatic */
        pm_data[6 * d_i] = 0.0;
        pm_data[6 * d_i + 3] = e_data[3 * d_i];
        pm_data[6 * d_i + 1] = 0.0;
        pm_data[6 * d_i + 4] = e_data[3 * d_i + 1];
        pm_data[6 * d_i + 2] = 0.0;
        pm_data[6 * d_i + 5] = e_data[3 * d_i + 2];
      } else if (robotJoints_data[d_i].type == 0.0) {
        /*  Fixed */
        for (i3 = 0; i3 < 6; i3++) {
          pm_data[i3 + 6 * d_i] = 0.0;
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        d, d1, d2, d3, d5, d4, i3, i4, i5)

    for (d_i = 0; d_i < i; d_i++) {
      if (robotJoints_data[d_i].type == 1.0) {
        /*  Revolute */
        pm_data[6 * d_i] = e_data[3 * d_i];
        i4 = 3 * d_i + 1;
        pm_data[6 * d_i + 1] = e_data[i4];
        i5 = 3 * d_i + 2;
        pm_data[6 * d_i + 2] = e_data[i5];
        d4 = e_data[i4];
        d5 = e_data[i5];
        d3 = g_data[i5];
        d2 = g_data[i4];
        pm_data[6 * d_i + 3] = d4 * d3 - d2 * d5;
        d1 = e_data[3 * d_i];
        d = g_data[3 * d_i];
        pm_data[6 * d_i + 4] = d * d5 - d1 * d3;
        pm_data[6 * d_i + 5] = d1 * d2 - d * d4;
      } else if (robotJoints_data[d_i].type == 2.0) {
        /*  Prismatic */
        pm_data[6 * d_i] = 0.0;
        pm_data[6 * d_i + 3] = e_data[3 * d_i];
        pm_data[6 * d_i + 1] = 0.0;
        pm_data[6 * d_i + 4] = e_data[3 * d_i + 1];
        pm_data[6 * d_i + 2] = 0.0;
        pm_data[6 * d_i + 5] = e_data[3 * d_i + 2];
      } else if (robotJoints_data[d_i].type == 0.0) {
        /*  Fixed */
        for (i3 = 0; i3 < 6; i3++) {
          pm_data[i3 + 6 * d_i] = 0.0;
        }
      }
    }
  }
}

/*
 * File trailer for DiffKinematics_C.c
 *
 * [EOF]
 */
