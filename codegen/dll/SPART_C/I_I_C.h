/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: I_I_C.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

#ifndef I_I_C_H
#define I_I_C_H

/* Include Files */
#include "SPART_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void I_I_C(const double R0[9], const emxArray_real_T *RL,
                  double nLinksJoints, const double robotBaseInertia[9],
                  const emxArray_struct1_T *robotLinks, double I0[9],
                  emxArray_cell_wrap_2 *Im);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for I_I_C.h
 *
 * [EOF]
 */
