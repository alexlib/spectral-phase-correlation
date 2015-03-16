/*
 * _coder_remove_dipoles_api.c
 *
 * Code generation for function '_coder_remove_dipoles_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "remove_dipoles.h"
#include "_coder_remove_dipoles_api.h"
#include "remove_dipoles_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo f_emlrtRTEI = { 1, 1, "_coder_remove_dipoles_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *FLAGS_MATRIX,
  const char_T *identifier, emxArray_uint8_T *y);
static void emlrt_marshallOut(const emxArray_uint8_T *u, const mxArray *y);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint8_T *y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint8_T *ret)
{
  int32_T iv2[2];
  boolean_T bv0[2];
  int32_T i;
  int32_T iv3[2];
  for (i = 0; i < 2; i++) {
    iv2[i] = -1;
    bv0[i] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, iv2, bv0, iv3);
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
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

static void emlrt_marshallOut(const emxArray_uint8_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

void remove_dipoles_api(const mxArray *prhs[1], const mxArray *plhs[1])
{
  emxArray_uint8_T *FLAGS_MATRIX;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  b_emxInit_uint8_T(&st, &FLAGS_MATRIX, 2, &f_emlrtRTEI, true);
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, true, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "FLAGS_MATRIX", FLAGS_MATRIX);

  /* Invoke the target function */
  remove_dipoles(&st, FLAGS_MATRIX);

  /* Marshall function outputs */
  emlrt_marshallOut(FLAGS_MATRIX, prhs[0]);
  plhs[0] = prhs[0];
  FLAGS_MATRIX->canFreeData = false;
  emxFree_uint8_T(&FLAGS_MATRIX);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_remove_dipoles_api.c) */
