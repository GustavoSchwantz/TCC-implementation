#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#include "modular_arithmetic.h"

int main (int argc, char const *argv[])
{
	mpz_t op1, op2, n, r;

	mpz_init (op1), mpz_init (op2), mpz_init (n), mpz_init (r);

	mpz_set_str (op1, "42", 10);
	mpz_set_str (op2, "313", 10);
	mpz_set_str (n, "17", 10);

	mod_div (r, op1, op2, n);

	gmp_printf ("r = %Zd\n", r);

	mpz_swap (op1, op2);

	mod_div (r, op1, op2, n);

	gmp_printf ("r = %Zd\n", r);

	mpz_neg (op2, op2);

	mod_div (r, op1, op2, n);

	gmp_printf ("r = %Zd\n", r);

	mpz_neg (op1, op1);

	mod_div (r, op1, op2, n);

	gmp_printf ("r = %Zd\n", r);

	mpz_clear (op1), mpz_clear (op2), mpz_clear (n), mpz_clear (r);

	return 0;
}