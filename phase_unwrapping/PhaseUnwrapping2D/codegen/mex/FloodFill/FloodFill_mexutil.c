/*
 * FloodFill_mexutil.c
 *
 * Code generation for function 'FloodFill_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FloodFill.h"
#include "FloodFill_mexutil.h"

/* Function Definitions */
void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

const mxArray *message(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
  *location)
{
  const mxArray *pArray;
  const mxArray *m7;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 1, &pArray, "message", true, location);
}

/* End of code generation (FloodFill_mexutil.c) */
