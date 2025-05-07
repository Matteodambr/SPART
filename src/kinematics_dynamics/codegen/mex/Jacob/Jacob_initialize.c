/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Jacob_initialize.c
 *
 * Code generation for function 'Jacob_initialize'
 *
 */

/* Include files */
#include "Jacob_initialize.h"
#include "Jacob_data.h"
#include "_coder_Jacob_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void Jacob_once(void);

/* Function Definitions */
static void Jacob_once(void)
{
  mex_InitInfAndNan();
}

void Jacob_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    Jacob_once();
  }
}

/* End of code generation (Jacob_initialize.c) */
