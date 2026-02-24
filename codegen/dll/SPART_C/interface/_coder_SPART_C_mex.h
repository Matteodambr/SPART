/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_SPART_C_mex.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

#ifndef _CODER_SPART_C_MEX_H
#define _CODER_SPART_C_MEX_H

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

void unsafe_Accelerations_C_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                        int32_T nrhs, const mxArray *prhs[12]);

void unsafe_DiffKinematics_C_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                         int32_T nrhs, const mxArray *prhs[8]);

void unsafe_FD_C_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                             const mxArray *prhs[21]);

void unsafe_ID_C_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                             const mxArray *prhs[19]);

void unsafe_I_I_C_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                              const mxArray *prhs[5]);

void unsafe_Kinematics_C_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                     int32_T nrhs, const mxArray *prhs[6]);

void unsafe_Velocities_C_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                     int32_T nrhs, const mxArray *prhs[8]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_SPART_C_mex.h
 *
 * [EOF]
 */
