
/* @(#)z_expf.c 1.0 98/08/13 */
/******************************************************************
 * The following routines are coded directly from the algorithms
 * and coefficients given in "Software Manual for the Elementary
 * Functions" by William J. Cody, Jr. and William Waite, Prentice
 * Hall, 1980.
 ******************************************************************/
/******************************************************************
 * Exponential Function
 *
 * Input:
 *   x - floating point value
 *
 * Output:
 *   e raised to x.
 *
 * Description:
 *   This routine returns e raised to the xth power.
 *
 *****************************************************************/

#include <float.h>
#include "fdlibm.h"
#include "zmath.h"

static const float INV_LN2 = 1.442695040;
static const float LN2 = 0.693147180;
static const float p0 = 0.249999999950;
static const float p1 = 0.00416028863;
static const float q0 = 0.5;
static const float q1 = 0.04998717878;

float
_DEFUN (expf, (float),
        float x)
{
  int N;
  float g, z, R, P, Q;

  switch (numtestf (x))
    {
      case NAN:
        errno = EDOM;
        return (x);
      case INF:
        errno = ERANGE;
        if (isposf (x))
          return (z_infinity_f.f);
        else
          return (0.0);
      case 0:
        return (1.0);
    }

  /* Check for out of bounds. */
  if (x > BIGX_F || x < SMALLX_F)
    {
      errno = ERANGE;
      return (x);
    }

  /* Check for a value too small to calculate. */
  if (-z_rooteps_f < x && x < z_rooteps_f)
    {
      return (1.0);
    }

  /* Calculate the exponent. */
  if (x < (float)0.0)
    N = (int) (x * INV_LN2 - (float)0.5);
  else
    N = (int) (x * INV_LN2 + (float)0.5);

  /* Construct the mantissa. */
  g = x - (float)N * LN2;
  z = g * g;
  P = g * (p1 * z + p0);
  Q = q1 * z + q0;
  R = 0.5f + P / (Q - P);

  /* Return the floating point value. */
  N++;
  return (ldexpf (R, N));
}

#ifdef _DOUBLE_IS_32BITS

double exp (double x)
{
  return (double) expf ((float) x);
}

#endif /* _DOUBLE_IS_32BITS */
