/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * I_I.c
 *
 * Code generation for function 'I_I'
 *
 */

/* Include files */
#include "I_I.h"
#include "I_I_data.h"
#include "I_I_emxutil.h"
#include "I_I_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    44,    /* lineNo */
    16,    /* colNo */
    "Im",  /* aName */
    "I_I", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/I_I.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    44,    /* lineNo */
    67,    /* colNo */
    "RL",  /* aName */
    "I_I", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/I_I.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    44,            /* lineNo */
    45,            /* colNo */
    "robot.links", /* aName */
    "I_I",         /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/I_I.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    43,    /* lineNo */
    7,     /* colNo */
    "I_I", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/I_I.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    40,    /* lineNo */
    14,    /* colNo */
    "I_I", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/I_I.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    40,    /* lineNo */
    14,    /* colNo */
    "I_I", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/I_I.m", /* pName */
    4                            /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    40,    /* lineNo */
    1,     /* colNo */
    "I_I", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/I_I.m" /* pName */
};

/* Function Definitions */
void I_I(const emlrtStack *sp, const real_T R0[9], const emxArray_real_T *RL,
         const struct0_T *robot, real_T I0[9], emxArray_real_T *Im)
{
  __m128d r;
  __m128d r1;
  real_T b_R0[9];
  const real_T *RL_data;
  real_T d;
  real_T *Im_data;
  int32_T R0_tmp;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  RL_data = RL->data;
  /*  Projects the link inertias in the inertial CCS. */
  /*  */
  /*  [I0,Im]=I_I(R0,RL,robot) */
  /*  */
  /*  :parameters:  */
  /*    * R0 -- Rotation matrix from the base-link CCS to the inertial CCS --
   * [3x3]. */
  /*    * RL -- Links CCS 3x3 rotation matrices with respect to the inertial CCS
   * -- as a [3x3xn] matrix. */
  /*    * robot -- Robot model (see :doc:`/Tutorial_Robot`). */
  /*  */
  /*  :return:  */
  /*    * I0 -- Base-link inertia matrix, projected in the inertial CCS -- as a
   * [3x3] matrix. */
  /*    * Im -- Links inertia matrices, projected in the inertial CCS -- as a
   * [3x3xn] matrix. */
  /*  */
  /*  See also: :func:`src.kinematics_dynamics.MCB`.  */
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
  /* Base-link inertia */
  memset(&b_R0[0], 0, 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    d = robot->base_link.inertia[3 * i];
    r = _mm_loadu_pd(&b_R0[3 * i]);
    _mm_storeu_pd(&b_R0[3 * i], _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&R0[0]),
                                                         _mm_set1_pd(d))));
    R0_tmp = 3 * i + 2;
    b_R0[R0_tmp] += R0[2] * d;
    d = robot->base_link.inertia[3 * i + 1];
    r = _mm_loadu_pd(&b_R0[3 * i]);
    _mm_storeu_pd(&b_R0[3 * i], _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&R0[3]),
                                                         _mm_set1_pd(d))));
    b_R0[R0_tmp] += R0[5] * d;
    d = robot->base_link.inertia[R0_tmp];
    r = _mm_loadu_pd(&b_R0[3 * i]);
    _mm_storeu_pd(&b_R0[3 * i], _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&R0[6]),
                                                         _mm_set1_pd(d))));
    b_R0[R0_tmp] += R0[8] * d;
  }
  memset(&I0[0], 0, 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    d = R0[i];
    r = _mm_loadu_pd(&b_R0[0]);
    r1 = _mm_loadu_pd(&I0[3 * i]);
    _mm_storeu_pd(&I0[3 * i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
    R0_tmp = 3 * i + 2;
    I0[R0_tmp] += b_R0[2] * d;
    d = R0[i + 3];
    r = _mm_loadu_pd(&b_R0[3]);
    r1 = _mm_loadu_pd(&I0[3 * i]);
    _mm_storeu_pd(&I0[3 * i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
    I0[R0_tmp] += b_R0[5] * d;
    d = R0[i + 6];
    r = _mm_loadu_pd(&b_R0[6]);
    r1 = _mm_loadu_pd(&I0[3 * i]);
    _mm_storeu_pd(&I0[3 * i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
    I0[R0_tmp] += b_R0[8] * d;
  }
  /* Pre-allocate inertias */
  if (!(robot->n_links_joints >= 0.0)) {
    emlrtNonNegativeCheckR2012b(robot->n_links_joints, &b_emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  if (robot->n_links_joints !=
      (int32_T)muDoubleScalarFloor(robot->n_links_joints)) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  R0_tmp = Im->size[0] * Im->size[1] * Im->size[2];
  Im->size[0] = 3;
  Im->size[1] = 3;
  i1 = (int32_T)robot->n_links_joints;
  Im->size[2] = (int32_T)robot->n_links_joints;
  emxEnsureCapacity_real_T(sp, Im, R0_tmp, &b_emlrtRTEI);
  Im_data = Im->data;
  R0_tmp = 9 * (int32_T)robot->n_links_joints;
  for (i = 0; i < R0_tmp; i++) {
    Im_data[i] = 0.0;
  }
  /* Inertias of the links */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i1; b_i++) {
    if ((b_i + 1 < 1) || (b_i + 1 > RL->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, RL->size[2], &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((b_i + 1 < 1) || (b_i + 1 > robot->links->size[1])) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, robot->links->size[1],
                                    &c_emlrtBCI, (emlrtConstCTX)sp);
    }
    memset(&b_R0[0], 0, 9U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      d = robot->links->data[b_i].inertia[3 * i];
      r = _mm_loadu_pd(&b_R0[3 * i]);
      _mm_storeu_pd(&b_R0[3 * i],
                    _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&RL_data[9 * b_i]),
                                             _mm_set1_pd(d))));
      R0_tmp = 3 * i + 2;
      b_R0[R0_tmp] += RL_data[9 * b_i + 2] * d;
      d = robot->links->data[b_i].inertia[3 * i + 1];
      r = _mm_loadu_pd(&b_R0[3 * i]);
      _mm_storeu_pd(
          &b_R0[3 * i],
          _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&RL_data[9 * b_i + 3]),
                                   _mm_set1_pd(d))));
      b_R0[R0_tmp] += RL_data[9 * b_i + 5] * d;
      d = robot->links->data[b_i].inertia[R0_tmp];
      r = _mm_loadu_pd(&b_R0[3 * i]);
      _mm_storeu_pd(
          &b_R0[3 * i],
          _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&RL_data[9 * b_i + 6]),
                                   _mm_set1_pd(d))));
      b_R0[R0_tmp] += RL_data[9 * b_i + 8] * d;
    }
    if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
        ((int32_T)((uint32_T)b_i + 1U) > Im->size[2])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                    Im->size[2], &emlrtBCI, (emlrtConstCTX)sp);
    }
    for (i = 0; i < 3; i++) {
      R0_tmp = 3 * i + 9 * b_i;
      Im_data[R0_tmp] = 0.0;
      Im_data[R0_tmp + 1] = 0.0;
      Im_data[R0_tmp + 2] = 0.0;
    }
    for (i = 0; i < 3; i++) {
      int32_T i2;
      R0_tmp = i + 9 * b_i;
      d = RL_data[R0_tmp];
      r = _mm_loadu_pd(&b_R0[0]);
      i2 = 3 * i + 9 * b_i;
      r1 = _mm_loadu_pd(&Im_data[i2]);
      _mm_storeu_pd(&Im_data[i2],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
      Im_data[i2 + 2] += b_R0[2] * d;
      d = RL_data[R0_tmp + 3];
      r = _mm_loadu_pd(&b_R0[3]);
      r1 = _mm_loadu_pd(&Im_data[i2]);
      _mm_storeu_pd(&Im_data[i2],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
      Im_data[i2 + 2] += b_R0[5] * d;
      d = RL_data[R0_tmp + 6];
      r = _mm_loadu_pd(&b_R0[6]);
      r1 = _mm_loadu_pd(&Im_data[i2]);
      _mm_storeu_pd(&Im_data[i2],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(d))));
      Im_data[i2 + 2] += b_R0[8] * d;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

/* End of code generation (I_I.c) */
