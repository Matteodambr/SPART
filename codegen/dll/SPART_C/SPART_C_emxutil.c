/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SPART_C_emxutil.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
 */

/* Include Files */
#include "SPART_C_emxutil.h"
#include "SPART_C_types.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : emxArray_cell_wrap_0 *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_cell_wrap_0(emxArray_cell_wrap_0 *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int newCapacity;
    newCapacity = emxArray->allocatedSize;
    if (newCapacity < 16) {
      newCapacity = 16;
    }
    while (newCapacity < newNumel) {
      if (newCapacity > 1073741823) {
        newCapacity = MAX_int32_T;
      } else {
        newCapacity *= 2;
      }
    }
    newData = malloc((unsigned int)newCapacity * sizeof(cell_wrap_0));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(cell_wrap_0) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_0 *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_1 *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_cell_wrap_1(emxArray_cell_wrap_1 *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int newCapacity;
    newCapacity = emxArray->allocatedSize;
    if (newCapacity < 16) {
      newCapacity = 16;
    }
    while (newCapacity < newNumel) {
      if (newCapacity > 1073741823) {
        newCapacity = MAX_int32_T;
      } else {
        newCapacity *= 2;
      }
    }
    newData = malloc((unsigned int)newCapacity * sizeof(cell_wrap_1));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(cell_wrap_1) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_1 *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_2 *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_cell_wrap_2(emxArray_cell_wrap_2 *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int newCapacity;
    newCapacity = emxArray->allocatedSize;
    if (newCapacity < 16) {
      newCapacity = 16;
    }
    while (newCapacity < newNumel) {
      if (newCapacity > 1073741823) {
        newCapacity = MAX_int32_T;
      } else {
        newCapacity *= 2;
      }
    }
    newData = malloc((unsigned int)newCapacity * sizeof(cell_wrap_2));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(cell_wrap_2) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_2 *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_3 *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_cell_wrap_3(emxArray_cell_wrap_3 *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int newCapacity;
    newCapacity = emxArray->allocatedSize;
    if (newCapacity < 16) {
      newCapacity = 16;
    }
    while (newCapacity < newNumel) {
      if (newCapacity > 1073741823) {
        newCapacity = MAX_int32_T;
      } else {
        newCapacity *= 2;
      }
    }
    newData = malloc((unsigned int)newCapacity * sizeof(cell_wrap_3));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(cell_wrap_3) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_3 *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int newCapacity;
    newCapacity = emxArray->allocatedSize;
    if (newCapacity < 16) {
      newCapacity = 16;
    }
    while (newCapacity < newNumel) {
      if (newCapacity > 1073741823) {
        newCapacity = MAX_int32_T;
      } else {
        newCapacity *= 2;
      }
    }
    newData = malloc((unsigned int)newCapacity * sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (double *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_0 **pEmxArray
 * Return Type  : void
 */
void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_0 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_0 *)NULL;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_1 **pEmxArray
 * Return Type  : void
 */
void emxFree_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_1 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_1 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_1 *)NULL;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_2 **pEmxArray
 * Return Type  : void
 */
void emxFree_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_2 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_2 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_2 *)NULL;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_3 **pEmxArray
 * Return Type  : void
 */
void emxFree_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_3 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_3 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_3 *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_struct0_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct0_T(emxArray_struct0_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct0_T *)NULL) {
    if (((*pEmxArray)->data != (struct0_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_struct0_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_struct1_T **pEmxArray
 * Return Type  : void
 */
void emxFree_struct1_T(emxArray_struct1_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct1_T *)NULL) {
    if (((*pEmxArray)->data != (struct1_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_struct1_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_0 **pEmxArray
 * Return Type  : void
 */
void emxInit_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  emxArray_cell_wrap_0 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_0 *)malloc(sizeof(emxArray_cell_wrap_0));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_0 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_1 **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_cell_wrap_1(emxArray_cell_wrap_1 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_1 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_1 *)malloc(sizeof(emxArray_cell_wrap_1));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_1 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_2 **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_cell_wrap_2(emxArray_cell_wrap_2 **pEmxArray, int numDimensions)
{
  emxArray_cell_wrap_2 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_2 *)malloc(sizeof(emxArray_cell_wrap_2));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_2 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_3 **pEmxArray
 * Return Type  : void
 */
void emxInit_cell_wrap_3(emxArray_cell_wrap_3 **pEmxArray)
{
  emxArray_cell_wrap_3 *emxArray;
  *pEmxArray = (emxArray_cell_wrap_3 *)malloc(sizeof(emxArray_cell_wrap_3));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_3 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int *)malloc(sizeof(int));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_struct0_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct0_T(emxArray_struct0_T **pEmxArray, int numDimensions)
{
  emxArray_struct0_T *emxArray;
  int i;
  *pEmxArray = (emxArray_struct0_T *)malloc(sizeof(emxArray_struct0_T));
  emxArray = *pEmxArray;
  emxArray->data = (struct0_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_struct1_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_struct1_T(emxArray_struct1_T **pEmxArray, int numDimensions)
{
  emxArray_struct1_T *emxArray;
  int i;
  *pEmxArray = (emxArray_struct1_T *)malloc(sizeof(emxArray_struct1_T));
  emxArray = *pEmxArray;
  emxArray->data = (struct1_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * File trailer for SPART_C_emxutil.c
 *
 * [EOF]
 */
