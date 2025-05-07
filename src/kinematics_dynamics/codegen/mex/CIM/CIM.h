/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * CIM.h
 *
 * Code generation for function 'CIM'
 *
 */

#pragma once

/* Include files */
#include "CIM_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void CIM(const emlrtStack *sp, const real_T t0[6], const emxArray_real_T *tL,
         const real_T I0[9], const emxArray_real_T *Im,
         const real_T M0_tilde[36], const emxArray_real_T *Mm_tilde,
         const emxArray_real_T *Bij, const emxArray_real_T *Bi0,
         const real_T P0[36], const emxArray_real_T *pm, const struct0_T *robot,
         real_T C0[36], emxArray_real_T *C0m, emxArray_real_T *Cm0,
         emxArray_real_T *Cm);

emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

/* End of code generation (CIM.h) */
