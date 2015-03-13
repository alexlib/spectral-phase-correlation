/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FloodFill.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "FloodFill_emxutil.h"
#include "FloodFill_mexutil.h"
#include "FloodFill_data.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 13, "sum",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/sum.m" };

static emlrtRSInfo ab_emlrtRSI = { 19, "sumprod",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo bb_emlrtRSI = { 38, "sumprod",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo cb_emlrtRSI = { 46, "sumprod",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo db_emlrtRSI = { 45, "combine_vector_elements",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRSInfo eb_emlrtRSI = { 51, "combine_vector_elements",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRSInfo fb_emlrtRSI = { 36, "combine_vector_elements",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtMCInfo k_emlrtMCI = { 28, 19, "assert",
  "/Applications/MATLAB_R2014b.app/toolbox/shared/coder/coder/+coder/+internal/assert.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 30, 1, "combine_vector_elements",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRTEInfo p_emlrtRTEI = { 1, 14, "sum",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/sum.m" };

static emlrtRSInfo hb_emlrtRSI = { 28, "assert",
  "/Applications/MATLAB_R2014b.app/toolbox/shared/coder/coder/+coder/+internal/assert.m"
};

/* Function Definitions */
real_T b_sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv11[2] = { 1, 36 };

  const mxArray *m4;
  char_T cv13[36];
  int32_T i;
  static const char_T cv14[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T p;
  int32_T exitg1;
  int32_T i2;
  const mxArray *c_y;
  static const int32_T iv12[2] = { 1, 37 };

  char_T cv15[37];
  static const char_T cv16[37] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'U', 'n', 's', 'u', 'p', 'p', 'o', 'r', 't', 'e',
    'd', 'S', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  b_st.site = &ab_emlrtRSI;
  if (overflow) {
  } else {
    b_y = NULL;
    m4 = emlrtCreateCharArray(2, iv11);
    for (i = 0; i < 36; i++) {
      cv13[i] = cv14[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 36, m4, cv13);
    emlrtAssign(&b_y, m4);
    c_st.site = &hb_emlrtRSI;
    error(&c_st, message(&c_st, b_y, &k_emlrtMCI), &k_emlrtMCI);
  }

  overflow = false;
  p = false;
  i = 0;
  do {
    exitg1 = 0;
    if (i < 2) {
      i2 = x->size[i];
      if (i2 != 0) {
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

  b_st.site = &bb_emlrtRSI;
  if (!overflow) {
  } else {
    c_y = NULL;
    m4 = emlrtCreateCharArray(2, iv12);
    for (i = 0; i < 37; i++) {
      cv15[i] = cv16[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 37, m4, cv15);
    emlrtAssign(&c_y, m4);
    c_st.site = &hb_emlrtRSI;
    error(&c_st, message(&c_st, c_y, &k_emlrtMCI), &k_emlrtMCI);
  }

  b_st.site = &cb_emlrtRSI;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    c_st.site = &fb_emlrtRSI;
    if (2 > x->size[1]) {
      overflow = false;
    } else {
      overflow = (x->size[1] > 2147483646);
    }

    if (overflow) {
      d_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (i = 2; i <= x->size[1]; i++) {
      y += x->data[i - 1];
    }
  }

  return y;
}

void sum(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv9[2] = { 1, 36 };

  const mxArray *m3;
  char_T cv9[36];
  int32_T i;
  static const char_T cv10[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T p;
  int32_T ixstart;
  int32_T exitg1;
  const mxArray *c_y;
  static const int32_T iv10[2] = { 1, 37 };

  char_T cv11[37];
  static const char_T cv12[37] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'U', 'n', 's', 'u', 'p', 'p', 'o', 'r', 't', 'e',
    'd', 'S', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };

  uint32_T sz[2];
  int32_T vlen;
  int32_T ix;
  int32_T iy;
  real_T s;
  boolean_T b1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (((x->size[0] == 1) && (x->size[1] == 1)) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  b_st.site = &ab_emlrtRSI;
  if (overflow) {
  } else {
    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv9);
    for (i = 0; i < 36; i++) {
      cv9[i] = cv10[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 36, m3, cv9);
    emlrtAssign(&b_y, m3);
    c_st.site = &hb_emlrtRSI;
    error(&c_st, message(&c_st, b_y, &k_emlrtMCI), &k_emlrtMCI);
  }

  overflow = false;
  p = false;
  ixstart = 0;
  do {
    exitg1 = 0;
    if (ixstart < 2) {
      i = x->size[ixstart];
      if (i != 0) {
        exitg1 = 1;
      } else {
        ixstart++;
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

  b_st.site = &bb_emlrtRSI;
  if (!overflow) {
  } else {
    c_y = NULL;
    m3 = emlrtCreateCharArray(2, iv10);
    for (i = 0; i < 37; i++) {
      cv11[i] = cv12[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 37, m3, cv11);
    emlrtAssign(&c_y, m3);
    c_st.site = &hb_emlrtRSI;
    error(&c_st, message(&c_st, c_y, &k_emlrtMCI), &k_emlrtMCI);
  }

  b_st.site = &cb_emlrtRSI;
  for (i = 0; i < 2; i++) {
    sz[i] = (uint32_T)x->size[i];
  }

  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                    &o_emlrtRTEI);
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity(&b_st, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                      &p_emlrtRTEI);
    i = y->size[0] * y->size[1];
    y->size[1] = (int32_T)sz[1];
    emxEnsureCapacity(&b_st, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                      &p_emlrtRTEI);
    ixstart = (int32_T)sz[1];
    for (i = 0; i < ixstart; i++) {
      y->data[i] = 0.0;
    }
  } else {
    vlen = x->size[0];
    ix = -1;
    iy = -1;
    c_st.site = &db_emlrtRSI;
    overflow = (x->size[1] > 2147483646);
    if (overflow) {
      d_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (i = 1; i <= x->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      c_st.site = &eb_emlrtRSI;
      if (2 > vlen) {
        b1 = false;
      } else {
        b1 = (vlen > 2147483646);
      }

      if (b1) {
        d_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&d_st, true);
      }

      for (ixstart = 2; ixstart <= vlen; ixstart++) {
        ix++;
        s += x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

/* End of code generation (sum.c) */
