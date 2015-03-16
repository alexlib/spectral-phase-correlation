/*
 * calculate_branch_cuts_goldstein.h
 *
 * Code generation for function 'calculate_branch_cuts_goldstein'
 *
 */

#ifndef __CALCULATE_BRANCH_CUTS_GOLDSTEIN_H__
#define __CALCULATE_BRANCH_CUTS_GOLDSTEIN_H__

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
extern void calculate_branch_cuts_goldstein(const emlrtStack *sp,
  emxArray_uint8_T *FLAGS_MATRIX, real_T MAX_BOX_SIZE, emxArray_uint8_T
  *branch_cut_matrix);

#endif

/* End of code generation (calculate_branch_cuts_goldstein.h) */
