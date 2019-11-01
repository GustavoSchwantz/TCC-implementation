#include <stdio.h>
#include <gmp.h>
#include "curve.h"
#include "group_operation.h"
#include "point_multiplication.h"

void double_and_add (struct Point *T, const struct Point P, mpz_t d, const struct Curve c)
{
    mpz_set (T->x, P.x);
    mpz_set (T->y, P.y);

    int i;

    for (i = (mpz_sizeinbase (d, 2) - 2) ; i >= 0 ; --i) {
        point_operation (T, *T, *T, c);

        if (mpz_tstbit (d, i) == 1) 
            point_operation (T, P, *T, c);
    }
}
