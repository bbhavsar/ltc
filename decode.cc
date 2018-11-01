#include "common.hh"

// Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
// For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
// You can assume that the messages are decodable. For example, '001' is not allowed.


void decode(const string& str, int pos, vector<string>& result, string running) {
    if (pos >= str.length()) {
        result.push_back(running);
        return;
    }

    char c = str[pos] - '0' - 1 + 'a';
    // cout << "single: " << c << endl;
    decode(str, pos + 1, result, running + c);
    if (pos + 1 < str.length()) {
        int twodigit = (str[pos] - '0') * 10 + str[pos + 1] - '0';
        if (twodigit <= 26) {
            char c = twodigit + 'a' -  1;
            // cout << "2digit: " << c << endl;
            decode(str, pos + 2, result, running + c);
        }
    }
}

vector<string> decode(const string& str) {
    vector<string> result;
    decode(str, 0, result, "");
    return result;
}


int main() {
    string s = "1111";
    vector<string> result = decode(s);
    for (auto s : result) {
        cout << s << endl;
    }

    return 0;
}


