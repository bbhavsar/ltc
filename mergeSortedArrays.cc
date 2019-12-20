// https://leetcode.com/problems/merge-sorted-array/
#include "common.hh"

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ai = m - 1;
        int bi = n - 1;
        int wi = nums1.size() - 1;

        assert(nums1.size() >= m + n);

        for ( ; ai >= 0 && bi >= 0; wi--) {
            assert(wi >= 0);
            if (nums1[ai] > nums2[bi]) {
                nums1[wi] = nums1[ai];
                ai--;
            } else {
                nums1[wi] = nums2[bi];
                bi--;
            }
        }
        if (ai == -1) {
            for (; bi >= 0; bi--, wi--) {
                nums1[wi] = nums2[bi];
            }
        } else if (bi == -1) {
            for (; ai >= 0; ai--, wi--) {
                nums1[wi] = nums1[ai];
            }
        }
        if (wi >= 0) {
            nums1.erase(nums1.begin(), nums1.begin() + wi + 1);
        }
    }

int main() {

    return 0;
}


