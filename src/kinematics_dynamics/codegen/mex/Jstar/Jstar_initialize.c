/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Jstar_initialize.c
 *
 * Code generation for function 'Jstar_initialize'
 *
 */

/* Include files */
#include "Jstar_initialize.h"
#include "Jstar_data.h"
#include "_coder_Jstar_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void Jstar_once(void);

/* Function Definitions */
static void Jstar_once(void)
{
  mex_InitInfAndNan();
}

void Jstar_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
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
    Jstar_once();
  }
}

/* End of code generation (Jstar_initialize.c) */
