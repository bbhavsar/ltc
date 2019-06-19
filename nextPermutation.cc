// https://leetcode.com/problems/next-permutation/

#include "common.hh"

void nextPermutation(vector<int>& nums) {
    int stopIdx = nums.size()-2;;
    for (; stopIdx >= 0; stopIdx--) {
            if (nums[stopIdx] < nums[stopIdx+1]) {
                break;
            }
    }

    if (stopIdx == -1) {
        return reverse(nums.begin(), nums.end());
    }

    int swapIdx = stopIdx + 1;
    for (; swapIdx < nums.size(); swapIdx++) {
        if (nums[swapIdx] <= nums[stopIdx]) {
            break;
        }
    }
    swap(nums[stopIdx], nums[swapIdx-1]);

    reverse(nums.begin() + stopIdx + 1, nums.end());
}

int main() {
    vector< vector<int> > nums = { {3, 6, 4, 2}, {1, 3, 5, 4, 2}};
    for (auto vec : nums) {
        nextPermutation(vec);
        for (auto elem : vec) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}

