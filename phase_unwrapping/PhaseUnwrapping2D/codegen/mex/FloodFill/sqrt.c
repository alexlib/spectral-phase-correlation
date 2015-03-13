/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FloodFill.h"
#include "sqrt.h"
#include "eml_error.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 14, "sqrt",
  "/Applications/MATLAB_R2014b.app/toolbox/eml/lib/matlab/elfun/sqrt.m" };

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T k;
  int32_T i3;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (k = 0; k < x->size[0]; k++) {
    if (x->data[k] < 0.0) {
      st.site = &p_emlrtRSI;
      eml_error(&st);
    }
  }

  i3 = x->size[0];
  for (k = 0; k < i3; k++) {
    x->data[k] = muDoubleScalarSqrt(x->data[k]);
  }
}

/* End of code generation (sqrt.c) */
