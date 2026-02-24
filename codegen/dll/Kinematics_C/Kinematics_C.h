/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Kinematics_C.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 10:31:47
 */

#ifndef KINEMATICS_C_H
#define KINEMATICS_C_H

/* Include Files */
#include "Kinematics_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Kinematics_C(const double R0[9], const double r0[3],
                         const emxArray_real_T *qm, double nLinksJoints,
                         const emxArray_struct0_T *robotJoints,
                         const emxArray_struct1_T *robotLinks,
                         emxArray_real_T *RJ, emxArray_real_T *RL,
                         emxArray_real_T *rJ, emxArray_real_T *rL,
                         emxArray_real_T *e, emxArray_real_T *g);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Kinematics_C.h
 *
 * [EOF]
 */
