#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#include "point_multiplication.h"

int main (int argc, char const *argv[])
{
    struct Curve curve;
	struct Point P, T;
	mpz_t d;

	curve_init (&curve);
	point_init (&P);
	point_init (&T);
	mpz_init (d);

	mpz_set_str (curve.a, "-3", 10);
	mpz_set_str (curve.b, "2455155546008943817740293915197451784769108058161191238065", 10);
	mpz_set_str (curve.p, "6277101735386680763835789423207666416083908700390324961279", 10);

	mpz_set_str (P.x, "602046282375688656758213480587526111916698976636884684818", 10);
	mpz_set_str (P.y, "174050332293622031404857552280219410364023488927386650641", 10);

	mpz_set_str (d, "6277101735386680763835789423176059013767194773180000000000", 10);

	double_and_add (&T, P, d, curve);

	gmp_printf ("x = %Zd\n", T.x);
	gmp_printf ("y = %Zd\n", T.y);

	curve_clear (&curve);
	point_clear (&P);
	point_clear (&T); 
	mpz_clear (d);

	return 0;
}