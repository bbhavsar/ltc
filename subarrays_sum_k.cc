#include "common.hh"


// https://leetcode.com/problems/subarray-sum-equals-k/

int subarraySum(const vector<int>& nums, int k) {
    if (nums.empty()) {
        return 0;
    }
    vector<int> sum(nums.size() + 1, 0);
    sum[0] = 0;
    for (int i = 1; i <= nums.size(); i++) {
        sum[i] = sum[i-1] + nums[i-1];
    }

    int count = 0;
    for (int start = 0; start < nums.size(); start++) {
        for (int end = start + 1; end <= nums.size(); end++) {
            int subarray_sum = sum[end]-sum[start];
            if (subarray_sum == k) {
                count++;
            }
        }
    }

    return count;
}

int subarraySum2(const vector<int>& nums, int k) {
    if (nums.empty()) {
        return 0;
    }
    int count = 0;
    for (int start = 0; start < nums.size(); start++) {
        int curr_sum = 0;
        for (int end = start; end < nums.size(); end++) {
            curr_sum += nums[end];
            if (curr_sum == k) {
                count++;
            }
        }
    }

    return count;
}

int subarraySum3(const vector<int>& nums, int k) {
    if (nums.empty()) {
        return 0;
    }

    int count = 0;
    unordered_map<int, int> subarray_sum_count;
    subarray_sum_count[0] = 1;
    int sum = 0;
    for (int num : nums) {
        sum += num;
        auto it = subarray_sum_count.find(sum-k);
        if (it != subarray_sum_count.end()) {
            count += it->second;
        }
        subarray_sum_count[sum]++;
    }

    return count;
}

int main() {


    return 0;
}

