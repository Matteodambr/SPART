/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Kinematics_emxutil.h
 *
 * Code generation for function 'Kinematics_emxutil'
 *
 */

#pragma once

/* Include files */
#include "Kinematics_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void emxEnsureCapacity_char_T(const emlrtStack *sp, emxArray_char_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_struct1_T(const emlrtStack *sp,
                                 emxArray_struct1_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_struct2_T(const emlrtStack *sp,
                                 emxArray_struct2_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxFreeStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct);

void emxFreeStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct);

void emxFree_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxFree_struct1_T(const emlrtStack *sp, emxArray_struct1_T **pEmxArray);

void emxFree_struct2_T(const emlrtStack *sp, emxArray_struct2_T **pEmxArray);

void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation);

void emxInit_struct1_T(const emlrtStack *sp, emxArray_struct1_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

void emxInit_struct2_T(const emlrtStack *sp, emxArray_struct2_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

/* End of code generation (Kinematics_emxutil.h) */
