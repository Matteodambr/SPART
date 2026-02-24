/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SPART_C_initialize.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

/* Include Files */
#include "SPART_C_initialize.h"
#include "SPART_C_data.h"
#include "omp.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void SPART_C_initialize(void)
{
  omp_init_nest_lock(&SPART_C_nestLockGlobal);
  isInitialized_SPART_C = true;
}

/*
 * File trailer for SPART_C_initialize.c
 *
 * [EOF]
 */
