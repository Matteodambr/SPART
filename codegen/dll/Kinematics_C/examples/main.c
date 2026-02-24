/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 10:31:47
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "Kinematics_C.h"
#include "Kinematics_C_emxAPI.h"
#include "Kinematics_C_initialize.h"
#include "Kinematics_C_terminate.h"
#include "Kinematics_C_types.h"

/* Function Declarations */
static emxArray_struct0_T *argInit_1xUnbounded_struct0_T(void);

static emxArray_struct1_T *argInit_1xUnbounded_struct1_T(void);

static void argInit_3x1_real_T(double result[3]);

static void argInit_3x3_real_T(double result[9]);

static void argInit_4x4_real_T(double result[16]);

static emxArray_real_T *argInit_Unboundedx1_real_T(void);

static double argInit_real_T(void);

static void argInit_struct0_T(struct0_T *result);

static void argInit_struct1_T(struct1_T *result);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_struct0_T *
 */
static emxArray_struct0_T *argInit_1xUnbounded_struct0_T(void)
{
  emxArray_struct0_T *result;
  struct0_T *result_data;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_struct0_T(1, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    argInit_struct0_T(&result_data[idx1]);
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_struct1_T *
 */
static emxArray_struct1_T *argInit_1xUnbounded_struct1_T(void)
{
  emxArray_struct1_T *result;
  struct1_T *result_data;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_struct1_T(1, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    argInit_struct1_T(&result_data[idx1]);
  }
  return result;
}

/*
 * Arguments    : double result[3]
 * Return Type  : void
 */
static void argInit_3x1_real_T(double result[3])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[9]
 * Return Type  : void
 */
static void argInit_3x3_real_T(double result[9])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 9; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[16]
 * Return Type  : void
 */
static void argInit_4x4_real_T(double result[16])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 16; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int i = 2;
  int idx0;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, &i);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx0] = argInit_real_T();
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : struct0_T *result
 * Return Type  : void
 */
static void argInit_struct0_T(struct0_T *result)
{
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result->id = result_tmp;
  result->type = result_tmp;
  result->q_id = result_tmp;
  result->parent_link = result_tmp;
  result->child_link = result_tmp;
  argInit_3x1_real_T(result->axis);
  argInit_4x4_real_T(result->T);
}

/*
 * Arguments    : struct1_T *result
 * Return Type  : void
 */
static void argInit_struct1_T(struct1_T *result)
{
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result->id = result_tmp;
  result->parent_joint = result_tmp;
  argInit_4x4_real_T(result->T);
  result->mass = result_tmp;
  argInit_3x3_real_T(result->inertia);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* Initialize the application.
You do not need to do this more than one time. */
  Kinematics_C_initialize();
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_Kinematics_C();
  /* Terminate the application.
You do not need to do this more than one time. */
  Kinematics_C_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Kinematics_C(void)
{
  emxArray_real_T *RJ;
  emxArray_real_T *RL;
  emxArray_real_T *e;
  emxArray_real_T *g;
  emxArray_real_T *qm;
  emxArray_real_T *rJ;
  emxArray_real_T *rL;
  emxArray_struct0_T *robotJoints;
  emxArray_struct1_T *robotLinks;
  double dv[9];
  double dv1[3];
  /* Initialize function 'Kinematics_C' input arguments. */
  /* Initialize function input argument 'R0'. */
  /* Initialize function input argument 'r0'. */
  /* Initialize function input argument 'qm'. */
  qm = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'robotJoints'. */
  robotJoints = argInit_1xUnbounded_struct0_T();
  /* Initialize function input argument 'robotLinks'. */
  robotLinks = argInit_1xUnbounded_struct1_T();
  /* Call the entry-point 'Kinematics_C'. */
  emxInitArray_real_T(&RJ, 2);
  emxInitArray_real_T(&RL, 2);
  emxInitArray_real_T(&rJ, 2);
  emxInitArray_real_T(&rL, 2);
  emxInitArray_real_T(&e, 2);
  emxInitArray_real_T(&g, 2);
  argInit_3x3_real_T(dv);
  argInit_3x1_real_T(dv1);
  Kinematics_C(dv, dv1, qm, argInit_real_T(), robotJoints, robotLinks, RJ, RL,
               rJ, rL, e, g);
  emxDestroyArray_struct1_T(robotLinks);
  emxDestroyArray_struct0_T(robotJoints);
  emxDestroyArray_real_T(qm);
  emxDestroyArray_real_T(RJ);
  emxDestroyArray_real_T(RL);
  emxDestroyArray_real_T(rJ);
  emxDestroyArray_real_T(rL);
  emxDestroyArray_real_T(e);
  emxDestroyArray_real_T(g);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
