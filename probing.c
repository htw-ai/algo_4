#include <stdio.h>
#include <math.h>
#include "probing.h"

int linear_probing(unsigned int j) {
    return j;
}

int quadratic_probing(unsigned int j) {
    return pow(round_div(j, 2), 2) * (-pow(1, j));
}

int round_div(unsigned int dividend, unsigned int divisor) {
    return (dividend + (divisor / 2)) / divisor;
}
