/*
https://leetcode.com/problems/word-break/

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false



*/

#include "common.hh"

bool prefix_match(const string& s, const string& w) {
    if (s.length() < w.length()) {
        return false;
    }

    return s.compare(0, w.length(), w) == 0;
}

bool wordBreak(string s, const vector<string>& wordDict) {
    if (s.empty()) {
        return true;
    }

    for (const auto& w : wordDict) {
        if (prefix_match(s, w)) {
            if (wordBreak(s.substr(w.length()), wordDict)) {
                return true;
            }
        }
    }

    return false;
}

bool prefix_match(const string& s, int idx, const string& w) {
    if (s.length() - idx < w.length()) {
        return false;
    }

    return s.compare(idx, w.length(), w) == 0;
}

bool wordBreak(const string& s, int idx, const vector<string>& wordDict, unordered_map<int, bool>& cache) {
    if (idx >= s.length()) {
        return true;
    }

    auto it = cache.find(idx);
    if (it != cache.end()) {
        return it->second;
    }

    for (const auto& w : wordDict) {
        if (prefix_match(s, idx, w)) {
            if (wordBreak(s, idx + w.length(), wordDict, cache)) {
                cache[idx] = true;
                return true;
            }
        }
    }

    cache[idx] = false;
    return false;
}


int main() {
    unordered_map<string, vector<string> > strings = {
        { "leetcode", {"leet", "code"} },
        { "catsandog", {"cats", "dog", "sand", "and", "cat" } },
        {  "applepenapple", {"apple", "pen"} }
    };

    unordered_map<int, bool> cache;
    for (auto p : strings) {
        cache.clear();
        cout << p.first << " " << wordBreak(p.first, p.second) << endl;
        cout << p.first << " " << wordBreak(p.first, 0,  p.second, cache) << endl;
    }
    return 0;
}

