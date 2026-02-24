/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FD_C.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

/* Include Files */
#include "FD_C.h"
#include "SPART_C_data.h"
#include "SPART_C_emxutil.h"
#include "SPART_C_initialize.h"
#include "SPART_C_types.h"
#include "mldivide.h"
#include "omp.h"
#include <emmintrin.h>
#include <string.h>

/* Function Declarations */
static void minus(emxArray_real_T *in1, const emxArray_real_T *in2);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
static void minus(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  double *b_in2_data;
  double *in1_data;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in2, 1);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  stride_0_0 = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in2, stride_0_0);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in1->size[0] != 1);
  if (loop_ub < 1600) {
    for (i = 0; i < loop_ub; i++) {
      b_in2_data[i] = in2_data[i * stride_0_0] - in1_data[i * stride_1_0];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (i = 0; i < loop_ub; i++) {
      b_in2_data[i] = in2_data[i * stride_0_0] - in1_data[i * stride_1_0];
    }
  }
  stride_0_0 = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, stride_0_0);
  in1_data = in1->data;
  for (i1 = 0; i1 < loop_ub; i1++) {
    in1_data[i1] = b_in2_data[i1];
  }
  emxFree_real_T(&b_in2);
}

/*
 * Arguments    : const double tau0[6]
 *                const emxArray_real_T *taum
 *                const double wF0[6]
 *                const emxArray_real_T *wFm
 *                const double t0[6]
 *                const emxArray_real_T *b_tm
 *                const double P0[36]
 *                const emxArray_real_T *pm
 *                const double I0[9]
 *                const emxArray_cell_wrap_2 *Im
 *                const emxArray_cell_wrap_1 *Bij
 *                const emxArray_cell_wrap_1 *Bi0
 *                const double u0[6]
 *                const emxArray_real_T *um
 *                double nLinksJoints
 *                double nQ
 *                const struct2_T *robotBaseLink
 *                const emxArray_struct1_T *robotLinks
 *                const emxArray_real_T *robotConChild
 *                const emxArray_real_T *robotConChildBase
 *                const emxArray_struct0_T *robotJoints
 *                double u0dot[6]
 *                emxArray_real_T *umdot
 * Return Type  : void
 */
void FD_C(const double tau0[6], const emxArray_real_T *taum,
          const double wF0[6], const emxArray_real_T *wFm, const double t0[6],
          const emxArray_real_T *b_tm, const double P0[36],
          const emxArray_real_T *pm, const double I0[9],
          const emxArray_cell_wrap_2 *Im, const emxArray_cell_wrap_1 *Bij,
          const emxArray_cell_wrap_1 *Bi0, const double u0[6],
          const emxArray_real_T *um, double nLinksJoints, double nQ,
          const struct2_T *robotBaseLink, const emxArray_struct1_T *robotLinks,
          const emxArray_real_T *robotConChild,
          const emxArray_real_T *robotConChildBase,
          const emxArray_struct0_T *robotJoints, double u0dot[6],
          emxArray_real_T *umdot)
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  __m128d r3;
  __m128d r4;
  __m128d r5;
  __m128d r6;
  __m128d r7;
  __m128d r8;
  const cell_wrap_1 *Bi0_data;
  const cell_wrap_1 *Bij_data;
  cell_wrap_1 *Omegam_data;
  const cell_wrap_2 *Im_data;
  cell_wrap_3 *eta_data;
  cell_wrap_3 *psi_data;
  cell_wrap_3 *psi_hat_data;
  emxArray_cell_wrap_1 *Mdot;
  emxArray_cell_wrap_1 *Omegam;
  emxArray_cell_wrap_1 *b_M_hat;
  emxArray_cell_wrap_3 *eta;
  emxArray_cell_wrap_3 *psi;
  emxArray_cell_wrap_3 *psi_hat;
  emxArray_real_T *phi;
  emxArray_real_T *phi_hat;
  emxArray_real_T *phi_tilde;
  emxArray_real_T *wq;
  emxArray_real_T *wq_tilde;
  const struct0_T *robotJoints_data;
  const struct1_T *robotLinks_data;
  double M_hat[36];
  double M_hat0[36];
  double b_Im[36];
  double tau0_0ddot_tmp[36];
  double dv[9];
  double skew_omega[9];
  double b_Mdot[6];
  double b_P0[6];
  double eta0[6];
  double wq0[6];
  double x[3];
  const double *pm_data;
  const double *robotConChildBase_data;
  const double *robotConChild_data;
  const double *taum_data;
  const double *tm_data;
  const double *um_data;
  const double *wFm_data;
  double Im_tmp;
  double b_i;
  double c_Im_tmp;
  double d1;
  double *phi_data;
  double *wq_data;
  double *wq_tilde_data;
  int M_hat0_tmp;
  int M_hat_tmp;
  int b_Im_tmp;
  int b_M_hat0_tmp;
  int b_loop_ub;
  int c_i;
  int c_loop_ub;
  int d_Im_tmp;
  int d_i;
  int e_Im_tmp;
  int e_i;
  int f_i;
  int g_i;
  int i;
  int j;
  int loop_ub;
  int vectorUB;
  if (!isInitialized_SPART_C) {
    SPART_C_initialize();
  }
  robotJoints_data = robotJoints->data;
  robotConChildBase_data = robotConChildBase->data;
  robotConChild_data = robotConChild->data;
  robotLinks_data = robotLinks->data;
  um_data = um->data;
  Bi0_data = Bi0->data;
  Bij_data = Bij->data;
  Im_data = Im->data;
  pm_data = pm->data;
  tm_data = b_tm->data;
  wFm_data = wFm->data;
  taum_data = taum->data;
  /* === Inverse Dynamics with zero accelerations ===% */
  /*  Computes operational-space accelerations (twist-rate). */
  /*  */
  /*  All 3D matrices (Bi0, Bij, Omegam) are replaced with cell arrays for */
  /*  code-generation compatibility. */
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
  M_hat_tmp = Omegam->size[0] * Omegam->size[1];
  Omegam->size[0] = 1;
  loop_ub = (int)nLinksJoints;
  Omegam->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(Omegam, M_hat_tmp);
  Omegam_data = Omegam->data;
  /*  Compute Omega for manipulator links */
  if ((int)nLinksJoints - 1 >= 0) {
    skew_omega[0] = 0.0;
    skew_omega[4] = 0.0;
    skew_omega[8] = 0.0;
  }
  for (i = 0; i < loop_ub; i++) {
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
    Im_tmp = tm_data[6 * i + 2];
    skew_omega[3] = -Im_tmp;
    b_i = tm_data[6 * i + 1];
    skew_omega[6] = b_i;
    skew_omega[1] = Im_tmp;
    Im_tmp = tm_data[6 * i];
    skew_omega[7] = -Im_tmp;
    skew_omega[2] = -b_i;
    skew_omega[5] = Im_tmp;
    for (c_i = 0; c_i < 3; c_i++) {
      Im_tmp = skew_omega[3 * c_i];
      Omegam_data[i].f1[6 * c_i] = Im_tmp;
      M_hat_tmp = 6 * (c_i + 3);
      Omegam_data[i].f1[M_hat_tmp] = 0.0;
      Omegam_data[i].f1[6 * c_i + 3] = 0.0;
      Omegam_data[i].f1[M_hat_tmp + 3] = Im_tmp;
      Im_tmp = skew_omega[3 * c_i + 1];
      Omegam_data[i].f1[6 * c_i + 1] = Im_tmp;
      Omegam_data[i].f1[M_hat_tmp + 1] = 0.0;
      Omegam_data[i].f1[6 * c_i + 4] = 0.0;
      Omegam_data[i].f1[M_hat_tmp + 4] = Im_tmp;
      Im_tmp = skew_omega[3 * c_i + 2];
      Omegam_data[i].f1[6 * c_i + 2] = Im_tmp;
      Omegam_data[i].f1[M_hat_tmp + 2] = 0.0;
      Omegam_data[i].f1[6 * c_i + 5] = 0.0;
      Omegam_data[i].f1[M_hat_tmp + 5] = Im_tmp;
    }
  }
  /* --- Twist Rate ---% */
  /*  Base-link acceleration */
  M_hat[0] = 0.0;
  M_hat[6] = -t0[2];
  M_hat[12] = t0[1];
  M_hat[1] = t0[2];
  M_hat[7] = 0.0;
  M_hat[13] = -t0[0];
  M_hat[2] = -t0[1];
  M_hat[8] = t0[0];
  M_hat[14] = 0.0;
  for (i = 0; i < 3; i++) {
    M_hat_tmp = 6 * (i + 3);
    M_hat[M_hat_tmp] = 0.0;
    M_hat[M_hat_tmp + 1] = 0.0;
    M_hat[M_hat_tmp + 2] = 0.0;
  }
  for (i = 0; i < 6; i++) {
    M_hat[6 * i + 3] = 0.0;
    M_hat[6 * i + 4] = 0.0;
    M_hat[6 * i + 5] = 0.0;
  }
  memset(&b_Im[0], 0, 36U * sizeof(double));
  memset(&eta0[0], 0, 6U * sizeof(double));
  memset(&b_P0[0], 0, 6U * sizeof(double));
  r = _mm_set1_pd(0.0);
  for (j = 0; j < 6; j++) {
    M_hat_tmp = 6 * j + 2;
    vectorUB = 6 * j + 4;
    for (i = 0; i < 6; i++) {
      r2 = _mm_loadu_pd(&M_hat[6 * i]);
      r1 = _mm_loadu_pd(&b_Im[6 * j]);
      r3 = _mm_set1_pd(P0[i + 6 * j]);
      _mm_storeu_pd(&b_Im[6 * j], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      r2 = _mm_loadu_pd(&M_hat[6 * i + 2]);
      r1 = _mm_loadu_pd(&b_Im[M_hat_tmp]);
      _mm_storeu_pd(&b_Im[M_hat_tmp], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      r2 = _mm_loadu_pd(&M_hat[6 * i + 4]);
      r1 = _mm_loadu_pd(&b_Im[vectorUB]);
      _mm_storeu_pd(&b_Im[vectorUB], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    }
    r2 = _mm_loadu_pd(&b_Im[6 * j]);
    r1 = _mm_loadu_pd(&eta0[0]);
    r3 = _mm_set1_pd(u0[j]);
    _mm_storeu_pd(&eta0[0], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    r1 = _mm_loadu_pd(&b_P0[0]);
    _mm_storeu_pd(&b_P0[0],
                  _mm_add_pd(r1, _mm_mul_pd(_mm_loadu_pd(&P0[6 * j]), r)));
    M_hat_tmp = 6 * j + 2;
    r2 = _mm_loadu_pd(&b_Im[M_hat_tmp]);
    r1 = _mm_loadu_pd(&eta0[2]);
    _mm_storeu_pd(&eta0[2], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    r1 = _mm_loadu_pd(&b_P0[2]);
    _mm_storeu_pd(&b_P0[2],
                  _mm_add_pd(r1, _mm_mul_pd(_mm_loadu_pd(&P0[M_hat_tmp]), r)));
    M_hat_tmp = 6 * j + 4;
    r2 = _mm_loadu_pd(&b_Im[M_hat_tmp]);
    r1 = _mm_loadu_pd(&eta0[4]);
    _mm_storeu_pd(&eta0[4], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    r1 = _mm_loadu_pd(&b_P0[4]);
    _mm_storeu_pd(&b_P0[4],
                  _mm_add_pd(r1, _mm_mul_pd(_mm_loadu_pd(&P0[M_hat_tmp]), r)));
  }
  r1 = _mm_loadu_pd(&eta0[0]);
  r2 = _mm_loadu_pd(&b_P0[0]);
  _mm_storeu_pd(&eta0[0], _mm_add_pd(r1, r2));
  r1 = _mm_loadu_pd(&eta0[2]);
  r2 = _mm_loadu_pd(&b_P0[2]);
  _mm_storeu_pd(&eta0[2], _mm_add_pd(r1, r2));
  r1 = _mm_loadu_pd(&eta0[4]);
  r2 = _mm_loadu_pd(&b_P0[4]);
  _mm_storeu_pd(&eta0[4], _mm_add_pd(r1, r2));
  /*  Pre-allocate for manipulator */
  emxInit_real_T(&wq_tilde, 2);
  M_hat_tmp = wq_tilde->size[0] * wq_tilde->size[1];
  wq_tilde->size[0] = 6;
  wq_tilde->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(wq_tilde, M_hat_tmp);
  wq_tilde_data = wq_tilde->data;
  b_loop_ub = 6 * (int)nLinksJoints;
  for (i = 0; i < b_loop_ub; i++) {
    wq_tilde_data[i] = 0.0;
  }
  /*  Forward recursion */
  for (c_i = 0; c_i < loop_ub; c_i++) {
    Im_tmp = robotJoints_data[c_i].parent_link;
    if (robotJoints_data[c_i].parent_link == 0.0) {
      /*  First link (connected to base) */
      _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&t0[3]),
                                      _mm_loadu_pd(&tm_data[6 * c_i + 3])));
      x[2] = t0[5] - tm_data[6 * c_i + 5];
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
      for (i = 0; i < 6; i++) {
        M_hat[6 * i] = 0.0;
        M_hat[6 * i + 1] = 0.0;
        M_hat[6 * i + 2] = 0.0;
      }
      M_hat[3] = 0.0;
      M_hat[9] = -x[2];
      M_hat[15] = x[1];
      M_hat[4] = x[2];
      M_hat[10] = 0.0;
      M_hat[16] = -x[0];
      M_hat[5] = -x[1];
      M_hat[11] = x[0];
      M_hat[17] = 0.0;
      for (i = 0; i < 3; i++) {
        M_hat_tmp = 6 * (i + 3);
        M_hat[M_hat_tmp + 3] = 0.0;
        M_hat[M_hat_tmp + 4] = 0.0;
        M_hat[M_hat_tmp + 5] = 0.0;
      }
      memset(&b_P0[0], 0, 6U * sizeof(double));
      memset(&b_Mdot[0], 0, 6U * sizeof(double));
      for (i = 0; i < 6; i++) {
        r2 = _mm_loadu_pd(&b_P0[0]);
        r3 = _mm_set1_pd(eta0[i]);
        _mm_storeu_pd(
            &b_P0[0],
            _mm_add_pd(r2,
                       _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[6 * i]), r3)));
        r2 = _mm_loadu_pd(&M_hat[6 * i]);
        r1 = _mm_loadu_pd(&b_Mdot[0]);
        r = _mm_set1_pd(t0[i]);
        _mm_storeu_pd(&b_Mdot[0], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
        r2 = _mm_loadu_pd(&b_P0[2]);
        M_hat_tmp = 6 * i + 2;
        _mm_storeu_pd(
            &b_P0[2],
            _mm_add_pd(
                r2,
                _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[M_hat_tmp]), r3)));
        r2 = _mm_loadu_pd(&M_hat[M_hat_tmp]);
        r1 = _mm_loadu_pd(&b_Mdot[2]);
        _mm_storeu_pd(&b_Mdot[2], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
        r2 = _mm_loadu_pd(&b_P0[4]);
        M_hat_tmp = 6 * i + 4;
        _mm_storeu_pd(
            &b_P0[4],
            _mm_add_pd(
                r2,
                _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[M_hat_tmp]), r3)));
        r2 = _mm_loadu_pd(&M_hat[M_hat_tmp]);
        r1 = _mm_loadu_pd(&b_Mdot[4]);
        _mm_storeu_pd(&b_Mdot[4], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
      }
      r1 = _mm_loadu_pd(&b_P0[0]);
      r2 = _mm_loadu_pd(&b_Mdot[0]);
      _mm_storeu_pd(&wq_tilde_data[6 * c_i], _mm_add_pd(r1, r2));
      r1 = _mm_loadu_pd(&b_P0[2]);
      r2 = _mm_loadu_pd(&b_Mdot[2]);
      _mm_storeu_pd(&wq_tilde_data[6 * c_i + 2], _mm_add_pd(r1, r2));
      r1 = _mm_loadu_pd(&b_P0[4]);
      r2 = _mm_loadu_pd(&b_Mdot[4]);
      _mm_storeu_pd(&wq_tilde_data[6 * c_i + 4], _mm_add_pd(r1, r2));
    } else {
      vectorUB = (int)robotJoints_data[c_i].parent_link - 1;
      M_hat_tmp = 6 * ((int)Im_tmp - 1);
      _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&tm_data[M_hat_tmp + 3]),
                                      _mm_loadu_pd(&tm_data[6 * c_i + 3])));
      x[2] = tm_data[M_hat_tmp + 5] - tm_data[6 * c_i + 5];
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
      for (i = 0; i < 6; i++) {
        M_hat[6 * i] = 0.0;
        M_hat[6 * i + 1] = 0.0;
        M_hat[6 * i + 2] = 0.0;
      }
      M_hat[3] = 0.0;
      M_hat[9] = -x[2];
      M_hat[15] = x[1];
      M_hat[4] = x[2];
      M_hat[10] = 0.0;
      M_hat[16] = -x[0];
      M_hat[5] = -x[1];
      M_hat[11] = x[0];
      M_hat[17] = 0.0;
      for (i = 0; i < 3; i++) {
        M_hat_tmp = 6 * (i + 3);
        M_hat[M_hat_tmp + 3] = 0.0;
        M_hat[M_hat_tmp + 4] = 0.0;
        M_hat[M_hat_tmp + 5] = 0.0;
      }
      memset(&b_P0[0], 0, 6U * sizeof(double));
      memset(&b_Mdot[0], 0, 6U * sizeof(double));
      for (i = 0; i < 6; i++) {
        r2 = _mm_loadu_pd(&b_P0[0]);
        M_hat_tmp = i + 6 * vectorUB;
        r3 = _mm_set1_pd(wq_tilde_data[M_hat_tmp]);
        _mm_storeu_pd(
            &b_P0[0],
            _mm_add_pd(
                r2,
                _mm_mul_pd(_mm_loadu_pd(
                               &Bij_data[c_i + Bij->size[0] * ((int)Im_tmp - 1)]
                                    .f1[6 * i]),
                           r3)));
        r2 = _mm_loadu_pd(&M_hat[6 * i]);
        r1 = _mm_loadu_pd(&b_Mdot[0]);
        r = _mm_set1_pd(tm_data[M_hat_tmp]);
        _mm_storeu_pd(&b_Mdot[0], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
        r2 = _mm_loadu_pd(&b_P0[2]);
        M_hat_tmp = 6 * i + 2;
        _mm_storeu_pd(
            &b_P0[2],
            _mm_add_pd(
                r2,
                _mm_mul_pd(_mm_loadu_pd(
                               &Bij_data[c_i + Bij->size[0] * ((int)Im_tmp - 1)]
                                    .f1[M_hat_tmp]),
                           r3)));
        r2 = _mm_loadu_pd(&M_hat[M_hat_tmp]);
        r1 = _mm_loadu_pd(&b_Mdot[2]);
        _mm_storeu_pd(&b_Mdot[2], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
        r2 = _mm_loadu_pd(&b_P0[4]);
        M_hat_tmp = 6 * i + 4;
        _mm_storeu_pd(
            &b_P0[4],
            _mm_add_pd(
                r2,
                _mm_mul_pd(_mm_loadu_pd(
                               &Bij_data[c_i + Bij->size[0] * ((int)Im_tmp - 1)]
                                    .f1[M_hat_tmp]),
                           r3)));
        r2 = _mm_loadu_pd(&M_hat[M_hat_tmp]);
        r1 = _mm_loadu_pd(&b_Mdot[4]);
        _mm_storeu_pd(&b_Mdot[4], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
      }
      r1 = _mm_loadu_pd(&b_P0[0]);
      r2 = _mm_loadu_pd(&b_Mdot[0]);
      _mm_storeu_pd(&wq_tilde_data[6 * c_i], _mm_add_pd(r1, r2));
      r1 = _mm_loadu_pd(&b_P0[2]);
      r2 = _mm_loadu_pd(&b_Mdot[2]);
      _mm_storeu_pd(&wq_tilde_data[6 * c_i + 2], _mm_add_pd(r1, r2));
      r1 = _mm_loadu_pd(&b_P0[4]);
      r2 = _mm_loadu_pd(&b_Mdot[4]);
      _mm_storeu_pd(&wq_tilde_data[6 * c_i + 4], _mm_add_pd(r1, r2));
    }
    /*  Add joint contribution */
    if (robotJoints_data[c_i].type != 0.0) {
      memset(&b_P0[0], 0, 6U * sizeof(double));
      for (i = 0; i < 6; i++) {
        r2 = _mm_loadu_pd(&Omegam_data[c_i].f1[6 * i]);
        r1 = _mm_loadu_pd(&b_P0[0]);
        r3 = _mm_set1_pd(pm_data[i + 6 * c_i]);
        _mm_storeu_pd(&b_P0[0], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
        r2 = _mm_loadu_pd(&Omegam_data[c_i].f1[6 * i + 2]);
        r1 = _mm_loadu_pd(&b_P0[2]);
        _mm_storeu_pd(&b_P0[2], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
        r2 = _mm_loadu_pd(&Omegam_data[c_i].f1[6 * i + 4]);
        r1 = _mm_loadu_pd(&b_P0[4]);
        _mm_storeu_pd(&b_P0[4], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      }
      r2 = _mm_loadu_pd(&b_P0[0]);
      r1 = _mm_loadu_pd(&wq_tilde_data[6 * c_i]);
      r3 = _mm_set1_pd(um_data[(int)robotJoints_data[c_i].q_id - 1]);
      r = _mm_set1_pd(0.0);
      _mm_storeu_pd(&wq_tilde_data[6 * c_i],
                    _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(r2, r3)),
                               _mm_mul_pd(_mm_loadu_pd(&pm_data[6 * c_i]), r)));
      r2 = _mm_loadu_pd(&b_P0[2]);
      M_hat_tmp = 6 * c_i + 2;
      r1 = _mm_loadu_pd(&wq_tilde_data[M_hat_tmp]);
      _mm_storeu_pd(
          &wq_tilde_data[M_hat_tmp],
          _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(r2, r3)),
                     _mm_mul_pd(_mm_loadu_pd(&pm_data[M_hat_tmp]), r)));
      r2 = _mm_loadu_pd(&b_P0[4]);
      M_hat_tmp = 6 * c_i + 4;
      r1 = _mm_loadu_pd(&wq_tilde_data[M_hat_tmp]);
      _mm_storeu_pd(
          &wq_tilde_data[M_hat_tmp],
          _mm_add_pd(_mm_add_pd(r1, _mm_mul_pd(r2, r3)),
                     _mm_mul_pd(_mm_loadu_pd(&pm_data[M_hat_tmp]), r)));
    }
  }
  emxFree_cell_wrap_1(&Omegam);
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
  M_hat_tmp = Mdot->size[0] * Mdot->size[1];
  Mdot->size[0] = 1;
  Mdot->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(Mdot, M_hat_tmp);
  Omegam_data = Mdot->data;
  if ((int)nLinksJoints - 1 >= 0) {
    skew_omega[0] = 0.0;
    skew_omega[4] = 0.0;
    skew_omega[8] = 0.0;
  }
  for (c_i = 0; c_i < loop_ub; c_i++) {
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
    Im_tmp = tm_data[6 * c_i + 2];
    skew_omega[3] = -Im_tmp;
    d = tm_data[6 * c_i + 1];
    skew_omega[6] = d;
    skew_omega[1] = Im_tmp;
    Im_tmp = tm_data[6 * c_i];
    skew_omega[7] = -Im_tmp;
    skew_omega[2] = -d;
    skew_omega[5] = Im_tmp;
    memset(&dv[0], 0, 9U * sizeof(double));
    for (i = 0; i < 3; i++) {
      b_i = Im_data[c_i].f1[3 * i];
      r1 = _mm_loadu_pd(&skew_omega[0]);
      r2 = _mm_loadu_pd(&dv[3 * i]);
      _mm_storeu_pd(&dv[3 * i],
                    _mm_add_pd(r2, _mm_mul_pd(r1, _mm_set1_pd(b_i))));
      M_hat_tmp = 3 * i + 2;
      dv[M_hat_tmp] += -d * b_i;
      vectorUB = 3 * i + 1;
      b_i = Im_data[c_i].f1[vectorUB];
      r1 = _mm_loadu_pd(&skew_omega[3]);
      r2 = _mm_loadu_pd(&dv[3 * i]);
      _mm_storeu_pd(&dv[3 * i],
                    _mm_add_pd(r2, _mm_mul_pd(r1, _mm_set1_pd(b_i))));
      dv[M_hat_tmp] += Im_tmp * b_i;
      b_i = Im_data[c_i].f1[M_hat_tmp];
      r1 = _mm_loadu_pd(&skew_omega[6]);
      r2 = _mm_loadu_pd(&dv[3 * i]);
      _mm_storeu_pd(&dv[3 * i],
                    _mm_add_pd(r2, _mm_mul_pd(r1, _mm_set1_pd(b_i))));
      dv[M_hat_tmp] += 0.0 * b_i;
      Omegam_data[c_i].f1[6 * i] = dv[3 * i];
      b_Im_tmp = 6 * (i + 3);
      Omegam_data[c_i].f1[b_Im_tmp] = 0.0;
      Omegam_data[c_i].f1[6 * i + 1] = dv[vectorUB];
      Omegam_data[c_i].f1[b_Im_tmp + 1] = 0.0;
      Omegam_data[c_i].f1[6 * i + 2] = dv[M_hat_tmp];
      Omegam_data[c_i].f1[b_Im_tmp + 2] = 0.0;
    }
    for (i = 0; i < 6; i++) {
      Omegam_data[c_i].f1[6 * i + 3] = 0.0;
      Omegam_data[c_i].f1[6 * i + 4] = 0.0;
      Omegam_data[c_i].f1[6 * i + 5] = 0.0;
    }
  }
  /* --- Forces ---% */
  skew_omega[0] = 0.0;
  skew_omega[3] = -t0[2];
  skew_omega[6] = t0[1];
  skew_omega[1] = t0[2];
  skew_omega[4] = 0.0;
  skew_omega[7] = -t0[0];
  skew_omega[2] = -t0[1];
  skew_omega[5] = t0[0];
  skew_omega[8] = 0.0;
  memset(&dv[0], 0, 9U * sizeof(double));
  for (i = 0; i < 3; i++) {
    Im_tmp = I0[3 * i];
    M_hat0[6 * i] = Im_tmp;
    M_hat_tmp = 6 * (i + 3);
    M_hat0[M_hat_tmp] = 0.0;
    M_hat0[6 * i + 3] = 0.0;
    M_hat0[M_hat_tmp + 3] = robotBaseLink->mass * (double)iv[3 * i];
    r1 = _mm_loadu_pd(&skew_omega[0]);
    r2 = _mm_loadu_pd(&dv[3 * i]);
    _mm_storeu_pd(&dv[3 * i],
                  _mm_add_pd(r2, _mm_mul_pd(r1, _mm_set1_pd(Im_tmp))));
    b_Im_tmp = 3 * i + 2;
    dv[b_Im_tmp] += skew_omega[2] * Im_tmp;
    vectorUB = 3 * i + 1;
    Im_tmp = I0[vectorUB];
    M_hat0_tmp = 6 * i + 1;
    M_hat0[M_hat0_tmp] = Im_tmp;
    M_hat0[M_hat_tmp + 1] = 0.0;
    M_hat0[6 * i + 4] = 0.0;
    M_hat0[M_hat_tmp + 4] = robotBaseLink->mass * (double)iv[vectorUB];
    r1 = _mm_loadu_pd(&skew_omega[3]);
    r2 = _mm_loadu_pd(&dv[3 * i]);
    _mm_storeu_pd(&dv[3 * i],
                  _mm_add_pd(r2, _mm_mul_pd(r1, _mm_set1_pd(Im_tmp))));
    dv[b_Im_tmp] += skew_omega[5] * Im_tmp;
    Im_tmp = I0[b_Im_tmp];
    b_M_hat0_tmp = 6 * i + 2;
    M_hat0[b_M_hat0_tmp] = Im_tmp;
    M_hat0[M_hat_tmp + 2] = 0.0;
    M_hat0[6 * i + 5] = 0.0;
    M_hat0[M_hat_tmp + 5] = robotBaseLink->mass * (double)iv[b_Im_tmp];
    r1 = _mm_loadu_pd(&skew_omega[6]);
    r2 = _mm_loadu_pd(&dv[3 * i]);
    _mm_storeu_pd(&dv[3 * i],
                  _mm_add_pd(r2, _mm_mul_pd(r1, _mm_set1_pd(Im_tmp))));
    dv[b_Im_tmp] += 0.0 * Im_tmp;
    M_hat[6 * i] = dv[3 * i];
    M_hat[M_hat_tmp] = 0.0;
    M_hat[M_hat0_tmp] = dv[vectorUB];
    M_hat[M_hat_tmp + 1] = 0.0;
    M_hat[b_M_hat0_tmp] = dv[b_Im_tmp];
    M_hat[M_hat_tmp + 2] = 0.0;
  }
  memset(&wq0[0], 0, 6U * sizeof(double));
  memset(&b_Mdot[0], 0, 6U * sizeof(double));
  for (i = 0; i < 6; i++) {
    M_hat[6 * i + 3] = 0.0;
    M_hat_tmp = 6 * i + 4;
    M_hat[M_hat_tmp] = 0.0;
    M_hat[6 * i + 5] = 0.0;
    r2 = _mm_loadu_pd(&M_hat0[6 * i]);
    r1 = _mm_loadu_pd(&wq0[0]);
    r3 = _mm_set1_pd(eta0[i]);
    _mm_storeu_pd(&wq0[0], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    r2 = _mm_loadu_pd(&M_hat[6 * i]);
    r1 = _mm_loadu_pd(&b_Mdot[0]);
    r = _mm_set1_pd(t0[i]);
    _mm_storeu_pd(&b_Mdot[0], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
    vectorUB = 6 * i + 2;
    r2 = _mm_loadu_pd(&M_hat0[vectorUB]);
    r1 = _mm_loadu_pd(&wq0[2]);
    _mm_storeu_pd(&wq0[2], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    r2 = _mm_loadu_pd(&M_hat[vectorUB]);
    r1 = _mm_loadu_pd(&b_Mdot[2]);
    _mm_storeu_pd(&b_Mdot[2], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
    r2 = _mm_loadu_pd(&M_hat0[M_hat_tmp]);
    r1 = _mm_loadu_pd(&wq0[4]);
    _mm_storeu_pd(&wq0[4], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    r2 = _mm_loadu_pd(&M_hat[M_hat_tmp]);
    r1 = _mm_loadu_pd(&b_Mdot[4]);
    _mm_storeu_pd(&b_Mdot[4], _mm_add_pd(r1, _mm_mul_pd(r2, r)));
  }
  r1 = _mm_loadu_pd(&wq0[0]);
  r2 = _mm_loadu_pd(&b_Mdot[0]);
  _mm_storeu_pd(&wq0[0], _mm_sub_pd(_mm_add_pd(r1, r2), _mm_loadu_pd(&wF0[0])));
  r1 = _mm_loadu_pd(&wq0[2]);
  r2 = _mm_loadu_pd(&b_Mdot[2]);
  _mm_storeu_pd(&wq0[2], _mm_sub_pd(_mm_add_pd(r1, r2), _mm_loadu_pd(&wF0[2])));
  r1 = _mm_loadu_pd(&wq0[4]);
  r2 = _mm_loadu_pd(&b_Mdot[4]);
  _mm_storeu_pd(&wq0[4], _mm_sub_pd(_mm_add_pd(r1, r2), _mm_loadu_pd(&wF0[4])));
  emxInit_real_T(&wq, 2);
  M_hat_tmp = wq->size[0] * wq->size[1];
  wq->size[0] = 6;
  wq->size[1] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(wq, M_hat_tmp);
  wq_data = wq->data;
  for (i = 0; i < b_loop_ub; i++) {
    wq_data[i] = 0.0;
  }
  c_loop_ub = (int)nQ;
  if ((int)nQ * 12 < 1600) {
    for (d_i = 0; d_i < c_loop_ub; d_i++) {
      for (e_i = 0; e_i < 3; e_i++) {
        b_Im[6 * e_i] = Im_data[d_i].f1[3 * e_i];
        b_Im_tmp = 6 * (e_i + 3);
        b_Im[b_Im_tmp] = 0.0;
        b_Im[6 * e_i + 3] = 0.0;
        Im_tmp = robotLinks_data[d_i].mass;
        b_Im[b_Im_tmp + 3] = Im_tmp * (double)iv[3 * e_i];
        M_hat_tmp = 3 * e_i + 1;
        b_Im[6 * e_i + 1] = Im_data[d_i].f1[M_hat_tmp];
        b_Im[b_Im_tmp + 1] = 0.0;
        b_Im[6 * e_i + 4] = 0.0;
        b_Im[b_Im_tmp + 4] = Im_tmp * (double)iv[M_hat_tmp];
        M_hat_tmp = 3 * e_i + 2;
        b_Im[6 * e_i + 2] = Im_data[d_i].f1[M_hat_tmp];
        b_Im[b_Im_tmp + 2] = 0.0;
        b_Im[6 * e_i + 5] = 0.0;
        b_Im[b_Im_tmp + 5] = Im_tmp * (double)iv[M_hat_tmp];
      }
      memset(&b_P0[0], 0, 6U * sizeof(double));
      memset(&b_Mdot[0], 0, 6U * sizeof(double));
      for (e_i = 0; e_i < 6; e_i++) {
        r4 = _mm_loadu_pd(&b_Im[6 * e_i]);
        r5 = _mm_loadu_pd(&b_P0[0]);
        M_hat_tmp = e_i + 6 * d_i;
        r2 = _mm_set1_pd(wq_tilde_data[M_hat_tmp]);
        _mm_storeu_pd(&b_P0[0], _mm_add_pd(r5, _mm_mul_pd(r4, r2)));
        r5 = _mm_loadu_pd(&Omegam_data[d_i].f1[6 * e_i]);
        r6 = _mm_loadu_pd(&b_Mdot[0]);
        r1 = _mm_set1_pd(tm_data[M_hat_tmp]);
        _mm_storeu_pd(&b_Mdot[0], _mm_add_pd(r6, _mm_mul_pd(r5, r1)));
        M_hat_tmp = 6 * e_i + 2;
        r4 = _mm_loadu_pd(&b_Im[M_hat_tmp]);
        r5 = _mm_loadu_pd(&b_P0[2]);
        _mm_storeu_pd(&b_P0[2], _mm_add_pd(r5, _mm_mul_pd(r4, r2)));
        r5 = _mm_loadu_pd(&Omegam_data[d_i].f1[M_hat_tmp]);
        r6 = _mm_loadu_pd(&b_Mdot[2]);
        _mm_storeu_pd(&b_Mdot[2], _mm_add_pd(r6, _mm_mul_pd(r5, r1)));
        M_hat_tmp = 6 * e_i + 4;
        r4 = _mm_loadu_pd(&b_Im[M_hat_tmp]);
        r5 = _mm_loadu_pd(&b_P0[4]);
        _mm_storeu_pd(&b_P0[4], _mm_add_pd(r5, _mm_mul_pd(r4, r2)));
        r5 = _mm_loadu_pd(&Omegam_data[d_i].f1[M_hat_tmp]);
        r6 = _mm_loadu_pd(&b_Mdot[4]);
        _mm_storeu_pd(&b_Mdot[4], _mm_add_pd(r6, _mm_mul_pd(r5, r1)));
      }
      r4 = _mm_loadu_pd(&b_P0[0]);
      r5 = _mm_loadu_pd(&b_Mdot[0]);
      _mm_storeu_pd(
          &wq_data[6 * d_i],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[6 * d_i])));
      r4 = _mm_loadu_pd(&b_P0[2]);
      r5 = _mm_loadu_pd(&b_Mdot[2]);
      M_hat_tmp = 6 * d_i + 2;
      _mm_storeu_pd(
          &wq_data[M_hat_tmp],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[M_hat_tmp])));
      r4 = _mm_loadu_pd(&b_P0[4]);
      r5 = _mm_loadu_pd(&b_Mdot[4]);
      M_hat_tmp = 6 * d_i + 4;
      _mm_storeu_pd(
          &wq_data[M_hat_tmp],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[M_hat_tmp])));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        r4, r5, r6, c_Im_tmp, d1, b_Mdot, b_P0, b_Im, e_i, d_Im_tmp, e_Im_tmp, \
            r7, r8)

    for (d_i = 0; d_i < c_loop_ub; d_i++) {
      for (e_i = 0; e_i < 3; e_i++) {
        b_Im[6 * e_i] = Im_data[d_i].f1[3 * e_i];
        d_Im_tmp = 6 * (e_i + 3);
        b_Im[d_Im_tmp] = 0.0;
        b_Im[6 * e_i + 3] = 0.0;
        c_Im_tmp = robotLinks_data[d_i].mass;
        b_Im[d_Im_tmp + 3] = c_Im_tmp * (double)iv[3 * e_i];
        e_Im_tmp = 3 * e_i + 1;
        b_Im[6 * e_i + 1] = Im_data[d_i].f1[e_Im_tmp];
        b_Im[d_Im_tmp + 1] = 0.0;
        b_Im[6 * e_i + 4] = 0.0;
        b_Im[d_Im_tmp + 4] = c_Im_tmp * (double)iv[e_Im_tmp];
        e_Im_tmp = 3 * e_i + 2;
        b_Im[6 * e_i + 2] = Im_data[d_i].f1[e_Im_tmp];
        b_Im[d_Im_tmp + 2] = 0.0;
        b_Im[6 * e_i + 5] = 0.0;
        b_Im[d_Im_tmp + 5] = c_Im_tmp * (double)iv[e_Im_tmp];
      }
      memset(&b_P0[0], 0, 6U * sizeof(double));
      memset(&b_Mdot[0], 0, 6U * sizeof(double));
      for (e_i = 0; e_i < 6; e_i++) {
        e_Im_tmp = e_i + 6 * d_i;
        d1 = wq_tilde_data[e_Im_tmp];
        c_Im_tmp = tm_data[e_Im_tmp];
        r4 = _mm_loadu_pd(&b_Im[6 * e_i]);
        r7 = _mm_set1_pd(d1);
        r5 = _mm_loadu_pd(&b_P0[0]);
        _mm_storeu_pd(&b_P0[0], _mm_add_pd(r5, _mm_mul_pd(r4, r7)));
        r5 = _mm_loadu_pd(&Omegam_data[d_i].f1[6 * e_i]);
        r8 = _mm_set1_pd(c_Im_tmp);
        r6 = _mm_loadu_pd(&b_Mdot[0]);
        _mm_storeu_pd(&b_Mdot[0], _mm_add_pd(r6, _mm_mul_pd(r5, r8)));
        e_Im_tmp = 6 * e_i + 2;
        r4 = _mm_loadu_pd(&b_Im[e_Im_tmp]);
        r5 = _mm_loadu_pd(&b_P0[2]);
        _mm_storeu_pd(&b_P0[2], _mm_add_pd(r5, _mm_mul_pd(r4, r7)));
        r5 = _mm_loadu_pd(&Omegam_data[d_i].f1[e_Im_tmp]);
        r6 = _mm_loadu_pd(&b_Mdot[2]);
        _mm_storeu_pd(&b_Mdot[2], _mm_add_pd(r6, _mm_mul_pd(r5, r8)));
        e_Im_tmp = 6 * e_i + 4;
        r4 = _mm_loadu_pd(&b_Im[e_Im_tmp]);
        r4 = _mm_mul_pd(r4, r7);
        r5 = _mm_loadu_pd(&b_P0[4]);
        r4 = _mm_add_pd(r5, r4);
        _mm_storeu_pd(&b_P0[4], r4);
        r5 = _mm_loadu_pd(&Omegam_data[d_i].f1[e_Im_tmp]);
        r4 = _mm_mul_pd(r5, r8);
        r6 = _mm_loadu_pd(&b_Mdot[4]);
        r4 = _mm_add_pd(r6, r4);
        _mm_storeu_pd(&b_Mdot[4], r4);
      }
      r4 = _mm_loadu_pd(&b_P0[0]);
      r5 = _mm_loadu_pd(&b_Mdot[0]);
      _mm_storeu_pd(
          &wq_data[6 * d_i],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[6 * d_i])));
      r4 = _mm_loadu_pd(&b_P0[2]);
      r5 = _mm_loadu_pd(&b_Mdot[2]);
      e_Im_tmp = 6 * d_i + 2;
      _mm_storeu_pd(
          &wq_data[e_Im_tmp],
          _mm_sub_pd(_mm_add_pd(r4, r5), _mm_loadu_pd(&wFm_data[e_Im_tmp])));
      r4 = _mm_loadu_pd(&b_P0[4]);
      r5 = _mm_loadu_pd(&b_Mdot[4]);
      r5 = _mm_add_pd(r4, r5);
      e_Im_tmp = 6 * d_i + 4;
      r4 = _mm_loadu_pd(&wFm_data[e_Im_tmp]);
      r4 = _mm_sub_pd(r5, r4);
      _mm_storeu_pd(&wq_data[e_Im_tmp], r4);
    }
  }
  emxFree_cell_wrap_1(&Mdot);
  /* --- Backward recursion ---% */
  M_hat_tmp = wq_tilde->size[0] * wq_tilde->size[1];
  wq_tilde->size[0] = 6;
  wq_tilde->size[1] = loop_ub;
  emxEnsureCapacity_real_T(wq_tilde, M_hat_tmp);
  wq_tilde_data = wq_tilde->data;
  for (i = 0; i < b_loop_ub; i++) {
    wq_tilde_data[i] = 0.0;
  }
  b_M_hat0_tmp = (int)-((-1.0 - nLinksJoints) + 1.0);
  for (f_i = 0; f_i < b_M_hat0_tmp; f_i++) {
    Im_tmp = nLinksJoints - (double)f_i;
    for (i = 0; i < 6; i++) {
      M_hat_tmp = i + 6 * ((int)Im_tmp - 1);
      wq_tilde_data[M_hat_tmp] = wq_data[M_hat_tmp];
    }
    for (j = 0; j < loop_ub; j++) {
      if (robotConChild_data[j + robotConChild->size[0] * ((int)Im_tmp - 1)] !=
          0.0) {
        for (i = 0; i < 6; i++) {
          b_i = 0.0;
          for (c_i = 0; c_i < 6; c_i++) {
            b_i +=
                Bij_data[j + Bij->size[0] * ((int)Im_tmp - 1)].f1[c_i + 6 * i] *
                wq_tilde_data[c_i + 6 * j];
          }
          b_P0[i] = wq_tilde_data[i + 6 * ((int)Im_tmp - 1)] + b_i;
        }
        for (i = 0; i < 6; i++) {
          wq_tilde_data[i + 6 * ((int)Im_tmp - 1)] = b_P0[i];
        }
      }
    }
  }
  emxFree_real_T(&wq);
  for (i = 0; i < loop_ub; i++) {
    if (robotConChildBase_data[i] != 0.0) {
      for (c_i = 0; c_i < 6; c_i++) {
        Im_tmp = 0.0;
        for (j = 0; j < 6; j++) {
          Im_tmp += Bi0_data[i].f1[j + 6 * c_i] * wq_tilde_data[j + 6 * i];
        }
        wq0[c_i] += Im_tmp;
      }
    }
  }
  /* --- Joint Forces ---% */
  for (i = 0; i < 6; i++) {
    for (c_i = 0; c_i < 6; c_i++) {
      tau0_0ddot_tmp[c_i + 6 * i] = P0[i + 6 * c_i];
    }
  }
  emxInit_real_T(&phi, 1);
  M_hat_tmp = phi->size[0];
  phi->size[0] = c_loop_ub;
  emxEnsureCapacity_real_T(phi, M_hat_tmp);
  phi_data = phi->data;
  for (i = 0; i < c_loop_ub; i++) {
    phi_data[i] = 0.0;
  }
  for (i = 0; i < loop_ub; i++) {
    if (robotJoints_data[i].type != 0.0) {
      Im_tmp = 0.0;
      for (c_i = 0; c_i < 6; c_i++) {
        M_hat_tmp = c_i + 6 * i;
        Im_tmp += pm_data[M_hat_tmp] * wq_tilde_data[M_hat_tmp];
      }
      phi_data[(int)robotJoints_data[i].q_id - 1] = Im_tmp;
    }
  }
  emxFree_real_T(&wq_tilde);
  /* === Forward Dynamics ===% */
  if (taum->size[0] == phi->size[0]) {
    M_hat0_tmp = taum->size[0];
    M_hat_tmp = phi->size[0];
    phi->size[0] = taum->size[0];
    emxEnsureCapacity_real_T(phi, M_hat_tmp);
    phi_data = phi->data;
    M_hat_tmp = (taum->size[0] / 2) << 1;
    vectorUB = M_hat_tmp - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r1 = _mm_loadu_pd(&phi_data[i]);
      _mm_storeu_pd(&phi_data[i], _mm_sub_pd(_mm_loadu_pd(&taum_data[i]), r1));
    }
    for (i = M_hat_tmp; i < M_hat0_tmp; i++) {
      phi_data[i] = taum_data[i] - phi_data[i];
    }
  } else {
    minus(phi, taum);
    phi_data = phi->data;
  }
  /*  Allocate and pre-initialize (required for code generation) */
  emxInit_cell_wrap_1(&b_M_hat, 1);
  M_hat_tmp = b_M_hat->size[0];
  b_M_hat->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_1(b_M_hat, M_hat_tmp);
  Omegam_data = b_M_hat->data;
  emxInit_cell_wrap_3(&psi_hat);
  M_hat_tmp = psi_hat->size[0];
  psi_hat->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_3(psi_hat, M_hat_tmp);
  psi_hat_data = psi_hat->data;
  emxInit_cell_wrap_3(&psi);
  M_hat_tmp = psi->size[0];
  psi->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_3(psi, M_hat_tmp);
  psi_data = psi->data;
  for (c_i = 0; c_i < loop_ub; c_i++) {
    for (i = 0; i < 36; i++) {
      Omegam_data[c_i].f1[i] = 0.0;
    }
    for (i = 0; i < 6; i++) {
      psi_hat_data[c_i].f1[i] = 0.0;
      psi_data[c_i].f1[i] = 0.0;
    }
  }
  /* === Backward recursion for M_hat, psi_hat, psi ===% */
  for (g_i = 0; g_i < b_M_hat0_tmp; g_i++) {
    b_i = nLinksJoints - (double)g_i;
    /*  cell: {3x3} */
    for (i = 0; i < 3; i++) {
      Omegam_data[(int)b_i - 1].f1[6 * i] = Im_data[(int)b_i - 1].f1[3 * i];
      vectorUB = 6 * (i + 3);
      Omegam_data[(int)b_i - 1].f1[vectorUB] = 0.0;
      Omegam_data[(int)b_i - 1].f1[6 * i + 3] = 0.0;
      Im_tmp = robotLinks_data[(int)b_i - 1].mass;
      Omegam_data[(int)b_i - 1].f1[vectorUB + 3] = Im_tmp * (double)iv[3 * i];
      M_hat_tmp = 3 * i + 1;
      Omegam_data[(int)b_i - 1].f1[6 * i + 1] =
          Im_data[(int)b_i - 1].f1[M_hat_tmp];
      Omegam_data[(int)b_i - 1].f1[vectorUB + 1] = 0.0;
      Omegam_data[(int)b_i - 1].f1[6 * i + 4] = 0.0;
      Omegam_data[(int)b_i - 1].f1[vectorUB + 4] =
          Im_tmp * (double)iv[M_hat_tmp];
      M_hat_tmp = 3 * i + 2;
      Omegam_data[(int)b_i - 1].f1[6 * i + 2] =
          Im_data[(int)b_i - 1].f1[M_hat_tmp];
      Omegam_data[(int)b_i - 1].f1[vectorUB + 2] = 0.0;
      Omegam_data[(int)b_i - 1].f1[6 * i + 5] = 0.0;
      Omegam_data[(int)b_i - 1].f1[vectorUB + 5] =
          Im_tmp * (double)iv[M_hat_tmp];
    }
    for (f_i = 0; f_i < loop_ub; f_i++) {
      if (robotConChild_data[f_i + robotConChild->size[0] * ((int)b_i - 1)] !=
          0.0) {
        r2 = _mm_set1_pd(0.0);
        for (j = 0; j < 6; j++) {
          r1 = _mm_loadu_pd(&psi_hat_data[f_i].f1[0]);
          r3 = _mm_loadu_pd(&Omegam_data[f_i].f1[6 * j]);
          r = _mm_set1_pd(psi_data[f_i].f1[j]);
          _mm_storeu_pd(&M_hat[6 * j],
                        _mm_sub_pd(r3, _mm_add_pd(r2, _mm_mul_pd(r1, r))));
          r1 = _mm_loadu_pd(&psi_hat_data[f_i].f1[2]);
          M_hat_tmp = 6 * j + 2;
          r3 = _mm_loadu_pd(&Omegam_data[f_i].f1[M_hat_tmp]);
          _mm_storeu_pd(&M_hat[M_hat_tmp],
                        _mm_sub_pd(r3, _mm_add_pd(r2, _mm_mul_pd(r1, r))));
          r1 = _mm_loadu_pd(&psi_hat_data[f_i].f1[4]);
          M_hat_tmp = 6 * j + 4;
          r3 = _mm_loadu_pd(&Omegam_data[f_i].f1[M_hat_tmp]);
          _mm_storeu_pd(&M_hat[M_hat_tmp],
                        _mm_sub_pd(r3, _mm_add_pd(r2, _mm_mul_pd(r1, r))));
          for (i = 0; i < 6; i++) {
            Im_tmp = 0.0;
            for (c_i = 0; c_i < 6; c_i++) {
              Im_tmp += Bij_data[f_i + Bij->size[0] * ((int)b_i - 1)]
                            .f1[c_i + 6 * i] *
                        M_hat[c_i + 6 * j];
            }
            b_Im[i + 6 * j] = Im_tmp;
          }
        }
        for (c_i = 0; c_i < 6; c_i++) {
          for (j = 0; j < 6; j++) {
            Im_tmp = 0.0;
            for (i = 0; i < 6; i++) {
              Im_tmp +=
                  b_Im[c_i + 6 * i] *
                  Bij_data[f_i + Bij->size[0] * ((int)b_i - 1)].f1[i + 6 * j];
            }
            M_hat_tmp = c_i + 6 * j;
            Omegam_data[(int)b_i - 1].f1[M_hat_tmp] += Im_tmp;
          }
        }
      }
    }
    if (robotJoints_data[(int)b_i - 1].type == 0.0) {
      for (i = 0; i < 6; i++) {
        psi_hat_data[(int)b_i - 1].f1[i] = 0.0;
        psi_data[(int)b_i - 1].f1[i] = 0.0;
      }
    } else {
      for (i = 0; i < 6; i++) {
        psi_hat_data[(int)b_i - 1].f1[i] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        r2 = _mm_loadu_pd(&Omegam_data[(int)b_i - 1].f1[6 * i]);
        r1 = _mm_loadu_pd(&psi_hat_data[(int)b_i - 1].f1[0]);
        r3 = _mm_set1_pd(pm_data[i + 6 * ((int)b_i - 1)]);
        _mm_storeu_pd(&psi_hat_data[(int)b_i - 1].f1[0],
                      _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
        r2 = _mm_loadu_pd(&Omegam_data[(int)b_i - 1].f1[6 * i + 2]);
        r1 = _mm_loadu_pd(&psi_hat_data[(int)b_i - 1].f1[2]);
        _mm_storeu_pd(&psi_hat_data[(int)b_i - 1].f1[2],
                      _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
        r2 = _mm_loadu_pd(&Omegam_data[(int)b_i - 1].f1[6 * i + 4]);
        r1 = _mm_loadu_pd(&psi_hat_data[(int)b_i - 1].f1[4]);
        _mm_storeu_pd(&psi_hat_data[(int)b_i - 1].f1[4],
                      _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      }
      Im_tmp = 0.0;
      for (i = 0; i < 6; i++) {
        Im_tmp +=
            pm_data[i + 6 * ((int)b_i - 1)] * psi_hat_data[(int)b_i - 1].f1[i];
      }
      r1 = _mm_loadu_pd(&psi_hat_data[(int)b_i - 1].f1[0]);
      r2 = _mm_set1_pd(Im_tmp);
      _mm_storeu_pd(&psi_data[(int)b_i - 1].f1[0], _mm_div_pd(r1, r2));
      r1 = _mm_loadu_pd(&psi_hat_data[(int)b_i - 1].f1[2]);
      _mm_storeu_pd(&psi_data[(int)b_i - 1].f1[2], _mm_div_pd(r1, r2));
      r1 = _mm_loadu_pd(&psi_hat_data[(int)b_i - 1].f1[4]);
      _mm_storeu_pd(&psi_data[(int)b_i - 1].f1[4], _mm_div_pd(r1, r2));
    }
  }
  /* === Base link M_hat0 ===% */
  for (f_i = 0; f_i < loop_ub; f_i++) {
    if (robotConChildBase_data[f_i] != 0.0) {
      r2 = _mm_set1_pd(0.0);
      for (j = 0; j < 6; j++) {
        r1 = _mm_loadu_pd(&psi_hat_data[f_i].f1[0]);
        r3 = _mm_loadu_pd(&Omegam_data[f_i].f1[6 * j]);
        r = _mm_set1_pd(psi_data[f_i].f1[j]);
        _mm_storeu_pd(&M_hat[6 * j],
                      _mm_sub_pd(r3, _mm_add_pd(r2, _mm_mul_pd(r1, r))));
        r1 = _mm_loadu_pd(&psi_hat_data[f_i].f1[2]);
        M_hat_tmp = 6 * j + 2;
        r3 = _mm_loadu_pd(&Omegam_data[f_i].f1[M_hat_tmp]);
        _mm_storeu_pd(&M_hat[M_hat_tmp],
                      _mm_sub_pd(r3, _mm_add_pd(r2, _mm_mul_pd(r1, r))));
        r1 = _mm_loadu_pd(&psi_hat_data[f_i].f1[4]);
        M_hat_tmp = 6 * j + 4;
        r3 = _mm_loadu_pd(&Omegam_data[f_i].f1[M_hat_tmp]);
        _mm_storeu_pd(&M_hat[M_hat_tmp],
                      _mm_sub_pd(r3, _mm_add_pd(r2, _mm_mul_pd(r1, r))));
        for (i = 0; i < 6; i++) {
          Im_tmp = 0.0;
          for (c_i = 0; c_i < 6; c_i++) {
            Im_tmp += Bi0_data[f_i].f1[c_i + 6 * i] * M_hat[c_i + 6 * j];
          }
          b_Im[i + 6 * j] = Im_tmp;
        }
      }
      for (c_i = 0; c_i < 6; c_i++) {
        for (j = 0; j < 6; j++) {
          Im_tmp = 0.0;
          for (i = 0; i < 6; i++) {
            Im_tmp += b_Im[c_i + 6 * i] * Bi0_data[f_i].f1[i + 6 * j];
          }
          M_hat_tmp = c_i + 6 * j;
          M_hat0[M_hat_tmp] += Im_tmp;
        }
      }
    }
  }
  emxFree_cell_wrap_1(&b_M_hat);
  /* === eta, phi_hat, phi_tilde ===% */
  emxInit_cell_wrap_3(&eta);
  M_hat_tmp = eta->size[0];
  eta->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_3(eta, M_hat_tmp);
  eta_data = eta->data;
  for (i = 0; i < loop_ub; i++) {
    for (c_i = 0; c_i < 6; c_i++) {
      eta_data[i].f1[c_i] = 0.0;
    }
  }
  emxInit_real_T(&phi_hat, 1);
  M_hat_tmp = phi_hat->size[0];
  phi_hat->size[0] = loop_ub;
  emxEnsureCapacity_real_T(phi_hat, M_hat_tmp);
  wq_data = phi_hat->data;
  for (i = 0; i < loop_ub; i++) {
    wq_data[i] = 0.0;
  }
  emxInit_real_T(&phi_tilde, 1);
  M_hat_tmp = phi_tilde->size[0];
  phi_tilde->size[0] = c_loop_ub;
  emxEnsureCapacity_real_T(phi_tilde, M_hat_tmp);
  wq_tilde_data = phi_tilde->data;
  for (i = 0; i < c_loop_ub; i++) {
    wq_tilde_data[i] = 0.0;
  }
  for (f_i = 0; f_i < b_M_hat0_tmp; f_i++) {
    b_i = nLinksJoints - (double)f_i;
    for (i = 0; i < loop_ub; i++) {
      if (robotConChild_data[i + robotConChild->size[0] * ((int)b_i - 1)] !=
          0.0) {
        r2 = _mm_loadu_pd(&psi_data[i].f1[0]);
        r1 = _mm_loadu_pd(&eta_data[i].f1[0]);
        r3 = _mm_set1_pd(wq_data[i]);
        _mm_storeu_pd(&b_P0[0], _mm_add_pd(_mm_mul_pd(r2, r3), r1));
        r2 = _mm_loadu_pd(&psi_data[i].f1[2]);
        r1 = _mm_loadu_pd(&eta_data[i].f1[2]);
        _mm_storeu_pd(&b_P0[2], _mm_add_pd(_mm_mul_pd(r2, r3), r1));
        r2 = _mm_loadu_pd(&psi_data[i].f1[4]);
        r1 = _mm_loadu_pd(&eta_data[i].f1[4]);
        _mm_storeu_pd(&b_P0[4], _mm_add_pd(_mm_mul_pd(r2, r3), r1));
        for (c_i = 0; c_i < 6; c_i++) {
          Im_tmp = 0.0;
          for (j = 0; j < 6; j++) {
            Im_tmp +=
                Bij_data[i + Bij->size[0] * ((int)b_i - 1)].f1[j + 6 * c_i] *
                b_P0[j];
          }
          eta_data[(int)b_i - 1].f1[c_i] += Im_tmp;
        }
      }
    }
    Im_tmp = 0.0;
    for (i = 0; i < 6; i++) {
      Im_tmp += -pm_data[i + 6 * ((int)b_i - 1)] * eta_data[(int)b_i - 1].f1[i];
    }
    wq_data[(int)b_i - 1] = Im_tmp;
    if (robotJoints_data[(int)b_i - 1].type != 0.0) {
      M_hat_tmp = (int)robotJoints_data[(int)b_i - 1].q_id - 1;
      wq_data[(int)b_i - 1] += phi_data[M_hat_tmp];
      Im_tmp = 0.0;
      for (i = 0; i < 6; i++) {
        Im_tmp +=
            pm_data[i + 6 * ((int)b_i - 1)] * psi_hat_data[(int)b_i - 1].f1[i];
      }
      wq_tilde_data[M_hat_tmp] = wq_data[(int)b_i - 1] / Im_tmp;
    }
  }
  emxFree_real_T(&phi);
  /* === Base-link phi_tilde0 ===% */
  for (i = 0; i < 6; i++) {
    eta0[i] = 0.0;
  }
  for (i = 0; i < loop_ub; i++) {
    if (robotConChildBase_data[i] != 0.0) {
      r2 = _mm_loadu_pd(&psi_data[i].f1[0]);
      r1 = _mm_loadu_pd(&eta_data[i].f1[0]);
      r3 = _mm_set1_pd(wq_data[i]);
      _mm_storeu_pd(&b_P0[0], _mm_add_pd(_mm_mul_pd(r2, r3), r1));
      r2 = _mm_loadu_pd(&psi_data[i].f1[2]);
      r1 = _mm_loadu_pd(&eta_data[i].f1[2]);
      _mm_storeu_pd(&b_P0[2], _mm_add_pd(_mm_mul_pd(r2, r3), r1));
      r2 = _mm_loadu_pd(&psi_data[i].f1[4]);
      r1 = _mm_loadu_pd(&eta_data[i].f1[4]);
      _mm_storeu_pd(&b_P0[4], _mm_add_pd(_mm_mul_pd(r2, r3), r1));
      for (c_i = 0; c_i < 6; c_i++) {
        Im_tmp = 0.0;
        for (j = 0; j < 6; j++) {
          Im_tmp += Bi0_data[i].f1[j + 6 * c_i] * b_P0[j];
        }
        eta0[c_i] += Im_tmp;
      }
    }
  }
  emxFree_real_T(&phi_hat);
  emxFree_cell_wrap_3(&eta);
  memset(&b_P0[0], 0, 6U * sizeof(double));
  for (i = 0; i < 6; i++) {
    Im_tmp = 0.0;
    for (c_i = 0; c_i < 6; c_i++) {
      Im_tmp += tau0_0ddot_tmp[i + 6 * c_i] * wq0[c_i];
      b_P0[c_i] += tau0_0ddot_tmp[c_i + 6 * i] * eta0[i];
    }
    u0dot[i] = tau0[i] - Im_tmp;
  }
  memset(&M_hat[0], 0, 36U * sizeof(double));
  memset(&b_Im[0], 0, 36U * sizeof(double));
  for (c_i = 0; c_i < 6; c_i++) {
    u0dot[c_i] -= b_P0[c_i];
    M_hat_tmp = 6 * c_i + 2;
    vectorUB = 6 * c_i + 4;
    for (i = 0; i < 6; i++) {
      r2 = _mm_loadu_pd(&M_hat0[6 * i]);
      r1 = _mm_loadu_pd(&M_hat[6 * c_i]);
      r3 = _mm_set1_pd(P0[i + 6 * c_i]);
      _mm_storeu_pd(&M_hat[6 * c_i], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      r2 = _mm_loadu_pd(&M_hat0[6 * i + 2]);
      r1 = _mm_loadu_pd(&M_hat[M_hat_tmp]);
      _mm_storeu_pd(&M_hat[M_hat_tmp], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      r2 = _mm_loadu_pd(&M_hat0[6 * i + 4]);
      r1 = _mm_loadu_pd(&M_hat[vectorUB]);
      _mm_storeu_pd(&M_hat[vectorUB], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    }
    M_hat_tmp = 6 * c_i + 2;
    vectorUB = 6 * c_i + 4;
    for (i = 0; i < 6; i++) {
      r2 = _mm_loadu_pd(&tau0_0ddot_tmp[6 * i]);
      r1 = _mm_loadu_pd(&b_Im[6 * c_i]);
      r3 = _mm_set1_pd(M_hat[i + 6 * c_i]);
      _mm_storeu_pd(&b_Im[6 * c_i], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      r2 = _mm_loadu_pd(&tau0_0ddot_tmp[6 * i + 2]);
      r1 = _mm_loadu_pd(&b_Im[M_hat_tmp]);
      _mm_storeu_pd(&b_Im[M_hat_tmp], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
      r2 = _mm_loadu_pd(&tau0_0ddot_tmp[6 * i + 4]);
      r1 = _mm_loadu_pd(&b_Im[vectorUB]);
      _mm_storeu_pd(&b_Im[vectorUB], _mm_add_pd(r1, _mm_mul_pd(r2, r3)));
    }
  }
  mldivide(b_Im, u0dot);
  /* === Forward recursion for manipulator acceleration ===% */
  M_hat_tmp = psi_hat->size[0];
  psi_hat->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_3(psi_hat, M_hat_tmp);
  psi_hat_data = psi_hat->data;
  for (i = 0; i < loop_ub; i++) {
    for (c_i = 0; c_i < 6; c_i++) {
      psi_hat_data[i].f1[c_i] = 0.0;
    }
  }
  M_hat_tmp = umdot->size[0];
  umdot->size[0] = c_loop_ub;
  emxEnsureCapacity_real_T(umdot, M_hat_tmp);
  wq_data = umdot->data;
  for (i = 0; i < c_loop_ub; i++) {
    wq_data[i] = 0.0;
  }
  for (c_i = 0; c_i < loop_ub; c_i++) {
    if (robotJoints_data[c_i].parent_link == 0.0) {
      memset(&b_P0[0], 0, 6U * sizeof(double));
      for (i = 0; i < 6; i++) {
        r1 = _mm_loadu_pd(&b_P0[0]);
        r2 = _mm_set1_pd(u0dot[i]);
        _mm_storeu_pd(&b_P0[0],
                      _mm_add_pd(r1, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i]), r2)));
        r1 = _mm_loadu_pd(&b_P0[2]);
        _mm_storeu_pd(
            &b_P0[2],
            _mm_add_pd(r1, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i + 2]), r2)));
        r1 = _mm_loadu_pd(&b_P0[4]);
        _mm_storeu_pd(
            &b_P0[4],
            _mm_add_pd(r1, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i + 4]), r2)));
        psi_hat_data[c_i].f1[i] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        r1 = _mm_loadu_pd(&psi_hat_data[c_i].f1[0]);
        r2 = _mm_set1_pd(b_P0[i]);
        _mm_storeu_pd(
            &psi_hat_data[c_i].f1[0],
            _mm_add_pd(r1,
                       _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[6 * i]), r2)));
        r1 = _mm_loadu_pd(&psi_hat_data[c_i].f1[2]);
        _mm_storeu_pd(
            &psi_hat_data[c_i].f1[2],
            _mm_add_pd(
                r1,
                _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[6 * i + 2]), r2)));
        r1 = _mm_loadu_pd(&psi_hat_data[c_i].f1[4]);
        _mm_storeu_pd(
            &psi_hat_data[c_i].f1[4],
            _mm_add_pd(
                r1,
                _mm_mul_pd(_mm_loadu_pd(&Bi0_data[c_i].f1[6 * i + 4]), r2)));
      }
    } else {
      for (i = 0; i < 6; i++) {
        eta0[i] =
            psi_hat_data[(int)robotJoints_data[c_i].parent_link - 1].f1[i];
      }
      M_hat_tmp = (int)robotJoints_data[c_i].parent_link - 1;
      if (robotJoints_data[M_hat_tmp].type != 0.0) {
        r1 = _mm_loadu_pd(&psi_hat_data[M_hat_tmp].f1[0]);
        r2 = _mm_set1_pd(wq_data[(int)robotJoints_data[M_hat_tmp].q_id - 1]);
        _mm_storeu_pd(
            &eta0[0],
            _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&pm_data[6 * M_hat_tmp]), r2),
                       r1));
        r1 = _mm_loadu_pd(&psi_hat_data[M_hat_tmp].f1[2]);
        _mm_storeu_pd(
            &eta0[2],
            _mm_add_pd(
                _mm_mul_pd(_mm_loadu_pd(&pm_data[6 * M_hat_tmp + 2]), r2), r1));
        r1 = _mm_loadu_pd(&psi_hat_data[M_hat_tmp].f1[4]);
        _mm_storeu_pd(
            &eta0[4],
            _mm_add_pd(
                _mm_mul_pd(_mm_loadu_pd(&pm_data[6 * M_hat_tmp + 4]), r2), r1));
      }
      for (i = 0; i < 6; i++) {
        psi_hat_data[c_i].f1[i] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        r1 = _mm_loadu_pd(&psi_hat_data[c_i].f1[0]);
        r2 = _mm_set1_pd(eta0[i]);
        _mm_storeu_pd(
            &psi_hat_data[c_i].f1[0],
            _mm_add_pd(
                r1,
                _mm_mul_pd(
                    _mm_loadu_pd(
                        &Bij_data[c_i + Bij->size[0] * (c_i - 1)].f1[6 * i]),
                    r2)));
        r1 = _mm_loadu_pd(&psi_hat_data[c_i].f1[2]);
        _mm_storeu_pd(
            &psi_hat_data[c_i].f1[2],
            _mm_add_pd(
                r1, _mm_mul_pd(
                        _mm_loadu_pd(&Bij_data[c_i + Bij->size[0] * (c_i - 1)]
                                          .f1[6 * i + 2]),
                        r2)));
        r1 = _mm_loadu_pd(&psi_hat_data[c_i].f1[4]);
        _mm_storeu_pd(
            &psi_hat_data[c_i].f1[4],
            _mm_add_pd(
                r1, _mm_mul_pd(
                        _mm_loadu_pd(&Bij_data[c_i + Bij->size[0] * (c_i - 1)]
                                          .f1[6 * i + 4]),
                        r2)));
      }
    }
    if (robotJoints_data[c_i].type != 0.0) {
      Im_tmp = 0.0;
      for (i = 0; i < 6; i++) {
        Im_tmp += psi_data[c_i].f1[i] * psi_hat_data[c_i].f1[i];
      }
      M_hat_tmp = (int)robotJoints_data[c_i].q_id - 1;
      wq_data[M_hat_tmp] = wq_tilde_data[M_hat_tmp] - Im_tmp;
    }
  }
  emxFree_real_T(&phi_tilde);
  emxFree_cell_wrap_3(&psi);
  emxFree_cell_wrap_3(&psi_hat);
}

/*
 * File trailer for FD_C.c
 *
 * [EOF]
 */
