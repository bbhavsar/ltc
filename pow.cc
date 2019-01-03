#include "common.hh"
/*
https://leetcode.com/problems/powx-n/
*/

double powRecur(double x, int n) {
    if (n == 0) return 1.0;
    if (n == 1) return x;
    if (n == 2) return x * x;
    double half = powRecur(x, n / 2);
    if ((n & 1) == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}

double myPow(double x, int n) {
    if (x == 0) {
        return x;
    }
    if (n == 0) {
        return 1.0;
    }
    bool negative = n < 0;
    if (negative) {
        n = -n;
    }

    double result = powRecur(x, n);
    return negative ? 1.0 / result : result;
}

int main() {

    cout << myPow(2.1, 3) << endl;
    cout << myPow(2.0, -2) << endl;
    cout << myPow(2.0, 11) << endl;
    cout << myPow(1.1, 2047) << endl;

    return 0;
}



