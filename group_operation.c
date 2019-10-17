#include <gmp.h>
#include "curve.h"
#include "modular_arithmetic.h"

void point_addition (struct Point *P, struct Point *Q, struct Point *R, struct Curve *c)
{
	mpz_t s;
	mpz_t temp1, temp2;
	mpz_t exp;

	mpz_init (s), mpz_init (temp1), mpz_init (temp2);
	mpz_init_set_str (exp, "2", 10);

    // s = (y2 - y1) / (x2 - x1) mod p
    mod_sub (Q->y, P->y, temp1, c->p);
    mod_sub (Q->x, P->x, temp2, c->p);
	mod_div (temp1, temp2, s, c->p);
    
    // x3 = s^2 - x1 - x2 mod p
    mpz_powm (temp1, s, exp, c->p);
    mod_sub (temp1, P->x, temp2, c->p);
    mod_sub (temp2, Q->x, temp1, c->p);
	mpz_set (R->x, temp1);
    
    // y3 = s*(x1 - x3) - y1 mod p
	mod_sub (P->x, R->x, temp1, c->p);
	mod_mul (s, temp1, temp2, c->p);
	mod_sub (temp2, P->y, R->y, c->p);

	mpz_clear (s), mpz_clear (temp1), mpz_clear (temp2), mpz_clear (exp);
}

void point_doubling (struct Point *P, struct Point *R, struct Curve *c)
{
	mpz_t s;
	mpz_t temp1, temp2;
	mpz_t exp;
	mpz_t c3;

	mpz_init (s), mpz_init (temp1), mpz_init (temp2);
	mpz_init_set_str (exp, "2", 10);
	mpz_init_set_str (c3, "3", 10);

    // s =  3*x^2 + a / 2*y1 mod p
    mpz_powm (temp1, P->x, exp, c->p);
    mod_mul (c3, temp1, temp2, c->p);
    mod_add (temp2, c->a, temp1, c->p);
    mod_mul (exp, P->y, temp2, c->p);
	mod_div (temp1, temp2, s, c->p);
    
    // x3 = s^2 - x1 - x2 mod p
    mpz_powm (temp1, s, exp, c->p);
    mod_sub (temp1, P->x, temp2, c->p);
    mod_sub (temp2, P->x, temp1, c->p);
	mpz_set (R->x, temp1);
    
    // y3 = s*(x1 - x3) - y1 mod p
	mod_sub (P->x, R->x, temp1, c->p);
	mod_mul (s, temp1, temp2, c->p);
	mod_sub (temp2, P->y, R->y, c->p);

	mpz_clear (s), mpz_clear (temp1), mpz_clear (temp2), mpz_clear (exp),
	mpz_clear (c3);
}