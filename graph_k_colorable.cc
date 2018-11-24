#include "common.hh"


class Graph {
private:
    int num_vertices;
    vector< vector<int> > mat;

    bool is_graph_valid(int v, const vector<int>& colors_assigned, int to_color) {
        for (int i = 0; i < num_vertices; i++) {
            if (mat[v][i] == 1 && colors_assigned[i] == to_color) {
                return false;
            }
        }
        return true;
    }

    bool is_graph_k_colorable_util(int v, vector<int>& colors_assigned, const int k) {
        if (v == num_vertices) {
            return true;
        }

        for (int color = 0; color < k; color++) {
            if (is_graph_valid(v, colors_assigned, color)) {
                colors_assigned[v] = color;
                if (is_graph_k_colorable_util(v+1, colors_assigned, k)) {
                    return true;
                }
                colors_assigned[v] = -1;
            }
        }
        return false;
    }

public:
    Graph(const int N) : num_vertices(N), mat(N, vector<int>(N, 0)) {}

    void add_edge(int u, int v) {
        assert(u < num_vertices && v < num_vertices);
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    bool is_graph_k_colorable(int k, vector<int>& colors) {
        colors.clear(); colors.resize(num_vertices);
        fill(colors.begin(), colors.end(), -1);
        return is_graph_k_colorable_util(0, colors, k);
    }
};

int main() {
    Graph g(6);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(2, 3);
    g.add_edge(4, 5);

    vector<int> colors;
    cout << g.is_graph_k_colorable(2, colors) << endl;
    for (int i = 0; i < colors.size(); i++) {
        cout << "Vertex: " << i << " color: " << colors[i] << endl;
    }
    return 0;
}

