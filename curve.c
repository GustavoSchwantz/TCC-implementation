#include <gmp.h>
#include "curve.h"

void point_init (struct Point *P)
{
	mpz_init (P->x);
	mpz_init (P->y);
	mpz_init (P->k);

	mpz_set_str (P->k, "1", 10);
}

void curve_init (struct Curve *c, const mpz_t n)
{
	mpz_init (c->a);
	mpz_init (c->b);
	mpz_init (c->p);
	mpz_init (c->n);

	mpz_set (c->n, n);
}

void point_clear (struct Point *P)
{
	mpz_clear (P->x);
	mpz_clear (P->y);
	mpz_clear (P->k);
}

void curve_clear (struct Curve *c)
{
	mpz_clear (c->a);
	mpz_clear (c->b);
	mpz_clear (c->p);
	mpz_clear (c->n);
}

