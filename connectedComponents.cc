/*
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

*/

#include "common.hh"

void dfs(int u, unordered_map<int, vector<int> >& g, unordered_set<int>& visited) {
    assert(visited.count(u) == 0);
    visited.insert(u);

    for (auto v : g[u]) {
        if (visited.count(v) == 0) {
            dfs(v, g, visited);
        }
    }
}


int countComponents(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, vector<int> > g;
    for (auto p : edges) {
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
    }

    int count = 0;
    unordered_set<int> visited;
    for (int u = 0; u < n; u++) {
        if (visited.count(u) == 0) {
            dfs(u, g, visited);
            count++;
        }
    }

    return count;
}

int main() {
    vector< pair<int, int> > e1 = {{0, 1}, {1, 2}, {3, 4}};
    vector< pair<int, int> > e2 =  {{0, 1}, {1, 2}, {2, 3}, {3, 4}};

    cout << countComponents(5, e1) << endl;
    cout << countComponents(5, e2) << endl;
    return 0;
}

