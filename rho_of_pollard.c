#include <stdio.h>
#include <gmp.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "curve.h"
#include "modular_arithmetic.h"
#include "point_multiplication.h"
#include "group_operation.h"

#define L 4

struct Triple {
	mpz_t a, b;
    struct Point P;
};

void triple_init (struct Triple *t);
void triple_clear (struct Triple *t);
void table_init (struct Triple t[L]);
void table_clear (struct Triple t[L]);
int H (const struct Point P);
void set_random (mpz_t a, mpz_t b, const mpz_t n);
void mul_and_add (struct Point *R, mpz_t a, mpz_t b, const struct Point P, 
	const struct Point Q, const struct Curve c);
void rho_of_pollard (mpz_t d, const struct Point P, const struct Point Q, 
	const mpz_t n, const struct Curve c);

int main(int argc, char const *argv[])
{
	struct Curve c;
	struct Point P, Q, R;
	mpz_t d, n;

	mpz_init_set_str (n, "239", 10);

	curve_init (&c, n); 
 	point_init (&P);  
	point_init (&Q);
	point_init (&R);
	mpz_init (d);
    
	mpz_set_str (c.a, "1", 10);
	mpz_set_str (c.b, "44", 10);
	mpz_set_str (c.p, "229", 10);
    
	mpz_set_str (P.x, "5", 10);
	mpz_set_str (P.y, "116", 10);

	mpz_set_str (Q.x, "155", 10);
	mpz_set_str (Q.y, "166", 10);
	mpz_set_str (Q.k, "176", 10);

	rho_of_pollard (d, P, Q, n, c);

	gmp_printf ("d = %Zd\n", d);

	curve_clear (&c);
	point_clear (&P);
	point_clear (&Q);
	point_clear (&R);
	mpz_clear (d);
	mpz_clear (n);

	return 0;
}

void triple_init (struct Triple *t)
{
	mpz_init (t->a);
	mpz_init (t->b);
	point_init (&(t->P));
}

void triple_clear (struct Triple *t)
{
	mpz_clear (t->a);
	mpz_clear (t->b);
	point_clear (&(t->P));
}

void table_init (struct Triple t[L])
{
	int i;
    
    for (i = 0; i < L; ++i)
    	triple_init (&t[i]);
}

void table_clear (struct Triple t[L])
{
	int i;
    
    for (i = 0; i < L; ++i)
    	triple_clear (&t[i]);
}

int H (const struct Point P)
{
	return mpz_fdiv_ui (P.x, L);
}

void set_random (mpz_t a, mpz_t b, const mpz_t n)
{
	gmp_randstate_t state;
	
	gmp_randinit_mt (state);

	// início código StackOverflow
    int fp = open("/dev/random", O_RDONLY);
    if (fp == -1) abort();
    unsigned seed;
    unsigned pos = 0;
    while (pos < sizeof(seed)) {
        int amt = read(fp, (char *) &seed + pos, sizeof(seed) - pos);
        if (amt <= 0) abort();
        pos += amt;
    }
    close(fp);
	// fim código StackOverflow

	gmp_randseed_ui (state, seed);

	mpz_urandomm (a, state, n);
	mpz_urandomm (b, state, n);

	gmp_randclear (state);
}

void mul_and_add (struct Point *R, mpz_t a, mpz_t b, const struct Point P, 
	const struct Point Q, const struct Curve c)
{
	struct Point T1, T2;

 	point_init (&T1);  
	point_init (&T2); 
    
	double_and_add (&T1, P, a, c);
	double_and_add (&T2, Q, b, c);

	point_operation (R, T1, T2, c);

	point_clear (&T1);
	point_clear (&T2);
}	

void rho_of_pollard (mpz_t d, const struct Point P, const struct Point Q, 
	const mpz_t n, const struct Curve c)
{
	struct Triple table[L];
	struct Point X1, X2;
	int i, j;
	mpz_t c1, c2, d1, d2;
	mpz_t temp1, temp2, temp3;

	point_init (&X1);
	point_init (&X2);
	table_init (table);
	mpz_init (c1); mpz_init (c2); mpz_init (d1); mpz_init (d2);
	mpz_init (temp1); mpz_init (temp2); mpz_init (temp3);

	for (j = 0; j < L; ++j) {
		set_random (table[j].a, table[j].b, n);
        mul_and_add (&(table[j].P), table[j].a, table[j].b, P, Q, c);
	}

    set_random (c1, d1, n);
    mul_and_add (&X1, c1, d1, P, Q, c);

    mpz_set (X2.x, X1.x); mpz_set (X2.y, X1.y); mpz_set (X2.k, X1.k); 
    mpz_set (c2, c1); mpz_set (d2, d1);

    do {

    	j = H (X1); 

    	point_operation (&X1, X1, table[j].P, c);
    	mod_add (c1, c1, table[j].a, n);
    	mod_add (d1, d1, table[j].b, n);

    	for (i = 0; i < 2; ++i) {
    		j = H (X2); 

    	    point_operation (&X2, X2, table[j].P, c);
    	    mod_add (c2, c2, table[j].a, n);
    	    mod_add (d2, d2, table[j].b, n);
    	}

    } while ( !(mpz_cmp (X1.x, X2.x) == 0 && mpz_cmp (X1.y, X2.y) == 0) );
    
    if ( (mpz_cmp (d1, d2) == 0 ) )
    	printf("failure\n");
    else {
        mod_sub (temp1, c1, c2, n);
        mod_sub (temp2, d2, d1, n);
        mpz_invert (temp3, temp2, n);
        mod_mul (d, temp1, temp3, n);
    }	

	point_clear (&X1);
	point_clear (&X2);
	table_clear (table);
	mpz_clear (c1); mpz_clear (c2); mpz_clear (d1); mpz_clear (d2);
	mpz_clear (temp1); mpz_clear (temp2); mpz_clear (temp3);
} 
