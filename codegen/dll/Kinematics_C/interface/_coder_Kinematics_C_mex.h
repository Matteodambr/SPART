/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Kinematics_C_mex.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 10:31:47
 */

#ifndef _CODER_KINEMATICS_C_MEX_H
#define _CODER_KINEMATICS_C_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_Kinematics_C_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                     int32_T nrhs, const mxArray *prhs[6]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_Kinematics_C_mex.h
 *
 * [EOF]
 */
