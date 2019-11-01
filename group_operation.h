#ifndef _GROUP_OPERATION_H_
#define _GROUP_OPERATION_H_

#include "curve.h"

// efetua adição ou duplicação de ponto dependendo dos valores dos pontos 
void point_operation (struct Point *R, const struct Point P, const struct Point Q, const struct Curve c);
// efetua P + Q
void point_addition (struct Point *R, const struct Point P, const struct Point Q, const struct Curve c);
// efetua P + P = 2P
void point_doubling (struct Point *R, const struct Point P, const struct Curve c);

#endif 
