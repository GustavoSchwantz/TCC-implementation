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

	mpz_set_str (P.x, "3", 10);
	mpz_set_str (P.y, "6", 10);

	mpz_set_str (Q.x, "5", 10);
	mpz_set_str (Q.y, "1", 10);

	point_doubling (&Q, &R, &curve);

	gmp_printf ("x3 = %Zd\n", R.x);
	gmp_printf ("y3 = %Zd\n", R.y);

	curve_clear (&curve);
	point_clear (&P);
	point_clear (&Q);
	point_clear (&R);

	return 0;
}
