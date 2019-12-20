
// https://leetcode.com/problems/longest-consecutive-sequence/

#include "common.hh"

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    const unordered_set<int> num_set(nums.begin(), nums.end());

    int max_len = 0;
    for (auto num : nums) {
        if (num_set.count(num-1) == 0) {
            int curr_len = 1;
            int curr_num = num;
            while (num_set.count(++curr_num) != 0) {
                curr_len++;
            }
            max_len = max(max_len, curr_len);
        }
    }

    return max_len;
}

int main() {
    vector<int> nums = { 100, 200, 4, 5, 1, 3};

    cout << longestConsecutive(nums) << endl;

    return 0;
}



