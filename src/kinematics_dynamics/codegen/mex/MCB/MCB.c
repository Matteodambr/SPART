/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * MCB.c
 *
 * Code generation for function 'MCB'
 *
 */

/* Include files */
#include "MCB.h"
#include "MCB_data.h"
#include "MCB_emxutil.h"
#include "MCB_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    50,    /* lineNo */
    "MCB", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    59,    /* lineNo */
    "MCB", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    39,                                                            /* lineNo */
    "find",                                                        /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

static emlrtDCInfo emlrtDCI = {
    43,    /* lineNo */
    20,    /* colNo */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    4                            /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    43,    /* lineNo */
    20,    /* colNo */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    1                            /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    46,    /* lineNo */
    7,     /* colNo */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    48,    /* lineNo */
    37,    /* colNo */
    "Im",  /* aName */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    48,            /* lineNo */
    74,            /* colNo */
    "robot.links", /* aName */
    "MCB",         /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    50,                /* lineNo */
    34,                /* colNo */
    "robot.con.child", /* aName */
    "MCB",             /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    48,         /* lineNo */
    22,         /* colNo */
    "Mm_tilde", /* aName */
    "MCB",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    52,         /* lineNo */
    46,         /* colNo */
    "Mm_tilde", /* aName */
    "MCB",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    52,    /* lineNo */
    61,    /* colNo */
    "Bij", /* aName */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    52,    /* lineNo */
    70,    /* colNo */
    "Bij", /* aName */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    52,         /* lineNo */
    91,         /* colNo */
    "Mm_tilde", /* aName */
    "MCB",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    52,    /* lineNo */
    113,   /* colNo */
    "Bij", /* aName */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    52,    /* lineNo */
    122,   /* colNo */
    "Bij", /* aName */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    52,         /* lineNo */
    26,         /* colNo */
    "Mm_tilde", /* aName */
    "MCB",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    61,    /* lineNo */
    35,    /* colNo */
    "Bi0", /* aName */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    61,         /* lineNo */
    63,         /* colNo */
    "Mm_tilde", /* aName */
    "MCB",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    61,    /* lineNo */
    85,    /* colNo */
    "Bi0", /* aName */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    61,      /* lineNo */
    41,      /* colNo */
    "child", /* aName */
    "MCB",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    61,      /* lineNo */
    69,      /* colNo */
    "child", /* aName */
    "MCB",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    61,      /* lineNo */
    91,      /* colNo */
    "child", /* aName */
    "MCB",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    52,      /* lineNo */
    67,      /* colNo */
    "child", /* aName */
    "MCB",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    52,      /* lineNo */
    97,      /* colNo */
    "child", /* aName */
    "MCB",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    52,      /* lineNo */
    119,     /* colNo */
    "child", /* aName */
    "MCB",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    43,    /* lineNo */
    1,     /* colNo */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    59,    /* lineNo */
    1,     /* colNo */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    50,    /* lineNo */
    16,    /* colNo */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    50,    /* lineNo */
    5,     /* colNo */
    "MCB", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/MCB.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    31,                                                            /* lineNo */
    6,                                                             /* colNo */
    "find",                                                        /* fName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

/* Function Definitions */
void MCB(const emlrtStack *sp, const real_T I0[9], const emxArray_real_T *Im,
         const emxArray_real_T *Bij, const emxArray_real_T *Bi0,
         const struct0_T *robot, real_T M0_tilde[36], emxArray_real_T *Mm_tilde)
{
  static const int8_T b_b[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *child;
  emxArray_int32_T *ii;
  real_T b_Bij[36];
  const real_T *Bi0_data;
  const real_T *Bij_data;
  const real_T *Im_data;
  real_T Mm_tilde_tmp;
  real_T *Mm_tilde_data;
  real_T *robot_data;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i5;
  int32_T i6;
  int32_T j;
  int32_T loop_ub;
  int32_T *child_data;
  int32_T *ii_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  Bi0_data = Bi0->data;
  Bij_data = Bij->data;
  Im_data = Im->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  Computes the Mass Composite Body Matrix (MCB) of the multibody system. */
  /*  */
  /*  [M0_tilde,Mm_tilde]=MCB(I0,Im,Bij,Bi0,robot) */
  /*  */
  /*  :parameters:  */
  /*    * I0 -- Base-link inertia matrix, projected in the inertial CCS -- as a
   * [3x3] matrix. */
  /*    * Im -- Links inertia matrices, projected in the inertial CCS -- as a
   * [3x3xn] matrix. */
  /*    * Bij -- Twist-propagation matrix (for manipulator i>0 and j>0) -- as a
   * [6x6xn] matrix. */
  /*    * Bi0 -- Twist-propagation matrix (for i>0 and j=0) -- as a [6x6xn]
   * matrix. */
  /*    * robot -- Robot model (see :doc:`/Tutorial_Robot`). */
  /*  */
  /*  :return:  */
  /*    * M0_tilde -- Base-link mass composite body matrix -- as a [6x6] matrix
   * . */
  /*    * Mm_tilde -- Manipulator mass composite body matrix -- as a [6x6xn]
   * matrix. */
  /*  */
  /*  See also: :func:`src.kinematics_dynamics.I_I`.  */
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
  /* Number of links and Joints */
  /* Pre-allocate */
  if (!(robot->n_links_joints >= 0.0)) {
    emlrtNonNegativeCheckR2012b(robot->n_links_joints, &emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  if (robot->n_links_joints !=
      (int32_T)muDoubleScalarFloor(robot->n_links_joints)) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &b_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  loop_ub = Mm_tilde->size[0] * Mm_tilde->size[1] * Mm_tilde->size[2];
  Mm_tilde->size[0] = 6;
  Mm_tilde->size[1] = 6;
  i = (int32_T)robot->n_links_joints;
  Mm_tilde->size[2] = (int32_T)robot->n_links_joints;
  emxEnsureCapacity_real_T(sp, Mm_tilde, loop_ub, &e_emlrtRTEI);
  Mm_tilde_data = Mm_tilde->data;
  loop_ub = 36 * (int32_T)robot->n_links_joints;
  for (i1 = 0; i1 < loop_ub; i1++) {
    Mm_tilde_data[i1] = 0.0;
  }
  /* Backwards recursion */
  i2 = (int32_T) - ((-1.0 - robot->n_links_joints) + 1.0);
  emlrtForLoopVectorCheckR2021a(
      robot->n_links_joints, -1.0, 1.0, mxDOUBLE_CLASS,
      (int32_T) - ((-1.0 - robot->n_links_joints) + 1.0), &emlrtRTEI,
      (emlrtConstCTX)sp);
  emxInit_int32_T(sp, &child, 2, &h_emlrtRTEI);
  emxInit_int32_T(sp, &ii, 1, &i_emlrtRTEI);
  emxInit_real_T(sp, &Mm_tilde, 1, &g_emlrtRTEI);
  for (b_i = 0; b_i < i2; b_i++) {
    real_T c_i;
    boolean_T b;
    c_i = robot->n_links_joints - (real_T)b_i;
    /* Initialize M tilde */
    if (((int32_T)c_i < 1) || ((int32_T)c_i > robot->links->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, robot->links->size[1],
                                    &b_emlrtBCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)c_i < 1) || ((int32_T)c_i > Im->size[2])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, Im->size[2], &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b = (((int32_T)c_i < 1) || ((int32_T)c_i > i));
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, i, &d_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = 36 * ((int32_T)c_i - 1);
    for (i1 = 0; i1 < 3; i1++) {
      int32_T i3;
      int32_T i4;
      b_loop_ub = 6 * i1 + loop_ub;
      i3 = 3 * i1 + 9 * ((int32_T)c_i - 1);
      Mm_tilde_data[b_loop_ub] = Im_data[i3];
      i4 = 6 * (i1 + 3) + loop_ub;
      Mm_tilde_data[i4] = 0.0;
      Mm_tilde_data[b_loop_ub + 3] = 0.0;
      Mm_tilde_tmp = robot->links->data[(int32_T)c_i - 1].mass;
      Mm_tilde_data[i4 + 3] = Mm_tilde_tmp * (real_T)b_b[3 * i1];
      Mm_tilde_data[b_loop_ub + 1] = Im_data[i3 + 1];
      Mm_tilde_data[i4 + 1] = 0.0;
      Mm_tilde_data[b_loop_ub + 4] = 0.0;
      Mm_tilde_data[i4 + 4] = Mm_tilde_tmp * (real_T)b_b[3 * i1 + 1];
      Mm_tilde_data[b_loop_ub + 2] = Im_data[i3 + 2];
      Mm_tilde_data[i4 + 2] = 0.0;
      Mm_tilde_data[b_loop_ub + 5] = 0.0;
      Mm_tilde_data[i4 + 5] = Mm_tilde_tmp * (real_T)b_b[3 * i1 + 2];
    }
    /* Add children contributions */
    st.site = &emlrtRSI;
    if (((int32_T)c_i < 1) || ((int32_T)c_i > robot->con.child->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, robot->con.child->size[1],
                                    &c_emlrtBCI, &st);
    }
    b_loop_ub = robot->con.child->size[0];
    loop_ub = Mm_tilde->size[0];
    Mm_tilde->size[0] = robot->con.child->size[0];
    emxEnsureCapacity_real_T(&st, Mm_tilde, loop_ub, &g_emlrtRTEI);
    robot_data = Mm_tilde->data;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      robot_data[i1] =
          robot->con.child
              ->data[i1 + robot->con.child->size[0] * ((int32_T)c_i - 1)];
    }
    b_st.site = &c_emlrtRSI;
    eml_find(&b_st, Mm_tilde, ii);
    ii_data = ii->data;
    loop_ub = child->size[0] * child->size[1];
    child->size[0] = 1;
    b_loop_ub = ii->size[0];
    child->size[1] = ii->size[0];
    emxEnsureCapacity_int32_T(sp, child, loop_ub, &h_emlrtRTEI);
    child_data = child->data;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      child_data[i1] = ii_data[i1];
    }
    for (j = 0; j < b_loop_ub; j++) {
      real_T b_Mm_tilde[36];
      if (j + 1 > b_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_loop_ub, &r_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      loop_ub = ii_data[j];
      if ((loop_ub < 1) || (loop_ub > Bij->size[2])) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Bij->size[2], &f_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)c_i < 1) || ((int32_T)c_i > Bij->size[3])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, Bij->size[3],
                                      &g_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (j + 1 > b_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_loop_ub, &s_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (loop_ub > i) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &h_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (j + 1 > b_loop_ub) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_loop_ub, &t_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (loop_ub > Bij->size[2]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Bij->size[2], &i_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)c_i < 1) || ((int32_T)c_i > Bij->size[3])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, Bij->size[3],
                                      &j_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, i, &e_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      loop_ub = child_data[j];
      loop_ub = 36 * (loop_ub - 1);
      for (i1 = 0; i1 < 6; i1++) {
        for (i6 = 0; i6 < 6; i6++) {
          Mm_tilde_tmp = 0.0;
          for (i5 = 0; i5 < 6; i5++) {
            Mm_tilde_tmp += Bij_data[((i5 + 6 * i6) + loop_ub) +
                                     36 * Bij->size[2] * ((int32_T)c_i - 1)] *
                            Mm_tilde_data[(i5 + 6 * i1) + loop_ub];
          }
          b_Bij[i6 + 6 * i1] = Mm_tilde_tmp;
        }
      }
      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)c_i, 1, i, &k_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      for (i6 = 0; i6 < 6; i6++) {
        for (i5 = 0; i5 < 6; i5++) {
          Mm_tilde_tmp = 0.0;
          for (i1 = 0; i1 < 6; i1++) {
            Mm_tilde_tmp += b_Bij[i6 + 6 * i1] *
                            Bij_data[((i1 + 6 * i5) + 36 * (ii_data[j] - 1)) +
                                     36 * Bij->size[2] * ((int32_T)c_i - 1)];
          }
          loop_ub = i6 + 6 * i5;
          b_Mm_tilde[loop_ub] =
              Mm_tilde_data[loop_ub + 36 * ((int32_T)c_i - 1)] + Mm_tilde_tmp;
        }
      }
      for (i1 = 0; i1 < 6; i1++) {
        for (i5 = 0; i5 < 6; i5++) {
          loop_ub = i5 + 6 * i1;
          Mm_tilde_data[loop_ub + 36 * ((int32_T)c_i - 1)] =
              b_Mm_tilde[loop_ub];
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
  emxFree_real_T(sp, &Mm_tilde);
  /* Base-link M tilde */
  for (i1 = 0; i1 < 3; i1++) {
    M0_tilde[6 * i1] = I0[3 * i1];
    b_loop_ub = 6 * (i1 + 3);
    M0_tilde[b_loop_ub] = 0.0;
    M0_tilde[6 * i1 + 3] = 0.0;
    M0_tilde[b_loop_ub + 3] = robot->base_link.mass * (real_T)b_b[3 * i1];
    loop_ub = 3 * i1 + 1;
    M0_tilde[6 * i1 + 1] = I0[loop_ub];
    M0_tilde[b_loop_ub + 1] = 0.0;
    M0_tilde[6 * i1 + 4] = 0.0;
    M0_tilde[b_loop_ub + 4] = robot->base_link.mass * (real_T)b_b[loop_ub];
    loop_ub = 3 * i1 + 2;
    M0_tilde[6 * i1 + 2] = I0[loop_ub];
    M0_tilde[b_loop_ub + 2] = 0.0;
    M0_tilde[6 * i1 + 5] = 0.0;
    M0_tilde[b_loop_ub + 5] = robot->base_link.mass * (real_T)b_b[loop_ub];
  }
  /* Add children contributions */
  st.site = &b_emlrtRSI;
  b_st.site = &c_emlrtRSI;
  eml_find(&b_st, robot->con.child_base, ii);
  ii_data = ii->data;
  loop_ub = child->size[0] * child->size[1];
  child->size[0] = 1;
  b_loop_ub = ii->size[0];
  child->size[1] = ii->size[0];
  emxEnsureCapacity_int32_T(sp, child, loop_ub, &f_emlrtRTEI);
  child_data = child->data;
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    child_data[i1] = ii_data[i1];
  }
  for (j = 0; j < b_loop_ub; j++) {
    if (j + 1 > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_loop_ub, &o_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = ii_data[j];
    if ((loop_ub < 1) || (loop_ub > Bi0->size[2])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Bi0->size[2], &l_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (j + 1 > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_loop_ub, &p_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (loop_ub > i) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i, &m_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (j + 1 > b_loop_ub) {
      emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_loop_ub, &q_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (loop_ub > Bi0->size[2]) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, Bi0->size[2], &n_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = child_data[j];
    loop_ub = 36 * (loop_ub - 1);
    for (i1 = 0; i1 < 6; i1++) {
      for (i5 = 0; i5 < 6; i5++) {
        Mm_tilde_tmp = 0.0;
        for (i6 = 0; i6 < 6; i6++) {
          Mm_tilde_tmp += Bi0_data[(i6 + 6 * i5) + loop_ub] *
                          Mm_tilde_data[(i6 + 6 * i1) + loop_ub];
        }
        b_Bij[i5 + 6 * i1] = Mm_tilde_tmp;
      }
    }
    for (i5 = 0; i5 < 6; i5++) {
      for (i6 = 0; i6 < 6; i6++) {
        Mm_tilde_tmp = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          Mm_tilde_tmp += b_Bij[i5 + 6 * i1] *
                          Bi0_data[(i1 + 6 * i6) + 36 * (ii_data[j] - 1)];
        }
        loop_ub = i5 + 6 * i6;
        M0_tilde[loop_ub] += Mm_tilde_tmp;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_int32_T(sp, &ii);
  emxFree_int32_T(sp, &child);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (MCB.c) */
