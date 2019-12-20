/**
https://leetcode.com/problems/house-robber/
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping you from
robbing each of them is that adjacent houses have security system connected and it
will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/


#include "common.hh"

class Solution {
public:
    int rob(const vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            return 0;
        }
        int select = rob(nums, idx + 2) + nums[idx];
        int not_select = rob(nums, idx + 1);
        return max(select, not_select);

    }
    int rob(vector<int>& nums) {
        return rob(nums, 0);
    }
    int rob_dp(vector<int>& nums) {
        const int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }
        if (size == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[size - 1];
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,7,9,3,1};
    cout << s.rob(nums) << endl;
    cout << s.rob_dp(nums) << endl;

    return 0;
}


