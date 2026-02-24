/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Velocities_C.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

#ifndef VELOCITIES_C_H
#define VELOCITIES_C_H

/* Include Files */
#include "SPART_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Velocities_C(const emxArray_cell_wrap_1 *Bij,
                         const emxArray_cell_wrap_1 *Bi0, const double P0[36],
                         const emxArray_real_T *pm, const double u0[6],
                         const emxArray_real_T *um, double nLinksJoints,
                         const emxArray_struct0_T *robotJoints, double t0[6],
                         emxArray_real_T *tL);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Velocities_C.h
 *
 * [EOF]
 */
