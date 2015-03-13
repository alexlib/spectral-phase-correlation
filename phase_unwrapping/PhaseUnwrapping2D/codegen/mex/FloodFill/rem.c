/*
 * rem.c
 *
 * Code generation for function 'rem'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FloodFill.h"
#include "rem.h"
#include "FloodFill_emxutil.h"
#include "FloodFill_data.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 38, "rem",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elfun/rem.m" };

/* Function Definitions */
void b_rem(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
           emxArray_real_T *r)
{
  uint32_T unnamed_idx_0;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &m_emlrtRSI;
  unnamed_idx_0 = (uint32_T)x->size[0];
  k = r->size[0];
  r->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity(&b_st, (emxArray__common *)r, k, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  for (k = 0; k < (int32_T)unnamed_idx_0; k++) {
    r->data[k] = muDoubleScalarRem(x->data[k], y);
  }
}

/* End of code generation (rem.c) */
