#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

vector<int> topKFrequent(const vector<int>& nums,
                         int k) {
    unordered_map<int, int> num_count_map;
    for (int elem : nums) {
        num_count_map[elem] += 1;
    }

    priority_queue<pair<int, int>, vector<pair <int, int> >, Compare> pq;
    for (const pair<int, int>& kv : num_count_map) {
        pq.push(kv);
    }
    vector<int> result;
    result.reserve(k);
    while (!pq.empty() && result.size() < k) {
        const pair<int, int>& ordered_elem = pq.top();
        result.push_back(ordered_elem.first);
        pq.pop();
    }
    return result;
}


int main() {
    vector<int> elems = {1, 1, 1, 2, 3, 3};
    vector<int> out = topKFrequent(elems, 2);
    for (int i : out) {
        cout << i << endl;
    }
    return 0;
}


