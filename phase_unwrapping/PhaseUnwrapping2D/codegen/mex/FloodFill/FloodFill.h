/*
 * FloodFill.h
 *
 * Code generation for function 'FloodFill'
 *
 */

#ifndef __FLOODFILL_H__
#define __FLOODFILL_H__

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
extern void FloodFill(const emlrtStack *sp, const emxArray_real_T *IM_phase,
                      const emxArray_uint8_T *branch_cuts, emxArray_real_T
                      *IM_unwrapped, emxArray_real_T *rowref, emxArray_real_T
                      *colref);

#endif

/* End of code generation (FloodFill.h) */
