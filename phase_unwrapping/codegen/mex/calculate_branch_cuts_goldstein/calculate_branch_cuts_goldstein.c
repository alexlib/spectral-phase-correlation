/*
 * calculate_branch_cuts_goldstein.c
 *
 * Code generation for function 'calculate_branch_cuts_goldstein'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculate_branch_cuts_goldstein.h"
#include "calculate_branch_cuts_goldstein_emxutil.h"
#include "eml_error.h"
#include "eml_int_forloop_overflow_check.h"
#include "meshgrid.h"
#include "count_residues.h"
#include "calculate_branch_cuts_goldstein_mexutil.h"
#include "calculate_branch_cuts_goldstein_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 54, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo b_emlrtRSI = { 57, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo c_emlrtRSI = { 58, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo d_emlrtRSI = { 73, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo e_emlrtRSI = { 80, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo f_emlrtRSI = { 83, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo g_emlrtRSI = { 86, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo h_emlrtRSI = { 96, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo i_emlrtRSI = { 101, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo j_emlrtRSI = { 102, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo k_emlrtRSI = { 100, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo l_emlrtRSI = { 105, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo m_emlrtRSI = { 124, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo n_emlrtRSI = { 138, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo o_emlrtRSI = { 143, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo p_emlrtRSI = { 152, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo q_emlrtRSI = { 158, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo r_emlrtRSI = { 159, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo s_emlrtRSI = { 163, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo t_emlrtRSI = { 172, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo u_emlrtRSI = { 177, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo v_emlrtRSI = { 184, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo w_emlrtRSI = { 190, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo x_emlrtRSI = { 224, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo y_emlrtRSI = { 234, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo eb_emlrtRSI = { 41, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo fb_emlrtRSI = { 230, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo gb_emlrtRSI = { 271, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo hb_emlrtRSI = { 272, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo ib_emlrtRSI = { 279, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo jb_emlrtRSI = { 282, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo kb_emlrtRSI = { 283, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo lb_emlrtRSI = { 21, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo mb_emlrtRSI = { 79, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo nb_emlrtRSI = { 283, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo ob_emlrtRSI = { 291, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo wb_emlrtRSI = { 10, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo xb_emlrtRSI = { 11, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo yb_emlrtRSI = { 56, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo ac_emlrtRSI = { 117, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo bc_emlrtRSI = { 132, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo cc_emlrtRSI = { 134, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo dc_emlrtRSI = { 137, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo ec_emlrtRSI = { 160, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo fc_emlrtRSI = { 103, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo gc_emlrtRSI = { 16, "min",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/min.m" };

static emlrtRSInfo hc_emlrtRSI = { 18, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo ic_emlrtRSI = { 96, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo jc_emlrtRSI = { 202, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo kc_emlrtRSI = { 229, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo lc_emlrtRSI = { 16, "max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/max.m" };

static emlrtRSInfo tc_emlrtRSI = { 365, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo uc_emlrtRSI = { 366, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo vc_emlrtRSI = { 385, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo wc_emlrtRSI = { 396, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo xc_emlrtRSI = { 400, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo yc_emlrtRSI = { 405, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo ad_emlrtRSI = { 38, "rem",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elfun/rem.m" };

static emlrtRSInfo bd_emlrtRSI = { 338, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo cd_emlrtRSI = { 344, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo dd_emlrtRSI = { 309, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo ed_emlrtRSI = { 315, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo fd_emlrtRSI = { 318, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo gd_emlrtRSI = { 321, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo hd_emlrtRSI = { 14, "sqrt",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elfun/sqrt.m" };

static emlrtRSInfo id_emlrtRSI = { 42, "bitset",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/bitset.m" };

static emlrtRSInfo jd_emlrtRSI = { 6, "get_flags_charge",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/get_flags_"
  "charge.m" };

static emlrtRSInfo kd_emlrtRSI = { 8, "get_flags_charge",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/get_flags_"
  "charge.m" };

static emlrtRSInfo ld_emlrtRSI = { 427, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo md_emlrtRSI = { 433, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRSInfo nd_emlrtRSI = { 18, "min",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/datafun/min.m" };

static emlrtRSInfo od_emlrtRSI = { 15, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo pd_emlrtRSI = { 11, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtRSInfo qd_emlrtRSI = { 26, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtRSInfo rd_emlrtRSI = { 39, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtMCInfo c_emlrtMCI = { 123, 9, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtMCInfo d_emlrtMCI = { 122, 19, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtMCInfo e_emlrtMCI = { 239, 9, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtMCInfo f_emlrtMCI = { 405, 5, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtMCInfo g_emlrtMCI = { 404, 15, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtMCInfo m_emlrtMCI = { 57, 9, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtMCInfo n_emlrtMCI = { 56, 19, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtMCInfo o_emlrtMCI = { 122, 9, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtMCInfo p_emlrtMCI = { 125, 9, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtMCInfo q_emlrtMCI = { 145, 9, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtMCInfo r_emlrtMCI = { 148, 9, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtMCInfo s_emlrtMCI = { 41, 9, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtMCInfo t_emlrtMCI = { 38, 19, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtMCInfo u_emlrtMCI = { 82, 9, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtMCInfo v_emlrtMCI = { 81, 19, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtMCInfo x_emlrtMCI = { 14, 5, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 46, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo b_emlrtRTEI = { 284, 1, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRTEInfo c_emlrtRTEI = { 238, 33, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo d_emlrtRTEI = { 127, 5, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo e_emlrtRTEI = { 249, 13, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo f_emlrtRTEI = { 279, 1, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo g_emlrtRTEI = { 33, 6, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo j_emlrtRTEI = { 1, 14, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 354, 49, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo n_emlrtRTEI = { 365, 1, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo o_emlrtRTEI = { 366, 1, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo p_emlrtRTEI = { 396, 1, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo q_emlrtRTEI = { 325, 46, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo s_emlrtRTEI = { 20, 9, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtRTEInfo t_emlrtRTEI = { 57, 1, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo u_emlrtRTEI = { 130, 9, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 341, 1, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtRTEInfo w_emlrtRTEI = { 315, 1, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtECInfo emlrtECI = { -1, 279, 25, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtDCInfo emlrtDCI = { 284, 28, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m", 4 };

static emlrtDCInfo b_emlrtDCI = { 385, 23, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo emlrtBCI = { -1, -1, 385, 23, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 401, 64, "res_inds",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtECInfo b_emlrtECI = { 1, 401, 37, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtECInfo c_emlrtECI = { 1, 401, 14, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtECInfo d_emlrtECI = { -1, 406, 21, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtDCInfo c_emlrtDCI = { 371, 18, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtDCInfo d_emlrtDCI = { 371, 18, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 4 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 401, 38, "res_inds",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 401, 5, "res_inds",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 381, 19, "row_vect",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 381, 40, "col_vect",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 388, 13, "res_inds",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo h_emlrtBCI = { 0, MAX_int32_T, 414, 1, "BRANCH_CUT_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo e_emlrtDCI = { 20, 34, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m", 4
};

static emlrtDCInfo f_emlrtDCI = { 127, 30, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m", 4 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 185, 32, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo g_emlrtDCI = { 185, 32, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 184, 52, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo h_emlrtDCI = { 184, 52, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 178, 37, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo i_emlrtDCI = { 178, 37, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 177, 57, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo j_emlrtDCI = { 177, 57, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 173, 50, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo k_emlrtDCI = { 173, 50, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 173, 37, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo l_emlrtDCI = { 173, 37, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 163, 66, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo m_emlrtDCI = { 163, 66, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 163, 53, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo n_emlrtDCI = { 163, 53, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 143, 65, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo o_emlrtDCI = { 143, 65, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 143, 53, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo p_emlrtDCI = { 143, 53, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 135, 59, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo q_emlrtDCI = { 135, 59, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 135, 46, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo r_emlrtDCI = { 135, 46, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtRTEInfo y_emlrtRTEI = { 116, 13, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 102, 26, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo s_emlrtDCI = { 102, 26, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 101, 26, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo t_emlrtDCI = { 101, 26, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtRTEInfo ab_emlrtRTEI = { 93, 9, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 86, 35, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo u_emlrtDCI = { 86, 35, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 86, 32, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo v_emlrtDCI = { 86, 32, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 83, 53, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo w_emlrtDCI = { 83, 53, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 83, 50, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo x_emlrtDCI = { 83, 50, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 80, 53, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo y_emlrtDCI = { 80, 53, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 80, 50, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo ab_emlrtDCI = { 80, 50, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 73, 41, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo bb_emlrtDCI = { 73, 41, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 73, 38, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo cb_emlrtDCI = { 73, 38, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 70, 10, "residue_locs",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 69, 13, "residue_locs",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtECInfo e_emlrtECI = { 2, 57, 21, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtBCInfo hb_emlrtBCI = { 0, MAX_int32_T, 51, 1, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo db_emlrtDCI = { 1, 1, "scalexpAlloc",
  "/Applications/MATLAB_R2014b.app/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p",
  4 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 234, 1, "branch_cut_matrix",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 80, 22, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo eb_emlrtDCI = { 80, 22, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 80, 25, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo fb_emlrtDCI = { 80, 25, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 83, 22, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo gb_emlrtDCI = { 83, 22, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 83, 25, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo hb_emlrtDCI = { 83, 25, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 107, 44, "residue_locs",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 120, 30, "residue_box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 121, 30, "residue_box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 135, 46, "box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 135, 59, "box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 163, 53, "box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 163, 66, "box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 173, 37, "box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 173, 50, "box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 177, 57, "box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 178, 37, "box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 176, 46, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo ib_emlrtDCI = { 176, 46, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 176, 46, "box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 176, 59, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo jb_emlrtDCI = { 176, 59, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 176, 59, "box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 184, 52, "box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 185, 32, "box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 183, 42, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo kb_emlrtDCI = { 183, 42, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 183, 42, "box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 183, 55, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo lb_emlrtDCI = { 183, 55, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 183, 55, "box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 194, 34, "box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 194, 47, "box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 142, 42, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 142, 54, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 154, 48, "box_rows",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 154, 61, "box_cols",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo mb_emlrtDCI = { 159, 13, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m",
  4 };

static emlrtECInfo f_emlrtECI = { -1, 344, 1, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtECInfo g_emlrtECI = { -1, 345, 5, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtECInfo h_emlrtECI = { 2, 341, 22, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m" };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 344, 1, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtDCInfo nb_emlrtDCI = { 344, 1, "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 1 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 345, 5, "FLAGS_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 348, 1, "BRANCH_CUT_MATRIX",
  "calculate_branch_cuts_goldstein",
  "/Users/matthewgiarra/Documents/School/VT/Research/Aether/SPC/analysis/src/spectral-phase-correlation/phase_unwrapping/calculate_"
  "branch_cuts_goldstein.m", 0 };

static emlrtRSInfo sd_emlrtRSI = { 404, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo td_emlrtRSI = { 122, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo ud_emlrtRSI = { 125, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo vd_emlrtRSI = { 145, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo wd_emlrtRSI = { 148, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo xd_emlrtRSI = { 81, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo yd_emlrtRSI = { 38, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo ae_emlrtRSI = { 14, "eml_li_find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_li_find.m" };

static emlrtRSInfo be_emlrtRSI = { 239, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo ce_emlrtRSI = { 122, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo ie_emlrtRSI = { 405, "colon",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo je_emlrtRSI = { 57, "eml_null_assignment",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo ke_emlrtRSI = { 82, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo le_emlrtRSI = { 41, "eml_min_or_max",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo me_emlrtRSI = { 123, "find",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elmat/find.m" };

/* Function Declarations */
static void eml_null_assignment(const emlrtStack *sp, emxArray_real_T *x, const
  emxArray_real_T *idx);
static void find_box_coordinates(const emlrtStack *sp, const real_T PIXEL_LOC[2],
  const real_T DIMS[2], real_T BOX_SIZE, emxArray_real_T *BOX_ROWS,
  emxArray_real_T *BOX_COLS);
static void find_residue_positions(const emlrtStack *sp, const emxArray_uint8_T *
  FLAGS_MATRIX, const emxArray_real_T *ROWS, const emxArray_real_T *COLS, real_T
  ANCHOR_LOC, real_T NUM_RESIDUES, emxArray_real_T *RESIDUE_BOX_ROWS,
  emxArray_real_T *RESIDUE_BOX_COLS);
static void place_branch_cut(const emlrtStack *sp, emxArray_uint8_T
  *BRANCH_CUT_MATRIX, emxArray_uint8_T *FLAGS_MATRIX, const real_T POINTS_01[2],
  const real_T POINTS_02[2]);

/* Function Definitions */
static void eml_null_assignment(const emlrtStack *sp, emxArray_real_T *x, const
  emxArray_real_T *idx)
{
  boolean_T overflow;
  int32_T k;
  boolean_T exitg1;
  const mxArray *y;
  static const int32_T iv39[2] = { 1, 31 };

  const mxArray *m11;
  char_T cv27[31];
  int32_T i;
  static const char_T cv28[31] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'u', 'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm',
    'i', 's', 'm', 'a', 't', 'c', 'h' };

  int32_T nxin;
  const mxArray *b_y;
  emxArray_real_T *b_x;
  int32_T k0;
  const mxArray *c_y;
  emxArray_real_T *c_x;
  emxArray_boolean_T *b;
  const mxArray *d_y;
  emxArray_real_T *d_x;
  const mxArray *e_y;
  emxArray_real_T *e_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &wb_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  overflow = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx->size[0] - 1)) {
    if ((idx->data[k] < 1.0) || ((int32_T)idx->data[k] > x->size[0]) ||
        (idx->data[k] != muDoubleScalarFloor(idx->data[k]))) {
      overflow = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (overflow) {
  } else {
    y = NULL;
    m11 = emlrtCreateCharArray(2, iv39);
    for (i = 0; i < 31; i++) {
      cv27[i] = cv28[i];
    }

    emlrtInitCharArrayR2013a(&st, 31, m11, cv27);
    emlrtAssign(&y, m11);
    b_st.site = &yb_emlrtRSI;
    c_st.site = &je_emlrtRSI;
    error(&b_st, b_message(&c_st, y, &m_emlrtMCI), &n_emlrtMCI);
  }

  st.site = &xb_emlrtRSI;
  nxin = x->size[0] - 1;
  if (idx->size[0] == 1) {
    b_st.site = &ac_emlrtRSI;
    if ((int32_T)idx->data[0] > x->size[0] - 1) {
      overflow = false;
    } else {
      overflow = (x->size[0] - 1 > 2147483646);
    }

    if (overflow) {
      d_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (k = (int32_T)idx->data[0]; k <= nxin; k++) {
      x->data[k - 1] = x->data[k];
    }

    if (x->size[0] != 1) {
      if (nxin <= x->size[0]) {
      } else {
        b_y = NULL;
        m11 = emlrtCreateString("Assertion failed.");
        emlrtAssign(&b_y, m11);
        b_st.site = &td_emlrtRSI;
        error(&b_st, b_y, &o_emlrtMCI);
      }

      if (1 > nxin) {
        i = 0;
      } else {
        i = nxin;
      }

      emxInit_real_T(&st, &b_x, 1, &j_emlrtRTEI, true);
      k0 = b_x->size[0];
      b_x->size[0] = i;
      emxEnsureCapacity(&st, (emxArray__common *)b_x, k0, (int32_T)sizeof(real_T),
                        &j_emlrtRTEI);
      for (k0 = 0; k0 < i; k0++) {
        b_x->data[k0] = x->data[k0];
      }

      k0 = x->size[0];
      x->size[0] = b_x->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)x, k0, (int32_T)sizeof(real_T),
                        &j_emlrtRTEI);
      i = b_x->size[0];
      for (k0 = 0; k0 < i; k0++) {
        x->data[k0] = b_x->data[k0];
      }

      emxFree_real_T(&b_x);
    } else {
      if (nxin <= nxin + 1) {
      } else {
        c_y = NULL;
        m11 = emlrtCreateString("Assertion failed.");
        emlrtAssign(&c_y, m11);
        b_st.site = &ud_emlrtRSI;
        error(&b_st, c_y, &p_emlrtMCI);
      }

      if (1 > nxin) {
        i = 0;
      } else {
        i = nxin;
      }

      emxInit_real_T(&st, &c_x, 1, &j_emlrtRTEI, true);
      k0 = c_x->size[0];
      c_x->size[0] = i;
      emxEnsureCapacity(&st, (emxArray__common *)c_x, k0, (int32_T)sizeof(real_T),
                        &j_emlrtRTEI);
      for (k0 = 0; k0 < i; k0++) {
        c_x->data[k0] = x->data[k0];
      }

      k0 = x->size[0];
      x->size[0] = c_x->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)x, k0, (int32_T)sizeof(real_T),
                        &j_emlrtRTEI);
      i = c_x->size[0];
      for (k0 = 0; k0 < i; k0++) {
        x->data[k0] = c_x->data[k0];
      }

      emxFree_real_T(&c_x);
    }
  } else {
    b_emxInit_boolean_T(&st, &b, 2, &u_emlrtRTEI, true);
    b_st.site = &bc_emlrtRSI;
    k0 = b->size[0] * b->size[1];
    b->size[0] = 1;
    emxEnsureCapacity(&b_st, (emxArray__common *)b, k0, (int32_T)sizeof
                      (boolean_T), &j_emlrtRTEI);
    k0 = x->size[0];
    i = (int32_T)emlrtNonNegativeCheckFastR2012b(k0, &mb_emlrtDCI, &b_st);
    k0 = b->size[0] * b->size[1];
    b->size[1] = i;
    emxEnsureCapacity(&b_st, (emxArray__common *)b, k0, (int32_T)sizeof
                      (boolean_T), &j_emlrtRTEI);
    k0 = x->size[0];
    i = (int32_T)emlrtNonNegativeCheckFastR2012b(k0, &mb_emlrtDCI, &b_st);
    for (k0 = 0; k0 < i; k0++) {
      b->data[k0] = false;
    }

    d_st.site = &ec_emlrtRSI;
    if (1 > idx->size[0]) {
      overflow = false;
    } else {
      overflow = (idx->size[0] > 2147483646);
    }

    if (overflow) {
      e_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (k = 1; k <= idx->size[0]; k++) {
      b->data[(int32_T)idx->data[k - 1] - 1] = true;
    }

    b_st.site = &cc_emlrtRSI;
    i = 0;
    d_st.site = &fc_emlrtRSI;
    if (1 > b->size[1]) {
      overflow = false;
    } else {
      overflow = (b->size[1] > 2147483646);
    }

    if (overflow) {
      e_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (k = 1; k <= b->size[1]; k++) {
      i += b->data[k - 1];
    }

    i = x->size[0] - i;
    k0 = -1;
    b_st.site = &dc_emlrtRSI;
    if (1 > x->size[0]) {
      overflow = false;
    } else {
      overflow = (x->size[0] > 2147483646);
    }

    if (overflow) {
      d_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&d_st, true);
    }

    for (k = 1; k <= nxin + 1; k++) {
      if ((k > b->size[1]) || (!b->data[k - 1])) {
        k0++;
        x->data[k0] = x->data[k - 1];
      }
    }

    emxFree_boolean_T(&b);
    if (x->size[0] != 1) {
      if (i <= x->size[0]) {
      } else {
        d_y = NULL;
        m11 = emlrtCreateString("Assertion failed.");
        emlrtAssign(&d_y, m11);
        b_st.site = &vd_emlrtRSI;
        error(&b_st, d_y, &q_emlrtMCI);
      }

      if (1 > i) {
        i = 0;
      }

      emxInit_real_T(&st, &d_x, 1, &j_emlrtRTEI, true);
      k0 = d_x->size[0];
      d_x->size[0] = i;
      emxEnsureCapacity(&st, (emxArray__common *)d_x, k0, (int32_T)sizeof(real_T),
                        &j_emlrtRTEI);
      for (k0 = 0; k0 < i; k0++) {
        d_x->data[k0] = x->data[k0];
      }

      k0 = x->size[0];
      x->size[0] = d_x->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)x, k0, (int32_T)sizeof(real_T),
                        &j_emlrtRTEI);
      i = d_x->size[0];
      for (k0 = 0; k0 < i; k0++) {
        x->data[k0] = d_x->data[k0];
      }

      emxFree_real_T(&d_x);
    } else {
      if (i <= nxin + 1) {
      } else {
        e_y = NULL;
        m11 = emlrtCreateString("Assertion failed.");
        emlrtAssign(&e_y, m11);
        b_st.site = &wd_emlrtRSI;
        error(&b_st, e_y, &r_emlrtMCI);
      }

      if (1 > i) {
        i = 0;
      }

      emxInit_real_T(&st, &e_x, 1, &j_emlrtRTEI, true);
      k0 = e_x->size[0];
      e_x->size[0] = i;
      emxEnsureCapacity(&st, (emxArray__common *)e_x, k0, (int32_T)sizeof(real_T),
                        &j_emlrtRTEI);
      for (k0 = 0; k0 < i; k0++) {
        e_x->data[k0] = x->data[k0];
      }

      k0 = x->size[0];
      x->size[0] = e_x->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)x, k0, (int32_T)sizeof(real_T),
                        &j_emlrtRTEI);
      i = e_x->size[0];
      for (k0 = 0; k0 < i; k0++) {
        x->data[k0] = e_x->data[k0];
      }

      emxFree_real_T(&e_x);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void find_box_coordinates(const emlrtStack *sp, const real_T PIXEL_LOC[2],
  const real_T DIMS[2], real_T BOX_SIZE, emxArray_real_T *BOX_ROWS,
  emxArray_real_T *BOX_COLS)
{
  real_T box_radius;
  real_T box_rows_min;
  real_T box_rows_max;
  real_T box_cols_min;
  int32_T idx;
  real_T anew;
  real_T apnd;
  boolean_T overflow;
  real_T ndbl;
  real_T cdiff;
  real_T absb;
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 21 };

  const mxArray *m1;
  char_T cv4[21];
  int32_T i;
  static const char_T cv5[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *r0;
  int32_T i0;
  int32_T nx;
  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 21 };

  emxArray_real_T *r1;
  emxArray_real_T *b_BOX_COLS;
  emxArray_real_T *b_BOX_ROWS;
  emxArray_boolean_T *x;
  emxArray_boolean_T *r2;
  emxArray_int32_T *ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  const mxArray *c_y;
  emxArray_real_T *anchor_pix_index;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  This function calculates the extents of a square odd-sized search box. */
  /*  Radius of the box. Round to enforce odd-sized boxes. */
  box_radius = muDoubleScalarRound((BOX_SIZE - 1.0) / 2.0);

  /*  Set the top-most row of the box to the  */
  /*  anchor pixel row position minus the box radius. */
  /*  If this results in a negative position, then set the */
  /*  top edge of the box equal to the top edge of the image. */
  box_rows_min = muDoubleScalarMax(1.0, PIXEL_LOC[0] - box_radius);

  /*  Set the bottom-most row of the box to the  */
  /*  anchor pixel row position plus the box radius. */
  /*  If this results in a position greater than the number of rows */
  /*  in the image, then set the bottom edge of the box equal */
  /*  to the bottom edge of the image. */
  box_rows_max = muDoubleScalarMin(DIMS[0], PIXEL_LOC[0] + box_radius);

  /*  Set the left-most column of the box to the  */
  /*  anchor pixel column position minus the box radius. */
  /*  If this results in a negative position, then set the left-edge */
  /*  of the box equal to the left edge of the image. */
  box_cols_min = muDoubleScalarMax(1.0, PIXEL_LOC[1] - box_radius);

  /*  Set the right-most column of the box to the  */
  /*  anchor pixel column position plus the box radius. */
  /*  If this results in a position greater than the number of columns */
  /*  in the image, then set the right edge of the box equal */
  /*  to the right edge of the image. */
  box_radius = muDoubleScalarMin(DIMS[1], PIXEL_LOC[1] + box_radius);

  /*  Create matrices of the box pixel positions  */
  st.site = &gb_emlrtRSI;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &mb_emlrtRSI;
  if (muDoubleScalarIsNaN(box_cols_min) || muDoubleScalarIsNaN(box_radius)) {
    idx = 1;
    anew = rtNaN;
    apnd = box_radius;
    overflow = false;
  } else if (box_radius < box_cols_min) {
    idx = 0;
    anew = box_cols_min;
    apnd = box_radius;
    overflow = false;
  } else if (muDoubleScalarIsInf(box_cols_min) || muDoubleScalarIsInf(box_radius))
  {
    idx = 1;
    anew = rtNaN;
    apnd = box_radius;
    overflow = !(box_cols_min == box_radius);
  } else {
    anew = box_cols_min;
    ndbl = muDoubleScalarFloor((box_radius - box_cols_min) + 0.5);
    apnd = box_cols_min + ndbl;
    cdiff = apnd - box_radius;
    absb = muDoubleScalarAbs(box_radius);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
        (box_cols_min, absb)) {
      ndbl++;
      apnd = box_radius;
    } else if (cdiff > 0.0) {
      apnd = box_cols_min + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      idx = (int32_T)ndbl;
    } else {
      idx = 0;
    }
  }

  d_st.site = &nb_emlrtRSI;
  if (!overflow) {
  } else {
    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    for (i = 0; i < 21; i++) {
      cv4[i] = cv5[i];
    }

    emlrtInitCharArrayR2013a(&d_st, 21, m1, cv4);
    emlrtAssign(&y, m1);
    e_st.site = &sd_emlrtRSI;
    f_st.site = &ie_emlrtRSI;
    error(&e_st, b_message(&f_st, y, &f_emlrtMCI), &g_emlrtMCI);
  }

  b_emxInit_real_T(&d_st, &r0, 2, &c_emlrtRTEI, true);
  emlrtNonNegativeCheckFastR2012b(idx, &emlrtDCI, &c_st);
  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = 1;
  r0->size[1] = idx;
  emxEnsureCapacity(&c_st, (emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (idx > 0) {
    r0->data[0] = anew;
    if (idx > 1) {
      r0->data[idx - 1] = apnd;
      i0 = idx - 1;
      i = (int32_T)((uint32_T)i0 >> 1);
      d_st.site = &ob_emlrtRSI;
      for (nx = 1; nx < i; nx++) {
        r0->data[nx] = anew + (real_T)nx;
        r0->data[(idx - nx) - 1] = apnd - (real_T)nx;
      }

      if (i << 1 == idx - 1) {
        r0->data[i] = (anew + apnd) / 2.0;
      } else {
        r0->data[i] = anew + (real_T)i;
        r0->data[i + 1] = apnd - (real_T)i;
      }
    }
  }

  st.site = &hb_emlrtRSI;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &mb_emlrtRSI;
  if (muDoubleScalarIsNaN(box_rows_min) || muDoubleScalarIsNaN(box_rows_max)) {
    idx = 1;
    anew = rtNaN;
    apnd = box_rows_max;
    overflow = false;
  } else if (box_rows_max < box_rows_min) {
    idx = 0;
    anew = box_rows_min;
    apnd = box_rows_max;
    overflow = false;
  } else if (muDoubleScalarIsInf(box_rows_min) || muDoubleScalarIsInf
             (box_rows_max)) {
    idx = 1;
    anew = rtNaN;
    apnd = box_rows_max;
    overflow = !(box_rows_min == box_rows_max);
  } else {
    anew = box_rows_min;
    ndbl = muDoubleScalarFloor((box_rows_max - box_rows_min) + 0.5);
    apnd = box_rows_min + ndbl;
    cdiff = apnd - box_rows_max;
    absb = muDoubleScalarAbs(box_rows_max);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
        (box_rows_min, absb)) {
      ndbl++;
      apnd = box_rows_max;
    } else if (cdiff > 0.0) {
      apnd = box_rows_min + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      idx = (int32_T)ndbl;
    } else {
      idx = 0;
    }
  }

  d_st.site = &nb_emlrtRSI;
  if (!overflow) {
  } else {
    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    for (i = 0; i < 21; i++) {
      cv4[i] = cv5[i];
    }

    emlrtInitCharArrayR2013a(&d_st, 21, m1, cv4);
    emlrtAssign(&b_y, m1);
    e_st.site = &sd_emlrtRSI;
    f_st.site = &ie_emlrtRSI;
    error(&e_st, b_message(&f_st, b_y, &f_emlrtMCI), &g_emlrtMCI);
  }

  b_emxInit_real_T(&d_st, &r1, 2, &c_emlrtRTEI, true);
  emlrtNonNegativeCheckFastR2012b(idx, &emlrtDCI, &c_st);
  i0 = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = idx;
  emxEnsureCapacity(&c_st, (emxArray__common *)r1, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (idx > 0) {
    r1->data[0] = anew;
    if (idx > 1) {
      r1->data[idx - 1] = apnd;
      i0 = idx - 1;
      i = (int32_T)((uint32_T)i0 >> 1);
      d_st.site = &ob_emlrtRSI;
      for (nx = 1; nx < i; nx++) {
        r1->data[nx] = anew + (real_T)nx;
        r1->data[(idx - nx) - 1] = apnd - (real_T)nx;
      }

      if (i << 1 == idx - 1) {
        r1->data[i] = (anew + apnd) / 2.0;
      } else {
        r1->data[i] = anew + (real_T)i;
        r1->data[i + 1] = apnd - (real_T)i;
      }
    }
  }

  b_emxInit_real_T(&c_st, &b_BOX_COLS, 2, &c_emlrtRTEI, true);
  b_emxInit_real_T(&c_st, &b_BOX_ROWS, 2, &c_emlrtRTEI, true);
  emxInit_boolean_T(&c_st, &x, 1, &c_emlrtRTEI, true);
  st.site = &gb_emlrtRSI;
  meshgrid(&st, r0, r1, b_BOX_COLS, b_BOX_ROWS);

  /*  Turn the arrays into vectors */
  /*  Index of the anchor pixel in the box rows / columns arrays */
  i0 = x->size[0];
  x->size[0] = b_BOX_COLS->size[0] * b_BOX_COLS->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)x, i0, (int32_T)sizeof(boolean_T),
                    &c_emlrtRTEI);
  i = b_BOX_COLS->size[0] * b_BOX_COLS->size[1];
  emxFree_real_T(&r1);
  emxFree_real_T(&r0);
  for (i0 = 0; i0 < i; i0++) {
    x->data[i0] = (b_BOX_COLS->data[i0] == PIXEL_LOC[1]);
  }

  emxInit_boolean_T(sp, &r2, 1, &c_emlrtRTEI, true);
  i0 = r2->size[0];
  r2->size[0] = b_BOX_ROWS->size[0] * b_BOX_ROWS->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r2, i0, (int32_T)sizeof(boolean_T),
                    &c_emlrtRTEI);
  i = b_BOX_ROWS->size[0] * b_BOX_ROWS->size[1];
  for (i0 = 0; i0 < i; i0++) {
    r2->data[i0] = (b_BOX_ROWS->data[i0] == PIXEL_LOC[0]);
  }

  i0 = x->size[0];
  i = r2->size[0];
  emlrtSizeEqCheck1DFastR2012b(i0, i, &emlrtECI, sp);
  st.site = &ib_emlrtRSI;
  i0 = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i0, (int32_T)sizeof(boolean_T),
                    &c_emlrtRTEI);
  i = x->size[0];
  for (i0 = 0; i0 < i; i0++) {
    x->data[i0] = (x->data[i0] && r2->data[i0]);
  }

  emxFree_boolean_T(&r2);
  emxInit_int32_T(&st, &ii, 1, &g_emlrtRTEI, true);
  b_st.site = &eb_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  i0 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                    &d_emlrtRTEI);
  c_st.site = &fb_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  i = 1;
  exitg1 = false;
  while ((!exitg1) && (i <= nx)) {
    guard1 = false;
    if (x->data[i - 1]) {
      idx++;
      ii->data[idx - 1] = i;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      i++;
    }
  }

  if (idx <= x->size[0]) {
  } else {
    c_y = NULL;
    m1 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&c_y, m1);
    c_st.site = &be_emlrtRSI;
    error(&c_st, c_y, &e_emlrtMCI);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i0 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                        (int32_T), &c_emlrtRTEI);
    }
  } else {
    i0 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  emxInit_real_T(&b_st, &anchor_pix_index, 1, &f_emlrtRTEI, true);
  i0 = anchor_pix_index->size[0];
  anchor_pix_index->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)anchor_pix_index, i0, (int32_T)
                    sizeof(real_T), &c_emlrtRTEI);
  i = ii->size[0];
  for (i0 = 0; i0 < i; i0++) {
    anchor_pix_index->data[i0] = ii->data[i0];
  }

  emxFree_int32_T(&ii);

  /*  Don't include the anchor pixel in the box coordinates.  */
  i0 = BOX_COLS->size[0];
  BOX_COLS->size[0] = b_BOX_COLS->size[0] * b_BOX_COLS->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)BOX_COLS, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  i = b_BOX_COLS->size[0] * b_BOX_COLS->size[1];
  for (i0 = 0; i0 < i; i0++) {
    BOX_COLS->data[i0] = b_BOX_COLS->data[i0];
  }

  emxFree_real_T(&b_BOX_COLS);
  st.site = &jb_emlrtRSI;
  eml_null_assignment(&st, BOX_COLS, anchor_pix_index);
  i0 = BOX_ROWS->size[0];
  BOX_ROWS->size[0] = b_BOX_ROWS->size[0] * b_BOX_ROWS->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)BOX_ROWS, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  i = b_BOX_ROWS->size[0] * b_BOX_ROWS->size[1];
  for (i0 = 0; i0 < i; i0++) {
    BOX_ROWS->data[i0] = b_BOX_ROWS->data[i0];
  }

  emxFree_real_T(&b_BOX_ROWS);
  st.site = &kb_emlrtRSI;
  eml_null_assignment(&st, BOX_ROWS, anchor_pix_index);
  emxFree_real_T(&anchor_pix_index);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void find_residue_positions(const emlrtStack *sp, const emxArray_uint8_T *
  FLAGS_MATRIX, const emxArray_real_T *ROWS, const emxArray_real_T *COLS, real_T
  ANCHOR_LOC, real_T NUM_RESIDUES, emxArray_real_T *RESIDUE_BOX_ROWS,
  emxArray_real_T *RESIDUE_BOX_COLS)
{
  int32_T height;
  int32_T nx;
  boolean_T guard5 = false;
  boolean_T overflow;
  const mxArray *y;
  static const int32_T iv12[2] = { 1, 36 };

  const mxArray *m5;
  char_T cv16[36];
  int32_T i;
  static const char_T cv17[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *b_y;
  static const int32_T iv13[2] = { 1, 39 };

  char_T cv18[39];
  static const char_T cv19[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T ixstart;
  real_T box_ind;
  boolean_T exitg5;
  boolean_T guard4 = false;
  const mxArray *c_y;
  static const int32_T iv14[2] = { 1, 36 };

  const mxArray *d_y;
  static const int32_T iv15[2] = { 1, 39 };

  real_T mtmp;
  boolean_T exitg4;
  real_T anew;
  real_T apnd;
  real_T ndbl;
  real_T cdiff;
  real_T absa;
  real_T absb;
  const mxArray *e_y;
  static const int32_T iv16[2] = { 1, 21 };

  char_T cv20[21];
  static const char_T cv21[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *row_vect;
  int32_T i2;
  boolean_T guard3 = false;
  const mxArray *f_y;
  static const int32_T iv17[2] = { 1, 36 };

  const mxArray *g_y;
  static const int32_T iv18[2] = { 1, 39 };

  boolean_T exitg3;
  boolean_T guard2 = false;
  const mxArray *h_y;
  static const int32_T iv19[2] = { 1, 36 };

  const mxArray *i_y;
  static const int32_T iv20[2] = { 1, 39 };

  boolean_T exitg2;
  const mxArray *j_y;
  static const int32_T iv21[2] = { 1, 21 };

  emxArray_real_T *col_vect;
  int32_T num_box_cols;
  uint32_T res_cnt;
  int8_T c[2];
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  const mxArray *k_y;
  emxArray_real_T *res_anchor_loc;
  boolean_T b_guard1 = false;
  const mxArray *l_y;
  static const int32_T iv22[2] = { 1, 36 };

  const mxArray *m_y;
  static const int32_T iv23[2] = { 1, 39 };

  emxArray_real_T *b_RESIDUE_BOX_COLS;
  int32_T iv24[2];
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
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &c_st;
  e_st.tls = c_st.tls;
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &d_st;
  h_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Determine the positions of all of the residues in the box. */
  /*  Dimensions of the larger matrix */
  height = FLAGS_MATRIX->size[0];

  /*  Residue flags bit positions */
  /*  Make vectors out of the row and column positions. */
  st.site = &tc_emlrtRSI;
  b_st.site = &gc_emlrtRSI;
  c_st.site = &hc_emlrtRSI;
  nx = ROWS->size[0];
  guard5 = false;
  if (nx == 1) {
    guard5 = true;
  } else {
    nx = ROWS->size[0];
    if (nx != 1) {
      guard5 = true;
    } else {
      overflow = false;
    }
  }

  if (guard5) {
    overflow = true;
  }

  if (overflow) {
  } else {
    y = NULL;
    m5 = emlrtCreateCharArray(2, iv12);
    for (i = 0; i < 36; i++) {
      cv16[i] = cv17[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m5, cv16);
    emlrtAssign(&y, m5);
    d_st.site = &yd_emlrtRSI;
    e_st.site = &le_emlrtRSI;
    error(&d_st, b_message(&e_st, y, &s_emlrtMCI), &t_emlrtMCI);
  }

  nx = ROWS->size[0];
  if (nx > 0) {
  } else {
    b_y = NULL;
    m5 = emlrtCreateCharArray(2, iv13);
    for (i = 0; i < 39; i++) {
      cv18[i] = cv19[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m5, cv18);
    emlrtAssign(&b_y, m5);
    d_st.site = &xd_emlrtRSI;
    e_st.site = &ke_emlrtRSI;
    error(&d_st, b_message(&e_st, b_y, &u_emlrtMCI), &v_emlrtMCI);
  }

  d_st.site = &ic_emlrtRSI;
  ixstart = 1;
  nx = ROWS->size[0];
  box_ind = ROWS->data[0];
  i = ROWS->size[0];
  if (i > 1) {
    if (muDoubleScalarIsNaN(ROWS->data[0])) {
      f_st.site = &jc_emlrtRSI;
      i = ROWS->size[0];
      if (2 > i) {
        overflow = false;
      } else {
        i = ROWS->size[0];
        overflow = (i > 2147483646);
      }

      if (overflow) {
        g_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      i = 2;
      exitg5 = false;
      while ((!exitg5) && (i <= nx)) {
        ixstart = i;
        if (!muDoubleScalarIsNaN(ROWS->data[i - 1])) {
          box_ind = ROWS->data[i - 1];
          exitg5 = true;
        } else {
          i++;
        }
      }
    }

    i = ROWS->size[0];
    if (ixstart < i) {
      f_st.site = &kc_emlrtRSI;
      i = ROWS->size[0];
      if (ixstart + 1 > i) {
        overflow = false;
      } else {
        i = ROWS->size[0];
        overflow = (i > 2147483646);
      }

      if (overflow) {
        g_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      while (ixstart + 1 <= nx) {
        if (ROWS->data[ixstart] < box_ind) {
          box_ind = ROWS->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  st.site = &tc_emlrtRSI;
  b_st.site = &lc_emlrtRSI;
  c_st.site = &hc_emlrtRSI;
  nx = ROWS->size[0];
  guard4 = false;
  if (nx == 1) {
    guard4 = true;
  } else {
    nx = ROWS->size[0];
    if (nx != 1) {
      guard4 = true;
    } else {
      overflow = false;
    }
  }

  if (guard4) {
    overflow = true;
  }

  if (overflow) {
  } else {
    c_y = NULL;
    m5 = emlrtCreateCharArray(2, iv14);
    for (i = 0; i < 36; i++) {
      cv16[i] = cv17[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m5, cv16);
    emlrtAssign(&c_y, m5);
    d_st.site = &yd_emlrtRSI;
    e_st.site = &le_emlrtRSI;
    error(&d_st, b_message(&e_st, c_y, &s_emlrtMCI), &t_emlrtMCI);
  }

  nx = ROWS->size[0];
  if (nx > 0) {
  } else {
    d_y = NULL;
    m5 = emlrtCreateCharArray(2, iv15);
    for (i = 0; i < 39; i++) {
      cv18[i] = cv19[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m5, cv18);
    emlrtAssign(&d_y, m5);
    d_st.site = &xd_emlrtRSI;
    e_st.site = &ke_emlrtRSI;
    error(&d_st, b_message(&e_st, d_y, &u_emlrtMCI), &v_emlrtMCI);
  }

  d_st.site = &ic_emlrtRSI;
  ixstart = 1;
  nx = ROWS->size[0];
  mtmp = ROWS->data[0];
  i = ROWS->size[0];
  if (i > 1) {
    if (muDoubleScalarIsNaN(ROWS->data[0])) {
      f_st.site = &jc_emlrtRSI;
      i = ROWS->size[0];
      if (2 > i) {
        overflow = false;
      } else {
        i = ROWS->size[0];
        overflow = (i > 2147483646);
      }

      if (overflow) {
        g_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      i = 2;
      exitg4 = false;
      while ((!exitg4) && (i <= nx)) {
        ixstart = i;
        if (!muDoubleScalarIsNaN(ROWS->data[i - 1])) {
          mtmp = ROWS->data[i - 1];
          exitg4 = true;
        } else {
          i++;
        }
      }
    }

    i = ROWS->size[0];
    if (ixstart < i) {
      f_st.site = &kc_emlrtRSI;
      i = ROWS->size[0];
      if (ixstart + 1 > i) {
        overflow = false;
      } else {
        i = ROWS->size[0];
        overflow = (i > 2147483646);
      }

      if (overflow) {
        g_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      while (ixstart + 1 <= nx) {
        if (ROWS->data[ixstart] > mtmp) {
          mtmp = ROWS->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  st.site = &tc_emlrtRSI;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &mb_emlrtRSI;
  if (muDoubleScalarIsNaN(box_ind) || muDoubleScalarIsNaN(mtmp)) {
    nx = 1;
    anew = rtNaN;
    apnd = mtmp;
    overflow = false;
  } else if (mtmp < box_ind) {
    nx = 0;
    anew = box_ind;
    apnd = mtmp;
    overflow = false;
  } else if (muDoubleScalarIsInf(box_ind) || muDoubleScalarIsInf(mtmp)) {
    nx = 1;
    anew = rtNaN;
    apnd = mtmp;
    overflow = !(box_ind == mtmp);
  } else {
    anew = box_ind;
    ndbl = muDoubleScalarFloor((mtmp - box_ind) + 0.5);
    apnd = box_ind + ndbl;
    cdiff = apnd - mtmp;
    absa = muDoubleScalarAbs(box_ind);
    absb = muDoubleScalarAbs(mtmp);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
        (absa, absb)) {
      ndbl++;
      apnd = mtmp;
    } else if (cdiff > 0.0) {
      apnd = box_ind + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      nx = (int32_T)ndbl;
    } else {
      nx = 0;
    }
  }

  d_st.site = &nb_emlrtRSI;
  if (!overflow) {
  } else {
    e_y = NULL;
    m5 = emlrtCreateCharArray(2, iv16);
    for (i = 0; i < 21; i++) {
      cv20[i] = cv21[i];
    }

    emlrtInitCharArrayR2013a(&d_st, 21, m5, cv20);
    emlrtAssign(&e_y, m5);
    f_st.site = &sd_emlrtRSI;
    h_st.site = &ie_emlrtRSI;
    error(&f_st, b_message(&h_st, e_y, &f_emlrtMCI), &g_emlrtMCI);
  }

  b_emxInit_real_T(&d_st, &row_vect, 2, &n_emlrtRTEI, true);
  emlrtNonNegativeCheckFastR2012b(nx, &emlrtDCI, &c_st);
  i2 = row_vect->size[0] * row_vect->size[1];
  row_vect->size[0] = 1;
  row_vect->size[1] = nx;
  emxEnsureCapacity(&c_st, (emxArray__common *)row_vect, i2, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  if (nx > 0) {
    row_vect->data[0] = anew;
    if (nx > 1) {
      row_vect->data[nx - 1] = apnd;
      i2 = nx - 1;
      i = (int32_T)((uint32_T)i2 >> 1);
      d_st.site = &ob_emlrtRSI;
      for (ixstart = 1; ixstart < i; ixstart++) {
        row_vect->data[ixstart] = anew + (real_T)ixstart;
        row_vect->data[(nx - ixstart) - 1] = apnd - (real_T)ixstart;
      }

      if (i << 1 == nx - 1) {
        row_vect->data[i] = (anew + apnd) / 2.0;
      } else {
        row_vect->data[i] = anew + (real_T)i;
        row_vect->data[i + 1] = apnd - (real_T)i;
      }
    }
  }

  st.site = &uc_emlrtRSI;
  b_st.site = &gc_emlrtRSI;
  c_st.site = &hc_emlrtRSI;
  nx = COLS->size[0];
  guard3 = false;
  if (nx == 1) {
    guard3 = true;
  } else {
    nx = COLS->size[0];
    if (nx != 1) {
      guard3 = true;
    } else {
      overflow = false;
    }
  }

  if (guard3) {
    overflow = true;
  }

  if (overflow) {
  } else {
    f_y = NULL;
    m5 = emlrtCreateCharArray(2, iv17);
    for (i = 0; i < 36; i++) {
      cv16[i] = cv17[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m5, cv16);
    emlrtAssign(&f_y, m5);
    d_st.site = &yd_emlrtRSI;
    e_st.site = &le_emlrtRSI;
    error(&d_st, b_message(&e_st, f_y, &s_emlrtMCI), &t_emlrtMCI);
  }

  nx = COLS->size[0];
  if (nx > 0) {
  } else {
    g_y = NULL;
    m5 = emlrtCreateCharArray(2, iv18);
    for (i = 0; i < 39; i++) {
      cv18[i] = cv19[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m5, cv18);
    emlrtAssign(&g_y, m5);
    d_st.site = &xd_emlrtRSI;
    e_st.site = &ke_emlrtRSI;
    error(&d_st, b_message(&e_st, g_y, &u_emlrtMCI), &v_emlrtMCI);
  }

  d_st.site = &ic_emlrtRSI;
  ixstart = 1;
  nx = COLS->size[0];
  box_ind = COLS->data[0];
  i = COLS->size[0];
  if (i > 1) {
    if (muDoubleScalarIsNaN(COLS->data[0])) {
      f_st.site = &jc_emlrtRSI;
      i = COLS->size[0];
      if (2 > i) {
        overflow = false;
      } else {
        i = COLS->size[0];
        overflow = (i > 2147483646);
      }

      if (overflow) {
        g_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      i = 2;
      exitg3 = false;
      while ((!exitg3) && (i <= nx)) {
        ixstart = i;
        if (!muDoubleScalarIsNaN(COLS->data[i - 1])) {
          box_ind = COLS->data[i - 1];
          exitg3 = true;
        } else {
          i++;
        }
      }
    }

    i = COLS->size[0];
    if (ixstart < i) {
      f_st.site = &kc_emlrtRSI;
      i = COLS->size[0];
      if (ixstart + 1 > i) {
        overflow = false;
      } else {
        i = COLS->size[0];
        overflow = (i > 2147483646);
      }

      if (overflow) {
        g_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      while (ixstart + 1 <= nx) {
        if (COLS->data[ixstart] < box_ind) {
          box_ind = COLS->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  st.site = &uc_emlrtRSI;
  b_st.site = &lc_emlrtRSI;
  c_st.site = &hc_emlrtRSI;
  nx = COLS->size[0];
  guard2 = false;
  if (nx == 1) {
    guard2 = true;
  } else {
    nx = COLS->size[0];
    if (nx != 1) {
      guard2 = true;
    } else {
      overflow = false;
    }
  }

  if (guard2) {
    overflow = true;
  }

  if (overflow) {
  } else {
    h_y = NULL;
    m5 = emlrtCreateCharArray(2, iv19);
    for (i = 0; i < 36; i++) {
      cv16[i] = cv17[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m5, cv16);
    emlrtAssign(&h_y, m5);
    d_st.site = &yd_emlrtRSI;
    e_st.site = &le_emlrtRSI;
    error(&d_st, b_message(&e_st, h_y, &s_emlrtMCI), &t_emlrtMCI);
  }

  nx = COLS->size[0];
  if (nx > 0) {
  } else {
    i_y = NULL;
    m5 = emlrtCreateCharArray(2, iv20);
    for (i = 0; i < 39; i++) {
      cv18[i] = cv19[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m5, cv18);
    emlrtAssign(&i_y, m5);
    d_st.site = &xd_emlrtRSI;
    e_st.site = &ke_emlrtRSI;
    error(&d_st, b_message(&e_st, i_y, &u_emlrtMCI), &v_emlrtMCI);
  }

  d_st.site = &ic_emlrtRSI;
  ixstart = 1;
  nx = COLS->size[0];
  mtmp = COLS->data[0];
  i = COLS->size[0];
  if (i > 1) {
    if (muDoubleScalarIsNaN(COLS->data[0])) {
      f_st.site = &jc_emlrtRSI;
      i = COLS->size[0];
      if (2 > i) {
        overflow = false;
      } else {
        i = COLS->size[0];
        overflow = (i > 2147483646);
      }

      if (overflow) {
        g_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      i = 2;
      exitg2 = false;
      while ((!exitg2) && (i <= nx)) {
        ixstart = i;
        if (!muDoubleScalarIsNaN(COLS->data[i - 1])) {
          mtmp = COLS->data[i - 1];
          exitg2 = true;
        } else {
          i++;
        }
      }
    }

    i = COLS->size[0];
    if (ixstart < i) {
      f_st.site = &kc_emlrtRSI;
      i = COLS->size[0];
      if (ixstart + 1 > i) {
        overflow = false;
      } else {
        i = COLS->size[0];
        overflow = (i > 2147483646);
      }

      if (overflow) {
        g_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      while (ixstart + 1 <= nx) {
        if (COLS->data[ixstart] > mtmp) {
          mtmp = COLS->data[ixstart];
        }

        ixstart++;
      }
    }
  }

  st.site = &uc_emlrtRSI;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &mb_emlrtRSI;
  if (muDoubleScalarIsNaN(box_ind) || muDoubleScalarIsNaN(mtmp)) {
    nx = 1;
    anew = rtNaN;
    apnd = mtmp;
    overflow = false;
  } else if (mtmp < box_ind) {
    nx = 0;
    anew = box_ind;
    apnd = mtmp;
    overflow = false;
  } else if (muDoubleScalarIsInf(box_ind) || muDoubleScalarIsInf(mtmp)) {
    nx = 1;
    anew = rtNaN;
    apnd = mtmp;
    overflow = !(box_ind == mtmp);
  } else {
    anew = box_ind;
    ndbl = muDoubleScalarFloor((mtmp - box_ind) + 0.5);
    apnd = box_ind + ndbl;
    cdiff = apnd - mtmp;
    absa = muDoubleScalarAbs(box_ind);
    absb = muDoubleScalarAbs(mtmp);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
        (absa, absb)) {
      ndbl++;
      apnd = mtmp;
    } else if (cdiff > 0.0) {
      apnd = box_ind + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      nx = (int32_T)ndbl;
    } else {
      nx = 0;
    }
  }

  d_st.site = &nb_emlrtRSI;
  if (!overflow) {
  } else {
    j_y = NULL;
    m5 = emlrtCreateCharArray(2, iv21);
    for (i = 0; i < 21; i++) {
      cv20[i] = cv21[i];
    }

    emlrtInitCharArrayR2013a(&d_st, 21, m5, cv20);
    emlrtAssign(&j_y, m5);
    f_st.site = &sd_emlrtRSI;
    h_st.site = &ie_emlrtRSI;
    error(&f_st, b_message(&h_st, j_y, &f_emlrtMCI), &g_emlrtMCI);
  }

  b_emxInit_real_T(&d_st, &col_vect, 2, &o_emlrtRTEI, true);
  emlrtNonNegativeCheckFastR2012b(nx, &emlrtDCI, &c_st);
  i2 = col_vect->size[0] * col_vect->size[1];
  col_vect->size[0] = 1;
  col_vect->size[1] = nx;
  emxEnsureCapacity(&c_st, (emxArray__common *)col_vect, i2, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  if (nx > 0) {
    col_vect->data[0] = anew;
    if (nx > 1) {
      col_vect->data[nx - 1] = apnd;
      i2 = nx - 1;
      i = (int32_T)((uint32_T)i2 >> 1);
      d_st.site = &ob_emlrtRSI;
      for (ixstart = 1; ixstart < i; ixstart++) {
        col_vect->data[ixstart] = anew + (real_T)ixstart;
        col_vect->data[(nx - ixstart) - 1] = apnd - (real_T)ixstart;
      }

      if (i << 1 == nx - 1) {
        col_vect->data[i] = (anew + apnd) / 2.0;
      } else {
        col_vect->data[i] = anew + (real_T)i;
        col_vect->data[i + 1] = apnd - (real_T)i;
      }
    }
  }

  num_box_cols = col_vect->size[1];

  /*  Vector to hold the indices of the residues in the box. */
  i2 = RESIDUE_BOX_COLS->size[0];
  box_ind = emlrtNonNegativeCheckFastR2012b(NUM_RESIDUES, &d_emlrtDCI, sp);
  RESIDUE_BOX_COLS->size[0] = (int32_T)emlrtIntegerCheckFastR2012b(box_ind,
    &c_emlrtDCI, sp);
  emxEnsureCapacity(sp, (emxArray__common *)RESIDUE_BOX_COLS, i2, (int32_T)
                    sizeof(real_T), &m_emlrtRTEI);
  box_ind = emlrtNonNegativeCheckFastR2012b(NUM_RESIDUES, &d_emlrtDCI, sp);
  nx = (int32_T)emlrtIntegerCheckFastR2012b(box_ind, &c_emlrtDCI, sp);
  for (i2 = 0; i2 < nx; i2++) {
    RESIDUE_BOX_COLS->data[i2] = 0.0;
  }

  /*  Start a counter. */
  res_cnt = 1U;

  /*  Loop over all the pixels in the box. */
  i = 0;
  while (i <= row_vect->size[1] - 1) {
    nx = 0;
    while (nx <= num_box_cols - 1) {
      /*  Big-array index of box pixel. */
      i2 = row_vect->size[1];
      ixstart = col_vect->size[1];
      box_ind = row_vect->data[emlrtDynamicBoundsCheckFastR2012b(i + 1, 1, i2,
        &e_emlrtBCI, sp) - 1] + (col_vect->
        data[emlrtDynamicBoundsCheckFastR2012b(nx + 1, 1, ixstart, &f_emlrtBCI,
        sp) - 1] - 1.0) * (real_T)height;

      /*  If the pixel corresponds to a residue  */
      /*  then add its index to the list of residue indices. */
      st.site = &vc_emlrtRSI;
      i2 = FLAGS_MATRIX->size[0] * FLAGS_MATRIX->size[1];
      ixstart = (int32_T)emlrtIntegerCheckFastR2012b(box_ind, &b_emlrtDCI, &st);
      emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, i2, &emlrtBCI, &st);
      for (ixstart = 0; ixstart < 2; ixstart++) {
        c[ixstart] = (int8_T)((FLAGS_MATRIX->data[(int32_T)box_ind - 1] & 1 <<
          ixstart) != 0);
      }

      if (c[0] + c[1] > 0) {
        i2 = RESIDUE_BOX_COLS->size[0];
        ixstart = (int32_T)res_cnt;
        RESIDUE_BOX_COLS->data[emlrtDynamicBoundsCheckFastR2012b(ixstart, 1, i2,
          &g_emlrtBCI, sp) - 1] = box_ind;
        res_cnt++;
      }

      nx++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    i++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&col_vect);
  emxFree_real_T(&row_vect);
  emxInit_boolean_T(sp, &x, 1, &m_emlrtRTEI, true);

  /*  Find the location of the anchor residue.  */
  st.site = &wc_emlrtRSI;
  i2 = x->size[0];
  x->size[0] = RESIDUE_BOX_COLS->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, i2, (int32_T)sizeof(boolean_T),
                    &m_emlrtRTEI);
  nx = RESIDUE_BOX_COLS->size[0];
  for (i2 = 0; i2 < nx; i2++) {
    x->data[i2] = (RESIDUE_BOX_COLS->data[i2] == ANCHOR_LOC);
  }

  emxInit_int32_T(&st, &ii, 1, &g_emlrtRTEI, true);
  b_st.site = &eb_emlrtRSI;
  nx = x->size[0];
  ixstart = 0;
  i2 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i2, (int32_T)sizeof(int32_T),
                    &d_emlrtRTEI);
  c_st.site = &fb_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&d_st, true);
  }

  i = 1;
  exitg1 = false;
  while ((!exitg1) && (i <= nx)) {
    guard1 = false;
    if (x->data[i - 1]) {
      ixstart++;
      ii->data[ixstart - 1] = i;
      if (ixstart >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      i++;
    }
  }

  if (ixstart <= x->size[0]) {
  } else {
    k_y = NULL;
    m5 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&k_y, m5);
    c_st.site = &be_emlrtRSI;
    error(&c_st, k_y, &e_emlrtMCI);
  }

  if (x->size[0] == 1) {
    if (ixstart == 0) {
      i2 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i2, (int32_T)sizeof
                        (int32_T), &m_emlrtRTEI);
    }
  } else {
    i2 = ii->size[0];
    if (1 > ixstart) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = ixstart;
    }

    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i2, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  emxInit_real_T(&b_st, &res_anchor_loc, 1, &p_emlrtRTEI, true);
  i2 = res_anchor_loc->size[0];
  res_anchor_loc->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)res_anchor_loc, i2, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);
  nx = ii->size[0];
  for (i2 = 0; i2 < nx; i2++) {
    res_anchor_loc->data[i2] = ii->data[i2];
  }

  emxFree_int32_T(&ii);

  /*  Swap the positions of the anchor pixel and the first pixel */
  /*  in the list of residue locations. */
  st.site = &xc_emlrtRSI;
  b_st.site = &lc_emlrtRSI;
  c_st.site = &hc_emlrtRSI;
  ixstart = res_anchor_loc->size[0];
  b_guard1 = false;
  if (ixstart == 1) {
    b_guard1 = true;
  } else {
    ixstart = res_anchor_loc->size[0];
    if (ixstart != 1) {
      b_guard1 = true;
    } else {
      overflow = false;
    }
  }

  if (b_guard1) {
    overflow = true;
  }

  if (overflow) {
  } else {
    l_y = NULL;
    m5 = emlrtCreateCharArray(2, iv22);
    for (i = 0; i < 36; i++) {
      cv16[i] = cv17[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m5, cv16);
    emlrtAssign(&l_y, m5);
    d_st.site = &yd_emlrtRSI;
    e_st.site = &le_emlrtRSI;
    error(&d_st, b_message(&e_st, l_y, &s_emlrtMCI), &t_emlrtMCI);
  }

  ixstart = res_anchor_loc->size[0];
  if (ixstart > 0) {
  } else {
    m_y = NULL;
    m5 = emlrtCreateCharArray(2, iv23);
    for (i = 0; i < 39; i++) {
      cv18[i] = cv19[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m5, cv18);
    emlrtAssign(&m_y, m5);
    d_st.site = &xd_emlrtRSI;
    e_st.site = &ke_emlrtRSI;
    error(&d_st, b_message(&e_st, m_y, &u_emlrtMCI), &v_emlrtMCI);
  }

  d_st.site = &ic_emlrtRSI;
  ixstart = res_anchor_loc->size[0];
  nx = (int32_T)res_anchor_loc->data[0];
  i = res_anchor_loc->size[0];
  if (i > 1) {
    i = res_anchor_loc->size[0];
    if (1 < i) {
      f_st.site = &kc_emlrtRSI;
      i = res_anchor_loc->size[0];
      if (2 > i) {
        overflow = false;
      } else {
        i = res_anchor_loc->size[0];
        overflow = (i > 2147483646);
      }

      if (overflow) {
        g_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&g_st, true);
      }

      for (i = 1; i + 1 <= ixstart; i++) {
        if ((int32_T)res_anchor_loc->data[i] > nx) {
          nx = (int32_T)res_anchor_loc->data[i];
        }
      }
    }
  }

  if (nx > 1) {
    nx = res_anchor_loc->size[0];
    for (i2 = 0; i2 < nx; i2++) {
      ixstart = RESIDUE_BOX_COLS->size[0];
      i = (int32_T)res_anchor_loc->data[i2];
      emlrtDynamicBoundsCheckFastR2012b(i, 1, ixstart, &c_emlrtBCI, sp);
    }

    emxInit_real_T(sp, &b_RESIDUE_BOX_COLS, 1, &m_emlrtRTEI, true);
    ixstart = res_anchor_loc->size[0];
    emlrtDimSizeEqCheckFastR2012b(1, ixstart, &b_emlrtECI, sp);
    ixstart = res_anchor_loc->size[0];
    emlrtDimSizeEqCheckFastR2012b(1, ixstart, &c_emlrtECI, sp);
    i2 = RESIDUE_BOX_COLS->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i2, &b_emlrtBCI, sp);
    i = RESIDUE_BOX_COLS->size[0];
    iv24[0] = 1;
    iv24[1] = (int32_T)res_anchor_loc->data[0];
    i2 = b_RESIDUE_BOX_COLS->size[0];
    b_RESIDUE_BOX_COLS->size[0] = res_anchor_loc->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)b_RESIDUE_BOX_COLS, i2, (int32_T)
                      sizeof(real_T), &m_emlrtRTEI);
    nx = res_anchor_loc->size[0];
    for (i2 = 0; i2 < nx; i2++) {
      b_RESIDUE_BOX_COLS->data[i2] = RESIDUE_BOX_COLS->data[(int32_T)
        res_anchor_loc->data[i2] - 1];
    }

    ixstart = res_anchor_loc->size[0];
    box_ind = RESIDUE_BOX_COLS->data[0];
    for (i2 = 0; i2 < ixstart; i2++) {
      RESIDUE_BOX_COLS->data[emlrtDynamicBoundsCheckFastR2012b(iv24[i2], 1, i,
        &d_emlrtBCI, sp) - 1] = b_RESIDUE_BOX_COLS->data[i2];
    }

    emxFree_real_T(&b_RESIDUE_BOX_COLS);
    RESIDUE_BOX_COLS->data[emlrtDynamicBoundsCheckFastR2012b(iv24[1], 1, i,
      &d_emlrtBCI, sp) - 1] = box_ind;
  }

  /*  Convert the index to [row, col] */
  st.site = &yc_emlrtRSI;
  i2 = res_anchor_loc->size[0];
  res_anchor_loc->size[0] = RESIDUE_BOX_COLS->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)res_anchor_loc, i2, (int32_T)sizeof
                    (real_T), &m_emlrtRTEI);
  nx = RESIDUE_BOX_COLS->size[0];
  for (i2 = 0; i2 < nx; i2++) {
    res_anchor_loc->data[i2] = RESIDUE_BOX_COLS->data[i2] - 1.0;
  }

  b_st.site = &ad_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  res_cnt = (uint32_T)res_anchor_loc->size[0];
  i2 = RESIDUE_BOX_ROWS->size[0];
  RESIDUE_BOX_ROWS->size[0] = (int32_T)res_cnt;
  emxEnsureCapacity(&c_st, (emxArray__common *)RESIDUE_BOX_ROWS, i2, (int32_T)
                    sizeof(real_T), &k_emlrtRTEI);
  for (ixstart = 0; ixstart < (int32_T)res_cnt; ixstart++) {
    RESIDUE_BOX_ROWS->data[ixstart] = muDoubleScalarRem(res_anchor_loc->
      data[ixstart], height);
  }

  emxFree_real_T(&res_anchor_loc);
  i2 = RESIDUE_BOX_ROWS->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)RESIDUE_BOX_ROWS, i2, (int32_T)
                    sizeof(real_T), &m_emlrtRTEI);
  nx = RESIDUE_BOX_ROWS->size[0];
  for (i2 = 0; i2 < nx; i2++) {
    RESIDUE_BOX_ROWS->data[i2]++;
  }

  i2 = RESIDUE_BOX_COLS->size[0];
  ixstart = RESIDUE_BOX_ROWS->size[0];
  emlrtSizeEqCheck1DFastR2012b(i2, ixstart, &d_emlrtECI, sp);
  i = FLAGS_MATRIX->size[0];
  i2 = RESIDUE_BOX_COLS->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)RESIDUE_BOX_COLS, i2, (int32_T)
                    sizeof(real_T), &m_emlrtRTEI);
  nx = RESIDUE_BOX_COLS->size[0];
  for (i2 = 0; i2 < nx; i2++) {
    RESIDUE_BOX_COLS->data[i2] = (RESIDUE_BOX_COLS->data[i2] -
      RESIDUE_BOX_ROWS->data[i2]) / (real_T)i + 1.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void place_branch_cut(const emlrtStack *sp, emxArray_uint8_T
  *BRANCH_CUT_MATRIX, emxArray_uint8_T *FLAGS_MATRIX, const real_T POINTS_01[2],
  const real_T POINTS_02[2])
{
  real_T row_distance;
  real_T col_distance;
  real_T apnd;
  real_T euc_distance;
  real_T residue_angle;
  int32_T n;
  boolean_T n_too_large;
  real_T cdiff;
  const mxArray *y;
  static const int32_T iv40[2] = { 1, 21 };

  const mxArray *m12;
  char_T cv29[21];
  int32_T i;
  static const char_T cv30[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *euc_vector;
  int32_T i7;
  int32_T k;
  emxArray_real_T *x;
  emxArray_real_T *branch_cut_indices;
  int32_T b_BRANCH_CUT_MATRIX;
  int32_T b_branch_cut_indices[2];
  int32_T b_x[2];
  emxArray_int32_T *r7;
  uint32_T uv0[2];
  emxArray_uint8_T *r8;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &e_st;
  g_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  This function places a branch cut in the branch cut matrix. */
  /*  This is the little-endian bit position of the  */
  /*  bit in each 8-bit element of the FLAGS_MATRIX array that indicates */
  /*  whether or not the pixel lies on a branch cut.  */
  /*  Determine size of matrix */
  /*  Find the pixels corresponding to the branch cut */
  st.site = &bd_emlrtRSI;

  /*  These are the coordinates of the first point */
  /*  Row */
  /*  Column */
  /*  These are the coordinates of the second first point */
  /*  Place a branch cut between the anchor pixel and the  */
  /*  residue found in the box. */
  /*  */
  /*  This is the difference in row positions between the */
  /*  two residues. */
  row_distance = POINTS_02[0] - POINTS_01[0];

  /*  This is the difference in column positions between */
  /*  the two residues. */
  col_distance = POINTS_02[1] - POINTS_01[1];

  /*  Euclidian distance between the two residues */
  b_st.site = &dd_emlrtRSI;
  apnd = row_distance * row_distance + col_distance * col_distance;
  if (apnd < 0.0) {
    c_st.site = &hd_emlrtRSI;
    eml_error(&c_st);
  }

  euc_distance = muDoubleScalarFloor(muDoubleScalarSqrt(apnd));

  /*  Angle between the residues */
  residue_angle = muDoubleScalarAtan2(row_distance, col_distance);

  /*  Euclidean distance vector */
  b_st.site = &ed_emlrtRSI;
  c_st.site = &lb_emlrtRSI;
  d_st.site = &mb_emlrtRSI;
  if (muDoubleScalarIsNaN(euc_distance)) {
    n = 1;
    row_distance = rtNaN;
    apnd = euc_distance;
    n_too_large = false;
  } else if (muDoubleScalarIsInf(euc_distance)) {
    n = 1;
    row_distance = rtNaN;
    apnd = euc_distance;
    n_too_large = !(0.0 == euc_distance);
  } else {
    row_distance = 0.0;
    col_distance = muDoubleScalarFloor(euc_distance + 0.5);
    apnd = col_distance;
    cdiff = col_distance - euc_distance;
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * euc_distance) {
      col_distance++;
      apnd = euc_distance;
    } else if (cdiff > 0.0) {
      apnd = col_distance - 1.0;
    } else {
      col_distance++;
    }

    n_too_large = (2.147483647E+9 < col_distance);
    if (col_distance >= 0.0) {
      n = (int32_T)col_distance;
    } else {
      n = 0;
    }
  }

  e_st.site = &nb_emlrtRSI;
  if (!n_too_large) {
  } else {
    y = NULL;
    m12 = emlrtCreateCharArray(2, iv40);
    for (i = 0; i < 21; i++) {
      cv29[i] = cv30[i];
    }

    emlrtInitCharArrayR2013a(&e_st, 21, m12, cv29);
    emlrtAssign(&y, m12);
    f_st.site = &sd_emlrtRSI;
    g_st.site = &ie_emlrtRSI;
    error(&f_st, b_message(&g_st, y, &f_emlrtMCI), &g_emlrtMCI);
  }

  b_emxInit_real_T(&e_st, &euc_vector, 2, &w_emlrtRTEI, true);
  emlrtNonNegativeCheckFastR2012b(n, &emlrtDCI, &d_st);
  i7 = euc_vector->size[0] * euc_vector->size[1];
  euc_vector->size[0] = 1;
  euc_vector->size[1] = n;
  emxEnsureCapacity(&d_st, (emxArray__common *)euc_vector, i7, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  if (n > 0) {
    euc_vector->data[0] = row_distance;
    if (n > 1) {
      euc_vector->data[n - 1] = apnd;
      i7 = n - 1;
      i = (int32_T)((uint32_T)i7 >> 1);
      e_st.site = &ob_emlrtRSI;
      for (k = 1; k < i; k++) {
        euc_vector->data[k] = row_distance + (real_T)k;
        euc_vector->data[(n - k) - 1] = apnd - (real_T)k;
      }

      if (i << 1 == n - 1) {
        euc_vector->data[i] = (row_distance + apnd) / 2.0;
      } else {
        euc_vector->data[i] = row_distance + (real_T)i;
        euc_vector->data[i + 1] = apnd - (real_T)i;
      }
    }
  }

  b_emxInit_real_T(&d_st, &x, 2, &q_emlrtRTEI, true);

  /*  Row pixels in the branch cut */
  apnd = muDoubleScalarSin(residue_angle);
  b_st.site = &fd_emlrtRSI;
  i7 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = euc_vector->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)x, i7, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  n = euc_vector->size[0] * euc_vector->size[1];
  for (i7 = 0; i7 < n; i7++) {
    x->data[i7] = POINTS_01[0] + euc_vector->data[i7] * apnd;
  }

  b_emxInit_real_T(&b_st, &branch_cut_indices, 2, &v_emlrtRTEI, true);
  i7 = branch_cut_indices->size[0] * branch_cut_indices->size[1];
  branch_cut_indices->size[0] = 1;
  branch_cut_indices->size[1] = x->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)branch_cut_indices, i7, (int32_T)
                    sizeof(real_T), &q_emlrtRTEI);
  n = x->size[0] * x->size[1];
  for (i7 = 0; i7 < n; i7++) {
    branch_cut_indices->data[i7] = x->data[i7];
  }

  for (k = 0; k < x->size[1]; k++) {
    branch_cut_indices->data[k] = muDoubleScalarRound(branch_cut_indices->data[k]);
  }

  /*  Column pixels in the branch cut */
  apnd = muDoubleScalarCos(residue_angle);
  b_st.site = &gd_emlrtRSI;
  i7 = euc_vector->size[0] * euc_vector->size[1];
  euc_vector->size[0] = 1;
  emxEnsureCapacity(&b_st, (emxArray__common *)euc_vector, i7, (int32_T)sizeof
                    (real_T), &q_emlrtRTEI);
  i = euc_vector->size[0];
  k = euc_vector->size[1];
  n = i * k;
  for (i7 = 0; i7 < n; i7++) {
    euc_vector->data[i7] = POINTS_01[1] + euc_vector->data[i7] * apnd;
  }

  i7 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = euc_vector->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)x, i7, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  n = euc_vector->size[0] * euc_vector->size[1];
  for (i7 = 0; i7 < n; i7++) {
    x->data[i7] = euc_vector->data[i7];
  }

  for (k = 0; k < euc_vector->size[1]; k++) {
    x->data[k] = muDoubleScalarRound(x->data[k]);
  }

  emxFree_real_T(&euc_vector);

  /*  Find the indices of the branch cut pixels. */
  i7 = x->size[0] * x->size[1];
  x->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)x, i7, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  i = x->size[0];
  k = x->size[1];
  b_BRANCH_CUT_MATRIX = BRANCH_CUT_MATRIX->size[0];
  n = i * k;
  for (i7 = 0; i7 < n; i7++) {
    x->data[i7] = (x->data[i7] - 1.0) * (real_T)b_BRANCH_CUT_MATRIX;
  }

  for (i7 = 0; i7 < 2; i7++) {
    b_branch_cut_indices[i7] = branch_cut_indices->size[i7];
  }

  for (i7 = 0; i7 < 2; i7++) {
    b_x[i7] = x->size[i7];
  }

  emlrtSizeEqCheck2DFastR2012b(b_branch_cut_indices, b_x, &h_emlrtECI, sp);
  i7 = branch_cut_indices->size[0] * branch_cut_indices->size[1];
  branch_cut_indices->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)branch_cut_indices, i7, (int32_T)
                    sizeof(real_T), &q_emlrtRTEI);
  i = branch_cut_indices->size[0];
  k = branch_cut_indices->size[1];
  n = i * k;
  for (i7 = 0; i7 < n; i7++) {
    branch_cut_indices->data[i7] += x->data[i7];
  }

  emxFree_real_T(&x);
  b_emxInit_int32_T(sp, &r7, 2, &q_emlrtRTEI, true);

  /*  Set the "branch cut" flag to one at the branch cut indices. */
  emlrtMatrixMatrixIndexCheckR2012b(*(int32_T (*)[2])FLAGS_MATRIX->size, 2,
    *(int32_T (*)[2])branch_cut_indices->size, 2, &g_emlrtECI, sp);
  i7 = r7->size[0] * r7->size[1];
  r7->size[0] = 1;
  r7->size[1] = branch_cut_indices->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r7, i7, (int32_T)sizeof(int32_T),
                    &q_emlrtRTEI);
  n = branch_cut_indices->size[0] * branch_cut_indices->size[1];
  for (i7 = 0; i7 < n; i7++) {
    i = FLAGS_MATRIX->size[0] * FLAGS_MATRIX->size[1];
    row_distance = branch_cut_indices->data[i7];
    k = (int32_T)emlrtIntegerCheckFastR2012b(row_distance, &nb_emlrtDCI, sp);
    r7->data[i7] = emlrtDynamicBoundsCheckFastR2012b(k, 1, i, &pc_emlrtBCI, sp);
  }

  st.site = &cd_emlrtRSI;
  n = branch_cut_indices->size[0] * branch_cut_indices->size[1];
  for (i7 = 0; i7 < n; i7++) {
    i = FLAGS_MATRIX->size[0] * FLAGS_MATRIX->size[1];
    k = (int32_T)branch_cut_indices->data[i7];
    emlrtDynamicBoundsCheckFastR2012b(k, 1, i, &qc_emlrtBCI, &st);
  }

  b_st.site = &id_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  for (i7 = 0; i7 < 2; i7++) {
    uv0[i7] = (uint32_T)branch_cut_indices->size[i7];
  }

  b_emxInit_uint8_T(&c_st, &r8, 2, &q_emlrtRTEI, true);
  i7 = r8->size[0] * r8->size[1];
  r8->size[0] = 1;
  r8->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)r8, i7, (int32_T)sizeof(uint8_T),
                    &k_emlrtRTEI);
  if ((int32_T)uv0[1] == 0) {
  } else {
    for (k = 0; k < (int32_T)uv0[1]; k++) {
      r8->data[k] = (uint8_T)(FLAGS_MATRIX->data[(int32_T)
        branch_cut_indices->data[branch_cut_indices->size[0] * k] - 1] | 4);
    }
  }

  i7 = r7->size[1];
  i = r8->size[1];
  emlrtSizeEqCheck1DFastR2012b(i7, i, &f_emlrtECI, sp);
  n = r8->size[1];
  for (i7 = 0; i7 < n; i7++) {
    FLAGS_MATRIX->data[r7->data[r7->size[0] * i7] - 1] = r8->data[r8->size[0] *
      i7];
  }

  emxFree_uint8_T(&r8);

  /*  Set those pixels to one in the branch cut matrix. */
  i7 = r7->size[0] * r7->size[1];
  r7->size[0] = 1;
  r7->size[1] = branch_cut_indices->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r7, i7, (int32_T)sizeof(int32_T),
                    &q_emlrtRTEI);
  n = branch_cut_indices->size[0] * branch_cut_indices->size[1];
  for (i7 = 0; i7 < n; i7++) {
    i = BRANCH_CUT_MATRIX->size[0] * BRANCH_CUT_MATRIX->size[1];
    k = (int32_T)branch_cut_indices->data[i7];
    r7->data[i7] = emlrtDynamicBoundsCheckFastR2012b(k, 1, i, &rc_emlrtBCI, sp);
  }

  emxFree_real_T(&branch_cut_indices);
  n = r7->size[1];
  for (i7 = 0; i7 < n; i7++) {
    BRANCH_CUT_MATRIX->data[r7->data[r7->size[0] * i7] - 1] = 1;
  }

  emxFree_int32_T(&r7);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void calculate_branch_cuts_goldstein(const emlrtStack *sp, emxArray_uint8_T
  *FLAGS_MATRIX, real_T MAX_BOX_SIZE, emxArray_uint8_T *branch_cut_matrix)
{
  int32_T i3;
  int32_T width;
  int32_T height;
  real_T LOC[2];
  int32_T i4;
  int32_T j;
  boolean_T b0;
  int32_T k;
  emxArray_uint8_T *r5;
  boolean_T b1;
  emxArray_uint8_T *r6;
  boolean_T b2;
  int32_T iv28[2];
  int32_T iv29[2];
  emxArray_boolean_T *x;
  int32_T idx;
  int32_T nx;
  boolean_T overflow;
  const mxArray *y;
  static const int32_T iv30[2] = { 1, 36 };

  const mxArray *m10;
  char_T cv22[36];
  int32_T i;
  static const char_T cv23[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'f', 'i', 'n', 'd', '_', 'i', 'n', 'c', 'o', 'm',
    'p', 'a', 't', 'i', 'b', 'l', 'e', 'S', 'h', 'a', 'p', 'e' };

  emxArray_int32_T *ii;
  boolean_T b3;
  boolean_T exitg9;
  boolean_T guard1 = false;
  const mxArray *b_y;
  emxArray_real_T *residue_locs;
  emxArray_real_T *box_rows_01;
  emxArray_real_T *box_cols_01;
  emxArray_real_T *residue_box_rows;
  emxArray_real_T *residue_box_cols;
  emxArray_uint8_T *b_FLAGS_MATRIX;
  real_T r;
  real_T c_y;
  int32_T i5;
  real_T net_charge;
  int32_T box_size;
  boolean_T exitg2;
  real_T b_box_size;
  real_T b_r[2];
  real_T b_height[2];
  const mxArray *d_y;
  static const int32_T iv31[2] = { 1, 36 };

  static const char_T cv24[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *e_y;
  static const int32_T iv32[2] = { 1, 39 };

  char_T cv25[39];
  static const char_T cv26[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T n;
  real_T num_residues_in_box;
  boolean_T exitg8;
  const mxArray *f_y;
  static const int32_T iv33[2] = { 1, 36 };

  const mxArray *g_y;
  static const int32_T iv34[2] = { 1, 39 };

  real_T row_anchor;
  boolean_T exitg7;
  const mxArray *h_y;
  static const int32_T iv35[2] = { 1, 36 };

  const mxArray *i_y;
  static const int32_T iv36[2] = { 1, 39 };

  boolean_T exitg6;
  const mxArray *j_y;
  static const int32_T iv37[2] = { 1, 36 };

  const mxArray *k_y;
  static const int32_T iv38[2] = { 1, 39 };

  boolean_T exitg5;
  int32_T i6;
  boolean_T exitg3;
  real_T col_anchor;
  real_T b_residue_box_rows[2];
  real_T c_height[2];
  boolean_T exitg4;
  real_T d0;
  real_T b_box_rows_01[2];
  real_T b_row_anchor[2];
  boolean_T b_guard1 = false;
  real_T c_row_anchor[2];
  real_T c_box_rows_01[2];
  real_T edge_distances[4];
  boolean_T exitg1;
  real_T dv0[8];
  real_T dv1[2];
  boolean_T b4;
  const mxArray *l_y;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &c_st;
  h_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Create a matrix containing the residue flags */
  /*  This matrix contains [height, width] 8-bit values */
  /*  where the first seven bits of each byte refer in */
  /*  little-endian order to the values of the following */
  /*  flags at each pixel:  */
  /*  2^0 bit = 1 if positive residue, 0 if not positive residue. */
  /*  2^1 bit = 1 if negative residue, 0 if not negative residue. */
  /*  2^2 bit = 1 if the pixel lies on a branch cut, 0 if not. */
  /*  2^3 bit = 1 if the pixel lies on the image border (I think??), 0 if not. */
  /*  2^4 bit = 1 if the pixel represents a balanced residue, 0 if not. */
  /*  2^5 bit = 1 if the pixel represnts an "active residue," i.e. */
  /*    if the pixel is "connected to the current set of branch cuts." */
  /*    I think this means that the pixel is on a branch cut within */
  /*    an active search window. */
  /*  2^6 bit = 1 if the pixel has been unwrapped. */
  /*  Define values for the different flags... */
  /*  Note that matlab indexes bit positions the same way */
  /*  it does arrays, e.g., little-endian bit 1 corresponds to 2^0. */
  /*  Positive residue flag bit-position and byte-value-if-true */
  /*  Negative residue flag bit position and byte-value-if-true */
  /*  Branch cut flag bit position and byte-value-if-true */
  /*  Image border flag bit position and byte-value-if-true */
  /*  Balanced residue flag bit position and byte-value-if-true */
  /*  Active residue flag bit position and byte-value-if-true */
  /*  Unwrapped pixel flag bit position and byte-value-if-true */
  /*  Flag specifying whether a search box has been centered on the */
  /*  pixel. */
  /*  Initial box size */
  /*  Determine matrix height and width */
  i3 = FLAGS_MATRIX->size[1];
  width = emlrtDynamicBoundsCheckFastR2012b(i3, 0, MAX_int32_T, &hb_emlrtBCI, sp);
  height = FLAGS_MATRIX->size[0];

  /*  Add any existing branch cuts to the branch cut matrix */
  st.site = &emlrtRSI;
  b_st.site = &ab_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  for (i3 = 0; i3 < 2; i3++) {
    i4 = FLAGS_MATRIX->size[i3];
    LOC[i3] = emlrtNonNegativeCheckFastR2012b(i4, &db_emlrtDCI, &c_st);
  }

  i3 = branch_cut_matrix->size[0] * branch_cut_matrix->size[1];
  branch_cut_matrix->size[0] = (int32_T)LOC[0];
  branch_cut_matrix->size[1] = (int32_T)LOC[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)branch_cut_matrix, i3, (int32_T)
                    sizeof(uint8_T), &k_emlrtRTEI);
  if (((int32_T)LOC[0] == 0) || ((int32_T)LOC[1] == 0)) {
  } else {
    j = (int32_T)LOC[0] * (int32_T)LOC[1];
    b_st.site = &bb_emlrtRSI;
    if (1 > j) {
      b0 = false;
    } else {
      b0 = (j > 2147483646);
    }

    if (b0) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 0; k + 1 <= j; k++) {
      branch_cut_matrix->data[k] = (uint8_T)((FLAGS_MATRIX->data[k] & 4) != 0);
    }
  }

  /*  Determine the locations of the residues */
  st.site = &b_emlrtRSI;
  b_st.site = &ab_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  for (i3 = 0; i3 < 2; i3++) {
    i4 = FLAGS_MATRIX->size[i3];
    LOC[i3] = emlrtNonNegativeCheckFastR2012b(i4, &db_emlrtDCI, &c_st);
  }

  b_emxInit_uint8_T(&c_st, &r5, 2, &emlrtRTEI, true);
  i3 = r5->size[0] * r5->size[1];
  r5->size[0] = (int32_T)LOC[0];
  r5->size[1] = (int32_T)LOC[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)r5, i3, (int32_T)sizeof(uint8_T),
                    &k_emlrtRTEI);
  if (((int32_T)LOC[0] == 0) || ((int32_T)LOC[1] == 0)) {
  } else {
    j = (int32_T)LOC[0] * (int32_T)LOC[1];
    b_st.site = &bb_emlrtRSI;
    if (1 > j) {
      b1 = false;
    } else {
      b1 = (j > 2147483646);
    }

    if (b1) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 0; k + 1 <= j; k++) {
      r5->data[k] = (uint8_T)((FLAGS_MATRIX->data[k] & 1) != 0);
    }
  }

  st.site = &c_emlrtRSI;
  b_st.site = &ab_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  for (i3 = 0; i3 < 2; i3++) {
    i4 = FLAGS_MATRIX->size[i3];
    LOC[i3] = emlrtNonNegativeCheckFastR2012b(i4, &db_emlrtDCI, &c_st);
  }

  b_emxInit_uint8_T(&c_st, &r6, 2, &emlrtRTEI, true);
  i3 = r6->size[0] * r6->size[1];
  r6->size[0] = (int32_T)LOC[0];
  r6->size[1] = (int32_T)LOC[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)r6, i3, (int32_T)sizeof(uint8_T),
                    &k_emlrtRTEI);
  if (((int32_T)LOC[0] == 0) || ((int32_T)LOC[1] == 0)) {
  } else {
    j = (int32_T)LOC[0] * (int32_T)LOC[1];
    b_st.site = &bb_emlrtRSI;
    if (1 > j) {
      b2 = false;
    } else {
      b2 = (j > 2147483646);
    }

    if (b2) {
      c_st.site = &db_emlrtRSI;
      check_forloop_overflow_error(&c_st, true);
    }

    for (k = 0; k + 1 <= j; k++) {
      r6->data[k] = (uint8_T)((FLAGS_MATRIX->data[k] & 2) != 0);
    }
  }

  for (i3 = 0; i3 < 2; i3++) {
    iv28[i3] = r5->size[i3];
  }

  for (i3 = 0; i3 < 2; i3++) {
    iv29[i3] = r6->size[i3];
  }

  b_emxInit_boolean_T(sp, &x, 2, &emlrtRTEI, true);
  emlrtSizeEqCheck2DFastR2012b(iv28, iv29, &e_emlrtECI, sp);
  st.site = &b_emlrtRSI;
  i3 = x->size[0] * x->size[1];
  x->size[0] = r5->size[0];
  x->size[1] = r5->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)x, i3, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  idx = r5->size[0] * r5->size[1];
  for (i3 = 0; i3 < idx; i3++) {
    x->data[i3] = ((r5->data[i3] != 0) || (r6->data[i3] != 0));
  }

  emxFree_uint8_T(&r6);
  emxFree_uint8_T(&r5);
  b_st.site = &eb_emlrtRSI;
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
    m10 = emlrtCreateCharArray(2, iv30);
    for (i = 0; i < 36; i++) {
      cv22[i] = cv23[i];
    }

    emlrtInitCharArrayR2013a(&b_st, 36, m10, cv22);
    emlrtAssign(&y, m10);
    c_st.site = &ce_emlrtRSI;
    d_st.site = &me_emlrtRSI;
    error(&c_st, b_message(&d_st, y, &c_emlrtMCI), &d_emlrtMCI);
  }

  emxInit_int32_T(&b_st, &ii, 1, &g_emlrtRTEI, true);
  emlrtNonNegativeCheckFastR2012b(nx, &f_emlrtDCI, &b_st);
  i3 = ii->size[0];
  ii->size[0] = nx;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, i3, (int32_T)sizeof(int32_T),
                    &d_emlrtRTEI);
  c_st.site = &fb_emlrtRSI;
  if (1 > nx) {
    b3 = false;
  } else {
    b3 = (nx > 2147483646);
  }

  if (b3) {
    e_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&e_st, true);
  }

  j = 1;
  exitg9 = false;
  while ((!exitg9) && (j <= nx)) {
    guard1 = false;
    if (x->data[j - 1]) {
      idx++;
      ii->data[idx - 1] = j;
      if (idx >= nx) {
        exitg9 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      j++;
    }
  }

  if (idx <= nx) {
  } else {
    b_y = NULL;
    m10 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&b_y, m10);
    c_st.site = &be_emlrtRSI;
    error(&c_st, b_y, &e_emlrtMCI);
  }

  if (nx == 1) {
    if (idx == 0) {
      i3 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i3, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
    }
  } else {
    i3 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i3, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
  }

  emxInit_real_T(&b_st, &residue_locs, 1, &t_emlrtRTEI, true);
  i3 = residue_locs->size[0];
  residue_locs->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)residue_locs, i3, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  idx = ii->size[0];
  for (i3 = 0; i3 < idx; i3++) {
    residue_locs->data[i3] = ii->data[i3];
  }

  /*  Number of residues identified */
  /*  Loop over the residue locations. */
  k = 0;
  emxInit_real_T(sp, &box_rows_01, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &box_cols_01, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &residue_box_rows, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &residue_box_cols, 1, &emlrtRTEI, true);
  b_emxInit_uint8_T(sp, &b_FLAGS_MATRIX, 2, &emlrtRTEI, true);
  while (k <= residue_locs->size[0] - 1) {
    /*  Determine the row and column position of the residue. */
    /*  The following lines are equivalent to (but faster than): */
    /*  [r, c] = ind2sub([height, width], residue_locs(k)); */
    i3 = residue_locs->size[0];
    i4 = k + 1;
    emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &gb_emlrtBCI, sp);
    r = muDoubleScalarRem(residue_locs->data[k] - 1.0, height);
    i3 = residue_locs->size[0];
    i4 = k + 1;
    emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &fb_emlrtBCI, sp);
    c_y = (residue_locs->data[k] - (r + 1.0)) / (real_T)height;

    /*  Check if the pixel is already balanced. */
    st.site = &d_emlrtRSI;
    i3 = FLAGS_MATRIX->size[0];
    i4 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &cb_emlrtDCI, &st);
    emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &eb_emlrtBCI, &st);
    i3 = FLAGS_MATRIX->size[1];
    i4 = (int32_T)emlrtIntegerCheckFastR2012b(c_y + 1.0, &bb_emlrtDCI, &st);
    emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &db_emlrtBCI, &st);

    /*  Ignore the pixel if it's already balanced. */
    /*  or conversely, only continue if the charge isn't already balanced. */
    if (!((FLAGS_MATRIX->data[((int32_T)(r + 1.0) + FLAGS_MATRIX->size[0] *
           ((int32_T)(c_y + 1.0) - 1)) - 1] & 16) != 0)) {
      /*  Mark the residue as "active." */
      st.site = &e_emlrtRSI;
      i3 = FLAGS_MATRIX->size[0];
      i4 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &ab_emlrtDCI, &st);
      emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &cb_emlrtBCI, &st);
      i3 = FLAGS_MATRIX->size[1];
      i4 = (int32_T)emlrtIntegerCheckFastR2012b(c_y + 1.0, &y_emlrtDCI, &st);
      emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &bb_emlrtBCI, &st);
      i3 = FLAGS_MATRIX->size[0];
      i4 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &eb_emlrtDCI, sp);
      i5 = FLAGS_MATRIX->size[1];
      i = (int32_T)emlrtIntegerCheckFastR2012b(c_y + 1.0, &fb_emlrtDCI, sp);
      FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
        &jb_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(i, 1, i5,
        &kb_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data[((int32_T)(r
        + 1.0) + FLAGS_MATRIX->size[0] * ((int32_T)(c_y + 1.0) - 1)) - 1] | 32);

      /*  Set to balanced */
      st.site = &f_emlrtRSI;
      i3 = FLAGS_MATRIX->size[0];
      i4 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &x_emlrtDCI, &st);
      emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &ab_emlrtBCI, &st);
      i3 = FLAGS_MATRIX->size[1];
      i4 = (int32_T)emlrtIntegerCheckFastR2012b(c_y + 1.0, &w_emlrtDCI, &st);
      emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &y_emlrtBCI, &st);
      i3 = FLAGS_MATRIX->size[0];
      i4 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &gb_emlrtDCI, sp);
      i5 = FLAGS_MATRIX->size[1];
      i = (int32_T)emlrtIntegerCheckFastR2012b(c_y + 1.0, &hb_emlrtDCI, sp);
      FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
        &lb_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(i, 1, i5,
        &mb_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data[((int32_T)(r
        + 1.0) + FLAGS_MATRIX->size[0] * ((int32_T)(c_y + 1.0) - 1)) - 1] | 16);

      /*  Calculate the residue charge. */
      st.site = &g_emlrtRSI;
      i3 = FLAGS_MATRIX->size[0];
      i4 = (int32_T)emlrtIntegerCheckFastR2012b(r + 1.0, &v_emlrtDCI, &st);
      emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &x_emlrtBCI, &st);
      i3 = FLAGS_MATRIX->size[1];
      i4 = (int32_T)emlrtIntegerCheckFastR2012b(c_y + 1.0, &u_emlrtDCI, &st);
      emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &w_emlrtBCI, &st);
      if ((FLAGS_MATRIX->data[((int32_T)(r + 1.0) + FLAGS_MATRIX->size[0] *
            ((int32_T)(c_y + 1.0) - 1)) - 1] & 1) != 0) {
        net_charge = 1.0;
      } else {
        net_charge = -1.0;
      }

      /*  Loop over each box size. */
      i3 = (int32_T)((MAX_BOX_SIZE + -1.0) / 2.0);
      emlrtForLoopVectorCheckR2012b(3.0, 2.0, MAX_BOX_SIZE, mxDOUBLE_CLASS, i3,
        &ab_emlrtRTEI, sp);
      box_size = 0;
      exitg2 = false;
      while ((!exitg2) && (box_size <= i3 - 1)) {
        b_box_size = 3.0 + (real_T)box_size * 2.0;

        /*  Determine the extents of the search box. */
        b_r[0] = r + 1.0;
        b_r[1] = c_y + 1.0;
        b_height[0] = height;
        b_height[1] = width;
        st.site = &h_emlrtRSI;
        find_box_coordinates(&st, b_r, b_height, b_box_size, box_rows_01,
                             box_cols_01);

        /*  Count the number of residues in the box */
        st.site = &i_emlrtRSI;
        b_st.site = &gc_emlrtRSI;
        c_st.site = &hc_emlrtRSI;
        if ((box_rows_01->size[0] == 1) || (box_rows_01->size[0] != 1)) {
          overflow = true;
        } else {
          overflow = false;
        }

        if (overflow) {
        } else {
          d_y = NULL;
          m10 = emlrtCreateCharArray(2, iv31);
          for (i = 0; i < 36; i++) {
            cv22[i] = cv24[i];
          }

          emlrtInitCharArrayR2013a(&c_st, 36, m10, cv22);
          emlrtAssign(&d_y, m10);
          e_st.site = &yd_emlrtRSI;
          h_st.site = &le_emlrtRSI;
          error(&e_st, b_message(&h_st, d_y, &s_emlrtMCI), &t_emlrtMCI);
        }

        if (box_rows_01->size[0] > 0) {
        } else {
          e_y = NULL;
          m10 = emlrtCreateCharArray(2, iv32);
          for (i = 0; i < 39; i++) {
            cv25[i] = cv26[i];
          }

          emlrtInitCharArrayR2013a(&c_st, 39, m10, cv25);
          emlrtAssign(&e_y, m10);
          e_st.site = &xd_emlrtRSI;
          h_st.site = &ke_emlrtRSI;
          error(&e_st, b_message(&h_st, e_y, &u_emlrtMCI), &v_emlrtMCI);
        }

        e_st.site = &ic_emlrtRSI;
        nx = 1;
        n = box_rows_01->size[0];
        num_residues_in_box = box_rows_01->data[0];
        if (box_rows_01->size[0] > 1) {
          if (muDoubleScalarIsNaN(box_rows_01->data[0])) {
            f_st.site = &jc_emlrtRSI;
            overflow = (box_rows_01->size[0] > 2147483646);
            if (overflow) {
              g_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&g_st, true);
            }

            idx = 2;
            exitg8 = false;
            while ((!exitg8) && (idx <= n)) {
              nx = idx;
              if (!muDoubleScalarIsNaN(box_rows_01->data[idx - 1])) {
                num_residues_in_box = box_rows_01->data[idx - 1];
                exitg8 = true;
              } else {
                idx++;
              }
            }
          }

          if (nx < box_rows_01->size[0]) {
            f_st.site = &kc_emlrtRSI;
            if (nx + 1 > box_rows_01->size[0]) {
              overflow = false;
            } else {
              overflow = (box_rows_01->size[0] > 2147483646);
            }

            if (overflow) {
              g_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&g_st, true);
            }

            while (nx + 1 <= n) {
              if (box_rows_01->data[nx] < num_residues_in_box) {
                num_residues_in_box = box_rows_01->data[nx];
              }

              nx++;
            }
          }
        }

        st.site = &i_emlrtRSI;
        b_st.site = &lc_emlrtRSI;
        c_st.site = &hc_emlrtRSI;
        if ((box_rows_01->size[0] == 1) || (box_rows_01->size[0] != 1)) {
          overflow = true;
        } else {
          overflow = false;
        }

        if (overflow) {
        } else {
          f_y = NULL;
          m10 = emlrtCreateCharArray(2, iv33);
          for (i = 0; i < 36; i++) {
            cv22[i] = cv24[i];
          }

          emlrtInitCharArrayR2013a(&c_st, 36, m10, cv22);
          emlrtAssign(&f_y, m10);
          e_st.site = &yd_emlrtRSI;
          h_st.site = &le_emlrtRSI;
          error(&e_st, b_message(&h_st, f_y, &s_emlrtMCI), &t_emlrtMCI);
        }

        if (box_rows_01->size[0] > 0) {
        } else {
          g_y = NULL;
          m10 = emlrtCreateCharArray(2, iv34);
          for (i = 0; i < 39; i++) {
            cv25[i] = cv26[i];
          }

          emlrtInitCharArrayR2013a(&c_st, 39, m10, cv25);
          emlrtAssign(&g_y, m10);
          e_st.site = &xd_emlrtRSI;
          h_st.site = &ke_emlrtRSI;
          error(&e_st, b_message(&h_st, g_y, &u_emlrtMCI), &v_emlrtMCI);
        }

        e_st.site = &ic_emlrtRSI;
        nx = 1;
        n = box_rows_01->size[0];
        row_anchor = box_rows_01->data[0];
        if (box_rows_01->size[0] > 1) {
          if (muDoubleScalarIsNaN(box_rows_01->data[0])) {
            f_st.site = &jc_emlrtRSI;
            overflow = (box_rows_01->size[0] > 2147483646);
            if (overflow) {
              g_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&g_st, true);
            }

            idx = 2;
            exitg7 = false;
            while ((!exitg7) && (idx <= n)) {
              nx = idx;
              if (!muDoubleScalarIsNaN(box_rows_01->data[idx - 1])) {
                row_anchor = box_rows_01->data[idx - 1];
                exitg7 = true;
              } else {
                idx++;
              }
            }
          }

          if (nx < box_rows_01->size[0]) {
            f_st.site = &kc_emlrtRSI;
            if (nx + 1 > box_rows_01->size[0]) {
              overflow = false;
            } else {
              overflow = (box_rows_01->size[0] > 2147483646);
            }

            if (overflow) {
              g_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&g_st, true);
            }

            while (nx + 1 <= n) {
              if (box_rows_01->data[nx] > row_anchor) {
                row_anchor = box_rows_01->data[nx];
              }

              nx++;
            }
          }
        }

        if (num_residues_in_box > row_anchor) {
          i4 = 0;
          i5 = 0;
        } else {
          i4 = FLAGS_MATRIX->size[0];
          i5 = (int32_T)emlrtIntegerCheckFastR2012b(num_residues_in_box,
            &t_emlrtDCI, sp);
          i4 = emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &v_emlrtBCI, sp) - 1;
          i5 = FLAGS_MATRIX->size[0];
          i = (int32_T)emlrtIntegerCheckFastR2012b(row_anchor, &t_emlrtDCI, sp);
          i5 = emlrtDynamicBoundsCheckFastR2012b(i, 1, i5, &v_emlrtBCI, sp);
        }

        st.site = &j_emlrtRSI;
        b_st.site = &gc_emlrtRSI;
        c_st.site = &hc_emlrtRSI;
        if ((box_cols_01->size[0] == 1) || (box_cols_01->size[0] != 1)) {
          overflow = true;
        } else {
          overflow = false;
        }

        if (overflow) {
        } else {
          h_y = NULL;
          m10 = emlrtCreateCharArray(2, iv35);
          for (i = 0; i < 36; i++) {
            cv22[i] = cv24[i];
          }

          emlrtInitCharArrayR2013a(&c_st, 36, m10, cv22);
          emlrtAssign(&h_y, m10);
          e_st.site = &yd_emlrtRSI;
          h_st.site = &le_emlrtRSI;
          error(&e_st, b_message(&h_st, h_y, &s_emlrtMCI), &t_emlrtMCI);
        }

        if (box_cols_01->size[0] > 0) {
        } else {
          i_y = NULL;
          m10 = emlrtCreateCharArray(2, iv36);
          for (i = 0; i < 39; i++) {
            cv25[i] = cv26[i];
          }

          emlrtInitCharArrayR2013a(&c_st, 39, m10, cv25);
          emlrtAssign(&i_y, m10);
          e_st.site = &xd_emlrtRSI;
          h_st.site = &ke_emlrtRSI;
          error(&e_st, b_message(&h_st, i_y, &u_emlrtMCI), &v_emlrtMCI);
        }

        e_st.site = &ic_emlrtRSI;
        nx = 1;
        n = box_cols_01->size[0];
        num_residues_in_box = box_cols_01->data[0];
        if (box_cols_01->size[0] > 1) {
          if (muDoubleScalarIsNaN(box_cols_01->data[0])) {
            f_st.site = &jc_emlrtRSI;
            overflow = (box_cols_01->size[0] > 2147483646);
            if (overflow) {
              g_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&g_st, true);
            }

            idx = 2;
            exitg6 = false;
            while ((!exitg6) && (idx <= n)) {
              nx = idx;
              if (!muDoubleScalarIsNaN(box_cols_01->data[idx - 1])) {
                num_residues_in_box = box_cols_01->data[idx - 1];
                exitg6 = true;
              } else {
                idx++;
              }
            }
          }

          if (nx < box_cols_01->size[0]) {
            f_st.site = &kc_emlrtRSI;
            if (nx + 1 > box_cols_01->size[0]) {
              overflow = false;
            } else {
              overflow = (box_cols_01->size[0] > 2147483646);
            }

            if (overflow) {
              g_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&g_st, true);
            }

            while (nx + 1 <= n) {
              if (box_cols_01->data[nx] < num_residues_in_box) {
                num_residues_in_box = box_cols_01->data[nx];
              }

              nx++;
            }
          }
        }

        st.site = &j_emlrtRSI;
        b_st.site = &lc_emlrtRSI;
        c_st.site = &hc_emlrtRSI;
        if ((box_cols_01->size[0] == 1) || (box_cols_01->size[0] != 1)) {
          overflow = true;
        } else {
          overflow = false;
        }

        if (overflow) {
        } else {
          j_y = NULL;
          m10 = emlrtCreateCharArray(2, iv37);
          for (i = 0; i < 36; i++) {
            cv22[i] = cv24[i];
          }

          emlrtInitCharArrayR2013a(&c_st, 36, m10, cv22);
          emlrtAssign(&j_y, m10);
          e_st.site = &yd_emlrtRSI;
          h_st.site = &le_emlrtRSI;
          error(&e_st, b_message(&h_st, j_y, &s_emlrtMCI), &t_emlrtMCI);
        }

        if (box_cols_01->size[0] > 0) {
        } else {
          k_y = NULL;
          m10 = emlrtCreateCharArray(2, iv38);
          for (i = 0; i < 39; i++) {
            cv25[i] = cv26[i];
          }

          emlrtInitCharArrayR2013a(&c_st, 39, m10, cv25);
          emlrtAssign(&k_y, m10);
          e_st.site = &xd_emlrtRSI;
          h_st.site = &ke_emlrtRSI;
          error(&e_st, b_message(&h_st, k_y, &u_emlrtMCI), &v_emlrtMCI);
        }

        e_st.site = &ic_emlrtRSI;
        nx = 1;
        n = box_cols_01->size[0];
        row_anchor = box_cols_01->data[0];
        if (box_cols_01->size[0] > 1) {
          if (muDoubleScalarIsNaN(box_cols_01->data[0])) {
            f_st.site = &jc_emlrtRSI;
            overflow = (box_cols_01->size[0] > 2147483646);
            if (overflow) {
              g_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&g_st, true);
            }

            idx = 2;
            exitg5 = false;
            while ((!exitg5) && (idx <= n)) {
              nx = idx;
              if (!muDoubleScalarIsNaN(box_cols_01->data[idx - 1])) {
                row_anchor = box_cols_01->data[idx - 1];
                exitg5 = true;
              } else {
                idx++;
              }
            }
          }

          if (nx < box_cols_01->size[0]) {
            f_st.site = &kc_emlrtRSI;
            if (nx + 1 > box_cols_01->size[0]) {
              overflow = false;
            } else {
              overflow = (box_cols_01->size[0] > 2147483646);
            }

            if (overflow) {
              g_st.site = &db_emlrtRSI;
              check_forloop_overflow_error(&g_st, true);
            }

            while (nx + 1 <= n) {
              if (box_cols_01->data[nx] > row_anchor) {
                row_anchor = box_cols_01->data[nx];
              }

              nx++;
            }
          }
        }

        if (num_residues_in_box > row_anchor) {
          i = 0;
          i6 = 0;
        } else {
          i = FLAGS_MATRIX->size[1];
          i6 = (int32_T)emlrtIntegerCheckFastR2012b(num_residues_in_box,
            &s_emlrtDCI, sp);
          i = emlrtDynamicBoundsCheckFastR2012b(i6, 1, i, &u_emlrtBCI, sp) - 1;
          i6 = FLAGS_MATRIX->size[1];
          j = (int32_T)emlrtIntegerCheckFastR2012b(row_anchor, &s_emlrtDCI, sp);
          i6 = emlrtDynamicBoundsCheckFastR2012b(j, 1, i6, &u_emlrtBCI, sp);
        }

        j = b_FLAGS_MATRIX->size[0] * b_FLAGS_MATRIX->size[1];
        b_FLAGS_MATRIX->size[0] = i5 - i4;
        b_FLAGS_MATRIX->size[1] = i6 - i;
        emxEnsureCapacity(sp, (emxArray__common *)b_FLAGS_MATRIX, j, (int32_T)
                          sizeof(uint8_T), &emlrtRTEI);
        idx = i6 - i;
        for (i6 = 0; i6 < idx; i6++) {
          nx = i5 - i4;
          for (j = 0; j < nx; j++) {
            b_FLAGS_MATRIX->data[j + b_FLAGS_MATRIX->size[0] * i6] =
              FLAGS_MATRIX->data[(i4 + j) + FLAGS_MATRIX->size[0] * (i + i6)];
          }
        }

        st.site = &k_emlrtRSI;
        num_residues_in_box = count_residues(&st, b_FLAGS_MATRIX);

        /*  Find the coordinates of all the residues in the box. */
        i4 = residue_locs->size[0];
        i5 = 1 + k;
        st.site = &l_emlrtRSI;
        find_residue_positions(&st, FLAGS_MATRIX, box_rows_01, box_cols_01,
          residue_locs->data[emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
          &nb_emlrtBCI, sp) - 1], num_residues_in_box, residue_box_rows,
          residue_box_cols);

        /*  Determine the positions of all of the residues in the box.  */
        /*  The "_local" name here is meant to indicate that these */
        /*  are the coordinates in the frame of the box, not in the */
        /*  overall residue matrix.        */
        /*  Loop over the number of residues contained in the box. */
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, num_residues_in_box,
          mxDOUBLE_CLASS, (int32_T)num_residues_in_box, &y_emlrtRTEI, sp);
        n = 0;
        exitg3 = false;
        while ((!exitg3) && (n <= (int32_T)num_residues_in_box - 1)) {
          /*  Set the anchor pixel to the n'th residue detected in the */
          /*  box */
          i4 = residue_box_rows->size[0];
          row_anchor = residue_box_rows->data[emlrtDynamicBoundsCheckFastR2012b
            (n + 1, 1, i4, &ob_emlrtBCI, sp) - 1];
          i4 = residue_box_cols->size[0];
          col_anchor = residue_box_cols->data[emlrtDynamicBoundsCheckFastR2012b
            (n + 1, 1, i4, &pb_emlrtBCI, sp) - 1];

          /*  Determine the extents of the search box centered */
          b_residue_box_rows[0] = residue_box_rows->data[n];
          b_residue_box_rows[1] = residue_box_cols->data[n];
          c_height[0] = height;
          c_height[1] = width;
          st.site = &m_emlrtRSI;
          find_box_coordinates(&st, b_residue_box_rows, c_height, b_box_size,
                               box_rows_01, box_cols_01);

          /*  Determine the number of box pixels. */
          /*  Loop over the box pixels. */
          nx = 1;
          exitg4 = false;
          while ((!exitg4) && (nx - 1 <= box_rows_01->size[0] - 1)) {
            /*  Get the flags for the box pixel */
            i4 = FLAGS_MATRIX->size[0];
            i5 = box_rows_01->size[0];
            d0 = box_rows_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1, i5,
              &qb_emlrtBCI, sp) - 1];
            i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &r_emlrtDCI, sp);
            emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &t_emlrtBCI, sp);
            i4 = FLAGS_MATRIX->size[1];
            i5 = box_cols_01->size[0];
            d0 = box_cols_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1, i5,
              &rb_emlrtBCI, sp) - 1];
            i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &q_emlrtDCI, sp);
            emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &s_emlrtBCI, sp);

            /*  Check if box pixel is a border pixel. */
            st.site = &n_emlrtRSI;
            if ((FLAGS_MATRIX->data[((int32_T)box_rows_01->data[nx - 1] +
                  FLAGS_MATRIX->size[0] * ((int32_T)box_cols_01->data[nx - 1] -
                   1)) - 1] & 8) != 0) {
              /*  Set the residue to balanced */
              /*  if the box contains a border pixel. */
              st.site = &o_emlrtRSI;
              i4 = FLAGS_MATRIX->size[0];
              i5 = (int32_T)emlrtIntegerCheckFastR2012b(row_anchor, &p_emlrtDCI,
                &st);
              emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &r_emlrtBCI, &st);
              i4 = FLAGS_MATRIX->size[1];
              i5 = (int32_T)emlrtIntegerCheckFastR2012b(col_anchor, &o_emlrtDCI,
                &st);
              emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &q_emlrtBCI, &st);
              i4 = FLAGS_MATRIX->size[0];
              i5 = (int32_T)row_anchor;
              i = FLAGS_MATRIX->size[1];
              i6 = (int32_T)col_anchor;
              FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
                &lc_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                                  (emlrtDynamicBoundsCheckFastR2012b(i6, 1, i,
                &mc_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data
                [((int32_T)row_anchor + FLAGS_MATRIX->size[0] * ((int32_T)
                col_anchor - 1)) - 1] | 16);

              /*  Set the net charge in the box to zero */
              /*  if the box contains a border pixel. */
              net_charge = 0.0;

              /*  Place a branch cut between the active pixel */
              /*  and the box (border) pixel */
              i4 = box_rows_01->size[0];
              b_box_rows_01[0] = box_rows_01->
                data[emlrtDynamicBoundsCheckFastR2012b(nx, 1, i4, &nc_emlrtBCI,
                sp) - 1];
              i4 = box_cols_01->size[0];
              b_box_rows_01[1] = box_cols_01->
                data[emlrtDynamicBoundsCheckFastR2012b(nx, 1, i4, &oc_emlrtBCI,
                sp) - 1];
              b_row_anchor[0] = row_anchor;
              b_row_anchor[1] = col_anchor;
              st.site = &p_emlrtRSI;
              place_branch_cut(&st, branch_cut_matrix, FLAGS_MATRIX,
                               b_box_rows_01, b_row_anchor);

              /*  Check if the box pixel is both a residue and not already active    */
            } else {
              st.site = &q_emlrtRSI;
              b_guard1 = false;
              if ((FLAGS_MATRIX->data[((int32_T)box_rows_01->data[nx - 1] +
                    FLAGS_MATRIX->size[0] * ((int32_T)box_cols_01->data[nx - 1]
                     - 1)) - 1] & 1) != 0) {
                b_guard1 = true;
              } else {
                st.site = &r_emlrtRSI;
                if ((FLAGS_MATRIX->data[((int32_T)box_rows_01->data[nx - 1] +
                      FLAGS_MATRIX->size[0] * ((int32_T)box_cols_01->data[nx - 1]
                       - 1)) - 1] & 2) != 0) {
                  b_guard1 = true;
                }
              }

              if (b_guard1) {
                /*  Check if the pixel is balanced. */
                st.site = &s_emlrtRSI;
                i4 = FLAGS_MATRIX->size[0];
                i5 = box_rows_01->size[0];
                d0 = box_rows_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                  i5, &sb_emlrtBCI, &st) - 1];
                i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &n_emlrtDCI, &st);
                emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &p_emlrtBCI, &st);
                i4 = FLAGS_MATRIX->size[1];
                i5 = box_cols_01->size[0];
                d0 = box_cols_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                  i5, &tb_emlrtBCI, &st) - 1];
                i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &m_emlrtDCI, &st);
                emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &o_emlrtBCI, &st);

                /*  If the pixel is not already balanced, add its */
                /*  polarity to to the net charge and mark as balanced. */
                if (!((FLAGS_MATRIX->data[((int32_T)box_rows_01->data[nx - 1] +
                       FLAGS_MATRIX->size[0] * ((int32_T)box_cols_01->data[nx -
                        1] - 1)) - 1] & 16) != 0)) {
                  /*  Add the pixel's charge to the net charge. */
                  st.site = &t_emlrtRSI;
                  i4 = FLAGS_MATRIX->size[0];
                  i5 = box_rows_01->size[0];
                  d0 = box_rows_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    i5, &ub_emlrtBCI, &st) - 1];
                  i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &l_emlrtDCI, &st);
                  emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &n_emlrtBCI, &st);
                  i4 = FLAGS_MATRIX->size[1];
                  i5 = box_cols_01->size[0];
                  d0 = box_cols_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    i5, &vb_emlrtBCI, &st) - 1];
                  i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &k_emlrtDCI, &st);
                  emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &m_emlrtBCI, &st);
                  b_st.site = &jd_emlrtRSI;
                  if ((FLAGS_MATRIX->data[((int32_T)box_rows_01->data[nx - 1] +
                        FLAGS_MATRIX->size[0] * ((int32_T)box_cols_01->data[nx -
                         1] - 1)) - 1] & 1) != 0) {
                    j = 1;
                  } else {
                    b_st.site = &kd_emlrtRSI;
                    if ((FLAGS_MATRIX->data[((int32_T)box_rows_01->data[nx - 1]
                          + FLAGS_MATRIX->size[0] * ((int32_T)box_cols_01->
                           data[nx - 1] - 1)) - 1] & 2) != 0) {
                      j = -1;
                    } else {
                      j = 0;
                    }
                  }

                  net_charge += (real_T)j;

                  /*  Set the pixel to balanced. */
                  st.site = &u_emlrtRSI;
                  i4 = FLAGS_MATRIX->size[0];
                  i5 = box_rows_01->size[0];
                  d0 = box_rows_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    i5, &wb_emlrtBCI, &st) - 1];
                  i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &j_emlrtDCI, &st);
                  emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &l_emlrtBCI, &st);
                  i4 = FLAGS_MATRIX->size[1];
                  i5 = box_cols_01->size[0];
                  d0 = box_cols_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    i5, &xb_emlrtBCI, &st) - 1];
                  i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &i_emlrtDCI, &st);
                  emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &k_emlrtBCI, &st);
                  i4 = FLAGS_MATRIX->size[0];
                  i5 = box_rows_01->size[0];
                  d0 = box_rows_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    i5, &ac_emlrtBCI, sp) - 1];
                  i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &ib_emlrtDCI, sp);
                  i = FLAGS_MATRIX->size[1];
                  i6 = box_cols_01->size[0];
                  d0 = box_cols_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                    i6, &cc_emlrtBCI, sp) - 1];
                  i6 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &jb_emlrtDCI, sp);
                  FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i5, 1,
                    i4, &yb_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(i6, 1,
                    i, &bc_emlrtBCI, sp) - 1)) - 1] = (uint8_T)
                    (FLAGS_MATRIX->data[((int32_T)box_rows_01->data[nx - 1] +
                      FLAGS_MATRIX->size[0] * ((int32_T)box_cols_01->data[nx - 1]
                       - 1)) - 1] | 16);
                }

                /*  End checking for balanced charge. */
                /*  Set the pixel to active. */
                st.site = &v_emlrtRSI;
                i4 = FLAGS_MATRIX->size[0];
                i5 = box_rows_01->size[0];
                d0 = box_rows_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                  i5, &dc_emlrtBCI, &st) - 1];
                i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &h_emlrtDCI, &st);
                emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &j_emlrtBCI, &st);
                i4 = FLAGS_MATRIX->size[1];
                i5 = box_cols_01->size[0];
                d0 = box_cols_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                  i5, &ec_emlrtBCI, &st) - 1];
                i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &g_emlrtDCI, &st);
                emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &i_emlrtBCI, &st);
                i4 = FLAGS_MATRIX->size[0];
                i5 = box_rows_01->size[0];
                d0 = box_rows_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                  i5, &gc_emlrtBCI, sp) - 1];
                i5 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &kb_emlrtDCI, sp);
                i = FLAGS_MATRIX->size[1];
                i6 = box_cols_01->size[0];
                d0 = box_cols_01->data[emlrtDynamicBoundsCheckFastR2012b(nx, 1,
                  i6, &ic_emlrtBCI, sp) - 1];
                i6 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &lb_emlrtDCI, sp);
                FLAGS_MATRIX->data[(emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
                  &fc_emlrtBCI, sp) + FLAGS_MATRIX->size[0] *
                                    (emlrtDynamicBoundsCheckFastR2012b(i6, 1, i,
                  &hc_emlrtBCI, sp) - 1)) - 1] = (uint8_T)(FLAGS_MATRIX->data
                  [((int32_T)box_rows_01->data[nx - 1] + FLAGS_MATRIX->size[0] *
                    ((int32_T)box_cols_01->data[nx - 1] - 1)) - 1] | 32);

                /*  Place a branch cut between that pixel  */
                /*  and the residue at which the box is centered. */
                c_row_anchor[0] = row_anchor;
                c_row_anchor[1] = col_anchor;
                i4 = box_rows_01->size[0];
                c_box_rows_01[0] = box_rows_01->
                  data[emlrtDynamicBoundsCheckFastR2012b(nx, 1, i4, &jc_emlrtBCI,
                  sp) - 1];
                i4 = box_cols_01->size[0];
                c_box_rows_01[1] = box_cols_01->
                  data[emlrtDynamicBoundsCheckFastR2012b(nx, 1, i4, &kc_emlrtBCI,
                  sp) - 1];
                st.site = &w_emlrtRSI;
                place_branch_cut(&st, branch_cut_matrix, FLAGS_MATRIX,
                                 c_row_anchor, c_box_rows_01);
              }
            }

            /*  End box pixel conditions */
            /*  Break the loop-over-box-pixels loop */
            /*  if the net charge is zero. */
            if (net_charge == 0.0) {
              exitg4 = true;
            } else {
              nx++;
              emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
            }
          }

          /*  End looping over box pixels. */
          /*  Break the loop if the net charge goes to zero. */
          if (net_charge == 0.0) {
            exitg3 = true;
          } else {
            n++;
            emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
          }
        }

        /*  Break the loop if the net charge is zero. */
        if (net_charge == 0.0) {
          exitg2 = true;
        } else {
          box_size++;
          emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
        }
      }

      /*  End looping over box size. */
      /*  If the max box size is reached, place a branch cut from the  */
      /*  active pixel to the nearest border. */
      if (net_charge != 0.0) {
        /*  branch_cut_to_edge */
        st.site = &x_emlrtRSI;
        LOC[0] = r + 1.0;
        LOC[1] = c_y + 1.0;

        /*  Measure height and width of the branch cut matrix. */
        i3 = branch_cut_matrix->size[1];
        emlrtDynamicBoundsCheckFastR2012b(i3, 0, MAX_int32_T, &h_emlrtBCI, &st);

        /*  Row and column positions of branch cut origin. */
        /*  Calculate distance from the pixel to the edges */
        edge_distances[0] = r + 1.0;
        edge_distances[1] = (real_T)branch_cut_matrix->size[0] - (r + 1.0);
        edge_distances[2] = c_y + 1.0;
        edge_distances[3] = (real_T)branch_cut_matrix->size[1] - (c_y + 1.0);

        /*  Edge coordinates: top, bottom, left, right */
        /*  Find the location of the minimum */
        b_st.site = &ld_emlrtRSI;
        c_st.site = &nd_emlrtRSI;
        e_st.site = &od_emlrtRSI;
        f_st.site = &ic_emlrtRSI;
        nx = 1;
        num_residues_in_box = r + 1.0;
        j = 0;
        if (muDoubleScalarIsNaN(r + 1.0)) {
          idx = 2;
          exitg1 = false;
          while ((!exitg1) && (idx < 5)) {
            nx = idx;
            if (!muDoubleScalarIsNaN(edge_distances[idx - 1])) {
              num_residues_in_box = edge_distances[idx - 1];
              j = idx - 1;
              exitg1 = true;
            } else {
              idx++;
            }
          }
        }

        if (nx < 4) {
          while (nx + 1 < 5) {
            if (edge_distances[nx] < num_residues_in_box) {
              num_residues_in_box = edge_distances[nx];
              j = nx;
            }

            nx++;
          }
        }

        /*  Coordinates on border to connect with a branch cut. */
        /*  Place the branch cut. */
        dv0[0] = 1.0;
        dv0[4] = c_y + 1.0;
        dv0[1] = branch_cut_matrix->size[0];
        dv0[5] = c_y + 1.0;
        dv0[2] = r + 1.0;
        dv0[6] = 1.0;
        dv0[3] = r + 1.0;
        dv0[7] = branch_cut_matrix->size[1];
        for (i3 = 0; i3 < 2; i3++) {
          dv1[i3] = dv0[j + (i3 << 2)];
        }

        b_st.site = &md_emlrtRSI;
        place_branch_cut(&b_st, branch_cut_matrix, FLAGS_MATRIX, LOC, dv1);
      }
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_uint8_T(&b_FLAGS_MATRIX);
  emxFree_real_T(&residue_box_cols);
  emxFree_real_T(&residue_box_rows);
  emxFree_real_T(&box_cols_01);
  emxFree_real_T(&box_rows_01);
  emxFree_real_T(&residue_locs);

  /*  Set branch cut pixels to one. */
  st.site = &y_emlrtRSI;
  i3 = x->size[0] * x->size[1];
  x->size[0] = branch_cut_matrix->size[0];
  x->size[1] = branch_cut_matrix->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)x, i3, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  idx = branch_cut_matrix->size[0] * branch_cut_matrix->size[1];
  for (i3 = 0; i3 < idx; i3++) {
    x->data[i3] = (branch_cut_matrix->data[i3] > 0);
  }

  n = x->size[0] * x->size[1];
  b_st.site = &pd_emlrtRSI;
  k = 0;
  c_st.site = &rd_emlrtRSI;
  if (1 > n) {
    b4 = false;
  } else {
    b4 = (n > 2147483646);
  }

  if (b4) {
    e_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&e_st, true);
  }

  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      k++;
    }
  }

  if (k <= n) {
  } else {
    l_y = NULL;
    m10 = emlrtCreateString("Assertion failed.");
    emlrtAssign(&l_y, m10);
    b_st.site = &ae_emlrtRSI;
    error(&b_st, l_y, &x_emlrtMCI);
  }

  emlrtNonNegativeCheckFastR2012b(k, &e_emlrtDCI, &st);
  i3 = ii->size[0];
  ii->size[0] = k;
  emxEnsureCapacity(&st, (emxArray__common *)ii, i3, (int32_T)sizeof(int32_T),
                    &s_emlrtRTEI);
  j = 0;
  b_st.site = &qd_emlrtRSI;
  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      ii->data[j] = i;
      j++;
    }
  }

  emxFree_boolean_T(&x);
  j = branch_cut_matrix->size[0];
  nx = branch_cut_matrix->size[1];
  idx = ii->size[0];
  for (i3 = 0; i3 < idx; i3++) {
    i4 = j * nx;
    i5 = ii->data[i3];
    branch_cut_matrix->data[emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
      &ib_emlrtBCI, sp) - 1] = 1;
  }

  emxFree_int32_T(&ii);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (calculate_branch_cuts_goldstein.c) */
