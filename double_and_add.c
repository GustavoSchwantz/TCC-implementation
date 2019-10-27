#include <gmp.h>
#include "curve.h"
#include "group_operation.h"

void double_and_add (struct Point *P, struct Point *T, mpz_t k, struct Curve *c)
{
	int d;
	struct Point R;

	point_init (&R);

	*T = *P;

    for (d = (mpz_sizeinbase (k, 2) - 1); d >= 1; --d) {

    	point_doubling (T, &R, c);
        
        mpz_set (T->x, R.x);
        mpz_set (T->y, R.y);

    	if (mpz_tstbit (k, d))
    		point_addition (T, P, &R, c);

    	mpz_set (T->x, R.x);
        mpz_set (T->y, R.y);
    }

    point_clear (&R);
}