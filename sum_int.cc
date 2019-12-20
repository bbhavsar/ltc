#include "common.hh"

// https://leetcode.com/problems/sum-of-two-integers/

int sum(int a, int b) {

    int sum = a ^ b;
    int carry = (a & b) << 1;
    while (carry) {
        int t1 = sum;
        int t2 = carry;

        sum = t1 ^ t2;
        carry = (t1 & t2) << 1;
    }

    return sum;
}

int main() {
    cout << sum(2, 2) << endl;
    cout << sum(5, 1) << endl;
    cout << sum(-2, 3) << endl;
    cout << sum(-4, 2) << endl;

    return 0;

}

