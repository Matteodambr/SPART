/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * CIM_initialize.c
 *
 * Code generation for function 'CIM_initialize'
 *
 */

/* Include files */
#include "CIM_initialize.h"
#include "CIM_data.h"
#include "_coder_CIM_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void CIM_once(void);

/* Function Definitions */
static void CIM_once(void)
{
  mex_InitInfAndNan();
}

void CIM_initialize(void)
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
    CIM_once();
  }
}

/* End of code generation (CIM_initialize.c) */
