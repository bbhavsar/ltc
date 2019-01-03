#include "common.hh"

/*
https://leetcode.com/problems/longest-palindromic-substring/

*/


string longestPalindrome(string s) {
    if (s.empty()) {
        return string();
    }

    vector< vector<bool> > dp(s.length(), vector<bool>(s.length(), false));

    // Base case for length of 1 and 2.
    dp[0][0] = true;
    int max_len = 1;
    int max_i = 0;
    for (int i = 1; i < s.length(); i++) {
        dp[i][i] = true;
        if (s[i] == s[i-1]) {
            dp[i-1][i] = true;
            max_i = i-1;
            max_len = 2;
        }
    }

    // Expand from lengths of 3 to n.
    for (int l = 3; l <= s.length(); l++) {
        for (int i = 0; i <= s.length() - l; i++) {
            int j = i+l-1;
            dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
            if (dp[i][j]) {
                max_len = l;
                max_i = i;
            }
        }
    }

    return s.substr(max_i, max_len);
}

int main() {
    vector<string> input = { "xxyyabcdefedcbayx" };

    for (auto s : input) {
        cout << longestPalindrome(s) << endl;
    }

    return 0;
}


