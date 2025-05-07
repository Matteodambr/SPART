/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * GIM.c
 *
 * Code generation for function 'GIM'
 *
 */

/* Include files */
#include "GIM.h"
#include "GIM_data.h"
#include "GIM_emxutil.h"
#include "GIM_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtDCInfo emlrtDCI = {
    69,    /* lineNo */
    37,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    69,    /* lineNo */
    37,    /* colNo */
    "Hm",  /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    69,             /* lineNo */
    29,             /* colNo */
    "robot.joints", /* aName */
    "GIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    69,    /* lineNo */
    16,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    69,    /* lineNo */
    16,    /* colNo */
    "Hm",  /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    69,             /* lineNo */
    96,             /* colNo */
    "robot.joints", /* aName */
    "GIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    69,    /* lineNo */
    83,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    69,    /* lineNo */
    83,    /* colNo */
    "Hm",  /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    69,             /* lineNo */
    75,             /* colNo */
    "robot.joints", /* aName */
    "GIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    69,    /* lineNo */
    62,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    69,    /* lineNo */
    62,    /* colNo */
    "Hm",  /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    68,    /* lineNo */
    37,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    68,    /* lineNo */
    37,    /* colNo */
    "Hm",  /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    68,             /* lineNo */
    29,             /* colNo */
    "robot.joints", /* aName */
    "GIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    68,    /* lineNo */
    16,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    68,    /* lineNo */
    16,    /* colNo */
    "Hm",  /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    79,             /* lineNo */
    21,             /* colNo */
    "robot.joints", /* aName */
    "GIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    67,             /* lineNo */
    52,             /* colNo */
    "robot.joints", /* aName */
    "GIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    67,             /* lineNo */
    25,             /* colNo */
    "robot.joints", /* aName */
    "GIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    80,    /* lineNo */
    17,    /* colNo */
    "H0m", /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    80,    /* lineNo */
    17,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    80,    /* lineNo */
    83,    /* colNo */
    "Bi0", /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    80,         /* lineNo */
    68,         /* colNo */
    "Mm_tilde", /* aName */
    "GIM",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    80,    /* lineNo */
    47,    /* colNo */
    "pm",  /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    78,    /* lineNo */
    7,     /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m" /* pName */
};

static emlrtDCInfo h_emlrtDCI = {
    75,    /* lineNo */
    13,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    68,    /* lineNo */
    114,   /* colNo */
    "pm",  /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    68,    /* lineNo */
    104,   /* colNo */
    "Bij", /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    68,    /* lineNo */
    102,   /* colNo */
    "Bij", /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    68,         /* lineNo */
    87,         /* colNo */
    "Mm_tilde", /* aName */
    "GIM",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    68,    /* lineNo */
    66,    /* colNo */
    "pm",  /* aName */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    66,    /* lineNo */
    11,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    65,    /* lineNo */
    7,     /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m" /* pName */
};

static emlrtDCInfo i_emlrtDCI = {
    62,    /* lineNo */
    14,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    62,    /* lineNo */
    10,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    62,    /* lineNo */
    10,    /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m", /* pName */
    4                            /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    62,    /* lineNo */
    1,     /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    75,    /* lineNo */
    1,     /* colNo */
    "GIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/GIM.m" /* pName */
};

/* Function Definitions */
void GIM(const emlrtStack *sp, const real_T M0_tilde[36],
         const emxArray_real_T *Mm_tilde, const emxArray_real_T *Bij,
         const emxArray_real_T *Bi0, const real_T P0[36],
         const emxArray_real_T *pm, const struct0_T *robot, real_T H0[36],
         emxArray_real_T *H0m, emxArray_real_T *Hm)
{
  real_T b_P0[36];
  real_T b_pm[6];
  real_T c_pm[6];
  const real_T *Bi0_data;
  const real_T *Bij_data;
  const real_T *Mm_tilde_data;
  const real_T *pm_data;
  real_T d;
  real_T n;
  real_T *Hm_data;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T j;
  int32_T loop_ub;
  boolean_T b;
  pm_data = pm->data;
  Bi0_data = Bi0->data;
  Bij_data = Bij->data;
  Mm_tilde_data = Mm_tilde->data;
  /*  Computes the Generalized Inertia Matrix (GIM) H of the multibody vehicle.
   */
  /*  */
  /*  This function uses a recursive algorithm. */
  /*  */
  /*  [H0, H0m, Hm] = GIM(M0_tilde,Mm_tilde,Bij,Bi0,P0,pm,robot) */
  /*  */
  /*  :parameters:  */
  /*    * M0_tilde -- Base-link mass composite body matrix -- as a [6x6] matrix
   * . */
  /*    * Mm_tilde -- Manipulator mass composite body matrix -- as a [6x6xn]
   * matrix. */
  /*    * Bij -- Twist-propagation matrix (for manipulator i>0 and j>0) -- as a
   * [6x6xn] matrix. */
  /*    * Bi0 -- Twist-propagation matrix (for i>0 and j=0) -- as a [6x6xn]
   * matrix. */
  /*    * P0 -- Base-link twist-propagation "vector" -- as a [6x6] matrix. */
  /*    * pm -- Manipulator twist-propagation "vector" -- as a [6xn] matrix. */
  /*    * robot -- Robot model (see :doc:`/Tutorial_Robot`). */
  /*  */
  /*  :return:  */
  /*    * H0 -- Base-link inertia matrix -- as a [6x6] matrix. */
  /*    * H0m -- Base-link -- manipulator coupling inertia matrix -- as a
   * [6xn_q] matrix. */
  /*    * Hm -- Manipulator inertia matrix -- as a [n_qxn_q] matrix. */
  /*     */
  /*  To obtain the full generalized inertia matrix H: */
  /*  */
  /*  .. code-block:: matlab */
  /*     */
  /*    %Compute H */
  /*    [H0, H0m, Hm] = GIM(M0_tilde,Mm_tilde,Bij,Bi0,P0,pm,robot); */
  /*    H=[H0,H0m;H0m';Hm]; */
  /*  */
  /*  See also: :func:`src.kinematics_dynamics.CIM`. */
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
  /* --- Number of links and Joints ---% */
  n = robot->n_links_joints;
  /* --- H matrix ---% */
  /* Base-link inertia matrix */
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (j = 0; j < 6; j++) {
        d += P0[j + 6 * i1] * M0_tilde[j + 6 * i];
      }
      b_P0[i1 + 6 * i] = d;
    }
  }
  memset(&H0[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    loop_ub = 6 * i + 2;
    b_loop_ub = 6 * i + 4;
    for (i1 = 0; i1 < 6; i1++) {
      __m128d r;
      __m128d r1;
      __m128d r2;
      r = _mm_loadu_pd(&b_P0[6 * i1]);
      r1 = _mm_loadu_pd(&H0[6 * i]);
      r2 = _mm_set1_pd(P0[i1 + 6 * i]);
      _mm_storeu_pd(&H0[6 * i], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&b_P0[6 * i1 + 2]);
      r1 = _mm_loadu_pd(&H0[loop_ub]);
      _mm_storeu_pd(&H0[loop_ub], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&b_P0[6 * i1 + 4]);
      r1 = _mm_loadu_pd(&H0[b_loop_ub]);
      _mm_storeu_pd(&H0[b_loop_ub], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    }
  }
  /* Pre-allocate Hm */
  if (!(robot->n_q >= 0.0)) {
    emlrtNonNegativeCheckR2012b(robot->n_q, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (robot->n_q != (int32_T)muDoubleScalarFloor(robot->n_q)) {
    emlrtIntegerCheckR2012b(robot->n_q, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  b_loop_ub = (int32_T)muDoubleScalarFloor(robot->n_q);
  if (robot->n_q != b_loop_ub) {
    emlrtIntegerCheckR2012b(robot->n_q, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  i2 = (int32_T)robot->n_q;
  loop_ub = Hm->size[0] * Hm->size[1];
  Hm->size[0] = i2;
  Hm->size[1] = i2;
  emxEnsureCapacity_real_T(sp, Hm, loop_ub, &d_emlrtRTEI);
  Hm_data = Hm->data;
  loop_ub = i2 * i2;
  for (i = 0; i < loop_ub; i++) {
    Hm_data[i] = 0.0;
  }
  /* Manipulator inertia matrix Hm */
  i3 = (int32_T)robot->n_links_joints;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &c_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (j = 0; j < i3; j++) {
    loop_ub = (int32_T)(n + (1.0 - ((real_T)j + 1.0)));
    emlrtForLoopVectorCheckR2021a((real_T)j + 1.0, 1.0, n, mxDOUBLE_CLASS,
                                  loop_ub, &b_emlrtRTEI, (emlrtConstCTX)sp);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      uint32_T c_i;
      c_i = ((uint32_T)j + (uint32_T)b_i) + 1U;
      b = (((int32_T)c_i < 1) || ((int32_T)c_i > robot->joints->size[1]));
      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, robot->joints->size[1],
                                      &m_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (robot->joints->data[(int32_T)c_i - 1].type != 0.0) {
        b = (((int32_T)((uint32_T)j + 1U) < 1) ||
             ((int32_T)((uint32_T)j + 1U) > robot->joints->size[1]));
        if (b) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        robot->joints->size[1], &l_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (robot->joints->data[j].type != 0.0) {
          real_T d1;
          real_T d2;
          real_T d3;
          real_T d_pm;
          if (((int32_T)c_i < 1) || ((int32_T)c_i > pm->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, pm->size[1],
                                          &v_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)c_i < 1) || ((int32_T)c_i > Mm_tilde->size[2])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, Mm_tilde->size[2],
                                          &u_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)c_i < 1) || ((int32_T)c_i > Bij->size[2])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, Bij->size[2],
                                          &t_emlrtBCI, (emlrtConstCTX)sp);
          }
          if ((j + 1 < 1) || (j + 1 > Bij->size[3])) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, Bij->size[3], &s_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if ((j + 1 < 1) || (j + 1 > pm->size[1])) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, pm->size[1], &r_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          memset(&b_pm[0], 0, 6U * sizeof(real_T));
          for (i = 0; i < 6; i++) {
            d = b_pm[i];
            for (i1 = 0; i1 < 6; i1++) {
              d += pm_data[i1 + 6 * ((int32_T)c_i - 1)] *
                   Mm_tilde_data[(i1 + 6 * i) + 36 * ((int32_T)c_i - 1)];
            }
            b_pm[i] = d;
          }
          memset(&c_pm[0], 0, 6U * sizeof(real_T));
          d_pm = 0.0;
          for (i = 0; i < 6; i++) {
            d = c_pm[i];
            for (i1 = 0; i1 < 6; i1++) {
              d +=
                  b_pm[i1] * Bij_data[((i1 + 6 * i) + 36 * ((int32_T)c_i - 1)) +
                                      36 * Bij->size[2] * j];
            }
            c_pm[i] = d;
            d_pm += d * pm_data[i + 6 * j];
          }
          d = robot->joints->data[j].q_id;
          d1 = (int32_T)muDoubleScalarFloor(d);
          if (d != d1) {
            emlrtIntegerCheckR2012b(d, &e_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d < 1) || ((int32_T)d > Hm->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Hm->size[1],
                                          &h_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)c_i < 1) || ((int32_T)c_i > robot->joints->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1,
                                          robot->joints->size[1], &i_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          d2 = robot->joints->data[(int32_T)c_i - 1].q_id;
          d3 = (int32_T)muDoubleScalarFloor(d2);
          if (d2 != d3) {
            emlrtIntegerCheckR2012b(d2, &f_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d2 < 1) || ((int32_T)d2 > Hm->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d2, 1, Hm->size[0],
                                          &j_emlrtBCI, (emlrtConstCTX)sp);
          }
          Hm_data[((int32_T)d2 + Hm->size[0] * ((int32_T)d - 1)) - 1] = d_pm;
          if (d2 != d3) {
            emlrtIntegerCheckR2012b(d2, &emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d2 < 1) || ((int32_T)d2 > Hm->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d2, 1, Hm->size[1],
                                          &emlrtBCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)((uint32_T)j + 1U) < 1) ||
              ((int32_T)((uint32_T)j + 1U) > robot->joints->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                          robot->joints->size[1], &b_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (d != d1) {
            emlrtIntegerCheckR2012b(d, &b_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d < 1) || ((int32_T)d > Hm->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Hm->size[0],
                                          &c_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)((uint32_T)j + 1U) < 1) ||
              ((int32_T)((uint32_T)j + 1U) > robot->joints->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                          robot->joints->size[1], &d_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (d != d1) {
            emlrtIntegerCheckR2012b(d, &c_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d < 1) || ((int32_T)d > Hm->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Hm->size[1],
                                          &e_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)c_i < 1) || ((int32_T)c_i > robot->joints->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1,
                                          robot->joints->size[1], &f_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (d2 != d3) {
            emlrtIntegerCheckR2012b(d2, &d_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)d2 < 1) || ((int32_T)d2 > Hm->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d2, 1, Hm->size[0],
                                          &g_emlrtBCI, (emlrtConstCTX)sp);
          }
          Hm_data[((int32_T)d + Hm->size[0] * ((int32_T)d2 - 1)) - 1] =
              Hm_data[((int32_T)d2 + Hm->size[0] * ((int32_T)d - 1)) - 1];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* Pre-allocate H0m */
  if (i2 != b_loop_ub) {
    emlrtIntegerCheckR2012b(robot->n_q, &h_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = H0m->size[0] * H0m->size[1];
  H0m->size[0] = 6;
  H0m->size[1] = i2;
  emxEnsureCapacity_real_T(sp, H0m, loop_ub, &e_emlrtRTEI);
  Hm_data = H0m->data;
  b_loop_ub = 6 * i2;
  for (i = 0; i < b_loop_ub; i++) {
    Hm_data[i] = 0.0;
  }
  /* Coupling inertia matrix */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (j = 0; j < i3; j++) {
    b = (((int32_T)((uint32_T)j + 1U) < 1) ||
         ((int32_T)((uint32_T)j + 1U) > robot->joints->size[1]));
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                    robot->joints->size[1], &k_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (robot->joints->data[j].type != 0.0) {
      if ((j + 1 < 1) || (j + 1 > pm->size[1])) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, pm->size[1], &q_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((j + 1 < 1) || (j + 1 > Mm_tilde->size[2])) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, Mm_tilde->size[2], &p_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((j + 1 < 1) || (j + 1 > Bi0->size[2])) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, Bi0->size[2], &o_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      memset(&b_pm[0], 0, 6U * sizeof(real_T));
      for (i = 0; i < 6; i++) {
        d = b_pm[i];
        for (i1 = 0; i1 < 6; i1++) {
          d += pm_data[i1 + 6 * j] * Mm_tilde_data[(i1 + 6 * i) + 36 * j];
        }
        b_pm[i] = d;
      }
      memset(&c_pm[0], 0, 6U * sizeof(real_T));
      for (i = 0; i < 6; i++) {
        d = c_pm[i];
        for (i1 = 0; i1 < 6; i1++) {
          d += b_pm[i1] * Bi0_data[(i1 + 6 * i) + 36 * j];
        }
        c_pm[i] = d;
      }
      memset(&b_pm[0], 0, 6U * sizeof(real_T));
      for (i = 0; i < 6; i++) {
        d = b_pm[i];
        for (i1 = 0; i1 < 6; i1++) {
          d += c_pm[i1] * P0[i1 + 6 * i];
        }
        b_pm[i] = d;
      }
      d = robot->joints->data[j].q_id;
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &g_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > i2)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, i2, &n_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      for (i = 0; i < 6; i++) {
        Hm_data[i + 6 * ((int32_T)robot->joints->data[j].q_id - 1)] = b_pm[i];
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

/* End of code generation (GIM.c) */
