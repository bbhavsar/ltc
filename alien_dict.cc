/*
https://leetcode.com/problems/alien-dictionary/

There is a new alien language which uses the latin alphabet.
However, the order among letters are unknown to you.
You receive a list of non-empty words from the dictionary, where words
are sorted lexicographically by the rules of this new language.
Derive the order of letters in this language.

*/

#include "common.hh"

class Graph {
private:
    int num_vertices;
    unordered_map<int, vector<int> > adj_list;

public:
    Graph(const unordered_set<int>& vertices)  {
        num_vertices = vertices.size();
        for (int v : vertices) {
            adj_list.emplace(make_pair(v, vector<int>()));
        }
    }

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
    }

    bool tp_sort_util(int u, list<int>& result, unordered_set<int>& visited,
                      unordered_set<int>& rec_stack) {
        visited.emplace(u);
        rec_stack.emplace(u);
        for (auto v : adj_list[u]) {
            if (rec_stack.count(v) != 0) {
                // cycle detected
                return true;
            }
            if (visited.count(v) == 0) {
                bool cycle = tp_sort_util(v, result, visited, rec_stack);
                if (cycle) {
                    // cycle
                    return true;
                }
            }
        }

        rec_stack.erase(u);
        result.push_front(u);
        return false;
    }

    bool topo_sort(list<int>& result) {
        unordered_set<int> visited;
        unordered_set<int> rec_stack;
        for (auto p : adj_list) {
            int u = p.first;
            if (visited.count(u) == 0)  {
                bool cycle = tp_sort_util(u, result, visited, rec_stack);
                if (cycle) {
                    return true;
                }
            }
        }
        return false;
    }
};

string alienOrder(vector<string>& words) {
    if (words.empty()) {
        return string();
    }
    unordered_set<int> uniq_chars;
    for (auto w : words) {
        for (auto c : w) {
            uniq_chars.emplace(c);
        }
    }

    Graph g(uniq_chars);
    for (int i = 0; i < words.size() - 1; i++) {
        for (int pos1 = 0, pos2 = 0; pos1 < words[i].length() && pos2 < words[i+1].length();
              pos1++, pos2++) {
            if (words[i][pos1] != words[i+1][pos2]) {
                g.add_edge(words[i][pos1], words[i+1][pos2]);
                break;
            }
        }
    }

    list<int> result_int;
    bool cycle = g.topo_sort(result_int);
    if (cycle) {
        return string();
    }
    stringstream result;
    for (auto i : result_int) {
        result << char(i);
    }
    return result.str();
}


int main() {
    vector< vector<string>>  input = { {
        "wrt",
        "wrf",
        "er",
        "ett",
        "rftt"},
        {   "x", "y", "x"},
        { "aabb", "aabbcc"}
    };

    for (auto i : input) {
        cout << alienOrder(i) << endl;
    }
    return 0;
}

