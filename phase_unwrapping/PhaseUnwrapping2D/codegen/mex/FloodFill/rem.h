/*
 * rem.h
 *
 * Code generation for function 'rem'
 *
 */

#ifndef __REM_H__
#define __REM_H__

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
#include "FloodFill_types.h"

/* Function Declarations */
extern void b_rem(const emlrtStack *sp, const emxArray_real_T *x, real_T y,
                  emxArray_real_T *r);

#endif

/* End of code generation (rem.h) */
