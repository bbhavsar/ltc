#include <iostream>
#include <string>

using namespace std;

string findLongestCommonSubstring(const string& s1, const string& s2) {
    int lcs[s1.length()][s2.length()];
    int max = 0;
    int maxEndIdxS1 = 0;
    for (int i = 0; i < s1.length(); ++i) {
        for (int j = 0; j < s2.length(); ++j) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = 1;
                } else {
                    lcs[i][j] = lcs[i-1][j-1]+ 1;
                }
                if (max < lcs[i][j]) {
                    max = lcs[i][j];
                    maxEndIdxS1 = i;
                }
            } else {
                // Imp: Moment we encounter unequal char drop count
                // to 0 else it becomes longest common subsequence
                // and we can't compare multiple substring matches.
                lcs[i][j] = 0;
            }
        }
    }
    if (max > 0) {
        return s1.substr(maxEndIdxS1 - max + 1, max);
    } else {
        return string();
    }
}

int main() {
    pair<string, string> pairs[] = {
         make_pair("abcdef", "xbcxyz"),
         make_pair("abcdefabcdefg", "xbcdyfabcdzy")
    };
    for (auto& p : pairs) {
        cout << findLongestCommonSubstring(p.first, p.second) << endl;
    }
    return 0;
}

