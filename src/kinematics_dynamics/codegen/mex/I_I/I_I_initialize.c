/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * I_I_initialize.c
 *
 * Code generation for function 'I_I_initialize'
 *
 */

/* Include files */
#include "I_I_initialize.h"
#include "I_I_data.h"
#include "_coder_I_I_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void I_I_once(void);

/* Function Definitions */
static void I_I_once(void)
{
  mex_InitInfAndNan();
}

void I_I_initialize(void)
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
    I_I_once();
  }
}

/* End of code generation (I_I_initialize.c) */
