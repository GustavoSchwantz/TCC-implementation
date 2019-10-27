#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#include "modular_arithmetic.h"
#include "group_operation.h"
#include "double_and_add.h"

int main (int argc, char const *argv[])
{
	struct Curve curve;
	struct Point P, T, R;
	mpz_t k;

	curve_init (&curve);
	point_init (&P);
	point_init (&T);
	point_init (&R);
	mpz_init (k);

	mpz_set_str (curve.a, "2", 10);
	mpz_set_str (curve.b, "2", 10);
	mpz_set_str (curve.p, "17", 10);

	mpz_set_str (P.x, "5", 10);
	mpz_set_str (P.y, "1", 10);

	mpz_set_str (T.x, "5", 10);
	mpz_set_str (T.y, "1", 10);

	mpz_set_str (k, "10", 10);

	// double_and_add (&P, &T, k, &curve);

	R = point_addition (P, T, curve);

	gmp_printf ("x3 = %Zd\n", R.x);
	gmp_printf ("y3 = %Zd\n", R.y);

	curve_clear (&curve);
	point_clear (&P);
	point_clear (&T); 
	point_clear (&R);
	mpz_clear (k);

	/*mpz_t n;

	mpz_init (n);
    
    // 42 = 00101010
	mpz_set_str (n, "42", 10);
    
    printf("%ld\n", mpz_sizeinbase (n, 2) - 2);

	mpz_clear (n);*/

	return 0;
}
