
/* @(#)z_ceilf.c 1.0 98/08/13 */
/*****************************************************************
 * ceil
 *
 * Input:
 *   x  - floating point value
 *
 * Output:
 *   Smallest integer greater than x.
 *
 * Description:
 *   This routine returns the smallest integer greater than x.
 *
 *****************************************************************/

#include "fdlibm.h"
#include "zmath.h"

float
_DEFUN (ceilf, (float),
        float x)
{
  float f, y;

  y = modff (x, &f);

  if (y == 0.0f)
    return (x);
  else if (x > -1.0f && x < 1.0f)
    return (x > 0.0f ? 1.0f : 0.0f);
  else
    return (x > 0.0f ? f + 1.0f : f);
}

#ifdef _DOUBLE_IS_32BITS
double ceil (double x)
{
  return (double) ceilf ((float) x);
}

#endif /* defined(_DOUBLE_IS_32BITS) */
