/*
 * count_residues.c
 *
 * Code generation for function 'count_residues'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculate_branch_cuts_goldstein.h"
#include "count_residues.h"
#include "calculate_branch_cuts_goldstein_emxutil.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "calculate_branch_cuts_goldstein_data.h"

/* Variable Definitions */
static emlrtRSInfo mc_emlrtRSI = { 11, "count_residues",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/count_resi"
  "dues.m" };

static emlrtRSInfo nc_emlrtRSI = { 12, "count_residues",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/count_resi"
  "dues.m" };

static emlrtRTEInfo l_emlrtRTEI = { 1, 25, "count_residues",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/count_resi"
  "dues.m" };

/* Function Definitions */
real_T count_residues(const emlrtStack *sp, const emxArray_uint8_T *FLAGS_MATRIX)
{
  real_T NUM_RESIDUES;
  emxArray_uint8_T *r3;
  int32_T FLAGS_MATRIX_idx_0;
  int32_T k;
  boolean_T overflow;
  emxArray_uint8_T *r4;
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
  d_st.prev = sp;
  d_st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_uint8_T(sp, &r3, 1, &l_emlrtRTEI, true);

  /*  This function counts the total number of residues contained */
  /*  in a matrix of residue flags, and also returns the net charge in the */
  /*  region. */
  /*  Bit positions of positive and negative residue flags. */
  /*  NUM_RESIDUES = sum(abs(RESIDUE_MATRIX(:)) > 0); */
  st.site = &mc_emlrtRSI;
  b_st.site = &ab_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  FLAGS_MATRIX_idx_0 = FLAGS_MATRIX->size[0] * FLAGS_MATRIX->size[1];
  k = r3->size[0];
  r3->size[0] = FLAGS_MATRIX_idx_0;
  emxEnsureCapacity(&c_st, (emxArray__common *)r3, k, (int32_T)sizeof(uint8_T),
                    &k_emlrtRTEI);
  if (FLAGS_MATRIX_idx_0 == 0) {
  } else {
    b_st.site = &bb_emlrtRSI;
    if (1 > FLAGS_MATRIX_idx_0) {
      overflow = false;
    } else {
      overflow = (FLAGS_MATRIX_idx_0 > 2147483646);
    }

    if (overflow) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 0; k + 1 <= FLAGS_MATRIX_idx_0; k++) {
      r3->data[k] = (uint8_T)((FLAGS_MATRIX->data[k] & 1) != 0);
    }
  }

  emxInit_uint8_T(&st, &r4, 1, &l_emlrtRTEI, true);
  st.site = &nc_emlrtRSI;
  b_st.site = &ab_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  FLAGS_MATRIX_idx_0 = FLAGS_MATRIX->size[0] * FLAGS_MATRIX->size[1];
  k = r4->size[0];
  r4->size[0] = FLAGS_MATRIX_idx_0;
  emxEnsureCapacity(&c_st, (emxArray__common *)r4, k, (int32_T)sizeof(uint8_T),
                    &k_emlrtRTEI);
  if (FLAGS_MATRIX_idx_0 == 0) {
  } else {
    b_st.site = &bb_emlrtRSI;
    if (1 > FLAGS_MATRIX_idx_0) {
      overflow = false;
    } else {
      overflow = (FLAGS_MATRIX_idx_0 > 2147483646);
    }

    if (overflow) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 0; k + 1 <= FLAGS_MATRIX_idx_0; k++) {
      r4->data[k] = (uint8_T)((FLAGS_MATRIX->data[k] & 2) != 0);
    }
  }

  st.site = &mc_emlrtRSI;
  d_st.site = &nc_emlrtRSI;
  NUM_RESIDUES = sum(&st, r3) + sum(&d_st, r4);
  emxFree_uint8_T(&r4);
  emxFree_uint8_T(&r3);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return NUM_RESIDUES;
}

/* End of code generation (count_residues.c) */
