#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(const string& s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        int result = 0;
        bool oddDropped = false;
        for (auto& p : charCount) {
            int count = p.second;
            if ((count & 0x1) == 0) {
                result += count;
            } else {
                result += (count - 1);
                oddDropped = true;
            }
        }
        return oddDropped ? result + 1 : result;
    }
};

int main() {
    string strs[] = { "abccccdd",
                   "aabbccde"};
    Solution sol;
    for (auto& s : strs) {
        cout << s << ":" << sol.longestPalindrome(s) << endl;
    }
    return 0;
}
