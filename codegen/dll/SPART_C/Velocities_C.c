/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Velocities_C.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

/* Include Files */
#include "Velocities_C.h"
#include "SPART_C_data.h"
#include "SPART_C_emxutil.h"
#include "SPART_C_initialize.h"
#include "SPART_C_types.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_cell_wrap_1 *Bij
 *                const emxArray_cell_wrap_1 *Bi0
 *                const double P0[36]
 *                const emxArray_real_T *pm
 *                const double u0[6]
 *                const emxArray_real_T *um
 *                double nLinksJoints
 *                const emxArray_struct0_T *robotJoints
 *                double t0[6]
 *                emxArray_real_T *tL
 * Return Type  : void
 */
void Velocities_C(const emxArray_cell_wrap_1 *Bij,
                  const emxArray_cell_wrap_1 *Bi0, const double P0[36],
                  const emxArray_real_T *pm, const double u0[6],
                  const emxArray_real_T *um, double nLinksJoints,
                  const emxArray_struct0_T *robotJoints, double t0[6],
                  emxArray_real_T *tL)
{
  __m128d r;
  __m128d r1;
  const cell_wrap_1 *Bi0_data;
  const cell_wrap_1 *Bij_data;
  const struct0_T *robotJoints_data;
  double b_Bij[6];
  const double *pm_data;
  const double *um_data;
  double *tL_data;
  int b_i;
  int i;
  int i1;
  int loop_ub;
  if (!isInitialized_SPART_C) {
    SPART_C_initialize();
  }
  robotJoints_data = robotJoints->data;
  um_data = um->data;
  pm_data = pm->data;
  Bi0_data = Bi0->data;
  Bij_data = Bij->data;
  /*  Pre-allocate tL as 6 x n */
  loop_ub = tL->size[0] * tL->size[1];
  tL->size[0] = 6;
  i = (int)nLinksJoints;
  tL->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(tL, loop_ub);
  tL_data = tL->data;
  loop_ub = 6 * (int)nLinksJoints;
  for (i1 = 0; i1 < loop_ub; i1++) {
    tL_data[i1] = 0.0;
  }
  /*  Base-link twist */
  memset(&t0[0], 0, 6U * sizeof(double));
  for (i1 = 0; i1 < 6; i1++) {
    r = _mm_loadu_pd(&t0[0]);
    r1 = _mm_set1_pd(u0[i1]);
    _mm_storeu_pd(&t0[0],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i1]), r1)));
    r = _mm_loadu_pd(&t0[2]);
    _mm_storeu_pd(&t0[2],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i1 + 2]), r1)));
    r = _mm_loadu_pd(&t0[4]);
    _mm_storeu_pd(&t0[4],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i1 + 4]), r1)));
  }
  for (b_i = 0; b_i < i; b_i++) {
    if (robotJoints_data[b_i].parent_link == 0.0) {
      int i2;
      /*  First link */
      for (i1 = 0; i1 < 6; i1++) {
        tL_data[i1 + 6 * b_i] = 0.0;
      }
      loop_ub = 6 * b_i + 2;
      i2 = 6 * b_i + 4;
      for (i1 = 0; i1 < 6; i1++) {
        r = _mm_loadu_pd(&tL_data[6 * b_i]);
        r1 = _mm_set1_pd(t0[i1]);
        _mm_storeu_pd(
            &tL_data[6 * b_i],
            _mm_add_pd(
                r, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[b_i].f1[6 * i1]), r1)));
        r = _mm_loadu_pd(&tL_data[loop_ub]);
        _mm_storeu_pd(
            &tL_data[loop_ub],
            _mm_add_pd(
                r,
                _mm_mul_pd(_mm_loadu_pd(&Bi0_data[b_i].f1[6 * i1 + 2]), r1)));
        r = _mm_loadu_pd(&tL_data[i2]);
        _mm_storeu_pd(
            &tL_data[i2],
            _mm_add_pd(
                r,
                _mm_mul_pd(_mm_loadu_pd(&Bi0_data[b_i].f1[6 * i1 + 4]), r1)));
      }
    } else {
      /*  Subsequent links */
      memset(&b_Bij[0], 0, 6U * sizeof(double));
      for (i1 = 0; i1 < 6; i1++) {
        r = _mm_loadu_pd(&b_Bij[0]);
        r1 = _mm_set1_pd(tL_data[i1 + 6 * (b_i - 1)]);
        _mm_storeu_pd(
            &b_Bij[0],
            _mm_add_pd(
                r,
                _mm_mul_pd(
                    _mm_loadu_pd(
                        &Bij_data[b_i + Bij->size[0] * (b_i - 1)].f1[6 * i1]),
                    r1)));
        r = _mm_loadu_pd(&b_Bij[2]);
        _mm_storeu_pd(
            &b_Bij[2],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(&Bij_data[b_i + Bij->size[0] * (b_i - 1)]
                                         .f1[6 * i1 + 2]),
                       r1)));
        r = _mm_loadu_pd(&b_Bij[4]);
        _mm_storeu_pd(
            &b_Bij[4],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(&Bij_data[b_i + Bij->size[0] * (b_i - 1)]
                                         .f1[6 * i1 + 4]),
                       r1)));
      }
      for (i1 = 0; i1 < 6; i1++) {
        tL_data[i1 + 6 * b_i] = b_Bij[i1];
      }
    }
    /*  Add joint contribution if joint is not fixed */
    if (robotJoints_data[b_i].type != 0.0) {
      r = _mm_loadu_pd(&tL_data[6 * b_i]);
      r1 = _mm_set1_pd(um_data[(int)robotJoints_data[b_i].q_id - 1]);
      _mm_storeu_pd(
          &tL_data[6 * b_i],
          _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&pm_data[6 * b_i]), r1)));
      loop_ub = 6 * b_i + 2;
      r = _mm_loadu_pd(&tL_data[loop_ub]);
      _mm_storeu_pd(
          &tL_data[loop_ub],
          _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&pm_data[loop_ub]), r1)));
      loop_ub = 6 * b_i + 4;
      r = _mm_loadu_pd(&tL_data[loop_ub]);
      _mm_storeu_pd(
          &tL_data[loop_ub],
          _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&pm_data[loop_ub]), r1)));
    }
  }
}

/*
 * File trailer for Velocities_C.c
 *
 * [EOF]
 */
