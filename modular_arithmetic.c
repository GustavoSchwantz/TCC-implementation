#include <gmp.h>

void mod_add (mpz_t a, mpz_t b, mpz_t c, mpz_t n)
{
	mpz_t temp;

	mpz_init (temp);

	mpz_add (temp, a, b);
	mpz_mod (c, temp, n);

	mpz_clear (temp);
}

void mod_sub (mpz_t a, mpz_t b, mpz_t c, mpz_t n)
{
	mpz_t temp;

	mpz_init (temp);

	mpz_sub (temp, a, b);
	mpz_mod (c, temp, n);

	mpz_clear (temp);
}

void mod_mul (mpz_t a, mpz_t b, mpz_t c, mpz_t n)
{
	mpz_t temp;

	mpz_init (temp);

	mpz_mul (temp, a, b);
	mpz_mod (c, temp, n);

	mpz_clear (temp);
}

void mod_div (mpz_t a, mpz_t b, mpz_t c, mpz_t n)
{
	mpz_t temp1, temp2;

	mpz_init (temp1);
	mpz_init (temp2);

    mpz_invert (temp1, b, n);
	mpz_mul (temp2, a, temp1);
	mpz_mod (c, temp2, n);

	mpz_clear (temp1);
	mpz_clear (temp2);
}