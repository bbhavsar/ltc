
// https://leetcode.com/problems/longest-repeating-character-replacement/

#include "common.hh"

class FrequencyCount {


};

int maxCharCount(const unordered_map<char, int>& freq_count) {
    int result = 0;
    for (const auto& p : freq_count) {
        result = max(result, p.second);
    }

    return result;
}

int characterReplacement(string s, int k) {
    const int n = s.length();
    int result = 0;
    if (n == 0) {
        return result;
    }

    unordered_map<char, int> freq_count;
    freq_count[s[0]]++;
    for (int i = 0, j = 0; i < n && j < n ;) {
        int maxCount = maxCharCount(freq_count);
        if (j - i + 1 - maxCount > k) {
            freq_count[s[i++]]--;
        } else {
            j++;
            result = max(result, j-i);
            freq_count[s[j]]++;
        }
    }

    return result;
}



int main() {
    vector< pair<string, int> > pairs = { {"ABAB", 2}, {"AABABBA", 1} };

    for (auto p : pairs) {
        cout << characterReplacement(p.first, p.second) << endl;
    }

    return 0;
}


