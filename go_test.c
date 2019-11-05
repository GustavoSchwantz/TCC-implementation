#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#include "modular_arithmetic.h"
#include "group_operation.h"

int main (int argc, char const *argv[])
{
	struct Curve curve;
	struct Point P, Q, R, O;
	mpz_t n;

	mpz_init_set_str (n, "19", 10);

	curve_init (&curve, n);
	point_init (&P);
	point_init (&Q);
	point_init (&R);
	point_init (&O);

	mpz_set_str (curve.a, "2", 10);
	mpz_set_str (curve.b, "2", 10);
	mpz_set_str (curve.p, "17", 10);

	mpz_set_str (P.x, "5", 10);
	mpz_set_str (P.y, "1", 10);

	mpz_set_str (Q.x, "5", 10);
	mpz_set_str (Q.y, "16", 10);
	mpz_set_str (Q.k, "18", 10);

	mpz_set_str (O.x, "0", 10);
	mpz_set_str (O.y, "0", 10);
	mpz_set_str (O.k, "19", 10);

	point_operation (&R, P, P, curve);

	//gmp_printf ("x1 = %Zd\n", P.x);
	//gmp_printf ("y1 = %Zd\n", P.y);
	gmp_printf ("R = (%Zd, %Zd), k = %Zd\n", R.x, R.y, R.k);

	int i;

	for (i = 0; i < 50; ++i) {
        point_operation (&R, R, P, curve);

		gmp_printf ("R = (%Zd, %Zd), k = %Zd\n", R.x, R.y, R.k);
	}

	curve_clear (&curve);
	point_clear (&P);
	point_clear (&Q); 
	point_clear (&R);
	point_clear (&O);
	mpz_clear (n);

	return 0;
}
