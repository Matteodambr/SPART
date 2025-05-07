/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * GIM.h
 *
 * Code generation for function 'GIM'
 *
 */

#pragma once

/* Include files */
#include "GIM_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void GIM(const emlrtStack *sp, const real_T M0_tilde[36],
         const emxArray_real_T *Mm_tilde, const emxArray_real_T *Bij,
         const emxArray_real_T *Bi0, const real_T P0[36],
         const emxArray_real_T *pm, const struct0_T *robot, real_T H0[36],
         emxArray_real_T *H0m, emxArray_real_T *Hm);

/* End of code generation (GIM.h) */
