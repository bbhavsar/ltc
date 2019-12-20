#include "common.hh"




vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string> > m;
    for (const auto& s : strs) {
        string k = s;
        sort(k.begin(), k.end());
        m[k].emplace_back(s);
    }

    vector< vector<string> > r;
    for (const auto& p : m) {
        r.emplace_back(p.second);
    }
    return r;
}

int main() {


    return 0;
}


