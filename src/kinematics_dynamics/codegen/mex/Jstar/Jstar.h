/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Jstar.h
 *
 * Code generation for function 'Jstar'
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
void Jstar(const emlrtStack *sp, const real_T H0[36],
           const emxArray_real_T *H0m, const real_T J0[36],
           const emxArray_real_T *Jm, emxArray_real_T *b_Jstar);

/* End of code generation (Jstar.h) */
