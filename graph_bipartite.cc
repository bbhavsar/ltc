

#include "common.hh"


bool isGraphBipartite(int src_vertex, int num_vertices, vector< vector<int> >& g,
                      vector<int>& colors) {
    colors[src_vertex] = 1;
    queue<int> q;
    q.push(src_vertex);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : g[u]) {
            if (colors[v] == -1) {
                colors[v] = 1-colors[u];
                q.push(v);
            } else if (colors[v] == colors[u]) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    const int num_vertices = graph.size();
    if (num_vertices <= 1) {
        return false;
    }
    vector<int> colors(num_vertices, -1);
    for (int i = 0; i < num_vertices; i++) {
        if (colors[i] == -1) {
            if (!isGraphBipartite(i, graph.size(), graph, colors)) {
                return false;
            }
        }
    }

    return true;
}

int main() {


    return 0;
}

