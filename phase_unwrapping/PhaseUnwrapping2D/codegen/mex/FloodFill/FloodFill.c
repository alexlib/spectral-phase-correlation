/*
 * FloodFill.c
 *
 * Code generation for function 'FloodFill'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FloodFill.h"
#include "FloodFill_emxutil.h"
#include "unwrap.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "sqrt.h"
#include "power.h"
#include "rem.h"
#include "FloodFill_mexutil.h"
#include "FloodFill_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 15, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRSInfo b_emlrtRSI = { 19, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRSInfo c_emlrtRSI = { 27, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRSInfo d_emlrtRSI = { 32, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRSInfo e_emlrtRSI = { 33, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRSInfo f_emlrtRSI = { 57, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRSInfo g_emlrtRSI = { 59, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRSInfo h_emlrtRSI = { 164, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRSInfo i_emlrtRSI = { 41, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo j_emlrtRSI = { 230, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo q_emlrtRSI = { 16, "min",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/min.m" };

static emlrtRSInfo r_emlrtRSI = { 18, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo s_emlrtRSI = { 96, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo t_emlrtRSI = { 202, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo u_emlrtRSI = { 229, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo v_emlrtRSI = { 11, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtRSInfo w_emlrtRSI = { 26, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtRSInfo x_emlrtRSI = { 39, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtRSInfo gb_emlrtRSI = { 37, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtMCInfo emlrtMCI = { 123, 9, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtMCInfo b_emlrtMCI = { 122, 19, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtMCInfo c_emlrtMCI = { 239, 9, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtMCInfo f_emlrtMCI = { 41, 9, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtMCInfo g_emlrtMCI = { 38, 19, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtMCInfo h_emlrtMCI = { 82, 9, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtMCInfo i_emlrtMCI = { 81, 19, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtMCInfo j_emlrtMCI = { 14, 5, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtMCInfo l_emlrtMCI = { 168, 9, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo emlrtRTEI = { 7, 43, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRTEInfo b_emlrtRTEI = { 127, 5, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo c_emlrtRTEI = { 249, 13, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo d_emlrtRTEI = { 129, 5, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo e_emlrtRTEI = { 182, 13, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo f_emlrtRTEI = { 183, 13, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo g_emlrtRTEI = { 15, 1, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRTEInfo h_emlrtRTEI = { 19, 1, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRTEInfo i_emlrtRTEI = { 27, 1, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRTEInfo j_emlrtRTEI = { 44, 1, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRTEInfo k_emlrtRTEI = { 45, 1, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtRTEInfo l_emlrtRTEI = { 33, 6, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo n_emlrtRTEI = { 20, 9, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtECInfo emlrtECI = { -1, 20, 10, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtECInfo b_emlrtECI = { -1, 27, 10, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 57, 22, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 57, 33, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 68, 22, "r_adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 69, 22, "c_adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtECInfo c_emlrtECI = { -1, 51, 1, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m" };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 73, 44, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 73, 56, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 74, 50, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 74, 60, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 90, 44, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 90, 56, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 91, 50, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 91, 60, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 108, 44, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 108, 54, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 109, 50, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 109, 60, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 125, 44, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 125, 54, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 126, 50, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 126, 60, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 170, 14, "r_adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 171, 14, "c_adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 174, 36, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 174, 48, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 175, 42, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 175, 52, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 182, 36, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 182, 48, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 183, 42, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 183, 52, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 190, 36, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 190, 46, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 191, 42, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 191, 52, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 198, 36, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 198, 46, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 199, 42, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 199, 52, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtDCInfo emlrtDCI = { 127, 30, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m", 4 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 32, 10, "y_ind", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 33, 10, "x_ind", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 47, 8, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtDCInfo b_emlrtDCI = { 47, 8, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 1 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 47, 18, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 47, 18, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 1 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 48, 8, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtDCInfo d_emlrtDCI = { 48, 8, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 1 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 48, 18, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 49, 8, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtDCInfo e_emlrtDCI = { 49, 8, "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 1 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 49, 16, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 50, 8, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 50, 16, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 51, 14, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 51, 22, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 51, 39, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 51, 47, "IM_phase", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 52, 18, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 52, 26, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 173, 29, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 173, 41, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 176, 26, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 176, 36, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 177, 30, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 177, 40, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 178, 20, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 178, 30, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 181, 29, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 181, 41, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 184, 26, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 184, 36, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 185, 30, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 185, 40, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 186, 20, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 186, 30, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 189, 29, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 189, 39, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 192, 26, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 192, 36, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 193, 30, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 193, 40, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 194, 20, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 194, 30, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 197, 29, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 197, 39, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 200, 26, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 200, 36, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 201, 30, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 201, 40, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 202, 20, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 202, 30, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 157, 23, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 157, 25, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 158, 26, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 158, 30, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 158, 51, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 158, 55, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 158, 76, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 158, 78, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 158, 101, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 158, 103, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 159, 17, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 159, 19, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 72, 32, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 72, 44, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 72, 77, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 72, 89, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 75, 34, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 75, 44, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 76, 38, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 76, 48, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 77, 28, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 77, 38, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 78, 58, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 78, 70, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 78, 98, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 78, 110, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 79, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 79, 44, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 81, 58, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 81, 68, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 81, 98, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 81, 108, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 82, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 82, 42, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 84, 62, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 84, 72, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 84, 102, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 84, 112, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 85, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 85, 42, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 89, 32, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 89, 44, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 89, 77, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 89, 89, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 92, 34, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 92, 44, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 93, 38, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 93, 48, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 94, 28, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 94, 38, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 96, 63, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 96, 75, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 96, 103, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 96, 115, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 97, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 97, 44, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 99, 58, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 99, 68, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 99, 98, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 99, 108, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 100, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 100, 42, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 102, 62, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 102, 72, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 102, 102, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 102, 112, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 103, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 103, 42, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 107, 32, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 107, 42, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 107, 77, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 107, 87, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 110, 34, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 110, 44, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 111, 38, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 111, 48, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 112, 28, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 112, 38, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 113, 63, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 113, 75, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 113, 103, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 113, 115, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 114, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 114, 44, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 116, 58, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 116, 68, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 116, 98, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 116, 108, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 117, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 117, 42, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 119, 58, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 119, 70, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 119, 98, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 119, 110, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo fh_emlrtBCI = { -1, -1, 120, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo gh_emlrtBCI = { -1, -1, 120, 44, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 124, 32, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 124, 42, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 124, 77, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 124, 87, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 127, 34, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 127, 44, "IM_unwrapped", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 128, 38, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 128, 48, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 129, 28, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 129, 38, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo rh_emlrtBCI = { -1, -1, 130, 63, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 130, 75, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 130, 103, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 130, 115, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 131, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 131, 44, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 133, 62, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 133, 72, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 133, 102, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo bi_emlrtBCI = { -1, -1, 133, 112, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ci_emlrtBCI = { -1, -1, 134, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo di_emlrtBCI = { -1, -1, 134, 42, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ei_emlrtBCI = { -1, -1, 136, 58, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo fi_emlrtBCI = { -1, -1, 136, 70, "unwrapped_binary",
  "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo gi_emlrtBCI = { -1, -1, 136, 98, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo hi_emlrtBCI = { -1, -1, 136, 110, "branch_cuts", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ii_emlrtBCI = { -1, -1, 137, 32, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtBCInfo ji_emlrtBCI = { -1, -1, 137, 44, "adjoin", "FloodFill",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/PhaseUnwra"
  "pping2D/FloodFill.m", 0 };

static emlrtDCInfo f_emlrtDCI = { 20, 34, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 4
};

static emlrtRSInfo ib_emlrtRSI = { 14, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtRSInfo kb_emlrtRSI = { 168, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo lb_emlrtRSI = { 122, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo mb_emlrtRSI = { 81, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo nb_emlrtRSI = { 38, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo ob_emlrtRSI = { 239, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo pb_emlrtRSI = { 123, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo qb_emlrtRSI = { 82, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo rb_emlrtRSI = { 41, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

/* Function Declarations */
static void eml_li_find(const emlrtStack *sp, const emxArray_boolean_T *x,
  emxArray_int32_T *y);

/* Function Definitions */
static void eml_li_find(const emlrtStack *sp, const emxArray_boolean_T *x,
  emxArray_int32_T *y)
{
  int32_T n;
  int32_T k;
  boolean_T overflow;
  int32_T i;
  const mxArray *b_y;
  const mxArray *m2;
  int32_T j;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  n = x->size[0];
  st.site = &v_emlrtRSI;
  k = 0;
  b_st.site = &x_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      k++;
    }
  }

  if (k <= x->size[0]) {
  } else {
    b_y = NULL;
    m2 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&b_y, m2);
    st.site = &ib_emlrtRSI;
    error(&st, b_y, &j_emlrtMCI);
  }

  emlrtNonNegativeCheckFastR2012b(k, &f_emlrtDCI, sp);
  j = y->size[0];
  y->size[0] = k;
  emxEnsureCapacity(sp, (emxArray__common *)y, j, (int32_T)sizeof(int32_T),
                    &n_emlrtRTEI);
  j = 0;
  st.site = &w_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    b_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&b_st, true);
  }

  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      y->data[j] = i;
      j++;
    }
  }
}

void FloodFill(const emlrtStack *sp, const emxArray_real_T *IM_phase, const
               emxArray_uint8_T *branch_cuts, emxArray_real_T *IM_unwrapped,
               emxArray_real_T *rowref, emxArray_real_T *colref)
{
  emxArray_boolean_T *x;
  int32_T width;
  int32_T height;
  int32_T i0;
  int32_T loop_ub;
  int32_T nx;
  int32_T idx;
  boolean_T overflow;
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 36 };

  const mxArray *m0;
  char_T cv0[36];
  int32_T i;
  static const char_T cv1[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'f', 'i', 'n', 'd', '_', 'i', 'n', 'c', 'o', 'm',
    'p', 'a', 't', 'i', 'b', 'l', 'e', 'S', 'h', 'a', 'p', 'e' };

  emxArray_int32_T *ii;
  boolean_T b0;
  int32_T ixstart;
  boolean_T exitg7;
  boolean_T guard3 = false;
  const mxArray *b_y;
  emxArray_real_T *non_branch_cuts;
  emxArray_real_T *b_non_branch_cuts;
  emxArray_real_T *y_ind;
  int32_T i1;
  emxArray_real_T *c_non_branch_cuts;
  real_T xc;
  real_T yc;
  emxArray_real_T *r;
  emxArray_real_T *b_y_ind;
  emxArray_real_T *r_adjoin;
  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 36 };

  static const char_T cv2[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *d_y;
  static const int32_T iv2[2] = { 1, 39 };

  char_T cv3[39];
  static const char_T cv4[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  boolean_T exitg6;
  emxArray_boolean_T *b_r;
  const mxArray *e_y;
  static const int32_T iv3[2] = { 1, 36 };

  const mxArray *f_y;
  static const int32_T iv4[2] = { 1, 39 };

  boolean_T exitg5;
  emxArray_boolean_T *c_r;
  emxArray_real_T *unwrapped_binary;
  emxArray_real_T *adjoin;
  emxArray_int32_T *jj;
  emxArray_real_T *b_IM_phase;
  int32_T b_ii[2];
  int32_T c_IM_phase[2];
  int32_T count_limit;
  int32_T adjoin_stuck;
  emxArray_real_T *r0;
  emxArray_real_T *b_adjoin;
  int32_T exitg2;
  int32_T exitg3;
  const mxArray *g_y;
  static const int32_T iv5[2] = { 1, 36 };

  boolean_T exitg4;
  boolean_T guard2 = false;
  const mxArray *h_y;
  real_T dv0[2];
  boolean_T guard1 = false;
  const mxArray *i_y;
  static const int32_T iv6[2] = { 1, 36 };

  boolean_T exitg1;
  boolean_T b_guard1 = false;
  const mxArray *j_y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
  e_st.prev = &c_st;
  e_st.tls = c_st.tls;
  f_st.prev = &c_st;
  f_st.tls = c_st.tls;
  g_st.prev = &e_st;
  g_st.tls = e_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &x, 2, &emlrtRTEI, true);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  FloodFill.m unwraps the phase image, avoiding all branch cuts. */
  /*  Created by B.S. Spottiswoode on 12/10/2004 */
  /*  Last modified on 13/10/2004 */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  width = IM_phase->size[1];
  height = IM_phase->size[0];

  /*  figure; imagesc(immultiply(IM_phase, ~branch_cuts)), colormap(gray), axis square, axis off, title('Phase image'); */
  /*  uiwait(msgbox('Select a known true phase reference point','Phase reference point','modal')); */
  /*  [xref,yref] = ginput(1);  */
  /*  Determine the positions of the non-branch cut pixels */
  st.site = &emlrtRSI;
  i0 = x->size[0] * x->size[1];
  x->size[0] = branch_cuts->size[0];
  x->size[1] = branch_cuts->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)x, i0, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  loop_ub = branch_cuts->size[0] * branch_cuts->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    x->data[i0] = (branch_cuts->data[i0] < 1);
  }

  b_st.site = &i_emlrtRSI;
  nx = x->size[0] * x->size[1];
  idx = 0;
  if ((!((x->size[0] == 1) || (x->size[1] == 1))) || (x->size[0] != 1) ||
      (x->size[1] <= 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    for (i = 0; i < 36; i++) {
      cv0[i] = cv1[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 36, m0, cv0);
    emlrtAssign(&y, m0);
    c_st.site = &lb_emlrtRSI;
    d_st.site = &pb_emlrtRSI;
    error(&c_st, message(&d_st, y, &emlrtMCI), &b_emlrtMCI);
  }

  emxInit_int32_T(&b_st, &ii, 1, &l_emlrtRTEI, true);
  emlrtNonNegativeCheckFastR2012b(nx, &emlrtDCI, &b_st);
  i0 = ii->size[0];
  ii->size[0] = nx;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  c_st.site = &j_emlrtRSI;
  if (1 > nx) {
    b0 = false;
  } else {
    b0 = (nx > 2147483646);
  }

  if (b0) {
    e_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&e_st, true);
  }

  ixstart = 1;
  exitg7 = false;
  while ((!exitg7) && (ixstart <= nx)) {
    guard3 = false;
    if (x->data[ixstart - 1]) {
      idx++;
      ii->data[idx - 1] = ixstart;
      if (idx >= nx) {
        exitg7 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3) {
      ixstart++;
    }
  }

  emxFree_boolean_T(&x);
  if (idx <= nx) {
  } else {
    b_y = NULL;
    m0 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&b_y, m0);
    c_st.site = &ob_emlrtRSI;
    error(&c_st, b_y, &c_emlrtMCI);
  }

  if (nx == 1) {
    if (idx == 0) {
      i0 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
    }
  } else {
    i0 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                      &c_emlrtRTEI);
  }

  emxInit_real_T(&b_st, &non_branch_cuts, 1, &g_emlrtRTEI, true);
  i0 = non_branch_cuts->size[0];
  non_branch_cuts->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)non_branch_cuts, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = ii->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    non_branch_cuts->data[i0] = ii->data[i0];
  }

  emxInit_real_T(&st, &b_non_branch_cuts, 1, &emlrtRTEI, true);

  /*  Determine the row and column indices of these pixels */
  /*  [y_ind, x_ind] = ind2sub([height, width], non_branch_cuts); */
  i0 = b_non_branch_cuts->size[0];
  b_non_branch_cuts->size[0] = non_branch_cuts->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_non_branch_cuts, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = non_branch_cuts->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_non_branch_cuts->data[i0] = non_branch_cuts->data[i0] - 1.0;
  }

  emxInit_real_T(sp, &y_ind, 1, &h_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  b_rem(&st, b_non_branch_cuts, IM_phase->size[0], y_ind);
  i0 = y_ind->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)y_ind, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = y_ind->size[0];
  emxFree_real_T(&b_non_branch_cuts);
  for (i0 = 0; i0 < loop_ub; i0++) {
    y_ind->data[i0]++;
  }

  i0 = non_branch_cuts->size[0];
  i1 = y_ind->size[0];
  emlrtSizeEqCheck1DFastR2012b(i0, i1, &emlrtECI, sp);
  ixstart = IM_phase->size[0];
  i0 = non_branch_cuts->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)non_branch_cuts, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = non_branch_cuts->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    non_branch_cuts->data[i0] = (non_branch_cuts->data[i0] - y_ind->data[i0]) /
      (real_T)ixstart + 1.0;
  }

  emxInit_real_T(sp, &c_non_branch_cuts, 1, &emlrtRTEI, true);

  /*  Determine the center of the array */
  xc = (real_T)IM_phase->size[1] / 2.0;
  yc = (real_T)IM_phase->size[0] / 2.0;

  /*  Determine radial position of those points */
  i0 = c_non_branch_cuts->size[0];
  c_non_branch_cuts->size[0] = non_branch_cuts->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_non_branch_cuts, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = non_branch_cuts->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    c_non_branch_cuts->data[i0] = non_branch_cuts->data[i0] - xc;
  }

  emxInit_real_T(sp, &r, 1, &i_emlrtRTEI, true);
  emxInit_real_T(sp, &b_y_ind, 1, &emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  power(&st, c_non_branch_cuts, r);
  i0 = b_y_ind->size[0];
  b_y_ind->size[0] = y_ind->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_y_ind, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = y_ind->size[0];
  emxFree_real_T(&c_non_branch_cuts);
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_y_ind->data[i0] = y_ind->data[i0] - yc;
  }

  emxInit_real_T(sp, &r_adjoin, 1, &emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  power(&st, b_y_ind, r_adjoin);
  i0 = r->size[0];
  i1 = r_adjoin->size[0];
  emlrtSizeEqCheck1DFastR2012b(i0, i1, &b_emlrtECI, sp);
  i0 = r->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = r->size[0];
  emxFree_real_T(&b_y_ind);
  for (i0 = 0; i0 < loop_ub; i0++) {
    r->data[i0] += r_adjoin->data[i0];
  }

  st.site = &c_emlrtRSI;
  b_sqrt(&st, r);

  /*  This picks the unwrapping starting position */
  /*  At the non-branch cut pixel closest to the  */
  /*  center of the spectrum. */
  st.site = &d_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  c_st.site = &r_emlrtRSI;
  if ((r->size[0] == 1) || (r->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    c_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    for (i = 0; i < 36; i++) {
      cv0[i] = cv2[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m0, cv0);
    emlrtAssign(&c_y, m0);
    e_st.site = &nb_emlrtRSI;
    f_st.site = &rb_emlrtRSI;
    error(&e_st, message(&f_st, c_y, &f_emlrtMCI), &g_emlrtMCI);
  }

  if (r->size[0] > 0) {
  } else {
    d_y = NULL;
    m0 = emlrtCreateCharArray(2, iv2);
    for (i = 0; i < 39; i++) {
      cv3[i] = cv4[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m0, cv3);
    emlrtAssign(&d_y, m0);
    e_st.site = &mb_emlrtRSI;
    f_st.site = &qb_emlrtRSI;
    error(&e_st, message(&f_st, d_y, &h_emlrtMCI), &i_emlrtMCI);
  }

  e_st.site = &s_emlrtRSI;
  ixstart = 1;
  i = r->size[0];
  xc = r->data[0];
  if (r->size[0] > 1) {
    if (muDoubleScalarIsNaN(r->data[0])) {
      g_st.site = &t_emlrtRSI;
      overflow = (r->size[0] > 2147483646);
      if (overflow) {
        h_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&h_st, true);
      }

      nx = 2;
      exitg6 = false;
      while ((!exitg6) && (nx <= i)) {
        ixstart = nx;
        if (!muDoubleScalarIsNaN(r->data[nx - 1])) {
          xc = r->data[nx - 1];
          exitg6 = true;
        } else {
          nx++;
        }
      }
    }

    if (ixstart < r->size[0]) {
      g_st.site = &u_emlrtRSI;
      if (ixstart + 1 > r->size[0]) {
        overflow = false;
      } else {
        overflow = (r->size[0] > 2147483646);
      }

      if (overflow) {
        h_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&h_st, true);
      }

      while (ixstart + 1 <= i) {
        if (r->data[ixstart] < xc) {
          xc = r->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  b_emxInit_boolean_T(&e_st, &b_r, 1, &emlrtRTEI, true);
  i0 = b_r->size[0];
  b_r->size[0] = r->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_r, i0, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  loop_ub = r->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_r->data[i0] = (r->data[i0] == xc);
  }

  st.site = &d_emlrtRSI;
  eml_li_find(&st, b_r, ii);
  i0 = rowref->size[0];
  rowref->size[0] = ii->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)rowref, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = ii->size[0];
  emxFree_boolean_T(&b_r);
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = y_ind->size[0];
    idx = ii->data[i0];
    rowref->data[i0] = y_ind->data[emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1,
      &nb_emlrtBCI, sp) - 1];
  }

  st.site = &e_emlrtRSI;
  b_st.site = &q_emlrtRSI;
  c_st.site = &r_emlrtRSI;
  if ((r->size[0] == 1) || (r->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    e_y = NULL;
    m0 = emlrtCreateCharArray(2, iv3);
    for (i = 0; i < 36; i++) {
      cv0[i] = cv2[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m0, cv0);
    emlrtAssign(&e_y, m0);
    e_st.site = &nb_emlrtRSI;
    f_st.site = &rb_emlrtRSI;
    error(&e_st, message(&f_st, e_y, &f_emlrtMCI), &g_emlrtMCI);
  }

  if (r->size[0] > 0) {
  } else {
    f_y = NULL;
    m0 = emlrtCreateCharArray(2, iv4);
    for (i = 0; i < 39; i++) {
      cv3[i] = cv4[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m0, cv3);
    emlrtAssign(&f_y, m0);
    e_st.site = &mb_emlrtRSI;
    f_st.site = &qb_emlrtRSI;
    error(&e_st, message(&f_st, f_y, &h_emlrtMCI), &i_emlrtMCI);
  }

  e_st.site = &s_emlrtRSI;
  ixstart = 1;
  i = r->size[0];
  xc = r->data[0];
  if (r->size[0] > 1) {
    if (muDoubleScalarIsNaN(r->data[0])) {
      g_st.site = &t_emlrtRSI;
      overflow = (r->size[0] > 2147483646);
      if (overflow) {
        h_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&h_st, true);
      }

      nx = 2;
      exitg5 = false;
      while ((!exitg5) && (nx <= i)) {
        ixstart = nx;
        if (!muDoubleScalarIsNaN(r->data[nx - 1])) {
          xc = r->data[nx - 1];
          exitg5 = true;
        } else {
          nx++;
        }
      }
    }

    if (ixstart < r->size[0]) {
      g_st.site = &u_emlrtRSI;
      if (ixstart + 1 > r->size[0]) {
        overflow = false;
      } else {
        overflow = (r->size[0] > 2147483646);
      }

      if (overflow) {
        h_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&h_st, true);
      }

      while (ixstart + 1 <= i) {
        if (r->data[ixstart] < xc) {
          xc = r->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  b_emxInit_boolean_T(&e_st, &c_r, 1, &emlrtRTEI, true);
  i0 = c_r->size[0];
  c_r->size[0] = r->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_r, i0, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  loop_ub = r->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    c_r->data[i0] = (r->data[i0] == xc);
  }

  emxFree_real_T(&r);
  st.site = &e_emlrtRSI;
  eml_li_find(&st, c_r, ii);
  i0 = colref->size[0];
  colref->size[0] = ii->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)colref, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = ii->size[0];
  emxFree_boolean_T(&c_r);
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = non_branch_cuts->size[0];
    idx = ii->data[i0];
    colref->data[i0] = non_branch_cuts->data[emlrtDynamicBoundsCheckFastR2012b
      (idx, 1, i1, &ob_emlrtBCI, sp) - 1];
  }

  emxFree_real_T(&non_branch_cuts);

  /*  Flag specifying that the starting point corresponds */
  /*  to a branch cut */
  /*  branch_cut_start = branch_cuts(rowref, colref); */
  /*  if logical(branch_cut_start) */
  /*      error('Selected point corresponds to a branch cut.'); */
  /*  end */
  ixstart = IM_phase->size[0];
  i0 = IM_unwrapped->size[0] * IM_unwrapped->size[1];
  IM_unwrapped->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)IM_unwrapped, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ixstart = IM_phase->size[1];
  i0 = IM_unwrapped->size[0] * IM_unwrapped->size[1];
  IM_unwrapped->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)IM_unwrapped, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = IM_phase->size[0] * IM_phase->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    IM_unwrapped->data[i0] = 0.0;
  }

  b_emxInit_real_T(sp, &unwrapped_binary, 2, &j_emlrtRTEI, true);
  ixstart = IM_phase->size[0];
  i0 = unwrapped_binary->size[0] * unwrapped_binary->size[1];
  unwrapped_binary->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)unwrapped_binary, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  ixstart = IM_phase->size[1];
  i0 = unwrapped_binary->size[0] * unwrapped_binary->size[1];
  unwrapped_binary->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)unwrapped_binary, i0, (int32_T)
                    sizeof(real_T), &emlrtRTEI);
  loop_ub = IM_phase->size[0] * IM_phase->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    unwrapped_binary->data[i0] = 0.0;
  }

  b_emxInit_real_T(sp, &adjoin, 2, &k_emlrtRTEI, true);
  ixstart = IM_phase->size[0];
  i0 = adjoin->size[0] * adjoin->size[1];
  adjoin->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)adjoin, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  ixstart = IM_phase->size[1];
  i0 = adjoin->size[0] * adjoin->size[1];
  adjoin->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)adjoin, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = IM_phase->size[0] * IM_phase->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    adjoin->data[i0] = 0.0;
  }

  ixstart = IM_phase->size[0];
  i0 = ii->size[0];
  ii->size[0] = rowref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = rowref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    xc = rowref->data[i0] - 1.0;
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(xc, &b_emlrtDCI, sp);
    ii->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i1, 1, ixstart,
      &pb_emlrtBCI, sp);
  }

  emxInit_int32_T(sp, &jj, 1, &emlrtRTEI, true);
  ixstart = IM_phase->size[1];
  i0 = jj->size[0];
  jj->size[0] = colref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)jj, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = colref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    xc = colref->data[i0];
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(xc, &c_emlrtDCI, sp);
    jj->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i1, 1, ixstart,
      &qb_emlrtBCI, sp);
  }

  ixstart = ii->size[0];
  i = jj->size[0];
  for (i0 = 0; i0 < i; i0++) {
    for (i1 = 0; i1 < ixstart; i1++) {
      adjoin->data[(ii->data[i1] + adjoin->size[0] * (jj->data[i0] - 1)) - 1] =
        1.0;
    }
  }

  /* Label the first four adjoining pixels */
  i0 = ii->size[0];
  ii->size[0] = rowref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = rowref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = adjoin->size[0];
    xc = rowref->data[i0] + 1.0;
    idx = (int32_T)emlrtIntegerCheckFastR2012b(xc, &d_emlrtDCI, sp);
    ii->data[i0] = emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1, &rb_emlrtBCI,
      sp);
  }

  i0 = jj->size[0];
  jj->size[0] = colref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)jj, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = colref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = adjoin->size[1];
    idx = (int32_T)colref->data[i0];
    jj->data[i0] = emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1, &sb_emlrtBCI,
      sp);
  }

  ixstart = ii->size[0];
  i = jj->size[0];
  for (i0 = 0; i0 < i; i0++) {
    for (i1 = 0; i1 < ixstart; i1++) {
      adjoin->data[(ii->data[i1] + adjoin->size[0] * (jj->data[i0] - 1)) - 1] =
        1.0;
    }
  }

  i0 = ii->size[0];
  ii->size[0] = rowref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = rowref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = adjoin->size[0];
    xc = rowref->data[i0];
    idx = (int32_T)emlrtIntegerCheckFastR2012b(xc, &e_emlrtDCI, sp);
    ii->data[i0] = emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1, &tb_emlrtBCI,
      sp);
  }

  i0 = jj->size[0];
  jj->size[0] = colref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)jj, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = colref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = adjoin->size[1];
    idx = (int32_T)(colref->data[i0] - 1.0);
    jj->data[i0] = emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1, &ub_emlrtBCI,
      sp);
  }

  ixstart = ii->size[0];
  i = jj->size[0];
  for (i0 = 0; i0 < i; i0++) {
    for (i1 = 0; i1 < ixstart; i1++) {
      adjoin->data[(ii->data[i1] + adjoin->size[0] * (jj->data[i0] - 1)) - 1] =
        1.0;
    }
  }

  i0 = ii->size[0];
  ii->size[0] = rowref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = rowref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = adjoin->size[0];
    idx = (int32_T)rowref->data[i0];
    ii->data[i0] = emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1, &vb_emlrtBCI,
      sp);
  }

  i0 = jj->size[0];
  jj->size[0] = colref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)jj, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = colref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = adjoin->size[1];
    idx = (int32_T)(colref->data[i0] + 1.0);
    jj->data[i0] = emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1, &wb_emlrtBCI,
      sp);
  }

  ixstart = ii->size[0];
  i = jj->size[0];
  for (i0 = 0; i0 < i; i0++) {
    for (i1 = 0; i1 < ixstart; i1++) {
      adjoin->data[(ii->data[i1] + adjoin->size[0] * (jj->data[i0] - 1)) - 1] =
        1.0;
    }
  }

  ixstart = IM_phase->size[0];
  i0 = ii->size[0];
  ii->size[0] = rowref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = rowref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = (int32_T)rowref->data[i0];
    ii->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i1, 1, ixstart,
      &xb_emlrtBCI, sp) - 1;
  }

  ixstart = IM_phase->size[1];
  i0 = jj->size[0];
  jj->size[0] = colref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)jj, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = colref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = (int32_T)colref->data[i0];
    jj->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i1, 1, ixstart,
      &yb_emlrtBCI, sp) - 1;
  }

  loop_ub = rowref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = IM_phase->size[0];
    idx = (int32_T)rowref->data[i0];
    emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1, &ac_emlrtBCI, sp);
  }

  loop_ub = colref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = IM_phase->size[1];
    idx = (int32_T)colref->data[i0];
    emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1, &bc_emlrtBCI, sp);
  }

  b_emxInit_real_T(sp, &b_IM_phase, 2, &emlrtRTEI, true);
  b_ii[0] = ii->size[0];
  b_ii[1] = jj->size[0];
  i0 = b_IM_phase->size[0] * b_IM_phase->size[1];
  b_IM_phase->size[0] = rowref->size[0];
  b_IM_phase->size[1] = colref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_IM_phase, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = colref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i = rowref->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_IM_phase->data[i1 + b_IM_phase->size[0] * i0] = IM_phase->data[((int32_T)
        rowref->data[i1] + IM_phase->size[0] * ((int32_T)colref->data[i0] - 1))
        - 1];
    }
  }

  for (i0 = 0; i0 < 2; i0++) {
    c_IM_phase[i0] = b_IM_phase->size[i0];
  }

  emxFree_real_T(&b_IM_phase);
  emlrtSubAssignSizeCheckR2012b(b_ii, 2, c_IM_phase, 2, &c_emlrtECI, sp);
  loop_ub = colref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i = rowref->size[0];
    for (i1 = 0; i1 < i; i1++) {
      IM_unwrapped->data[ii->data[i1] + IM_unwrapped->size[0] * jj->data[i0]] =
        IM_phase->data[((int32_T)rowref->data[i1] + IM_phase->size[0] *
                        ((int32_T)colref->data[i0] - 1)) - 1];
    }
  }

  /* Mark the first pixel as unwrapped */
  ixstart = IM_phase->size[0];
  i0 = ii->size[0];
  ii->size[0] = rowref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = rowref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = (int32_T)rowref->data[i0];
    ii->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i1, 1, ixstart,
      &cc_emlrtBCI, sp);
  }

  ixstart = IM_phase->size[1];
  i0 = jj->size[0];
  jj->size[0] = colref->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)jj, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  loop_ub = colref->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = (int32_T)colref->data[i0];
    jj->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i1, 1, ixstart,
      &dc_emlrtBCI, sp);
  }

  ixstart = ii->size[0];
  i = jj->size[0];
  for (i0 = 0; i0 < i; i0++) {
    for (i1 = 0; i1 < ixstart; i1++) {
      unwrapped_binary->data[(ii->data[i1] + unwrapped_binary->size[0] *
        (jj->data[i0] - 1)) - 1] = 1.0;
    }
  }

  /*  disp('Performing floodfill operation ...'); */
  count_limit = 0;
  adjoin_stuck = 0;
  b_emxInit_real_T(sp, &r0, 2, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &b_adjoin, 2, &emlrtRTEI, true);
  do {
    exitg2 = 0;
    if (2 > height - 1) {
      i0 = 0;
      i1 = 0;
    } else {
      i0 = adjoin->size[0];
      emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &emlrtBCI, sp);
      i0 = 1;
      i1 = adjoin->size[0];
      idx = height - 1;
      i1 = emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1, &emlrtBCI, sp);
    }

    if (2 > width - 1) {
      idx = 0;
      nx = 0;
    } else {
      idx = adjoin->size[1];
      emlrtDynamicBoundsCheckFastR2012b(2, 1, idx, &b_emlrtBCI, sp);
      idx = 1;
      nx = adjoin->size[1];
      ixstart = width - 1;
      nx = emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, nx, &b_emlrtBCI, sp);
    }

    ixstart = b_adjoin->size[0] * b_adjoin->size[1];
    b_adjoin->size[0] = i1 - i0;
    b_adjoin->size[1] = nx - idx;
    emxEnsureCapacity(sp, (emxArray__common *)b_adjoin, ixstart, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = nx - idx;
    for (nx = 0; nx < loop_ub; nx++) {
      i = i1 - i0;
      for (ixstart = 0; ixstart < i; ixstart++) {
        b_adjoin->data[ixstart + b_adjoin->size[0] * nx] = adjoin->data[(i0 +
          ixstart) + adjoin->size[0] * (idx + nx)];
      }
    }

    st.site = &f_emlrtRSI;
    sum(&st, b_adjoin, r0);
    st.site = &f_emlrtRSI;
    if (b_sum(&st, r0) != 0.0) {
      /* Loop until there are no adjoining pixels or they all lie on the border */
      do {
        exitg3 = 0;
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
        if (count_limit < 100) {
          /* or the code gets stuck because of isolated regions */
          st.site = &g_emlrtRSI;
          b_st.site = &gb_emlrtRSI;
          nx = adjoin->size[0] * adjoin->size[1];
          idx = 0;
          if ((!((adjoin->size[0] == 1) || (adjoin->size[1] == 1))) ||
              (adjoin->size[0] != 1) || (adjoin->size[1] <= 1)) {
            overflow = true;
          } else {
            overflow = false;
          }

          if (overflow) {
          } else {
            g_y = NULL;
            m0 = emlrtCreateCharArray(2, iv5);
            for (i = 0; i < 36; i++) {
              cv0[i] = cv1[i];
            }

            emlrtInitCharArrayR2013a(&b_st, 36, m0, cv0);
            emlrtAssign(&g_y, m0);
            c_st.site = &lb_emlrtRSI;
            d_st.site = &pb_emlrtRSI;
            error(&c_st, message(&d_st, g_y, &emlrtMCI), &b_emlrtMCI);
          }

          emlrtNonNegativeCheckFastR2012b(nx, &emlrtDCI, &b_st);
          i0 = ii->size[0];
          ii->size[0] = nx;
          emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                            (int32_T), &b_emlrtRTEI);
          i0 = jj->size[0];
          jj->size[0] = nx;
          emxEnsureCapacity(&b_st, (emxArray__common *)jj, i0, (int32_T)sizeof
                            (int32_T), &d_emlrtRTEI);
          if (nx == 0) {
            i0 = ii->size[0];
            ii->size[0] = 0;
            emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                              (int32_T), &emlrtRTEI);
            i0 = jj->size[0];
            jj->size[0] = 0;
            emxEnsureCapacity(&b_st, (emxArray__common *)jj, i0, (int32_T)sizeof
                              (int32_T), &emlrtRTEI);
          } else {
            ixstart = 1;
            i = 1;
            exitg4 = false;
            while ((!exitg4) && (i <= adjoin->size[1])) {
              guard2 = false;
              if (adjoin->data[(ixstart + adjoin->size[0] * (i - 1)) - 1] != 0.0)
              {
                idx++;
                ii->data[idx - 1] = ixstart;
                jj->data[idx - 1] = i;
                if (idx >= nx) {
                  exitg4 = true;
                } else {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }

              if (guard2) {
                ixstart++;
                if (ixstart > adjoin->size[0]) {
                  ixstart = 1;
                  i++;
                }
              }
            }

            if (idx <= nx) {
            } else {
              h_y = NULL;
              m0 = emlrtCreateString("Assertion failed.");
              emlrtAssign(&h_y, m0);
              c_st.site = &kb_emlrtRSI;
              error(&c_st, h_y, &l_emlrtMCI);
            }

            if (nx == 1) {
              if (idx == 0) {
                i0 = ii->size[0];
                ii->size[0] = 0;
                emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)
                                  sizeof(int32_T), &emlrtRTEI);
                i0 = jj->size[0];
                jj->size[0] = 0;
                emxEnsureCapacity(&b_st, (emxArray__common *)jj, i0, (int32_T)
                                  sizeof(int32_T), &emlrtRTEI);
              }
            } else {
              i0 = ii->size[0];
              if (1 > idx) {
                ii->size[0] = 0;
              } else {
                ii->size[0] = idx;
              }

              emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)
                                sizeof(int32_T), &e_emlrtRTEI);
              i0 = jj->size[0];
              if (1 > idx) {
                jj->size[0] = 0;
              } else {
                jj->size[0] = idx;
              }

              emxEnsureCapacity(&b_st, (emxArray__common *)jj, i0, (int32_T)
                                sizeof(int32_T), &f_emlrtRTEI);
            }
          }

          i0 = r_adjoin->size[0];
          r_adjoin->size[0] = ii->size[0];
          emxEnsureCapacity(&st, (emxArray__common *)r_adjoin, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          loop_ub = ii->size[0];
          for (i0 = 0; i0 < loop_ub; i0++) {
            r_adjoin->data[i0] = ii->data[i0];
          }

          i0 = y_ind->size[0];
          y_ind->size[0] = jj->size[0];
          emxEnsureCapacity(&st, (emxArray__common *)y_ind, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = jj->size[0];
          for (i0 = 0; i0 < loop_ub; i0++) {
            y_ind->data[i0] = jj->data[i0];
          }

          /* Obtain coordinates of adjoining unwrapped phase pixels */
          if (r_adjoin->size[0] == adjoin_stuck) {
            count_limit++;

            /* Make sure loop doesn't get stuck */
          } else {
            count_limit = 0;
          }

          adjoin_stuck = r_adjoin->size[0];
          i = 0;
          while (i <= r_adjoin->size[0] - 1) {
            i0 = r_adjoin->size[0];
            i1 = i + 1;
            emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &c_emlrtBCI, sp);
            i0 = y_ind->size[0];
            i1 = i + 1;
            emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &d_emlrtBCI, sp);
            if (((int32_T)r_adjoin->data[i] <= height - 1) && (r_adjoin->data[i]
                 >= 2.0) && ((int32_T)y_ind->data[i] <= width - 1) &&
                (y_ind->data[i] >= 2.0)) {
              /* Ignore pixels near the border */
              /* First search below for an adjoining unwrapped phase pixel */
              i0 = branch_cuts->size[0];
              i1 = (int32_T)(r_adjoin->data[i] + 1.0);
              idx = branch_cuts->size[1];
              nx = (int32_T)y_ind->data[i];
              if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                    &xd_emlrtBCI, sp) + branch_cuts->size[0] *
                                     (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                     idx, &yd_emlrtBCI, sp) - 1)) - 1] == 0) {
                i0 = unwrapped_binary->size[0];
                i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                idx = unwrapped_binary->size[1];
                nx = (int32_T)y_ind->data[i];
                if (unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1,
                      1, i0, &ae_emlrtBCI, sp) + unwrapped_binary->size[0] *
                     (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &be_emlrtBCI,
                       sp) - 1)) - 1] == 1.0) {
                  i0 = IM_unwrapped->size[0];
                  i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &e_emlrtBCI, sp);
                  i0 = IM_unwrapped->size[1];
                  i1 = (int32_T)y_ind->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &f_emlrtBCI, sp);

                  /* Obtain the reference unwrapped phase */
                  i0 = IM_phase->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &g_emlrtBCI, sp);
                  i0 = IM_phase->size[1];
                  i1 = (int32_T)y_ind->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &h_emlrtBCI, sp);

                  /* Unwrap the active pixel */
                  dv0[0] = IM_unwrapped->data[((int32_T)(r_adjoin->data[i] + 1.0)
                    + IM_unwrapped->size[0] * ((int32_T)y_ind->data[i] - 1)) - 1];
                  dv0[1] = IM_phase->data[((int32_T)r_adjoin->data[i] +
                    IM_phase->size[0] * ((int32_T)y_ind->data[i] - 1)) - 1];
                  unwrap(dv0);
                  i0 = IM_unwrapped->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = IM_unwrapped->size[1];
                  nx = (int32_T)y_ind->data[i];
                  IM_unwrapped->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                    i0, &ce_emlrtBCI, sp) + IM_unwrapped->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    idx, &de_emlrtBCI, sp) - 1)) - 1] = dv0[1];
                  i0 = unwrapped_binary->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = unwrapped_binary->size[1];
                  nx = (int32_T)y_ind->data[i];
                  unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1,
                    1, i0, &ee_emlrtBCI, sp) + unwrapped_binary->size[0] *
                    (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &fe_emlrtBCI,
                    sp) - 1)) - 1] = 1.0;

                  /* Mark the pixel as unwrapped */
                  i0 = adjoin->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = adjoin->size[1];
                  nx = (int32_T)y_ind->data[i];
                  adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                    &ge_emlrtBCI, sp) + adjoin->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                    &he_emlrtBCI, sp) - 1)) - 1] = 0.0;

                  /* Remove it from the list of adjoining pixels */
                  if (r_adjoin->data[i] - 1.0 >= 1.0) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)y_ind->data[i];
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &ie_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &je_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                      idx = branch_cuts->size[1];
                      nx = (int32_T)y_ind->data[i];
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &ke_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &le_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                        idx = adjoin->size[1];
                        nx = (int32_T)y_ind->data[i];
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &me_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &ne_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }

                  if (y_ind->data[i] - 1.0 >= 1.0) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)r_adjoin->data[i];
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)(y_ind->data[i] - 1.0);
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &oe_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &pe_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)r_adjoin->data[i];
                      idx = branch_cuts->size[1];
                      nx = (int32_T)(y_ind->data[i] - 1.0);
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &qe_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &re_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)r_adjoin->data[i];
                        idx = adjoin->size[1];
                        nx = (int32_T)(y_ind->data[i] - 1.0);
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &se_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &te_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }

                  if (y_ind->data[i] + 1.0 <= width) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)r_adjoin->data[i];
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)(y_ind->data[i] + 1.0);
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &ue_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &ve_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)r_adjoin->data[i];
                      idx = branch_cuts->size[1];
                      nx = (int32_T)(y_ind->data[i] + 1.0);
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &we_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &xe_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)r_adjoin->data[i];
                        idx = adjoin->size[1];
                        nx = (int32_T)(y_ind->data[i] + 1.0);
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &ye_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &af_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }
                }
              }

              /* Then search above */
              i0 = branch_cuts->size[0];
              i1 = (int32_T)(r_adjoin->data[i] - 1.0);
              idx = branch_cuts->size[1];
              nx = (int32_T)y_ind->data[i];
              if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                    &bf_emlrtBCI, sp) + branch_cuts->size[0] *
                                     (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                     idx, &cf_emlrtBCI, sp) - 1)) - 1] == 0) {
                i0 = unwrapped_binary->size[0];
                i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                idx = unwrapped_binary->size[1];
                nx = (int32_T)y_ind->data[i];
                if (unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1,
                      1, i0, &df_emlrtBCI, sp) + unwrapped_binary->size[0] *
                     (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &ef_emlrtBCI,
                       sp) - 1)) - 1] == 1.0) {
                  i0 = IM_unwrapped->size[0];
                  i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &i_emlrtBCI, sp);
                  i0 = IM_unwrapped->size[1];
                  i1 = (int32_T)y_ind->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &j_emlrtBCI, sp);

                  /* Obtain the reference unwrapped phase */
                  i0 = IM_phase->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &k_emlrtBCI, sp);
                  i0 = IM_phase->size[1];
                  i1 = (int32_T)y_ind->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &l_emlrtBCI, sp);

                  /* Unwrap the active pixel */
                  dv0[0] = IM_unwrapped->data[((int32_T)(r_adjoin->data[i] - 1.0)
                    + IM_unwrapped->size[0] * ((int32_T)y_ind->data[i] - 1)) - 1];
                  dv0[1] = IM_phase->data[((int32_T)r_adjoin->data[i] +
                    IM_phase->size[0] * ((int32_T)y_ind->data[i] - 1)) - 1];
                  unwrap(dv0);
                  i0 = IM_unwrapped->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = IM_unwrapped->size[1];
                  nx = (int32_T)y_ind->data[i];
                  IM_unwrapped->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                    i0, &ff_emlrtBCI, sp) + IM_unwrapped->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    idx, &gf_emlrtBCI, sp) - 1)) - 1] = dv0[1];
                  i0 = unwrapped_binary->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = unwrapped_binary->size[1];
                  nx = (int32_T)y_ind->data[i];
                  unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1,
                    1, i0, &hf_emlrtBCI, sp) + unwrapped_binary->size[0] *
                    (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &if_emlrtBCI,
                    sp) - 1)) - 1] = 1.0;

                  /* Mark the pixel as unwrapped */
                  i0 = adjoin->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = adjoin->size[1];
                  nx = (int32_T)y_ind->data[i];
                  adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                    &jf_emlrtBCI, sp) + adjoin->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                    &kf_emlrtBCI, sp) - 1)) - 1] = 0.0;

                  /* Remove it from the list of adjoining pixels */
                  /* Update the new adjoining pixels: */
                  if (r_adjoin->data[i] + 1.0 <= height) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)y_ind->data[i];
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &lf_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &mf_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                      idx = branch_cuts->size[1];
                      nx = (int32_T)y_ind->data[i];
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &nf_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &of_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                        idx = adjoin->size[1];
                        nx = (int32_T)y_ind->data[i];
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &pf_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &qf_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }

                  if (y_ind->data[i] - 1.0 >= 1.0) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)r_adjoin->data[i];
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)(y_ind->data[i] - 1.0);
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &rf_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &sf_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)r_adjoin->data[i];
                      idx = branch_cuts->size[1];
                      nx = (int32_T)(y_ind->data[i] - 1.0);
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &tf_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &uf_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)r_adjoin->data[i];
                        idx = adjoin->size[1];
                        nx = (int32_T)(y_ind->data[i] - 1.0);
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &vf_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &wf_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }

                  if (y_ind->data[i] + 1.0 <= width) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)r_adjoin->data[i];
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)(y_ind->data[i] + 1.0);
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &xf_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &yf_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)r_adjoin->data[i];
                      idx = branch_cuts->size[1];
                      nx = (int32_T)(y_ind->data[i] + 1.0);
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &ag_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &bg_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)r_adjoin->data[i];
                        idx = adjoin->size[1];
                        nx = (int32_T)(y_ind->data[i] + 1.0);
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &cg_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &dg_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }
                }
              }

              /* Then search on the right */
              i0 = branch_cuts->size[0];
              i1 = (int32_T)r_adjoin->data[i];
              idx = branch_cuts->size[1];
              nx = (int32_T)(y_ind->data[i] + 1.0);
              if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                    &eg_emlrtBCI, sp) + branch_cuts->size[0] *
                                     (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                     idx, &fg_emlrtBCI, sp) - 1)) - 1] == 0) {
                i0 = unwrapped_binary->size[0];
                i1 = (int32_T)r_adjoin->data[i];
                idx = unwrapped_binary->size[1];
                nx = (int32_T)(y_ind->data[i] + 1.0);
                if (unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1,
                      1, i0, &gg_emlrtBCI, sp) + unwrapped_binary->size[0] *
                     (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &hg_emlrtBCI,
                       sp) - 1)) - 1] == 1.0) {
                  i0 = IM_unwrapped->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &m_emlrtBCI, sp);
                  i0 = IM_unwrapped->size[1];
                  i1 = (int32_T)(y_ind->data[i] + 1.0);
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &n_emlrtBCI, sp);

                  /* Obtain the reference unwrapped phase */
                  i0 = IM_phase->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &o_emlrtBCI, sp);
                  i0 = IM_phase->size[1];
                  i1 = (int32_T)y_ind->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &p_emlrtBCI, sp);

                  /* Unwrap the active pixel */
                  dv0[0] = IM_unwrapped->data[((int32_T)r_adjoin->data[i] +
                    IM_unwrapped->size[0] * ((int32_T)(y_ind->data[i] + 1.0) - 1))
                    - 1];
                  dv0[1] = IM_phase->data[((int32_T)r_adjoin->data[i] +
                    IM_phase->size[0] * ((int32_T)y_ind->data[i] - 1)) - 1];
                  unwrap(dv0);
                  i0 = IM_unwrapped->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = IM_unwrapped->size[1];
                  nx = (int32_T)y_ind->data[i];
                  IM_unwrapped->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                    i0, &ig_emlrtBCI, sp) + IM_unwrapped->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    idx, &jg_emlrtBCI, sp) - 1)) - 1] = dv0[1];
                  i0 = unwrapped_binary->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = unwrapped_binary->size[1];
                  nx = (int32_T)y_ind->data[i];
                  unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1,
                    1, i0, &kg_emlrtBCI, sp) + unwrapped_binary->size[0] *
                    (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &lg_emlrtBCI,
                    sp) - 1)) - 1] = 1.0;

                  /* Mark the pixel as unwrapped */
                  i0 = adjoin->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = adjoin->size[1];
                  nx = (int32_T)y_ind->data[i];
                  adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                    &mg_emlrtBCI, sp) + adjoin->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                    &ng_emlrtBCI, sp) - 1)) - 1] = 0.0;

                  /* Remove it from the list of adjoining pixels */
                  if (r_adjoin->data[i] + 1.0 <= height) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)y_ind->data[i];
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &og_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &pg_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                      idx = branch_cuts->size[1];
                      nx = (int32_T)y_ind->data[i];
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &qg_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &rg_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                        idx = adjoin->size[1];
                        nx = (int32_T)y_ind->data[i];
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &sg_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &tg_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }

                  if (y_ind->data[i] - 1.0 >= 1.0) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)r_adjoin->data[i];
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)(y_ind->data[i] - 1.0);
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &ug_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &vg_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)r_adjoin->data[i];
                      idx = branch_cuts->size[1];
                      nx = (int32_T)(y_ind->data[i] - 1.0);
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &wg_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &xg_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)r_adjoin->data[i];
                        idx = adjoin->size[1];
                        nx = (int32_T)(y_ind->data[i] - 1.0);
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &yg_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &ah_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }

                  if (r_adjoin->data[i] - 1.0 >= 1.0) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)y_ind->data[i];
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &bh_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &ch_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                      idx = branch_cuts->size[1];
                      nx = (int32_T)y_ind->data[i];
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &dh_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &eh_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                        idx = adjoin->size[1];
                        nx = (int32_T)y_ind->data[i];
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &fh_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &gh_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }
                }
              }

              /* Finally search on the left */
              i0 = branch_cuts->size[0];
              i1 = (int32_T)r_adjoin->data[i];
              idx = branch_cuts->size[1];
              nx = (int32_T)(y_ind->data[i] - 1.0);
              if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                    &hh_emlrtBCI, sp) + branch_cuts->size[0] *
                                     (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                     idx, &ih_emlrtBCI, sp) - 1)) - 1] == 0) {
                i0 = unwrapped_binary->size[0];
                i1 = (int32_T)r_adjoin->data[i];
                idx = unwrapped_binary->size[1];
                nx = (int32_T)(y_ind->data[i] - 1.0);
                if (unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1,
                      1, i0, &jh_emlrtBCI, sp) + unwrapped_binary->size[0] *
                     (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &kh_emlrtBCI,
                       sp) - 1)) - 1] == 1.0) {
                  i0 = IM_unwrapped->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &q_emlrtBCI, sp);
                  i0 = IM_unwrapped->size[1];
                  i1 = (int32_T)(y_ind->data[i] - 1.0);
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &r_emlrtBCI, sp);

                  /* Obtain the reference unwrapped phase */
                  i0 = IM_phase->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &s_emlrtBCI, sp);
                  i0 = IM_phase->size[1];
                  i1 = (int32_T)y_ind->data[i];
                  emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &t_emlrtBCI, sp);

                  /* Unwrap the active pixel */
                  dv0[0] = IM_unwrapped->data[((int32_T)r_adjoin->data[i] +
                    IM_unwrapped->size[0] * ((int32_T)(y_ind->data[i] - 1.0) - 1))
                    - 1];
                  dv0[1] = IM_phase->data[((int32_T)r_adjoin->data[i] +
                    IM_phase->size[0] * ((int32_T)y_ind->data[i] - 1)) - 1];
                  unwrap(dv0);
                  i0 = IM_unwrapped->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = IM_unwrapped->size[1];
                  nx = (int32_T)y_ind->data[i];
                  IM_unwrapped->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                    i0, &lh_emlrtBCI, sp) + IM_unwrapped->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    idx, &mh_emlrtBCI, sp) - 1)) - 1] = dv0[1];
                  i0 = unwrapped_binary->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = unwrapped_binary->size[1];
                  nx = (int32_T)y_ind->data[i];
                  unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1,
                    1, i0, &nh_emlrtBCI, sp) + unwrapped_binary->size[0] *
                    (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &oh_emlrtBCI,
                    sp) - 1)) - 1] = 1.0;

                  /* Mark the pixel as unwrapped */
                  i0 = adjoin->size[0];
                  i1 = (int32_T)r_adjoin->data[i];
                  idx = adjoin->size[1];
                  nx = (int32_T)y_ind->data[i];
                  adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                    &ph_emlrtBCI, sp) + adjoin->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                    &qh_emlrtBCI, sp) - 1)) - 1] = 0.0;

                  /* Remove it from the list of adjoining pixels */
                  if (r_adjoin->data[i] + 1.0 <= height) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)y_ind->data[i];
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &rh_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &sh_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                      idx = branch_cuts->size[1];
                      nx = (int32_T)y_ind->data[i];
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &th_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &uh_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)(r_adjoin->data[i] + 1.0);
                        idx = adjoin->size[1];
                        nx = (int32_T)y_ind->data[i];
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &vh_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &wh_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }

                  if (y_ind->data[i] + 1.0 <= width) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)r_adjoin->data[i];
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)(y_ind->data[i] + 1.0);
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &xh_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &yh_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)r_adjoin->data[i];
                      idx = branch_cuts->size[1];
                      nx = (int32_T)(y_ind->data[i] + 1.0);
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &ai_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &bi_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)r_adjoin->data[i];
                        idx = adjoin->size[1];
                        nx = (int32_T)(y_ind->data[i] + 1.0);
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &ci_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &di_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }

                  if (r_adjoin->data[i] - 1.0 >= 1.0) {
                    i0 = unwrapped_binary->size[0];
                    i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                    idx = unwrapped_binary->size[1];
                    nx = (int32_T)y_ind->data[i];
                    if (unwrapped_binary->data
                        [(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                          &ei_emlrtBCI, sp) + unwrapped_binary->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
                           &fi_emlrtBCI, sp) - 1)) - 1] == 0.0) {
                      i0 = branch_cuts->size[0];
                      i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                      idx = branch_cuts->size[1];
                      nx = (int32_T)y_ind->data[i];
                      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b
                                             (i1, 1, i0, &gi_emlrtBCI, sp) +
                                             branch_cuts->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (nx, 1, idx, &hi_emlrtBCI, sp) - 1))
                          - 1] == 0) {
                        i0 = adjoin->size[0];
                        i1 = (int32_T)(r_adjoin->data[i] - 1.0);
                        idx = adjoin->size[1];
                        nx = (int32_T)y_ind->data[i];
                        adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1,
                          i0, &ii_emlrtBCI, sp) + adjoin->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                          idx, &ji_emlrtBCI, sp) - 1)) - 1] = 1.0;
                      }
                    }
                  }
                }
              }
            }

            i++;
            emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
          }

          /* figure; imagesc(adjoin), colormap(gray), axis square, axis off, title('Adjoining pixels'); */
          /* figure; imagesc(IM_unwrapped), colormap(gray), axis square, axis off, title('Pixels unwrapped'); */
          emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  emxFree_real_T(&b_adjoin);
  emxFree_real_T(&r0);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Finally, fill in the branch cut pixels that adjoin the unwrapped pixels. */
  /*  This can be done because the branch cuts actually lie between the pixels, */
  /*  and not on top of them. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  disp('Filling in branch cuts that border on unwrapped pixels ...'); */
  ixstart = IM_phase->size[0];
  i0 = adjoin->size[0] * adjoin->size[1];
  adjoin->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)adjoin, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  ixstart = IM_phase->size[1];
  i0 = adjoin->size[0] * adjoin->size[1];
  adjoin->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)adjoin, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = IM_phase->size[0] * IM_phase->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    adjoin->data[i0] = 0.0;
  }

  /* Re-load the adjoining pixel matrix with the branch cut values: */
  i = 2;
  while (i - 2 <= IM_phase->size[0] - 3) {
    ixstart = 2;
    while (ixstart - 2 <= width - 3) {
      /*                          %Identify which branch cut pixel borders an unwrapped pixel */
      i0 = branch_cuts->size[0];
      i1 = branch_cuts->size[1];
      if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0,
            &ld_emlrtBCI, sp) + branch_cuts->size[0] *
                             (emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, i1,
             &md_emlrtBCI, sp) - 1)) - 1] == 1) {
        i0 = branch_cuts->size[0];
        i1 = 1 + i;
        idx = branch_cuts->size[1];
        guard1 = false;
        if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
              &nd_emlrtBCI, sp) + branch_cuts->size[0] *
                               (emlrtDynamicBoundsCheckFastR2012b(ixstart, 1,
               idx, &od_emlrtBCI, sp) - 1)) - 1] == 0) {
          guard1 = true;
        } else {
          i0 = branch_cuts->size[0];
          i1 = i - 1;
          idx = branch_cuts->size[1];
          if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
                &pd_emlrtBCI, sp) + branch_cuts->size[0] *
                                 (emlrtDynamicBoundsCheckFastR2012b(ixstart, 1,
                 idx, &qd_emlrtBCI, sp) - 1)) - 1] == 0) {
            guard1 = true;
          } else {
            i0 = branch_cuts->size[0];
            i1 = branch_cuts->size[1];
            idx = ixstart - 1;
            if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0,
                  &rd_emlrtBCI, sp) + branch_cuts->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(idx, 1, i1,
                   &sd_emlrtBCI, sp) - 1)) - 1] == 0) {
              guard1 = true;
            } else {
              i0 = branch_cuts->size[0];
              i1 = branch_cuts->size[1];
              idx = 1 + ixstart;
              if (branch_cuts->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0,
                    &td_emlrtBCI, sp) + branch_cuts->size[0] *
                                     (emlrtDynamicBoundsCheckFastR2012b(idx, 1,
                     i1, &ud_emlrtBCI, sp) - 1)) - 1] == 0) {
                guard1 = true;
              }
            }
          }
        }

        if (guard1) {
          i0 = adjoin->size[0];
          i1 = adjoin->size[1];
          adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, i0, &vd_emlrtBCI,
            sp) + adjoin->size[0] * (emlrtDynamicBoundsCheckFastR2012b(ixstart,
            1, i1, &wd_emlrtBCI, sp) - 1)) - 1] = 1.0;
        }
      }

      ixstart++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  st.site = &h_emlrtRSI;
  b_st.site = &gb_emlrtRSI;
  nx = adjoin->size[0] * adjoin->size[1];
  idx = 0;
  if ((!((adjoin->size[0] == 1) || (adjoin->size[1] == 1))) || (adjoin->size[0]
       != 1) || (adjoin->size[1] <= 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    i_y = NULL;
    m0 = emlrtCreateCharArray(2, iv6);
    for (i = 0; i < 36; i++) {
      cv0[i] = cv1[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 36, m0, cv0);
    emlrtAssign(&i_y, m0);
    c_st.site = &lb_emlrtRSI;
    d_st.site = &pb_emlrtRSI;
    error(&c_st, message(&d_st, i_y, &emlrtMCI), &b_emlrtMCI);
  }

  emlrtNonNegativeCheckFastR2012b(nx, &emlrtDCI, &b_st);
  i0 = ii->size[0];
  ii->size[0] = nx;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  i0 = jj->size[0];
  jj->size[0] = nx;
  emxEnsureCapacity(&b_st, (emxArray__common *)jj, i0, (int32_T)sizeof(int32_T),
                    &d_emlrtRTEI);
  if (nx == 0) {
    i0 = ii->size[0];
    ii->size[0] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    i0 = jj->size[0];
    jj->size[0] = 0;
    emxEnsureCapacity(&b_st, (emxArray__common *)jj, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
  } else {
    ixstart = 1;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i <= adjoin->size[1])) {
      b_guard1 = false;
      if (adjoin->data[(ixstart + adjoin->size[0] * (i - 1)) - 1] != 0.0) {
        idx++;
        ii->data[idx - 1] = ixstart;
        jj->data[idx - 1] = i;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_guard1 = true;
        }
      } else {
        b_guard1 = true;
      }

      if (b_guard1) {
        ixstart++;
        if (ixstart > adjoin->size[0]) {
          ixstart = 1;
          i++;
        }
      }
    }

    if (idx <= nx) {
    } else {
      j_y = NULL;
      m0 = emlrtCreateString("Assertion failed.");
      emlrtAssign(&j_y, m0);
      c_st.site = &kb_emlrtRSI;
      error(&c_st, j_y, &l_emlrtMCI);
    }

    if (nx == 1) {
      if (idx == 0) {
        i0 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                          (int32_T), &emlrtRTEI);
        i0 = jj->size[0];
        jj->size[0] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)jj, i0, (int32_T)sizeof
                          (int32_T), &emlrtRTEI);
      }
    } else {
      i0 = ii->size[0];
      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        ii->size[0] = idx;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                        (int32_T), &e_emlrtRTEI);
      i0 = jj->size[0];
      if (1 > idx) {
        jj->size[0] = 0;
      } else {
        jj->size[0] = idx;
      }

      emxEnsureCapacity(&b_st, (emxArray__common *)jj, i0, (int32_T)sizeof
                        (int32_T), &f_emlrtRTEI);
    }
  }

  i0 = r_adjoin->size[0];
  r_adjoin->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)r_adjoin, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = ii->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    r_adjoin->data[i0] = ii->data[i0];
  }

  emxFree_int32_T(&ii);
  i0 = y_ind->size[0];
  y_ind->size[0] = jj->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)y_ind, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = jj->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    y_ind->data[i0] = jj->data[i0];
  }

  emxFree_int32_T(&jj);

  /* Obtain coordinates of adjoining unwrapped phase pixels */
  /*  Matt changed from 'size' to length */
  i = 0;
  while (i <= r_adjoin->size[0] - 1) {
    i0 = r_adjoin->size[0];
    i1 = i + 1;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &u_emlrtBCI, sp);
    i0 = y_ind->size[0];
    i1 = i + 1;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &v_emlrtBCI, sp);

    /* First search below for an adjoining unwrapped phase pixel */
    i0 = unwrapped_binary->size[0];
    i1 = (int32_T)(r_adjoin->data[i] + 1.0);
    idx = unwrapped_binary->size[1];
    nx = (int32_T)y_ind->data[i];
    if (unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
          &ec_emlrtBCI, sp) + unwrapped_binary->size[0] *
         (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &fc_emlrtBCI, sp) - 1))
        - 1] == 1.0) {
      i0 = IM_unwrapped->size[0];
      i1 = (int32_T)(r_adjoin->data[i] + 1.0);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &w_emlrtBCI, sp);
      i0 = IM_unwrapped->size[1];
      i1 = (int32_T)y_ind->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &x_emlrtBCI, sp);

      /* Obtain the reference unwrapped phase */
      i0 = IM_phase->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &y_emlrtBCI, sp);
      i0 = IM_phase->size[1];
      i1 = (int32_T)y_ind->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &ab_emlrtBCI, sp);

      /* Unwrap the active pixel */
      dv0[0] = IM_unwrapped->data[((int32_T)(r_adjoin->data[i] + 1.0) +
        IM_unwrapped->size[0] * ((int32_T)y_ind->data[i] - 1)) - 1];
      dv0[1] = IM_phase->data[((int32_T)r_adjoin->data[i] + IM_phase->size[0] *
                               ((int32_T)y_ind->data[i] - 1)) - 1];
      unwrap(dv0);
      i0 = IM_unwrapped->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = IM_unwrapped->size[1];
      nx = (int32_T)y_ind->data[i];
      IM_unwrapped->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
        &gc_emlrtBCI, sp) + IM_unwrapped->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
        &hc_emlrtBCI, sp) - 1)) - 1] = dv0[1];
      i0 = unwrapped_binary->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = unwrapped_binary->size[1];
      nx = (int32_T)y_ind->data[i];
      unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
        &ic_emlrtBCI, sp) + unwrapped_binary->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &jc_emlrtBCI, sp) - 1)) -
        1] = 1.0;

      /* Mark the pixel as unwrapped */
      i0 = adjoin->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = adjoin->size[1];
      nx = (int32_T)y_ind->data[i];
      adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &kc_emlrtBCI,
        sp) + adjoin->size[0] * (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
        &lc_emlrtBCI, sp) - 1)) - 1] = 0.0;

      /* Remove it from the list of adjoining pixels */
    }

    /* Then search above */
    i0 = unwrapped_binary->size[0];
    i1 = (int32_T)(r_adjoin->data[i] - 1.0);
    idx = unwrapped_binary->size[1];
    nx = (int32_T)y_ind->data[i];
    if (unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
          &mc_emlrtBCI, sp) + unwrapped_binary->size[0] *
         (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &nc_emlrtBCI, sp) - 1))
        - 1] == 1.0) {
      i0 = IM_unwrapped->size[0];
      i1 = (int32_T)(r_adjoin->data[i] - 1.0);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &bb_emlrtBCI, sp);
      i0 = IM_unwrapped->size[1];
      i1 = (int32_T)y_ind->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &cb_emlrtBCI, sp);

      /* Obtain the reference unwrapped phase */
      i0 = IM_phase->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &db_emlrtBCI, sp);
      i0 = IM_phase->size[1];
      i1 = (int32_T)y_ind->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &eb_emlrtBCI, sp);

      /* Unwrap the active pixel */
      dv0[0] = IM_unwrapped->data[((int32_T)(r_adjoin->data[i] - 1.0) +
        IM_unwrapped->size[0] * ((int32_T)y_ind->data[i] - 1)) - 1];
      dv0[1] = IM_phase->data[((int32_T)r_adjoin->data[i] + IM_phase->size[0] *
                               ((int32_T)y_ind->data[i] - 1)) - 1];
      unwrap(dv0);
      i0 = IM_unwrapped->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = IM_unwrapped->size[1];
      nx = (int32_T)y_ind->data[i];
      IM_unwrapped->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
        &oc_emlrtBCI, sp) + IM_unwrapped->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
        &pc_emlrtBCI, sp) - 1)) - 1] = dv0[1];
      i0 = unwrapped_binary->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = unwrapped_binary->size[1];
      nx = (int32_T)y_ind->data[i];
      unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
        &qc_emlrtBCI, sp) + unwrapped_binary->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &rc_emlrtBCI, sp) - 1)) -
        1] = 1.0;

      /* Mark the pixel as unwrapped */
      i0 = adjoin->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = adjoin->size[1];
      nx = (int32_T)y_ind->data[i];
      adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &sc_emlrtBCI,
        sp) + adjoin->size[0] * (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
        &tc_emlrtBCI, sp) - 1)) - 1] = 0.0;

      /* Remove it from the list of adjoining pixels */
    }

    /* Then search on the right */
    i0 = unwrapped_binary->size[0];
    i1 = (int32_T)r_adjoin->data[i];
    idx = unwrapped_binary->size[1];
    nx = (int32_T)(y_ind->data[i] + 1.0);
    if (unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
          &uc_emlrtBCI, sp) + unwrapped_binary->size[0] *
         (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &vc_emlrtBCI, sp) - 1))
        - 1] == 1.0) {
      i0 = IM_unwrapped->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &fb_emlrtBCI, sp);
      i0 = IM_unwrapped->size[1];
      i1 = (int32_T)(y_ind->data[i] + 1.0);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &gb_emlrtBCI, sp);

      /* Obtain the reference unwrapped phase */
      i0 = IM_phase->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &hb_emlrtBCI, sp);
      i0 = IM_phase->size[1];
      i1 = (int32_T)y_ind->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &ib_emlrtBCI, sp);

      /* Unwrap the active pixel */
      dv0[0] = IM_unwrapped->data[((int32_T)r_adjoin->data[i] +
        IM_unwrapped->size[0] * ((int32_T)(y_ind->data[i] + 1.0) - 1)) - 1];
      dv0[1] = IM_phase->data[((int32_T)r_adjoin->data[i] + IM_phase->size[0] *
                               ((int32_T)y_ind->data[i] - 1)) - 1];
      unwrap(dv0);
      i0 = IM_unwrapped->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = IM_unwrapped->size[1];
      nx = (int32_T)y_ind->data[i];
      IM_unwrapped->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
        &wc_emlrtBCI, sp) + IM_unwrapped->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
        &xc_emlrtBCI, sp) - 1)) - 1] = dv0[1];
      i0 = unwrapped_binary->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = unwrapped_binary->size[1];
      nx = (int32_T)y_ind->data[i];
      unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
        &yc_emlrtBCI, sp) + unwrapped_binary->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &ad_emlrtBCI, sp) - 1)) -
        1] = 1.0;

      /* Mark the pixel as unwrapped */
      i0 = adjoin->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = adjoin->size[1];
      nx = (int32_T)y_ind->data[i];
      adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &bd_emlrtBCI,
        sp) + adjoin->size[0] * (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
        &cd_emlrtBCI, sp) - 1)) - 1] = 0.0;

      /* Remove it from the list of adjoining pixels */
    }

    /* Finally search on the left */
    i0 = unwrapped_binary->size[0];
    i1 = (int32_T)r_adjoin->data[i];
    idx = unwrapped_binary->size[1];
    nx = (int32_T)(y_ind->data[i] - 1.0);
    if (unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
          &dd_emlrtBCI, sp) + unwrapped_binary->size[0] *
         (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &ed_emlrtBCI, sp) - 1))
        - 1] == 1.0) {
      i0 = IM_unwrapped->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &jb_emlrtBCI, sp);
      i0 = IM_unwrapped->size[1];
      i1 = (int32_T)(y_ind->data[i] - 1.0);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &kb_emlrtBCI, sp);

      /* Obtain the reference unwrapped phase */
      i0 = IM_phase->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &lb_emlrtBCI, sp);
      i0 = IM_phase->size[1];
      i1 = (int32_T)y_ind->data[i];
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &mb_emlrtBCI, sp);

      /* Unwrap the active pixel */
      dv0[0] = IM_unwrapped->data[((int32_T)r_adjoin->data[i] +
        IM_unwrapped->size[0] * ((int32_T)(y_ind->data[i] - 1.0) - 1)) - 1];
      dv0[1] = IM_phase->data[((int32_T)r_adjoin->data[i] + IM_phase->size[0] *
                               ((int32_T)y_ind->data[i] - 1)) - 1];
      unwrap(dv0);
      i0 = IM_unwrapped->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = IM_unwrapped->size[1];
      nx = (int32_T)y_ind->data[i];
      IM_unwrapped->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
        &fd_emlrtBCI, sp) + IM_unwrapped->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
        &gd_emlrtBCI, sp) - 1)) - 1] = dv0[1];
      i0 = unwrapped_binary->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = unwrapped_binary->size[1];
      nx = (int32_T)y_ind->data[i];
      unwrapped_binary->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
        &hd_emlrtBCI, sp) + unwrapped_binary->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx, &id_emlrtBCI, sp) - 1)) -
        1] = 1.0;

      /* Mark the pixel as unwrapped */
      i0 = adjoin->size[0];
      i1 = (int32_T)r_adjoin->data[i];
      idx = adjoin->size[1];
      nx = (int32_T)y_ind->data[i];
      adjoin->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &jd_emlrtBCI,
        sp) + adjoin->size[0] * (emlrtDynamicBoundsCheckFastR2012b(nx, 1, idx,
        &kd_emlrtBCI, sp) - 1)) - 1] = 0.0;

      /* Remove it from the list of adjoining pixels */
    }

    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&r_adjoin);
  emxFree_real_T(&adjoin);
  emxFree_real_T(&unwrapped_binary);
  emxFree_real_T(&y_ind);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (FloodFill.c) */
