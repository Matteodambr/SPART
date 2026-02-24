/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FD_C.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

/* Include Files */
#include "FD_C.h"
#include "Accelerations_C.h"
#include "ID_C.h"
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
  const cell_wrap_1 *Bi0_data;
  const cell_wrap_1 *Bij_data;
  cell_wrap_1 *M_hat_data;
  const cell_wrap_2 *Im_data;
  cell_wrap_3 *eta_data;
  cell_wrap_3 *psi_data;
  cell_wrap_3 *psi_hat_data;
  emxArray_cell_wrap_1 *M_hat;
  emxArray_cell_wrap_3 *eta;
  emxArray_cell_wrap_3 *psi;
  emxArray_cell_wrap_3 *psi_hat;
  emxArray_real_T *phi;
  emxArray_real_T *phi_hat;
  emxArray_real_T *phi_tilde;
  emxArray_real_T *tmdot;
  const struct0_T *robotJoints_data;
  const struct1_T *robotLinks_data;
  double M_hat0[36];
  double b_Bij[36];
  double b_M_hat[36];
  double b_M_hat0[36];
  double b_psi[6];
  double eta0[6];
  double tau0_0ddot[6];
  const double *pm_data;
  const double *robotConChildBase_data;
  const double *robotConChild_data;
  const double *taum_data;
  double b_pm;
  double e_i;
  double *phi_data;
  double *phi_hat_data;
  double *phi_tilde_data;
  int b_i;
  int b_loop_ub;
  int c_i;
  int d_i;
  int i;
  int i1;
  int j;
  int loop_ub;
  int scalarLB;
  int vectorUB;
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
  taum_data = taum->data;
  /* === Inverse Dynamics with zero accelerations ===% */
  emxInit_real_T(&phi, 1);
  emxInit_real_T(&tmdot, 2);
  b_Accelerations_C(t0, b_tm, P0, pm, Bi0, Bij, u0, um, nLinksJoints,
                    robotJoints, eta0, tmdot);
  b_ID_C(wF0, wFm, t0, b_tm, eta0, tmdot, P0, pm, I0, Im, Bij, Bi0,
         nLinksJoints, nQ, robotBaseLink->mass, robotLinks, robotConChild,
         robotConChildBase, robotJoints, tau0_0ddot, phi);
  emxFree_real_T(&tmdot);
  /* === Forward Dynamics ===% */
  if (taum->size[0] == phi->size[0]) {
    loop_ub = taum->size[0];
    scalarLB = phi->size[0];
    phi->size[0] = taum->size[0];
    emxEnsureCapacity_real_T(phi, scalarLB);
    phi_data = phi->data;
    scalarLB = (taum->size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&phi_data[i]);
      _mm_storeu_pd(&phi_data[i], _mm_sub_pd(_mm_loadu_pd(&taum_data[i]), r));
    }
    for (i = scalarLB; i < loop_ub; i++) {
      phi_data[i] = taum_data[i] - phi_data[i];
    }
  } else {
    minus(phi, taum);
    phi_data = phi->data;
  }
  /*  Allocate and pre-initialize (required for code generation) */
  b_loop_ub = (int)nLinksJoints;
  emxInit_cell_wrap_1(&M_hat, 1);
  scalarLB = M_hat->size[0];
  M_hat->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_1(M_hat, scalarLB);
  M_hat_data = M_hat->data;
  emxInit_cell_wrap_3(&psi_hat);
  scalarLB = psi_hat->size[0];
  psi_hat->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_3(psi_hat, scalarLB);
  psi_hat_data = psi_hat->data;
  emxInit_cell_wrap_3(&psi);
  scalarLB = psi->size[0];
  psi->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_3(psi, scalarLB);
  psi_data = psi->data;
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    for (i = 0; i < 36; i++) {
      M_hat_data[b_i].f1[i] = 0.0;
    }
    for (i = 0; i < 6; i++) {
      psi_hat_data[b_i].f1[i] = 0.0;
      psi_data[b_i].f1[i] = 0.0;
    }
  }
  /* === Backward recursion for M_hat, psi_hat, psi ===% */
  c_i = (int)-((-1.0 - nLinksJoints) + 1.0);
  for (d_i = 0; d_i < c_i; d_i++) {
    e_i = nLinksJoints - (double)d_i;
    /*  cell: {3x3} */
    for (i = 0; i < 3; i++) {
      M_hat_data[(int)e_i - 1].f1[6 * i] = Im_data[(int)e_i - 1].f1[3 * i];
      vectorUB = 6 * (i + 3);
      M_hat_data[(int)e_i - 1].f1[vectorUB] = 0.0;
      M_hat_data[(int)e_i - 1].f1[6 * i + 3] = 0.0;
      b_pm = robotLinks_data[(int)e_i - 1].mass;
      M_hat_data[(int)e_i - 1].f1[vectorUB + 3] = b_pm * (double)iv[3 * i];
      scalarLB = 3 * i + 1;
      M_hat_data[(int)e_i - 1].f1[6 * i + 1] =
          Im_data[(int)e_i - 1].f1[scalarLB];
      M_hat_data[(int)e_i - 1].f1[vectorUB + 1] = 0.0;
      M_hat_data[(int)e_i - 1].f1[6 * i + 4] = 0.0;
      M_hat_data[(int)e_i - 1].f1[vectorUB + 4] = b_pm * (double)iv[scalarLB];
      scalarLB = 3 * i + 2;
      M_hat_data[(int)e_i - 1].f1[6 * i + 2] =
          Im_data[(int)e_i - 1].f1[scalarLB];
      M_hat_data[(int)e_i - 1].f1[vectorUB + 2] = 0.0;
      M_hat_data[(int)e_i - 1].f1[6 * i + 5] = 0.0;
      M_hat_data[(int)e_i - 1].f1[vectorUB + 5] = b_pm * (double)iv[scalarLB];
    }
    for (j = 0; j < b_loop_ub; j++) {
      if (robotConChild_data[j + robotConChild->size[0] * ((int)e_i - 1)] !=
          0.0) {
        r = _mm_set1_pd(0.0);
        for (i1 = 0; i1 < 6; i1++) {
          r1 = _mm_loadu_pd(&psi_hat_data[j].f1[0]);
          r2 = _mm_loadu_pd(&M_hat_data[j].f1[6 * i1]);
          r3 = _mm_set1_pd(psi_data[j].f1[i1]);
          _mm_storeu_pd(&b_M_hat[6 * i1],
                        _mm_sub_pd(r2, _mm_add_pd(r, _mm_mul_pd(r1, r3))));
          r1 = _mm_loadu_pd(&psi_hat_data[j].f1[2]);
          scalarLB = 6 * i1 + 2;
          r2 = _mm_loadu_pd(&M_hat_data[j].f1[scalarLB]);
          _mm_storeu_pd(&b_M_hat[scalarLB],
                        _mm_sub_pd(r2, _mm_add_pd(r, _mm_mul_pd(r1, r3))));
          r1 = _mm_loadu_pd(&psi_hat_data[j].f1[4]);
          scalarLB = 6 * i1 + 4;
          r2 = _mm_loadu_pd(&M_hat_data[j].f1[scalarLB]);
          _mm_storeu_pd(&b_M_hat[scalarLB],
                        _mm_sub_pd(r2, _mm_add_pd(r, _mm_mul_pd(r1, r3))));
          for (i = 0; i < 6; i++) {
            b_pm = 0.0;
            for (b_i = 0; b_i < 6; b_i++) {
              b_pm +=
                  Bij_data[j + Bij->size[0] * ((int)e_i - 1)].f1[b_i + 6 * i] *
                  b_M_hat[b_i + 6 * i1];
            }
            b_Bij[i + 6 * i1] = b_pm;
          }
        }
        for (b_i = 0; b_i < 6; b_i++) {
          for (i1 = 0; i1 < 6; i1++) {
            b_pm = 0.0;
            for (i = 0; i < 6; i++) {
              b_pm +=
                  b_Bij[b_i + 6 * i] *
                  Bij_data[j + Bij->size[0] * ((int)e_i - 1)].f1[i + 6 * i1];
            }
            scalarLB = b_i + 6 * i1;
            M_hat_data[(int)e_i - 1].f1[scalarLB] += b_pm;
          }
        }
      }
    }
    if (robotJoints_data[(int)e_i - 1].type == 0.0) {
      for (i = 0; i < 6; i++) {
        psi_hat_data[(int)e_i - 1].f1[i] = 0.0;
        psi_data[(int)e_i - 1].f1[i] = 0.0;
      }
    } else {
      for (i = 0; i < 6; i++) {
        psi_hat_data[(int)e_i - 1].f1[i] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        r = _mm_loadu_pd(&M_hat_data[(int)e_i - 1].f1[6 * i]);
        r1 = _mm_loadu_pd(&psi_hat_data[(int)e_i - 1].f1[0]);
        r2 = _mm_set1_pd(pm_data[i + 6 * ((int)e_i - 1)]);
        _mm_storeu_pd(&psi_hat_data[(int)e_i - 1].f1[0],
                      _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        r = _mm_loadu_pd(&M_hat_data[(int)e_i - 1].f1[6 * i + 2]);
        r1 = _mm_loadu_pd(&psi_hat_data[(int)e_i - 1].f1[2]);
        _mm_storeu_pd(&psi_hat_data[(int)e_i - 1].f1[2],
                      _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        r = _mm_loadu_pd(&M_hat_data[(int)e_i - 1].f1[6 * i + 4]);
        r1 = _mm_loadu_pd(&psi_hat_data[(int)e_i - 1].f1[4]);
        _mm_storeu_pd(&psi_hat_data[(int)e_i - 1].f1[4],
                      _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      }
      b_pm = 0.0;
      for (i = 0; i < 6; i++) {
        b_pm +=
            pm_data[i + 6 * ((int)e_i - 1)] * psi_hat_data[(int)e_i - 1].f1[i];
      }
      r = _mm_loadu_pd(&psi_hat_data[(int)e_i - 1].f1[0]);
      r1 = _mm_set1_pd(b_pm);
      _mm_storeu_pd(&psi_data[(int)e_i - 1].f1[0], _mm_div_pd(r, r1));
      r = _mm_loadu_pd(&psi_hat_data[(int)e_i - 1].f1[2]);
      _mm_storeu_pd(&psi_data[(int)e_i - 1].f1[2], _mm_div_pd(r, r1));
      r = _mm_loadu_pd(&psi_hat_data[(int)e_i - 1].f1[4]);
      _mm_storeu_pd(&psi_data[(int)e_i - 1].f1[4], _mm_div_pd(r, r1));
    }
  }
  /* === Base link M_hat0 ===% */
  for (i = 0; i < 3; i++) {
    M_hat0[6 * i] = I0[3 * i];
    vectorUB = 6 * (i + 3);
    M_hat0[vectorUB] = 0.0;
    M_hat0[6 * i + 3] = 0.0;
    M_hat0[vectorUB + 3] = robotBaseLink->mass * (double)iv[3 * i];
    scalarLB = 3 * i + 1;
    M_hat0[6 * i + 1] = I0[scalarLB];
    M_hat0[vectorUB + 1] = 0.0;
    M_hat0[6 * i + 4] = 0.0;
    M_hat0[vectorUB + 4] = robotBaseLink->mass * (double)iv[scalarLB];
    scalarLB = 3 * i + 2;
    M_hat0[6 * i + 2] = I0[scalarLB];
    M_hat0[vectorUB + 2] = 0.0;
    M_hat0[6 * i + 5] = 0.0;
    M_hat0[vectorUB + 5] = robotBaseLink->mass * (double)iv[scalarLB];
  }
  for (j = 0; j < b_loop_ub; j++) {
    if (robotConChildBase_data[j] != 0.0) {
      r = _mm_set1_pd(0.0);
      for (i1 = 0; i1 < 6; i1++) {
        r1 = _mm_loadu_pd(&psi_hat_data[j].f1[0]);
        r2 = _mm_loadu_pd(&M_hat_data[j].f1[6 * i1]);
        r3 = _mm_set1_pd(psi_data[j].f1[i1]);
        _mm_storeu_pd(&b_M_hat[6 * i1],
                      _mm_sub_pd(r2, _mm_add_pd(r, _mm_mul_pd(r1, r3))));
        r1 = _mm_loadu_pd(&psi_hat_data[j].f1[2]);
        scalarLB = 6 * i1 + 2;
        r2 = _mm_loadu_pd(&M_hat_data[j].f1[scalarLB]);
        _mm_storeu_pd(&b_M_hat[scalarLB],
                      _mm_sub_pd(r2, _mm_add_pd(r, _mm_mul_pd(r1, r3))));
        r1 = _mm_loadu_pd(&psi_hat_data[j].f1[4]);
        scalarLB = 6 * i1 + 4;
        r2 = _mm_loadu_pd(&M_hat_data[j].f1[scalarLB]);
        _mm_storeu_pd(&b_M_hat[scalarLB],
                      _mm_sub_pd(r2, _mm_add_pd(r, _mm_mul_pd(r1, r3))));
        for (i = 0; i < 6; i++) {
          b_pm = 0.0;
          for (b_i = 0; b_i < 6; b_i++) {
            b_pm += Bi0_data[j].f1[b_i + 6 * i] * b_M_hat[b_i + 6 * i1];
          }
          b_Bij[i + 6 * i1] = b_pm;
        }
      }
      for (b_i = 0; b_i < 6; b_i++) {
        for (i1 = 0; i1 < 6; i1++) {
          b_pm = 0.0;
          for (i = 0; i < 6; i++) {
            b_pm += b_Bij[b_i + 6 * i] * Bi0_data[j].f1[i + 6 * i1];
          }
          scalarLB = b_i + 6 * i1;
          M_hat0[scalarLB] += b_pm;
        }
      }
    }
  }
  emxFree_cell_wrap_1(&M_hat);
  /* === eta, phi_hat, phi_tilde ===% */
  emxInit_cell_wrap_3(&eta);
  scalarLB = eta->size[0];
  eta->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_3(eta, scalarLB);
  eta_data = eta->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (b_i = 0; b_i < 6; b_i++) {
      eta_data[i].f1[b_i] = 0.0;
    }
  }
  emxInit_real_T(&phi_hat, 1);
  scalarLB = phi_hat->size[0];
  phi_hat->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_real_T(phi_hat, scalarLB);
  phi_hat_data = phi_hat->data;
  for (i = 0; i < b_loop_ub; i++) {
    phi_hat_data[i] = 0.0;
  }
  emxInit_real_T(&phi_tilde, 1);
  loop_ub = (int)nQ;
  scalarLB = phi_tilde->size[0];
  phi_tilde->size[0] = (int)nQ;
  emxEnsureCapacity_real_T(phi_tilde, scalarLB);
  phi_tilde_data = phi_tilde->data;
  for (i = 0; i < loop_ub; i++) {
    phi_tilde_data[i] = 0.0;
  }
  for (j = 0; j < c_i; j++) {
    e_i = nLinksJoints - (double)j;
    for (i = 0; i < b_loop_ub; i++) {
      if (robotConChild_data[i + robotConChild->size[0] * ((int)e_i - 1)] !=
          0.0) {
        r = _mm_loadu_pd(&psi_data[i].f1[0]);
        r1 = _mm_loadu_pd(&eta_data[i].f1[0]);
        r2 = _mm_set1_pd(phi_hat_data[i]);
        _mm_storeu_pd(&b_psi[0], _mm_add_pd(_mm_mul_pd(r, r2), r1));
        r = _mm_loadu_pd(&psi_data[i].f1[2]);
        r1 = _mm_loadu_pd(&eta_data[i].f1[2]);
        _mm_storeu_pd(&b_psi[2], _mm_add_pd(_mm_mul_pd(r, r2), r1));
        r = _mm_loadu_pd(&psi_data[i].f1[4]);
        r1 = _mm_loadu_pd(&eta_data[i].f1[4]);
        _mm_storeu_pd(&b_psi[4], _mm_add_pd(_mm_mul_pd(r, r2), r1));
        for (b_i = 0; b_i < 6; b_i++) {
          b_pm = 0.0;
          for (i1 = 0; i1 < 6; i1++) {
            b_pm +=
                Bij_data[i + Bij->size[0] * ((int)e_i - 1)].f1[i1 + 6 * b_i] *
                b_psi[i1];
          }
          eta_data[(int)e_i - 1].f1[b_i] += b_pm;
        }
      }
    }
    b_pm = 0.0;
    for (i = 0; i < 6; i++) {
      b_pm += -pm_data[i + 6 * ((int)e_i - 1)] * eta_data[(int)e_i - 1].f1[i];
    }
    phi_hat_data[(int)e_i - 1] = b_pm;
    if (robotJoints_data[(int)e_i - 1].type != 0.0) {
      scalarLB = (int)robotJoints_data[(int)e_i - 1].q_id - 1;
      phi_hat_data[(int)e_i - 1] += phi_data[scalarLB];
      b_pm = 0.0;
      for (i = 0; i < 6; i++) {
        b_pm +=
            pm_data[i + 6 * ((int)e_i - 1)] * psi_hat_data[(int)e_i - 1].f1[i];
      }
      phi_tilde_data[scalarLB] = phi_hat_data[(int)e_i - 1] / b_pm;
    }
  }
  emxFree_real_T(&phi);
  /* === Base-link phi_tilde0 ===% */
  for (i = 0; i < 6; i++) {
    eta0[i] = 0.0;
  }
  for (i = 0; i < b_loop_ub; i++) {
    if (robotConChildBase_data[i] != 0.0) {
      r = _mm_loadu_pd(&psi_data[i].f1[0]);
      r1 = _mm_loadu_pd(&eta_data[i].f1[0]);
      r2 = _mm_set1_pd(phi_hat_data[i]);
      _mm_storeu_pd(&b_psi[0], _mm_add_pd(_mm_mul_pd(r, r2), r1));
      r = _mm_loadu_pd(&psi_data[i].f1[2]);
      r1 = _mm_loadu_pd(&eta_data[i].f1[2]);
      _mm_storeu_pd(&b_psi[2], _mm_add_pd(_mm_mul_pd(r, r2), r1));
      r = _mm_loadu_pd(&psi_data[i].f1[4]);
      r1 = _mm_loadu_pd(&eta_data[i].f1[4]);
      _mm_storeu_pd(&b_psi[4], _mm_add_pd(_mm_mul_pd(r, r2), r1));
      for (b_i = 0; b_i < 6; b_i++) {
        b_pm = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          b_pm += Bi0_data[i].f1[i1 + 6 * b_i] * b_psi[i1];
        }
        eta0[b_i] += b_pm;
      }
    }
  }
  emxFree_real_T(&phi_hat);
  emxFree_cell_wrap_3(&eta);
  for (i = 0; i < 6; i++) {
    for (b_i = 0; b_i < 6; b_i++) {
      b_M_hat[b_i + 6 * i] = P0[i + 6 * b_i];
    }
  }
  memset(&b_M_hat0[0], 0, 36U * sizeof(double));
  memset(&b_Bij[0], 0, 36U * sizeof(double));
  for (b_i = 0; b_i < 6; b_i++) {
    b_pm = 0.0;
    scalarLB = 6 * b_i + 2;
    vectorUB = 6 * b_i + 4;
    for (i = 0; i < 6; i++) {
      b_pm += b_M_hat[b_i + 6 * i] * eta0[i];
      r = _mm_loadu_pd(&M_hat0[6 * i]);
      r1 = _mm_loadu_pd(&b_M_hat0[6 * b_i]);
      r2 = _mm_set1_pd(P0[i + 6 * b_i]);
      _mm_storeu_pd(&b_M_hat0[6 * b_i], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&M_hat0[6 * i + 2]);
      r1 = _mm_loadu_pd(&b_M_hat0[scalarLB]);
      _mm_storeu_pd(&b_M_hat0[scalarLB], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&M_hat0[6 * i + 4]);
      r1 = _mm_loadu_pd(&b_M_hat0[vectorUB]);
      _mm_storeu_pd(&b_M_hat0[vectorUB], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    }
    u0dot[b_i] = (tau0[b_i] - tau0_0ddot[b_i]) - b_pm;
    scalarLB = 6 * b_i + 2;
    vectorUB = 6 * b_i + 4;
    for (i = 0; i < 6; i++) {
      r = _mm_loadu_pd(&b_M_hat[6 * i]);
      r1 = _mm_loadu_pd(&b_Bij[6 * b_i]);
      r2 = _mm_set1_pd(b_M_hat0[i + 6 * b_i]);
      _mm_storeu_pd(&b_Bij[6 * b_i], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&b_M_hat[6 * i + 2]);
      r1 = _mm_loadu_pd(&b_Bij[scalarLB]);
      _mm_storeu_pd(&b_Bij[scalarLB], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&b_M_hat[6 * i + 4]);
      r1 = _mm_loadu_pd(&b_Bij[vectorUB]);
      _mm_storeu_pd(&b_Bij[vectorUB], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    }
  }
  mldivide(b_Bij, u0dot);
  /* === Forward recursion for manipulator acceleration ===% */
  scalarLB = psi_hat->size[0];
  psi_hat->size[0] = (int)nLinksJoints;
  emxEnsureCapacity_cell_wrap_3(psi_hat, scalarLB);
  psi_hat_data = psi_hat->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (b_i = 0; b_i < 6; b_i++) {
      psi_hat_data[i].f1[b_i] = 0.0;
    }
  }
  scalarLB = umdot->size[0];
  umdot->size[0] = (int)nQ;
  emxEnsureCapacity_real_T(umdot, scalarLB);
  phi_data = umdot->data;
  for (i = 0; i < loop_ub; i++) {
    phi_data[i] = 0.0;
  }
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    if (robotJoints_data[b_i].parent_link == 0.0) {
      memset(&b_psi[0], 0, 6U * sizeof(double));
      for (i = 0; i < 6; i++) {
        r = _mm_loadu_pd(&b_psi[0]);
        r1 = _mm_set1_pd(u0dot[i]);
        _mm_storeu_pd(&b_psi[0],
                      _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i]), r1)));
        r = _mm_loadu_pd(&b_psi[2]);
        _mm_storeu_pd(
            &b_psi[2],
            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i + 2]), r1)));
        r = _mm_loadu_pd(&b_psi[4]);
        _mm_storeu_pd(
            &b_psi[4],
            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i + 4]), r1)));
        psi_hat_data[b_i].f1[i] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        r = _mm_loadu_pd(&psi_hat_data[b_i].f1[0]);
        r1 = _mm_set1_pd(b_psi[i]);
        _mm_storeu_pd(
            &psi_hat_data[b_i].f1[0],
            _mm_add_pd(r,
                       _mm_mul_pd(_mm_loadu_pd(&Bi0_data[b_i].f1[6 * i]), r1)));
        r = _mm_loadu_pd(&psi_hat_data[b_i].f1[2]);
        _mm_storeu_pd(
            &psi_hat_data[b_i].f1[2],
            _mm_add_pd(
                r, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[b_i].f1[6 * i + 2]), r1)));
        r = _mm_loadu_pd(&psi_hat_data[b_i].f1[4]);
        _mm_storeu_pd(
            &psi_hat_data[b_i].f1[4],
            _mm_add_pd(
                r, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[b_i].f1[6 * i + 4]), r1)));
      }
    } else {
      for (i = 0; i < 6; i++) {
        eta0[i] =
            psi_hat_data[(int)robotJoints_data[b_i].parent_link - 1].f1[i];
      }
      scalarLB = (int)robotJoints_data[b_i].parent_link - 1;
      if (robotJoints_data[scalarLB].type != 0.0) {
        r = _mm_loadu_pd(&psi_hat_data[scalarLB].f1[0]);
        r1 = _mm_set1_pd(phi_data[(int)robotJoints_data[scalarLB].q_id - 1]);
        _mm_storeu_pd(
            &eta0[0],
            _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&pm_data[6 * scalarLB]), r1),
                       r));
        r = _mm_loadu_pd(&psi_hat_data[scalarLB].f1[2]);
        _mm_storeu_pd(
            &eta0[2],
            _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&pm_data[6 * scalarLB + 2]), r1),
                       r));
        r = _mm_loadu_pd(&psi_hat_data[scalarLB].f1[4]);
        _mm_storeu_pd(
            &eta0[4],
            _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&pm_data[6 * scalarLB + 4]), r1),
                       r));
      }
      for (i = 0; i < 6; i++) {
        psi_hat_data[b_i].f1[i] = 0.0;
      }
      for (i = 0; i < 6; i++) {
        r = _mm_loadu_pd(&psi_hat_data[b_i].f1[0]);
        r1 = _mm_set1_pd(eta0[i]);
        _mm_storeu_pd(
            &psi_hat_data[b_i].f1[0],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(
                           &Bij_data[b_i + Bij->size[0] * (b_i - 1)].f1[6 * i]),
                       r1)));
        r = _mm_loadu_pd(&psi_hat_data[b_i].f1[2]);
        _mm_storeu_pd(
            &psi_hat_data[b_i].f1[2],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(&Bij_data[b_i + Bij->size[0] * (b_i - 1)]
                                         .f1[6 * i + 2]),
                       r1)));
        r = _mm_loadu_pd(&psi_hat_data[b_i].f1[4]);
        _mm_storeu_pd(
            &psi_hat_data[b_i].f1[4],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(&Bij_data[b_i + Bij->size[0] * (b_i - 1)]
                                         .f1[6 * i + 4]),
                       r1)));
      }
    }
    if (robotJoints_data[b_i].type != 0.0) {
      b_pm = 0.0;
      for (i = 0; i < 6; i++) {
        b_pm += psi_data[b_i].f1[i] * psi_hat_data[b_i].f1[i];
      }
      scalarLB = (int)robotJoints_data[b_i].q_id - 1;
      phi_data[scalarLB] = phi_tilde_data[scalarLB] - b_pm;
    }
  }
  emxFree_real_T(&phi_tilde);
  emxFree_cell_wrap_3(&psi);
  emxFree_cell_wrap_3(&psi_hat);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                int in3
 *                int in4
 * Return Type  : void
 */
void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2, int in3,
                      int in4)
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
  stride_0_0 = (in4 - in3) + 1;
  if (in1->size[0] == 1) {
    loop_ub = stride_0_0;
  } else {
    loop_ub = in1->size[0];
  }
  stride_1_0 = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in2, stride_1_0);
  b_in2_data = b_in2->data;
  stride_0_0 = (stride_0_0 != 1);
  stride_1_0 = (in1->size[0] != 1);
  if (loop_ub < 1600) {
    for (i = 0; i < loop_ub; i++) {
      b_in2_data[i] = in2_data[in3 + i * stride_0_0] - in1_data[i * stride_1_0];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (i = 0; i < loop_ub; i++) {
      b_in2_data[i] = in2_data[in3 + i * stride_0_0] - in1_data[i * stride_1_0];
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
 * File trailer for FD_C.c
 *
 * [EOF]
 */
