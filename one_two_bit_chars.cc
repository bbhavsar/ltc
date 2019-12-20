#include "common.hh"



bool isOneBitCharacter(vector<int>& bits) {
    int i = 0;
    int num_bits = bits.size();
    while (i <  num_bits - 1) {
        if (bits[i] == 1) {
            i += 2;
        } else {
            i++;
        }
    }
    return i == num_bits - 1;
}

int main() {

    return 0;
}

