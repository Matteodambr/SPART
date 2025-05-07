/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * MCB_initialize.c
 *
 * Code generation for function 'MCB_initialize'
 *
 */

/* Include files */
#include "MCB_initialize.h"
#include "MCB_data.h"
#include "_coder_MCB_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void MCB_once(void);

/* Function Definitions */
static void MCB_once(void)
{
  mex_InitInfAndNan();
}

void MCB_initialize(void)
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
    MCB_once();
  }
}

/* End of code generation (MCB_initialize.c) */
