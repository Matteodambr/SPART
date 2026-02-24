/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ID_C.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

#ifndef ID_C_H
#define ID_C_H

/* Include Files */
#include "SPART_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void ID_C(const double wF0[6], const emxArray_real_T *wFm,
                 const double t0[6], const emxArray_real_T *tL,
                 const double t0dot[6], const emxArray_real_T *tLdot,
                 const double P0[36], const emxArray_real_T *pm,
                 const double I0[9], const emxArray_cell_wrap_2 *Im,
                 const emxArray_cell_wrap_1 *Bij,
                 const emxArray_cell_wrap_1 *Bi0, double nLinksJoints,
                 double nQ, const struct2_T *robotBaseLink,
                 const emxArray_struct1_T *robotLinks,
                 const emxArray_real_T *robotConChild,
                 const emxArray_real_T *robotConChildBase,
                 const emxArray_struct0_T *robotJoints, double tau0[6],
                 emxArray_real_T *taum);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for ID_C.h
 *
 * [EOF]
 */
