/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * DiffKinematics_initialize.c
 *
 * Code generation for function 'DiffKinematics_initialize'
 *
 */

/* Include files */
#include "DiffKinematics_initialize.h"
#include "DiffKinematics_data.h"
#include "_coder_DiffKinematics_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void DiffKinematics_once(void);

/* Function Definitions */
static void DiffKinematics_once(void)
{
  mex_InitInfAndNan();
}

void DiffKinematics_initialize(void)
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
    DiffKinematics_once();
  }
}

/* End of code generation (DiffKinematics_initialize.c) */
