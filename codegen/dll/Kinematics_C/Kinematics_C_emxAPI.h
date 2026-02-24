/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Kinematics_C_emxAPI.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 10:31:47
 */

#ifndef KINEMATICS_C_EMXAPI_H
#define KINEMATICS_C_EMXAPI_H

/* Include Files */
#include "Kinematics_C_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);

extern emxArray_struct0_T *emxCreateND_struct0_T(int numDimensions,
                                                 const int *size);

extern emxArray_struct1_T *emxCreateND_struct1_T(int numDimensions,
                                                 const int *size);

extern emxArray_real_T *
emxCreateWrapperND_real_T(double *data, int numDimensions, const int *size);

extern emxArray_struct0_T *emxCreateWrapperND_struct0_T(struct0_T *data,
                                                        int numDimensions,
                                                        const int *size);

extern emxArray_struct1_T *emxCreateWrapperND_struct1_T(struct1_T *data,
                                                        int numDimensions,
                                                        const int *size);

extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows,
                                                int cols);

extern emxArray_struct0_T *emxCreateWrapper_struct0_T(struct0_T *data, int rows,
                                                      int cols);

extern emxArray_struct1_T *emxCreateWrapper_struct1_T(struct1_T *data, int rows,
                                                      int cols);

extern emxArray_real_T *emxCreate_real_T(int rows, int cols);

extern emxArray_struct0_T *emxCreate_struct0_T(int rows, int cols);

extern emxArray_struct1_T *emxCreate_struct1_T(int rows, int cols);

extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);

extern void emxDestroyArray_struct0_T(emxArray_struct0_T *emxArray);

extern void emxDestroyArray_struct1_T(emxArray_struct1_T *emxArray);

extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxInitArray_struct0_T(emxArray_struct0_T **pEmxArray,
                                   int numDimensions);

extern void emxInitArray_struct1_T(emxArray_struct1_T **pEmxArray,
                                   int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Kinematics_C_emxAPI.h
 *
 * [EOF]
 */
