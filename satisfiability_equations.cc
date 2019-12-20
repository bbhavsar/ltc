// https://leetcode.com/problems/satisfiability-of-equality-equations/

#include "common.hh"

unordered_map<char, vector<char> > constructGraph(vector<string>& equations) {
    unordered_map<char, vector<char> > g;
    for (auto eq : equations) {
        if (eq[1] == '=') {
            g[eq[0]].push_back(eq[3]);
            g[eq[3]].push_back(eq[0]);
        }
    }

    return g;
}

unordered_set<char> getUniqueChars(vector<string>& equations) {
    unordered_set<char> uniq_chars;

    for (auto eq :equations) {
        uniq_chars.insert(eq[0]);
        uniq_chars.insert(eq[3]);
    }

    return uniq_chars;
}

void dfs(char u, unordered_map<char, vector<char> >& g,
         int color, unordered_map<char, int>& vertex_colors) {
    vertex_colors[u] = color;
    for (auto v : g[u]) {
        auto it = vertex_colors.find(v);
        if (it == vertex_colors.end()) {
            dfs(v, g, color, vertex_colors);
        }
    }
}

bool equationsPossible(vector<string>& equations) {
    auto g = constructGraph(equations);
    unordered_map<char, int> vertex_colors;
    int color = 1;
    for (auto u : getUniqueChars(equations)) {
        auto it = vertex_colors.find(u);
        if (it == vertex_colors.end()) {
            dfs(u, g, color++, vertex_colors);
        }
    }

    for (auto eq : equations) {
        if (eq[1] == '!') {
            char u = eq[0];
            char v = eq[3];
            if (vertex_colors[u] == vertex_colors[v] || u == v) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<string> equations = { "a==b", "b==c", "a==c"};
    cout << equationsPossible(equations) << endl;
    vector<string> eq2 = { "a==b", "b==c", "a!=c"};
    cout << equationsPossible(eq2) << endl;
    vector<string> eq3 = {"c==c","b==d","x!=z"};
    cout << equationsPossible(eq3) << endl;

    return 0;
}


