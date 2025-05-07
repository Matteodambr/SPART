/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * DiffKinematics.h
 *
 * Code generation for function 'DiffKinematics'
 *
 */

#pragma once

/* Include files */
#include "DiffKinematics_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void DiffKinematics(const emlrtStack *sp, const real_T R0[9],
                    const real_T r0[3], const emxArray_real_T *rL,
                    const emxArray_real_T *e, const emxArray_real_T *g,
                    const struct0_T *robot, emxArray_real_T *Bij,
                    emxArray_real_T *Bi0, real_T P0[36], emxArray_real_T *pm);

/* End of code generation (DiffKinematics.h) */
