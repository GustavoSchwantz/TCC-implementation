#include <stdio.h>
#include <gmp.h>
#include "curve.h"
#include "group_operation.h"
#include "point_multiplication.h"

void double_and_add (struct Point *T, const struct Point P, mpz_t d, const struct Curve c)
{
	if ( mpz_cmp_si (d, 0) == 0 ) {
    	mpz_set_str (T->x, "0", 10);
	    mpz_set_str (T->y, "0", 10);
	    mpz_set (T->k, c.n);

	    return;
    }

    mpz_set (T->x, P.x);
    mpz_set (T->y, P.y);
    mpz_set (T->k, P.k);

    int i;

    // gmp_printf ("T = (%Zd, %Zd), k = %Zd\n", T->x, T->y, T->k);

    for (i = (mpz_sizeinbase (d, 2) - 2) ; i >= 0 ; --i) {
        point_operation (T, *T, *T, c);

        // gmp_printf ("T depois do Doubling = (%Zd, %Zd), k = %Zd\n", T->x, T->y, T->k);

        if (mpz_tstbit (d, i) == 1) {
            point_operation (T, *T, P, c);
            // gmp_printf ("T depois da Addition = (%Zd, %Zd), k = %Zd\n", T->x, T->y, T->k);
        }
    }
}
