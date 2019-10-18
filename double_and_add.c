#include <gmp.h>
#include "curve.h"
#include "group_operation.h"

void double_and_add (struct Point *P, struct Point *T, mpz_t k, struct Curve *c)
{
	int d;
	*T = *P;

    for (d = mpz_sizeinbase (k, 2) - 2; d == 0; --d) {

    	point_doubling (T, T, c);

    	if (mpz_tstbit (k, d))
    		point_addition (T, P, T, c);
    }
}