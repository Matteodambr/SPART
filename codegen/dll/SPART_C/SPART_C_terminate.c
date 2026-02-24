/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SPART_C_terminate.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

/* Include Files */
#include "SPART_C_terminate.h"
#include "SPART_C_data.h"
#include "omp.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void SPART_C_terminate(void)
{
  omp_destroy_nest_lock(&SPART_C_nestLockGlobal);
  isInitialized_SPART_C = false;
}

/*
 * File trailer for SPART_C_terminate.c
 *
 * [EOF]
 */
