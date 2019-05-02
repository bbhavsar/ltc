// https://leetcode.com/problems/product-of-array-except-self/

#include "common.hh"

vector<int> productExceptSelf(vector<int>& nums) {
    const int size = nums.size();
    if (size <= 1) {
        return vector<int>();
    }
    vector<int> left(size);
    vector<int> right(size);

    left[0] = nums[0];
    for (int i = 1; i < size; i++) {
        left[i] = nums[i] * left[i-1];
    }

    right[size-1] = nums[size-1];
    for (int i = size-2; i >= 0; i--) {
        right[i] = nums[i] * right[i+1];
    }

    vector<int> result(size);
    result[0] = right[1];
    result[size-1] = left[size-2];
    for (int i = 1; i <= size-2 ; i++) {
        result[i] = left[i-1] * right[i+1];
    }

    return result;
}



int main() {

    return 0;
}


