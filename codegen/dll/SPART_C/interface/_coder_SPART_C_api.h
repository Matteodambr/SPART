/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_SPART_C_api.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

#ifndef _CODER_SPART_C_API_H
#define _CODER_SPART_C_API_H

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

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1
typedef struct {
  real_T f1[36];
} cell_wrap_1;
#endif /* typedef_cell_wrap_1 */

#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2
typedef struct {
  real_T f1[9];
} cell_wrap_2;
#endif /* typedef_cell_wrap_2 */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  real_T mass;
  real_T inertia[9];
} struct2_T;
#endif /* typedef_struct2_T */

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

#ifndef typedef_emxArray_cell_wrap_1
#define typedef_emxArray_cell_wrap_1
typedef struct {
  cell_wrap_1 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_1;
#endif /* typedef_emxArray_cell_wrap_1 */

#ifndef typedef_emxArray_cell_wrap_2
#define typedef_emxArray_cell_wrap_2
typedef struct {
  cell_wrap_2 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_2;
#endif /* typedef_emxArray_cell_wrap_2 */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void Accelerations_C(real_T t0[6], emxArray_real_T *tL, real_T P0[36],
                     emxArray_real_T *pm, emxArray_cell_wrap_1 *Bi0,
                     emxArray_cell_wrap_1 *Bij, real_T u0[6],
                     emxArray_real_T *um, real_T u0dot[6],
                     emxArray_real_T *umdot, real_T nLinksJoints,
                     emxArray_struct0_T *robotJoints, real_T t0dot[6],
                     emxArray_real_T *tLdot);

void Accelerations_C_api(const mxArray *const prhs[12], int32_T nlhs,
                         const mxArray *plhs[2]);

void DiffKinematics_C(real_T R0[9], real_T r0[3], emxArray_real_T *rL,
                      emxArray_real_T *e, emxArray_real_T *g,
                      real_T nLinksJoints, emxArray_real_T *robotConBranch,
                      emxArray_struct0_T *robotJoints,
                      emxArray_cell_wrap_1 *Bij, emxArray_cell_wrap_1 *Bi0,
                      real_T P0[36], emxArray_real_T *pm);

void DiffKinematics_C_api(const mxArray *const prhs[8], int32_T nlhs,
                          const mxArray *plhs[4]);

void FD_C(real_T tau0[6], emxArray_real_T *taum, real_T wF0[6],
          emxArray_real_T *wFm, real_T t0[6], emxArray_real_T *b_tm,
          real_T P0[36], emxArray_real_T *pm, real_T I0[9],
          emxArray_cell_wrap_2 *Im, emxArray_cell_wrap_1 *Bij,
          emxArray_cell_wrap_1 *Bi0, real_T u0[6], emxArray_real_T *um,
          real_T nLinksJoints, real_T nQ, struct2_T *robotBaseLink,
          emxArray_struct1_T *robotLinks, emxArray_real_T *robotConChild,
          emxArray_real_T *robotConChildBase, emxArray_struct0_T *robotJoints,
          real_T u0dot[6], emxArray_real_T *umdot);

void FD_C_api(const mxArray *const prhs[21], int32_T nlhs,
              const mxArray *plhs[2]);

void ID_C(real_T wF0[6], emxArray_real_T *wFm, real_T t0[6],
          emxArray_real_T *tL, real_T t0dot[6], emxArray_real_T *tLdot,
          real_T P0[36], emxArray_real_T *pm, real_T I0[9],
          emxArray_cell_wrap_2 *Im, emxArray_cell_wrap_1 *Bij,
          emxArray_cell_wrap_1 *Bi0, real_T nLinksJoints, real_T nQ,
          struct2_T *robotBaseLink, emxArray_struct1_T *robotLinks,
          emxArray_real_T *robotConChild, emxArray_real_T *robotConChildBase,
          emxArray_struct0_T *robotJoints, real_T tau0[6],
          emxArray_real_T *taum);

void ID_C_api(const mxArray *const prhs[19], int32_T nlhs,
              const mxArray *plhs[2]);

void I_I_C(real_T R0[9], emxArray_real_T *RL, real_T nLinksJoints,
           real_T robotBaseInertia[9], emxArray_struct1_T *robotLinks,
           real_T I0[9], emxArray_cell_wrap_2 *Im);

void I_I_C_api(const mxArray *const prhs[5], int32_T nlhs,
               const mxArray *plhs[2]);

void Kinematics_C(real_T R0[9], real_T r0[3], emxArray_real_T *qm,
                  real_T nLinksJoints, emxArray_struct0_T *robotJoints,
                  emxArray_struct1_T *robotLinks, emxArray_real_T *RJ,
                  emxArray_real_T *RL, emxArray_real_T *rJ, emxArray_real_T *rL,
                  emxArray_real_T *e, emxArray_real_T *g);

void Kinematics_C_api(const mxArray *const prhs[6], int32_T nlhs,
                      const mxArray *plhs[6]);

void SPART_C_atexit(void);

void SPART_C_initialize(void);

void SPART_C_terminate(void);

void SPART_C_xil_shutdown(void);

void SPART_C_xil_terminate(void);

void SPART_SPACEROBOT_ODE_C(
    uint64_T t, emxArray_real_T *y, emxArray_real_T *tau, real_T nLinksJoints,
    emxArray_struct0_T *robotJoints, emxArray_struct1_T *robotLinks,
    emxArray_real_T *robotConBranch, real_T robotBaseInertia[9], real_T nQ,
    struct2_T *robotBaseLink, emxArray_real_T *robotConChild,
    emxArray_real_T *robotConChildBase, emxArray_real_T *dydt);

void SPART_SPACEROBOT_ODE_C_api(const mxArray *const prhs[12],
                                const mxArray **plhs);

void Velocities_C(emxArray_cell_wrap_1 *Bij, emxArray_cell_wrap_1 *Bi0,
                  real_T P0[36], emxArray_real_T *pm, real_T u0[6],
                  emxArray_real_T *um, real_T nLinksJoints,
                  emxArray_struct0_T *robotJoints, real_T t0[6],
                  emxArray_real_T *tL);

void Velocities_C_api(const mxArray *const prhs[8], int32_T nlhs,
                      const mxArray *plhs[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_SPART_C_api.h
 *
 * [EOF]
 */
