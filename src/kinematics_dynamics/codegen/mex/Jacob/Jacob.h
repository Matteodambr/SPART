/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Jacob.h
 *
 * Code generation for function 'Jacob'
 *
 */

#pragma once

/* Include files */
#include "Jacob_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void Jacob(const emlrtStack *sp, const real_T rp[3], const real_T r0[3],
           const emxArray_real_T *rL, const real_T P0[36],
           const emxArray_real_T *pm, real_T i, const struct0_T *robot,
           real_T J0[36], emxArray_real_T *Jm);

/* End of code generation (Jacob.h) */
