#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#include "modular_arithmetic.h"
#include "group_operation.h"

int main (int argc, char const *argv[])
{
	struct Curve curve;
	struct Point P, Q, R;

	curve_init (&curve);
	point_init (&P);
	point_init (&Q);
	point_init (&R);

	mpz_set_str (curve.a, "2", 10);
	mpz_set_str (curve.b, "2", 10);
	mpz_set_str (curve.p, "17", 10);

	mpz_set_str (P.x, "5", 10);
	mpz_set_str (P.y, "1", 10);

	mpz_set_str (Q.x, "16", 10);
	mpz_set_str (Q.y, "13", 10);

	point_doubling (&R, P, curve);

	//gmp_printf ("x1 = %Zd\n", P.x);
	//gmp_printf ("y1 = %Zd\n", P.y);
	gmp_printf ("x3 = %Zd\n", R.x);
	gmp_printf ("y3 = %Zd\n", R.y);

	int i;

	for (i = 0; i < 17; ++i) {
        point_addition (&R, P, R, curve);

		gmp_printf ("x3 = %Zd\n", R.x);
	    gmp_printf ("y3 = %Zd\n", R.y);
	}

	curve_clear (&curve);
	point_clear (&P);
	point_clear (&Q); 
	point_clear (&R);

	return 0;
}
