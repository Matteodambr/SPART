/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_Kinematics_mex.c
 *
 * Code generation for function '_coder_Kinematics_mex'
 *
 */

/* Include files */
#include "_coder_Kinematics_mex.h"
#include "Kinematics_data.h"
#include "Kinematics_initialize.h"
#include "Kinematics_terminate.h"
#include "_coder_Kinematics_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Kinematics_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T nrhs,
                            const mxArray *prhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[6];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        10, "Kinematics");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "Kinematics");
  }
  /* Call the function. */
  Kinematics_api(prhs, nlhs, outputs);
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
  mexAtExit(&Kinematics_atexit);
  Kinematics_initialize();
  Kinematics_mexFunction(nlhs, plhs, nrhs, prhs);
  Kinematics_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Kinematics_mex.c) */
