#include "common.hh"


// https://leetcode.com/problems/minimum-window-substring/

bool windowContainsTarget(const unordered_map<char, int>& window,
    const unordered_map<char, int>& target) {
    for (const auto& p : target) {
        if (window.count(p.first) == 0) {
            return false;
        }
        if (window.at(p.first) < p.second) {
            return false;
        }
    }

    return true;
}


string minWindow(string s, string t) {
    const auto n = s.length();
    if (n == 0 || t.length() == 0) {
        return string();
    }

    unordered_map<char, int> target;
    for (auto c : t) {
        target[c]++;
    }

    string result;
    int min_len = INT_MAX;
    unordered_map<char, int> window;
    for (auto i = 0, j = 0; i < n && j < n;) {
       bool found = false;
       while (j < n) {
            window[s[j++]]++;
            if (windowContainsTarget(window, target)) {
                if (min_len > j - i) {
                    min_len = j - i;
                    result = s.substr(i, min_len);
                }
                found = true;
                break;
            }
        }
        if (!found) {
            break;
        }
        while (i < j - 1) {
            window[s[i++]]--;
            if (windowContainsTarget(window, target)) {
                if (min_len > j - i) {
                    min_len = j - i;
                    result = s.substr(i, min_len);
                }
            } else {
              break;
            }
        }
    }

    return result;
}

int main() {
    cout <<  minWindow("A", "A") << endl;
    cout <<  minWindow("BBA", "AB") << endl;
    cout <<  minWindow("BBAAC", "ABA") << endl;

    cout <<  minWindow("XADOBECODEBANCBAX", "ABC") << endl;
    return 0;
}



