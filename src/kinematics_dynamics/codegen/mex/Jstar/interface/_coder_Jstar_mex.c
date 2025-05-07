/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_Jstar_mex.c
 *
 * Code generation for function '_coder_Jstar_mex'
 *
 */

/* Include files */
#include "_coder_Jstar_mex.h"
#include "Jstar_data.h"
#include "Jstar_initialize.h"
#include "Jstar_terminate.h"
#include "_coder_Jstar_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Jstar_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                       const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        5, "Jstar");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "Jstar");
  }
  /* Call the function. */
  Jstar_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&Jstar_atexit);
  Jstar_initialize();
  Jstar_mexFunction(nlhs, plhs, nrhs, prhs);
  Jstar_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Jstar_mex.c) */
