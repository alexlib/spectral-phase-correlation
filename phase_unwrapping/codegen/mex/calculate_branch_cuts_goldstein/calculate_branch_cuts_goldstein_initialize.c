/*
 * calculate_branch_cuts_goldstein_initialize.c
 *
 * Code generation for function 'calculate_branch_cuts_goldstein_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculate_branch_cuts_goldstein.h"
#include "calculate_branch_cuts_goldstein_initialize.h"
#include "calculate_branch_cuts_goldstein_data.h"

/* Function Definitions */
void calculate_branch_cuts_goldstein_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (calculate_branch_cuts_goldstein_initialize.c) */
