/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ID_C.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

/* Include Files */
#include "ID_C.h"
#include "SPART_C_data.h"
#include "SPART_C_emxutil.h"
#include "SPART_C_initialize.h"
#include "SPART_C_types.h"
#include "omp.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double wF0[6]
 *                const emxArray_real_T *wFm
 *                const double t0[6]
 *                const emxArray_real_T *tL
 *                const double t0dot[6]
 *                const emxArray_real_T *tLdot
 *                const double P0[36]
 *                const emxArray_real_T *pm
 *                const double I0[9]
 *                const emxArray_cell_wrap_2 *Im
 *                const emxArray_cell_wrap_1 *Bij
 *                const emxArray_cell_wrap_1 *Bi0
 *                double nLinksJoints
 *                double nQ
 *                const struct2_T *robotBaseLink
 *                const emxArray_struct1_T *robotLinks
 *                const emxArray_real_T *robotConChild
 *                const emxArray_real_T *robotConChildBase
 *                const emxArray_struct0_T *robotJoints
 *                double tau0[6]
 *                emxArray_real_T *taum
 * Return Type  : void
 */
void ID_C(const double wF0[6], const emxArray_real_T *wFm, const double t0[6],
          const emxArray_real_T *tL, const double t0dot[6],
          const emxArray_real_T *tLdot, const double P0[36],
          const emxArray_real_T *pm, const double I0[9],
          const emxArray_cell_wrap_2 *Im, const emxArray_cell_wrap_1 *Bij,
          const emxArray_cell_wrap_1 *Bi0, double nLinksJoints, double nQ,
          const struct2_T *robotBaseLink, const emxArray_struct1_T *robotLinks,
          const emxArray_real_T *robotConChild,
          const emxArray_real_T *robotConChildBase,
          const emxArray_struct0_T *robotJoints, double tau0[6],
          emxArray_real_T *taum)
{
  __m128d r;
  __m128d r1;
  __m128d r4;
  __m128d r5;
  __m128d r6;
  __m128d r7;
  __m128d r8;
  const cell_wrap_1 *Bi0_data;
  const cell_wrap_1 *Bij_data;
  cell_wrap_1 *Mdot_data;
  const cell_wrap_2 *Im_data;
  emxArray_cell_wrap_1 *Mdot;
  emxArray_real_T *wq;
  emxArray_real_T *wq_tilde;
  const struct0_T *robotJoints_data;
  const struct1_T *robotLinks_data;
  double b_I0[36];
  double dv2[36];
  double dv[9];
  double dv1[9];
  double b_Im[6];
  double b_Mdot[6];
  double wq0[6];
  const double *pm_data;
  const double *robotConChildBase_data;
  const double *robotConChild_data;
  const double *tL_data;
  const double *tLdot_data;
  const double *wFm_data;
  double b_I0_tmp;
  double d1;
  double d2;
  double g_I0_tmp;
  double *wq_data;
  double *wq_tilde_data;
  int I0_tmp;
  int b_i;
  int c_I0_tmp;
  int c_i;
  int d_I0_tmp;
  int d_i;
  int e_I0_tmp;
  int e_i;
  int f_I0_tmp;
  int h_I0_tmp;
  int i;
  int i1;
  int i2;
  int i_I0_tmp;
  if (!isInitialized_SPART_C) {
    SPART_C_initialize();
  }
  robotJoints_data = robotJoints->data;
  robotConChildBase_data = robotConChildBase->data;
  robotConChild_data = robotConChild->data;
  robotLinks_data = robotLinks->data;
  Bi0_data = Bi0->data;
  Bij_data = Bij->data;
  Im_data = Im->data;
  pm_data = pm->data;
  tLdot_data = tLdot->data;
  tL_data = tL->data;
  wFm_data = wFm->data;
  /* --- Mdot ---% */
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
  emxInit_cell_wrap_1(&Mdot, 2);
  I0_tmp = Mdot->size[0] * Mdot->size[1];
  Mdot->size[0] = 1;
  i = (int)nLinksJoints;
  Mdot->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(Mdot, I0_tmp);
  Mdot_data = Mdot->data;
  if ((int)nLinksJoints - 1 >= 0) {
    dv[0] = 0.0;
    dv[4] = 0.0;
    dv[8] = 0.0;
  }
  for (b_i = 0; b_i < i; b_i++) {
    double d;
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
    b_I0_tmp = tL_data[6 * b_i + 2];
    dv[3] = -b_I0_tmp;
    d = tL_data[6 * b_i + 1];
    dv[6] = d;
    dv[1] = b_I0_tmp;
    b_I0_tmp = tL_data[6 * b_i];
    dv[7] = -b_I0_tmp;
    dv[2] = -d;
    dv[5] = b_I0_tmp;
    memset(&dv1[0], 0, 9U * sizeof(double));
    for (c_i = 0; c_i < 3; c_i++) {
      d1 = Im_data[b_i].f1[3 * c_i];
      r = _mm_loadu_pd(&dv[0]);
      r1 = _mm_loadu_pd(&dv1[3 * c_i]);
      _mm_storeu_pd(&dv1[3 * c_i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d1))));
      c_I0_tmp = 3 * c_i + 2;
      dv1[c_I0_tmp] += -d * d1;
      I0_tmp = 3 * c_i + 1;
      d1 = Im_data[b_i].f1[I0_tmp];
      r = _mm_loadu_pd(&dv[3]);
      r1 = _mm_loadu_pd(&dv1[3 * c_i]);
      _mm_storeu_pd(&dv1[3 * c_i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d1))));
      dv1[c_I0_tmp] += b_I0_tmp * d1;
      d1 = Im_data[b_i].f1[c_I0_tmp];
      r = _mm_loadu_pd(&dv[6]);
      r1 = _mm_loadu_pd(&dv1[3 * c_i]);
      _mm_storeu_pd(&dv1[3 * c_i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d1))));
      dv1[c_I0_tmp] += 0.0 * d1;
      Mdot_data[b_i].f1[6 * c_i] = dv1[3 * c_i];
      d_I0_tmp = 6 * (c_i + 3);
      Mdot_data[b_i].f1[d_I0_tmp] = 0.0;
      Mdot_data[b_i].f1[6 * c_i + 1] = dv1[I0_tmp];
      Mdot_data[b_i].f1[d_I0_tmp + 1] = 0.0;
      Mdot_data[b_i].f1[6 * c_i + 2] = dv1[c_I0_tmp];
      Mdot_data[b_i].f1[d_I0_tmp + 2] = 0.0;
    }
    for (c_i = 0; c_i < 6; c_i++) {
      Mdot_data[b_i].f1[6 * c_i + 3] = 0.0;
      Mdot_data[b_i].f1[6 * c_i + 4] = 0.0;
      Mdot_data[b_i].f1[6 * c_i + 5] = 0.0;
    }
  }
  /* --- Forces ---% */
  dv[0] = 0.0;
  dv[3] = -t0[2];
  dv[6] = t0[1];
  dv[1] = t0[2];
  dv[4] = 0.0;
  dv[7] = -t0[0];
  dv[2] = -t0[1];
  dv[5] = t0[0];
  dv[8] = 0.0;
  memset(&dv1[0], 0, 9U * sizeof(double));
  for (c_i = 0; c_i < 3; c_i++) {
    b_I0_tmp = I0[3 * c_i];
    b_I0[6 * c_i] = b_I0_tmp;
    I0_tmp = 6 * (c_i + 3);
    b_I0[I0_tmp] = 0.0;
    b_I0[6 * c_i + 3] = 0.0;
    b_I0[I0_tmp + 3] = robotBaseLink->mass * (double)iv[3 * c_i];
    r = _mm_loadu_pd(&dv[0]);
    r1 = _mm_loadu_pd(&dv1[3 * c_i]);
    _mm_storeu_pd(&dv1[3 * c_i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(b_I0_tmp))));
    c_I0_tmp = 3 * c_i + 2;
    dv1[c_I0_tmp] += dv[2] * b_I0_tmp;
    d_I0_tmp = 3 * c_i + 1;
    b_I0_tmp = I0[d_I0_tmp];
    e_I0_tmp = 6 * c_i + 1;
    b_I0[e_I0_tmp] = b_I0_tmp;
    b_I0[I0_tmp + 1] = 0.0;
    b_I0[6 * c_i + 4] = 0.0;
    b_I0[I0_tmp + 4] = robotBaseLink->mass * (double)iv[d_I0_tmp];
    r = _mm_loadu_pd(&dv[3]);
    r1 = _mm_loadu_pd(&dv1[3 * c_i]);
    _mm_storeu_pd(&dv1[3 * c_i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(b_I0_tmp))));
    dv1[c_I0_tmp] += dv[5] * b_I0_tmp;
    b_I0_tmp = I0[c_I0_tmp];
    f_I0_tmp = 6 * c_i + 2;
    b_I0[f_I0_tmp] = b_I0_tmp;
    b_I0[I0_tmp + 2] = 0.0;
    b_I0[6 * c_i + 5] = 0.0;
    b_I0[I0_tmp + 5] = robotBaseLink->mass * (double)iv[c_I0_tmp];
    r = _mm_loadu_pd(&dv[6]);
    r1 = _mm_loadu_pd(&dv1[3 * c_i]);
    _mm_storeu_pd(&dv1[3 * c_i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(b_I0_tmp))));
    dv1[c_I0_tmp] += 0.0 * b_I0_tmp;
    dv2[6 * c_i] = dv1[3 * c_i];
    dv2[I0_tmp] = 0.0;
    dv2[e_I0_tmp] = dv1[d_I0_tmp];
    dv2[I0_tmp + 1] = 0.0;
    dv2[f_I0_tmp] = dv1[c_I0_tmp];
    dv2[I0_tmp + 2] = 0.0;
  }
  memset(&wq0[0], 0, 6U * sizeof(double));
  memset(&b_Im[0], 0, 6U * sizeof(double));
  for (c_i = 0; c_i < 6; c_i++) {
    __m128d r2;
    __m128d r3;
    dv2[6 * c_i + 3] = 0.0;
    I0_tmp = 6 * c_i + 4;
    dv2[I0_tmp] = 0.0;
    dv2[6 * c_i + 5] = 0.0;
    r = _mm_loadu_pd(&b_I0[6 * c_i]);
    r1 = _mm_loadu_pd(&wq0[0]);
    r2 = _mm_set1_pd(t0dot[c_i]);
    _mm_storeu_pd(&wq0[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&dv2[6 * c_i]);
    r1 = _mm_loadu_pd(&b_Im[0]);
    r3 = _mm_set1_pd(t0[c_i]);
    _mm_storeu_pd(&b_Im[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    c_I0_tmp = 6 * c_i + 2;
    r = _mm_loadu_pd(&b_I0[c_I0_tmp]);
    r1 = _mm_loadu_pd(&wq0[2]);
    _mm_storeu_pd(&wq0[2], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&dv2[c_I0_tmp]);
    r1 = _mm_loadu_pd(&b_Im[2]);
    _mm_storeu_pd(&b_Im[2], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    r = _mm_loadu_pd(&b_I0[I0_tmp]);
    r1 = _mm_loadu_pd(&wq0[4]);
    _mm_storeu_pd(&wq0[4], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&dv2[I0_tmp]);
    r1 = _mm_loadu_pd(&b_Im[4]);
    _mm_storeu_pd(&b_Im[4], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
  }
  r = _mm_loadu_pd(&wq0[0]);
  r1 = _mm_loadu_pd(&b_Im[0]);
  _mm_storeu_pd(&wq0[0], _mm_sub_pd(_mm_add_pd(r, r1), _mm_loadu_pd(&wF0[0])));
  r = _mm_loadu_pd(&wq0[2]);
  r1 = _mm_loadu_pd(&b_Im[2]);
  _mm_storeu_pd(&wq0[2], _mm_sub_pd(_mm_add_pd(r, r1), _mm_loadu_pd(&wF0[2])));
  r = _mm_loadu_pd(&wq0[4]);
  r1 = _mm_loadu_pd(&b_Im[4]);
  _mm_storeu_pd(&wq0[4], _mm_sub_pd(_mm_add_pd(r, r1), _mm_loadu_pd(&wF0[4])));
  emxInit_real_T(&wq, 2);
  I0_tmp = wq->size[0] * wq->size[1];
  wq->size[0] = 6;
  wq->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(wq, I0_tmp);
  wq_data = wq->data;
  e_I0_tmp = 6 * (int)nLinksJoints;
  for (c_i = 0; c_i < e_I0_tmp; c_i++) {
    wq_data[c_i] = 0.0;
  }
  f_I0_tmp = (int)nQ;
  if ((int)nQ * 12 < 1600) {
    for (d_i = 0; d_i < f_I0_tmp; d_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_I0[6 * i1] = Im_data[d_i].f1[3 * i1];
        I0_tmp = 6 * (i1 + 3);
        b_I0[I0_tmp] = 0.0;
        b_I0[6 * i1 + 3] = 0.0;
        b_I0_tmp = robotLinks_data[d_i].mass;
        b_I0[I0_tmp + 3] = b_I0_tmp * (double)iv[3 * i1];
        c_I0_tmp = 3 * i1 + 1;
        b_I0[6 * i1 + 1] = Im_data[d_i].f1[c_I0_tmp];
        b_I0[I0_tmp + 1] = 0.0;
        b_I0[6 * i1 + 4] = 0.0;
        b_I0[I0_tmp + 4] = b_I0_tmp * (double)iv[c_I0_tmp];
        d_I0_tmp = 3 * i1 + 2;
        b_I0[6 * i1 + 2] = Im_data[d_i].f1[d_I0_tmp];
        b_I0[I0_tmp + 2] = 0.0;
        b_I0[6 * i1 + 5] = 0.0;
        b_I0[I0_tmp + 5] = b_I0_tmp * (double)iv[d_I0_tmp];
      }
      memset(&b_Im[0], 0, 6U * sizeof(double));
      memset(&b_Mdot[0], 0, 6U * sizeof(double));
      for (i1 = 0; i1 < 6; i1++) {
        r4 = _mm_loadu_pd(&b_I0[6 * i1]);
        r5 = _mm_loadu_pd(&b_Im[0]);
        I0_tmp = i1 + 6 * d_i;
        r = _mm_set1_pd(tLdot_data[I0_tmp]);
        _mm_storeu_pd(&b_Im[0], _mm_add_pd(r5, _mm_mul_pd(r4, r)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[6 * i1]);
        r6 = _mm_loadu_pd(&b_Mdot[0]);
        r1 = _mm_set1_pd(tL_data[I0_tmp]);
        _mm_storeu_pd(&b_Mdot[0], _mm_add_pd(r6, _mm_mul_pd(r5, r1)));
        I0_tmp = 6 * i1 + 2;
        r4 = _mm_loadu_pd(&b_I0[I0_tmp]);
        r5 = _mm_loadu_pd(&b_Im[2]);
        _mm_storeu_pd(&b_Im[2], _mm_add_pd(r5, _mm_mul_pd(r4, r)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[I0_tmp]);
        r6 = _mm_loadu_pd(&b_Mdot[2]);
        _mm_storeu_pd(&b_Mdot[2], _mm_add_pd(r6, _mm_mul_pd(r5, r1)));
        I0_tmp = 6 * i1 + 4;
        r4 = _mm_loadu_pd(&b_I0[I0_tmp]);
        r5 = _mm_loadu_pd(&b_Im[4]);
        _mm_storeu_pd(&b_Im[4], _mm_add_pd(r5, _mm_mul_pd(r4, r)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[I0_tmp]);
        r6 = _mm_loadu_pd(&b_Mdot[4]);
        _mm_storeu_pd(&b_Mdot[4], _mm_add_pd(r6, _mm_mul_pd(r5, r1)));
      }
      r4 = _mm_loadu_pd(&b_Im[0]);
      r5 = _mm_loadu_pd(&b_Mdot[0]);
      _mm_storeu_pd(
          &wq_data[6 * d_i],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[6 * d_i])));
      r4 = _mm_loadu_pd(&b_Im[2]);
      r5 = _mm_loadu_pd(&b_Mdot[2]);
      c_I0_tmp = 6 * d_i + 2;
      _mm_storeu_pd(
          &wq_data[c_I0_tmp],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[c_I0_tmp])));
      r4 = _mm_loadu_pd(&b_Im[4]);
      r5 = _mm_loadu_pd(&b_Mdot[4]);
      c_I0_tmp = 6 * d_i + 4;
      _mm_storeu_pd(
          &wq_data[c_I0_tmp],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[c_I0_tmp])));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        r4, r5, r6, g_I0_tmp, d2, b_Mdot, b_Im, b_I0, i1, h_I0_tmp, i_I0_tmp,  \
            r7, r8)

    for (d_i = 0; d_i < f_I0_tmp; d_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_I0[6 * i1] = Im_data[d_i].f1[3 * i1];
        h_I0_tmp = 6 * (i1 + 3);
        b_I0[h_I0_tmp] = 0.0;
        b_I0[6 * i1 + 3] = 0.0;
        g_I0_tmp = robotLinks_data[d_i].mass;
        b_I0[h_I0_tmp + 3] = g_I0_tmp * (double)iv[3 * i1];
        i_I0_tmp = 3 * i1 + 1;
        b_I0[6 * i1 + 1] = Im_data[d_i].f1[i_I0_tmp];
        b_I0[h_I0_tmp + 1] = 0.0;
        b_I0[6 * i1 + 4] = 0.0;
        b_I0[h_I0_tmp + 4] = g_I0_tmp * (double)iv[i_I0_tmp];
        i_I0_tmp = 3 * i1 + 2;
        b_I0[6 * i1 + 2] = Im_data[d_i].f1[i_I0_tmp];
        b_I0[h_I0_tmp + 2] = 0.0;
        b_I0[6 * i1 + 5] = 0.0;
        b_I0[h_I0_tmp + 5] = g_I0_tmp * (double)iv[i_I0_tmp];
      }
      memset(&b_Im[0], 0, 6U * sizeof(double));
      memset(&b_Mdot[0], 0, 6U * sizeof(double));
      for (i1 = 0; i1 < 6; i1++) {
        i_I0_tmp = i1 + 6 * d_i;
        d2 = tLdot_data[i_I0_tmp];
        g_I0_tmp = tL_data[i_I0_tmp];
        r4 = _mm_loadu_pd(&b_I0[6 * i1]);
        r7 = _mm_set1_pd(d2);
        r5 = _mm_loadu_pd(&b_Im[0]);
        _mm_storeu_pd(&b_Im[0], _mm_add_pd(r5, _mm_mul_pd(r4, r7)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[6 * i1]);
        r8 = _mm_set1_pd(g_I0_tmp);
        r6 = _mm_loadu_pd(&b_Mdot[0]);
        _mm_storeu_pd(&b_Mdot[0], _mm_add_pd(r6, _mm_mul_pd(r5, r8)));
        i_I0_tmp = 6 * i1 + 2;
        r4 = _mm_loadu_pd(&b_I0[i_I0_tmp]);
        r5 = _mm_loadu_pd(&b_Im[2]);
        _mm_storeu_pd(&b_Im[2], _mm_add_pd(r5, _mm_mul_pd(r4, r7)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[i_I0_tmp]);
        r6 = _mm_loadu_pd(&b_Mdot[2]);
        _mm_storeu_pd(&b_Mdot[2], _mm_add_pd(r6, _mm_mul_pd(r5, r8)));
        i_I0_tmp = 6 * i1 + 4;
        r4 = _mm_loadu_pd(&b_I0[i_I0_tmp]);
        r4 = _mm_mul_pd(r4, r7);
        r5 = _mm_loadu_pd(&b_Im[4]);
        r4 = _mm_add_pd(r5, r4);
        _mm_storeu_pd(&b_Im[4], r4);
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[i_I0_tmp]);
        r4 = _mm_mul_pd(r5, r8);
        r6 = _mm_loadu_pd(&b_Mdot[4]);
        r4 = _mm_add_pd(r6, r4);
        _mm_storeu_pd(&b_Mdot[4], r4);
      }
      r4 = _mm_loadu_pd(&b_Im[0]);
      r5 = _mm_loadu_pd(&b_Mdot[0]);
      _mm_storeu_pd(
          &wq_data[6 * d_i],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[6 * d_i])));
      r4 = _mm_loadu_pd(&b_Im[2]);
      r5 = _mm_loadu_pd(&b_Mdot[2]);
      i_I0_tmp = 6 * d_i + 2;
      _mm_storeu_pd(
          &wq_data[i_I0_tmp],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[i_I0_tmp])));
      r4 = _mm_loadu_pd(&b_Im[4]);
      r5 = _mm_loadu_pd(&b_Mdot[4]);
      r5 = _mm_add_pd(r4, r5);
      i_I0_tmp = 6 * d_i + 4;
      r4 = _mm_loadu_pd(&wFm_data[i_I0_tmp]);
      r4 = _mm_sub_pd(r5, r4);
      _mm_storeu_pd(&wq_data[i_I0_tmp], r4);
    }
  }
  emxFree_cell_wrap_1(&Mdot);
  /* --- Backward recursion ---% */
  emxInit_real_T(&wq_tilde, 2);
  I0_tmp = wq_tilde->size[0] * wq_tilde->size[1];
  wq_tilde->size[0] = 6;
  wq_tilde->size[1] = i;
  emxEnsureCapacity_real_T(wq_tilde, I0_tmp);
  wq_tilde_data = wq_tilde->data;
  for (c_i = 0; c_i < e_I0_tmp; c_i++) {
    wq_tilde_data[c_i] = 0.0;
  }
  e_I0_tmp = (int)-((-1.0 - nLinksJoints) + 1.0);
  for (e_i = 0; e_i < e_I0_tmp; e_i++) {
    b_I0_tmp = nLinksJoints - (double)e_i;
    for (c_i = 0; c_i < 6; c_i++) {
      I0_tmp = c_i + 6 * ((int)b_I0_tmp - 1);
      wq_tilde_data[I0_tmp] = wq_data[I0_tmp];
    }
    for (b_i = 0; b_i < i; b_i++) {
      if (robotConChild_data[b_i + robotConChild->size[0] *
                                       ((int)b_I0_tmp - 1)] != 0.0) {
        for (c_i = 0; c_i < 6; c_i++) {
          d1 = 0.0;
          for (i2 = 0; i2 < 6; i2++) {
            d1 += Bij_data[b_i + Bij->size[0] * ((int)b_I0_tmp - 1)]
                      .f1[i2 + 6 * c_i] *
                  wq_tilde_data[i2 + 6 * b_i];
          }
          b_Im[c_i] = wq_tilde_data[c_i + 6 * ((int)b_I0_tmp - 1)] + d1;
        }
        for (c_i = 0; c_i < 6; c_i++) {
          wq_tilde_data[c_i + 6 * ((int)b_I0_tmp - 1)] = b_Im[c_i];
        }
      }
    }
  }
  emxFree_real_T(&wq);
  for (b_i = 0; b_i < i; b_i++) {
    if (robotConChildBase_data[b_i] != 0.0) {
      for (c_i = 0; c_i < 6; c_i++) {
        b_I0_tmp = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          b_I0_tmp +=
              Bi0_data[b_i].f1[i2 + 6 * c_i] * wq_tilde_data[i2 + 6 * b_i];
        }
        wq0[c_i] += b_I0_tmp;
      }
    }
  }
  /* --- Joint Forces ---% */
  for (c_i = 0; c_i < 6; c_i++) {
    b_I0_tmp = 0.0;
    for (b_i = 0; b_i < 6; b_i++) {
      b_I0_tmp += P0[b_i + 6 * c_i] * wq0[b_i];
    }
    tau0[c_i] = b_I0_tmp;
  }
  I0_tmp = taum->size[0];
  taum->size[0] = f_I0_tmp;
  emxEnsureCapacity_real_T(taum, I0_tmp);
  wq_data = taum->data;
  for (c_i = 0; c_i < f_I0_tmp; c_i++) {
    wq_data[c_i] = 0.0;
  }
  for (c_i = 0; c_i < i; c_i++) {
    if (robotJoints_data[c_i].type != 0.0) {
      b_I0_tmp = 0.0;
      for (b_i = 0; b_i < 6; b_i++) {
        I0_tmp = b_i + 6 * c_i;
        b_I0_tmp += pm_data[I0_tmp] * wq_tilde_data[I0_tmp];
      }
      wq_data[(int)robotJoints_data[c_i].q_id - 1] = b_I0_tmp;
    }
  }
  emxFree_real_T(&wq_tilde);
}

/*
 * Arguments    : const double wF0[6]
 *                const emxArray_real_T *wFm
 *                const double t0[6]
 *                const emxArray_real_T *tL
 *                const double t0dot[6]
 *                const emxArray_real_T *tLdot
 *                const double P0[36]
 *                const emxArray_real_T *pm
 *                const double I0[9]
 *                const emxArray_cell_wrap_2 *Im
 *                const emxArray_cell_wrap_1 *Bij
 *                const emxArray_cell_wrap_1 *Bi0
 *                double nLinksJoints
 *                double nQ
 *                double robotBaseLink_mass
 *                const emxArray_struct1_T *robotLinks
 *                const emxArray_real_T *robotConChild
 *                const emxArray_real_T *robotConChildBase
 *                const emxArray_struct0_T *robotJoints
 *                double tau0[6]
 *                emxArray_real_T *taum
 * Return Type  : void
 */
void b_ID_C(const double wF0[6], const emxArray_real_T *wFm, const double t0[6],
            const emxArray_real_T *tL, const double t0dot[6],
            const emxArray_real_T *tLdot, const double P0[36],
            const emxArray_real_T *pm, const double I0[9],
            const emxArray_cell_wrap_2 *Im, const emxArray_cell_wrap_1 *Bij,
            const emxArray_cell_wrap_1 *Bi0, double nLinksJoints, double nQ,
            double robotBaseLink_mass, const emxArray_struct1_T *robotLinks,
            const emxArray_real_T *robotConChild,
            const emxArray_real_T *robotConChildBase,
            const emxArray_struct0_T *robotJoints, double tau0[6],
            emxArray_real_T *taum)
{
  __m128d r;
  __m128d r1;
  __m128d r4;
  __m128d r5;
  __m128d r6;
  __m128d r7;
  __m128d r8;
  const cell_wrap_1 *Bi0_data;
  const cell_wrap_1 *Bij_data;
  cell_wrap_1 *Mdot_data;
  const cell_wrap_2 *Im_data;
  emxArray_cell_wrap_1 *Mdot;
  emxArray_real_T *wq;
  emxArray_real_T *wq_tilde;
  const struct0_T *robotJoints_data;
  const struct1_T *robotLinks_data;
  double b_I0[36];
  double dv2[36];
  double dv[9];
  double dv1[9];
  double b_Im[6];
  double b_Mdot[6];
  double wq0[6];
  const double *pm_data;
  const double *robotConChildBase_data;
  const double *robotConChild_data;
  const double *tL_data;
  const double *tLdot_data;
  const double *wFm_data;
  double b_I0_tmp;
  double d1;
  double d2;
  double g_I0_tmp;
  double *wq_data;
  double *wq_tilde_data;
  int I0_tmp;
  int b_i;
  int c_I0_tmp;
  int c_i;
  int d_I0_tmp;
  int d_i;
  int e_I0_tmp;
  int e_i;
  int f_I0_tmp;
  int h_I0_tmp;
  int i;
  int i1;
  int i2;
  int i_I0_tmp;
  robotJoints_data = robotJoints->data;
  robotConChildBase_data = robotConChildBase->data;
  robotConChild_data = robotConChild->data;
  robotLinks_data = robotLinks->data;
  Bi0_data = Bi0->data;
  Bij_data = Bij->data;
  Im_data = Im->data;
  pm_data = pm->data;
  tLdot_data = tLdot->data;
  tL_data = tL->data;
  wFm_data = wFm->data;
  /* --- Mdot ---% */
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
  emxInit_cell_wrap_1(&Mdot, 2);
  I0_tmp = Mdot->size[0] * Mdot->size[1];
  Mdot->size[0] = 1;
  i = (int)nLinksJoints;
  Mdot->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(Mdot, I0_tmp);
  Mdot_data = Mdot->data;
  if ((int)nLinksJoints - 1 >= 0) {
    dv[0] = 0.0;
    dv[4] = 0.0;
    dv[8] = 0.0;
  }
  for (b_i = 0; b_i < i; b_i++) {
    double d;
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
    b_I0_tmp = tL_data[6 * b_i + 2];
    dv[3] = -b_I0_tmp;
    d = tL_data[6 * b_i + 1];
    dv[6] = d;
    dv[1] = b_I0_tmp;
    b_I0_tmp = tL_data[6 * b_i];
    dv[7] = -b_I0_tmp;
    dv[2] = -d;
    dv[5] = b_I0_tmp;
    memset(&dv1[0], 0, 9U * sizeof(double));
    for (c_i = 0; c_i < 3; c_i++) {
      d1 = Im_data[b_i].f1[3 * c_i];
      r = _mm_loadu_pd(&dv[0]);
      r1 = _mm_loadu_pd(&dv1[3 * c_i]);
      _mm_storeu_pd(&dv1[3 * c_i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d1))));
      c_I0_tmp = 3 * c_i + 2;
      dv1[c_I0_tmp] += -d * d1;
      I0_tmp = 3 * c_i + 1;
      d1 = Im_data[b_i].f1[I0_tmp];
      r = _mm_loadu_pd(&dv[3]);
      r1 = _mm_loadu_pd(&dv1[3 * c_i]);
      _mm_storeu_pd(&dv1[3 * c_i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d1))));
      dv1[c_I0_tmp] += b_I0_tmp * d1;
      d1 = Im_data[b_i].f1[c_I0_tmp];
      r = _mm_loadu_pd(&dv[6]);
      r1 = _mm_loadu_pd(&dv1[3 * c_i]);
      _mm_storeu_pd(&dv1[3 * c_i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d1))));
      dv1[c_I0_tmp] += 0.0 * d1;
      Mdot_data[b_i].f1[6 * c_i] = dv1[3 * c_i];
      d_I0_tmp = 6 * (c_i + 3);
      Mdot_data[b_i].f1[d_I0_tmp] = 0.0;
      Mdot_data[b_i].f1[6 * c_i + 1] = dv1[I0_tmp];
      Mdot_data[b_i].f1[d_I0_tmp + 1] = 0.0;
      Mdot_data[b_i].f1[6 * c_i + 2] = dv1[c_I0_tmp];
      Mdot_data[b_i].f1[d_I0_tmp + 2] = 0.0;
    }
    for (c_i = 0; c_i < 6; c_i++) {
      Mdot_data[b_i].f1[6 * c_i + 3] = 0.0;
      Mdot_data[b_i].f1[6 * c_i + 4] = 0.0;
      Mdot_data[b_i].f1[6 * c_i + 5] = 0.0;
    }
  }
  /* --- Forces ---% */
  dv[0] = 0.0;
  dv[3] = -t0[2];
  dv[6] = t0[1];
  dv[1] = t0[2];
  dv[4] = 0.0;
  dv[7] = -t0[0];
  dv[2] = -t0[1];
  dv[5] = t0[0];
  dv[8] = 0.0;
  memset(&dv1[0], 0, 9U * sizeof(double));
  for (c_i = 0; c_i < 3; c_i++) {
    b_I0_tmp = I0[3 * c_i];
    b_I0[6 * c_i] = b_I0_tmp;
    I0_tmp = 6 * (c_i + 3);
    b_I0[I0_tmp] = 0.0;
    b_I0[6 * c_i + 3] = 0.0;
    b_I0[I0_tmp + 3] = robotBaseLink_mass * (double)iv[3 * c_i];
    r = _mm_loadu_pd(&dv[0]);
    r1 = _mm_loadu_pd(&dv1[3 * c_i]);
    _mm_storeu_pd(&dv1[3 * c_i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(b_I0_tmp))));
    c_I0_tmp = 3 * c_i + 2;
    dv1[c_I0_tmp] += dv[2] * b_I0_tmp;
    d_I0_tmp = 3 * c_i + 1;
    b_I0_tmp = I0[d_I0_tmp];
    e_I0_tmp = 6 * c_i + 1;
    b_I0[e_I0_tmp] = b_I0_tmp;
    b_I0[I0_tmp + 1] = 0.0;
    b_I0[6 * c_i + 4] = 0.0;
    b_I0[I0_tmp + 4] = robotBaseLink_mass * (double)iv[d_I0_tmp];
    r = _mm_loadu_pd(&dv[3]);
    r1 = _mm_loadu_pd(&dv1[3 * c_i]);
    _mm_storeu_pd(&dv1[3 * c_i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(b_I0_tmp))));
    dv1[c_I0_tmp] += dv[5] * b_I0_tmp;
    b_I0_tmp = I0[c_I0_tmp];
    f_I0_tmp = 6 * c_i + 2;
    b_I0[f_I0_tmp] = b_I0_tmp;
    b_I0[I0_tmp + 2] = 0.0;
    b_I0[6 * c_i + 5] = 0.0;
    b_I0[I0_tmp + 5] = robotBaseLink_mass * (double)iv[c_I0_tmp];
    r = _mm_loadu_pd(&dv[6]);
    r1 = _mm_loadu_pd(&dv1[3 * c_i]);
    _mm_storeu_pd(&dv1[3 * c_i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(b_I0_tmp))));
    dv1[c_I0_tmp] += 0.0 * b_I0_tmp;
    dv2[6 * c_i] = dv1[3 * c_i];
    dv2[I0_tmp] = 0.0;
    dv2[e_I0_tmp] = dv1[d_I0_tmp];
    dv2[I0_tmp + 1] = 0.0;
    dv2[f_I0_tmp] = dv1[c_I0_tmp];
    dv2[I0_tmp + 2] = 0.0;
  }
  memset(&wq0[0], 0, 6U * sizeof(double));
  memset(&b_Im[0], 0, 6U * sizeof(double));
  for (c_i = 0; c_i < 6; c_i++) {
    __m128d r2;
    __m128d r3;
    dv2[6 * c_i + 3] = 0.0;
    I0_tmp = 6 * c_i + 4;
    dv2[I0_tmp] = 0.0;
    dv2[6 * c_i + 5] = 0.0;
    r = _mm_loadu_pd(&b_I0[6 * c_i]);
    r1 = _mm_loadu_pd(&wq0[0]);
    r2 = _mm_set1_pd(t0dot[c_i]);
    _mm_storeu_pd(&wq0[0], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&dv2[6 * c_i]);
    r1 = _mm_loadu_pd(&b_Im[0]);
    r3 = _mm_set1_pd(t0[c_i]);
    _mm_storeu_pd(&b_Im[0], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    c_I0_tmp = 6 * c_i + 2;
    r = _mm_loadu_pd(&b_I0[c_I0_tmp]);
    r1 = _mm_loadu_pd(&wq0[2]);
    _mm_storeu_pd(&wq0[2], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&dv2[c_I0_tmp]);
    r1 = _mm_loadu_pd(&b_Im[2]);
    _mm_storeu_pd(&b_Im[2], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
    r = _mm_loadu_pd(&b_I0[I0_tmp]);
    r1 = _mm_loadu_pd(&wq0[4]);
    _mm_storeu_pd(&wq0[4], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    r = _mm_loadu_pd(&dv2[I0_tmp]);
    r1 = _mm_loadu_pd(&b_Im[4]);
    _mm_storeu_pd(&b_Im[4], _mm_add_pd(r1, _mm_mul_pd(r, r3)));
  }
  r = _mm_loadu_pd(&wq0[0]);
  r1 = _mm_loadu_pd(&b_Im[0]);
  _mm_storeu_pd(&wq0[0], _mm_sub_pd(_mm_add_pd(r, r1), _mm_loadu_pd(&wF0[0])));
  r = _mm_loadu_pd(&wq0[2]);
  r1 = _mm_loadu_pd(&b_Im[2]);
  _mm_storeu_pd(&wq0[2], _mm_sub_pd(_mm_add_pd(r, r1), _mm_loadu_pd(&wF0[2])));
  r = _mm_loadu_pd(&wq0[4]);
  r1 = _mm_loadu_pd(&b_Im[4]);
  _mm_storeu_pd(&wq0[4], _mm_sub_pd(_mm_add_pd(r, r1), _mm_loadu_pd(&wF0[4])));
  emxInit_real_T(&wq, 2);
  I0_tmp = wq->size[0] * wq->size[1];
  wq->size[0] = 6;
  wq->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(wq, I0_tmp);
  wq_data = wq->data;
  e_I0_tmp = 6 * (int)nLinksJoints;
  for (c_i = 0; c_i < e_I0_tmp; c_i++) {
    wq_data[c_i] = 0.0;
  }
  f_I0_tmp = (int)nQ;
  if ((int)nQ * 12 < 1600) {
    for (d_i = 0; d_i < f_I0_tmp; d_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_I0[6 * i1] = Im_data[d_i].f1[3 * i1];
        I0_tmp = 6 * (i1 + 3);
        b_I0[I0_tmp] = 0.0;
        b_I0[6 * i1 + 3] = 0.0;
        b_I0_tmp = robotLinks_data[d_i].mass;
        b_I0[I0_tmp + 3] = b_I0_tmp * (double)iv[3 * i1];
        c_I0_tmp = 3 * i1 + 1;
        b_I0[6 * i1 + 1] = Im_data[d_i].f1[c_I0_tmp];
        b_I0[I0_tmp + 1] = 0.0;
        b_I0[6 * i1 + 4] = 0.0;
        b_I0[I0_tmp + 4] = b_I0_tmp * (double)iv[c_I0_tmp];
        d_I0_tmp = 3 * i1 + 2;
        b_I0[6 * i1 + 2] = Im_data[d_i].f1[d_I0_tmp];
        b_I0[I0_tmp + 2] = 0.0;
        b_I0[6 * i1 + 5] = 0.0;
        b_I0[I0_tmp + 5] = b_I0_tmp * (double)iv[d_I0_tmp];
      }
      memset(&b_Im[0], 0, 6U * sizeof(double));
      memset(&b_Mdot[0], 0, 6U * sizeof(double));
      for (i1 = 0; i1 < 6; i1++) {
        r4 = _mm_loadu_pd(&b_I0[6 * i1]);
        r5 = _mm_loadu_pd(&b_Im[0]);
        I0_tmp = i1 + 6 * d_i;
        r = _mm_set1_pd(tLdot_data[I0_tmp]);
        _mm_storeu_pd(&b_Im[0], _mm_add_pd(r5, _mm_mul_pd(r4, r)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[6 * i1]);
        r6 = _mm_loadu_pd(&b_Mdot[0]);
        r1 = _mm_set1_pd(tL_data[I0_tmp]);
        _mm_storeu_pd(&b_Mdot[0], _mm_add_pd(r6, _mm_mul_pd(r5, r1)));
        I0_tmp = 6 * i1 + 2;
        r4 = _mm_loadu_pd(&b_I0[I0_tmp]);
        r5 = _mm_loadu_pd(&b_Im[2]);
        _mm_storeu_pd(&b_Im[2], _mm_add_pd(r5, _mm_mul_pd(r4, r)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[I0_tmp]);
        r6 = _mm_loadu_pd(&b_Mdot[2]);
        _mm_storeu_pd(&b_Mdot[2], _mm_add_pd(r6, _mm_mul_pd(r5, r1)));
        I0_tmp = 6 * i1 + 4;
        r4 = _mm_loadu_pd(&b_I0[I0_tmp]);
        r5 = _mm_loadu_pd(&b_Im[4]);
        _mm_storeu_pd(&b_Im[4], _mm_add_pd(r5, _mm_mul_pd(r4, r)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[I0_tmp]);
        r6 = _mm_loadu_pd(&b_Mdot[4]);
        _mm_storeu_pd(&b_Mdot[4], _mm_add_pd(r6, _mm_mul_pd(r5, r1)));
      }
      r4 = _mm_loadu_pd(&b_Im[0]);
      r5 = _mm_loadu_pd(&b_Mdot[0]);
      _mm_storeu_pd(
          &wq_data[6 * d_i],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[6 * d_i])));
      r4 = _mm_loadu_pd(&b_Im[2]);
      r5 = _mm_loadu_pd(&b_Mdot[2]);
      c_I0_tmp = 6 * d_i + 2;
      _mm_storeu_pd(
          &wq_data[c_I0_tmp],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[c_I0_tmp])));
      r4 = _mm_loadu_pd(&b_Im[4]);
      r5 = _mm_loadu_pd(&b_Mdot[4]);
      c_I0_tmp = 6 * d_i + 4;
      _mm_storeu_pd(
          &wq_data[c_I0_tmp],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[c_I0_tmp])));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        r4, r5, r6, g_I0_tmp, d2, b_Mdot, b_Im, b_I0, i1, h_I0_tmp, i_I0_tmp,  \
            r7, r8)

    for (d_i = 0; d_i < f_I0_tmp; d_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_I0[6 * i1] = Im_data[d_i].f1[3 * i1];
        h_I0_tmp = 6 * (i1 + 3);
        b_I0[h_I0_tmp] = 0.0;
        b_I0[6 * i1 + 3] = 0.0;
        g_I0_tmp = robotLinks_data[d_i].mass;
        b_I0[h_I0_tmp + 3] = g_I0_tmp * (double)iv[3 * i1];
        i_I0_tmp = 3 * i1 + 1;
        b_I0[6 * i1 + 1] = Im_data[d_i].f1[i_I0_tmp];
        b_I0[h_I0_tmp + 1] = 0.0;
        b_I0[6 * i1 + 4] = 0.0;
        b_I0[h_I0_tmp + 4] = g_I0_tmp * (double)iv[i_I0_tmp];
        i_I0_tmp = 3 * i1 + 2;
        b_I0[6 * i1 + 2] = Im_data[d_i].f1[i_I0_tmp];
        b_I0[h_I0_tmp + 2] = 0.0;
        b_I0[6 * i1 + 5] = 0.0;
        b_I0[h_I0_tmp + 5] = g_I0_tmp * (double)iv[i_I0_tmp];
      }
      memset(&b_Im[0], 0, 6U * sizeof(double));
      memset(&b_Mdot[0], 0, 6U * sizeof(double));
      for (i1 = 0; i1 < 6; i1++) {
        i_I0_tmp = i1 + 6 * d_i;
        d2 = tLdot_data[i_I0_tmp];
        g_I0_tmp = tL_data[i_I0_tmp];
        r4 = _mm_loadu_pd(&b_I0[6 * i1]);
        r7 = _mm_set1_pd(d2);
        r5 = _mm_loadu_pd(&b_Im[0]);
        _mm_storeu_pd(&b_Im[0], _mm_add_pd(r5, _mm_mul_pd(r4, r7)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[6 * i1]);
        r8 = _mm_set1_pd(g_I0_tmp);
        r6 = _mm_loadu_pd(&b_Mdot[0]);
        _mm_storeu_pd(&b_Mdot[0], _mm_add_pd(r6, _mm_mul_pd(r5, r8)));
        i_I0_tmp = 6 * i1 + 2;
        r4 = _mm_loadu_pd(&b_I0[i_I0_tmp]);
        r5 = _mm_loadu_pd(&b_Im[2]);
        _mm_storeu_pd(&b_Im[2], _mm_add_pd(r5, _mm_mul_pd(r4, r7)));
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[i_I0_tmp]);
        r6 = _mm_loadu_pd(&b_Mdot[2]);
        _mm_storeu_pd(&b_Mdot[2], _mm_add_pd(r6, _mm_mul_pd(r5, r8)));
        i_I0_tmp = 6 * i1 + 4;
        r4 = _mm_loadu_pd(&b_I0[i_I0_tmp]);
        r4 = _mm_mul_pd(r4, r7);
        r5 = _mm_loadu_pd(&b_Im[4]);
        r4 = _mm_add_pd(r5, r4);
        _mm_storeu_pd(&b_Im[4], r4);
        r5 = _mm_loadu_pd(&Mdot_data[d_i].f1[i_I0_tmp]);
        r4 = _mm_mul_pd(r5, r8);
        r6 = _mm_loadu_pd(&b_Mdot[4]);
        r4 = _mm_add_pd(r6, r4);
        _mm_storeu_pd(&b_Mdot[4], r4);
      }
      r4 = _mm_loadu_pd(&b_Im[0]);
      r5 = _mm_loadu_pd(&b_Mdot[0]);
      _mm_storeu_pd(
          &wq_data[6 * d_i],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[6 * d_i])));
      r4 = _mm_loadu_pd(&b_Im[2]);
      r5 = _mm_loadu_pd(&b_Mdot[2]);
      i_I0_tmp = 6 * d_i + 2;
      _mm_storeu_pd(
          &wq_data[i_I0_tmp],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[i_I0_tmp])));
      r4 = _mm_loadu_pd(&b_Im[4]);
      r5 = _mm_loadu_pd(&b_Mdot[4]);
      r5 = _mm_add_pd(r4, r5);
      i_I0_tmp = 6 * d_i + 4;
      r4 = _mm_loadu_pd(&wFm_data[i_I0_tmp]);
      r4 = _mm_sub_pd(r5, r4);
      _mm_storeu_pd(&wq_data[i_I0_tmp], r4);
    }
  }
  emxFree_cell_wrap_1(&Mdot);
  /* --- Backward recursion ---% */
  emxInit_real_T(&wq_tilde, 2);
  I0_tmp = wq_tilde->size[0] * wq_tilde->size[1];
  wq_tilde->size[0] = 6;
  wq_tilde->size[1] = i;
  emxEnsureCapacity_real_T(wq_tilde, I0_tmp);
  wq_tilde_data = wq_tilde->data;
  for (c_i = 0; c_i < e_I0_tmp; c_i++) {
    wq_tilde_data[c_i] = 0.0;
  }
  e_I0_tmp = (int)-((-1.0 - nLinksJoints) + 1.0);
  for (e_i = 0; e_i < e_I0_tmp; e_i++) {
    b_I0_tmp = nLinksJoints - (double)e_i;
    for (c_i = 0; c_i < 6; c_i++) {
      I0_tmp = c_i + 6 * ((int)b_I0_tmp - 1);
      wq_tilde_data[I0_tmp] = wq_data[I0_tmp];
    }
    for (b_i = 0; b_i < i; b_i++) {
      if (robotConChild_data[b_i + robotConChild->size[0] *
                                       ((int)b_I0_tmp - 1)] != 0.0) {
        for (c_i = 0; c_i < 6; c_i++) {
          d1 = 0.0;
          for (i2 = 0; i2 < 6; i2++) {
            d1 += Bij_data[b_i + Bij->size[0] * ((int)b_I0_tmp - 1)]
                      .f1[i2 + 6 * c_i] *
                  wq_tilde_data[i2 + 6 * b_i];
          }
          b_Im[c_i] = wq_tilde_data[c_i + 6 * ((int)b_I0_tmp - 1)] + d1;
        }
        for (c_i = 0; c_i < 6; c_i++) {
          wq_tilde_data[c_i + 6 * ((int)b_I0_tmp - 1)] = b_Im[c_i];
        }
      }
    }
  }
  emxFree_real_T(&wq);
  for (b_i = 0; b_i < i; b_i++) {
    if (robotConChildBase_data[b_i] != 0.0) {
      for (c_i = 0; c_i < 6; c_i++) {
        b_I0_tmp = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          b_I0_tmp +=
              Bi0_data[b_i].f1[i2 + 6 * c_i] * wq_tilde_data[i2 + 6 * b_i];
        }
        wq0[c_i] += b_I0_tmp;
      }
    }
  }
  /* --- Joint Forces ---% */
  for (c_i = 0; c_i < 6; c_i++) {
    b_I0_tmp = 0.0;
    for (b_i = 0; b_i < 6; b_i++) {
      b_I0_tmp += P0[b_i + 6 * c_i] * wq0[b_i];
    }
    tau0[c_i] = b_I0_tmp;
  }
  I0_tmp = taum->size[0];
  taum->size[0] = f_I0_tmp;
  emxEnsureCapacity_real_T(taum, I0_tmp);
  wq_data = taum->data;
  for (c_i = 0; c_i < f_I0_tmp; c_i++) {
    wq_data[c_i] = 0.0;
  }
  for (c_i = 0; c_i < i; c_i++) {
    if (robotJoints_data[c_i].type != 0.0) {
      b_I0_tmp = 0.0;
      for (b_i = 0; b_i < 6; b_i++) {
        I0_tmp = b_i + 6 * c_i;
        b_I0_tmp += pm_data[I0_tmp] * wq_tilde_data[I0_tmp];
      }
      wq_data[(int)robotJoints_data[c_i].q_id - 1] = b_I0_tmp;
    }
  }
  emxFree_real_T(&wq_tilde);
}

/*
 * File trailer for ID_C.c
 *
 * [EOF]
 */
