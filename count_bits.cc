
#include "common.hh"

int num_set_bits(uint32_t num) {
    int count = 0;
    while (num != 0) {
        // removes the last set bit
        num &= (num - 1);
        count++;
    }

    return count;
}

int main() {

  return 0;
}

