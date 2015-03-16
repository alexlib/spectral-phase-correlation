/*
 * find_residue_locs.h
 *
 * Code generation for function 'find_residue_locs'
 *
 */

#ifndef __FIND_RESIDUE_LOCS_H__
#define __FIND_RESIDUE_LOCS_H__

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
#include "remove_dipoles_types.h"

/* Function Declarations */
extern void find_residue_locs(const emlrtStack *sp, const emxArray_uint8_T
  *FLAGS_MATRIX, emxArray_real_T *RESIDUE_LOCS);

#endif

/* End of code generation (find_residue_locs.h) */
