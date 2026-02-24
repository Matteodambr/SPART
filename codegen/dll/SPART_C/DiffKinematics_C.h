/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: DiffKinematics_C.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

#ifndef DIFFKINEMATICS_C_H
#define DIFFKINEMATICS_C_H

/* Include Files */
#include "SPART_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void DiffKinematics_C(
    const double R0[9], const double r0[3], const emxArray_real_T *rL,
    const emxArray_real_T *e, const emxArray_real_T *g, double nLinksJoints,
    const emxArray_real_T *robotConBranch,
    const emxArray_struct0_T *robotJoints, emxArray_cell_wrap_1 *Bij,
    emxArray_cell_wrap_1 *Bi0, double P0[36], emxArray_real_T *pm);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for DiffKinematics_C.h
 *
 * [EOF]
 */
