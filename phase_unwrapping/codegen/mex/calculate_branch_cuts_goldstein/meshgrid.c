/*
 * meshgrid.c
 *
 * Code generation for function 'meshgrid'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculate_branch_cuts_goldstein.h"
#include "meshgrid.h"
#include "calculate_branch_cuts_goldstein_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "calculate_branch_cuts_goldstein_mexutil.h"
#include "calculate_branch_cuts_goldstein_data.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = { 17, "meshgrid",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/meshgrid.m" };

static emlrtRSInfo qb_emlrtRSI = { 18, "meshgrid",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/meshgrid.m" };

static emlrtRSInfo rb_emlrtRSI = { 12, "repmat",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRSInfo sb_emlrtRSI = { 40, "repmat",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRSInfo tb_emlrtRSI = { 42, "repmat",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRSInfo ub_emlrtRSI = { 45, "repmat",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRSInfo vb_emlrtRSI = { 47, "repmat",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtMCInfo h_emlrtMCI = { 24, 5, "repmat",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtMCInfo i_emlrtMCI = { 42, 9, "eml_assert_valid_size_arg",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtMCInfo j_emlrtMCI = { 41, 19, "eml_assert_valid_size_arg",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtMCInfo k_emlrtMCI = { 57, 5, "eml_assert_valid_size_arg",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtMCInfo l_emlrtMCI = { 56, 15, "eml_assert_valid_size_arg",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 1, 23, "meshgrid",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/meshgrid.m" };

static emlrtRTEInfo i_emlrtRTEI = { 30, 1, "repmat",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRSInfo ee_emlrtRSI = { 56, "eml_assert_valid_size_arg",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtRSInfo fe_emlrtRSI = { 41, "eml_assert_valid_size_arg",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtRSInfo ge_emlrtRSI = { 24, "repmat",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRSInfo ne_emlrtRSI = { 57, "eml_assert_valid_size_arg",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtRSInfo pe_emlrtRSI = { 42, "eml_assert_valid_size_arg",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

/* Function Declarations */
static const mxArray *c_message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static void eml_assert_valid_size_arg(const emlrtStack *sp, const real_T
  varargin_1[2]);

/* Function Definitions */
static const mxArray *c_message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m9;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m9, 3, pArrays, "message", true, location);
}

static void eml_assert_valid_size_arg(const emlrtStack *sp, const real_T
  varargin_1[2])
{
  int32_T i;
  int32_T exitg2;
  boolean_T p;
  boolean_T guard1 = false;
  int32_T exitg1;
  const mxArray *y;
  static const int32_T iv8[2] = { 1, 57 };

  const mxArray *m3;
  char_T cv8[57];
  static const char_T cv9[57] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 's', 's', 'e', 'r', 't',
    '_', 'v', 'a', 'l', 'i', 'd', '_', 's', 'i', 'z', 'e', '_', 'a', 'r', 'g',
    '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'S', 'i', 'z', 'e', 'V', 'e', 'c',
    't', 'o', 'r' };

  const mxArray *b_y;
  const mxArray *c_y;
  real_T n;
  const mxArray *d_y;
  static const int32_T iv9[2] = { 1, 21 };

  char_T cv10[21];
  static const char_T cv11[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  i = 0;
  do {
    exitg2 = 0;
    if (i < 2) {
      if ((varargin_1[i] != muDoubleScalarFloor(varargin_1[i])) ||
          muDoubleScalarIsInf(varargin_1[i])) {
        p = false;
        exitg2 = 1;
      } else {
        i++;
      }
    } else {
      p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  guard1 = false;
  if (p) {
    i = 0;
    do {
      exitg1 = 0;
      if (i < 2) {
        if ((-2.147483648E+9 > varargin_1[i]) || (2.147483647E+9 < varargin_1[i]))
        {
          p = false;
          exitg1 = 1;
        } else {
          i++;
        }
      } else {
        p = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (p) {
      p = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    p = false;
  }

  if (p) {
  } else {
    y = NULL;
    m3 = emlrtCreateCharArray(2, iv8);
    for (i = 0; i < 57; i++) {
      cv8[i] = cv9[i];
    }

    emlrtInitCharArrayR2013a(sp, 57, m3, cv8);
    emlrtAssign(&y, m3);
    b_y = NULL;
    m3 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)mxGetData(m3) = MIN_int32_T;
    emlrtAssign(&b_y, m3);
    c_y = NULL;
    m3 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)mxGetData(m3) = MAX_int32_T;
    emlrtAssign(&c_y, m3);
    st.site = &fe_emlrtRSI;
    b_st.site = &pe_emlrtRSI;
    error(&st, c_message(&b_st, y, b_y, c_y, &i_emlrtMCI), &j_emlrtMCI);
  }

  n = 1.0;
  for (i = 0; i < 2; i++) {
    if (varargin_1[i] <= 0.0) {
      n = 0.0;
    } else {
      n *= varargin_1[i];
    }
  }

  if (2.147483647E+9 >= n) {
  } else {
    d_y = NULL;
    m3 = emlrtCreateCharArray(2, iv9);
    for (i = 0; i < 21; i++) {
      cv10[i] = cv11[i];
    }

    emlrtInitCharArrayR2013a(sp, 21, m3, cv10);
    emlrtAssign(&d_y, m3);
    st.site = &ee_emlrtRSI;
    b_st.site = &ne_emlrtRSI;
    error(&st, b_message(&b_st, d_y, &k_emlrtMCI), &l_emlrtMCI);
  }
}

void meshgrid(const emlrtStack *sp, const emxArray_real_T *x, const
              emxArray_real_T *y, emxArray_real_T *xx, emxArray_real_T *yy)
{
  emxArray_real_T *a;
  int32_T jcol;
  int32_T i;
  real_T varargin_1[2];
  const mxArray *b_y;
  static const int32_T iv4[2] = { 1, 15 };

  const mxArray *m2;
  char_T cv6[15];
  static const char_T cv7[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  int32_T outsize_idx_1;
  const mxArray *c_y;
  static const int32_T iv5[2] = { 1, 15 };

  int32_T ibmat;
  int32_T itilerow;
  const mxArray *d_y;
  static const int32_T iv6[2] = { 1, 15 };

  const mxArray *e_y;
  static const int32_T iv7[2] = { 1, 15 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  b_emxInit_real_T(sp, &a, 2, &h_emlrtRTEI, true);
  if ((x->size[1] == 0) || (y->size[1] == 0)) {
    jcol = xx->size[0] * xx->size[1];
    xx->size[0] = 0;
    xx->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)xx, jcol, (int32_T)sizeof(real_T),
                      &h_emlrtRTEI);
    jcol = yy->size[0] * yy->size[1];
    yy->size[0] = 0;
    yy->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)yy, jcol, (int32_T)sizeof(real_T),
                      &h_emlrtRTEI);
  } else {
    st.site = &pb_emlrtRSI;
    i = x->size[1];
    jcol = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = i;
    emxEnsureCapacity(&st, (emxArray__common *)a, jcol, (int32_T)sizeof(real_T),
                      &h_emlrtRTEI);
    for (jcol = 0; jcol < i; jcol++) {
      a->data[a->size[0] * jcol] = x->data[jcol];
    }

    varargin_1[0] = y->size[1];
    varargin_1[1] = 1.0;
    b_st.site = &rb_emlrtRSI;
    eml_assert_valid_size_arg(&b_st, varargin_1);
    if (varargin_1[0] == varargin_1[0]) {
    } else {
      b_y = NULL;
      m2 = emlrtCreateCharArray(2, iv4);
      for (i = 0; i < 15; i++) {
        cv6[i] = cv7[i];
      }

      emlrtInitCharArrayR2013a(&st, 15, m2, cv6);
      emlrtAssign(&b_y, m2);
      b_st.site = &ge_emlrtRSI;
      error(&b_st, b_y, &h_emlrtMCI);
    }

    outsize_idx_1 = a->size[1];
    if (outsize_idx_1 == a->size[1]) {
    } else {
      c_y = NULL;
      m2 = emlrtCreateCharArray(2, iv5);
      for (i = 0; i < 15; i++) {
        cv6[i] = cv7[i];
      }

      emlrtInitCharArrayR2013a(&st, 15, m2, cv6);
      emlrtAssign(&c_y, m2);
      b_st.site = &ge_emlrtRSI;
      error(&b_st, c_y, &h_emlrtMCI);
    }

    jcol = xx->size[0] * xx->size[1];
    xx->size[0] = (int32_T)varargin_1[0];
    xx->size[1] = outsize_idx_1;
    emxEnsureCapacity(&st, (emxArray__common *)xx, jcol, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    i = a->size[1];
    outsize_idx_1 = (int32_T)varargin_1[0];
    b_st.site = &sb_emlrtRSI;
    b_st.site = &tb_emlrtRSI;
    if (i > 2147483646) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (jcol = 0; jcol + 1 <= i; jcol++) {
      ibmat = jcol * outsize_idx_1;
      b_st.site = &ub_emlrtRSI;
      if (outsize_idx_1 > 2147483646) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (itilerow = 1; itilerow <= outsize_idx_1; itilerow++) {
        xx->data[(ibmat + itilerow) - 1] = a->data[jcol];
      }
    }

    st.site = &qb_emlrtRSI;
    varargin_1[0] = 1.0;
    varargin_1[1] = x->size[1];
    b_st.site = &rb_emlrtRSI;
    eml_assert_valid_size_arg(&b_st, varargin_1);
    ibmat = y->size[1];
    i = y->size[1];
    if (ibmat == i) {
    } else {
      d_y = NULL;
      m2 = emlrtCreateCharArray(2, iv6);
      for (i = 0; i < 15; i++) {
        cv6[i] = cv7[i];
      }

      emlrtInitCharArrayR2013a(&st, 15, m2, cv6);
      emlrtAssign(&d_y, m2);
      b_st.site = &ge_emlrtRSI;
      error(&b_st, d_y, &h_emlrtMCI);
    }

    if (varargin_1[1] == varargin_1[1]) {
    } else {
      e_y = NULL;
      m2 = emlrtCreateCharArray(2, iv7);
      for (i = 0; i < 15; i++) {
        cv6[i] = cv7[i];
      }

      emlrtInitCharArrayR2013a(&st, 15, m2, cv6);
      emlrtAssign(&e_y, m2);
      b_st.site = &ge_emlrtRSI;
      error(&b_st, e_y, &h_emlrtMCI);
    }

    jcol = yy->size[0] * yy->size[1];
    yy->size[0] = ibmat;
    yy->size[1] = (int32_T)varargin_1[1];
    emxEnsureCapacity(&st, (emxArray__common *)yy, jcol, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    ibmat = y->size[1];
    b_st.site = &sb_emlrtRSI;
    if (varargin_1[1] > 2.147483646E+9) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (i = 1; i <= (int32_T)varargin_1[1]; i++) {
      outsize_idx_1 = (i - 1) * ibmat;
      b_st.site = &ub_emlrtRSI;
      b_st.site = &vb_emlrtRSI;
      if (ibmat > 2147483646) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (jcol = 0; jcol + 1 <= ibmat; jcol++) {
        yy->data[outsize_idx_1 + jcol] = y->data[jcol];
      }
    }
  }

  emxFree_real_T(&a);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (meshgrid.c) */
