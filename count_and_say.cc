// https://leetcode.com/problems/count-and-say/

#include "common.hh"


string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }

    const string s = countAndSay(n-1);
    int i = 0;
    stringstream ss;
    const int len = s.length();
    while (i < len) {
        char c = s[i++];
        int count = 1;
        while (i < len && c == s[i]) {
            i++;
            count++;
        }
        ss << count << c;
    }

    return ss.str();
}

int main() {
    cout << countAndSay(3) << endl;
    cout << countAndSay(4) << endl;
    cout << countAndSay(5) << endl;

    return 0;
}

