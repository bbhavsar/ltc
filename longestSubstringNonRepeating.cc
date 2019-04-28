#include "common.hh"

// Longest Substring Without Repeating Characters

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <typeinfo>


int lengthOfLongestSubstring(string s) {
    const auto size = s.length();
    unordered_set<char> seen;
    auto result = 0;
    for (auto i = 0, j = 0; i < size && j < size;) {
        if (seen.count(s[j]) != 0) {
            seen.erase(s[i++]);
        } else {
            seen.insert(s[j++]);
            result = max(j-i, result);
        }
    }

    return result;
}


int main() {
    auto strs = {"pwwkew", "abcdcefgh", "aaass"};

    cout << typeid(strs).name() << endl;

    for (auto s : strs) {
        cout << lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}

