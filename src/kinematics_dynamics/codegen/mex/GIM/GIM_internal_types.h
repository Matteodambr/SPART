/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * GIM_internal_types.h
 *
 * Code generation for function 'GIM'
 *
 */

#pragma once

/* Include files */
#include "GIM_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

/* End of code generation (GIM_internal_types.h) */
