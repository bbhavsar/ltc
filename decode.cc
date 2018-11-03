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

int num_calls = 0;
int decode_num(const string& str, int pos) {
    num_calls++;
    if (pos >= str.length()) {
        return 1;
    }

    int num = decode_num(str, pos + 1);
    if (pos + 1 < str.length()) {
        int twodigit = (str[pos] - '0') * 10 + str[pos + 1] - '0';
        if (twodigit <= 26) {
            num += decode_num(str, pos + 2);
        }
    }

    return num;
}

int num_memo_calls = 0;
int decode_memo(const string& str, int pos, vector<int>& cache) {
    num_memo_calls++;

    if (pos >= str.length()) {
        return 1;
    }

    if (cache[pos] != -1) {
        return cache[pos];
    }

    int num = decode_memo(str, pos + 1, cache);
    if (pos + 1 < str.length()) {
        int twodigit = (str[pos] - '0') * 10 + str[pos + 1] - '0';
        if (twodigit <= 26) {
            num += decode_memo(str, pos + 2, cache);
        }
    }

    cache[pos] = num;
    return num;
}

int decode_dp(const string& str) {
    const int length = str.length();
    vector<int> dp(length, 0);

    dp[0] = 1;
    if (length > 1) {
      dp[1] = dp[0];
      int two_digit = (str[0] - '0') * 10 + str[1] - '0';
      if (two_digit <= 26) {
        dp[1] += 1;
      }
    }

    for (int i = 2; i < length; i++) {
        dp[i] = dp[i-1];
        int two_digit = (str[i - 1] - '0') * 10 + str[i] - '0';
        if (two_digit <= 26) {
            dp[i] += dp[i-2];
        }
    }

    return dp[length-1];
}


int main() {
    string s = "2626";
    vector<string> result = decode(s);
    for (auto s : result) {
        cout << s << endl;
    }

    cout << decode_num(s, 0) << endl;
//    cout << num_calls << endl;

    vector<int> cache(s.length(), -1);
    cout << decode_memo(s, 0, cache) << endl;
//    cout << num_memo_calls << endl;

    cout << decode_dp(s) << endl;

    return 0;
}


