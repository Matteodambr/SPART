/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Kinematics_C_api.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 10:31:47
 */

#ifndef _CODER_KINEMATICS_C_API_H
#define _CODER_KINEMATICS_C_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T id;
  real_T type;
  real_T q_id;
  real_T parent_link;
  real_T child_link;
  real_T axis[3];
  real_T T[16];
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T id;
  real_T parent_joint;
  real_T T[16];
  real_T mass;
  real_T inertia[9];
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_emxArray_struct0_T
#define typedef_emxArray_struct0_T
typedef struct {
  struct0_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct0_T;
#endif /* typedef_emxArray_struct0_T */

#ifndef typedef_emxArray_struct1_T
#define typedef_emxArray_struct1_T
typedef struct {
  struct1_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct1_T;
#endif /* typedef_emxArray_struct1_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void Kinematics_C(real_T R0[9], real_T r0[3], emxArray_real_T *qm,
                  real_T nLinksJoints, emxArray_struct0_T *robotJoints,
                  emxArray_struct1_T *robotLinks, emxArray_real_T *RJ,
                  emxArray_real_T *RL, emxArray_real_T *rJ, emxArray_real_T *rL,
                  emxArray_real_T *e, emxArray_real_T *g);

void Kinematics_C_api(const mxArray *const prhs[6], int32_T nlhs,
                      const mxArray *plhs[6]);

void Kinematics_C_atexit(void);

void Kinematics_C_initialize(void);

void Kinematics_C_terminate(void);

void Kinematics_C_xil_shutdown(void);

void Kinematics_C_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_Kinematics_C_api.h
 *
 * [EOF]
 */
