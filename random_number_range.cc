/*
    Generate random numbers
*/

#include "common.hh"

#include <stdlib.h>     /* srand, rand */
#include <time.h>

double get_random_0_1() {
    return (double) rand() / RAND_MAX;
}

int get_random_range(int low, int high) {

    return low + (rand() % (high - low + 1));
}

// https://stackoverflow.com/a/10984975
int get_random_range_mod(int low, int high) {
    int n = high - low + 1;

    int non_uniform_range = RAND_MAX - (RAND_MAX % n);
    int random;
    do {
        random = rand();
    } while (random >= non_uniform_range);

    random %= n;
    return low + random;
}

int main() {
    srand(time(NULL));

    return 0;;
}


