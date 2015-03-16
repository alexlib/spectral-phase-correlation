/*
 * calculate_branch_cuts_goldstein_mexutil.h
 *
 * Code generation for function 'calculate_branch_cuts_goldstein_mexutil'
 *
 */

#ifndef __CALCULATE_BRANCH_CUTS_GOLDSTEIN_MEXUTIL_H__
#define __CALCULATE_BRANCH_CUTS_GOLDSTEIN_MEXUTIL_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "calculate_branch_cuts_goldstein_types.h"

/* Function Declarations */
extern const mxArray *b_message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);
extern void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

#endif

/* End of code generation (calculate_branch_cuts_goldstein_mexutil.h) */
