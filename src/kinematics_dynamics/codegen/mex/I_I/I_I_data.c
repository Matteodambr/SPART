/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * I_I_data.c
 *
 * Code generation for function 'I_I_data'
 *
 */

/* Include files */
#include "I_I_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131674U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "I_I",                                                /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t I_I_nestLockGlobal;

/* End of code generation (I_I_data.c) */
