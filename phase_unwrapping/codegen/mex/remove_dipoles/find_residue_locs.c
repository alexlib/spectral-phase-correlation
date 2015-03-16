/*
 * find_residue_locs.c
 *
 * Code generation for function 'find_residue_locs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "remove_dipoles.h"
#include "find_residue_locs.h"
#include "remove_dipoles_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "remove_dipoles_mexutil.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = { 7, "find_residue_locs",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/find_resid"
  "ue_locs.m" };

static emlrtRSInfo l_emlrtRSI = { 9, "find_residue_locs",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/find_resid"
  "ue_locs.m" };

static emlrtRSInfo m_emlrtRSI = { 11, "bitget",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/bitget.m" };

static emlrtRSInfo n_emlrtRSI = { 48, "bitget",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/bitget.m" };

static emlrtRSInfo o_emlrtRSI = { 11, "eml_scalexp_alloc",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"
};

static emlrtRSInfo p_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo q_emlrtRSI = { 41, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo r_emlrtRSI = { 230, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtMCInfo c_emlrtMCI = { 239, 9, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 1, "scalexpAlloc",
  "/Applications/MATLAB_R2014b.app/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"
};

static emlrtRTEInfo b_emlrtRTEI = { 1, 25, "find_residue_locs",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/find_resid"
  "ue_locs.m" };

static emlrtRTEInfo c_emlrtRTEI = { 127, 5, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo d_emlrtRTEI = { 249, 13, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo e_emlrtRTEI = { 33, 6, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtECInfo emlrtECI = { -1, 7, 21, "find_residue_locs",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/find_resid"
  "ue_locs.m" };

static emlrtRSInfo x_emlrtRSI = { 239, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

/* Function Definitions */
void find_residue_locs(const emlrtStack *sp, const emxArray_uint8_T
  *FLAGS_MATRIX, emxArray_real_T *RESIDUE_LOCS)
{
  emxArray_uint8_T *r0;
  int32_T nx;
  int32_T i0;
  boolean_T overflow;
  int32_T k;
  emxArray_uint8_T *r1;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  const mxArray *y;
  const mxArray *m0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_uint8_T(sp, &r0, 1, &b_emlrtRTEI, true);

  /*  Bit positions of positive and negative residue flags. */
  st.site = &k_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  nx = FLAGS_MATRIX->size[0] * FLAGS_MATRIX->size[1];
  i0 = r0->size[0];
  r0->size[0] = nx;
  emxEnsureCapacity(&c_st, (emxArray__common *)r0, i0, (int32_T)sizeof(uint8_T),
                    &emlrtRTEI);
  if (nx == 0) {
  } else {
    b_st.site = &n_emlrtRSI;
    if (1 > nx) {
      overflow = false;
    } else {
      overflow = (nx > 2147483646);
    }

    if (overflow) {
      c_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 0; k + 1 <= nx; k++) {
      r0->data[k] = (uint8_T)((FLAGS_MATRIX->data[k] & 1) != 0);
    }
  }

  emxInit_uint8_T(&st, &r1, 1, &b_emlrtRTEI, true);
  st.site = &l_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  nx = FLAGS_MATRIX->size[0] * FLAGS_MATRIX->size[1];
  i0 = r1->size[0];
  r1->size[0] = nx;
  emxEnsureCapacity(&c_st, (emxArray__common *)r1, i0, (int32_T)sizeof(uint8_T),
                    &emlrtRTEI);
  if (nx == 0) {
  } else {
    b_st.site = &n_emlrtRSI;
    if (1 > nx) {
      overflow = false;
    } else {
      overflow = (nx > 2147483646);
    }

    if (overflow) {
      c_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 0; k + 1 <= nx; k++) {
      r1->data[k] = (uint8_T)((FLAGS_MATRIX->data[k] & 2) != 0);
    }
  }

  emxInit_boolean_T(&st, &x, 1, &b_emlrtRTEI, true);
  i0 = r0->size[0];
  k = r1->size[0];
  emlrtSizeEqCheck1DFastR2012b(i0, k, &emlrtECI, sp);
  st.site = &k_emlrtRSI;
  i0 = x->size[0];
  x->size[0] = r0->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i0, (int32_T)sizeof(boolean_T),
                    &b_emlrtRTEI);
  k = r0->size[0];
  for (i0 = 0; i0 < k; i0++) {
    x->data[i0] = ((r0->data[i0] != 0) || (r1->data[i0] != 0));
  }

  emxFree_uint8_T(&r1);
  emxFree_uint8_T(&r0);
  emxInit_int32_T(&st, &ii, 1, &e_emlrtRTEI, true);
  b_st.site = &q_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i0 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &c_emlrtRTEI);
  c_st.site = &r_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k <= nx)) {
    guard1 = false;
    if (x->data[k - 1]) {
      idx++;
      ii->data[idx - 1] = k;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      k++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    y = NULL;
    m0 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&y, m0);
    c_st.site = &x_emlrtRSI;
    error(&c_st, y, &c_emlrtMCI);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i0 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                        (int32_T), &b_emlrtRTEI);
    }
  } else {
    i0 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                      &d_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  i0 = RESIDUE_LOCS->size[0];
  RESIDUE_LOCS->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)RESIDUE_LOCS, i0, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  k = ii->size[0];
  for (i0 = 0; i0 < k; i0++) {
    RESIDUE_LOCS->data[i0] = ii->data[i0];
  }

  emxFree_int32_T(&ii);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (find_residue_locs.c) */
