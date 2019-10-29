#ifndef _POINT_MULTIPLICATION_H_
#define _POINT_MULTIPLICATION_H_

#include <gmp.h>
#include "curve.h"

void double_and_add (struct Point *T, const struct Point P, mpz_t d, const struct Curve c);

#endif 