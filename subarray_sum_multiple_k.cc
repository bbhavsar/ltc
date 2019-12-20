// https://leetcode.com/problems/continuous-subarray-sum/discuss/99506/Concise-C%2B%2B-solution-use-set-instead-of-map


#include "common.hh"

bool checkSubarraySum(const vector<int>& nums, int k) {
    const int size = nums.size();
    for (int start = 0; start < size - 1; start++) {
        int sum = nums[start];
        for (int end = start + 1; end < size; end++) {
            sum += nums[end];
            if (sum % k == 0) {
                return true;
            }
        }
    }

    return false;
}

int safeMod(int s, int k) {
    return k != 0 ? s % k : s;
}

bool checkSubarraySum2(const vector<int>& nums, int k) {
    unordered_set<int> sum_mod_seen;
    int sum = nums[0];
    sum_mod_seen.insert(0);
    sum_mod_seen.insert(safeMod(sum, k));
    for (int i = 1; i < nums.size(); i++) {
        sum += nums[i];

        if (sum_mod_seen.count(safeMod(sum, k)) == 1) {
            return true;
        }

        sum_mod_seen.insert(safeMod(sum,k));
    }

    return false;
}

int main() {
    return 0;
}

