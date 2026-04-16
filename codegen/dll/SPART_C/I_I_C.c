/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: I_I_C.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

/* Include Files */
#include "I_I_C.h"
#include "SPART_C_data.h"
#include "SPART_C_emxutil.h"
#include "SPART_C_initialize.h"
#include "SPART_C_types.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double R0[9]
 *                const emxArray_real_T *RL
 *                double nLinksJoints
 *                const double robotBaseInertia[9]
 *                const emxArray_struct1_T *robotLinks
 *                double I0[9]
 *                emxArray_cell_wrap_2 *Im
 * Return Type  : void
 */
void I_I_C(const double R0[9], const emxArray_real_T *RL, double nLinksJoints,
           const double robotBaseInertia[9],
           const emxArray_struct1_T *robotLinks, double I0[9],
           emxArray_cell_wrap_2 *Im)
{
  __m128d r;
  __m128d r1;
  cell_wrap_2 *Im_data;
  emxArray_real_T *b_RL;
  emxArray_real_T *c_RL;
  const struct1_T *robotLinks_data;
  double b_R0[9];
  const double *RL_data;
  double d;
  double *b_RL_data;
  double *c_RL_data;
  int R0_tmp;
  int b_i;
  int i;
  int i1;
  int i3;
  if (!isInitialized_SPART_C) {
    SPART_C_initialize();
  }
  robotLinks_data = robotLinks->data;
  RL_data = RL->data;
  memset(&b_R0[0], 0, 9U * sizeof(double));
  for (i = 0; i < 3; i++) {
    d = robotBaseInertia[3 * i];
    r = _mm_loadu_pd(&b_R0[3 * i]);
    _mm_storeu_pd(&b_R0[3 * i], _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&R0[0]),
                                                         _mm_set1_pd(d))));
    R0_tmp = 3 * i + 2;
    b_R0[R0_tmp] += R0[2] * d;
    d = robotBaseInertia[3 * i + 1];
    r = _mm_loadu_pd(&b_R0[3 * i]);
    _mm_storeu_pd(&b_R0[3 * i], _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&R0[3]),
                                                         _mm_set1_pd(d))));
    b_R0[R0_tmp] += R0[5] * d;
    d = robotBaseInertia[R0_tmp];
    r = _mm_loadu_pd(&b_R0[3 * i]);
    _mm_storeu_pd(&b_R0[3 * i], _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&R0[6]),
                                                         _mm_set1_pd(d))));
    b_R0[R0_tmp] += R0[8] * d;
  }
  memset(&I0[0], 0, 9U * sizeof(double));
  for (i = 0; i < 3; i++) {
    d = R0[i];
    r = _mm_loadu_pd(&b_R0[0]);
    r1 = _mm_loadu_pd(&I0[3 * i]);
    _mm_storeu_pd(&I0[3 * i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
    R0_tmp = 3 * i + 2;
    I0[R0_tmp] += b_R0[2] * d;
    d = R0[i + 3];
    r = _mm_loadu_pd(&b_R0[3]);
    r1 = _mm_loadu_pd(&I0[3 * i]);
    _mm_storeu_pd(&I0[3 * i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
    I0[R0_tmp] += b_R0[5] * d;
    d = R0[i + 6];
    r = _mm_loadu_pd(&b_R0[6]);
    r1 = _mm_loadu_pd(&I0[3 * i]);
    _mm_storeu_pd(&I0[3 * i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
    I0[R0_tmp] += b_R0[8] * d;
  }
  /*  Pre-allocate Im as a cell array of 3x3 matrices */
  R0_tmp = Im->size[0] * Im->size[1];
  Im->size[0] = 1;
  i1 = (int)nLinksJoints;
  Im->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_2(Im, R0_tmp);
  Im_data = Im->data;
  emxInit_real_T(&b_RL, 2);
  emxInit_real_T(&c_RL, 2);
  for (b_i = 0; b_i < i1; b_i++) {
    double d1;
    int b_R0_tmp;
    int i2;
    int loop_ub;
    /*  Extract 3x3 block from RL */
    d = 3.0 * (((double)b_i + 1.0) - 1.0) + 1.0;
    d1 = 3.0 * ((double)b_i + 1.0);
    if (d > d1) {
      i2 = 0;
      R0_tmp = 0;
    } else {
      i2 = (int)d - 1;
      R0_tmp = (int)d1;
    }
    /*  Compute inertia projection */
    b_R0_tmp = b_RL->size[0] * b_RL->size[1];
    b_RL->size[0] = 3;
    loop_ub = R0_tmp - i2;
    b_RL->size[1] = loop_ub;
    emxEnsureCapacity_real_T(b_RL, b_R0_tmp);
    b_RL_data = b_RL->data;
    for (i = 0; i < loop_ub; i++) {
      R0_tmp = i2 + i;
      b_RL_data[3 * i] = RL_data[3 * R0_tmp];
      b_RL_data[3 * i + 1] = RL_data[3 * R0_tmp + 1];
      b_RL_data[3 * i + 2] = RL_data[3 * R0_tmp + 2];
    }
    R0_tmp = c_RL->size[0] * c_RL->size[1];
    c_RL->size[0] = loop_ub;
    c_RL->size[1] = 3;
    emxEnsureCapacity_real_T(c_RL, R0_tmp);
    c_RL_data = c_RL->data;
    memset(&b_R0[0], 0, 9U * sizeof(double));
    for (i3 = 0; i3 < 3; i3++) {
      for (i = 0; i < loop_ub; i++) {
        c_RL_data[i + c_RL->size[0] * i3] = RL_data[i3 + 3 * (i2 + i)];
      }
      d = b_R0[3 * i3];
      R0_tmp = 3 * i3 + 1;
      b_R0_tmp = 3 * i3 + 2;
      for (i = 0; i < 3; i++) {
        int i4;
        i4 = i + 3 * i3;
        d1 = robotLinks_data[b_i].inertia[i4];
        d += b_RL_data[3 * i] * d1;
        b_R0[R0_tmp] += b_RL_data[3 * i + 1] * d1;
        b_R0[b_R0_tmp] += b_RL_data[3 * i + 2] * d1;
        Im_data[b_i].f1[i4] = 0.0;
      }
      b_R0[3 * i3] = d;
    }
    for (i = 0; i < 3; i++) {
      d = c_RL_data[3 * i];
      r = _mm_loadu_pd(&b_R0[0]);
      r1 = _mm_loadu_pd(&Im_data[b_i].f1[3 * i]);
      _mm_storeu_pd(&Im_data[b_i].f1[3 * i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
      R0_tmp = 3 * i + 2;
      Im_data[b_i].f1[R0_tmp] += b_R0[2] * d;
      d = c_RL_data[3 * i + 1];
      r = _mm_loadu_pd(&b_R0[3]);
      r1 = _mm_loadu_pd(&Im_data[b_i].f1[3 * i]);
      _mm_storeu_pd(&Im_data[b_i].f1[3 * i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
      Im_data[b_i].f1[R0_tmp] += b_R0[5] * d;
      d = c_RL_data[R0_tmp];
      r = _mm_loadu_pd(&b_R0[6]);
      r1 = _mm_loadu_pd(&Im_data[b_i].f1[3 * i]);
      _mm_storeu_pd(&Im_data[b_i].f1[3 * i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
      Im_data[b_i].f1[R0_tmp] += b_R0[8] * d;
    }
  }
  emxFree_real_T(&c_RL);
  emxFree_real_T(&b_RL);
}

/*
 * File trailer for I_I_C.c
 *
 * [EOF]
 */
