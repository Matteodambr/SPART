/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * _coder_Kinematics_info.c
 *
 * Code generation for function 'Kinematics'
 *
 */

/* Include files */
#include "_coder_Kinematics_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789ced55d16ed3301475d940db2460bc20b4fd43cd04a8e5b1ebcae85847ba06a9ea0459"
      "9ab84bd6384e63a774fb893df0c2e7f427f631ec694d13274d242b15"
      "1d41ad765fae8f4eece37b6f72020af5460100f00204d17e15e4e721de0ef313908c345f"
      "08f35a0af3780ad613fb387f13668dd80c8d58006c15a368a74eb069",
      "ab3693af1c045c44893544fa94e99916924d8c5ab3e0c447f8d30c15019ff2d7550369fd"
      "9687816bd0f886d62c88fa712ea8773da31fe948f723fd1cd773fe52"
      "8f9fbf95a1c7f92fa68db0ca4c8d26f5cf17d47f26d40f18ca5c4f63b1de7841bd33a15e"
      "923fab7d8706c108625dc55d975093c00344fb8c38f0d06486d78595",
      "bafc55521a52155257832da9722a4f57fda8558a7e357935270b18b7af88a7e767f5efe5"
      "9cf5a473fcfcc634eff7768d3cf5ee6eff6ce5a9c7e37fe98d04e7cd"
      "fb3ebe16e86da7f866d9baae5d4a6c207b52f9c3fba3d3fd7792fc39be8794a193750f20"
      "c0799d3f16ec5fd6ef7a515fdecca887f335cf42ae72506d84382f5f",
      "d689d7b5d0c3cd4f11ea25f905e6a73266324f470a73559bf688eb0f8ed814463d9ccc30"
      "2f1ff965bfc9d597773abf8b79eaf158755f6e542ef64a3ff79a4673"
      "e81c95f4a1d6bea86b8fbebc74dff5bcf56ca4705c4fc00c3c95f992cbeac33f847a49fe"
      "5fcc8bf7ceff953efaf0c3e8f158751fee7c3bfed81a5d1e0e8ee55a",
      "e96d8538654cd00af8f03dbc041ffa",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 4464U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[7] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Visible"};
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum", "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "AuxData"};
  uint8_T v[216] = {
      0U,   1U,   73U,  77U,  0U,   0U,   0U,   0U,   14U,  0U,   0U,   0U,
      200U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,
      2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   4U,   0U,
      17U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,   17U,  0U,   0U,   0U,
      67U,  108U, 97U,  115U, 115U, 69U,  110U, 116U, 114U, 121U, 80U,  111U,
      105U, 110U, 116U, 115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      14U,  0U,   0U,   0U,   112U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      0U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   4U,   0U,   14U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,
      56U,  0U,   0U,   0U,   81U,  117U, 97U,  108U, 105U, 102U, 105U, 101U,
      100U, 78U,  97U,  109U, 101U, 0U,   77U,  101U, 116U, 104U, 111U, 100U,
      115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   80U,  114U, 111U, 112U,
      101U, 114U, 116U, 105U, 101U, 115U, 0U,   0U,   0U,   0U,   72U,  97U,
      110U, 100U, 108U, 101U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("Kinematics"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/"
                          "src/kinematics_dynamics/Kinematics.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739744.66335648147));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(
      xResult, 0, "Version",
      emlrtMxCreateString("25.1.0.2897550 (R2025a) Prerelease Update 5"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("6Uu7zOCIxpklfVrIY8lX0D"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_Kinematics_info.c) */
