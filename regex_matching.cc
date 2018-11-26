#include "common.hh"

/*
Given an input string (s) and a pattern (p), implement regular expression matching
 with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

*/

bool regex_match_recur(const string& s, int si, const string& p, int pj) {
    if (pj == p.length()) {
        return si == s.length();
    }

    bool followed_by_star = pj < p.length() - 1 ? p[pj+1] == '*' : false;
    if (followed_by_star) {
        // * matches 0 preceding char in the text

        if (regex_match_recur(s, si, p, pj + 2)) {
            return true;
        }

        // * matches 1 or more preceding chars in the text
        while (si < s.length() && (s[si] == p[pj] || p[pj] == '.')) {
            if (regex_match_recur(s, si + 1, p, pj + 2)) {
                return true;
            }
            si++;
        }
        return false;
    } else if (si < s.length() && (s[si] == p[pj] || p[pj] == '.')) {
        return regex_match_recur(s, si + 1, p, pj + 1);
    } else {
        return false;
    }
}


bool regex_match_r(string s, string p) {
    return regex_match_recur(s, 0, p, 0);
}

bool regex_match_dp(string s, string p) {

    /*
        when s[i] == p[j] or p[j] == '.':
            dp[i][j] = dp[i-1][j-1]

        when p[j] == '*':
            // * matches 0 chars in text
            dp[i][j] = dp[i][j-2]
            OR
            // * matches 1 or more preceding chars in text
            if s[i] == p[j-1] or p[j-1] == '.'
                dp[i][j] = dp[i-1][j]
            else
                false
        else false
    */

    const int rows = s.length() + 1;
    const int cols = p.length() + 1;
    vector< vector<bool> > dp(rows, vector<bool>(cols, false));
    dp[0][0] = true;
    assert(p[0] != '*');
    for (int col = 1; col < cols; col++) {
        if (p[col-1] == '*') {
            dp[0][col] = dp[0][col-2];
        } else {
            dp[0][col] = false;
        }
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
           if (p[j-1] == s[i-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2];
                if (s[i-1] == p[j-2] || p[j-2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[rows-1][cols-1];
}



int main() {
    string p  = "a*bc";
    vector<string> strs = {"bc", "abc", "aabbc", "aaaabc"};

    for (auto s : strs) {
        cout << s << ": " << regex_match_r(s, p) << endl;
    }
    cout << endl;
    for (auto s : strs) {
        cout << s << ": " << regex_match_dp(s, p) << endl;
    }
    return 0;
}

