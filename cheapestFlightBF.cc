#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        static const int local_max = 100000;
        vector<int> cost(n, local_max);

        cost[src] = 0;
        while (k-- >= 0) {
            vector<int> newCost(cost);
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                newCost[v] = min(newCost[v], cost[u] + price);
            }
            cost = newCost;
        }

        return cost[dst] == local_max ? -1 : cost[dst];
    }
};

int main() {
    vector< vector < int > > flights =  {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    Solution s;
    cout << s.findCheapestPrice(4, flights, 0, 3, 1) << endl;

    return 0;
}


