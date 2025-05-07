/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Jacob.c
 *
 * Code generation for function 'Jacob'
 *
 */

/* Include files */
#include "Jacob.h"
#include "Jacob_data.h"
#include "Jacob_emxutil.h"
#include "Jacob_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    31,                 /* colNo */
    "robot.con.branch", /* aName */
    "Jacob",            /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    65,      /* lineNo */
    29,      /* colNo */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    29,                 /* colNo */
    "robot.con.branch", /* aName */
    "Jacob",            /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    64,             /* lineNo */
    21,             /* colNo */
    "robot.joints", /* aName */
    "Jacob",        /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    66,      /* lineNo */
    20,      /* colNo */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    66,      /* lineNo */
    20,      /* colNo */
    "Jm",    /* aName */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    68,      /* lineNo */
    20,      /* colNo */
    "Jm",    /* aName */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    0                              /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    68,      /* lineNo */
    20,      /* colNo */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    1                              /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    66,      /* lineNo */
    98,      /* colNo */
    "pm",    /* aName */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    66,      /* lineNo */
    76,      /* colNo */
    "rL",    /* aName */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    62,      /* lineNo */
    7,       /* colNo */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m" /* pName */
};

static emlrtDCInfo d_emlrtDCI = {
    57,      /* lineNo */
    12,      /* colNo */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    1                              /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    57,      /* lineNo */
    12,      /* colNo */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m", /* pName */
    4                              /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    57,      /* lineNo */
    1,       /* colNo */
    "Jacob", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Jacob.m" /* pName */
};

/* Function Definitions */
void Jacob(const emlrtStack *sp, const real_T rp[3], const real_T r0[3],
           const emxArray_real_T *rL, const real_T P0[36],
           const emxArray_real_T *pm, real_T i, const struct0_T *robot,
           real_T J0[36], emxArray_real_T *Jm)
{
  static const int8_T iv[18] = {1, 0, 0, 0, 1, 0, 0, 0, 1,
                                0, 0, 0, 0, 0, 0, 0, 0, 0};
  static const int8_T iv1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  __m128d r;
  __m128d r1;
  __m128d r2;
  real_T dv[36];
  real_T x[3];
  const real_T *pm_data;
  const real_T *rL_data;
  real_T *Jm_data;
  int32_T b_i;
  int32_T i1;
  int32_T j;
  int32_T loop_ub;
  pm_data = pm->data;
  rL_data = rL->data;
  /*  Computes the geometric Jacobian of a point `p`. */
  /*  */
  /*  [J0, Jm]=Jacob(rp,r0,rL,P0,pm,i,robot) */
  /*   */
  /*  :parameters:  */
  /*    * rp -- Position of the point of interest, projected in the inertial CCS
   * -- [3x1]. */
  /*    * r0 -- Position of the base-link, projected in the inertial CCS --
   * [3x1]. */
  /*    * rL -- Positions of the links, projected in the inertial CCS -- as a
   * [3xn] matrix. */
  /*    * P0 -- Base-link twist-propagation "vector" -- as a [6x6] matrix. */
  /*    * pm -- Manipulator twist-propagation "vector" -- as a [6xn] matrix. */
  /*    * i -- Link id where the point `p` is located -- int 0 to n. */
  /*    * robot -- Robot model (see :doc:`/Tutorial_Robot`). */
  /*  */
  /*  :return:  */
  /*    * J0 -- Base-link geometric Jacobian -- [6x6]. */
  /*    * Jm -- Manipulator geometric Jacobian -- [6xn_q]. */
  /*  */
  /*  Examples: */
  /*  */
  /*    To compute the velocity of the point `p` on the ith link: */
  /*  */
  /*  .. code-block:: matlab */
  /*     */
  /*    %Compute Jacobians */
  /*    [J0, Jm]=Jacob(rp,r0,rL,P0,pm,i,robot); */
  /*    %Twist of that point */
  /*    tp=J0*u0+Jm*um; */
  /*  */
  /*  See also: :func:`src.kinematics_dynamics.Kinematics`,
   * :func:`src.kinematics_dynamics.DiffKinematics` */
  /* {   */
  /*     LICENSE */
  /*  */
  /*     This program is free software: you can redistribute it and/or modify */
  /*     it under the terms of the GNU Lesser General Public License as
   * published by */
  /*     the Free Software Foundation, either version 3 of the License, or */
  /*     (at your option) any later version. */
  /*  */
  /*     This program is distributed in the hope that it will be useful, */
  /*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*     GNU Lesser General Public License for more details. */
  /*  */
  /*     You should have received a copy of the GNU Lesser General Public
   * License */
  /*     along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */
  /* } */
  /* === CODE ===% */
  /* --- Number of links  ---% */
  /* Base-link Jacobian */
  _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&r0[0]), _mm_loadu_pd(&rp[0])));
  x[2] = r0[2] - rp[2];
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
    dv[6 * b_i] = iv[3 * b_i];
    dv[6 * b_i + 1] = iv[3 * b_i + 1];
    dv[6 * b_i + 2] = iv[3 * b_i + 2];
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
    dv[loop_ub + 3] = iv1[3 * b_i];
    dv[loop_ub + 4] = iv1[3 * b_i + 1];
    dv[loop_ub + 5] = iv1[3 * b_i + 2];
  }
  memset(&J0[0], 0, 36U * sizeof(real_T));
  for (b_i = 0; b_i < 6; b_i++) {
    loop_ub = 6 * b_i + 2;
    i1 = 6 * b_i + 4;
    for (j = 0; j < 6; j++) {
      r = _mm_loadu_pd(&dv[6 * j]);
      r1 = _mm_loadu_pd(&J0[6 * b_i]);
      r2 = _mm_set1_pd(P0[j + 6 * b_i]);
      _mm_storeu_pd(&J0[6 * b_i], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&dv[6 * j + 2]);
      r1 = _mm_loadu_pd(&J0[loop_ub]);
      _mm_storeu_pd(&J0[loop_ub], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&dv[6 * j + 4]);
      r1 = _mm_loadu_pd(&J0[i1]);
      _mm_storeu_pd(&J0[i1], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    }
  }
  /* Pre-allocate */
  if (!(robot->n_q >= 0.0)) {
    emlrtNonNegativeCheckR2012b(robot->n_q, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (robot->n_q != (int32_T)muDoubleScalarFloor(robot->n_q)) {
    emlrtIntegerCheckR2012b(robot->n_q, &d_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = Jm->size[0] * Jm->size[1];
  Jm->size[0] = 6;
  Jm->size[1] = (int32_T)robot->n_q;
  emxEnsureCapacity_real_T(sp, Jm, loop_ub, &b_emlrtRTEI);
  Jm_data = Jm->data;
  loop_ub = 6 * (int32_T)robot->n_q;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    Jm_data[b_i] = 0.0;
  }
  /* Manipulator Jacobian */
  /* Iterate through all "previous" joints */
  i1 = (int32_T)i;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, i, mxDOUBLE_CLASS, (int32_T)i,
                                &emlrtRTEI, (emlrtConstCTX)sp);
  for (j = 0; j < i1; j++) {
    boolean_T b;
    /* If joint is not fixed */
    b = (((int32_T)((uint32_T)j + 1U) < 1) ||
         ((int32_T)((uint32_T)j + 1U) > robot->joints->size[1]));
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                    robot->joints->size[1], &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (robot->joints->data[j].type != 0.0) {
      if (((int32_T)((uint32_T)j + 1U) < 1) ||
          ((int32_T)((uint32_T)j + 1U) > robot->con.branch->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                      robot->con.branch->size[1], &emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (i != (int32_T)muDoubleScalarFloor(i)) {
        emlrtIntegerCheckR2012b(i, &emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)i < 1) || ((int32_T)i > robot->con.branch->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)i, 1, robot->con.branch->size[0],
                                      &b_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (robot->con.branch
              ->data[((int32_T)i + robot->con.branch->size[0] * j) - 1] ==
          1.0) {
        real_T d;
        if (((int32_T)((uint32_T)j + 1U) < 1) ||
            ((int32_T)((uint32_T)j + 1U) > rL->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        rL->size[1], &g_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&rL_data[3 * j]),
                                        _mm_loadu_pd(&rp[0])));
        x[2] = rL_data[3 * j + 2] - rp[2];
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
        if ((j + 1 < 1) || (j + 1 > pm->size[1])) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, pm->size[1], &f_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        for (b_i = 0; b_i < 6; b_i++) {
          dv[6 * b_i] = iv[3 * b_i];
          dv[6 * b_i + 1] = iv[3 * b_i + 1];
          dv[6 * b_i + 2] = iv[3 * b_i + 2];
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
          dv[loop_ub + 3] = iv1[3 * b_i];
          dv[loop_ub + 4] = iv1[3 * b_i + 1];
          dv[loop_ub + 5] = iv1[3 * b_i + 2];
        }
        d = robot->joints->data[j].q_id;
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &b_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)d < 1) || ((int32_T)d > Jm->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Jm->size[1], &d_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        for (b_i = 0; b_i < 6; b_i++) {
          Jm_data[b_i + 6 * ((int32_T)d - 1)] = 0.0;
        }
        loop_ub = 6 * ((int32_T)d - 1);
        for (b_i = 0; b_i < 6; b_i++) {
          r = _mm_loadu_pd(&dv[6 * b_i]);
          r1 = _mm_loadu_pd(&Jm_data[loop_ub]);
          r2 = _mm_set1_pd(pm_data[b_i + 6 * j]);
          _mm_storeu_pd(&Jm_data[loop_ub], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&dv[6 * b_i + 2]);
          r1 = _mm_loadu_pd(&Jm_data[loop_ub + 2]);
          _mm_storeu_pd(&Jm_data[loop_ub + 2],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&dv[6 * b_i + 4]);
          r1 = _mm_loadu_pd(&Jm_data[loop_ub + 4]);
          _mm_storeu_pd(&Jm_data[loop_ub + 4],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        }
      } else {
        real_T d;
        d = robot->joints->data[j].q_id;
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &c_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)d < 1) || ((int32_T)d > Jm->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Jm->size[1], &e_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        for (b_i = 0; b_i < 6; b_i++) {
          Jm_data[b_i + 6 * ((int32_T)robot->joints->data[j].q_id - 1)] = 0.0;
        }
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

/* End of code generation (Jacob.c) */
