#include "common.hh"

string addBinary(string a, string b) {
    if (a.empty()) {
        return b;
    }
    if (b.empty()) {
        return a;
    }
    int result = 0;
    int prev_carry = 0;

    int ai = a.length()-1;
    int bi = b.length()-1;
    int mult = 1;
    for (; ai >= 0 && bi >= 0; ai--, bi--) {
        int adigit = a[ai]-'0';
        int bdigit = b[bi]-'0';
        int digit = adigit ^ bdigit ^ prev_carry;
        result += digit * mult;
        mult *= 10;
        if ((adigit && bdigit) || (bdigit && prev_carry) || (adigit && prev_carry)) {
            prev_carry = 1;
        } else {
            prev_carry = 0;
        }
    }
    int idx = -1;
    string remainder;
    if (ai == -1) {
        idx = bi;
        remainder = b;
    } else if (bi == -1) {
        idx = ai;
        remainder = a;
    }
    while (idx >= 0) {
        int remain_digit = remainder[idx--] - '0';
        int digit = remain_digit ^ prev_carry;
        result += digit * mult;
        mult *= 10;
        if (remain_digit && prev_carry) {
            prev_carry = 1;
        } else {
            prev_carry = 0;
        }
    }
    if (prev_carry) {
        result += 1 * mult;
    }
    stringstream ss;
    ss << result;
    return ss.str();
}

string addBinary2(const string& a, const string& b) {
    unsigned int carry = 0;
    string sum;
    for (int ai = a.length()-1, bi = b.length()-1; ai >= 0 || bi >= 0 || carry == 1;
         ai--, bi--) {
        carry += ai >= 0 ? a[ai] - '0' : 0;
        carry += bi >= 0 ? b[bi] - '0' : 0;
        sum = (char)((carry & 0x1) + '0') + sum;
        carry >>= 1;
    }
    return sum;
}

int main() {
    cout << addBinary("11", "1") << endl;
    cout << addBinary("1010", "1011") << endl;

    cout << addBinary2("11", "1") << endl;
    cout << addBinary2("1010", "1011") << endl;

    return 0;
}


