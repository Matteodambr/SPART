/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Accelerations_C.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

/* Include Files */
#include "Accelerations_C.h"
#include "SPART_C_data.h"
#include "SPART_C_emxutil.h"
#include "SPART_C_initialize.h"
#include "SPART_C_types.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Computes operational-space accelerations (twist-rate).
 *
 *  All 3D matrices (Bi0, Bij, Omegam) are replaced with cell arrays for
 *  code-generation compatibility.
 *
 * Arguments    : const double t0[6]
 *                const emxArray_real_T *tL
 *                const double P0[36]
 *                const emxArray_real_T *pm
 *                const emxArray_cell_wrap_1 *Bi0
 *                const emxArray_cell_wrap_1 *Bij
 *                const double u0[6]
 *                const emxArray_real_T *um
 *                const double u0dot[6]
 *                const emxArray_real_T *umdot
 *                double nLinksJoints
 *                const emxArray_struct0_T *robotJoints
 *                double t0dot[6]
 *                emxArray_real_T *tLdot
 * Return Type  : void
 */
void Accelerations_C(const double t0[6], const emxArray_real_T *tL,
                     const double P0[36], const emxArray_real_T *pm,
                     const emxArray_cell_wrap_1 *Bi0,
                     const emxArray_cell_wrap_1 *Bij, const double u0[6],
                     const emxArray_real_T *um, const double u0dot[6],
                     const emxArray_real_T *umdot, double nLinksJoints,
                     const emxArray_struct0_T *robotJoints, double t0dot[6],
                     emxArray_real_T *tLdot)
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  __m128d r3;
  const cell_wrap_1 *Bi0_data;
  const cell_wrap_1 *Bij_data;
  cell_wrap_1 *Omegam_data;
  emxArray_cell_wrap_1 *Omegam;
  const struct0_T *robotJoints_data;
  double dv[36];
  double dv1[36];
  double skew_omega[9];
  double b_P0[6];
  double dv2[6];
  double x[3];
  const double *pm_data;
  const double *tL_data;
  const double *um_data;
  const double *umdot_data;
  double d;
  double *tLdot_data;
  int b_i;
  int c_i;
  int i;
  int i1;
  int loop_ub;
  if (!isInitialized_SPART_C) {
    SPART_C_initialize();
  }
  robotJoints_data = robotJoints->data;
  umdot_data = umdot->data;
  um_data = um->data;
  Bij_data = Bij->data;
  Bi0_data = Bi0->data;
  pm_data = pm->data;
  tL_data = tL->data;
  /* --- Omega matrices ---% */
  /*  Base-link */
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
  /*  Pre-allocate cell array for Omegam */
  emxInit_cell_wrap_1(&Omegam, 2);
  loop_ub = Omegam->size[0] * Omegam->size[1];
  Omegam->size[0] = 1;
  i = (int)nLinksJoints;
  Omegam->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(Omegam, loop_ub);
  Omegam_data = Omegam->data;
  /*  Compute Omega for manipulator links */
  if ((int)nLinksJoints - 1 >= 0) {
    skew_omega[0] = 0.0;
    skew_omega[4] = 0.0;
    skew_omega[8] = 0.0;
  }
  for (b_i = 0; b_i < i; b_i++) {
    double d1;
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
    d = tL_data[6 * b_i + 2];
    skew_omega[3] = -d;
    d1 = tL_data[6 * b_i + 1];
    skew_omega[6] = d1;
    skew_omega[1] = d;
    d = tL_data[6 * b_i];
    skew_omega[7] = -d;
    skew_omega[2] = -d1;
    skew_omega[5] = d;
    for (c_i = 0; c_i < 3; c_i++) {
      d = skew_omega[3 * c_i];
      Omegam_data[b_i].f1[6 * c_i] = d;
      loop_ub = 6 * (c_i + 3);
      Omegam_data[b_i].f1[loop_ub] = 0.0;
      Omegam_data[b_i].f1[6 * c_i + 3] = 0.0;
      Omegam_data[b_i].f1[loop_ub + 3] = d;
      d = skew_omega[3 * c_i + 1];
      Omegam_data[b_i].f1[6 * c_i + 1] = d;
      Omegam_data[b_i].f1[loop_ub + 1] = 0.0;
      Omegam_data[b_i].f1[6 * c_i + 4] = 0.0;
      Omegam_data[b_i].f1[loop_ub + 4] = d;
      d = skew_omega[3 * c_i + 2];
      Omegam_data[b_i].f1[6 * c_i + 2] = d;
      Omegam_data[b_i].f1[loop_ub + 2] = 0.0;
      Omegam_data[b_i].f1[6 * c_i + 5] = 0.0;
      Omegam_data[b_i].f1[loop_ub + 5] = d;
    }
  }
  /* --- Twist Rate ---% */
  /*  Base-link acceleration */
  dv[0] = 0.0;
  dv[6] = -t0[2];
  dv[12] = t0[1];
  dv[1] = t0[2];
  dv[7] = 0.0;
  dv[13] = -t0[0];
  dv[2] = -t0[1];
  dv[8] = t0[0];
  dv[14] = 0.0;
  for (b_i = 0; b_i < 3; b_i++) {
    loop_ub = 6 * (b_i + 3);
    dv[loop_ub] = 0.0;
    dv[loop_ub + 1] = 0.0;
    dv[loop_ub + 2] = 0.0;
  }
  for (b_i = 0; b_i < 6; b_i++) {
    dv[6 * b_i + 3] = 0.0;
    dv[6 * b_i + 4] = 0.0;
    dv[6 * b_i + 5] = 0.0;
  }
  memset(&dv1[0], 0, 36U * sizeof(double));
  memset(&t0dot[0], 0, 6U * sizeof(double));
  memset(&b_P0[0], 0, 6U * sizeof(double));
  for (c_i = 0; c_i < 6; c_i++) {
    loop_ub = 6 * c_i + 2;
    i1 = 6 * c_i + 4;
    for (b_i = 0; b_i < 6; b_i++) {
      r = _mm_loadu_pd(&dv[6 * b_i]);
      r1 = _mm_loadu_pd(&dv1[6 * c_i]);
      r2 = _mm_set1_pd(P0[b_i + 6 * c_i]);
      _mm_storeu_pd(&dv1[6 * c_i], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&dv[6 * b_i + 2]);
      r1 = _mm_loadu_pd(&dv1[loop_ub]);
      _mm_storeu_pd(&dv1[loop_ub], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&dv[6 * b_i + 4]);
      r1 = _mm_loadu_pd(&dv1[i1]);
      _mm_storeu_pd(&dv1[i1], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    }
    r = _mm_loadu_pd(&dv1[6 * c_i]);
    r1 = _mm_loadu_pd(&t0dot[0]);
    r2 = _mm_set1_pd(u0[c_i]);
    _mm_storeu_pd(&t0dot[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&b_P0[0]);
    r3 = _mm_set1_pd(u0dot[c_i]);
    _mm_storeu_pd(&b_P0[0],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * c_i]), r3)));
    loop_ub = 6 * c_i + 2;
    r = _mm_loadu_pd(&dv1[loop_ub]);
    r1 = _mm_loadu_pd(&t0dot[2]);
    _mm_storeu_pd(&t0dot[2], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&b_P0[2]);
    _mm_storeu_pd(&b_P0[2],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[loop_ub]), r3)));
    loop_ub = 6 * c_i + 4;
    r = _mm_loadu_pd(&dv1[loop_ub]);
    r1 = _mm_loadu_pd(&t0dot[4]);
    _mm_storeu_pd(&t0dot[4], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&b_P0[4]);
    _mm_storeu_pd(&b_P0[4],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[loop_ub]), r3)));
  }
  r = _mm_loadu_pd(&t0dot[0]);
  r1 = _mm_loadu_pd(&b_P0[0]);
  _mm_storeu_pd(&t0dot[0], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&t0dot[2]);
  r1 = _mm_loadu_pd(&b_P0[2]);
  _mm_storeu_pd(&t0dot[2], _mm_add_pd(r, r1));
  r = _mm_loadu_pd(&t0dot[4]);
  r1 = _mm_loadu_pd(&b_P0[4]);
  _mm_storeu_pd(&t0dot[4], _mm_add_pd(r, r1));
  /*  Pre-allocate for manipulator */
  loop_ub = tLdot->size[0] * tLdot->size[1];
  tLdot->size[0] = 6;
  tLdot->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(tLdot, loop_ub);
  tLdot_data = tLdot->data;
  loop_ub = 6 * (int)nLinksJoints;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    tLdot_data[b_i] = 0.0;
  }
  /*  Forward recursion */
  for (c_i = 0; c_i < i; c_i++) {
    d = robotJoints_data[c_i].parent_link;
    if (robotJoints_data[c_i].parent_link == 0.0) {
      /*  First link (connected to base) */
      _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&t0[3]),
                                      _mm_loadu_pd(&tL_data[6 * c_i + 3])));
      x[2] = t0[5] - tL_data[6 * c_i + 5];
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
      for (b_i = 0; b_i < 6; b_i++) {
        dv[6 * b_i] = 0.0;
        dv[6 * b_i + 1] = 0.0;
        dv[6 * b_i + 2] = 0.0;
      }
      dv[3] = 0.0;
      dv[9] = -x[2];
      dv[15] = x[1];
      dv[4] = x[2];
      dv[10] = 0.0;
      dv[16] = -x[0];
      dv[5] = -x[1];
      dv[11] = x[0];
      dv[17] = 0.0;
      for (b_i = 0; b_i < 3; b_i++) {
        loop_ub = 6 * (b_i + 3);
        dv[loop_ub + 3] = 0.0;
        dv[loop_ub + 4] = 0.0;
        dv[loop_ub + 5] = 0.0;
      }
      memset(&b_P0[0], 0, 6U * sizeof(double));
      memset(&dv2[0], 0, 6U * sizeof(double));
      for (b_i = 0; b_i < 6; b_i++) {
        r = _mm_loadu_pd(&b_P0[0]);
        r2 = _mm_set1_pd(t0dot[b_i]);
        _mm_storeu_pd(
            &b_P0[0],
            _mm_add_pd(
                r, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[6 * b_i]), r2)));
        r = _mm_loadu_pd(&dv[6 * b_i]);
        r1 = _mm_loadu_pd(&dv2[0]);
        r3 = _mm_set1_pd(t0[b_i]);
        _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&b_P0[2]);
        loop_ub = 6 * b_i + 2;
        _mm_storeu_pd(
            &b_P0[2],
            _mm_add_pd(
                r, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[loop_ub]), r2)));
        r = _mm_loadu_pd(&dv[loop_ub]);
        r1 = _mm_loadu_pd(&dv2[2]);
        _mm_storeu_pd(&dv2[2], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&b_P0[4]);
        loop_ub = 6 * b_i + 4;
        _mm_storeu_pd(
            &b_P0[4],
            _mm_add_pd(
                r, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[loop_ub]), r2)));
        r = _mm_loadu_pd(&dv[loop_ub]);
        r1 = _mm_loadu_pd(&dv2[4]);
        _mm_storeu_pd(&dv2[4], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
      }
      r = _mm_loadu_pd(&b_P0[0]);
      r1 = _mm_loadu_pd(&dv2[0]);
      _mm_storeu_pd(&tLdot_data[6 * c_i], _mm_add_pd(r, r1));
      r = _mm_loadu_pd(&b_P0[2]);
      r1 = _mm_loadu_pd(&dv2[2]);
      _mm_storeu_pd(&tLdot_data[6 * c_i + 2], _mm_add_pd(r, r1));
      r = _mm_loadu_pd(&b_P0[4]);
      r1 = _mm_loadu_pd(&dv2[4]);
      _mm_storeu_pd(&tLdot_data[6 * c_i + 4], _mm_add_pd(r, r1));
    } else {
      i1 = (int)robotJoints_data[c_i].parent_link - 1;
      loop_ub = 6 * ((int)d - 1);
      _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&tL_data[loop_ub + 3]),
                                      _mm_loadu_pd(&tL_data[6 * c_i + 3])));
      x[2] = tL_data[loop_ub + 5] - tL_data[6 * c_i + 5];
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
      for (b_i = 0; b_i < 6; b_i++) {
        dv[6 * b_i] = 0.0;
        dv[6 * b_i + 1] = 0.0;
        dv[6 * b_i + 2] = 0.0;
      }
      dv[3] = 0.0;
      dv[9] = -x[2];
      dv[15] = x[1];
      dv[4] = x[2];
      dv[10] = 0.0;
      dv[16] = -x[0];
      dv[5] = -x[1];
      dv[11] = x[0];
      dv[17] = 0.0;
      for (b_i = 0; b_i < 3; b_i++) {
        loop_ub = 6 * (b_i + 3);
        dv[loop_ub + 3] = 0.0;
        dv[loop_ub + 4] = 0.0;
        dv[loop_ub + 5] = 0.0;
      }
      memset(&b_P0[0], 0, 6U * sizeof(double));
      memset(&dv2[0], 0, 6U * sizeof(double));
      for (b_i = 0; b_i < 6; b_i++) {
        r = _mm_loadu_pd(&b_P0[0]);
        loop_ub = b_i + 6 * i1;
        r2 = _mm_set1_pd(tLdot_data[loop_ub]);
        _mm_storeu_pd(
            &b_P0[0],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(&Bij_data[c_i + Bij->size[0] * ((int)d - 1)]
                                         .f1[6 * b_i]),
                       r2)));
        r = _mm_loadu_pd(&dv[6 * b_i]);
        r1 = _mm_loadu_pd(&dv2[0]);
        r3 = _mm_set1_pd(tL_data[loop_ub]);
        _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&b_P0[2]);
        loop_ub = 6 * b_i + 2;
        _mm_storeu_pd(
            &b_P0[2],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(&Bij_data[c_i + Bij->size[0] * ((int)d - 1)]
                                         .f1[loop_ub]),
                       r2)));
        r = _mm_loadu_pd(&dv[loop_ub]);
        r1 = _mm_loadu_pd(&dv2[2]);
        _mm_storeu_pd(&dv2[2], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
        r = _mm_loadu_pd(&b_P0[4]);
        loop_ub = 6 * b_i + 4;
        _mm_storeu_pd(
            &b_P0[4],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(&Bij_data[c_i + Bij->size[0] * ((int)d - 1)]
                                         .f1[loop_ub]),
                       r2)));
        r = _mm_loadu_pd(&dv[loop_ub]);
        r1 = _mm_loadu_pd(&dv2[4]);
        _mm_storeu_pd(&dv2[4], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
      }
      r = _mm_loadu_pd(&b_P0[0]);
      r1 = _mm_loadu_pd(&dv2[0]);
      _mm_storeu_pd(&tLdot_data[6 * c_i], _mm_add_pd(r, r1));
      r = _mm_loadu_pd(&b_P0[2]);
      r1 = _mm_loadu_pd(&dv2[2]);
      _mm_storeu_pd(&tLdot_data[6 * c_i + 2], _mm_add_pd(r, r1));
      r = _mm_loadu_pd(&b_P0[4]);
      r1 = _mm_loadu_pd(&dv2[4]);
      _mm_storeu_pd(&tLdot_data[6 * c_i + 4], _mm_add_pd(r, r1));
    }
    /*  Add joint contribution */
    if (robotJoints_data[c_i].type != 0.0) {
      memset(&b_P0[0], 0, 6U * sizeof(double));
      for (b_i = 0; b_i < 6; b_i++) {
        r = _mm_loadu_pd(&Omegam_data[c_i].f1[6 * b_i]);
        r1 = _mm_loadu_pd(&b_P0[0]);
        r2 = _mm_set1_pd(pm_data[b_i + 6 * c_i]);
        _mm_storeu_pd(&b_P0[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        r = _mm_loadu_pd(&Omegam_data[c_i].f1[6 * b_i + 2]);
        r1 = _mm_loadu_pd(&b_P0[2]);
        _mm_storeu_pd(&b_P0[2], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        r = _mm_loadu_pd(&Omegam_data[c_i].f1[6 * b_i + 4]);
        r1 = _mm_loadu_pd(&b_P0[4]);
        _mm_storeu_pd(&b_P0[4], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      }
      r = _mm_loadu_pd(&b_P0[0]);
      r1 = _mm_loadu_pd(&tLdot_data[6 * c_i]);
      loop_ub = (int)robotJoints_data[c_i].q_id - 1;
      r2 = _mm_set1_pd(um_data[loop_ub]);
      r3 = _mm_set1_pd(umdot_data[loop_ub]);
      _mm_storeu_pd(
          &tLdot_data[6 * c_i],
          _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(r, r2)),
                     _mm_mul_pd(_mm_loadu_pd(&pm_data[6 * c_i]), r3)));
      r = _mm_loadu_pd(&b_P0[2]);
      loop_ub = 6 * c_i + 2;
      r1 = _mm_loadu_pd(&tLdot_data[loop_ub]);
      _mm_storeu_pd(
          &tLdot_data[loop_ub],
          _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(r, r2)),
                     _mm_mul_pd(_mm_loadu_pd(&pm_data[loop_ub]), r3)));
      r = _mm_loadu_pd(&b_P0[4]);
      loop_ub = 6 * c_i + 4;
      r1 = _mm_loadu_pd(&tLdot_data[loop_ub]);
      _mm_storeu_pd(
          &tLdot_data[loop_ub],
          _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(r, r2)),
                     _mm_mul_pd(_mm_loadu_pd(&pm_data[loop_ub]), r3)));
    }
  }
  emxFree_cell_wrap_1(&Omegam);
}

/*
 * Computes operational-space accelerations (twist-rate).
 *
 *  All 3D matrices (Bi0, Bij, Omegam) are replaced with cell arrays for
 *  code-generation compatibility.
 *
 * Arguments    : const double t0[6]
 *                const emxArray_real_T *tL
 *                const double P0[36]
 *                const emxArray_real_T *pm
 *                const emxArray_cell_wrap_1 *Bi0
 *                const emxArray_cell_wrap_1 *Bij
 *                const double u0[6]
 *                const emxArray_real_T *um
 *                double nLinksJoints
 *                const emxArray_struct0_T *robotJoints
 *                double t0dot[6]
 *                emxArray_real_T *tLdot
 * Return Type  : void
 */
void b_Accelerations_C(const double t0[6], const emxArray_real_T *tL,
                       const double P0[36], const emxArray_real_T *pm,
                       const emxArray_cell_wrap_1 *Bi0,
                       const emxArray_cell_wrap_1 *Bij, const double u0[6],
                       const emxArray_real_T *um, double nLinksJoints,
                       const emxArray_struct0_T *robotJoints, double t0dot[6],
                       emxArray_real_T *tLdot)
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  __m128d r3;
  const cell_wrap_1 *Bi0_data;
  const cell_wrap_1 *Bij_data;
  cell_wrap_1 *Omegam_data;
  emxArray_cell_wrap_1 *Omegam;
  const struct0_T *robotJoints_data;
  double dv[36];
  double dv1[36];
  double skew_omega[9];
  double b_P0[6];
  double dv2[6];
  double x[3];
  const double *pm_data;
  const double *tL_data;
  const double *um_data;
  double d;
  double *tLdot_data;
  int b_i;
  int c_i;
  int i;
  int i1;
  int loop_ub;
  robotJoints_data = robotJoints->data;
  um_data = um->data;
  Bij_data = Bij->data;
  Bi0_data = Bi0->data;
  pm_data = pm->data;
  tL_data = tL->data;
  /* --- Omega matrices ---% */
  /*  Base-link */
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
  /*  Pre-allocate cell array for Omegam */
  emxInit_cell_wrap_1(&Omegam, 2);
  loop_ub = Omegam->size[0] * Omegam->size[1];
  Omegam->size[0] = 1;
  i = (int)nLinksJoints;
  Omegam->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(Omegam, loop_ub);
  Omegam_data = Omegam->data;
  /*  Compute Omega for manipulator links */
  if ((int)nLinksJoints - 1 >= 0) {
    skew_omega[0] = 0.0;
    skew_omega[4] = 0.0;
    skew_omega[8] = 0.0;
  }
  for (b_i = 0; b_i < i; b_i++) {
    double d1;
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
    d = tL_data[6 * b_i + 2];
    skew_omega[3] = -d;
    d1 = tL_data[6 * b_i + 1];
    skew_omega[6] = d1;
    skew_omega[1] = d;
    d = tL_data[6 * b_i];
    skew_omega[7] = -d;
    skew_omega[2] = -d1;
    skew_omega[5] = d;
    for (c_i = 0; c_i < 3; c_i++) {
      d = skew_omega[3 * c_i];
      Omegam_data[b_i].f1[6 * c_i] = d;
      loop_ub = 6 * (c_i + 3);
      Omegam_data[b_i].f1[loop_ub] = 0.0;
      Omegam_data[b_i].f1[6 * c_i + 3] = 0.0;
      Omegam_data[b_i].f1[loop_ub + 3] = d;
      d = skew_omega[3 * c_i + 1];
      Omegam_data[b_i].f1[6 * c_i + 1] = d;
      Omegam_data[b_i].f1[loop_ub + 1] = 0.0;
      Omegam_data[b_i].f1[6 * c_i + 4] = 0.0;
      Omegam_data[b_i].f1[loop_ub + 4] = d;
      d = skew_omega[3 * c_i + 2];
      Omegam_data[b_i].f1[6 * c_i + 2] = d;
      Omegam_data[b_i].f1[loop_ub + 2] = 0.0;
      Omegam_data[b_i].f1[6 * c_i + 5] = 0.0;
      Omegam_data[b_i].f1[loop_ub + 5] = d;
    }
  }
  /* --- Twist Rate ---% */
  /*  Base-link acceleration */
  dv[0] = 0.0;
  dv[6] = -t0[2];
  dv[12] = t0[1];
  dv[1] = t0[2];
  dv[7] = 0.0;
  dv[13] = -t0[0];
  dv[2] = -t0[1];
  dv[8] = t0[0];
  dv[14] = 0.0;
  for (b_i = 0; b_i < 3; b_i++) {
    loop_ub = 6 * (b_i + 3);
    dv[loop_ub] = 0.0;
    dv[loop_ub + 1] = 0.0;
    dv[loop_ub + 2] = 0.0;
  }
  for (b_i = 0; b_i < 6; b_i++) {
    dv[6 * b_i + 3] = 0.0;
    dv[6 * b_i + 4] = 0.0;
    dv[6 * b_i + 5] = 0.0;
  }
  memset(&dv1[0], 0, 36U * sizeof(double));
  memset(&t0dot[0], 0, 6U * sizeof(double));
  memset(&b_P0[0], 0, 6U * sizeof(double));
  r = _mm_set1_pd(0.0);
  for (c_i = 0; c_i < 6; c_i++) {
    loop_ub = 6 * c_i + 2;
    i1 = 6 * c_i + 4;
    for (b_i = 0; b_i < 6; b_i++) {
      r2 = _mm_loadu_pd(&dv[6 * b_i]);
      r1 = _mm_loadu_pd(&dv1[6 * c_i]);
      r3 = _mm_set1_pd(P0[b_i + 6 * c_i]);
      _mm_storeu_pd(&dv1[6 * c_i], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      r2 = _mm_loadu_pd(&dv[6 * b_i + 2]);
      r1 = _mm_loadu_pd(&dv1[loop_ub]);
      _mm_storeu_pd(&dv1[loop_ub], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      r2 = _mm_loadu_pd(&dv[6 * b_i + 4]);
      r1 = _mm_loadu_pd(&dv1[i1]);
      _mm_storeu_pd(&dv1[i1], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    }
    r2 = _mm_loadu_pd(&dv1[6 * c_i]);
    r1 = _mm_loadu_pd(&t0dot[0]);
    r3 = _mm_set1_pd(u0[c_i]);
    _mm_storeu_pd(&t0dot[0], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    r1 = _mm_loadu_pd(&b_P0[0]);
    _mm_storeu_pd(&b_P0[0],
                  _mm_add_pd(r1, _mm_mul_pd(_mm_loadu_pd(&P0[6 * c_i]), r)));
    loop_ub = 6 * c_i + 2;
    r2 = _mm_loadu_pd(&dv1[loop_ub]);
    r1 = _mm_loadu_pd(&t0dot[2]);
    _mm_storeu_pd(&t0dot[2], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    r1 = _mm_loadu_pd(&b_P0[2]);
    _mm_storeu_pd(&b_P0[2],
                  _mm_add_pd(r1, _mm_mul_pd(_mm_loadu_pd(&P0[loop_ub]), r)));
    loop_ub = 6 * c_i + 4;
    r2 = _mm_loadu_pd(&dv1[loop_ub]);
    r1 = _mm_loadu_pd(&t0dot[4]);
    _mm_storeu_pd(&t0dot[4], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    r1 = _mm_loadu_pd(&b_P0[4]);
    _mm_storeu_pd(&b_P0[4],
                  _mm_add_pd(r1, _mm_mul_pd(_mm_loadu_pd(&P0[loop_ub]), r)));
  }
  r1 = _mm_loadu_pd(&t0dot[0]);
  r2 = _mm_loadu_pd(&b_P0[0]);
  _mm_storeu_pd(&t0dot[0], _mm_add_pd(r1, r2));
  r1 = _mm_loadu_pd(&t0dot[2]);
  r2 = _mm_loadu_pd(&b_P0[2]);
  _mm_storeu_pd(&t0dot[2], _mm_add_pd(r1, r2));
  r1 = _mm_loadu_pd(&t0dot[4]);
  r2 = _mm_loadu_pd(&b_P0[4]);
  _mm_storeu_pd(&t0dot[4], _mm_add_pd(r1, r2));
  /*  Pre-allocate for manipulator */
  loop_ub = tLdot->size[0] * tLdot->size[1];
  tLdot->size[0] = 6;
  tLdot->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(tLdot, loop_ub);
  tLdot_data = tLdot->data;
  loop_ub = 6 * (int)nLinksJoints;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    tLdot_data[b_i] = 0.0;
  }
  /*  Forward recursion */
  for (c_i = 0; c_i < i; c_i++) {
    d = robotJoints_data[c_i].parent_link;
    if (robotJoints_data[c_i].parent_link == 0.0) {
      /*  First link (connected to base) */
      _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&t0[3]),
                                      _mm_loadu_pd(&tL_data[6 * c_i + 3])));
      x[2] = t0[5] - tL_data[6 * c_i + 5];
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
      for (b_i = 0; b_i < 6; b_i++) {
        dv[6 * b_i] = 0.0;
        dv[6 * b_i + 1] = 0.0;
        dv[6 * b_i + 2] = 0.0;
      }
      dv[3] = 0.0;
      dv[9] = -x[2];
      dv[15] = x[1];
      dv[4] = x[2];
      dv[10] = 0.0;
      dv[16] = -x[0];
      dv[5] = -x[1];
      dv[11] = x[0];
      dv[17] = 0.0;
      for (b_i = 0; b_i < 3; b_i++) {
        loop_ub = 6 * (b_i + 3);
        dv[loop_ub + 3] = 0.0;
        dv[loop_ub + 4] = 0.0;
        dv[loop_ub + 5] = 0.0;
      }
      memset(&b_P0[0], 0, 6U * sizeof(double));
      memset(&dv2[0], 0, 6U * sizeof(double));
      for (b_i = 0; b_i < 6; b_i++) {
        r2 = _mm_loadu_pd(&b_P0[0]);
        r3 = _mm_set1_pd(t0dot[b_i]);
        _mm_storeu_pd(
            &b_P0[0],
            _mm_add_pd(
                r2, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[6 * b_i]), r3)));
        r2 = _mm_loadu_pd(&dv[6 * b_i]);
        r1 = _mm_loadu_pd(&dv2[0]);
        r = _mm_set1_pd(t0[b_i]);
        _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
        r2 = _mm_loadu_pd(&b_P0[2]);
        loop_ub = 6 * b_i + 2;
        _mm_storeu_pd(
            &b_P0[2],
            _mm_add_pd(
                r2, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[loop_ub]), r3)));
        r2 = _mm_loadu_pd(&dv[loop_ub]);
        r1 = _mm_loadu_pd(&dv2[2]);
        _mm_storeu_pd(&dv2[2], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
        r2 = _mm_loadu_pd(&b_P0[4]);
        loop_ub = 6 * b_i + 4;
        _mm_storeu_pd(
            &b_P0[4],
            _mm_add_pd(
                r2, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[loop_ub]), r3)));
        r2 = _mm_loadu_pd(&dv[loop_ub]);
        r1 = _mm_loadu_pd(&dv2[4]);
        _mm_storeu_pd(&dv2[4], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
      }
      r1 = _mm_loadu_pd(&b_P0[0]);
      r2 = _mm_loadu_pd(&dv2[0]);
      _mm_storeu_pd(&tLdot_data[6 * c_i], _mm_add_pd(r1, r2));
      r1 = _mm_loadu_pd(&b_P0[2]);
      r2 = _mm_loadu_pd(&dv2[2]);
      _mm_storeu_pd(&tLdot_data[6 * c_i + 2], _mm_add_pd(r1, r2));
      r1 = _mm_loadu_pd(&b_P0[4]);
      r2 = _mm_loadu_pd(&dv2[4]);
      _mm_storeu_pd(&tLdot_data[6 * c_i + 4], _mm_add_pd(r1, r2));
    } else {
      i1 = (int)robotJoints_data[c_i].parent_link - 1;
      loop_ub = 6 * ((int)d - 1);
      _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&tL_data[loop_ub + 3]),
                                      _mm_loadu_pd(&tL_data[6 * c_i + 3])));
      x[2] = tL_data[loop_ub + 5] - tL_data[6 * c_i + 5];
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
      for (b_i = 0; b_i < 6; b_i++) {
        dv[6 * b_i] = 0.0;
        dv[6 * b_i + 1] = 0.0;
        dv[6 * b_i + 2] = 0.0;
      }
      dv[3] = 0.0;
      dv[9] = -x[2];
      dv[15] = x[1];
      dv[4] = x[2];
      dv[10] = 0.0;
      dv[16] = -x[0];
      dv[5] = -x[1];
      dv[11] = x[0];
      dv[17] = 0.0;
      for (b_i = 0; b_i < 3; b_i++) {
        loop_ub = 6 * (b_i + 3);
        dv[loop_ub + 3] = 0.0;
        dv[loop_ub + 4] = 0.0;
        dv[loop_ub + 5] = 0.0;
      }
      memset(&b_P0[0], 0, 6U * sizeof(double));
      memset(&dv2[0], 0, 6U * sizeof(double));
      for (b_i = 0; b_i < 6; b_i++) {
        r2 = _mm_loadu_pd(&b_P0[0]);
        loop_ub = b_i + 6 * i1;
        r3 = _mm_set1_pd(tLdot_data[loop_ub]);
        _mm_storeu_pd(
            &b_P0[0],
            _mm_add_pd(
                r2, _mm_mul_pd(_mm_loadu_pd(
                                   &Bij_data[c_i + Bij->size[0] * ((int)d - 1)]
                                        .f1[6 * b_i]),
                               r3)));
        r2 = _mm_loadu_pd(&dv[6 * b_i]);
        r1 = _mm_loadu_pd(&dv2[0]);
        r = _mm_set1_pd(tL_data[loop_ub]);
        _mm_storeu_pd(&dv2[0], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
        r2 = _mm_loadu_pd(&b_P0[2]);
        loop_ub = 6 * b_i + 2;
        _mm_storeu_pd(
            &b_P0[2],
            _mm_add_pd(
                r2, _mm_mul_pd(_mm_loadu_pd(
                                   &Bij_data[c_i + Bij->size[0] * ((int)d - 1)]
                                        .f1[loop_ub]),
                               r3)));
        r2 = _mm_loadu_pd(&dv[loop_ub]);
        r1 = _mm_loadu_pd(&dv2[2]);
        _mm_storeu_pd(&dv2[2], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
        r2 = _mm_loadu_pd(&b_P0[4]);
        loop_ub = 6 * b_i + 4;
        _mm_storeu_pd(
            &b_P0[4],
            _mm_add_pd(
                r2, _mm_mul_pd(_mm_loadu_pd(
                                   &Bij_data[c_i + Bij->size[0] * ((int)d - 1)]
                                        .f1[loop_ub]),
                               r3)));
        r2 = _mm_loadu_pd(&dv[loop_ub]);
        r1 = _mm_loadu_pd(&dv2[4]);
        _mm_storeu_pd(&dv2[4], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
      }
      r1 = _mm_loadu_pd(&b_P0[0]);
      r2 = _mm_loadu_pd(&dv2[0]);
      _mm_storeu_pd(&tLdot_data[6 * c_i], _mm_add_pd(r1, r2));
      r1 = _mm_loadu_pd(&b_P0[2]);
      r2 = _mm_loadu_pd(&dv2[2]);
      _mm_storeu_pd(&tLdot_data[6 * c_i + 2], _mm_add_pd(r1, r2));
      r1 = _mm_loadu_pd(&b_P0[4]);
      r2 = _mm_loadu_pd(&dv2[4]);
      _mm_storeu_pd(&tLdot_data[6 * c_i + 4], _mm_add_pd(r1, r2));
    }
    /*  Add joint contribution */
    if (robotJoints_data[c_i].type != 0.0) {
      memset(&b_P0[0], 0, 6U * sizeof(double));
      for (b_i = 0; b_i < 6; b_i++) {
        r2 = _mm_loadu_pd(&Omegam_data[c_i].f1[6 * b_i]);
        r1 = _mm_loadu_pd(&b_P0[0]);
        r3 = _mm_set1_pd(pm_data[b_i + 6 * c_i]);
        _mm_storeu_pd(&b_P0[0], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
        r2 = _mm_loadu_pd(&Omegam_data[c_i].f1[6 * b_i + 2]);
        r1 = _mm_loadu_pd(&b_P0[2]);
        _mm_storeu_pd(&b_P0[2], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
        r2 = _mm_loadu_pd(&Omegam_data[c_i].f1[6 * b_i + 4]);
        r1 = _mm_loadu_pd(&b_P0[4]);
        _mm_storeu_pd(&b_P0[4], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      }
      r2 = _mm_loadu_pd(&b_P0[0]);
      r1 = _mm_loadu_pd(&tLdot_data[6 * c_i]);
      r3 = _mm_set1_pd(um_data[(int)robotJoints_data[c_i].q_id - 1]);
      r = _mm_set1_pd(0.0);
      _mm_storeu_pd(&tLdot_data[6 * c_i],
                    _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(r2, r3)),
                               _mm_mul_pd(_mm_loadu_pd(&pm_data[6 * c_i]), r)));
      r2 = _mm_loadu_pd(&b_P0[2]);
      loop_ub = 6 * c_i + 2;
      r1 = _mm_loadu_pd(&tLdot_data[loop_ub]);
      _mm_storeu_pd(&tLdot_data[loop_ub],
                    _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(r2, r3)),
                               _mm_mul_pd(_mm_loadu_pd(&pm_data[loop_ub]), r)));
      r2 = _mm_loadu_pd(&b_P0[4]);
      loop_ub = 6 * c_i + 4;
      r1 = _mm_loadu_pd(&tLdot_data[loop_ub]);
      _mm_storeu_pd(&tLdot_data[loop_ub],
                    _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(r2, r3)),
                               _mm_mul_pd(_mm_loadu_pd(&pm_data[loop_ub]), r)));
    }
  }
  emxFree_cell_wrap_1(&Omegam);
}

/*
 * File trailer for Accelerations_C.c
 *
 * [EOF]
 */
