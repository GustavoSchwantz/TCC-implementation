#ifndef _DOUBLE_AND_ADD_H_
#define _DOUBLE_AND_ADD_H_

#include <gmp.h>
#include "curve.h"

void double_and_add (struct Point *P, struct Point *T, mpz_t k, struct Curve *c);

#endif 