/*
This problem was asked by Google.

You are given an array of nonnegative integers.
Let's say you start at the beginning of the array and are trying to advance to the end.
You can advance at most, the number of steps that you're currently on. Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.
*/
#include "common.hh"

bool end_reachable_recur(const vector<int>& nums, int idx) {
    if (idx == nums.size() - 1) {
        return true;
    }

    int steps = nums[idx];
    while (steps > 0) {
        if (end_reachable_recur(nums, idx + steps)) {
            return true;
        }
        steps--;
    }

    return false;
}

bool end_reachable(const vector<int>& nums) {
    if (nums.empty()) {
        return true;
    }
    return end_reachable_recur(nums, 0);
}

bool end_reachable_dp(const vector<int>& nums) {
    if (nums.empty()) {
        return true;
    }
    vector<bool> dp(nums.size(), false);
    dp[0] = true;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (dp[i]) {
            int steps = nums[i];
            while (steps > 0) {
                int fwd_idx = i + steps;
                if (fwd_idx < nums.size()) {
                    dp[fwd_idx] = true;
                    if (fwd_idx == nums.size() - 1) {
                        return true;
                    }
                }
                steps--;
            }
        }
    }

    return false;
}


int main() {
    vector< vector<int> > arr = {
        {1, 3, 1, 2, 0, 1},
        {1, 2, 1, 0, 0},
    };

    for (auto v : arr) {
        cout << end_reachable(v) << endl;
        cout << end_reachable_dp(v) << endl;
    }

    return 0;
}


