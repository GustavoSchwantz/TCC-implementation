#include <gmp.h>
#include "curve.h"

void point_init (struct Point *P)
{
	mpz_init (P->x);
	mpz_init (P->y);
}

void curve_init (struct Curve *c)
{
	mpz_init (c->a);
	mpz_init (c->b);
	mpz_init (c->p);
}

void point_clear (struct Point *P)
{
	mpz_clear (P->x);
	mpz_clear (P->y);
}

void curve_clear (struct Curve *c)
{
	mpz_clear (c->a);
	mpz_clear (c->b);
	mpz_clear (c->p);
}

