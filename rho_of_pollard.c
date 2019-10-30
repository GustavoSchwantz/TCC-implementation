#include <stdio.h>
#include <gmp.h>

#include "curve.h"
#include "point_multiplication.h"
#include "group_operation.h"

#define L 32

void H (mpz_t j, const struct Point x);
void mul_and_add (struct Point *R, mpz_t a, mpz_t b, const struct Point P, 
	const struct Point Q, const struct Curve c);

int main(int argc, char const *argv[])
{
	struct Curve c;
	struct Point P, Q, R;
	mpz_t a, b;

	curve_init (&c); 
 	point_init (&P);  
	point_init (&Q);
	point_init (&R); 
	mpz_init (a);
	mpz_init (b);     
    
	mpz_set_str (c.a, "2", 10);
	mpz_set_str (c.b, "2", 10);
	mpz_set_str (c.p, "17", 10);
    
	mpz_set_str (P.x, "5", 10);
	mpz_set_str (P.y, "1", 10);

	mpz_set_str (Q.x, "10", 10);
	mpz_set_str (Q.y, "11", 10);

	mpz_set_str (a, "42", 10);
	mpz_set_str (b, "300", 10);

	// mul_and_add (&R, a, b, P, Q, c);
	double_and_add (&R, P, a, c);

	gmp_printf ("x = %Zd\n", R.x);
	gmp_printf ("y = %Zd\n", R.y);

	curve_clear (&c);
	point_clear (&P);
	point_clear (&Q);
	point_clear (&R);
	mpz_clear (a);
	mpz_clear (b);

	return 0;
}

void H (mpz_t j, const struct Point P)
{
	mpz_t temp;

	mpz_init (temp);

	mpz_mod_ui (temp, P.x, L);
	mpz_add_ui (j, temp, 1);

	mpz_clear (temp);
}

void mul_and_add (struct Point *R, mpz_t a, mpz_t b, const struct Point P, 
	const struct Point Q, const struct Curve c)
{
	struct Point T1, T2;

 	point_init (&T1);  
	point_init (&T2); 
    
	double_and_add (&T1, P, a, c);
	double_and_add (&T2, Q, b, c);

	gmp_printf ("x = %Zd\n", T1.x);
	gmp_printf ("y = %Zd\n", T1.y);
	gmp_printf ("x = %Zd\n", T2.x);
	gmp_printf ("y = %Zd\n", T2.y);

	point_addition (R, T1, T2, c);

	point_clear (&T1);
	point_clear (&T2);
}	