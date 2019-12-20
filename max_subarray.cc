#include "common.hh"

int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int result = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        result = max(result, dp[i]);
    }

    return result;
}

int maxSubArrayOptimal(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int currMax = nums[0];
    int result = currMax;

    for (int i = 1; i < nums.size(); i++) {
        currMax = max(currMax + nums[i], nums[i]);
        result = max(result, currMax);
    }
    return result;
}

int main() {

    return 0;
}

