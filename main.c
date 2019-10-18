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
	struct Point P, T;
	mpz_t k;

	curve_init (&curve);
	point_init (&P);
	point_init (&T);
	mpz_init (k);

	mpz_set_str (curve.a, "2", 10);
	mpz_set_str (curve.b, "2", 10);
	mpz_set_str (curve.p, "17", 10);

	mpz_set_str (P.x, "5", 10);
	mpz_set_str (P.y, "1", 10);

	mpz_set_str (k, "10", 10);

	double_and_add (&P, &T, k, &curve);

	gmp_printf ("x3 = %Zd\n", T.x);
	gmp_printf ("y3 = %Zd\n", T.y);

	curve_clear (&curve);
	point_clear (&P);
	point_clear (&T); 
	mpz_clear (k);

	return 0;
}
