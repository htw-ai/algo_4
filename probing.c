#include <stdio.h>
#include <math.h>
#include "probing.h"

//linear probing
int linear_probing(unsigned int j) {
    return j;
}
//quadric probing
int quadratic_probing(unsigned int j) {
    return pow(round_div(j, 2), 2) * (-pow(1, j));
}

//rounds the result of division operation
int round_div(unsigned int dividend, unsigned int divisor) {
    return (dividend + (divisor / 2)) / divisor;
}
