/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * CIM_types.h
 *
 * Code generation for function 'CIM'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T id;
  real_T parent_joint;
  real_T T[16];
  real_T mass;
  real_T inertia[9];
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  real_T id;
  real_T type;
  real_T q_id;
  real_T parent_link;
  real_T child_link;
  real_T axis[3];
  real_T T[16];
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef typedef_struct3_T
#define typedef_struct3_T
typedef struct {
  real_T mass;
  real_T inertia[9];
} struct3_T;
#endif /* typedef_struct3_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_char_T */
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif /* typedef_emxArray_char_T */

#ifndef typedef_emxArray_struct1_T
#define typedef_emxArray_struct1_T
typedef struct {
  struct1_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct1_T;
#endif /* typedef_emxArray_struct1_T */

#ifndef typedef_emxArray_struct2_T
#define typedef_emxArray_struct2_T
typedef struct {
  struct2_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct2_T;
#endif /* typedef_emxArray_struct2_T */

#ifndef typedef_struct4_T
#define typedef_struct4_T
typedef struct {
  emxArray_real_T *branch;
  emxArray_real_T *child;
  emxArray_real_T *child_base;
} struct4_T;
#endif /* typedef_struct4_T */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  emxArray_char_T *name;
  real_T n_q;
  real_T n_links_joints;
  emxArray_struct1_T *links;
  emxArray_struct2_T *joints;
  struct3_T base_link;
  struct4_T con;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

/* End of code generation (CIM_types.h) */
