/*
 * unwrap.c
 *
 * Code generation for function 'unwrap'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FloodFill.h"
#include "unwrap.h"

/* Function Definitions */
void unwrap(real_T p[2])
{
  real_T cumsum_dp_corr;
  int32_T k;
  real_T pkm1;
  int32_T exitg1;
  real_T r;
  real_T dps;
  cumsum_dp_corr = 0.0;
  k = 1;
  while ((k < 2) && (!((!muDoubleScalarIsInf(p[0])) && (!muDoubleScalarIsNaN(p[0])))))
  {
    k = 2;
  }

  if (k < 2) {
    pkm1 = p[0];
    do {
      exitg1 = 0;
      k++;
      while ((k <= 2) && (!((!muDoubleScalarIsInf(p[1])) &&
                            (!muDoubleScalarIsNaN(p[1]))))) {
        k = 3;
      }

      if (k > 2) {
        exitg1 = 1;
      } else {
        pkm1 = p[1] - pkm1;
        r = (pkm1 + 3.1415926535897931) / 6.2831853071795862;
        if (muDoubleScalarAbs(r - muDoubleScalarRound(r)) <=
            2.2204460492503131E-16 * muDoubleScalarAbs(r)) {
          r = 0.0;
        } else {
          r = (r - muDoubleScalarFloor(r)) * 6.2831853071795862;
        }

        dps = r - 3.1415926535897931;
        if ((r - 3.1415926535897931 == -3.1415926535897931) && (pkm1 > 0.0)) {
          dps = 3.1415926535897931;
        }

        if (muDoubleScalarAbs(pkm1) >= 3.1415926535897931) {
          cumsum_dp_corr += dps - pkm1;
        }

        pkm1 = p[1];
        p[1] += cumsum_dp_corr;
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (unwrap.c) */
