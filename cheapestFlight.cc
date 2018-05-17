#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int popMinDistUnvisited(list<int>& q, const vector<int>& dist) {
        int min = INT_MAX, minIdx = -1;

        for (auto u : q) {
            if (dist[u] < min) {
                min = dist[u];
                minIdx = u;
            }
        }
        q.remove(minIdx);
        return minIdx;
    }

    unordered_map< int, vector<pair <int, int> > > convertToAdjList(const vector< vector<int> >& flights) {
        unordered_map <int, vector<pair <int, int> > > result;
        for (const auto& flight : flights) {
            result[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }
        return result;
    }

    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        list<int> q;
        // dist to node i from src
        vector<int> dist(n);
        auto adj_list = convertToAdjList(flights);
        vector<bool> visited(n);
        vector<int> depth(n);
        for (int i = 0 ; i < n; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }
        dist[src] = 0;
        depth[src] = 0;
        visited[src] = true;
        q.push_back(src);
        while (!q.empty()) {
            int u = q.front();
            if (depth[u] > k) {
                break;
            }
            q.pop_front();
            auto it = adj_list.find(u);
            if (it == adj_list.end()) {
                continue;
            }
            for (const auto& pair : it->second) {
                int v = pair.first;
                int cost = pair.second;

                if (dist[v] > (dist[u] + cost)) {
                    dist[v] = dist[u] + cost;
                    depth[v] = depth[u] + 1;
                }
                if (!visited[v]) {
                    visited[v] = true;
                    q.push_back(v);
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    vector< vector < int > > flights =  {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    Solution s;
    cout << s.findCheapestPrice(4, flights, 0, 3, 1) << endl;

    return 0;
}


