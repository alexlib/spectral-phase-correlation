/*
 * _coder_FloodFill_api.c
 *
 * Code generation for function '_coder_FloodFill_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FloodFill.h"
#include "_coder_FloodFill_api.h"
#include "FloodFill_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo q_emlrtRTEI = { 1, 1, "_coder_FloodFill_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *branch_cuts,
  const char_T *identifier, emxArray_uint8_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *IM_phase,
  const char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv14[1] = { 0 };

  const mxArray *m6;
  y = NULL;
  m6 = emlrtCreateNumericArray(1, iv14, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m6, (void *)u->data);
  emlrtSetDimensions((mxArray *)m6, u->size, 1);
  emlrtAssign(&y, m6);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *branch_cuts,
  const char_T *identifier, emxArray_uint8_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(branch_cuts), &thisId, y);
  emlrtDestroyArray(&branch_cuts);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv15[2];
  boolean_T bv0[2];
  int32_T i;
  int32_T iv16[2];
  for (i = 0; i < 2; i++) {
    iv15[i] = -1;
    bv0[i] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv15, bv0, iv16);
  ret->size[0] = iv16[0];
  ret->size[1] = iv16[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *IM_phase,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(IM_phase), &thisId, y);
  emlrtDestroyArray(&IM_phase);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv13[2] = { 0, 0 };

  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateNumericArray(2, iv13, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m5, (void *)u->data);
  emlrtSetDimensions((mxArray *)m5, u->size, 2);
  emlrtAssign(&y, m5);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret)
{
  int32_T iv17[2];
  boolean_T bv1[2];
  int32_T i;
  int32_T iv18[2];
  for (i = 0; i < 2; i++) {
    iv17[i] = -1;
    bv1[i] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, iv17, bv1, iv18);
  ret->size[0] = iv18[0];
  ret->size[1] = iv18[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (uint8_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void FloodFill_api(const mxArray * const prhs[2], const mxArray *plhs[3])
{
  emxArray_real_T *IM_phase;
  emxArray_uint8_T *branch_cuts;
  emxArray_real_T *IM_unwrapped;
  emxArray_real_T *rowref;
  emxArray_real_T *colref;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  b_emxInit_real_T(&st, &IM_phase, 2, &q_emlrtRTEI, true);
  emxInit_uint8_T(&st, &branch_cuts, 2, &q_emlrtRTEI, true);
  b_emxInit_real_T(&st, &IM_unwrapped, 2, &q_emlrtRTEI, true);
  emxInit_real_T(&st, &rowref, 1, &q_emlrtRTEI, true);
  emxInit_real_T(&st, &colref, 1, &q_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "IM_phase", IM_phase);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "branch_cuts", branch_cuts);

  /* Invoke the target function */
  FloodFill(&st, IM_phase, branch_cuts, IM_unwrapped, rowref, colref);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(IM_unwrapped);
  plhs[1] = b_emlrt_marshallOut(rowref);
  plhs[2] = b_emlrt_marshallOut(colref);
  colref->canFreeData = false;
  emxFree_real_T(&colref);
  rowref->canFreeData = false;
  emxFree_real_T(&rowref);
  IM_unwrapped->canFreeData = false;
  emxFree_real_T(&IM_unwrapped);
  branch_cuts->canFreeData = false;
  emxFree_uint8_T(&branch_cuts);
  IM_phase->canFreeData = false;
  emxFree_real_T(&IM_phase);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_FloodFill_api.c) */
