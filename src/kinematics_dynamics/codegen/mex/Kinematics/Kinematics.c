/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Kinematics.c
 *
 * Code generation for function 'Kinematics'
 *
 */

/* Include files */
#include "Kinematics.h"
#include "Kinematics_data.h"
#include "Kinematics_emxutil.h"
#include "Kinematics_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    81,           /* lineNo */
    "Kinematics", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    55,           /* lineNo */
    14,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    4                                   /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    55,           /* lineNo */
    14,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    56,           /* lineNo */
    14,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    64,           /* lineNo */
    7,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    67,             /* lineNo */
    25,             /* colNo */
    "robot.joints", /* aName */
    "Kinematics",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    75,           /* lineNo */
    42,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    75,           /* lineNo */
    42,           /* colNo */
    "TL",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    81,           /* lineNo */
    40,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    81,           /* lineNo */
    40,           /* colNo */
    "qm",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    84,           /* lineNo */
    37,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    84,           /* lineNo */
    37,           /* colNo */
    "qm",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    91,           /* lineNo */
    23,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    91,            /* lineNo */
    23,            /* colNo */
    "robot.links", /* aName */
    "Kinematics",  /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    92,           /* lineNo */
    37,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    92,           /* lineNo */
    37,           /* colNo */
    "TJ",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    98,           /* lineNo */
    14,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    100,          /* lineNo */
    12,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    111,          /* lineNo */
    7,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    112,          /* lineNo */
    30,           /* colNo */
    "TJ",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    114,            /* lineNo */
    41,             /* colNo */
    "robot.joints", /* aName */
    "Kinematics",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    112,          /* lineNo */
    16,           /* colNo */
    "RJ",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    114,          /* lineNo */
    25,           /* colNo */
    "RJ",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    117,          /* lineNo */
    7,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    118,          /* lineNo */
    30,           /* colNo */
    "TL",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    119,          /* lineNo */
    12,           /* colNo */
    "rL",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    120,          /* lineNo */
    21,           /* colNo */
    "rL",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    113,          /* lineNo */
    12,           /* colNo */
    "rJ",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    120,          /* lineNo */
    31,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    120,          /* lineNo */
    31,           /* colNo */
    "rJ",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    118,          /* lineNo */
    16,           /* colNo */
    "RL",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    120,          /* lineNo */
    11,           /* colNo */
    "g",          /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    72,           /* lineNo */
    20,           /* colNo */
    "TJ",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    72,           /* lineNo */
    20,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    75,           /* lineNo */
    20,           /* colNo */
    "TJ",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    75,           /* lineNo */
    20,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    114,          /* lineNo */
    11,           /* colNo */
    "e",          /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    92,           /* lineNo */
    16,           /* colNo */
    "TL",         /* aName */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    92,           /* lineNo */
    16,           /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    120,           /* lineNo */
    43,            /* colNo */
    "robot.links", /* aName */
    "Kinematics",  /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m", /* pName */
    0                                   /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    55,           /* lineNo */
    1,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    56,           /* lineNo */
    1,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    98,           /* lineNo */
    1,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    99,           /* lineNo */
    1,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    100,          /* lineNo */
    1,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    101,          /* lineNo */
    1,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    103,          /* lineNo */
    1,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    105,          /* lineNo */
    1,            /* colNo */
    "Kinematics", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Kinematics.m" /* pName */
};

/* Function Definitions */
void Kinematics(const emlrtStack *sp, const real_T R0[9], const real_T r0[3],
                const emxArray_real_T *qm, const struct0_T *robot,
                emxArray_real_T *RJ, emxArray_real_T *RL, emxArray_real_T *rJ,
                emxArray_real_T *rL, emxArray_real_T *e, emxArray_real_T *g)
{
  __m128d r;
  __m128d r1;
  emlrtStack st;
  emxArray_real_T *TJ;
  emxArray_real_T *TL;
  real_T T0[16];
  real_T b_TJ[16];
  real_T q[4];
  const real_T *qm_data;
  real_T b_tmp;
  real_T *RJ_data;
  real_T *RL_data;
  real_T *TJ_data;
  real_T *TL_data;
  real_T *e_data;
  real_T *g_data;
  real_T *rJ_data;
  real_T *rL_data;
  int32_T T0_tmp;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  boolean_T b_b;
  st.prev = sp;
  st.tls = sp->tls;
  qm_data = qm->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  Computes the kinematics -- positions and orientations -- of the multibody
   * system. */
  /*  */
  /*  [RJ,RL,rJ,rL,e,g]=Kinematics(R0,r0,qm,robot) */
  /*  */
  /*  :parameters:  */
  /*    * R0 -- Rotation matrix from the base-link CCS to the inertial CCS --
   * [3x3]. */
  /*    * r0 -- Position of the base-link center-of-mass with respect to the
   * origin of the inertial frame, projected in the inertial CCS -- [3x1]. */
  /*    * qm -- Displacements of the active joints -- [n_qx1]. */
  /*    * robot -- Robot model (see :doc:`/Tutorial_Robot`). */
  /*  */
  /*  :return:  */
  /*    * RJ -- Joints CCS 3x3 rotation matrices with respect to the inertial
   * CCS  -- as a [3x3xn] matrix. */
  /*    * RL -- Links CCS 3x3 rotation matrices with respect to the inertial CCS
   * -- as a [3x3xn] matrix. */
  /*    * rJ -- Positions of the joints, projected in the inertial CCS -- as a
   * [3xn] matrix. */
  /*    * rL -- Positions of the links, projected in the inertial CCS -- as a
   * [3xn] matrix. */
  /*    * e -- Joint rotation/sliding axes, projected in the inertial CCS -- as
   * a [3xn] matrix. */
  /*    * g -- Vector from the origin of the ith joint CCS to the origin of the
   * ith link CCS, projected in the inertial CCS -- as a [3xn] matrix. */
  /*  */
  /*  Remember that all the ouput magnitudes are projected in the **inertial
   * frame**. */
  /*  */
  /*  Examples on how to retrieve the results from a specific link/joint: */
  /*  */
  /*    To retrieve the position of the ith link: ``rL(1:3,i)``. */
  /*  */
  /*    To retrieve the rotation matrix of the ith joint: ``RJ(1:3,1:3,i)``. */
  /*  */
  /*  See also: :func:`src.robot_model.urdf2robot` and
   * :func:`src.robot_model.DH_Serial2robot`. */
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
  /* --- Number of links and joints ---% */
  /* --- Homogeneous transformation matrices ---% */
  /* Pre-allocate homogeneous transformations matrices */
  if (!(robot->n_links_joints >= 0.0)) {
    emlrtNonNegativeCheckR2012b(robot->n_links_joints, &emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(robot->n_links_joints);
  if (robot->n_links_joints != i) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &b_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &TJ, 3, &d_emlrtRTEI);
  T0_tmp = TJ->size[0] * TJ->size[1] * TJ->size[2];
  TJ->size[0] = 4;
  TJ->size[1] = 4;
  i1 = (int32_T)robot->n_links_joints;
  TJ->size[2] = i1;
  emxEnsureCapacity_real_T(sp, TJ, T0_tmp, &d_emlrtRTEI);
  TJ_data = TJ->data;
  loop_ub = i1 << 4;
  for (i2 = 0; i2 < loop_ub; i2++) {
    TJ_data[i2] = 0.0;
  }
  if (i1 != i) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &c_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &TL, 3, &e_emlrtRTEI);
  T0_tmp = TL->size[0] * TL->size[1] * TL->size[2];
  TL->size[0] = 4;
  TL->size[1] = 4;
  TL->size[2] = i1;
  emxEnsureCapacity_real_T(sp, TL, T0_tmp, &e_emlrtRTEI);
  TL_data = TL->data;
  for (i2 = 0; i2 < loop_ub; i2++) {
    TL_data[i2] = 0.0;
  }
  /* --- Base-link ---% */
  for (i2 = 0; i2 < 3; i2++) {
    T0_tmp = i2 << 2;
    T0[T0_tmp] = R0[3 * i2];
    T0[T0_tmp + 1] = R0[3 * i2 + 1];
    T0[T0_tmp + 2] = R0[3 * i2 + 2];
    T0[i2 + 12] = r0[i2];
  }
  T0[3] = 0.0;
  T0[7] = 0.0;
  T0[11] = 0.0;
  T0[15] = 1.0;
  /* --- Forward kinematics recursion ---% */
  /* Obtain the joints and links kinematics */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i1; b_i++) {
    __m128d r2;
    real_T T_qm[16];
    real_T b;
    /* Get child joint */
    if (b_i + 1 > robot->joints->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, robot->joints->size[1],
                                    &emlrtBCI, (emlrtConstCTX)sp);
    }
    /* Joint kinematics (homogeneous transformation matrix) */
    if (robot->joints->data[b_i].parent_link == 0.0) {
      /* Parent link is the base-link */
      b_tmp = robot->joints->data[b_i].id;
      if (b_tmp != (int32_T)muDoubleScalarFloor(b_tmp)) {
        emlrtIntegerCheckR2012b(b_tmp, &l_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)b_tmp < 1) || ((int32_T)b_tmp > TJ->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_tmp, 1, TJ->size[2],
                                      &r_emlrtBCI, (emlrtConstCTX)sp);
      }
      for (i2 = 0; i2 < 4; i2++) {
        T0_tmp = 4 * i2 + 16 * ((int32_T)b_tmp - 1);
        TJ_data[T0_tmp] = 0.0;
        TJ_data[T0_tmp + 1] = 0.0;
        TJ_data[T0_tmp + 2] = 0.0;
        TJ_data[T0_tmp + 3] = 0.0;
        for (c_i = 0; c_i < 4; c_i++) {
          loop_ub = c_i << 2;
          r = _mm_loadu_pd(&T0[loop_ub]);
          r1 = _mm_loadu_pd(&TJ_data[T0_tmp]);
          r2 = _mm_set1_pd(robot->joints->data[b_i].T[c_i + (i2 << 2)]);
          _mm_storeu_pd(&TJ_data[T0_tmp], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&T0[loop_ub + 2]);
          r1 = _mm_loadu_pd(&TJ_data[T0_tmp + 2]);
          _mm_storeu_pd(&TJ_data[T0_tmp + 2],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        }
      }
    } else {
      /* Parent link is not the base-link */
      b_tmp = robot->joints->data[b_i].parent_link;
      if (b_tmp != (int32_T)muDoubleScalarFloor(b_tmp)) {
        emlrtIntegerCheckR2012b(b_tmp, &d_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)b_tmp < 1) || ((int32_T)b_tmp > TL->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_tmp, 1, TL->size[2],
                                      &b_emlrtBCI, (emlrtConstCTX)sp);
      }
      b = robot->joints->data[b_i].id;
      if (b != (int32_T)muDoubleScalarFloor(b)) {
        emlrtIntegerCheckR2012b(b, &m_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)b < 1) || ((int32_T)b > TJ->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, TJ->size[2], &s_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      for (i2 = 0; i2 < 4; i2++) {
        T0_tmp = 4 * i2 + 16 * ((int32_T)b - 1);
        TJ_data[T0_tmp] = 0.0;
        TJ_data[T0_tmp + 1] = 0.0;
        TJ_data[T0_tmp + 2] = 0.0;
        TJ_data[T0_tmp + 3] = 0.0;
        for (c_i = 0; c_i < 4; c_i++) {
          loop_ub = 4 * c_i + 16 * ((int32_T)b_tmp - 1);
          r = _mm_loadu_pd(&TL_data[loop_ub]);
          r1 = _mm_loadu_pd(&TJ_data[T0_tmp]);
          r2 = _mm_set1_pd(robot->joints->data[b_i].T[c_i + (i2 << 2)]);
          _mm_storeu_pd(&TJ_data[T0_tmp], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&TL_data[loop_ub + 2]);
          r1 = _mm_loadu_pd(&TJ_data[T0_tmp + 2]);
          _mm_storeu_pd(&TJ_data[T0_tmp + 2],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        }
      }
    }
    /* Transformation due to current joint variable */
    if (robot->joints->data[b_i].type == 1.0) {
      real_T T_qm_tmp;
      real_T b_T_qm_tmp;
      real_T c_T_qm_tmp;
      real_T d;
      real_T d_T_qm_tmp;
      real_T e_T_qm_tmp;
      /* Revolute */
      st.site = &emlrtRSI;
      b_tmp = robot->joints->data[b_i].q_id;
      if (b_tmp != (int32_T)muDoubleScalarFloor(b_tmp)) {
        emlrtIntegerCheckR2012b(b_tmp, &e_emlrtDCI, &st);
      }
      if (((int32_T)b_tmp < 1) || ((int32_T)b_tmp > qm->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_tmp, 1, qm->size[0],
                                      &c_emlrtBCI, &st);
      }
      /* Provides the Direction Cosine Matrix (DCM) from a Euler axis
       * e=[e1,e2,e3] */
      /* and angle alpha. */
      /* Create quaternion */
      b_tmp = qm_data[(int32_T)b_tmp - 1] / 2.0;
      b = muDoubleScalarSin(b_tmp);
      d = muDoubleScalarCos(b_tmp);
      _mm_storeu_pd(&q[0],
                    _mm_mul_pd(_mm_loadu_pd(&robot->joints->data[b_i].axis[0]),
                               _mm_set1_pd(b)));
      q[2] = robot->joints->data[b_i].axis[2] * b;
      /* Convert quaternion to DCM */
      /* Provides the Direction Cosine Matrix (DCM) from a quaterionion (q) */
      /*  */
      /*  q = [q1;q2;q3;q4] -> With q4 being the scalar part of the quaternion.
       */
      T_qm_tmp = q[2] * q[2];
      b_T_qm_tmp = q[1] * q[1];
      T_qm[0] = 1.0 - 2.0 * (b_T_qm_tmp + T_qm_tmp);
      b_tmp = q[0] * q[1];
      b = q[2] * d;
      T_qm[1] = 2.0 * (b_tmp + b);
      c_T_qm_tmp = q[0] * q[2];
      d_T_qm_tmp = q[1] * d;
      T_qm[2] = 2.0 * (c_T_qm_tmp - d_T_qm_tmp);
      T_qm[4] = 2.0 * (b_tmp - b);
      e_T_qm_tmp = q[0] * q[0];
      T_qm[5] = 1.0 - 2.0 * (e_T_qm_tmp + T_qm_tmp);
      b = q[1] * q[2];
      b_tmp = q[0] * d;
      T_qm[6] = 2.0 * (b + b_tmp);
      T_qm[8] = 2.0 * (c_T_qm_tmp + d_T_qm_tmp);
      T_qm[9] = 2.0 * (b - b_tmp);
      T_qm[10] = 1.0 - 2.0 * (e_T_qm_tmp + b_T_qm_tmp);
      T_qm[12] = 0.0;
      T_qm[13] = 0.0;
      T_qm[14] = 0.0;
      T_qm[3] = 0.0;
      T_qm[7] = 0.0;
      T_qm[11] = 0.0;
      T_qm[15] = 1.0;
    } else if (robot->joints->data[b_i].type == 2.0) {
      int8_T b_I[9];
      /* Prismatic */
      b_tmp = robot->joints->data[b_i].q_id;
      if (b_tmp != (int32_T)muDoubleScalarFloor(b_tmp)) {
        emlrtIntegerCheckR2012b(b_tmp, &f_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)b_tmp < 1) || ((int32_T)b_tmp > qm->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_tmp, 1, qm->size[0],
                                      &d_emlrtBCI, (emlrtConstCTX)sp);
      }
      for (i2 = 0; i2 < 9; i2++) {
        b_I[i2] = 0;
      }
      b_I[0] = 1;
      b_I[4] = 1;
      b_I[8] = 1;
      for (i2 = 0; i2 < 3; i2++) {
        T0_tmp = i2 << 2;
        T_qm[T0_tmp] = b_I[3 * i2];
        T_qm[T0_tmp + 1] = b_I[3 * i2 + 1];
        T_qm[T0_tmp + 2] = b_I[3 * i2 + 2];
        T_qm[i2 + 12] =
            robot->joints->data[b_i].axis[i2] * qm_data[(int32_T)b_tmp - 1];
      }
      T_qm[3] = 0.0;
      T_qm[7] = 0.0;
      T_qm[11] = 0.0;
      T_qm[15] = 1.0;
    } else {
      int8_T b_I[9];
      /* Fixed */
      for (i2 = 0; i2 < 9; i2++) {
        b_I[i2] = 0;
      }
      b_I[0] = 1;
      b_I[4] = 1;
      b_I[8] = 1;
      for (i2 = 0; i2 < 3; i2++) {
        T0_tmp = i2 << 2;
        T_qm[T0_tmp] = b_I[3 * i2];
        T_qm[T0_tmp + 1] = b_I[3 * i2 + 1];
        T_qm[T0_tmp + 2] = b_I[3 * i2 + 2];
        T_qm[i2 + 12] = 0.0;
      }
      T_qm[3] = 0.0;
      T_qm[7] = 0.0;
      T_qm[11] = 0.0;
      T_qm[15] = 1.0;
    }
    /* Link Kinematics (homogeneous transformation matrix) */
    b = robot->joints->data[b_i].child_link;
    if (b != (int32_T)muDoubleScalarFloor(b)) {
      emlrtIntegerCheckR2012b(b, &g_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)b < 1) || ((int32_T)b > robot->links->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, robot->links->size[1],
                                    &e_emlrtBCI, (emlrtConstCTX)sp);
    }
    b_tmp = robot->links->data[(int32_T)b - 1].parent_joint;
    if (b_tmp != (int32_T)muDoubleScalarFloor(b_tmp)) {
      emlrtIntegerCheckR2012b(b_tmp, &h_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)b_tmp < 1) || ((int32_T)b_tmp > TJ->size[2])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_tmp, 1, TJ->size[2], &f_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    memset(&b_TJ[0], 0, sizeof(real_T) << 4);
    for (i2 = 0; i2 < 4; i2++) {
      T0_tmp = i2 << 2;
      for (c_i = 0; c_i < 4; c_i++) {
        loop_ub = 4 * c_i + 16 * ((int32_T)b_tmp - 1);
        r = _mm_loadu_pd(&TJ_data[loop_ub]);
        r1 = _mm_loadu_pd(&b_TJ[T0_tmp]);
        r2 = _mm_set1_pd(T_qm[c_i + T0_tmp]);
        _mm_storeu_pd(&b_TJ[T0_tmp], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        r = _mm_loadu_pd(&TJ_data[loop_ub + 2]);
        r1 = _mm_loadu_pd(&b_TJ[T0_tmp + 2]);
        _mm_storeu_pd(&b_TJ[T0_tmp + 2], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      }
    }
    b_tmp = robot->links->data[(int32_T)b - 1].id;
    if (b_tmp != (int32_T)muDoubleScalarFloor(b_tmp)) {
      emlrtIntegerCheckR2012b(b_tmp, &n_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)b_tmp < 1) || ((int32_T)b_tmp > TL->size[2])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_tmp, 1, TL->size[2], &u_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    for (i2 = 0; i2 < 4; i2++) {
      T0_tmp = 4 * i2 + 16 * ((int32_T)b_tmp - 1);
      TL_data[T0_tmp] = 0.0;
      TL_data[T0_tmp + 1] = 0.0;
      TL_data[T0_tmp + 2] = 0.0;
      TL_data[T0_tmp + 3] = 0.0;
      for (c_i = 0; c_i < 4; c_i++) {
        loop_ub = c_i << 2;
        r = _mm_loadu_pd(&b_TJ[loop_ub]);
        r1 = _mm_loadu_pd(&TL_data[T0_tmp]);
        r2 = _mm_set1_pd(robot->links->data[(int32_T)b - 1].T[c_i + (i2 << 2)]);
        _mm_storeu_pd(&TL_data[T0_tmp], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        r = _mm_loadu_pd(&b_TJ[loop_ub + 2]);
        r1 = _mm_loadu_pd(&TL_data[T0_tmp + 2]);
        _mm_storeu_pd(&TL_data[T0_tmp + 2], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* --- Rotation matrices, translation, position and other geometric quantities
   * ---% */
  /* Pre-allocate rotation matrices, translation and positions */
  if (i1 != i) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &i_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  T0_tmp = RJ->size[0] * RJ->size[1] * RJ->size[2];
  RJ->size[0] = 3;
  RJ->size[1] = 3;
  RJ->size[2] = i1;
  emxEnsureCapacity_real_T(sp, RJ, T0_tmp, &f_emlrtRTEI);
  RJ_data = RJ->data;
  loop_ub = 9 * i1;
  for (i2 = 0; i2 < loop_ub; i2++) {
    RJ_data[i2] = 0.0;
  }
  T0_tmp = RL->size[0] * RL->size[1] * RL->size[2];
  RL->size[0] = 3;
  RL->size[1] = 3;
  RL->size[2] = i1;
  emxEnsureCapacity_real_T(sp, RL, T0_tmp, &g_emlrtRTEI);
  RL_data = RL->data;
  for (i2 = 0; i2 < loop_ub; i2++) {
    RL_data[i2] = 0.0;
  }
  if (i1 != i) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &j_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  T0_tmp = rJ->size[0] * rJ->size[1];
  rJ->size[0] = 3;
  rJ->size[1] = i1;
  emxEnsureCapacity_real_T(sp, rJ, T0_tmp, &h_emlrtRTEI);
  rJ_data = rJ->data;
  loop_ub = 3 * i1;
  for (i2 = 0; i2 < loop_ub; i2++) {
    rJ_data[i2] = 0.0;
  }
  T0_tmp = rL->size[0] * rL->size[1];
  rL->size[0] = 3;
  rL->size[1] = i1;
  emxEnsureCapacity_real_T(sp, rL, T0_tmp, &i_emlrtRTEI);
  rL_data = rL->data;
  for (i2 = 0; i2 < loop_ub; i2++) {
    rL_data[i2] = 0.0;
  }
  /* Pre-allocate rotation/sliding axis */
  T0_tmp = e->size[0] * e->size[1];
  e->size[0] = 3;
  e->size[1] = i1;
  emxEnsureCapacity_real_T(sp, e, T0_tmp, &j_emlrtRTEI);
  e_data = e->data;
  for (i2 = 0; i2 < loop_ub; i2++) {
    e_data[i2] = 0.0;
  }
  /* Pre-allocate other geometric quantities */
  T0_tmp = g->size[0] * g->size[1];
  g->size[0] = 3;
  g->size[1] = i1;
  emxEnsureCapacity_real_T(sp, g, T0_tmp, &k_emlrtRTEI);
  g_data = g->data;
  for (i2 = 0; i2 < loop_ub; i2++) {
    g_data[i2] = 0.0;
  }
  /* Format rotation matrices, link positions, joint axis and other geometric */
  /* quantities */
  /* Joint associated quantities */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &b_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (c_i = 0; c_i < i1; c_i++) {
    b_b = ((int32_T)((uint32_T)c_i + 1U) > TJ->size[2]);
    if (b_b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    TJ->size[2], &g_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((int32_T)((uint32_T)c_i + 1U) > i1) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1, i1,
                                    &i_emlrtBCI, (emlrtConstCTX)sp);
    }
    for (i2 = 0; i2 < 3; i2++) {
      T0_tmp = 4 * i2 + 16 * c_i;
      loop_ub = 3 * i2 + 9 * c_i;
      RJ_data[loop_ub] = TJ_data[T0_tmp];
      RJ_data[loop_ub + 1] = TJ_data[T0_tmp + 1];
      RJ_data[loop_ub + 2] = TJ_data[T0_tmp + 2];
    }
    if ((int32_T)((uint32_T)c_i + 1U) > rJ->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    rJ->size[1], &n_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    rJ_data[3 * c_i] = TJ_data[16 * c_i + 12];
    T0_tmp = 3 * c_i + 1;
    rJ_data[T0_tmp] = TJ_data[16 * c_i + 13];
    loop_ub = 3 * c_i + 2;
    rJ_data[loop_ub] = TJ_data[16 * c_i + 14];
    if (c_i + 1 > i1) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, i1, &j_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (c_i + 1 > robot->joints->size[1]) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, robot->joints->size[1],
                                    &h_emlrtBCI, (emlrtConstCTX)sp);
    }
    if ((int32_T)((uint32_T)c_i + 1U) > e->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    e->size[1], &t_emlrtBCI, (emlrtConstCTX)sp);
    }
    e_data[3 * c_i] = 0.0;
    e_data[T0_tmp] = 0.0;
    e_data[loop_ub] = 0.0;
    r = _mm_loadu_pd(&RJ_data[9 * c_i]);
    r1 = _mm_loadu_pd(&e_data[3 * c_i]);
    _mm_storeu_pd(
        &e_data[3 * c_i],
        _mm_add_pd(
            r1, _mm_mul_pd(r, _mm_set1_pd(robot->joints->data[c_i].axis[0]))));
    e_data[loop_ub] += RJ_data[9 * c_i + 2] * robot->joints->data[c_i].axis[0];
    r = _mm_loadu_pd(&RJ_data[9 * c_i + 3]);
    r1 = _mm_loadu_pd(&e_data[3 * c_i]);
    _mm_storeu_pd(
        &e_data[3 * c_i],
        _mm_add_pd(
            r1, _mm_mul_pd(r, _mm_set1_pd(robot->joints->data[c_i].axis[1]))));
    e_data[loop_ub] += RJ_data[9 * c_i + 5] * robot->joints->data[c_i].axis[1];
    r = _mm_loadu_pd(&RJ_data[9 * c_i + 6]);
    r1 = _mm_loadu_pd(&e_data[3 * c_i]);
    _mm_storeu_pd(
        &e_data[3 * c_i],
        _mm_add_pd(
            r1, _mm_mul_pd(r, _mm_set1_pd(robot->joints->data[c_i].axis[2]))));
    e_data[loop_ub] += RJ_data[9 * c_i + 8] * robot->joints->data[c_i].axis[2];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &TJ);
  /* Link associated quantities */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &c_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (c_i = 0; c_i < i1; c_i++) {
    b_b = ((int32_T)((uint32_T)c_i + 1U) > TL->size[2]);
    if (b_b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    TL->size[2], &k_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((int32_T)((uint32_T)c_i + 1U) > i1) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1, i1,
                                    &p_emlrtBCI, (emlrtConstCTX)sp);
    }
    for (i2 = 0; i2 < 3; i2++) {
      T0_tmp = 4 * i2 + 16 * c_i;
      loop_ub = 3 * i2 + 9 * c_i;
      RL_data[loop_ub] = TL_data[T0_tmp];
      RL_data[loop_ub + 1] = TL_data[T0_tmp + 1];
      RL_data[loop_ub + 2] = TL_data[T0_tmp + 2];
    }
    if ((int32_T)((uint32_T)c_i + 1U) > rL->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    rL->size[1], &l_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    rL_data[3 * c_i] = TL_data[16 * c_i + 12];
    rL_data[3 * c_i + 1] = TL_data[16 * c_i + 13];
    T0_tmp = 3 * c_i + 2;
    rL_data[T0_tmp] = TL_data[16 * c_i + 14];
    if ((int32_T)((uint32_T)c_i + 1U) > rL->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    rL->size[1], &m_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((int32_T)((uint32_T)c_i + 1U) > robot->links->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    robot->links->size[1], &v_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_tmp = robot->links->data[c_i].parent_joint;
    if (b_tmp != (int32_T)muDoubleScalarFloor(b_tmp)) {
      emlrtIntegerCheckR2012b(b_tmp, &k_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)b_tmp < 1) || ((int32_T)b_tmp > rJ->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_tmp, 1, rJ->size[1], &o_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((int32_T)((uint32_T)c_i + 1U) > g->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    g->size[1], &q_emlrtBCI, (emlrtConstCTX)sp);
    }
    r = _mm_loadu_pd(&rL_data[3 * c_i]);
    loop_ub = (int32_T)robot->links->data[c_i].parent_joint - 1;
    r1 = _mm_loadu_pd(&rJ_data[3 * loop_ub]);
    _mm_storeu_pd(&g_data[3 * c_i], _mm_sub_pd(r, r1));
    g_data[T0_tmp] = rL_data[T0_tmp] - rJ_data[3 * loop_ub + 2];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &TL);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (Kinematics.c) */
