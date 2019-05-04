
#include "common.hh"

int find_pivot_idx(const vector<int>& nums) {
    if (nums.empty()) {
        return INT_MIN;
    }
    int l = 0;
    int r = nums.size() - 1;
    int m = l + (r-l)/2;
    while (l < m && m < r) {
        if (nums[m] <= nums[r]) {
            r = m;
        } else {
            l = m;
        }
        m = l + (r-l)/2;
    }
    assert(l == m);
    return nums[l] < nums[r] ? l : r;
}

int min_element(const vector<int>& nums) {
    if (nums.empty()) {
        return INT_MIN;
    }
    return nums[find_pivot_idx(nums)];
}

int binary_search(const vector<int>& nums, int l, int r, int target) {
    while (l <= r) {
        int m = (r-l)/2 + l;
        if (target == nums[m]) {
            return m;
        }
        if (target < nums[m]) {
            r = m-1;
        } else {
            l = m +1;
        }
    }

    return -1;

}

int search(const vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }

    int pivot = find_pivot_idx(nums);
    if (pivot == 0) {
        return binary_search(nums, 0, nums.size()-1, target);
    } else if (target >= nums[pivot] && target <= nums[nums.size()-1]) {
        return binary_search(nums, pivot, nums.size()-1, target);
    } else {
        return binary_search(nums, 0, pivot-1, target);
    }
}


int main() {
    vector< vector<int> > arr = {
        { 2, 2, 3, 3, 4, 4 },
        {9, 10, 11, 2, 3, 4, 5}
    };

    for (auto v : arr) {
        cout << find_pivot_idx(v) << endl;
        cout << v[find_pivot_idx(v)] << endl;
    }
    return 0;
}

