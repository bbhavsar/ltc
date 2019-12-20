#include "common.hh"


int leastInterval(const string& tasks, int n) {
    unordered_map<char, int> char_count;
    for (char c : tasks) {
        char_count[c]++;
    }
    priority_queue<int> pq;
    for (auto p : char_count) {
        pq.push(p.second);
    }
    int time = 0;
    while (!pq.empty()) {
        vector<int> to_add_counts;
        for (int i = 0; i <= n; i++) {
            if (!pq.empty()) {
                int top = pq.top();
                pq.pop();
                if (top > 1) {
                    to_add_counts.push_back(top-1);
                }
            }
            time++;
            if (pq.empty() && to_add_counts.empty()) {
                return time;
            }
        }
        for (int count : to_add_counts) {
            pq.push(count);
        }
    }

    return time;
}

int main() {


    return 0;
}

