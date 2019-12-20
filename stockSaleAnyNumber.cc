// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/

#include "common.hh"

int maxProfit(vector<int>& prices) {
    int i = 0;
    int profit = 0;

    const int len = prices.size();
    while (i < len - 1) {
        // find valley
        while (i < len - 1 && prices[i] >= prices[i+1]) {
            i++;
        }
        int valley = i;
        // find peak
        while (i < len - 1 && prices[i] <= prices[i+1]) {
            i++;
        }
        int peak = i;
        profit += prices[peak] - prices[valley];
    }

    return profit;
}

int main() {
    vector<int> prices = {3,2,6,5,0,3};

    cout << maxProfit(prices) << endl;

    return 0;
}


