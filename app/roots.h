#ifndef ROOTS_H
#define ROOTS_H

#include <float.h>
#include <stdio.h>

typedef struct res {
   double x1, x2;
   const char* msg;
} res;

/**
 * @brief solve
 * @param a
 * @param b
 * @param c
 * @return r: object containing the result of calculations
 */

res solve(double a, double b, double c);

/**
 * @brief print
 * @param r
 * @return -1: the message was received
 *          0: two roots obtained
 *          1: only one root obtained
 */

double print(res);

#endif // ROOTS_H
