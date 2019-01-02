/*
 * https://leetcode.com/problems/coin-change/
 *
 */

#include "common.hh"


int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);

    dp[0] = 0;
    const int coins_size = coins.size();
    for (int a = 0; a <= amount; a++) {
        for (int i = 0; i < coins_size; i++) {
            if (a - coins[i] >= 0) {
                if (dp[a-coins[i]] != INT_MAX) {
                    dp[a] = min(dp[a-coins[i]] + 1, dp[a]);
                }
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 18) << endl;

    return 0;
}

