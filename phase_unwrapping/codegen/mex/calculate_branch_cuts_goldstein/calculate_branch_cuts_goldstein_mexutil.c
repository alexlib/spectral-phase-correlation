/*
 * calculate_branch_cuts_goldstein_mexutil.c
 *
 * Code generation for function 'calculate_branch_cuts_goldstein_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculate_branch_cuts_goldstein.h"
#include "calculate_branch_cuts_goldstein_mexutil.h"

/* Function Definitions */
const mxArray *b_message(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
  *location)
{
  const mxArray *pArray;
  const mxArray *m8;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m8, 1, &pArray, "message", true, location);
}

void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

/* End of code generation (calculate_branch_cuts_goldstein_mexutil.c) */
