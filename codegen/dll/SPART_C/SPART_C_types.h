/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SPART_C_types.h
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

#ifndef SPART_C_TYPES_H
#define SPART_C_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3
typedef struct {
  double f1[6];
} cell_wrap_3;
#endif /* typedef_cell_wrap_3 */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  double id;
  double type;
  double q_id;
  double parent_link;
  double child_link;
  double axis[3];
  double T[16];
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  double id;
  double parent_joint;
  double T[16];
  double mass;
  double inertia[9];
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  double f1[16];
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1
typedef struct {
  double f1[36];
} cell_wrap_1;
#endif /* typedef_cell_wrap_1 */

#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2
typedef struct {
  double f1[9];
} cell_wrap_2;
#endif /* typedef_cell_wrap_2 */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  double mass;
  double inertia[9];
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_emxArray_struct0_T
#define typedef_emxArray_struct0_T
typedef struct {
  struct0_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_struct0_T;
#endif /* typedef_emxArray_struct0_T */

#ifndef typedef_emxArray_struct1_T
#define typedef_emxArray_struct1_T
typedef struct {
  struct1_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_struct1_T;
#endif /* typedef_emxArray_struct1_T */

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0
typedef struct {
  cell_wrap_0 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_0;
#endif /* typedef_emxArray_cell_wrap_0 */

#ifndef typedef_emxArray_cell_wrap_1
#define typedef_emxArray_cell_wrap_1
typedef struct {
  cell_wrap_1 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_1;
#endif /* typedef_emxArray_cell_wrap_1 */

#ifndef typedef_emxArray_cell_wrap_2
#define typedef_emxArray_cell_wrap_2
typedef struct {
  cell_wrap_2 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_2;
#endif /* typedef_emxArray_cell_wrap_2 */

#ifndef typedef_emxArray_cell_wrap_3
#define typedef_emxArray_cell_wrap_3
typedef struct {
  cell_wrap_3 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_3;
#endif /* typedef_emxArray_cell_wrap_3 */

#endif
/*
 * File trailer for SPART_C_types.h
 *
 * [EOF]
 */
