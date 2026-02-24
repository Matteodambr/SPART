/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FD_C.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

#ifndef FD_C_H
#define FD_C_H

/* Include Files */
#include "SPART_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void FD_C(const double tau0[6], const emxArray_real_T *taum,
                 const double wF0[6], const emxArray_real_T *wFm,
                 const double t0[6], const emxArray_real_T *b_tm,
                 const double P0[36], const emxArray_real_T *pm,
                 const double I0[9], const emxArray_cell_wrap_2 *Im,
                 const emxArray_cell_wrap_1 *Bij,
                 const emxArray_cell_wrap_1 *Bi0, const double u0[6],
                 const emxArray_real_T *um, double nLinksJoints, double nQ,
                 const struct2_T *robotBaseLink,
                 const emxArray_struct1_T *robotLinks,
                 const emxArray_real_T *robotConChild,
                 const emxArray_real_T *robotConChildBase,
                 const emxArray_struct0_T *robotJoints, double u0dot[6],
                 emxArray_real_T *umdot);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for FD_C.h
 *
 * [EOF]
 */
