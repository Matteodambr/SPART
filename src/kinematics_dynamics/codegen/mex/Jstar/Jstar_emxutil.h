/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Jstar_emxutil.h
 *
 * Code generation for function 'Jstar_emxutil'
 *
 */

#pragma once

/* Include files */
#include "Jstar_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation);

/* End of code generation (Jstar_emxutil.h) */
