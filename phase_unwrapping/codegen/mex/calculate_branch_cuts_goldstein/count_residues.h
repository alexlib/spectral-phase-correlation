/*
 * count_residues.h
 *
 * Code generation for function 'count_residues'
 *
 */

#ifndef __COUNT_RESIDUES_H__
#define __COUNT_RESIDUES_H__

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
extern real_T count_residues(const emlrtStack *sp, const emxArray_uint8_T
  *FLAGS_MATRIX);

#ifdef __WATCOMC__

#pragma aux count_residues value [8087];

#endif
#endif

/* End of code generation (count_residues.h) */
