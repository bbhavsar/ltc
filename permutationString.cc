#include "common.hh"

void permutationString(const string& prefix, const string& remain, vector<string>& result) {
    if (remain.empty()) {
        result.emplace_back(prefix);
        return;
    }

    const int remain_size = remain.length();
    for (int i = 0; i < remain_size ; i++) {
        permutationString(prefix + remain[i],
                          remain.substr(0, i) + remain.substr(i+1), result);
    }
}

vector<string> generatePermutations(string s) {
    vector<string> result;

    permutationString("", s, result);

    return result;
}

int main() {
    string str = "xyz";

    for (auto s : generatePermutations(str)) {
        cout << s << endl;
    }
    return 0;
}

