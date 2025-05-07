/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_GIM_mex.c
 *
 * Code generation for function '_coder_GIM_mex'
 *
 */

/* Include files */
#include "_coder_GIM_mex.h"
#include "GIM_data.h"
#include "GIM_initialize.h"
#include "GIM_terminate.h"
#include "_coder_GIM_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void GIM_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                     const mxArray *prhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        3, "GIM");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 3,
                        "GIM");
  }
  /* Call the function. */
  GIM_api(prhs, nlhs, outputs);
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
  mexAtExit(&GIM_atexit);
  GIM_initialize();
  GIM_mexFunction(nlhs, plhs, nrhs, prhs);
  GIM_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_GIM_mex.c) */
