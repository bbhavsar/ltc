#include "common.hh"

class Graph {
private:
    map<int, vector<int> > adj_list;
    int num_vertices;

public:
    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    void add_vertex(int u) {
        adj_list.insert(make_pair(u, vector<int>()));
        num_vertices++;
    }
    void add_vertices(int u, int v) {
        for (int i = u; i <= v; i++) {
            add_vertex(i);
        }
    }

    map<int, int> color_graph() {
        map<int, int> vertex_color_map;

        for (auto p : adj_list) {
            int v = p.first;
            auto neighbors = p.second;
            vector<bool> colors_taken(num_vertices, false);

            for (auto n : neighbors) {
                auto color_it = vertex_color_map.find(n);
                if (color_it != vertex_color_map.end()) {
                    colors_taken[color_it->second] = true;
                }
            }

            int color;
            for (color = 0; color < colors_taken.size(); color++) {
                if (!colors_taken[color]) {
                    break;
                }
            }
            assert(color < colors_taken.size());
            vertex_color_map[v] = color;
        }
        return vertex_color_map;
    }
};

int main() {
    Graph g;
    g.add_vertices(0, 4);
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(1, 3); 
    g.add_edge(2, 3); 
    g.add_edge(3, 4);

    auto result = g.color_graph();
    for (auto p : result) {
        cout << "Vertex: " << p.first << " color: " << p.second << endl;
    }

    Graph g2;
    g2.add_vertices(0, 4);
    g2.add_edge(0, 1); 
    g2.add_edge(0, 2); 
    g2.add_edge(1, 2); 
    g2.add_edge(1, 4); 
    g2.add_edge(2, 4); 
    g2.add_edge(4, 3);

    result = g2.color_graph();
    for (auto p : result) {
        cout << "Vertex: " << p.first << " color: " << p.second << endl;
    }

    return 0;
}

