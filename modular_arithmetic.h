#ifndef _MODULAR_ARITHMETIC_H_
#define _MODULAR_ARITHMETIC_H_

void mod_add (mpz_t a, mpz_t b, mpz_t c, mpz_t n);
void mod_sub (mpz_t a, mpz_t b, mpz_t c, mpz_t n);
void mod_mul (mpz_t a, mpz_t b, mpz_t c, mpz_t n);
void mod_div (mpz_t a, mpz_t b, mpz_t c, mpz_t n);

#endif
