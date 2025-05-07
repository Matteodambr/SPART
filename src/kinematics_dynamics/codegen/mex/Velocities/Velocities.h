/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Velocities.h
 *
 * Code generation for function 'Velocities'
 *
 */

#pragma once

/* Include files */
#include "Velocities_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void Velocities(const emlrtStack *sp, const emxArray_real_T *Bij,
                const emxArray_real_T *Bi0, const real_T P0[36],
                const emxArray_real_T *pm, const real_T u0[6],
                const emxArray_real_T *um, const struct0_T *robot, real_T t0[6],
                emxArray_real_T *tL);

/* End of code generation (Velocities.h) */
