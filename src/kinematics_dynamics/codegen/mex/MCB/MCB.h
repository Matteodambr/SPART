/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * MCB.h
 *
 * Code generation for function 'MCB'
 *
 */

#pragma once

/* Include files */
#include "MCB_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void MCB(const emlrtStack *sp, const real_T I0[9], const emxArray_real_T *Im,
         const emxArray_real_T *Bij, const emxArray_real_T *Bi0,
         const struct0_T *robot, real_T M0_tilde[36],
         emxArray_real_T *Mm_tilde);

/* End of code generation (MCB.h) */
