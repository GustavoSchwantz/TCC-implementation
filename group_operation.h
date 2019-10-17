#ifndef _GROUP_OPERATION_H_
#define _GROUP_OPERATION_H_

#include "curve.h"

// efetua P + Q
void point_addition (struct Point *P, struct Point *Q, struct Point *R, struct Curve *c);
// efetua P + P = 2P
void point_doubling (struct Point *P, struct Point *R, struct Curve *c);

#endif 
