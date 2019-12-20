#include "common.hh"

bool verifyAlienDict(const vector<string>& words,
                     const string& order) {
    unordered_map<char, int> order_map;
    for(int i = 0; i < order.length(); i++) {
        order_map[order[i]] = i;
    }

    for (int i = 0; i < words.size() - 1; i++) {
        int j;
        for (j = 0; j < words[i].length() && j < words[i+1].length(); j++) {
            if (words[i][j] != words[i+1][j]) {
                if (order_map[words[i][j]] > order_map[words[i+1][j]]) {
                    return false;
                } else {
                    break;
                }
            }
        }
        if (j == words[i+1].length() && j != words[i].length()) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<string> words = {"word","world","row"};
    string order = "worldabcefghijkmnpqstuvxyz";

    cout << verifyAlienDict(words, order) << endl;

    vector<string> words1 = {"hello","leetcode"};
    string order1 = "hlabcdefgijkmnopqrstuvwxyz";

    cout << verifyAlienDict(words1, order1) << endl;

    return 0;
}

