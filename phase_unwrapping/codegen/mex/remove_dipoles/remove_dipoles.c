/*
 * remove_dipoles.c
 *
 * Code generation for function 'remove_dipoles'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "remove_dipoles.h"
#include "get_flags_charge.h"
#include "remove_dipoles_emxutil.h"
#include "find_residue_locs.h"
#include "remove_dipoles_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 16, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRSInfo b_emlrtRSI = { 36, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRSInfo c_emlrtRSI = { 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRSInfo d_emlrtRSI = { 55, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRSInfo e_emlrtRSI = { 65, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRSInfo f_emlrtRSI = { 69, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRSInfo g_emlrtRSI = { 76, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRSInfo h_emlrtRSI = { 80, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRSInfo i_emlrtRSI = { 86, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRSInfo j_emlrtRSI = { 91, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtRTEInfo g_emlrtRTEI = { 16, 1, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 92, 46, "FLAGS_MATRIX", "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo emlrtDCI = { 92, 46, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 92, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo b_emlrtDCI = { 92, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 87, 49, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 87, 49, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 87, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo d_emlrtDCI = { 87, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 81, 46, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo e_emlrtDCI = { 81, 46, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 81, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo f_emlrtDCI = { 81, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 77, 46, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo g_emlrtDCI = { 77, 46, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 77, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo h_emlrtDCI = { 77, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 70, 49, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo i_emlrtDCI = { 70, 49, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 70, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo j_emlrtDCI = { 70, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 66, 49, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo k_emlrtDCI = { 66, 49, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 66, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo l_emlrtDCI = { 66, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 52, 53, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo m_emlrtDCI = { 52, 53, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 52, 44, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo n_emlrtDCI = { 52, 44, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 32, 43, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo o_emlrtDCI = { 32, 43, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 32, 31, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo p_emlrtDCI = { 32, 31, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 28, 22, "residue_locs",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtBCInfo r_emlrtBCI = { 0, MAX_int32_T, 22, 1, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 29, 19, "residue_locs",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 69, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo q_emlrtDCI = { 69, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 69, 49, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo r_emlrtDCI = { 69, 49, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 65, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo s_emlrtDCI = { 65, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 65, 49, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo t_emlrtDCI = { 65, 49, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 80, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo u_emlrtDCI = { 80, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 80, 46, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo v_emlrtDCI = { 80, 46, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 76, 37, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo w_emlrtDCI = { 76, 37, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 76, 46, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo x_emlrtDCI = { 76, 46, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 86, 33, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo y_emlrtDCI = { 86, 33, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 86, 45, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo ab_emlrtDCI = { 86, 45, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 91, 33, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo bb_emlrtDCI = { 91, 33, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 91, 42, "FLAGS_MATRIX",
  "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 0 };

static emlrtDCInfo cb_emlrtDCI = { 91, 42, "remove_dipoles",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/remove_dip"
  "oles.m", 1 };

/* Function Definitions */
void remove_dipoles(const emlrtStack *sp, emxArray_uint8_T *FLAGS_MATRIX)
{
  emxArray_real_T *residue_locs;
  int32_T i1;
  int32_T width;
  int32_T height;
  int32_T k;
  int32_T i2;
  real_T r;
  real_T anchor_charge;
  real_T y;
  real_T rows[8];
  real_T cols[8];
  static const int8_T iv4[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

  static const int8_T iv5[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

  int32_T p;
  boolean_T exitg1;
  boolean_T guard1 = false;
  real_T current_flag_charge;
  int32_T i3;
  int32_T i4;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &residue_locs, 1, &g_emlrtRTEI, true);

  /*  Define values for the different flags... */
  /*  Note that matlab indexes bit positions the same way */
  /*  it does arrays, e.g., little-endian bit 1 corresponds to 2^0. */
  /*  Positive residue flag bit-position and byte-value-if-true */
  /*  Negative residue flag bit position and byte-value-if-true */
  /*  Branch cut flag bit position and byte-value-if-true */
  /*  Determine the locations of the residues */
  st.site = &emlrtRSI;
  find_residue_locs(&st, FLAGS_MATRIX, residue_locs);

  /*  Number of residues identified */
  /*  Flags matrix dimensions */
  i1 = FLAGS_MATRIX->size[1];
  width = emlrtDynamicBoundsCheckFastR2012b(i1, 0, MAX_int32_T, &r_emlrtBCI, sp);
  height = FLAGS_MATRIX->size[0];

  /*  Loop over all the residues */
  k = 0;
  while (k <= residue_locs->size[0] - 1) {
    /*  Residue row and column */
    i1 = residue_locs->size[0];
    i2 = k + 1;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &q_emlrtBCI, sp);
    r = muDoubleScalarRem(residue_locs->data[k] - 1.0, height);
    i1 = residue_locs->size[0];
    i2 = 1 + k;
    anchor_charge = residue_locs->data[emlrtDynamicBoundsCheckFastR2012b(i2, 1,
      i1, &s_emlrtBCI, sp) - 1] - (r + 1.0);
    y = anchor_charge / (real_T)height;

    /*  Anchor flag */
    i1 = FLAGS_MATRIX->size[0];
    i2 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &p_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &p_emlrtBCI, sp);
    i1 = FLAGS_MATRIX->size[1];
    i2 = (int32_T)emlrtIntegerCheckFastR2012b(y + 1.0, &o_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &o_emlrtBCI, sp);

    /*  Check if the pixel is still marked as a residue, */
    /*  since its residue flag may have been removed. */
    st.site = &b_emlrtRSI;
    if (((FLAGS_MATRIX->data[((int32_T)(r + 1.0) + FLAGS_MATRIX->size[0] *
           ((int32_T)(y + 1.0) - 1)) - 1] & 1) != 0) || ((FLAGS_MATRIX->data
          [((int32_T)(r + 1.0) + FLAGS_MATRIX->size[0] * ((int32_T)(y + 1.0) - 1))
          - 1] & 2) != 0)) {
      st.site = &c_emlrtRSI;
      anchor_charge = get_flags_charge(FLAGS_MATRIX->data[((int32_T)
        (muDoubleScalarRem(residue_locs->data[k] - 1.0, height) + 1.0) +
        FLAGS_MATRIX->size[0] * ((int32_T)(anchor_charge / (real_T)height + 1.0)
        - 1)) - 1]);

      /*  Determine the rows and columns of the surrounding pixels. */
      for (i1 = 0; i1 < 8; i1++) {
        rows[i1] = (r + 1.0) + (real_T)iv4[i1];
        cols[i1] = (y + 1.0) + (real_T)iv5[i1];
      }

      /*  Number of surrounding pixels (should always be 8) */
      p = 0;
      exitg1 = false;
      while ((!exitg1) && (p < 8)) {
        guard1 = false;
        if ((rows[p] >= 1.0) && (cols[p] >= 1.0) && (rows[p] <= height) &&
            (cols[p] <= width)) {
          /*  Grab the current flag */
          i1 = FLAGS_MATRIX->size[0];
          i2 = (int32_T)emlrtIntegerCheckFastR2012b(rows[p], &n_emlrtDCI, sp);
          emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &n_emlrtBCI, sp);
          i1 = FLAGS_MATRIX->size[1];
          i2 = (int32_T)emlrtIntegerCheckFastR2012b(cols[p], &m_emlrtDCI, sp);
          emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &m_emlrtBCI, sp);

          /*  Measure the charge of the current flag */
          st.site = &d_emlrtRSI;
          current_flag_charge = get_flags_charge(FLAGS_MATRIX->data[((int32_T)
            rows[p] + FLAGS_MATRIX->size[0] * ((int32_T)cols[p] - 1)) - 1]);

          /*  If the charge of the current flag opposes the anchor flag */
          /*  then place a branch cut and remove the two residues. */
          if (anchor_charge + current_flag_charge == 0.0) {
            /*  Set the anchor pixel charge to zero */
            if (anchor_charge > 0.0) {
              st.site = &e_emlrtRSI;
              i1 = FLAGS_MATRIX->size[0];
              i2 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &l_emlrtDCI,
                &st);
              emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &l_emlrtBCI, &st);
              i1 = FLAGS_MATRIX->size[1];
              i2 = (int32_T)emlrtIntegerCheckFastR2012b(y + 1.0, &k_emlrtDCI,
                &st);
              emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &k_emlrtBCI, &st);
              i1 = FLAGS_MATRIX->size[0];
              i2 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &s_emlrtDCI, sp);
              i3 = FLAGS_MATRIX->size[1];
              i4 = (int32_T)emlrtIntegerCheckFastR2012b(y + 1.0, &t_emlrtDCI, sp);
              FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
                &v_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                                  (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
                &w_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data
                [((int32_T)(r + 1.0) + FLAGS_MATRIX->size[0] * ((int32_T)(y +
                1.0) - 1)) - 1] & 254);
            } else {
              if (anchor_charge < 0.0) {
                st.site = &f_emlrtRSI;
                i1 = FLAGS_MATRIX->size[0];
                i2 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &j_emlrtDCI,
                  &st);
                emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &j_emlrtBCI, &st);
                i1 = FLAGS_MATRIX->size[1];
                i2 = (int32_T)emlrtIntegerCheckFastR2012b(y + 1.0, &i_emlrtDCI,
                  &st);
                emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &i_emlrtBCI, &st);
                i1 = FLAGS_MATRIX->size[0];
                i2 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &q_emlrtDCI,
                  sp);
                i3 = FLAGS_MATRIX->size[1];
                i4 = (int32_T)emlrtIntegerCheckFastR2012b(y + 1.0, &r_emlrtDCI,
                  sp);
                FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
                  &t_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                                    (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
                  &u_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data
                  [((int32_T)(r + 1.0) + FLAGS_MATRIX->size[0] * ((int32_T)(y +
                  1.0) - 1)) - 1] & 253);
              }
            }

            /*  Set the current pixel charge to zero */
            if (current_flag_charge > 0.0) {
              st.site = &g_emlrtRSI;
              i1 = FLAGS_MATRIX->size[0];
              i2 = (int32_T)emlrtIntegerCheckFastR2012b(rows[p], &h_emlrtDCI,
                &st);
              emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &h_emlrtBCI, &st);
              i1 = FLAGS_MATRIX->size[1];
              i2 = (int32_T)emlrtIntegerCheckFastR2012b(cols[p], &g_emlrtDCI,
                &st);
              emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &g_emlrtBCI, &st);
              i1 = FLAGS_MATRIX->size[0];
              i2 = (int32_T)emlrtIntegerCheckFastR2012b(rows[p], &w_emlrtDCI, sp);
              i3 = FLAGS_MATRIX->size[1];
              i4 = (int32_T)emlrtIntegerCheckFastR2012b(cols[p], &x_emlrtDCI, sp);
              FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
                &ab_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                                  (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
                &bb_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data
                [((int32_T)rows[p] + FLAGS_MATRIX->size[0] * ((int32_T)cols[p] -
                1)) - 1] & 254);
            } else {
              if (current_flag_charge < 0.0) {
                st.site = &h_emlrtRSI;
                i1 = FLAGS_MATRIX->size[0];
                i2 = (int32_T)emlrtIntegerCheckFastR2012b(rows[p], &f_emlrtDCI,
                  &st);
                emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &f_emlrtBCI, &st);
                i1 = FLAGS_MATRIX->size[1];
                i2 = (int32_T)emlrtIntegerCheckFastR2012b(cols[p], &e_emlrtDCI,
                  &st);
                emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &e_emlrtBCI, &st);
                i1 = FLAGS_MATRIX->size[0];
                i2 = (int32_T)emlrtIntegerCheckFastR2012b(rows[p], &u_emlrtDCI,
                  sp);
                i3 = FLAGS_MATRIX->size[1];
                i4 = (int32_T)emlrtIntegerCheckFastR2012b(cols[p], &v_emlrtDCI,
                  sp);
                FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
                  &x_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                                    (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
                  &y_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data
                  [((int32_T)rows[p] + FLAGS_MATRIX->size[0] * ((int32_T)cols[p]
                  - 1)) - 1] & 253);
              }
            }

            /*  Place the anchor pixel on a branch cut. */
            st.site = &i_emlrtRSI;
            i1 = FLAGS_MATRIX->size[0];
            i2 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &d_emlrtDCI, &st);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &d_emlrtBCI, &st);
            i1 = FLAGS_MATRIX->size[1];
            i2 = (int32_T)emlrtIntegerCheckFastR2012b(y + 1.0, &c_emlrtDCI, &st);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &c_emlrtBCI, &st);
            i1 = FLAGS_MATRIX->size[0];
            i2 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &y_emlrtDCI, sp);
            i3 = FLAGS_MATRIX->size[1];
            i4 = (int32_T)emlrtIntegerCheckFastR2012b(y + 1.0, &ab_emlrtDCI, sp);
            FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
              &cb_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
              &db_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data
              [((int32_T)(r + 1.0) + FLAGS_MATRIX->size[0] * ((int32_T)(y + 1.0)
              - 1)) - 1] | 4);

            /*  Place the box pixel on a branch cut. */
            st.site = &j_emlrtRSI;
            i1 = FLAGS_MATRIX->size[0];
            i2 = (int32_T)emlrtIntegerCheckFastR2012b(rows[p], &b_emlrtDCI, &st);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &b_emlrtBCI, &st);
            i1 = FLAGS_MATRIX->size[1];
            i2 = (int32_T)emlrtIntegerCheckFastR2012b(cols[p], &emlrtDCI, &st);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &emlrtBCI, &st);
            i1 = FLAGS_MATRIX->size[0];
            i2 = (int32_T)emlrtIntegerCheckFastR2012b(rows[p], &bb_emlrtDCI, sp);
            i3 = FLAGS_MATRIX->size[1];
            i4 = (int32_T)emlrtIntegerCheckFastR2012b(cols[p], &cb_emlrtDCI, sp);
            FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
              &eb_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
              &fb_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data
              [((int32_T)rows[p] + FLAGS_MATRIX->size[0] * ((int32_T)cols[p] - 1))
              - 1] | 4);

            /*  Break the for-loop */
            exitg1 = true;
          } else {
            /*  End if net_charge == 0 */
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          p++;
          emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
        }
      }

      /*  End looping around surrounding pixels */
    }

    /*  end if(is_residue) */
    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&residue_locs);

  /*  End looping over all detected residues. */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (remove_dipoles.c) */
