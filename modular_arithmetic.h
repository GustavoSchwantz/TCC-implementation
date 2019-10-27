#ifndef _MODULAR_ARITHMETIC_H_
#define _MODULAR_ARITHMETIC_H_

void mod_add (mpz_t r, const mpz_t op1, const mpz_t op2, const mpz_t n);
void mod_sub (mpz_t r, const mpz_t op1, const mpz_t op2, const mpz_t n);
void mod_mul (mpz_t r, const mpz_t op1, const mpz_t op2, const mpz_t n);
void mod_div (mpz_t r, const mpz_t op1, const mpz_t op2, const mpz_t n);

#endif
