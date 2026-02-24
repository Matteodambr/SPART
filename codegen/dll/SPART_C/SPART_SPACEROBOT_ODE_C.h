/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SPART_SPACEROBOT_ODE_C.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

#ifndef SPART_SPACEROBOT_ODE_C_H
#define SPART_SPACEROBOT_ODE_C_H

/* Include Files */
#include "SPART_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void SPART_SPACEROBOT_ODE_C(
    unsigned long t, const emxArray_real_T *y, const emxArray_real_T *tau,
    double nLinksJoints, const emxArray_struct0_T *robotJoints,
    const emxArray_struct1_T *robotLinks, const emxArray_real_T *robotConBranch,
    const double robotBaseInertia[9], double nQ, const struct2_T *robotBaseLink,
    const emxArray_real_T *robotConChild,
    const emxArray_real_T *robotConChildBase, emxArray_real_T *dydt);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for SPART_SPACEROBOT_ODE_C.h
 *
 * [EOF]
 */
