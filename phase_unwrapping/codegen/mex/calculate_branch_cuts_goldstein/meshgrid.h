/*
 * meshgrid.h
 *
 * Code generation for function 'meshgrid'
 *
 */

#ifndef __MESHGRID_H__
#define __MESHGRID_H__

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
extern void meshgrid(const emlrtStack *sp, const emxArray_real_T *x, const
                     emxArray_real_T *y, emxArray_real_T *xx, emxArray_real_T
                     *yy);

#endif

/* End of code generation (meshgrid.h) */
