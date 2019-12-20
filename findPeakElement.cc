// https://leetcode.com/problems/find-peak-element/

#include "common.hh"

int findPeakElement(vector<int>& nums) {
    int i = 0;
    for (; i < nums.size()-1; i++) {
        if (nums[i] > nums[i+1]) {
            return i;
        }
    }
    return i;
}


int main() {
    vector< vector<int> > nums = {
        {1, 2, 3, 1},
        {1, 2, 1, 3, 5, 6, 4}
    };

    for (auto v : nums) {
        cout << findPeakElement(v) << endl;
    }


    return 0;
}



