/*
 * FloodFill_initialize.c
 *
 * Code generation for function 'FloodFill_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FloodFill.h"
#include "FloodFill_initialize.h"
#include "FloodFill_data.h"

/* Function Definitions */
void FloodFill_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (FloodFill_initialize.c) */
