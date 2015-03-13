/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FloodFill.h"
#include "power.h"
#include "FloodFill_emxutil.h"
#include "FloodFill_data.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 42, "power",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/power.m" };

static emlrtRSInfo o_emlrtRSI = { 51, "power",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/power.m" };

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  uint32_T unnamed_idx_0;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &n_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &o_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  unnamed_idx_0 = (uint32_T)a->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity(&c_st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  for (k = 0; k < (int32_T)unnamed_idx_0; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }
}

/* End of code generation (power.c) */
