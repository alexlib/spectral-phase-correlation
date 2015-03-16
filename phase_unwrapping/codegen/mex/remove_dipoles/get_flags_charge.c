/*
 * get_flags_charge.c
 *
 * Code generation for function 'get_flags_charge'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "remove_dipoles.h"
#include "get_flags_charge.h"

/* Function Definitions */
real_T get_flags_charge(uint8_T FLAG)
{
  real_T CHARGE;
  if ((FLAG & 1) != 0) {
    CHARGE = 1.0;
  } else if ((FLAG & 2) != 0) {
    CHARGE = -1.0;
  } else {
    CHARGE = 0.0;
  }

  return CHARGE;
}

/* End of code generation (get_flags_charge.c) */
