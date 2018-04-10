#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(const vector<string>& strs) {
    const int size = strs.size();
    if (size == 0) {
        return string();
    }
    string result;
    for (int pos = 0; ; ++pos) {
        if (pos == strs[0].length()) {
            return result;
        }
        char c = strs[0][pos];
        for (int i = 1; i < size; ++i) {
            if (pos == strs[i].length()) {
                return result;
            } else if (c != strs[i][pos]) {
                return result;
            }
        }
        result += c;
    }

    return result;
}

int main() {
    vector<string> strs = { "abcde",
                            "abcfg",
                            "abcdx"
                            };
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}

