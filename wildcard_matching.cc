#include "common.hh"


/*
https://leetcode.com/problems/wildcard-matching/

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/

void remove_repeated_stars(string& s) {
    if (s.empty()) {
        return;
    }
    int writeIdx = 1;
    for (int readIdx = 1; readIdx < s.length(); readIdx++) {
        if (s[readIdx] != '*' || (s[readIdx] == '*' && s[writeIdx-1] != '*')) {
            s[writeIdx] = s[readIdx];
            writeIdx++;
        }
    }
    s.resize(writeIdx);
}

int num_calls_recurse = 0;
bool wildcard_match_recurse(const string& s, int si, const string& p, int pj) {
    num_calls_recurse++;
    if (pj == p.length()) {
        return si == s.length();
    }

    // Must check * first to allow for * to match 0 chars from text when
    // si is already at end of text.
    if (p[pj] == '*') {
        // * matches 0 chars from text
        if (wildcard_match_recurse(s, si, p, pj + 1)) {
            return true;
        }

        // * matches 1 or more chars from text
        while (si < s.length()) {
            if (wildcard_match_recurse(s, si + 1, p, pj + 1)) {
                return true;
            }
            si++;
        }

        return false;
    } else if (si < s.length() && (s[si] == p[pj] || p[pj] == '?')) {
        return wildcard_match_recurse(s, si + 1, p, pj + 1);
    } else {
        return false;
    }
}

int num_calls_memo = 0;
bool wildcard_match_memo(const string& s, int si, const string& p, int pj,
                         vector< vector<int> >& cache) {
    num_calls_memo++;

    if (cache[si][pj] != -1) {
        return cache[si][pj];
    }

    if (pj == p.length()) {
        bool match = si == s.length();
        cache[si][pj] = match;
        return match;
    }

    // Must check * first to allow for * to match 0 chars from text when
    // si is already at end of text.
    if (p[pj] == '*') {
        // * matches 0 chars from text
        if (wildcard_match_memo(s, si, p, pj + 1, cache)) {
            cache[si][pj] =  true;
            return true;
        }

        // * matches 1 or more chars from text
        while (si < s.length()) {
            if (wildcard_match_memo(s, si + 1, p, pj + 1, cache)) {
                cache[si][pj] = true;
                return true;
            }
            si++;
        }

        cache[si][pj] = false;
        return false;
    } else if (si < s.length() && (s[si] == p[pj] || p[pj] == '?')) {
        bool match  = wildcard_match_memo(s, si + 1, p, pj + 1, cache);
        cache[si][pj] = match;
        return match;
    } else {
        cache[si][pj] = false;
        return false;
    }
}

bool wildcard_match_memo(string& s, string& p) {
    remove_repeated_stars(p);
    vector< vector<int> > cache(s.length() + 1, vector<int>(p.length() + 1, -1));
    return wildcard_match_memo(s, 0, p, 0, cache);
}

bool wildcard_match_dp(string& s , string& p) {
    remove_repeated_stars(p);

    /*
        when s[i] == p[j] or p[j] == '?':
            dp[i][j] = dp[i-1][j-1]

        when p[j] == '*':
            // * matches 0 chars in text
            dp[i][j] = dp[i][j-1]
            OR
            // * matches 1 or more chars in text
            dp[i][j] = dp[i-1][j]
        else false
    */

    const int rows = s.length() + 1;
    const int cols = p.length() + 1;
    vector< vector<bool> > dp(rows, vector<bool>(cols, false));
    dp[0][0] = true;

    for (int j = 1; j < cols; j++) {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        } else {
            dp[0][j] = false;
        }
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[rows-1][cols-1];
}

int main() {
    vector<string> strs = { "adasdxyz", "xysasxyza", "xyz", "xxyz"};

    string p = "*xyz";
    for (auto s : strs) {
        num_calls_recurse = 0;
        cout << s << ": " << wildcard_match_recurse(s, 0, "*xyz", 0) << endl;
        cout << "recursive calls " << num_calls_recurse << endl;
    }

    for (auto s : strs) {
        num_calls_memo = 0;
        cout << s << ": " << wildcard_match_memo(s, p) << endl;
        cout << "memo calls " << num_calls_memo << endl;
    }

    for (auto s : strs) {
        cout << s << ": " << wildcard_match_dp(s, p) << endl;
    }

    string text  = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab";
    string pattern = "***bba**a*bbba**aab**b";

    num_calls_recurse = 0;
    cout << text << ": " << wildcard_match_recurse(text, 0, pattern, 0) << endl;
    cout << "recurse calls: " << num_calls_recurse << endl;

    num_calls_memo = 0;
    cout << text << ": " << wildcard_match_memo(text, pattern) << endl;
    cout << "memo calls: " << num_calls_memo << endl;

    return 0;
}

