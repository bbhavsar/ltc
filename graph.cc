#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Graph {
private:
    map<int, set<int> > adj_list;
public:
    void addEdge(int u, int v) {
        adj_list[u].insert(v);
    }

    void print() {
        for (const auto& pair : adj_list) {
            cout << "Node: " << pair.first << endl;
            cout << "Connected" << endl;
            for (int node : pair.second) {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    void bfs(int s) {
        queue<int> q;
        set<int> visited;
        q.push(s);
        visited.insert(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << ",";
            if (adj_list.count(u) == 0) {
                continue;
            }
            for (int v : adj_list[u]) {
                if (visited.count(v) == 0) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
    }

    void dfsRecurse(int u, set<int>& visited) {
        cout << u << ",";
        if (adj_list.count(u) == 0) {
            return;
        }
        for (int v : adj_list[u]) {
            if (visited.count(v) == 0) {
                visited.insert(v);
                dfsRecurse(v, visited);
            }
        }
    }

    void dfs(int s) {
        set<int> visited;
        visited.insert(s);
        dfsRecurse(s, visited);
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.bfs(0);
    cout << endl;
    g.dfs(1);
    cout << endl;
    return 0;
}


