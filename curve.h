#ifndef _CURVE_H_
#define _CURVE_H_

// define um ponto da curva elíptica 
struct Point { 
    mpz_t x, y; 
    mpz_t k;   // quantos pontos P's geradores são usados para representar o ponto 
}; 

// define uma curva elíptica
struct Curve {
	mpz_t a, b;
    mpz_t p;
    mpz_t n;   // ordem da curva
};

// inicializa um ponto
void point_init (struct Point *P);
// inicializa uma curva
void curve_init (struct Curve *c, const mpz_t n);
// destroi o ponto
void point_clear (struct Point *P);
// destroi a curva
void curve_clear (struct Curve *c);

#endif

