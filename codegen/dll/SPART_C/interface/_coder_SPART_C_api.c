/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_SPART_C_api.c
 *
 * MATLAB Coder version            : 25.1
 * C/C++ source code generated on  : 24-Feb-2026 15:36:29
 */

/* Include Files */
#include "_coder_SPART_C_api.h"
#include "_coder_SPART_C_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131674U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "SPART_C",                                            /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[36];

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9];

static const mxArray *b_emlrt_marshallOut(const emxArray_cell_wrap_1 *u);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier, emxArray_real_T *y);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[3];

static const mxArray *c_emlrt_marshallOut(const real_T u[36]);

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_real_T *y);

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static const mxArray *d_emlrt_marshallOut(const emxArray_cell_wrap_1 *u);

static real_T (*db_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier))[6];

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y);

static const mxArray *e_emlrt_marshallOut(real_T u[36]);

static real_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[6];

static void emlrtExitTimeCleanupDtorFcn(const void *r);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[9];

static const mxArray *emlrt_marshallOut(emxArray_real_T *u);

static void emxEnsureCapacity_cell_wrap_1(emxArray_cell_wrap_1 *emxArray,
                                          int32_T oldNumel);

static void emxEnsureCapacity_cell_wrap_2(emxArray_cell_wrap_2 *emxArray,
                                          int32_T oldNumel);

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel);

static void emxEnsureCapacity_struct0_T(emxArray_struct0_T *emxArray,
                                        int32_T oldNumel);

static void emxEnsureCapacity_struct1_T(emxArray_struct1_T *emxArray,
                                        int32_T oldNumel);

static void emxFree_cell_wrap_1(const emlrtStack *sp,
                                emxArray_cell_wrap_1 **pEmxArray);

static void emxFree_cell_wrap_2(const emlrtStack *sp,
                                emxArray_cell_wrap_2 **pEmxArray);

static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

static void emxFree_struct0_T(const emlrtStack *sp,
                              emxArray_struct0_T **pEmxArray);

static void emxFree_struct1_T(const emlrtStack *sp,
                              emxArray_struct1_T **pEmxArray);

static void emxInit_cell_wrap_1(const emlrtStack *sp,
                                emxArray_cell_wrap_1 **pEmxArray,
                                int32_T numDimensions);

static void emxInit_cell_wrap_2(const emlrtStack *sp,
                                emxArray_cell_wrap_2 **pEmxArray);

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions);

static void emxInit_struct0_T(const emlrtStack *sp,
                              emxArray_struct0_T **pEmxArray);

static void emxInit_struct1_T(const emlrtStack *sp,
                              emxArray_struct1_T **pEmxArray);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *f_emlrt_marshallOut(real_T u[6]);

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier,
                                emxArray_cell_wrap_2 *y);

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier);

static const mxArray *g_emlrt_marshallOut(real_T u[9]);

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_2 *y);

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *h_emlrt_marshallOut(const emxArray_cell_wrap_2 *u);

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier, struct2_T *y);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_struct0_T *y);

static const mxArray *i_emlrt_marshallOut(emxArray_real_T *u);

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct2_T *y);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct0_T *y);

static uint64_T jb_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static uint64_T kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[16]);

static real_T (*lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[9];

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_struct1_T *y);

static real_T (*mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[3];

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct1_T *y);

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9]);

static real_T ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y);

static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3]);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[16]);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y);

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[9]);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier,
                               emxArray_cell_wrap_1 *y);

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_1 *y);

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[36]);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[36]);

static real_T (*vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[36];

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier,
                               emxArray_cell_wrap_1 *y);

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_1 *y);

static real_T (*xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[6];

static real_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[36];

static uint64_T yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[36]
 */
static real_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[36]
{
  real_T(*y)[36];
  y = vb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[9]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9]
{
  real_T(*y)[9];
  y = lb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emxArray_cell_wrap_1 *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const emxArray_cell_wrap_1 *u)
{
  const cell_wrap_1 *u_data;
  const mxArray *y;
  int32_T i;
  int32_T n;
  u_data = u->data;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &u->size[0]));
  i = 0;
  n = u->size[0] * u->size[1];
  while (i < n) {
    emlrtSetCell(y, i, c_emlrt_marshallOut(u_data[i].f1));
    i++;
  }
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  cb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const real_T u[36]
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u[36])
{
  static const int32_T iv[2] = {6, 6};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 6; b_i++) {
    for (c_i = 0; c_i < 6; c_i++) {
      pData[i + c_i] = u[c_i + 6 * b_i];
    }
    i += 6;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_real_T *y)
{
  wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = mb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emxArray_cell_wrap_1 *u
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const emxArray_cell_wrap_1 *u)
{
  const cell_wrap_1 *u_data;
  const mxArray *y;
  int32_T i;
  u_data = u->data;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, &u->size[0]));
  for (i = 0; i < u->size[0]; i++) {
    emlrtSetCell(y, i, c_emlrt_marshallOut(u_data[i].f1));
  }
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real_T (*)[6]
 */
static real_T (*db_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier))[6]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[6];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = eb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : real_T u[36]
 * Return Type  : const mxArray *
 */
static const mxArray *e_emlrt_marshallOut(real_T u[36])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {6, 6};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[6]
 */
static real_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[6]
{
  real_T(*y)[6];
  y = xb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const void *r
 * Return Type  : void
 */
static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real_T (*)[9]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[9]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[9];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(emxArray_real_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  u->canFreeData = false;
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : emxArray_cell_wrap_1 *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_cell_wrap_1(emxArray_cell_wrap_1 *emxArray,
                                          int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int32_T newCapacity;
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
    newData = emlrtMallocMex((uint32_T)newCapacity * sizeof(cell_wrap_1));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_1) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_1 *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_2 *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_cell_wrap_2(emxArray_cell_wrap_2 *emxArray,
                                          int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int32_T newCapacity;
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
    newData = emlrtMallocMex((uint32_T)newCapacity * sizeof(cell_wrap_2));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_2) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_2 *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int32_T newCapacity;
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
    newData = emlrtMallocMex((uint32_T)newCapacity * sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_struct0_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_struct0_T(emxArray_struct0_T *emxArray,
                                        int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int32_T newCapacity;
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
    newData = emlrtMallocMex((uint32_T)newCapacity * sizeof(struct0_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(struct0_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (struct0_T *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_struct1_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_struct1_T(emxArray_struct1_T *emxArray,
                                        int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    int32_T newCapacity;
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
    newData = emlrtMallocMex((uint32_T)newCapacity * sizeof(struct1_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(struct1_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (struct1_T *)newData;
    emxArray->allocatedSize = newCapacity;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_cell_wrap_1 **pEmxArray
 * Return Type  : void
 */
static void emxFree_cell_wrap_1(const emlrtStack *sp,
                                emxArray_cell_wrap_1 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_1 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_1 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_1 *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_cell_wrap_2 **pEmxArray
 * Return Type  : void
 */
static void emxFree_cell_wrap_2(const emlrtStack *sp,
                                emxArray_cell_wrap_2 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_2 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_2 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_2 *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct0_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_struct0_T(const emlrtStack *sp,
                              emxArray_struct0_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct0_T *)NULL) {
    if (((*pEmxArray)->data != (struct0_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_struct0_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct1_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_struct1_T(const emlrtStack *sp,
                              emxArray_struct1_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct1_T *)NULL) {
    if (((*pEmxArray)->data != (struct1_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_struct1_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_cell_wrap_1 **pEmxArray
 *                int32_T numDimensions
 * Return Type  : void
 */
static void emxInit_cell_wrap_1(const emlrtStack *sp,
                                emxArray_cell_wrap_1 **pEmxArray,
                                int32_T numDimensions)
{
  emxArray_cell_wrap_1 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_1 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_1));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_1, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_1 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size =
      (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_cell_wrap_2 **pEmxArray
 * Return Type  : void
 */
static void emxInit_cell_wrap_2(const emlrtStack *sp,
                                emxArray_cell_wrap_2 **pEmxArray)
{
  emxArray_cell_wrap_2 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_2 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_2));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_2, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_2 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size =
      (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct0_T **pEmxArray
 * Return Type  : void
 */
static void emxInit_struct0_T(const emlrtStack *sp,
                              emxArray_struct0_T **pEmxArray)
{
  emxArray_struct0_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_struct0_T *)emlrtMallocEmxArray(sizeof(emxArray_struct0_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_struct0_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (struct0_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct1_T **pEmxArray
 * Return Type  : void
 */
static void emxInit_struct1_T(const emlrtStack *sp,
                              emxArray_struct1_T **pEmxArray)
{
  emxArray_struct1_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_struct1_T *)emlrtMallocEmxArray(sizeof(emxArray_struct1_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_struct1_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (struct1_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  nb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : real_T u[6]
 * Return Type  : const mxArray *
 */
static const mxArray *f_emlrt_marshallOut(real_T u[6])
{
  static const int32_T i = 0;
  static const int32_T i1 = 6;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_cell_wrap_2 *y
 * Return Type  : void
 */
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier,
                                emxArray_cell_wrap_2 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  gb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : real_T u[9]
 * Return Type  : const mxArray *
 */
static const mxArray *g_emlrt_marshallOut(real_T u[9])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {3, 3};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_cell_wrap_2 *y
 * Return Type  : void
 */
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                emxArray_cell_wrap_2 *y)
{
  static const boolean_T bv[2] = {false, true};
  cell_wrap_2 *y_data;
  emlrtMsgIdentifier thisId;
  real_T dv[9];
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv[0] = 1;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_2(y, i);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    emlrtMexSnprintf(&str[0], (size_t)11U, "%d", i + 1);
    thisId.fIdentifier = &str[0];
    o_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, dv);
    memcpy(&y_data[i].f1[0], &dv[0], 9U * sizeof(real_T));
  }
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = ob_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emxArray_cell_wrap_2 *u
 * Return Type  : const mxArray *
 */
static const mxArray *h_emlrt_marshallOut(const emxArray_cell_wrap_2 *u)
{
  static const int32_T iv[2] = {3, 3};
  const cell_wrap_2 *u_data;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T i;
  u_data = u->data;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &u->size[0]));
  for (i = 0; i < u->size[1]; i++) {
    int32_T i1;
    b_y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    i1 = 0;
    for (b_i = 0; b_i < 3; b_i++) {
      pData[i1] = u_data[i].f1[3 * b_i];
      pData[i1 + 1] = u_data[i].f1[3 * b_i + 1];
      pData[i1 + 2] = u_data[i].f1[3 * b_i + 2];
      i1 += 3;
    }
    emlrtAssign(&b_y, m);
    emlrtSetCell(y, i, b_y);
  }
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                struct2_T *y
 * Return Type  : void
 */
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  ib_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_struct0_T *y
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *i_emlrt_marshallOut(emxArray_real_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  u->canFreeData = false;
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct2_T *y
 * Return Type  : void
 */
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                struct2_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[2] = {"mass", "inertia"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 2,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "mass";
  y->mass = h_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "mass")),
      &thisId);
  thisId.fIdentifier = "inertia";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "inertia")),
      &thisId, y->inertia);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_struct0_T *y
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct0_T *y)
{
  static const int32_T dims[2] = {1, -1};
  static const char_T *fieldNames[7] = {
      "id", "type", "q_id", "parent_link", "child_link", "axis", "T"};
  emlrtMsgIdentifier thisId;
  struct0_T *y_data;
  real_T dv1[16];
  int32_T sizes[2];
  int32_T i;
  boolean_T bv[2] = {false, true};
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckVsStructR2012b((emlrtCTX)sp, parentId, u, 7,
                           (const char_T **)&fieldNames[0], 2U,
                           (const void *)&dims[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct0_T(y, i);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    real_T dv[3];
    thisId.fIdentifier = "id";
    y_data[i].id = h_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 0, "id")),
        &thisId);
    thisId.fIdentifier = "type";
    y_data[i].type = h_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 1, "type")),
        &thisId);
    thisId.fIdentifier = "q_id";
    y_data[i].q_id = h_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 2, "q_id")),
        &thisId);
    thisId.fIdentifier = "parent_link";
    y_data[i].parent_link =
        h_emlrt_marshallIn(sp,
                           emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u,
                                                          i, 3, "parent_link")),
                           &thisId);
    thisId.fIdentifier = "child_link";
    y_data[i].child_link =
        h_emlrt_marshallIn(sp,
                           emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u,
                                                          i, 4, "child_link")),
                           &thisId);
    thisId.fIdentifier = "axis";
    k_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 5, "axis")),
        &thisId, dv);
    y_data[i].axis[0] = dv[0];
    y_data[i].axis[1] = dv[1];
    y_data[i].axis[2] = dv[2];
    thisId.fIdentifier = "T";
    l_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 6, "T")),
        &thisId, dv1);
    memcpy(&y_data[i].T[0], &dv1[0], 16U * sizeof(real_T));
  }
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : uint64_T
 */
static uint64_T jb_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  uint64_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = kb_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[3]
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  pb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : uint64_T
 */
static uint64_T kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  uint64_T y;
  y = yb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[16]
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[16])
{
  qb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[9]
 */
static real_T (*lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[9]
{
  static const int32_T dims[2] = {3, 3};
  real_T(*ret)[9];
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_struct1_T *y
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[3]
 */
static real_T (*mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims = 3;
  real_T(*ret)[3];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_struct1_T *y
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct1_T *y)
{
  static const int32_T dims[2] = {1, -1};
  static const char_T *fieldNames[5] = {"id", "parent_joint", "T", "mass",
                                        "inertia"};
  emlrtMsgIdentifier thisId;
  struct1_T *y_data;
  real_T dv[16];
  real_T dv1[9];
  int32_T sizes[2];
  int32_T i;
  boolean_T bv[2] = {false, true};
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckVsStructR2012b((emlrtCTX)sp, parentId, u, 5,
                           (const char_T **)&fieldNames[0], 2U,
                           (const void *)&dims[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct1_T(y, i);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    thisId.fIdentifier = "id";
    y_data[i].id = h_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 0, "id")),
        &thisId);
    thisId.fIdentifier = "parent_joint";
    y_data[i].parent_joint =
        h_emlrt_marshallIn(sp,
                           emlrtAlias(emlrtGetFieldR2017b(
                               (emlrtConstCTX)sp, u, i, 1, "parent_joint")),
                           &thisId);
    thisId.fIdentifier = "T";
    l_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 2, "T")),
        &thisId, dv);
    memcpy(&y_data[i].T[0], &dv[0], 16U * sizeof(real_T));
    thisId.fIdentifier = "mass";
    y_data[i].mass = h_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 3, "mass")),
        &thisId);
    thisId.fIdentifier = "inertia";
    o_emlrt_marshallIn(
        sp,
        emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 4, "inertia")),
        &thisId, dv1);
    memcpy(&y_data[i].inertia[0], &dv1[0], 9U * sizeof(real_T));
  }
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  int32_T i;
  int32_T i1;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret->allocatedSize = i;
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(ret, i1);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[9]
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9])
{
  rb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  q_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[3]
 * Return Type  : void
 */
static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims = 3;
  real_T(*r)[3];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  sb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[16]
 * Return Type  : void
 */
static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[16])
{
  static const int32_T dims[2] = {4, 4};
  real_T(*r)[16];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[16])emlrtMxGetData(src);
  for (i = 0; i < 16; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  s_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[9]
 * Return Type  : void
 */
static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = {3, 3};
  real_T(*r)[9];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[9])emlrtMxGetData(src);
  for (i = 0; i < 9; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {3, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_cell_wrap_1 *y
 * Return Type  : void
 */
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier,
                               emxArray_cell_wrap_1 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  u_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_cell_wrap_1 *y
 * Return Type  : void
 */
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_1 *y)
{
  cell_wrap_1 *y_data;
  emlrtMsgIdentifier thisId;
  real_T dv[36];
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  int32_T n;
  char_T str[11];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  bv[0] = true;
  iv[0] = -1;
  bv[1] = true;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  n = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_1(y, n);
  y_data = y->data;
  n = sizes[0] * sizes[1];
  for (i = 0; i < n; i++) {
    emlrtMexSnprintf(&str[0], (size_t)11U, "%d", i + 1);
    thisId.fIdentifier = &str[0];
    v_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, dv);
    memcpy(&y_data[i].f1[0], &dv[0], 36U * sizeof(real_T));
  }
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[36]
 * Return Type  : void
 */
static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[36])
{
  static const int32_T dims[2] = {6, 6};
  real_T(*r)[36];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[36])emlrtMxGetData(src);
  for (i = 0; i < 36; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[36]
 * Return Type  : void
 */
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[36])
{
  ub_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[36]
 */
static real_T (*vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[36]
{
  static const int32_T dims[2] = {6, 6};
  real_T(*ret)[36];
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[36])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 *                emxArray_cell_wrap_1 *y
 * Return Type  : void
 */
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier,
                               emxArray_cell_wrap_1 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  x_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {6, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_cell_wrap_1 *y
 * Return Type  : void
 */
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_1 *y)
{
  cell_wrap_1 *y_data;
  emlrtMsgIdentifier thisId;
  real_T dv[36];
  int32_T i;
  int32_T sizes;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = true;
  i = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 1U, &i, &b, &sizes);
  i = y->size[0];
  y->size[0] = sizes;
  emxEnsureCapacity_cell_wrap_1(y, i);
  y_data = y->data;
  for (i = 0; i < sizes; i++) {
    emlrtMexSnprintf(&str[0], (size_t)11U, "%d", i + 1);
    thisId.fIdentifier = &str[0];
    v_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, dv);
    memcpy(&y_data[i].f1[0], &dv[0], 36U * sizeof(real_T));
  }
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[6]
 */
static real_T (*xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[6]
{
  static const int32_T dims = 6;
  real_T(*ret)[6];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[6])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real_T (*)[36]
 */
static real_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[36]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[36];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = ab_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : uint64_T
 */
static uint64_T yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  uint64_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint64", false, 0U,
                          (const void *)&dims);
  ret = *(uint64_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[12]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void Accelerations_C_api(const mxArray *const prhs[12], int32_T nlhs,
                         const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_cell_wrap_1 *Bi0;
  emxArray_cell_wrap_1 *Bij;
  emxArray_real_T *pm;
  emxArray_real_T *tL;
  emxArray_real_T *tLdot;
  emxArray_real_T *um;
  emxArray_real_T *umdot;
  emxArray_struct0_T *robotJoints;
  real_T(*P0)[36];
  real_T(*t0)[6];
  real_T(*t0dot)[6];
  real_T(*u0)[6];
  real_T(*u0dot)[6];
  real_T nLinksJoints;
  st.tls = emlrtRootTLSGlobal;
  t0dot = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  t0 = db_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "t0");
  emxInit_real_T(&st, &tL, 2);
  tL->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "tL", tL);
  P0 = y_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "P0");
  emxInit_real_T(&st, &pm, 2);
  pm->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "pm", pm);
  emxInit_cell_wrap_1(&st, &Bi0, 1);
  w_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "Bi0", Bi0);
  emxInit_cell_wrap_1(&st, &Bij, 2);
  t_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "Bij", Bij);
  u0 = db_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "u0");
  emxInit_real_T(&st, &um, 1);
  um->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "um", um);
  u0dot = db_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "u0dot");
  emxInit_real_T(&st, &umdot, 1);
  umdot->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "umdot", umdot);
  nLinksJoints = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "nLinksJoints");
  emxInit_struct0_T(&st, &robotJoints);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "robotJoints", robotJoints);
  /* Invoke the target function */
  emxInit_real_T(&st, &tLdot, 2);
  Accelerations_C(*t0, tL, *P0, pm, Bi0, Bij, *u0, um, *u0dot, umdot,
                  nLinksJoints, robotJoints, *t0dot, tLdot);
  emxFree_struct0_T(&st, &robotJoints);
  emxFree_real_T(&st, &umdot);
  emxFree_real_T(&st, &um);
  emxFree_cell_wrap_1(&st, &Bij);
  emxFree_cell_wrap_1(&st, &Bi0);
  emxFree_real_T(&st, &pm);
  emxFree_real_T(&st, &tL);
  /* Marshall function outputs */
  plhs[0] = f_emlrt_marshallOut(*t0dot);
  if (nlhs > 1) {
    tLdot->canFreeData = false;
    plhs[1] = emlrt_marshallOut(tLdot);
  }
  emxFree_real_T(&st, &tLdot);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[8]
 *                int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void DiffKinematics_C_api(const mxArray *const prhs[8], int32_T nlhs,
                          const mxArray *plhs[4])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_cell_wrap_1 *Bi0;
  emxArray_cell_wrap_1 *Bij;
  emxArray_real_T *e;
  emxArray_real_T *g;
  emxArray_real_T *pm;
  emxArray_real_T *rL;
  emxArray_real_T *robotConBranch;
  emxArray_struct0_T *robotJoints;
  real_T(*P0)[36];
  real_T(*R0)[9];
  real_T(*r0)[3];
  real_T nLinksJoints;
  st.tls = emlrtRootTLSGlobal;
  P0 = (real_T(*)[36])mxMalloc(sizeof(real_T[36]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  R0 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "R0");
  r0 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "r0");
  emxInit_real_T(&st, &rL, 2);
  rL->canFreeData = false;
  p_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "rL", rL);
  emxInit_real_T(&st, &e, 2);
  e->canFreeData = false;
  p_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "e", e);
  emxInit_real_T(&st, &g, 2);
  g->canFreeData = false;
  p_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "g", g);
  nLinksJoints = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "nLinksJoints");
  emxInit_real_T(&st, &robotConBranch, 2);
  robotConBranch->canFreeData = false;
  r_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "robotConBranch",
                     robotConBranch);
  emxInit_struct0_T(&st, &robotJoints);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "robotJoints", robotJoints);
  /* Invoke the target function */
  emxInit_cell_wrap_1(&st, &Bij, 2);
  emxInit_cell_wrap_1(&st, &Bi0, 1);
  emxInit_real_T(&st, &pm, 2);
  DiffKinematics_C(*R0, *r0, rL, e, g, nLinksJoints, robotConBranch,
                   robotJoints, Bij, Bi0, *P0, pm);
  emxFree_struct0_T(&st, &robotJoints);
  emxFree_real_T(&st, &robotConBranch);
  emxFree_real_T(&st, &g);
  emxFree_real_T(&st, &e);
  emxFree_real_T(&st, &rL);
  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(Bij);
  emxFree_cell_wrap_1(&st, &Bij);
  if (nlhs > 1) {
    plhs[1] = d_emlrt_marshallOut(Bi0);
  }
  emxFree_cell_wrap_1(&st, &Bi0);
  if (nlhs > 2) {
    plhs[2] = e_emlrt_marshallOut(*P0);
  }
  if (nlhs > 3) {
    pm->canFreeData = false;
    plhs[3] = emlrt_marshallOut(pm);
  }
  emxFree_real_T(&st, &pm);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[21]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void FD_C_api(const mxArray *const prhs[21], int32_T nlhs,
              const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
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
  struct2_T robotBaseLink;
  real_T(*P0)[36];
  real_T(*I0)[9];
  real_T(*t0)[6];
  real_T(*tau0)[6];
  real_T(*u0)[6];
  real_T(*u0dot)[6];
  real_T(*wF0)[6];
  real_T nLinksJoints;
  real_T nQ;
  st.tls = emlrtRootTLSGlobal;
  u0dot = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  tau0 = db_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "tau0");
  emxInit_real_T(&st, &taum, 1);
  taum->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "taum", taum);
  wF0 = db_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "wF0");
  emxInit_real_T(&st, &wFm, 2);
  wFm->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "wFm", wFm);
  t0 = db_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "t0");
  emxInit_real_T(&st, &b_tm, 2);
  b_tm->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "tm", b_tm);
  P0 = y_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "P0");
  emxInit_real_T(&st, &pm, 2);
  pm->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "pm", pm);
  I0 = emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "I0");
  emxInit_cell_wrap_2(&st, &Im);
  fb_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "Im", Im);
  emxInit_cell_wrap_1(&st, &Bij, 2);
  t_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "Bij", Bij);
  emxInit_cell_wrap_1(&st, &Bi0, 1);
  w_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "Bi0", Bi0);
  u0 = db_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "u0");
  emxInit_real_T(&st, &um, 1);
  um->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "um", um);
  nLinksJoints = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "nLinksJoints");
  nQ = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "nQ");
  hb_emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "robotBaseLink",
                      &robotBaseLink);
  emxInit_struct1_T(&st, &robotLinks);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[17]), "robotLinks", robotLinks);
  emxInit_real_T(&st, &robotConChild, 2);
  robotConChild->canFreeData = false;
  r_emlrt_marshallIn(&st, emlrtAlias(prhs[18]), "robotConChild", robotConChild);
  emxInit_real_T(&st, &robotConChildBase, 1);
  robotConChildBase->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[19]), "robotConChildBase",
                     robotConChildBase);
  emxInit_struct0_T(&st, &robotJoints);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[20]), "robotJoints", robotJoints);
  /* Invoke the target function */
  emxInit_real_T(&st, &umdot, 1);
  FD_C(*tau0, taum, *wF0, wFm, *t0, b_tm, *P0, pm, *I0, Im, Bij, Bi0, *u0, um,
       nLinksJoints, nQ, &robotBaseLink, robotLinks, robotConChild,
       robotConChildBase, robotJoints, *u0dot, umdot);
  emxFree_struct0_T(&st, &robotJoints);
  emxFree_real_T(&st, &robotConChildBase);
  emxFree_real_T(&st, &robotConChild);
  emxFree_struct1_T(&st, &robotLinks);
  emxFree_real_T(&st, &um);
  emxFree_cell_wrap_1(&st, &Bi0);
  emxFree_cell_wrap_1(&st, &Bij);
  emxFree_cell_wrap_2(&st, &Im);
  emxFree_real_T(&st, &pm);
  emxFree_real_T(&st, &b_tm);
  emxFree_real_T(&st, &wFm);
  emxFree_real_T(&st, &taum);
  /* Marshall function outputs */
  plhs[0] = f_emlrt_marshallOut(*u0dot);
  if (nlhs > 1) {
    umdot->canFreeData = false;
    plhs[1] = i_emlrt_marshallOut(umdot);
  }
  emxFree_real_T(&st, &umdot);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[19]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void ID_C_api(const mxArray *const prhs[19], int32_T nlhs,
              const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
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
  struct2_T robotBaseLink;
  real_T(*P0)[36];
  real_T(*I0)[9];
  real_T(*t0)[6];
  real_T(*t0dot)[6];
  real_T(*tau0)[6];
  real_T(*wF0)[6];
  real_T nLinksJoints;
  real_T nQ;
  st.tls = emlrtRootTLSGlobal;
  tau0 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  wF0 = db_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "wF0");
  emxInit_real_T(&st, &wFm, 2);
  wFm->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "wFm", wFm);
  t0 = db_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "t0");
  emxInit_real_T(&st, &tL, 2);
  tL->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "tL", tL);
  t0dot = db_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "t0dot");
  emxInit_real_T(&st, &tLdot, 2);
  tLdot->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "tLdot", tLdot);
  P0 = y_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "P0");
  emxInit_real_T(&st, &pm, 2);
  pm->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "pm", pm);
  I0 = emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "I0");
  emxInit_cell_wrap_2(&st, &Im);
  fb_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "Im", Im);
  emxInit_cell_wrap_1(&st, &Bij, 2);
  t_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "Bij", Bij);
  emxInit_cell_wrap_1(&st, &Bi0, 1);
  w_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "Bi0", Bi0);
  nLinksJoints = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "nLinksJoints");
  nQ = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "nQ");
  hb_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "robotBaseLink",
                      &robotBaseLink);
  emxInit_struct1_T(&st, &robotLinks);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "robotLinks", robotLinks);
  emxInit_real_T(&st, &robotConChild, 2);
  robotConChild->canFreeData = false;
  r_emlrt_marshallIn(&st, emlrtAlias(prhs[16]), "robotConChild", robotConChild);
  emxInit_real_T(&st, &robotConChildBase, 1);
  robotConChildBase->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[17]), "robotConChildBase",
                     robotConChildBase);
  emxInit_struct0_T(&st, &robotJoints);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[18]), "robotJoints", robotJoints);
  /* Invoke the target function */
  emxInit_real_T(&st, &taum, 1);
  ID_C(*wF0, wFm, *t0, tL, *t0dot, tLdot, *P0, pm, *I0, Im, Bij, Bi0,
       nLinksJoints, nQ, &robotBaseLink, robotLinks, robotConChild,
       robotConChildBase, robotJoints, *tau0, taum);
  emxFree_struct0_T(&st, &robotJoints);
  emxFree_real_T(&st, &robotConChildBase);
  emxFree_real_T(&st, &robotConChild);
  emxFree_struct1_T(&st, &robotLinks);
  emxFree_cell_wrap_1(&st, &Bi0);
  emxFree_cell_wrap_1(&st, &Bij);
  emxFree_cell_wrap_2(&st, &Im);
  emxFree_real_T(&st, &pm);
  emxFree_real_T(&st, &tLdot);
  emxFree_real_T(&st, &tL);
  emxFree_real_T(&st, &wFm);
  /* Marshall function outputs */
  plhs[0] = f_emlrt_marshallOut(*tau0);
  if (nlhs > 1) {
    taum->canFreeData = false;
    plhs[1] = i_emlrt_marshallOut(taum);
  }
  emxFree_real_T(&st, &taum);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void I_I_C_api(const mxArray *const prhs[5], int32_T nlhs,
               const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_cell_wrap_2 *Im;
  emxArray_real_T *RL;
  emxArray_struct1_T *robotLinks;
  real_T(*I0)[9];
  real_T(*R0)[9];
  real_T(*robotBaseInertia)[9];
  real_T nLinksJoints;
  st.tls = emlrtRootTLSGlobal;
  I0 = (real_T(*)[9])mxMalloc(sizeof(real_T[9]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  R0 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "R0");
  emxInit_real_T(&st, &RL, 2);
  RL->canFreeData = false;
  p_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "RL", RL);
  nLinksJoints = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "nLinksJoints");
  robotBaseInertia =
      emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "robotBaseInertia");
  emxInit_struct1_T(&st, &robotLinks);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "robotLinks", robotLinks);
  /* Invoke the target function */
  emxInit_cell_wrap_2(&st, &Im);
  I_I_C(*R0, RL, nLinksJoints, *robotBaseInertia, robotLinks, *I0, Im);
  emxFree_struct1_T(&st, &robotLinks);
  emxFree_real_T(&st, &RL);
  /* Marshall function outputs */
  plhs[0] = g_emlrt_marshallOut(*I0);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(Im);
  }
  emxFree_cell_wrap_2(&st, &Im);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[6]
 *                int32_T nlhs
 *                const mxArray *plhs[6]
 * Return Type  : void
 */
void Kinematics_C_api(const mxArray *const prhs[6], int32_T nlhs,
                      const mxArray *plhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *RJ;
  emxArray_real_T *RL;
  emxArray_real_T *e;
  emxArray_real_T *g;
  emxArray_real_T *qm;
  emxArray_real_T *rJ;
  emxArray_real_T *rL;
  emxArray_struct0_T *robotJoints;
  emxArray_struct1_T *robotLinks;
  real_T(*R0)[9];
  real_T(*r0)[3];
  real_T nLinksJoints;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  R0 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "R0");
  r0 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "r0");
  emxInit_real_T(&st, &qm, 1);
  qm->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "qm", qm);
  nLinksJoints = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "nLinksJoints");
  emxInit_struct0_T(&st, &robotJoints);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "robotJoints", robotJoints);
  emxInit_struct1_T(&st, &robotLinks);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "robotLinks", robotLinks);
  /* Invoke the target function */
  emxInit_real_T(&st, &RJ, 2);
  emxInit_real_T(&st, &RL, 2);
  emxInit_real_T(&st, &rJ, 2);
  emxInit_real_T(&st, &rL, 2);
  emxInit_real_T(&st, &e, 2);
  emxInit_real_T(&st, &g, 2);
  Kinematics_C(*R0, *r0, qm, nLinksJoints, robotJoints, robotLinks, RJ, RL, rJ,
               rL, e, g);
  emxFree_struct1_T(&st, &robotLinks);
  emxFree_struct0_T(&st, &robotJoints);
  emxFree_real_T(&st, &qm);
  /* Marshall function outputs */
  RJ->canFreeData = false;
  plhs[0] = emlrt_marshallOut(RJ);
  emxFree_real_T(&st, &RJ);
  if (nlhs > 1) {
    RL->canFreeData = false;
    plhs[1] = emlrt_marshallOut(RL);
  }
  emxFree_real_T(&st, &RL);
  if (nlhs > 2) {
    rJ->canFreeData = false;
    plhs[2] = emlrt_marshallOut(rJ);
  }
  emxFree_real_T(&st, &rJ);
  if (nlhs > 3) {
    rL->canFreeData = false;
    plhs[3] = emlrt_marshallOut(rL);
  }
  emxFree_real_T(&st, &rL);
  if (nlhs > 4) {
    e->canFreeData = false;
    plhs[4] = emlrt_marshallOut(e);
  }
  emxFree_real_T(&st, &e);
  if (nlhs > 5) {
    g->canFreeData = false;
    plhs[5] = emlrt_marshallOut(g);
  }
  emxFree_real_T(&st, &g);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void SPART_C_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(
      &st, false, NULL, (void *)&emlrtExitTimeCleanupDtorFcn, NULL, NULL, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  SPART_C_xil_terminate();
  SPART_C_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void SPART_C_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void SPART_C_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[12]
 *                const mxArray **plhs
 * Return Type  : void
 */
void SPART_SPACEROBOT_ODE_C_api(const mxArray *const prhs[12],
                                const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *dydt;
  emxArray_real_T *robotConBranch;
  emxArray_real_T *robotConChild;
  emxArray_real_T *robotConChildBase;
  emxArray_real_T *tau;
  emxArray_real_T *y;
  emxArray_struct0_T *robotJoints;
  emxArray_struct1_T *robotLinks;
  struct2_T robotBaseLink;
  real_T(*robotBaseInertia)[9];
  real_T nLinksJoints;
  real_T nQ;
  uint64_T t;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  t = jb_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  emxInit_real_T(&st, &y, 1);
  y->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "y", y);
  emxInit_real_T(&st, &tau, 1);
  tau->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "tau", tau);
  nLinksJoints = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "nLinksJoints");
  emxInit_struct0_T(&st, &robotJoints);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "robotJoints", robotJoints);
  emxInit_struct1_T(&st, &robotLinks);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "robotLinks", robotLinks);
  emxInit_real_T(&st, &robotConBranch, 2);
  robotConBranch->canFreeData = false;
  r_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "robotConBranch",
                     robotConBranch);
  robotBaseInertia =
      emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "robotBaseInertia");
  nQ = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "nQ");
  hb_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "robotBaseLink",
                      &robotBaseLink);
  emxInit_real_T(&st, &robotConChild, 2);
  robotConChild->canFreeData = false;
  r_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "robotConChild", robotConChild);
  emxInit_real_T(&st, &robotConChildBase, 1);
  robotConChildBase->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "robotConChildBase",
                     robotConChildBase);
  /* Invoke the target function */
  emxInit_real_T(&st, &dydt, 1);
  SPART_SPACEROBOT_ODE_C(t, y, tau, nLinksJoints, robotJoints, robotLinks,
                         robotConBranch, *robotBaseInertia, nQ, &robotBaseLink,
                         robotConChild, robotConChildBase, dydt);
  emxFree_real_T(&st, &robotConChildBase);
  emxFree_real_T(&st, &robotConChild);
  emxFree_real_T(&st, &robotConBranch);
  emxFree_struct1_T(&st, &robotLinks);
  emxFree_struct0_T(&st, &robotJoints);
  emxFree_real_T(&st, &tau);
  emxFree_real_T(&st, &y);
  /* Marshall function outputs */
  dydt->canFreeData = false;
  *plhs = i_emlrt_marshallOut(dydt);
  emxFree_real_T(&st, &dydt);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[8]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void Velocities_C_api(const mxArray *const prhs[8], int32_T nlhs,
                      const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_cell_wrap_1 *Bi0;
  emxArray_cell_wrap_1 *Bij;
  emxArray_real_T *pm;
  emxArray_real_T *tL;
  emxArray_real_T *um;
  emxArray_struct0_T *robotJoints;
  real_T(*P0)[36];
  real_T(*t0)[6];
  real_T(*u0)[6];
  real_T nLinksJoints;
  st.tls = emlrtRootTLSGlobal;
  t0 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emxInit_cell_wrap_1(&st, &Bij, 2);
  t_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "Bij", Bij);
  emxInit_cell_wrap_1(&st, &Bi0, 1);
  w_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Bi0", Bi0);
  P0 = y_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "P0");
  emxInit_real_T(&st, &pm, 2);
  pm->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "pm", pm);
  u0 = db_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "u0");
  emxInit_real_T(&st, &um, 1);
  um->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "um", um);
  nLinksJoints = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "nLinksJoints");
  emxInit_struct0_T(&st, &robotJoints);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "robotJoints", robotJoints);
  /* Invoke the target function */
  emxInit_real_T(&st, &tL, 2);
  Velocities_C(Bij, Bi0, *P0, pm, *u0, um, nLinksJoints, robotJoints, *t0, tL);
  emxFree_struct0_T(&st, &robotJoints);
  emxFree_real_T(&st, &um);
  emxFree_real_T(&st, &pm);
  emxFree_cell_wrap_1(&st, &Bi0);
  emxFree_cell_wrap_1(&st, &Bij);
  /* Marshall function outputs */
  plhs[0] = f_emlrt_marshallOut(*t0);
  if (nlhs > 1) {
    tL->canFreeData = false;
    plhs[1] = emlrt_marshallOut(tL);
  }
  emxFree_real_T(&st, &tL);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * File trailer for _coder_SPART_C_api.c
 *
 * [EOF]
 */
