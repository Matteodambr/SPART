/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * GIM_initialize.c
 *
 * Code generation for function 'GIM_initialize'
 *
 */

/* Include files */
#include "GIM_initialize.h"
#include "GIM_data.h"
#include "_coder_GIM_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void GIM_once(void);

/* Function Definitions */
static void GIM_once(void)
{
  mex_InitInfAndNan();
}

void GIM_initialize(void)
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
    GIM_once();
  }
}

/* End of code generation (GIM_initialize.c) */
