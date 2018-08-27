#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits.h>

using namespace std;

class PQComparator {
    const vector<int>& dist;
public:
    PQComparator(const vector<int>& d) : dist(d) {
    }

    bool operator()(int a, int b) {
        return dist[a] < dist[b];
    }
};

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
        // dist to node i from src
        vector<int> dist;
        // Nodes remaining to be traversed
        priority_queue<int, vector<int>, PQComparator> q ((PQComparator(dist)));

        // stops to node i from src
        vector<int> stops;
        dist.resize(n);
        stops.resize(n);
        auto adj_list = convertToAdjList(flights);
        for (int i = 0 ; i < n; i++) {
            q.push(i);
            stops[i] = 0;
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        stops[src] = -1;
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            auto it = adj_list.find(u);
            if (it == adj_list.end()) {
                continue;
            }
            for (const auto& pair : it->second) {
                int v = pair.first;
                int cost = pair.second;

                if (dist[u] != INT_MAX &&
                    (dist[v] > dist[u] + cost) &&
                    k > stops[u]) {
                    dist[v] = dist[u] + cost;
                    stops[v] = stops[u] + 1;
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    vector< vector < int > > flights = { {0,1,100} ,{ 1,2,100}, {0,2,500}};
    Solution s;
    cout << s.findCheapestPrice(3, flights, 0, 2, 1) << endl;

    return 0;
}


