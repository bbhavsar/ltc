#include <iostream>
#include <assert.h>

using namespace std;

double computeDecimal(const string&s, int& i) {
    double decimal = 0;
    double divisor = 10.0;
    while (i < s.length()) {
        if (s[i] == 'E' || s[i] == 'e') {
            break;
        }
        assert(s[i] >= '0' && s[i] <= '9');
        int val = s[i] - '0';
        decimal += val / divisor;
        divisor *= 10.0;
        ++i;
    }
    return decimal;
}

double computeExponent(const string& s, int& i) {
    if (i >= s.length()) {
        return 1;
    }
    int sign = 1;
    if (s[i] == '-' ) {
        sign = -1;
        ++i;
    } else if (s[i] == '+') {
        sign = 1;
        ++i;
    }

    int exp = 0;
    while (i < s.length()) {
        assert(s[i] >= '0' && s[i] <= '9');
        int val = s[i] - '0';
        exp *= 10;
        exp += val;
        ++i;
    }

    double expMult = 1.0;
    while (exp > 0) {
        expMult *= 10.0;
        --exp;
    }
    return sign == -1 ? 1.0 / expMult : expMult;
}

double strToDouble(const string& s) {
    // 1234.56E-2
    if (s.length() == 0) {
        return 0;
    }

    // Determine leading sign
    int i = 0;
    int sign = 1;
    if (s[i] == '-' ) {
        sign = -1;
        ++i;
    } else if (s[i] == '+') {
        sign = 1;
        ++i;
    }

    int whole = 0;
    double decimal = 0.0;
    bool dotSeen = false;
    double exponent = 1.0;
    while (i < s.length()) {
        char c = s[i];
        if (c == '.') {
            assert(!dotSeen);
            dotSeen = true;
            decimal = computeDecimal(s, ++i);
        } else if (c == 'E' || c == 'e') {
            exponent = computeExponent(s, ++i);
        } else {
            assert(s[i] >= '0' && s[i] <= '9');
            int val = c - '0';
            whole *= 10;
            whole += val;
            ++i;
        }
    }
    return sign * (whole + decimal) * exponent;
}

int main() {
    string str[] = { "1234",
                     "1234.56",
                     "1.23E+2",
                     "100.23E-2",
                     "12345.4560e+3",
                     "-345.26"};

    for (string& s: str) {
        cout << strToDouble(s) << endl;
    }
}

