/*
https://leetcode.com/problems/coin-change/

*/

#include "common.hh"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        int min_num = INT_MAX;
        for (auto c : coins) {
            if (amount - c >= 0) {
                int num = coinChange(coins, amount - c);
                if (num != INT_MAX) {
                    num += 1;
                }
                min_num = min(min_num, num);
            }
        }
        return min_num;
    }
};

int main() {
    return 0;
}

