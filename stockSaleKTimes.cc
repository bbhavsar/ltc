#include "common.hh"

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

int maxProfit(int k, vector<int>& prices) {
    priority_queue<int, vector<int>, greater<int> > min_heap;
    assert(k > 0);
    int i = 0;
    const int size = prices.size();
    while (i < size-1) {
        // find valley
        while (i < size - 1 && prices[i] >= prices[i+1]) {
            i++;
        }
        int valley = i;
        // find peak
        while (i < size - 1 && prices[i] <= prices[i+1]) {
            i++;
        }
        int peak = i;
        int profit = prices[peak]-prices[valley];
        if (min_heap.size() < k || profit > min_heap.top()) {
            if (min_heap.size() >= k) {
                min_heap.pop();
            }
            min_heap.push(profit);
        }
    }

    assert(min_heap.size() <= k);
    int max_total_profit = 0;
    while (!min_heap.empty()) {
        max_total_profit += min_heap.top();
        min_heap.pop();
    }
    return max_total_profit;
}

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    cout << maxProfit(2, prices) << endl;

    return 0;
}



