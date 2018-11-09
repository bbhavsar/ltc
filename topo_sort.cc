#include "common.hh"

struct Edge {
    int src, dst, weight;
    Edge(int u, int v, int w=1) : src(u), dst(v), weight(w) {}
};

class WeightedGraph {
private:
    unordered_set<int> vertices;
    map<int, vector<Edge> > adj_list;
public:
    void add_edge(int u, int v, int w=1) {
        adj_list[u].emplace_back(u, v, w);
        vertices.insert(u);
        vertices.insert(v);
    }

    void add_vertex(int u) {
        vertices.insert(u);
        adj_list.insert(make_pair(u, vector<Edge>()));
    }

    vector<Edge> get_all_edges() {
        vector<Edge> edges;

        for (const auto& p : adj_list) {
            edges.insert(edges.end(), p.second.begin(), p.second.end());
        }

        return edges;
    }

    void print() {
        cout << "Num vertices: " << vertices.size() << endl;
        for (const auto& p : adj_list) {
            cout << "Edges from " << p.first << ":";
            const auto& edges = p.second;
            for (const auto& e : edges) {
                cout << " dst=" << e.dst << " weight=" << e.weight << ", ";
            }
            cout << endl;
        }
        print_edges();
    }

    void print_edges() {
        cout << "Edges: " << endl;
        for (auto e : get_all_edges()) {
            cout << "src: " << e.src << " dst: " << e.dst << " weight: " << e.weight << endl;
        }
    }

    void dfs_recurse(int u, unordered_set<int>& visited, list<int> *result) {
        for (auto e : adj_list[u]) {
            if (visited.count(e.dst) == 0) {
                dfs_recurse(e.dst, visited, result);
            }
        }

        visited.insert(u);
        result->push_front(u);
    }

    list<int> topo_sort() {
        list<int> result;
        unordered_set<int> visited;
        for (int v : vertices) {
            if (visited.count(v) == 0) {
                dfs_recurse(v, visited, &result);
            }
        }

        return result;
    }
};

int main() {
    WeightedGraph wg;
    wg.add_vertex(1);
    wg.add_vertex(2);
    wg.add_vertex(3);
    wg.add_edge(1, 2, 100);
    wg.add_edge(1, 3, 200);
    wg.add_edge(3, 2, 50);
    wg.add_edge(2, 4, 1000);
    wg.add_edge(3, 4, 60);
    wg.add_edge(5, 4, 50);

    wg.print();

    for (auto v : wg.topo_sort()) {
        cout << v << ", ";
    }
    cout << endl;

    return 0;
}

