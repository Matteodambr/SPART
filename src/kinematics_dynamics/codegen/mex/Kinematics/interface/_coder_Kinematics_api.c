/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_Kinematics_api.c
 *
 * Code generation for function '_coder_Kinematics_api'
 *
 */

/* Include files */
#include "_coder_Kinematics_api.h"
#include "Kinematics.h"
#include "Kinematics_data.h"
#include "Kinematics_emxutil.h"
#include "Kinematics_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = {
    1,                       /* lineNo */
    1,                       /* colNo */
    "_coder_Kinematics_api", /* fName */
    ""                       /* pName */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[9]);

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9];

static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3]);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[3];

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real_T *y);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[9];

static const mxArray *emlrt_marshallOut(emxArray_real_T *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y);

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct1_T *y);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[16]);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9]);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct2_T *y);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct3_T *y);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct4_T *y);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[9];

static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_char_T *ret);

static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[16]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9]
{
  real_T(*y)[9];
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u)
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

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  real_T *ret_data;
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims = -1;
  real_T *ret_data;
  int32_T i;
  int32_T i1;
  boolean_T b = true;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  i1 = ret->size[0];
  ret->size[0] = i;
  emxEnsureCapacity_real_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

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

static const mxArray *emlrt_marshallOut(emxArray_real_T *u)
{
  static const int32_T iv[3] = {0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(3, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 3);
  u->canFreeData = false;
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[7] = {
      "name", "n_q", "n_links_joints", "links", "joints", "base_link", "con"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "name";
  i_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "name")),
      &thisId, y->name);
  thisId.fIdentifier = "n_q";
  y->n_q = j_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "n_q")),
      &thisId);
  thisId.fIdentifier = "n_links_joints";
  y->n_links_joints =
      j_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        2, "n_links_joints")),
                         &thisId);
  thisId.fIdentifier = "links";
  k_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "links")),
      &thisId, y->links);
  thisId.fIdentifier = "joints";
  n_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "joints")),
      &thisId, y->joints);
  thisId.fIdentifier = "base_link";
  p_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "base_link")),
      &thisId, &y->base_link);
  thisId.fIdentifier = "con";
  q_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "con")),
      &thisId, &y->con);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y)
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct1_T *y)
{
  static const int32_T dims[2] = {1, -1};
  static const char_T *fieldNames[5] = {"id", "parent_joint", "T", "mass",
                                        "inertia"};
  emlrtMsgIdentifier thisId;
  struct1_T *y_data;
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
  emxEnsureCapacity_struct1_T(sp, y, i, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    thisId.fIdentifier = "id";
    y_data[i].id = j_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 0, "id")),
        &thisId);
    thisId.fIdentifier = "parent_joint";
    y_data[i].parent_joint =
        j_emlrt_marshallIn(sp,
                           emlrtAlias(emlrtGetFieldR2017b(
                               (emlrtConstCTX)sp, u, i, 1, "parent_joint")),
                           &thisId);
    thisId.fIdentifier = "T";
    l_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 2, "T")),
        &thisId, y_data[i].T);
    thisId.fIdentifier = "mass";
    y_data[i].mass = j_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 3, "mass")),
        &thisId);
    thisId.fIdentifier = "inertia";
    m_emlrt_marshallIn(
        sp,
        emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 4, "inertia")),
        &thisId, y_data[i].inertia);
  }
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[16])
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct2_T *y)
{
  static const int32_T dims[2] = {1, -1};
  static const char_T *fieldNames[7] = {
      "id", "type", "q_id", "parent_link", "child_link", "axis", "T"};
  emlrtMsgIdentifier thisId;
  struct2_T *y_data;
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
  emxEnsureCapacity_struct2_T(sp, y, i, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  for (i = 0; i < sizes[1]; i++) {
    thisId.fIdentifier = "id";
    y_data[i].id = j_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 0, "id")),
        &thisId);
    thisId.fIdentifier = "type";
    y_data[i].type = j_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 1, "type")),
        &thisId);
    thisId.fIdentifier = "q_id";
    y_data[i].q_id = j_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 2, "q_id")),
        &thisId);
    thisId.fIdentifier = "parent_link";
    y_data[i].parent_link =
        j_emlrt_marshallIn(sp,
                           emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u,
                                                          i, 3, "parent_link")),
                           &thisId);
    thisId.fIdentifier = "child_link";
    y_data[i].child_link =
        j_emlrt_marshallIn(sp,
                           emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u,
                                                          i, 4, "child_link")),
                           &thisId);
    thisId.fIdentifier = "axis";
    o_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 5, "axis")),
        &thisId, y_data[i].axis);
    thisId.fIdentifier = "T";
    l_emlrt_marshallIn(
        sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, i, 6, "T")),
        &thisId, y_data[i].T);
  }
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct3_T *y)
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
  y->mass = j_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "mass")),
      &thisId);
  thisId.fIdentifier = "inertia";
  m_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "inertia")),
      &thisId, y->inertia);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct4_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[3] = {"branch", "child", "child_base"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 3,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "branch";
  r_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "branch")),
      &thisId, y->branch);
  thisId.fIdentifier = "child";
  r_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "child")),
      &thisId, y->child);
  thisId.fIdentifier = "child_base";
  s_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "child_base")),
      &thisId, y->child_base);
  emlrtDestroyArray(&u);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
  emxEnsureCapacity_real_T(sp, ret, i1, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_char_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  char_T *ret_data;
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "char", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_char_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

void Kinematics_api(const mxArray *const prhs[4], int32_T nlhs,
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
  struct0_T robot;
  real_T(*R0)[9];
  real_T(*r0)[3];
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  R0 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "R0");
  r0 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "r0");
  emxInit_real_T(&st, &qm, 1, &l_emlrtRTEI);
  qm->canFreeData = false;
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "qm", qm);
  emxInitStruct_struct0_T(&st, &robot, &l_emlrtRTEI);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "robot", &robot);
  /* Invoke the target function */
  emxInit_real_T(&st, &RJ, 3, &l_emlrtRTEI);
  emxInit_real_T(&st, &RL, 3, &l_emlrtRTEI);
  emxInit_real_T(&st, &rJ, 2, &l_emlrtRTEI);
  emxInit_real_T(&st, &rL, 2, &l_emlrtRTEI);
  emxInit_real_T(&st, &e, 2, &l_emlrtRTEI);
  emxInit_real_T(&st, &g, 2, &l_emlrtRTEI);
  Kinematics(&st, *R0, *r0, qm, &robot, RJ, RL, rJ, rL, e, g);
  emxFreeStruct_struct0_T(&st, &robot);
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
    plhs[2] = b_emlrt_marshallOut(rJ);
  }
  emxFree_real_T(&st, &rJ);
  if (nlhs > 3) {
    rL->canFreeData = false;
    plhs[3] = b_emlrt_marshallOut(rL);
  }
  emxFree_real_T(&st, &rL);
  if (nlhs > 4) {
    e->canFreeData = false;
    plhs[4] = b_emlrt_marshallOut(e);
  }
  emxFree_real_T(&st, &e);
  if (nlhs > 5) {
    g->canFreeData = false;
    plhs[5] = b_emlrt_marshallOut(g);
  }
  emxFree_real_T(&st, &g);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_Kinematics_api.c) */
