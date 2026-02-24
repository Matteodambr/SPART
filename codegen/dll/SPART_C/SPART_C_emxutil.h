/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SPART_C_emxutil.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

#ifndef SPART_C_EMXUTIL_H
#define SPART_C_EMXUTIL_H

/* Include Files */
#include "SPART_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_cell_wrap_0(emxArray_cell_wrap_0 *emxArray,
                                          int oldNumel);

extern void emxEnsureCapacity_cell_wrap_1(emxArray_cell_wrap_1 *emxArray,
                                          int oldNumel);

extern void emxEnsureCapacity_cell_wrap_2(emxArray_cell_wrap_2 *emxArray,
                                          int oldNumel);

extern void emxEnsureCapacity_cell_wrap_3(emxArray_cell_wrap_3 *emxArray,
                                          int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);

extern void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray);

extern void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray);

extern void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxFree_struct0_T(emxArray_struct0_T **pEmxArray);

extern void emxFree_struct1_T(emxArray_struct1_T **pEmxArray);

extern void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);

extern void emxInit_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray,
                                int numDimensions);

extern void emxInit_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray,
                                int numDimensions);

extern void emxInit_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxInit_struct0_T(emxArray_struct0_T **pEmxArray,
                              int numDimensions);

extern void emxInit_struct1_T(emxArray_struct1_T **pEmxArray,
                              int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for SPART_C_emxutil.h
 *
 * [EOF]
 */
