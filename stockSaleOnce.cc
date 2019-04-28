#include <iostream>
#include <vector>
#include <limits>

using namespace std;

double buySellOnce(const vector<double>& prices) {
    if (prices.empty()) {
        return -1;
    }
    double min_so_far = prices[0];
    double max_so_far = numeric_limits<double>::min();

    for (int i = 1; i < prices.size(); ++i) {
        const auto& elem = prices[i];
        max_so_far = max(max_so_far, elem - min_so_far);
        min_so_far = min(min_so_far, elem);
    }

    return max_so_far;
}

int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int min_so_far = prices[0];
    int max_so_far = 0;
    for (int i = 1; i < prices.size(); i++) {
        int diff = prices[i] - min_so_far;
        max_so_far = max(diff, max_so_far);
        min_so_far = min(prices[i], min_so_far);
    }

    return max_so_far;
}

int main() {
    vector< vector<double> > prices = {
            { 10.0, 2.0, 3.0, 5.0, 4.0},
            { 10.0, 9.0, 8.0, 7.0}
        };

    for (const auto& v : prices) {
        cout << buySellOnce(v) << endl;
    }
    return 0;
}

