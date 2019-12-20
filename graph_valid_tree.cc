// https://leetcode.com/problems/graph-valid-tree/

#include "common.hh"

bool dfs(int u, unordered_map<int, vector<int> >& graph,
         unordered_set<int>& visited, int parent) {

    visited.insert(u);
    for (auto v : graph[u]) {
        if (visited.count(v) == 0) {
            bool cycle = dfs(v, graph, visited, u);
            if (cycle) {
                return true;
            }
        } else if (parent !=  v) {
            return true;
        }
    }

    return false;
}

bool validTree(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int> > graph;

    for (auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    unordered_set<int> visited;
    if (dfs(0, graph, visited, -1)) {
        // if cycle detected not a graph
        return false;
    }

    // if any other vertex/node is not visited then it's not a connected
    // graph and hence not a tree
    for (int i = 1; i < n; i++) {
        if (visited.count(i) == 0) {
            return false;
        }
    }

    return true;
}

int main() {

    return 0;
}

