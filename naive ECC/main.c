#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

// define um ponto da curva elíptica 
struct Point { 
    int x, y; 
}; 

// define uma curva elíptica
struct Curve {
	int a, b;
    int p;
};

struct Point * addition (struct Point *P, struct Point *Q, struct Curve *c);

int main (int argc, char const *argv[])
{
	struct Curve curve;
	struct Point P;
	struct Point Q;
    struct Point *R;

    curve.a = 2;
    curve.b = 2;
    curve.p = 17;

    P.x = 3;
    P.y = 6;

    Q.x = 3;
    Q.y = 6;

    R = addition (&P, &Q, &curve);

    printf("x3 value: %d\n", R->x);
    printf("y3 value: %d\n", R->y);

    free (R);

	return 0;
}

struct Point * addition (struct Point *P, struct Point *Q, struct Curve *c)
{
	int x1 = P->x;
	int y1 = P->y;
    int x2 = Q->x;
	int y2 = Q->y;
	int a = c->a;
	int p = c->p;
	int s;

	if (P->x == Q->x && P->y == Q->y) {
		s = mod ( (3*pow(x1, 2) + a) * inverse (p, mod (2*y1, p)), p );
	}
	else {
		s = mod ( (y2 - y1) * inverse (p, mod (x2 - x1, p)), p );
	}

	struct Point *R = (struct Point *) malloc (sizeof(struct Point));

	unsigned int x3 = mod ( pow (s, 2) - x1 - x2, p);  
	(*R).y = mod ( (s*(x1 - x3) - y1), p);	

	(*R).x = x3;

	return R;	
}
