
/* @(#)z_floorf.c 1.0 98/08/13 */
/*****************************************************************
 * floor 
 *
 * Input:
 *   x  - floating point value
 *
 * Output:
 *   Smallest integer less than x.
 *
 * Description:
 *   This routine returns the smallest integer less than x.
 *
 *****************************************************************/

#include "fdlibm.h"
#include "zmath.h"

float
_DEFUN (floorf, (float),
        float x)
{
  float f, y;

  if (x > -1.0f && x < 1.0f)
    return (x >= 0.0f ? 0.0f : -1.0f);

  y = modff (x, &f);

  if (y == 0.0f)
    return (x);

  return (x >= 0.0f ? f : f - 1.0f);
}

#ifdef _DOUBLE_IS_32BITS
double floor (double x)
{
  return (double) floorf ((float) x);
}

#endif /* defined(_DOUBLE_IS_32BITS) */
