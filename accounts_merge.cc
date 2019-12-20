#include "common.hh"
// https://leetcode.com/problems/accounts-merge/

void dfs(unordered_map<string, unordered_set<string> >& conns,
         string u, unordered_set<string>& visited,
         set<string>& component) {
    assert(visited.count(u) == 0);
    visited.insert(u);
    component.insert(u);
    for (auto v : conns[u]) {
        if (visited.count(v) == 0) {
            dfs(conns, v, visited, component);
        }
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    // email to other emails connection
    unordered_map< string, unordered_set<string> > conns;
    // email to name lookup
    unordered_map<string, string> rev_lookup;
    for (auto vec : accounts) {
        string name = vec[0];
        assert(vec.size() >= 2);
        rev_lookup[vec[1]] = name;
        if (vec.size() == 2) {
           conns.insert(make_pair(vec[1], unordered_set<string>()));
        } else {
            for (int j = 1; j < vec.size()-1;j++) {
                string email1 = vec[j];
                string email2 = vec[j+1];
                rev_lookup[email2] = name;
                conns[email1].insert(email2);
                conns[email2].insert(email1);
            }
        }
    }

    vector< vector<string> > result;
    unordered_set<string> visited;
    for (auto p : conns) {
        auto u = p.first;
        if (visited.count(u) == 0) {
            set<string> component;
            dfs(conns, u, visited, component);
            vector<string> component_vec = { rev_lookup[u] };
            component_vec.insert(component_vec.end(), component.begin(), component.end());
            result.push_back(component_vec);
        }
    }

    return result;
}

int main() {

    return 0;
}

