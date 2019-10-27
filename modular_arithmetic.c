#include <gmp.h>

void mod_add (mpz_t r, const mpz_t op1, const mpz_t op2, const mpz_t n)
{
	mpz_t temp;

	mpz_init (temp);

	mpz_add (temp, op1, op2);
	mpz_mod (r, temp, n);

	mpz_clear (temp);
}

void mod_sub (mpz_t r, const mpz_t op1, const mpz_t op2, const mpz_t n)
{
	mpz_t temp;

	mpz_init (temp);

	mpz_sub (temp, op1, op2);
	mpz_mod (r, temp, n);

	mpz_clear (temp);
}

void mod_mul (mpz_t r, const mpz_t op1, const mpz_t op2, const mpz_t n)
{
	mpz_t temp;

	mpz_init (temp);

	mpz_mul (temp, op1, op2);
	mpz_mod (r, temp, n);

	mpz_clear (temp);
}

void mod_div (mpz_t r, const mpz_t op1, const mpz_t op2, const mpz_t n)
{
	mpz_t op2_inv, temp;

	mpz_init (op2_inv);
	mpz_init (temp);
    
    mpz_invert (op2_inv, op2, n);
	mpz_mul (temp, op1, op2_inv);
	mpz_mod (r, temp, n);

	mpz_clear (op2_inv);
	mpz_clear (temp);
}