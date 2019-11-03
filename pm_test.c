#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#include "point_multiplication.h"

void points_are_equal (const struct Point E, const struct Point R);

int main (int argc, char const *argv[])
{
    struct Curve c1;
	struct Point P, T, R;
	mpz_t d, n;

	mpz_init_set_str (n, "6277101735386680763835789423176059013767194773182842284081", 10);

	curve_init (&c1, n); 
 	point_init (&P);  // ponto gerador
	point_init (&R);  // irá guardar resultado
	point_init (&T);  // resultado esperado
	mpz_init (d);     // secret key
    
    // curva P-192 do NIST
	mpz_set_str (c1.a, "-3", 10);
	mpz_set_str (c1.b, "64210519e59c80e70fa7e9ab72243049feb8deecc146b9b1", 16);
	mpz_set_str (c1.p, "6277101735386680763835789423207666416083908700390324961279", 10);
    
    // ponto gerador dado junto com a curva P-192 do NIST
	mpz_set_str (P.x, "188da80eb03090f67cbf20eb43a18800f4ff0afd82ff1012", 16);
	mpz_set_str (P.y, "07192b95ffc8da78631011ed6b24cdd573f977a11e794811", 16);
    
    mpz_set_str (d, "1", 10); // setando um valor para a secret key: d = 1
    
    // resultado esperado para a key anterior calculado usando-se http://www.christelbach.com/ECCalculator.aspx
	mpz_set_str (T.x, "602046282375688656758213480587526111916698976636884684818", 10);
	mpz_set_str (T.y, "174050332293622031404857552280219410364023488927386650641", 10);

	double_and_add (&R, P, d, c1);

	points_are_equal (T, R);

	mpz_set_str (d, "6277101735386680763835789423176059013767194773182842284080", 10); // setando d =  n - 1
    
    // resultado esperado para a key anterior calculado usando-se http://www.christelbach.com/ECCalculator.aspx
	mpz_set_str (T.x, "602046282375688656758213480587526111916698976636884684818", 10);
	mpz_set_str (T.y, "6103051403093058732430931870927447005719885211462938310638", 10);

	double_and_add (&R, P, d, c1);

	points_are_equal (T, R);

	mpz_set_str (d, "627710173538668076383578942", 10); // setando d para um valor arbitrario
    
    // resultado esperado para a key anterior calculado usando-se http://www.christelbach.com/ECCalculator.aspx
	mpz_set_str (T.x, "2668995205919493605924576127814201094718996035497877442924", 10);
	mpz_set_str (T.y, "2802168224337809892214402629952556760108172192407412665833", 10);

	double_and_add (&R, P, d, c1);

	points_are_equal (T, R);

	mpz_set_str (d, "6277101735386680763835789423176059013767194773182842284081", 10); // setando d = n
    
    // resultado esperado para a key anterior calculado usando-se http://www.christelbach.com/ECCalculator.aspx
	mpz_set_str (T.x, "0", 10);
	mpz_set_str (T.y, "0", 10);

	double_and_add (&R, P, d, c1);

	points_are_equal (T, R);

	// gmp_printf ("x = %Zd\n", R.x);
	// gmp_printf ("y = %Zd\n", R.y);

	curve_clear (&c1);
	point_clear (&P);
	point_clear (&R);
	point_clear (&T); 
	mpz_clear (d);
	mpz_clear (n);

	return 0;
}

void points_are_equal (const struct Point E, const struct Point R)
{
	if ( mpz_cmp (E.x, R.x) == 0 &&  mpz_cmp (E.y, R.y) == 0)
		printf("TRUE!\n");
	else
		printf("FALSE!\n");
}