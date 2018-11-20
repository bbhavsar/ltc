#include "common.hh"

/*
 * Run-length encoding is a fast and simple method of encoding strings.
 * The basic idea is to represent repeated successive characters as a
 * single count and character. For example, the string "AAAABBBCCDAA"
 * would be encoded as "4A3B2C1D2A".
 *
 * Implement run-length encoding and decoding. You can assume the string
 * to be encoded have no digits and consists solely of alphabetic characters.
 * You can assume the string to be decoded is valid.
 */

string encode(const string& s) {
    if (s.empty()) {
        return s;
    }

    char prev_char = s[0];
    int char_count = 1;
    const int len = s.length();
    stringstream result;
    for (int i = 1; i < len; i++) {
        if (s[i] == prev_char) {
            char_count++;
        } else {
            result << char_count << prev_char;
            prev_char = s[i];
            char_count = 1;
        }
    }
    result << char_count << prev_char;

    return result.str();
}

string decode(const string& s) {
    if (s.empty()) {
        return s;
    }

    stringstream result;
    const int len = s.length();
    assert((len % 2) == 0);
    for (int i = 0; i < len; i += 2) {
        short count = s[i] - '0';
        assert(count >= 0 && count <= 9);
        const char c = s[i+1];
        while (count > 0) {
            result << c;
            count--;
        }
    }

    return result.str();
}

int main() {
    vector<string> strs = { "aabbccddddzza", "jsddkkmmMMooss"};

    for (auto s : strs) {
        cout << decode(encode(s)) << endl;
    }
    return 0;
}


