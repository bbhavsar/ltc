/*
https://leetcode.com/problems/reverse-bits/submissions/
*/

#include "common.hh"

uint32_t reverse_bits(uint32_t num) {
    uint32_t result = 0;
    assert(sizeof num == 4);
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        uint32_t bit = num & 0x1;
        result |= bit;
        num >>= 1;
    }
    return result;
}

int main() {
    uint32_t arr[] = {0xffffffff, 0x1, 0xa};
    for (auto n : arr) {
        cout << "orig: " << hex << n << " reverse: " << hex << reverse_bits(n) << endl;
    }
    return 0;
}

