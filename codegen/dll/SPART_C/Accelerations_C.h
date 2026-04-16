/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Accelerations_C.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

#ifndef ACCELERATIONS_C_H
#define ACCELERATIONS_C_H

/* Include Files */
#include "SPART_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Accelerations_C(const double t0[6], const emxArray_real_T *tL,
                            const double P0[36], const emxArray_real_T *pm,
                            const emxArray_cell_wrap_1 *Bi0,
                            const emxArray_cell_wrap_1 *Bij, const double u0[6],
                            const emxArray_real_T *um, const double u0dot[6],
                            const emxArray_real_T *umdot, double nLinksJoints,
                            const emxArray_struct0_T *robotJoints,
                            double t0dot[6], emxArray_real_T *tLdot);

void b_Accelerations_C(const double t0[6], const emxArray_real_T *tL,
                       const double P0[36], const emxArray_real_T *pm,
                       const emxArray_cell_wrap_1 *Bi0,
                       const emxArray_cell_wrap_1 *Bij, const double u0[6],
                       const emxArray_real_T *um, double nLinksJoints,
                       const emxArray_struct0_T *robotJoints, double t0dot[6],
                       emxArray_real_T *tLdot);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Accelerations_C.h
 *
 * [EOF]
 */
