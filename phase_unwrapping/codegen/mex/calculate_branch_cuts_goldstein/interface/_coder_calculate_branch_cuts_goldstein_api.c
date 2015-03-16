/*
 * _coder_calculate_branch_cuts_goldstein_api.c
 *
 * Code generation for function '_coder_calculate_branch_cuts_goldstein_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculate_branch_cuts_goldstein.h"
#include "_coder_calculate_branch_cuts_goldstein_api.h"
#include "calculate_branch_cuts_goldstein_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo r_emlrtRTEI = { 1, 1,
  "_coder_calculate_branch_cuts_goldstein_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y);
static void b_emlrt_marshallOut(const emxArray_uint8_T *u, const mxArray *y);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MAX_BOX_SIZE, const char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *FLAGS_MATRIX,
  const char_T *identifier, emxArray_uint8_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_uint8_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallOut(const emxArray_uint8_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MAX_BOX_SIZE, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(MAX_BOX_SIZE), &thisId);
  emlrtDestroyArray(&MAX_BOX_SIZE);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret)
{
  int32_T iv26[2];
  boolean_T bv0[2];
  int32_T i;
  int32_T iv27[2];
  for (i = 0; i < 2; i++) {
    iv26[i] = -1;
    bv0[i] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, iv26, bv0, iv27);
  ret->size[0] = iv27[0];
  ret->size[1] = iv27[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (uint8_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *FLAGS_MATRIX,
  const char_T *identifier, emxArray_uint8_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(FLAGS_MATRIX), &thisId, y);
  emlrtDestroyArray(&FLAGS_MATRIX);
}

static const mxArray *emlrt_marshallOut(const emxArray_uint8_T *u)
{
  const mxArray *y;
  static const int32_T iv25[2] = { 0, 0 };

  const mxArray *m6;
  y = NULL;
  m6 = emlrtCreateNumericArray(2, iv25, mxUINT8_CLASS, mxREAL);
  mxSetData((mxArray *)m6, (void *)u->data);
  emlrtSetDimensions((mxArray *)m6, u->size, 2);
  emlrtAssign(&y, m6);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void calculate_branch_cuts_goldstein_api(const mxArray *prhs[2], const mxArray
  *plhs[2])
{
  emxArray_uint8_T *FLAGS_MATRIX;
  emxArray_uint8_T *branch_cut_matrix;
  real_T MAX_BOX_SIZE;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  b_emxInit_uint8_T(&st, &FLAGS_MATRIX, 2, &r_emlrtRTEI, true);
  b_emxInit_uint8_T(&st, &branch_cut_matrix, 2, &r_emlrtRTEI, true);
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, true, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "FLAGS_MATRIX", FLAGS_MATRIX);
  MAX_BOX_SIZE = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "MAX_BOX_SIZE");

  /* Invoke the target function */
  calculate_branch_cuts_goldstein(&st, FLAGS_MATRIX, MAX_BOX_SIZE,
    branch_cut_matrix);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(branch_cut_matrix);
  b_emlrt_marshallOut(FLAGS_MATRIX, prhs[0]);
  plhs[1] = prhs[0];
  branch_cut_matrix->canFreeData = false;
  emxFree_uint8_T(&branch_cut_matrix);
  FLAGS_MATRIX->canFreeData = false;
  emxFree_uint8_T(&FLAGS_MATRIX);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_calculate_branch_cuts_goldstein_api.c) */
