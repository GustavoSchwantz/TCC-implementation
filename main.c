#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#include "modular_arithmetic.h"

// define um ponto da curva elíptica 
struct Point { 
    mpz_t x, y; 
}; 

// define uma curva elíptica
struct Curve {
	mpz_t a, b;
    mpz_t p;
};

void point_init (struct Point *P);
void curve_init (struct Curve *c);
void point_clear (struct Point *P);
void curve_clear (struct Curve *c);
struct Point * addition (struct Point *P, struct Point *Q, struct Curve *c);

int main (int argc, char const *argv[])
{
	mpz_t op1, op2, p, r;

	mpz_init (r);
    
    mpz_init_set_str (op1, "313", 10);
	mpz_init_set_str (op2, "42", 10);
	mpz_init_set_str (p, "17", 10);

	mod_div (op1, op2, r, p);
    
    gmp_printf ("%Zd\n", r);

	mpz_clear (op1);
	mpz_clear (op2);
	mpz_clear (r);
	mpz_clear (p);

	return 0;
}

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