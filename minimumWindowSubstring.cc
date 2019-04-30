#include "common.hh"


// https://leetcode.com/problems/minimum-window-substring/

bool windowContainsTarget(const unordered_map<char, int>& window, const unordered_map<char, int>& target) {
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
    int i = 0;
    while (i < n && target.count(s[i]) == 0) {
        i++;
    }
    int j = i;
    while (i < n) {
        while (i < n && target.count(s[i]) == 0) {
            window[s[i++]]--;
        }
        if (i == n) {
            break;
        }
        j = max(j, i);
        if (j == n) {
            if (windowContainsTarget(window,target)) {
                if (min_len > j - i) {
                    min_len = j - i;
                    result = s.substr(i, min_len);
                }
            }
        }
        while (j < n) {
            window[s[j]]++;
            if (windowContainsTarget(window, target)) {
                if (min_len > j - i + 1) {
                    min_len = j - i + 1;
                    result = s.substr(i, min_len);
                }
                break;
            }
            j++;
        }
        window[s[i++]]--;
    }

    return result;
}

int main() {
    cout <<  minWindow("XADOBECODEBANCBAX", "ABC") << endl;
    cout <<  minWindow("A", "A") << endl;
    cout <<  minWindow("BBA", "AB") << endl;
    cout <<  minWindow("BBAAC", "ABA") << endl;
    return 0;
}



