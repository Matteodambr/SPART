/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 12:00:28
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
#include "Accelerations_C.h"
#include "DiffKinematics_C.h"
#include "FD_C.h"
#include "ID_C.h"
#include "I_I_C.h"
#include "Kinematics_C.h"
#include "SPART_C_emxAPI.h"
#include "SPART_C_initialize.h"
#include "SPART_C_terminate.h"
#include "SPART_C_types.h"
#include "Velocities_C.h"

/* Function Declarations */
static emxArray_cell_wrap_2 *argInit_1xUnbounded_cell_wrap_2(void);

static emxArray_struct0_T *argInit_1xUnbounded_struct0_T(void);

static emxArray_struct1_T *argInit_1xUnbounded_struct1_T(void);

static void argInit_3x1_real_T(double result[3]);

static void argInit_3x3_real_T(double result[9]);

static emxArray_real_T *argInit_3xUnbounded_real_T(void);

static void argInit_4x4_real_T(double result[16]);

static void argInit_6x1_real_T(double result[6]);

static void argInit_6x6_real_T(double result[36]);

static emxArray_real_T *argInit_6xUnbounded_real_T(void);

static emxArray_cell_wrap_1 *argInit_Unboundedx1_cell_wrap_1(void);

static emxArray_real_T *argInit_Unboundedx1_real_T(void);

static void argInit_cell_wrap_1(cell_wrap_1 *result);

static void argInit_cell_wrap_2(cell_wrap_2 *result);

static double argInit_real_T(void);

static void argInit_struct0_T(struct0_T *result);

static void argInit_struct1_T(struct1_T *result);

static void argInit_struct2_T(struct2_T *result);

static emxArray_cell_wrap_1 *c_argInit_UnboundedxUnbounded_c(void);

static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_cell_wrap_2 *
 */
static emxArray_cell_wrap_2 *argInit_1xUnbounded_cell_wrap_2(void)
{
  cell_wrap_2 *result_data;
  emxArray_cell_wrap_2 *result;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_cell_wrap_2(1, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    argInit_cell_wrap_2(&result_data[idx1]);
  }
  return result;
}

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
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_3xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(3, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + 3 * idx1] = argInit_real_T();
    }
  }
  return result;
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
 * Arguments    : double result[6]
 * Return Type  : void
 */
static void argInit_6x1_real_T(double result[6])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 6; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[36]
 * Return Type  : void
 */
static void argInit_6x6_real_T(double result[36])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 36; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_6xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(6, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 6; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + 6 * idx1] = argInit_real_T();
    }
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_cell_wrap_1 *
 */
static emxArray_cell_wrap_1 *argInit_Unboundedx1_cell_wrap_1(void)
{
  cell_wrap_1 *result_data;
  emxArray_cell_wrap_1 *result;
  int i = 2;
  int idx0;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreateND_cell_wrap_1(1, &i);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    argInit_cell_wrap_1(&result_data[idx0]);
  }
  return result;
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
 * Arguments    : cell_wrap_1 *result
 * Return Type  : void
 */
static void argInit_cell_wrap_1(cell_wrap_1 *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_6x6_real_T(result->f1);
}

/*
 * Arguments    : cell_wrap_2 *result
 * Return Type  : void
 */
static void argInit_cell_wrap_2(cell_wrap_2 *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_3x3_real_T(result->f1);
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
 * Arguments    : struct2_T *result
 * Return Type  : void
 */
static void argInit_struct2_T(struct2_T *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result->mass = argInit_real_T();
  argInit_3x3_real_T(result->inertia);
}

/*
 * Arguments    : void
 * Return Type  : emxArray_cell_wrap_1 *
 */
static emxArray_cell_wrap_1 *c_argInit_UnboundedxUnbounded_c(void)
{
  cell_wrap_1 *result_data;
  emxArray_cell_wrap_1 *result;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_cell_wrap_1(2, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      argInit_cell_wrap_1(&result_data[idx0 + result->size[0] * idx1]);
    }
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }
  return result;
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
  SPART_C_initialize();
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_Kinematics_C();
  main_DiffKinematics_C();
  main_Velocities_C();
  main_I_I_C();
  main_Accelerations_C();
  main_ID_C();
  main_FD_C();
  /* Terminate the application.
You do not need to do this more than one time. */
  SPART_C_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_Accelerations_C(void)
{
  emxArray_cell_wrap_1 *Bi0;
  emxArray_cell_wrap_1 *Bij;
  emxArray_real_T *pm;
  emxArray_real_T *tL;
  emxArray_real_T *tLdot;
  emxArray_real_T *um;
  emxArray_real_T *umdot;
  emxArray_struct0_T *robotJoints;
  double dv[36];
  double t0_tmp[6];
  double t0dot[6];
  /* Initialize function 'Accelerations_C' input arguments. */
  /* Initialize function input argument 't0'. */
  argInit_6x1_real_T(t0_tmp);
  /* Initialize function input argument 'tL'. */
  tL = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 'P0'. */
  /* Initialize function input argument 'pm'. */
  pm = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 'Bi0'. */
  Bi0 = argInit_Unboundedx1_cell_wrap_1();
  /* Initialize function input argument 'Bij'. */
  Bij = c_argInit_UnboundedxUnbounded_c();
  /* Initialize function input argument 'u0'. */
  /* Initialize function input argument 'um'. */
  um = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'u0dot'. */
  /* Initialize function input argument 'umdot'. */
  umdot = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'robotJoints'. */
  robotJoints = argInit_1xUnbounded_struct0_T();
  /* Call the entry-point 'Accelerations_C'. */
  emxInitArray_real_T(&tLdot, 2);
  argInit_6x6_real_T(dv);
  Accelerations_C(t0_tmp, tL, dv, pm, Bi0, Bij, t0_tmp, um, t0_tmp, umdot,
                  argInit_real_T(), robotJoints, t0dot, tLdot);
  emxDestroyArray_struct0_T(robotJoints);
  emxDestroyArray_real_T(umdot);
  emxDestroyArray_real_T(um);
  emxDestroyArray_cell_wrap_1(Bij);
  emxDestroyArray_cell_wrap_1(Bi0);
  emxDestroyArray_real_T(pm);
  emxDestroyArray_real_T(tL);
  emxDestroyArray_real_T(tLdot);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_DiffKinematics_C(void)
{
  emxArray_cell_wrap_1 *Bi0;
  emxArray_cell_wrap_1 *Bij;
  emxArray_real_T *e;
  emxArray_real_T *g;
  emxArray_real_T *pm;
  emxArray_real_T *rL;
  emxArray_real_T *robotConBranch;
  emxArray_struct0_T *robotJoints;
  double P0[36];
  double dv[9];
  double dv1[3];
  /* Initialize function 'DiffKinematics_C' input arguments. */
  /* Initialize function input argument 'R0'. */
  /* Initialize function input argument 'r0'. */
  /* Initialize function input argument 'rL'. */
  rL = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'e'. */
  e = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'g'. */
  g = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'robotConBranch'. */
  robotConBranch = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'robotJoints'. */
  robotJoints = argInit_1xUnbounded_struct0_T();
  /* Call the entry-point 'DiffKinematics_C'. */
  emxInitArray_cell_wrap_1(&Bij, 2);
  emxInitArray_cell_wrap_1(&Bi0, 1);
  emxInitArray_real_T(&pm, 2);
  argInit_3x3_real_T(dv);
  argInit_3x1_real_T(dv1);
  DiffKinematics_C(dv, dv1, rL, e, g, argInit_real_T(), robotConBranch,
                   robotJoints, Bij, Bi0, P0, pm);
  emxDestroyArray_struct0_T(robotJoints);
  emxDestroyArray_real_T(robotConBranch);
  emxDestroyArray_real_T(g);
  emxDestroyArray_real_T(e);
  emxDestroyArray_real_T(rL);
  emxDestroyArray_cell_wrap_1(Bij);
  emxDestroyArray_cell_wrap_1(Bi0);
  emxDestroyArray_real_T(pm);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_FD_C(void)
{
  emxArray_cell_wrap_1 *Bi0;
  emxArray_cell_wrap_1 *Bij;
  emxArray_cell_wrap_2 *Im;
  emxArray_real_T *b_tm;
  emxArray_real_T *pm;
  emxArray_real_T *robotConChild;
  emxArray_real_T *robotConChildBase;
  emxArray_real_T *taum;
  emxArray_real_T *um;
  emxArray_real_T *umdot;
  emxArray_real_T *wFm;
  emxArray_struct0_T *robotJoints;
  emxArray_struct1_T *robotLinks;
  struct2_T r;
  double dv[36];
  double dv1[9];
  double tau0_tmp[6];
  double u0dot[6];
  double nLinksJoints_tmp;
  /* Initialize function 'FD_C' input arguments. */
  /* Initialize function input argument 'tau0'. */
  argInit_6x1_real_T(tau0_tmp);
  /* Initialize function input argument 'taum'. */
  taum = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'wF0'. */
  /* Initialize function input argument 'wFm'. */
  wFm = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 't0'. */
  /* Initialize function input argument 'tm'. */
  b_tm = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 'P0'. */
  /* Initialize function input argument 'pm'. */
  pm = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 'I0'. */
  /* Initialize function input argument 'Im'. */
  Im = argInit_1xUnbounded_cell_wrap_2();
  /* Initialize function input argument 'Bij'. */
  Bij = c_argInit_UnboundedxUnbounded_c();
  /* Initialize function input argument 'Bi0'. */
  Bi0 = argInit_Unboundedx1_cell_wrap_1();
  /* Initialize function input argument 'u0'. */
  /* Initialize function input argument 'um'. */
  um = argInit_Unboundedx1_real_T();
  nLinksJoints_tmp = argInit_real_T();
  /* Initialize function input argument 'robotBaseLink'. */
  /* Initialize function input argument 'robotLinks'. */
  robotLinks = argInit_1xUnbounded_struct1_T();
  /* Initialize function input argument 'robotConChild'. */
  robotConChild = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'robotConChildBase'. */
  robotConChildBase = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'robotJoints'. */
  robotJoints = argInit_1xUnbounded_struct0_T();
  /* Call the entry-point 'FD_C'. */
  emxInitArray_real_T(&umdot, 1);
  argInit_6x6_real_T(dv);
  argInit_3x3_real_T(dv1);
  argInit_struct2_T(&r);
  FD_C(tau0_tmp, taum, tau0_tmp, wFm, tau0_tmp, b_tm, dv, pm, dv1, Im, Bij, Bi0,
       tau0_tmp, um, nLinksJoints_tmp, nLinksJoints_tmp, &r, robotLinks,
       robotConChild, robotConChildBase, robotJoints, u0dot, umdot);
  emxDestroyArray_struct0_T(robotJoints);
  emxDestroyArray_real_T(robotConChildBase);
  emxDestroyArray_real_T(robotConChild);
  emxDestroyArray_struct1_T(robotLinks);
  emxDestroyArray_real_T(um);
  emxDestroyArray_cell_wrap_1(Bi0);
  emxDestroyArray_cell_wrap_1(Bij);
  emxDestroyArray_cell_wrap_2(Im);
  emxDestroyArray_real_T(pm);
  emxDestroyArray_real_T(b_tm);
  emxDestroyArray_real_T(wFm);
  emxDestroyArray_real_T(taum);
  emxDestroyArray_real_T(umdot);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_ID_C(void)
{
  emxArray_cell_wrap_1 *Bi0;
  emxArray_cell_wrap_1 *Bij;
  emxArray_cell_wrap_2 *Im;
  emxArray_real_T *pm;
  emxArray_real_T *robotConChild;
  emxArray_real_T *robotConChildBase;
  emxArray_real_T *tL;
  emxArray_real_T *tLdot;
  emxArray_real_T *taum;
  emxArray_real_T *wFm;
  emxArray_struct0_T *robotJoints;
  emxArray_struct1_T *robotLinks;
  struct2_T r;
  double dv[36];
  double dv1[9];
  double tau0[6];
  double wF0_tmp[6];
  double nLinksJoints_tmp;
  /* Initialize function 'ID_C' input arguments. */
  /* Initialize function input argument 'wF0'. */
  argInit_6x1_real_T(wF0_tmp);
  /* Initialize function input argument 'wFm'. */
  wFm = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 't0'. */
  /* Initialize function input argument 'tL'. */
  tL = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 't0dot'. */
  /* Initialize function input argument 'tLdot'. */
  tLdot = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 'P0'. */
  /* Initialize function input argument 'pm'. */
  pm = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 'I0'. */
  /* Initialize function input argument 'Im'. */
  Im = argInit_1xUnbounded_cell_wrap_2();
  /* Initialize function input argument 'Bij'. */
  Bij = c_argInit_UnboundedxUnbounded_c();
  /* Initialize function input argument 'Bi0'. */
  Bi0 = argInit_Unboundedx1_cell_wrap_1();
  nLinksJoints_tmp = argInit_real_T();
  /* Initialize function input argument 'robotBaseLink'. */
  /* Initialize function input argument 'robotLinks'. */
  robotLinks = argInit_1xUnbounded_struct1_T();
  /* Initialize function input argument 'robotConChild'. */
  robotConChild = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'robotConChildBase'. */
  robotConChildBase = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'robotJoints'. */
  robotJoints = argInit_1xUnbounded_struct0_T();
  /* Call the entry-point 'ID_C'. */
  emxInitArray_real_T(&taum, 1);
  argInit_6x6_real_T(dv);
  argInit_3x3_real_T(dv1);
  argInit_struct2_T(&r);
  ID_C(wF0_tmp, wFm, wF0_tmp, tL, wF0_tmp, tLdot, dv, pm, dv1, Im, Bij, Bi0,
       nLinksJoints_tmp, nLinksJoints_tmp, &r, robotLinks, robotConChild,
       robotConChildBase, robotJoints, tau0, taum);
  emxDestroyArray_struct0_T(robotJoints);
  emxDestroyArray_real_T(robotConChildBase);
  emxDestroyArray_real_T(robotConChild);
  emxDestroyArray_struct1_T(robotLinks);
  emxDestroyArray_cell_wrap_1(Bi0);
  emxDestroyArray_cell_wrap_1(Bij);
  emxDestroyArray_cell_wrap_2(Im);
  emxDestroyArray_real_T(pm);
  emxDestroyArray_real_T(tLdot);
  emxDestroyArray_real_T(tL);
  emxDestroyArray_real_T(wFm);
  emxDestroyArray_real_T(taum);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_I_I_C(void)
{
  emxArray_cell_wrap_2 *Im;
  emxArray_real_T *RL;
  emxArray_struct1_T *robotLinks;
  double I0[9];
  double R0_tmp[9];
  /* Initialize function 'I_I_C' input arguments. */
  /* Initialize function input argument 'R0'. */
  argInit_3x3_real_T(R0_tmp);
  /* Initialize function input argument 'RL'. */
  RL = argInit_3xUnbounded_real_T();
  /* Initialize function input argument 'robotBaseInertia'. */
  /* Initialize function input argument 'robotLinks'. */
  robotLinks = argInit_1xUnbounded_struct1_T();
  /* Call the entry-point 'I_I_C'. */
  emxInitArray_cell_wrap_2(&Im, 2);
  I_I_C(R0_tmp, RL, argInit_real_T(), R0_tmp, robotLinks, I0, Im);
  emxDestroyArray_struct1_T(robotLinks);
  emxDestroyArray_real_T(RL);
  emxDestroyArray_cell_wrap_2(Im);
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
 * Arguments    : void
 * Return Type  : void
 */
void main_Velocities_C(void)
{
  emxArray_cell_wrap_1 *Bi0;
  emxArray_cell_wrap_1 *Bij;
  emxArray_real_T *pm;
  emxArray_real_T *tL;
  emxArray_real_T *um;
  emxArray_struct0_T *robotJoints;
  double dv[36];
  double dv1[6];
  double t0[6];
  /* Initialize function 'Velocities_C' input arguments. */
  /* Initialize function input argument 'Bij'. */
  Bij = c_argInit_UnboundedxUnbounded_c();
  /* Initialize function input argument 'Bi0'. */
  Bi0 = argInit_Unboundedx1_cell_wrap_1();
  /* Initialize function input argument 'P0'. */
  /* Initialize function input argument 'pm'. */
  pm = argInit_6xUnbounded_real_T();
  /* Initialize function input argument 'u0'. */
  /* Initialize function input argument 'um'. */
  um = argInit_Unboundedx1_real_T();
  /* Initialize function input argument 'robotJoints'. */
  robotJoints = argInit_1xUnbounded_struct0_T();
  /* Call the entry-point 'Velocities_C'. */
  emxInitArray_real_T(&tL, 2);
  argInit_6x6_real_T(dv);
  argInit_6x1_real_T(dv1);
  Velocities_C(Bij, Bi0, dv, pm, dv1, um, argInit_real_T(), robotJoints, t0,
               tL);
  emxDestroyArray_struct0_T(robotJoints);
  emxDestroyArray_real_T(um);
  emxDestroyArray_real_T(pm);
  emxDestroyArray_cell_wrap_1(Bi0);
  emxDestroyArray_cell_wrap_1(Bij);
  emxDestroyArray_real_T(tL);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
