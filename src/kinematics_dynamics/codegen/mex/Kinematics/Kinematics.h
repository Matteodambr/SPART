/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Kinematics.h
 *
 * Code generation for function 'Kinematics'
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
void Kinematics(const emlrtStack *sp, const real_T R0[9], const real_T r0[3],
                const emxArray_real_T *qm, const struct0_T *robot,
                emxArray_real_T *RJ, emxArray_real_T *RL, emxArray_real_T *rJ,
                emxArray_real_T *rL, emxArray_real_T *e, emxArray_real_T *g);

/* End of code generation (Kinematics.h) */
