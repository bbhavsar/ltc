
#include "common.hh"

bool isPalindrome(const string& str) {
    for (int l = 0, r = str.size()-1; l < r; l++, r--) {
        if (str[l] != str[r]) {
            return false;
        }
    }

    return true;
}

string buildPalindrome(const string& str) {
    if (isPalindrome(str)) {
        return str;
    }

    string s1 = str.front() + buildPalindrome(str.substr(1)) + str.front();
    string s2 = str.back() + buildPalindrome(str.substr(0, str.size()-1)) + str.back();

    if (s1.length() < s2.length()) {
        return s1;
    } else if (s2.length() < s1.length()) {
        return s2;
    } else {
        return s1 < s2 ? s1 : s2;
    }
}

int main() {

    vector<string> strs = { "abcd", "lssll", "xyx", "abb"};

    for (auto s : strs) {
        cout << s << ":" << buildPalindrome(s) << endl;
    }

    return 0;
}

