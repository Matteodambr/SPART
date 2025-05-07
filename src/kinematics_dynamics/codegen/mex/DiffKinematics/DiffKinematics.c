/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * DiffKinematics.c
 *
 * Code generation for function 'DiffKinematics'
 *
 */

/* Include files */
#include "DiffKinematics.h"
#include "DiffKinematics_data.h"
#include "DiffKinematics_emxutil.h"
#include "DiffKinematics_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtDCInfo emlrtDCI = {
    49,               /* lineNo */
    15,               /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    4                                       /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    49,               /* lineNo */
    15,               /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    1                                       /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    52,               /* lineNo */
    7,                /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    53,               /* lineNo */
    11,               /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    56,               /* lineNo */
    66,               /* colNo */
    "rL",             /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    56,               /* lineNo */
    76,               /* colNo */
    "rL",             /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    65,               /* lineNo */
    15,               /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    1                                       /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    68,               /* lineNo */
    7,                /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    69,               /* lineNo */
    59,               /* colNo */
    "rL",             /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    75,               /* lineNo */
    12,               /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    1                                       /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    81,               /* lineNo */
    7,                /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m" /* pName */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    84,               /* lineNo */
    26,               /* colNo */
    "e",              /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    84,               /* lineNo */
    41,               /* colNo */
    "e",              /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    84,               /* lineNo */
    50,               /* colNo */
    "g",              /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    87,               /* lineNo */
    37,               /* colNo */
    "e",              /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    56,               /* lineNo */
    25,               /* colNo */
    "Bij",            /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    56,               /* lineNo */
    27,               /* colNo */
    "Bij",            /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    25,               /* colNo */
    "Bij",            /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    27,               /* colNo */
    "Bij",            /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    69,               /* lineNo */
    17,               /* colNo */
    "Bi0",            /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    84,               /* lineNo */
    16,               /* colNo */
    "pm",             /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    87,               /* lineNo */
    16,               /* colNo */
    "pm",             /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    90,               /* lineNo */
    16,               /* colNo */
    "pm",             /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    54,                 /* lineNo */
    29,                 /* colNo */
    "robot.con.branch", /* aName */
    "DiffKinematics",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    54,                 /* lineNo */
    31,                 /* colNo */
    "robot.con.branch", /* aName */
    "DiffKinematics",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    82,               /* lineNo */
    21,               /* colNo */
    "robot.joints",   /* aName */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m", /* pName */
    0                                       /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    49,               /* lineNo */
    1,                /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    65,               /* lineNo */
    1,                /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    75,               /* lineNo */
    1,                /* colNo */
    "DiffKinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/DiffKinematics.m" /* pName */
};

/* Function Definitions */
void DiffKinematics(const emlrtStack *sp, const real_T R0[9],
                    const real_T r0[3], const emxArray_real_T *rL,
                    const emxArray_real_T *e, const emxArray_real_T *g,
                    const struct0_T *robot, emxArray_real_T *Bij,
                    emxArray_real_T *Bi0, real_T P0[36], emxArray_real_T *pm)
{
  real_T x[3];
  const real_T *e_data;
  const real_T *g_data;
  const real_T *rL_data;
  real_T n;
  real_T *Bij_data;
  int32_T P0_tmp;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int8_T Bij_tmp[9];
  int8_T i2;
  g_data = g->data;
  e_data = e->data;
  rL_data = rL->data;
  /*  Computes the differential kinematics of the multibody system. */
  /*  */
  /*  [Bij,Bi0,P0,pm]=DiffKinematics(R0,r0,rL,e,g,robot) */
  /*   */
  /*  :parameters: */
  /*    * R0 -- Rotation matrix from the base-link CCS to the inertial CCS --
   * [3x3]. */
  /*    * r0 -- Position of the base-link center-of-mass with respect to the
   * origin of the inertial frame, projected in the inertial CCS -- [3x1]. */
  /*    * rL -- Positions of the links, projected in the inertial CCS -- as a
   * [3xn] matrix. */
  /*    * e -- Joint rotation/sliding axes, projected in the inertial CCS -- as
   * a [3xn] matrix. */
  /*    * g -- Vector from the origin of the ith joint CCS to the origin of the
   * ith link CCS, projected in the inertial CCS -- as a [3xn] matrix. */
  /*    * robot -- Robot model (see :doc:`/Tutorial_Robot`). */
  /*  */
  /*  :return: */
  /*    * Bij -- Twist-propagation matrix (for manipulator i>0 and j>0) -- as a
   * [6x6xn] matrix. */
  /*    * Bi0 -- Twist-propagation matrix (for i>0 and j=0) -- as a [6x6xn]
   * matrix. */
  /*    * P0 -- Base-link twist-propagation "vector" -- as a [6x6] matrix. */
  /*    * pm -- Manipulator twist-propagation "vector" -- as a [6xn] matrix. */
  /*  */
  /*  Use :func:`src.kinematics_dynamics.Kinematics` to compute ``rL,e``, and
   * ``g``. */
  /*  */
  /*  See also: :func:`src.kinematics_dynamics.Kinematics` and
   * :func:`src.kinematics_dynamics.Jacob`.  */
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
  n = robot->n_links_joints;
  /* --- Twist-propagation matrix ---% */
  /* Pre-allocate Bij */
  if (!(robot->n_links_joints >= 0.0)) {
    emlrtNonNegativeCheckR2012b(robot->n_links_joints, &emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(robot->n_links_joints);
  if (robot->n_links_joints != i) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &b_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  loop_ub = Bij->size[0] * Bij->size[1] * Bij->size[2] * Bij->size[3];
  Bij->size[0] = 6;
  Bij->size[1] = 6;
  i1 = (int32_T)robot->n_links_joints;
  Bij->size[2] = i1;
  Bij->size[3] = i1;
  emxEnsureCapacity_real_T(sp, Bij, loop_ub, &e_emlrtRTEI);
  Bij_data = Bij->data;
  loop_ub_tmp = 36 * i1;
  loop_ub = loop_ub_tmp * i1;
  for (k = 0; k < loop_ub; k++) {
    Bij_data[k] = 0.0;
  }
  /* Compute Bij */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (j = 0; j < i1; j++) {
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
                                  &b_emlrtRTEI, (emlrtConstCTX)sp);
    for (b_i = 0; b_i < i1; b_i++) {
      if ((int32_T)((uint32_T)b_i + 1U) > robot->con.branch->size[0]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                      robot->con.branch->size[0], &p_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((int32_T)((uint32_T)j + 1U) > robot->con.branch->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                      robot->con.branch->size[1], &q_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (robot->con.branch->data[b_i + robot->con.branch->size[0] * j] ==
          1.0) {
        /* Links are in the same branch */
        for (k = 0; k < 9; k++) {
          Bij_tmp[k] = 0;
        }
        Bij_tmp[0] = 1;
        Bij_tmp[4] = 1;
        Bij_tmp[8] = 1;
        if ((int32_T)((uint32_T)j + 1U) > rL->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        rL->size[1], &emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if ((int32_T)((uint32_T)b_i + 1U) > rL->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                        rL->size[1], &b_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
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
        if ((int32_T)((uint32_T)b_i + 1U) > Bij->size[2]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                        Bij->size[2], &h_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if ((int32_T)((uint32_T)j + 1U) > Bij->size[3]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        Bij->size[3], &i_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        Bij_data[(36 * b_i + 36 * Bij->size[2] * j) + 3] = 0.0;
        Bij_data[(36 * b_i + 36 * Bij->size[2] * j) + 9] = -x[2];
        Bij_data[(36 * b_i + 36 * Bij->size[2] * j) + 15] = x[1];
        Bij_data[(36 * b_i + 36 * Bij->size[2] * j) + 4] = x[2];
        Bij_data[(36 * b_i + 36 * Bij->size[2] * j) + 10] = 0.0;
        Bij_data[(36 * b_i + 36 * Bij->size[2] * j) + 16] = -x[0];
        Bij_data[(36 * b_i + 36 * Bij->size[2] * j) + 5] = -x[1];
        Bij_data[(36 * b_i + 36 * Bij->size[2] * j) + 11] = x[0];
        Bij_data[(36 * b_i + 36 * Bij->size[2] * j) + 17] = 0.0;
        for (k = 0; k < 3; k++) {
          i2 = Bij_tmp[3 * k];
          loop_ub = 6 * k + 36 * b_i;
          Bij_data[loop_ub + 36 * Bij->size[2] * j] = i2;
          P0_tmp = 6 * (k + 3) + 36 * b_i;
          Bij_data[P0_tmp + 36 * Bij->size[2] * j] = 0.0;
          Bij_data[(P0_tmp + 36 * Bij->size[2] * j) + 3] = i2;
          i2 = Bij_tmp[3 * k + 1];
          Bij_data[(loop_ub + 36 * Bij->size[2] * j) + 1] = i2;
          Bij_data[(P0_tmp + 36 * Bij->size[2] * j) + 1] = 0.0;
          Bij_data[(P0_tmp + 36 * Bij->size[2] * j) + 4] = i2;
          i2 = Bij_tmp[3 * k + 2];
          Bij_data[(loop_ub + 36 * Bij->size[2] * j) + 2] = i2;
          Bij_data[(P0_tmp + 36 * Bij->size[2] * j) + 2] = 0.0;
          Bij_data[(P0_tmp + 36 * Bij->size[2] * j) + 5] = i2;
        }
      } else {
        /* Links are not in the same branch */
        if ((int32_T)((uint32_T)b_i + 1U) > Bij->size[2]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                        Bij->size[2], &j_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if ((int32_T)((uint32_T)j + 1U) > Bij->size[3]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        Bij->size[3], &k_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        for (k = 0; k < 6; k++) {
          for (c_i = 0; c_i < 6; c_i++) {
            Bij_data[((c_i + 6 * k) + 36 * b_i) + 36 * Bij->size[2] * j] = 0.0;
          }
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
  /* Pre-allocate Bi0 */
  if (i1 != i) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &c_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  loop_ub = Bi0->size[0] * Bi0->size[1] * Bi0->size[2];
  Bi0->size[0] = 6;
  Bi0->size[1] = 6;
  Bi0->size[2] = i1;
  emxEnsureCapacity_real_T(sp, Bi0, loop_ub, &f_emlrtRTEI);
  Bij_data = Bi0->data;
  for (k = 0; k < loop_ub_tmp; k++) {
    Bij_data[k] = 0.0;
  }
  /* Compute Bi0 */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &c_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (c_i = 0; c_i < i1; c_i++) {
    for (k = 0; k < 9; k++) {
      Bij_tmp[k] = 0;
    }
    Bij_tmp[0] = 1;
    Bij_tmp[4] = 1;
    Bij_tmp[8] = 1;
    if ((int32_T)((uint32_T)c_i + 1U) > rL->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    rL->size[1], &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
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
    if ((int32_T)((uint32_T)c_i + 1U) > Bi0->size[2]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    Bi0->size[2], &l_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Bij_data[36 * c_i + 3] = 0.0;
    Bij_data[36 * c_i + 9] = -x[2];
    Bij_data[36 * c_i + 15] = x[1];
    Bij_data[36 * c_i + 4] = x[2];
    Bij_data[36 * c_i + 10] = 0.0;
    Bij_data[36 * c_i + 16] = -x[0];
    Bij_data[36 * c_i + 5] = -x[1];
    Bij_data[36 * c_i + 11] = x[0];
    Bij_data[36 * c_i + 17] = 0.0;
    for (k = 0; k < 3; k++) {
      i2 = Bij_tmp[3 * k];
      loop_ub = 6 * k + 36 * c_i;
      Bij_data[loop_ub] = i2;
      P0_tmp = 6 * (k + 3) + 36 * c_i;
      Bij_data[P0_tmp] = 0.0;
      Bij_data[P0_tmp + 3] = i2;
      i2 = Bij_tmp[3 * k + 1];
      Bij_data[loop_ub + 1] = i2;
      Bij_data[P0_tmp + 1] = 0.0;
      Bij_data[P0_tmp + 4] = i2;
      i2 = Bij_tmp[3 * k + 2];
      Bij_data[loop_ub + 2] = i2;
      Bij_data[P0_tmp + 2] = 0.0;
      Bij_data[P0_tmp + 5] = i2;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* --- Twist-propagation "vector" ---% */
  /* Pre-allocate pm */
  if (i1 != i) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &d_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  loop_ub = pm->size[0] * pm->size[1];
  pm->size[0] = 6;
  pm->size[1] = i1;
  emxEnsureCapacity_real_T(sp, pm, loop_ub, &g_emlrtRTEI);
  Bij_data = pm->data;
  loop_ub = 6 * i1;
  for (k = 0; k < loop_ub; k++) {
    Bij_data[k] = 0.0;
  }
  /* Base-link */
  for (k = 0; k < 9; k++) {
    Bij_tmp[k] = 0;
  }
  for (k = 0; k < 3; k++) {
    Bij_tmp[k + 3 * k] = 1;
    P0[6 * k] = R0[3 * k];
    P0_tmp = 6 * (k + 3);
    P0[P0_tmp] = 0.0;
    P0[6 * k + 3] = 0.0;
    loop_ub = 3 * k + 1;
    P0[6 * k + 1] = R0[loop_ub];
    P0[P0_tmp + 1] = 0.0;
    P0[6 * k + 4] = 0.0;
    loop_ub_tmp = 3 * k + 2;
    P0[6 * k + 2] = R0[loop_ub_tmp];
    P0[P0_tmp + 2] = 0.0;
    P0[6 * k + 5] = 0.0;
    P0[P0_tmp + 3] = Bij_tmp[3 * k];
    P0[P0_tmp + 4] = Bij_tmp[loop_ub];
    P0[P0_tmp + 5] = Bij_tmp[loop_ub_tmp];
  }
  /* Forward recursion to obtain the twist-propagation "vector" */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &d_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (c_i = 0; c_i < i1; c_i++) {
    boolean_T b;
    b = ((int32_T)((uint32_T)c_i + 1U) > robot->joints->size[1]);
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    robot->joints->size[1], &r_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (robot->joints->data[c_i].type == 1.0) {
      /* Revolute joint */
      if (c_i + 1 > e->size[1]) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, e->size[1], &e_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (c_i + 1 > g->size[1]) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, g->size[1], &f_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((int32_T)((uint32_T)c_i + 1U) > e->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                      e->size[1], &d_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((int32_T)((uint32_T)c_i + 1U) > pm->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                      pm->size[1], &m_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Bij_data[6 * c_i] = e_data[3 * c_i];
      loop_ub = 3 * c_i + 1;
      Bij_data[6 * c_i + 1] = e_data[loop_ub];
      P0_tmp = 3 * c_i + 2;
      Bij_data[6 * c_i + 2] = e_data[P0_tmp];
      Bij_data[6 * c_i + 3] =
          e_data[loop_ub] * g_data[P0_tmp] - g_data[loop_ub] * e_data[P0_tmp];
      Bij_data[6 * c_i + 4] =
          g_data[3 * c_i] * e_data[P0_tmp] - e_data[3 * c_i] * g_data[P0_tmp];
      Bij_data[6 * c_i + 5] =
          e_data[3 * c_i] * g_data[loop_ub] - g_data[3 * c_i] * e_data[loop_ub];
    } else if (robot->joints->data[c_i].type == 2.0) {
      /* Prismatic joint */
      if ((int32_T)((uint32_T)c_i + 1U) > e->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                      e->size[1], &g_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((int32_T)((uint32_T)c_i + 1U) > pm->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                      pm->size[1], &n_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Bij_data[6 * c_i] = 0.0;
      Bij_data[6 * c_i + 3] = e_data[3 * c_i];
      Bij_data[6 * c_i + 1] = 0.0;
      Bij_data[6 * c_i + 4] = e_data[3 * c_i + 1];
      Bij_data[6 * c_i + 2] = 0.0;
      Bij_data[6 * c_i + 5] = e_data[3 * c_i + 2];
    } else if (robot->joints->data[c_i].type == 0.0) {
      /* Fixed joint */
      if ((int32_T)((uint32_T)c_i + 1U) > pm->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                      pm->size[1], &o_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      for (k = 0; k < 6; k++) {
        Bij_data[k + 6 * c_i] = 0.0;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

/* End of code generation (DiffKinematics.c) */
