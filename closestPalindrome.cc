#include "common.hh"

/*
https://leetcode.com/problems/find-the-closest-palindrome/

XXX: INCORRECT SOLUTION below

*/

bool isPalindrome(const string& str, int i, int j) {
    for (; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

string nearestPalindromic(string n) {
    int len = n.length();

    string result = n;
    for (int i = 0, j = len-1; i < j; i++, j--) {
        if (isPalindrome(result, i, j)) {
            return result;
        }
        result[j] = n[i];
    }

    return result;
}


int main() {
    vector<string> str = {"1234", "1000"};

    for (auto s : str) {
        cout << nearestPalindromic(s) << endl;
    }

    return 0;
}

