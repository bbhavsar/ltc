/*
This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains
at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters
is "bcb".
*/

#include "common.hh"

int get_char_counts(const unordered_map<char, int>& m) {
    int result = 0;
    for (auto p : m) {
        result += p.second;
    }
    return result;
}

string longest_distinct_substring(const string& s, const int k) {
    int max_len = 0;
    string max_path;

    const int len = s.length();
    for (int i = 0; i < len; i++) {
        unordered_map<char, int> char_count;
        for (int j = i; j < len; j++) {
            auto it = char_count.find(s[j]);
            if (it != char_count.end()) {
                it->second++;
            } else if (char_count.size() == k) {
                break;
            } else {
                char_count[s[j]] = 1;
            }
            int total_char_count = get_char_counts(char_count);
            if (total_char_count > max_len) {
                max_len = total_char_count;
                max_path = s.substr(i, j - i + 1);
            }
        }
    }

    return max_path;
}

string longest_distinct_substring_perf(const string& s, const int k) {
    int max_len = 0;
    string max_path;

    unordered_map<char, int> char_counts;
    const int len = s.length();
    for (int i = 0, j = i; j < len; j++) {
        auto it = char_counts.find(s[j]);
        if (it != char_counts.end()) {
            it->second++;
        } else if (char_counts.size() < k) {
            char_counts[s[j]] = 1;
        } else {
            assert(char_counts.size() == k);

            while (char_counts.size() == k) {
                char_counts[s[i]]--;
                if (char_counts[s[i]] == 0) {
                    char_counts.erase(s[i]);
                }
                i++;
            }

            char_counts[s[j]] = 1;
            assert(char_counts.size() == k);
        }

        int total_char_count = get_char_counts(char_counts);
        if (total_char_count > max_len) {
            max_len = total_char_count;
            max_path = s.substr(i, j - i + 1);
        }
    }

    return max_path;
}


int main() {
    vector<string> strs = {"abcba", "aaabcccdddd"};

    for (auto s: strs) {
        cout << longest_distinct_substring(s, 2) << endl;
        cout << longest_distinct_substring_perf(s, 2) << endl;
    }

    return 0;
}

