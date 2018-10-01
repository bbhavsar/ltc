#include <iostream>
#include <vector>
#include <unordered_set>
#include <assert.h>

using namespace std;

int knapsack_recurse(const vector<int>& w, const vector<int>& v, const int maxW,
                     int pos, int currW, int currVal,  vector<int>& items) {
    if (pos == v.size() || currW >= maxW) {
        return currVal;
    }

    vector<int> v1;
    int valIncluding = -1;
    if (currW + w[pos] <= maxW) {
        // can include
        v1.push_back(pos);
        valIncluding = knapsack_recurse(w, v, maxW, pos + 1, currW + w[pos], currVal + v[pos],
                                        v1);
    }

    vector<int> v2;
    int valExcluding = knapsack_recurse(w, v, maxW, pos + 1, currW, currVal, v2);
    if (valIncluding > valExcluding) {
        items.insert(items.end(), v1.begin(), v1.end());
        return valIncluding;
    } else {
        items.insert(items.end(), v2.begin(), v2.end());
        return valExcluding;
    }
}

int knapsack_repeat_dp(const vector<int>& w, const vector<int>& v, int maxW, vector<int>& items) {
    int dp[maxW + 1];
    dp[0] = 0;
    int keep[maxW + 1];

    for (int i = 1; i <= maxW; i++) {
        dp[i] = dp[i-1];
        for (int j = 0; j < v.size(); j++) {
            if (i - w[j] >= 0) {
                // include elem
                if (v[j] + dp[i - w[j]] > dp[i]) {
                    dp[i] = v[j] + dp[i - w[j]];
                    keep[i] = j;
                }
            }
        }
    }

    int i = maxW;
    while (i > 0) {
        items.push_back(keep[i]);
        i -=  w[keep[i]];
    }
    return dp[maxW];
}

int knapsack_dp(const vector<int>& w, const vector<int>& v, int maxW, vector<int>& items) {
    assert(w.size() == v.size());
    int dp[v.size() + 1][maxW + 1];
    bool keep[v.size() + 1][maxW +1];

    for (int j = 0; j <= maxW; j++) {
        dp[0][j] = 0;
    }

    for (int i = 0; i <= v.size(); i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= v.size(); i++) {
        for (int j = 1; j <= maxW; j++) {
            if (j - w[i - 1] < 0) {
                dp[i][j] = dp[i-1][j];
                keep[i][j] = false;
            } else {
                // include item
                if  (v[i-1] + dp[i-1][j - w[i-1]] > dp[i-1][j]) {
                    dp[i][j] = v[i-1] + dp[i-1][j - w[i-1]];
                    keep[i][j] = true;
                } else {
                    dp[i][j] = dp[i-1][j];
                    keep[i][j] = false;
                }
            }
        }
    }

    int j = maxW;
    for (int i = v.size(); i > 0; i--) {
        if (keep[i][j]) {
            items.push_back(i-1);
            j -= w[i-1];
        }
    }
    return dp[v.size()][maxW];
}



int knapsack(const vector<int>& w, const vector<int>& v, int maxW, vector<int>& items) {
    return knapsack_recurse(w, v, maxW, 0, 0, 0, items);
}


void kp_repeat() {
    vector<int> w = {1, 3, 4, 5};
    vector<int> v = {10, 40, 50, 70};
    vector<int> items;
    int maxVal = knapsack_repeat_dp(w, v, 8, items);
    cout << "MaxVal: " << maxVal << endl;
    for (auto idx : items) {
        cout << idx << " ";
    }
    cout << endl;
}

int main() {
    vector<int> w = {12, 7, 11, 8, 9};
    vector<int> v = {24, 13, 23, 15, 16};
    vector<int> items;
    int maxVal = knapsack_dp(w, v, 26, items);
    cout << "MaxVal: " << maxVal << endl;
    for (auto idx : items) {
        cout << idx << " ";
    }
    cout << endl;
    kp_repeat();

    return 0;
}

