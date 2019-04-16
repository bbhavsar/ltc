#include "common.hh"

// Dijkstra's algo for shortest path in a graph


struct Edge {
    int u, v;
    int w;
    Edge(int src, int dst, int weight) : u(src), v(dst), w(weight) {}
};

struct Graph {
    int v;
    unordered_map<int, vector<Edge> > adj_list;

    Graph(int n) : v(n) {}

    void add_edge(int u, int v, int w) {
        adj_list[u].emplace_back(u, v, w);
    }
};

class Compare {
private:
    const unordered_map<int, int>& dist;
public:
    Compare(const unordered_map<int, int>& d) :  dist(d) {}

    bool operator()(const int& lhs, const int& rhs) const {
        return dist.at(lhs) > dist.at(rhs);
    }
};

unordered_map<int, int> shortest_path_dijsktra(Graph g, int src) {
    unordered_map<int, int> dist;
    for (int i = 0; i < g.v; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    priority_queue<int, vector<int>, Compare > q((Compare(dist)));

    for (int i = 0; i < g.v; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int u = q.top();
        for (auto e : g.adj_list[u]) {
            int v = e.v;
            if (dist[v] > dist[u] + e.w) {
                dist[v] = dist[u] + e.w;
            }
        }
        // pop will modify the ordering and hence must be done after relaxing
        // the edges/distance above.
        q.pop();
    }

    return dist;
}

int main() {
    Graph g(5);

    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 4);
    g.add_edge(0, 3, 13);
    g.add_edge(1, 3, 3);
    g.add_edge(2, 3, 3);
    g.add_edge(3, 4, 4);

    cout << shortest_path_dijsktra(g, 0)[4] << endl;


    return 0;
}

