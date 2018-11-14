/*
A builder is looking to build a row of N houses that can be of K different colors.
He has a goal of minimizing cost while ensuring that no two neighboring houses are of
the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build
the nth house with kth color, return the minimum cost which achieves this goal.
*/
#include "common.hh"

int paint_houses_optimal(const vector< vector<int> >& cost) {
    if (cost.empty() || cost[0].size() <= 2) {
        return 0;
    }

    const int N = cost.size();
    const int k = cost[0].size();

    int prev_min_cost = 0;
    int prev_min_idx = -1;
    int prev_second_min_cost = 0;
    for (int i = 1; i <= N; i++) {
        int next_min_cost = INT_MAX;
        int next_min_idx = -1;
        int next_second_min_cost = INT_MAX;
        for (int j = 0; j < k; j++) {
            int house_paint_cost_cumulative = cost[i-1][j];
            if (j != prev_min_idx) {
                house_paint_cost_cumulative += prev_min_cost;
            } else {
                house_paint_cost_cumulative += prev_second_min_cost;
            }

            if (next_min_cost > house_paint_cost_cumulative) {
                next_second_min_cost = next_min_cost;
                next_min_cost = house_paint_cost_cumulative;
                next_min_idx = j;
            } else if (next_second_min_cost > house_paint_cost_cumulative) {
                next_second_min_cost = house_paint_cost_cumulative;
            }
        }

        prev_min_cost = next_min_cost;
        prev_min_idx = next_min_idx;
        prev_second_min_cost = next_second_min_cost;
    }

    return prev_min_cost;
}

int paint_houses(const vector< vector<int> >& cost, vector<int>& house_color) {
    if (cost.empty() || cost[0].size() <= 2) {
        return 0;
    }

    const int N = cost.size();
    const int k = cost[0].size();
    vector< vector <int> > dp(N + 1, vector<int>(k, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < k; j++) {
            int min_val = INT_MAX;
            for (int idx = 0; idx < k; idx++) {
                if (idx != j) {
                    min_val = min(min_val, dp[i-1][idx]);
                }
            }
            dp[i][j] = min_val + cost[i-1][j];
        }
    }

    int min_val = INT_MAX;
    int min_idx = -1;
    for (int j = 0; j < k; j++) {
        if (dp[N][j] < min_val) {
            min_val = dp[N][j];
            min_idx = j;
        }
    }
    assert(min_idx != -1);
    house_color.resize(N);
    house_color[N-1] = min_idx;
    for (int i = N-2; i >= 0; i--) {
        int min_idx = -1;
        int min_val = INT_MAX;
        for (int j = 0; j < k; j++) {
            if (j != house_color[i+1]) {
                if (dp[i][j] < min_val) {
                    min_idx = j;
                    min_val = dp[i][j];
                }
            }
        }
        house_color[i] = min_idx;
    }

    return min_val;
}


int main() {


    return 0;
}


