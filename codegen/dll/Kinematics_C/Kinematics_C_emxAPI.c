/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Kinematics_C_emxAPI.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 10:31:47
 */

/* Include Files */
#include "Kinematics_C_emxAPI.h"
#include "Kinematics_C_emxutil.h"
#include "Kinematics_C_types.h"
#include <stdlib.h>

/* Function Definitions */
/*
 * Arguments    : int numDimensions
 *                const int *size
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size)
{
  emxArray_real_T *emx;
  int i;
  int numEl;
  emxInit_real_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = (double *)malloc((unsigned int)numEl * sizeof(double));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : int numDimensions
 *                const int *size
 * Return Type  : emxArray_struct0_T *
 */
emxArray_struct0_T *emxCreateND_struct0_T(int numDimensions, const int *size)
{
  emxArray_struct0_T *emx;
  int i;
  int numEl;
  emxInit_struct0_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = (struct0_T *)malloc((unsigned int)numEl * sizeof(struct0_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : int numDimensions
 *                const int *size
 * Return Type  : emxArray_struct1_T *
 */
emxArray_struct1_T *emxCreateND_struct1_T(int numDimensions, const int *size)
{
  emxArray_struct1_T *emx;
  int i;
  int numEl;
  emxInit_struct1_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = (struct1_T *)malloc((unsigned int)numEl * sizeof(struct1_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : double *data
 *                int numDimensions
 *                const int *size
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T *emxCreateWrapperND_real_T(double *data, int numDimensions,
                                           const int *size)
{
  emxArray_real_T *emx;
  int i;
  int numEl;
  emxInit_real_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : struct0_T *data
 *                int numDimensions
 *                const int *size
 * Return Type  : emxArray_struct0_T *
 */
emxArray_struct0_T *emxCreateWrapperND_struct0_T(struct0_T *data,
                                                 int numDimensions,
                                                 const int *size)
{
  emxArray_struct0_T *emx;
  int i;
  int numEl;
  emxInit_struct0_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : struct1_T *data
 *                int numDimensions
 *                const int *size
 * Return Type  : emxArray_struct1_T *
 */
emxArray_struct1_T *emxCreateWrapperND_struct1_T(struct1_T *data,
                                                 int numDimensions,
                                                 const int *size)
{
  emxArray_struct1_T *emx;
  int i;
  int numEl;
  emxInit_struct1_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : double *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols)
{
  emxArray_real_T *emx;
  emxInit_real_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : struct0_T *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_struct0_T *
 */
emxArray_struct0_T *emxCreateWrapper_struct0_T(struct0_T *data, int rows,
                                               int cols)
{
  emxArray_struct0_T *emx;
  emxInit_struct0_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : struct1_T *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_struct1_T *
 */
emxArray_struct1_T *emxCreateWrapper_struct1_T(struct1_T *data, int rows,
                                               int cols)
{
  emxArray_struct1_T *emx;
  emxInit_struct1_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T *emxCreate_real_T(int rows, int cols)
{
  emxArray_real_T *emx;
  emxInit_real_T(&emx, 2);
  emx->size[0] = rows;
  rows *= cols;
  emx->size[1] = cols;
  emx->data = (double *)malloc((unsigned int)rows * sizeof(double));
  emx->numDimensions = 2;
  emx->allocatedSize = rows;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_struct0_T *
 */
emxArray_struct0_T *emxCreate_struct0_T(int rows, int cols)
{
  emxArray_struct0_T *emx;
  emxInit_struct0_T(&emx, 2);
  emx->size[0] = rows;
  rows *= cols;
  emx->size[1] = cols;
  emx->data = (struct0_T *)malloc((unsigned int)rows * sizeof(struct0_T));
  emx->numDimensions = 2;
  emx->allocatedSize = rows;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_struct1_T *
 */
emxArray_struct1_T *emxCreate_struct1_T(int rows, int cols)
{
  emxArray_struct1_T *emx;
  emxInit_struct1_T(&emx, 2);
  emx->size[0] = rows;
  rows *= cols;
  emx->size[1] = cols;
  emx->data = (struct1_T *)malloc((unsigned int)rows * sizeof(struct1_T));
  emx->numDimensions = 2;
  emx->allocatedSize = rows;
  return emx;
}

/*
 * Arguments    : emxArray_real_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_real_T(emxArray_real_T *emxArray)
{
  emxFree_real_T(&emxArray);
}

/*
 * Arguments    : emxArray_struct0_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_struct0_T(emxArray_struct0_T *emxArray)
{
  emxFree_struct0_T(&emxArray);
}

/*
 * Arguments    : emxArray_struct1_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_struct1_T(emxArray_struct1_T *emxArray)
{
  emxFree_struct1_T(&emxArray);
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

/*
 * Arguments    : emxArray_struct0_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInitArray_struct0_T(emxArray_struct0_T **pEmxArray, int numDimensions)
{
  emxInit_struct0_T(pEmxArray, numDimensions);
}

/*
 * Arguments    : emxArray_struct1_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInitArray_struct1_T(emxArray_struct1_T **pEmxArray, int numDimensions)
{
  emxInit_struct1_T(pEmxArray, numDimensions);
}

/*
 * File trailer for Kinematics_C_emxAPI.c
 *
 * [EOF]
 */
