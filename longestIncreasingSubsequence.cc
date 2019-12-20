/*
https://leetcode.com/problems/longest-increasing-subsequence/
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

*/

#include "common.hh"

class Solution {
public:
    int lis_recur(const vector<int>& nums, int idx, int max_val, int max_lis) {
        if (idx >= nums.size()) {
            return max_lis;
        }

        if (nums[idx] < max_val) {
            // can't include
            return lis_recur(nums, idx + 1, max_val, max_lis);
        } else {
            // include or not
            return max(lis_recur(nums, idx + 1, nums[idx], max_lis + 1),
                lis_recur(nums, idx + 1, max_val, max_lis));
        }
    }

    int lengthOfLISRecursive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        return lis_recur(nums, 0, INT_MIN, 0);
    }

    int lengthOfLIS(vector<int>& nums) {
        const int size = nums.size();
        if (size == 0) {
            return 0;
        }
        // dp[i] is length of LIS including element at i
        vector<int> dp(size);
        for (int i = 0; i < size; i++) {
            int max_lis = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    max_lis = max(max_lis, 1 + dp[j]);
                }
            }
            dp[i] = max_lis;
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution s;
    cout << s.lengthOfLISRecursive(nums) << endl;
    cout << s.lengthOfLIS(nums) << endl;

    return 0;
}

