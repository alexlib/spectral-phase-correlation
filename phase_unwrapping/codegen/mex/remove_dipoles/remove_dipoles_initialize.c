/*
 * remove_dipoles_initialize.c
 *
 * Code generation for function 'remove_dipoles_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "remove_dipoles.h"
#include "remove_dipoles_initialize.h"
#include "remove_dipoles_data.h"

/* Function Definitions */
void remove_dipoles_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (remove_dipoles_initialize.c) */
