/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Jstar.c
 *
 * Code generation for function 'Jstar'
 *
 */

/* Include files */
#include "Jstar.h"
#include "Jstar_emxutil.h"
#include "Jstar_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "blas.h"
#include "lapacke.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    4,       /* lineNo */
    "Jstar", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jstar.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    5,       /* lineNo */
    "Jstar", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jstar.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    20,         /* lineNo */
    "mldivide", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/ops/mldivide.m" /* pathName
                                                                      */
};

static emlrtRSInfo d_emlrtRSI = {
    42,      /* lineNo */
    "mldiv", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/ops/mldivide.m" /* pathName
                                                                      */
};

static emlrtRSInfo e_emlrtRSI = {
    67,        /* lineNo */
    "lusolve", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo f_emlrtRSI = {
    109,          /* lineNo */
    "lusolveNxN", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo g_emlrtRSI = {
    112,          /* lineNo */
    "lusolveNxN", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo h_emlrtRSI = {
    124,          /* lineNo */
    "InvAtimesX", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo i_emlrtRSI = {
    19,        /* lineNo */
    "xgetrfs", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    108,      /* lineNo */
    "cmldiv", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    90,              /* lineNo */
    "warn_singular", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo l_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI =
    {
        142,      /* lineNo */
        "mtimes", /* fcnName */
        "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI =
    {
        177,           /* lineNo */
        "mtimes_blas", /* fcnName */
        "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    2,       /* nDims */
    5,       /* lineNo */
    9,       /* colNo */
    "Jstar", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jstar.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    4,       /* lineNo */
    1,       /* colNo */
    "Jstar", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jstar.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    5,       /* lineNo */
    1,       /* colNo */
    "Jstar", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jstar.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI =
    {
        218,      /* lineNo */
        20,       /* colNo */
        "mtimes", /* fName */
        "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    5,       /* lineNo */
    9,       /* colNo */
    "Jstar", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jstar.m" /* pName */
};

/* Function Declarations */
static void minus(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2);

/* Function Definitions */
static void minus(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2)
{
  emxArray_real_T *b_in2;
  const real_T *in2_data;
  real_T *b_in2_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in2, &g_emlrtRTEI);
  stride_0_1 = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = 6;
  if (in1->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in1->size[1];
  }
  b_in2->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in2, stride_0_1, &g_emlrtRTEI);
  b_in2_data = b_in2->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in1->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&in2_data[6 * aux_0_1]);
    r1 = _mm_loadu_pd(&in1_data[6 * aux_1_1]);
    _mm_storeu_pd(&b_in2_data[6 * i], _mm_sub_pd(r, r1));
    r = _mm_loadu_pd(&in2_data[6 * aux_0_1 + 2]);
    r1 = _mm_loadu_pd(&in1_data[6 * aux_1_1 + 2]);
    _mm_storeu_pd(&b_in2_data[6 * i + 2], _mm_sub_pd(r, r1));
    r = _mm_loadu_pd(&in2_data[6 * aux_0_1 + 4]);
    r1 = _mm_loadu_pd(&in1_data[6 * aux_1_1 + 4]);
    _mm_storeu_pd(&b_in2_data[6 * i + 4], _mm_sub_pd(r, r1));
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  stride_0_1 = in1->size[0] * in1->size[1];
  in1->size[0] = 6;
  emxEnsureCapacity_real_T(sp, in1, stride_0_1, &g_emlrtRTEI);
  stride_1_1 = b_in2->size[1];
  stride_0_1 = in1->size[0] * in1->size[1];
  in1->size[1] = b_in2->size[1];
  emxEnsureCapacity_real_T(sp, in1, stride_0_1, &g_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < stride_1_1; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      stride_0_1 = i1 + 6 * i;
      in1_data[stride_0_1] = b_in2_data[stride_0_1];
    }
  }
  emxFree_real_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void Jstar(const emlrtStack *sp, const real_T H0[36],
           const emxArray_real_T *H0m, const real_T J0[36],
           const emxArray_real_T *Jm, emxArray_real_T *b_Jstar)
{
  static const char_T fname[19] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 't', 'r', 'f',
                                   '_', 'w', 'o', 'r', 'k'};
  ptrdiff_t IPIV[6];
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_real_T *h;
  real_T A[36];
  const real_T *H0m_data;
  const real_T *Jm_data;
  real_T alpha1;
  real_T beta1;
  real_T *Jstar_data;
  real_T *h_data;
  int32_T i;
  int32_T scalarLB;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  Jm_data = Jm->data;
  H0m_data = H0m->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  This is formula 45.6 in "Handbook of Robotics" - Siciliano, Springer */
  st.site = &emlrtRSI;
  b_st.site = &c_emlrtRSI;
  emxInit_real_T(&b_st, &h, &c_emlrtRTEI);
  h_data = h->data;
  if (H0m->size[1] == 0) {
    h->size[0] = 6;
    h->size[1] = 0;
  } else {
    c_st.site = &d_emlrtRSI;
    d_st.site = &e_emlrtRSI;
    scalarLB = h->size[0] * h->size[1];
    h->size[0] = 6;
    h->size[1] = H0m->size[1];
    emxEnsureCapacity_real_T(&d_st, h, scalarLB, &c_emlrtRTEI);
    h_data = h->data;
    scalarLB = 6 * H0m->size[1];
    for (i = 0; i < scalarLB; i++) {
      h_data[i] = H0m_data[i];
    }
    e_st.site = &f_emlrtRSI;
    f_st.site = &h_emlrtRSI;
    g_st.site = &i_emlrtRSI;
    memcpy(&A[0], &H0[0], 36U * sizeof(real_T));
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)6;
    k_t = LAPACKE_dgetrf_work(102, m_t, m_t, &A[0], n_t, &IPIV[0]);
    h_st.site = &j_emlrtRSI;
    if ((int32_T)k_t < 0) {
      if ((int32_T)k_t == -1010) {
        emlrtErrorWithMessageIdR2018a(&h_st, &b_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&h_st, &emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      19, &fname[0], 12, (int32_T)k_t);
      }
    }
    LAPACKE_dgetrs_work(102, 'N', m_t, (ptrdiff_t)h->size[1], &A[0], n_t,
                        &IPIV[0], &h_data[0], (ptrdiff_t)6);
    if ((int32_T)k_t > 0) {
      e_st.site = &g_emlrtRSI;
      f_st.site = &k_emlrtRSI;
      warning(&f_st);
    }
  }
  st.site = &b_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  if (h->size[1] == 0) {
    b_Jstar->size[0] = 6;
    b_Jstar->size[1] = 0;
  } else {
    c_st.site = &m_emlrtRSI;
    d_st.site = &n_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)h->size[1];
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)6;
    scalarLB = b_Jstar->size[0] * b_Jstar->size[1];
    b_Jstar->size[0] = 6;
    b_Jstar->size[1] = h->size[1];
    emxEnsureCapacity_real_T(&d_st, b_Jstar, scalarLB, &e_emlrtRTEI);
    Jstar_data = b_Jstar->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&J0[0],
          &lda_t, &h_data[0], &ldb_t, &beta1, &Jstar_data[0], &ldc_t);
  }
  emxFree_real_T(&b_st, &h);
  if ((Jm->size[1] != b_Jstar->size[1]) &&
      ((Jm->size[1] != 1) && (b_Jstar->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(Jm->size[1], b_Jstar->size[1], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (Jm->size[1] == b_Jstar->size[1]) {
    int32_T loop_ub;
    int32_T vectorUB;
    loop_ub = 6 * Jm->size[1];
    scalarLB = b_Jstar->size[0] * b_Jstar->size[1];
    b_Jstar->size[0] = 6;
    b_Jstar->size[1] = Jm->size[1];
    emxEnsureCapacity_real_T(sp, b_Jstar, scalarLB, &d_emlrtRTEI);
    Jstar_data = b_Jstar->data;
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      __m128d r;
      r = _mm_loadu_pd(&Jstar_data[i]);
      _mm_storeu_pd(&Jstar_data[i], _mm_sub_pd(_mm_loadu_pd(&Jm_data[i]), r));
    }
    for (i = scalarLB; i < loop_ub; i++) {
      Jstar_data[i] = Jm_data[i] - Jstar_data[i];
    }
  } else {
    st.site = &b_emlrtRSI;
    minus(&st, b_Jstar, Jm);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (Jstar.c) */
