/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * Kinematics_initialize.c
 *
 * Code generation for function 'Kinematics_initialize'
 *
 */

/* Include files */
#include "Kinematics_initialize.h"
#include "Kinematics_data.h"
#include "_coder_Kinematics_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void Kinematics_once(void);

/* Function Definitions */
static void Kinematics_once(void)
{
  mex_InitInfAndNan();
}

void Kinematics_initialize(void)
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
    Kinematics_once();
  }
}

/* End of code generation (Kinematics_initialize.c) */
