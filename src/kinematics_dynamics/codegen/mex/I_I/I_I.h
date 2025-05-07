/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * I_I.h
 *
 * Code generation for function 'I_I'
 *
 */

#pragma once

/* Include files */
#include "I_I_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void I_I(const emlrtStack *sp, const real_T R0[9], const emxArray_real_T *RL,
         const struct0_T *robot, real_T I0[9], emxArray_real_T *Im);

emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

/* End of code generation (I_I.h) */
