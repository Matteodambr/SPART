/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_DiffKinematics_mex.c
 *
 * Code generation for function '_coder_DiffKinematics_mex'
 *
 */

/* Include files */
#include "_coder_DiffKinematics_mex.h"
#include "DiffKinematics_data.h"
#include "DiffKinematics_initialize.h"
#include "DiffKinematics_terminate.h"
#include "_coder_DiffKinematics_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void DiffKinematics_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
                                const mxArray *prhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[4];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        14, "DiffKinematics");
  }
  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "DiffKinematics");
  }
  /* Call the function. */
  DiffKinematics_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&DiffKinematics_atexit);
  DiffKinematics_initialize();
  DiffKinematics_mexFunction(nlhs, plhs, nrhs, prhs);
  DiffKinematics_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_DiffKinematics_mex.c) */
