/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculate_branch_cuts_goldstein.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "calculate_branch_cuts_goldstein_mexutil.h"
#include "calculate_branch_cuts_goldstein_data.h"

/* Variable Definitions */
static emlrtRSInfo oc_emlrtRSI = { 13, "sum",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/sum.m" };

static emlrtRSInfo pc_emlrtRSI = { 19, "sumprod",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo qc_emlrtRSI = { 38, "sumprod",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo rc_emlrtRSI = { 46, "sumprod",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo sc_emlrtRSI = { 36, "combine_vector_elements",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtMCInfo w_emlrtMCI = { 28, 19, "assert",
  "/Applications/MATLAB_R2014b.app/toolbox/shared/coder/coder/+coder/+internal/assert.m"
};

static emlrtRSInfo de_emlrtRSI = { 28, "assert",
  "/Applications/MATLAB_R2014b.app/toolbox/shared/coder/coder/+coder/+internal/assert.m"
};

/* Function Definitions */
real_T sum(const emlrtStack *sp, const emxArray_uint8_T *x)
{
  real_T y;
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv10[2] = { 1, 36 };

  const mxArray *m4;
  char_T cv12[36];
  int32_T i;
  static const char_T cv13[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T p;
  int32_T exitg1;
  int32_T i1;
  const mxArray *c_y;
  static const int32_T iv11[2] = { 1, 37 };

  char_T cv14[37];
  static const char_T cv15[37] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'U', 'n', 's', 'u', 'p', 'p', 'o', 'r', 't', 'e',
    'd', 'S', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  b_st.site = &pc_emlrtRSI;
  if (overflow) {
  } else {
    b_y = NULL;
    m4 = emlrtCreateCharArray(2, iv10);
    for (i = 0; i < 36; i++) {
      cv12[i] = cv13[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 36, m4, cv12);
    emlrtAssign(&b_y, m4);
    c_st.site = &de_emlrtRSI;
    error(&c_st, b_message(&c_st, b_y, &w_emlrtMCI), &w_emlrtMCI);
  }

  overflow = false;
  p = false;
  i = 0;
  do {
    exitg1 = 0;
    if (i < 2) {
      if (1 + i <= 1) {
        i1 = x->size[i];
      } else {
        i1 = 1;
      }

      if (i1 != 0) {
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  b_st.site = &qc_emlrtRSI;
  if (!overflow) {
  } else {
    c_y = NULL;
    m4 = emlrtCreateCharArray(2, iv11);
    for (i = 0; i < 37; i++) {
      cv14[i] = cv15[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 37, m4, cv14);
    emlrtAssign(&c_y, m4);
    c_st.site = &de_emlrtRSI;
    error(&c_st, b_message(&c_st, c_y, &w_emlrtMCI), &w_emlrtMCI);
  }

  b_st.site = &rc_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    c_st.site = &sc_emlrtRSI;
    if (2 > x->size[0]) {
      overflow = false;
    } else {
      overflow = (x->size[0] > 2147483646);
    }

    if (overflow) {
      d_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (i = 2; i <= x->size[0]; i++) {
      y += (real_T)x->data[i - 1];
    }
  }

  return y;
}

/* End of code generation (sum.c) */
