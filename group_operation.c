#include <gmp.h>
#include "curve.h"
#include "modular_arithmetic.h"

void point_addition (struct Point *R, const struct Point P, const struct Point Q, const struct Curve c)
{
    mpz_t temp1, temp2, temp3, s;

    mpz_init (temp1); mpz_init (temp2); mpz_init (temp3); mpz_init (s);

	// s = (y2 - y1)/(x2 - x1) mod p
	mpz_sub (temp1, Q.y, P.y);
	mpz_sub (temp2, Q.x, P.x);
	mod_div (s, temp1, temp2, c.p);

	// x3 = s^2 - x1 - x2 mod p
	mpz_pow_ui (temp1, s, 2);
	mpz_sub (temp2, temp1, P.x);
	mod_sub (R->x, temp2, Q.x, c.p);

	// y3 = s*(x1 - x3) - y1 mod p
	mpz_sub (temp1, P.x, R->x);
	mpz_mul (temp2, s, temp1);
	mod_sub (R->y, temp2, P.y, c.p);

    mpz_clear (temp1); mpz_clear (temp2); mpz_clear (temp3); mpz_clear (s);
}

void point_doubling (struct Point *R, const struct Point P, const struct Curve c)
{
	mpz_t temp1, temp2, temp3, s;

    mpz_init (temp1); mpz_init (temp2); mpz_init (temp3); mpz_init (s);

	// s = (3*x1^2 + a)/2*y1 mod p
	mpz_pow_ui (temp1, P.x, 2);
	mpz_mul_ui (temp2, temp1, 3);
    mpz_add (temp3, temp2, c.a);
    mpz_mul_ui (temp1, P.y, 2);
    mod_div (s, temp3, temp1, c.p);

	// x3 = s^2 - x1 - x2 mod p
	mpz_pow_ui (temp1, s, 2);
	mpz_sub (temp2, temp1, P.x);
	mod_sub (R->x, temp2, P.x, c.p);

	// y3 = s*(x1 - x3) - y1 mod p
	mpz_sub (temp1, P.x, R->x);
	gmp_printf ("x1 = %Zd\n", P.x);
	mpz_mul (temp2, s, temp1);
	mod_sub (R->y, temp2, P.y, c.p);

    mpz_clear (temp1); mpz_clear (temp2); mpz_clear (temp3); mpz_clear (s); 
}

