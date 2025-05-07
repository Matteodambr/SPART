/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Velocities_initialize.c
 *
 * Code generation for function 'Velocities_initialize'
 *
 */

/* Include files */
#include "Velocities_initialize.h"
#include "Velocities_data.h"
#include "_coder_Velocities_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void Velocities_once(void);

/* Function Definitions */
static void Velocities_once(void)
{
  mex_InitInfAndNan();
}

void Velocities_initialize(void)
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
    Velocities_once();
  }
}

/* End of code generation (Velocities_initialize.c) */
