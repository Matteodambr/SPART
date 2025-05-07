/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Velocities.c
 *
 * Code generation for function 'Velocities'
 *
 */

/* Include files */
#include "Velocities.h"
#include "Velocities_data.h"
#include "Velocities_emxutil.h"
#include "Velocities_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtDCInfo emlrtDCI = {
    47,           /* lineNo */
    12,           /* colNo */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    4                                   /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    47,           /* lineNo */
    12,           /* colNo */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    1                                   /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    53,           /* lineNo */
    7,            /* colNo */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    57,           /* lineNo */
    31,           /* colNo */
    "Bi0",        /* aName */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    60,           /* lineNo */
    31,           /* colNo */
    "Bij",        /* aName */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    60,           /* lineNo */
    33,           /* colNo */
    "Bij",        /* aName */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    60,           /* lineNo */
    45,           /* colNo */
    "tL",         /* aName */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    65,           /* lineNo */
    26,           /* colNo */
    "tL",         /* aName */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    65,           /* lineNo */
    36,           /* colNo */
    "pm",         /* aName */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    65,           /* lineNo */
    42,           /* colNo */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    65,           /* lineNo */
    42,           /* colNo */
    "um",         /* aName */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    57,           /* lineNo */
    16,           /* colNo */
    "tL",         /* aName */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    60,           /* lineNo */
    16,           /* colNo */
    "tL",         /* aName */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    55,             /* lineNo */
    21,             /* colNo */
    "robot.joints", /* aName */
    "Velocities",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    65,             /* lineNo */
    55,             /* colNo */
    "robot.joints", /* aName */
    "Velocities",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m", /* pName */
    0                                   /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    47,           /* lineNo */
    1,            /* colNo */
    "Velocities", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/Velocities.m" /* pName */
};

/* Function Definitions */
void Velocities(const emlrtStack *sp, const emxArray_real_T *Bij,
                const emxArray_real_T *Bi0, const real_T P0[36],
                const emxArray_real_T *pm, const real_T u0[6],
                const emxArray_real_T *um, const struct0_T *robot, real_T t0[6],
                emxArray_real_T *tL)
{
  __m128d r;
  __m128d r1;
  real_T b_Bij[6];
  const real_T *Bi0_data;
  const real_T *Bij_data;
  const real_T *pm_data;
  const real_T *um_data;
  real_T *tL_data;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  um_data = um->data;
  pm_data = pm->data;
  Bi0_data = Bi0->data;
  Bij_data = Bij->data;
  /*  Computes the operational-space velocities of the multibody system. */
  /*  */
  /*  [t0,tL]=Velocities(Bij,Bi0,P0,pm,u0,um,robot) */
  /*  */
  /*  :parameters: */
  /*    * Bij -- Twist-propagation matrix (for manipulator i>0 and j>0) -- as a
   * [6x6xn] matrix. */
  /*    * Bi0 -- Twist-propagation matrix (for i>0 and j=0) -- as a [6x6xn]
   * matrix. */
  /*    * P0 -- Base-link twist-propagation "vector" -- as a [6x6] matrix. */
  /*    * pm -- Manipulator twist-propagation "vector" -- as a [6xn] matrix. */
  /*    * u0 -- Base-link velocities [\omega,rdot]. The angular velocity is
   * projected in the body-fixed CCS, while the linear velocity is projected in
   * the inertial CCS -- [6x1]. */
  /*    * um -- Joint velocities -- [n_qx1]. */
  /*    * robot -- Robot model (see :doc:`/Tutorial_Robot`). */
  /*  */
  /*  :return: */
  /*    * t0 -- Base-link twist [\omega,rdot], projected in the inertial CCS --
   * as a [6x1] matrix. */
  /*    * tL -- Manipulator twist [\omega,rdot], projected in the inertial CCS
   * -- as a [6xn] matrix. */
  /*  */
  /*  Use :func:`src.kinematics_dynamics.DiffKinematics` to compute ``Bij``,
   * ``Bi0``, ``P0``, and ``pm``. */
  /*  */
  /*  See also: :func:`src.kinematics_dynamics.Jacob` */
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
  loop_ub = tL->size[0] * tL->size[1];
  tL->size[0] = 6;
  i = (int32_T)robot->n_links_joints;
  tL->size[1] = (int32_T)robot->n_links_joints;
  emxEnsureCapacity_real_T(sp, tL, loop_ub, &b_emlrtRTEI);
  tL_data = tL->data;
  loop_ub = 6 * (int32_T)robot->n_links_joints;
  for (i1 = 0; i1 < loop_ub; i1++) {
    tL_data[i1] = 0.0;
  }
  /* Base-link */
  memset(&t0[0], 0, 6U * sizeof(real_T));
  for (i1 = 0; i1 < 6; i1++) {
    r = _mm_loadu_pd(&t0[0]);
    r1 = _mm_set1_pd(u0[i1]);
    _mm_storeu_pd(&t0[0],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i1]), r1)));
    r = _mm_loadu_pd(&t0[2]);
    _mm_storeu_pd(&t0[2],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i1 + 2]), r1)));
    r = _mm_loadu_pd(&t0[4]);
    _mm_storeu_pd(&t0[4],
                  _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&P0[6 * i1 + 4]), r1)));
  }
  /* Forward recursion to obtain the twist */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T b;
    b = (((int32_T)((uint32_T)b_i + 1U) < 1) ||
         ((int32_T)((uint32_T)b_i + 1U) > robot->joints->size[1]));
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                    robot->joints->size[1], &j_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (robot->joints->data[b_i].parent_link == 0.0) {
      int32_T i2;
      /* First link */
      if ((b_i + 1 < 1) || (b_i + 1 > Bi0->size[2])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Bi0->size[2], &emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
          ((int32_T)((uint32_T)b_i + 1U) > tL->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                      tL->size[1], &h_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      for (i1 = 0; i1 < 6; i1++) {
        tL_data[i1 + 6 * b_i] = 0.0;
      }
      loop_ub = 6 * b_i + 2;
      i2 = 6 * b_i + 4;
      for (i1 = 0; i1 < 6; i1++) {
        int32_T i3;
        r = _mm_loadu_pd(&tL_data[6 * b_i]);
        r1 = _mm_set1_pd(t0[i1]);
        i3 = 6 * i1 + 36 * b_i;
        _mm_storeu_pd(
            &tL_data[6 * b_i],
            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[i3]), r1)));
        r = _mm_loadu_pd(&tL_data[loop_ub]);
        _mm_storeu_pd(
            &tL_data[loop_ub],
            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[i3 + 2]), r1)));
        r = _mm_loadu_pd(&tL_data[i2]);
        _mm_storeu_pd(
            &tL_data[i2],
            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&Bi0_data[i3 + 4]), r1)));
      }
    } else {
      /* Rest of the links */
      if ((b_i + 1 < 1) || (b_i + 1 > Bij->size[2])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Bij->size[2], &b_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((b_i < 1) || (b_i > Bij->size[3])) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, Bij->size[3], &c_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((b_i < 1) || (b_i > tL->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, tL->size[1], &d_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
          ((int32_T)((uint32_T)b_i + 1U) > tL->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                      tL->size[1], &i_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      memset(&b_Bij[0], 0, 6U * sizeof(real_T));
      for (i1 = 0; i1 < 6; i1++) {
        r = _mm_loadu_pd(&b_Bij[0]);
        r1 = _mm_set1_pd(tL_data[i1 + 6 * (b_i - 1)]);
        loop_ub = 6 * i1 + 36 * b_i;
        _mm_storeu_pd(
            &b_Bij[0],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(
                           &Bij_data[loop_ub + 36 * Bij->size[2] * (b_i - 1)]),
                       r1)));
        r = _mm_loadu_pd(&b_Bij[2]);
        _mm_storeu_pd(
            &b_Bij[2],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(
                           &Bij_data[(loop_ub + 36 * Bij->size[2] * (b_i - 1)) +
                                     2]),
                       r1)));
        r = _mm_loadu_pd(&b_Bij[4]);
        _mm_storeu_pd(
            &b_Bij[4],
            _mm_add_pd(
                r, _mm_mul_pd(
                       _mm_loadu_pd(
                           &Bij_data[(loop_ub + 36 * Bij->size[2] * (b_i - 1)) +
                                     4]),
                       r1)));
      }
      for (i1 = 0; i1 < 6; i1++) {
        tL_data[i1 + 6 * b_i] = b_Bij[i1];
      }
    }
    /* Add joint contribution */
    if (robot->joints->data[b_i].type != 0.0) {
      real_T d;
      if ((b_i + 1 < 1) || (b_i + 1 > pm->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, pm->size[1], &f_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
          ((int32_T)((uint32_T)b_i + 1U) > robot->joints->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                      robot->joints->size[1], &k_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      d = robot->joints->data[b_i].q_id;
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &c_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > um->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, um->size[0], &g_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
          ((int32_T)((uint32_T)b_i + 1U) > tL->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                      tL->size[1], &e_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      r = _mm_loadu_pd(&tL_data[6 * b_i]);
      r1 = _mm_set1_pd(um_data[(int32_T)robot->joints->data[b_i].q_id - 1]);
      _mm_storeu_pd(
          &b_Bij[0],
          _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&pm_data[6 * b_i]), r1)));
      loop_ub = 6 * b_i + 2;
      r = _mm_loadu_pd(&tL_data[loop_ub]);
      _mm_storeu_pd(
          &b_Bij[2],
          _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&pm_data[loop_ub]), r1)));
      loop_ub = 6 * b_i + 4;
      r = _mm_loadu_pd(&tL_data[loop_ub]);
      _mm_storeu_pd(
          &b_Bij[4],
          _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&pm_data[loop_ub]), r1)));
      for (i1 = 0; i1 < 6; i1++) {
        tL_data[i1 + 6 * b_i] = b_Bij[i1];
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

/* End of code generation (Velocities.c) */
