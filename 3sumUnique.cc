// https://leetcode.com/problems/3sum/
#include "common.hh"

void twoSum(const vector<int>& nums, int f, int l, vector< vector<int> >& result) {
    int target = -nums[f];

    int r = nums.size() -1 ;
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) {
            result.emplace_back(vector<int>{ nums[f], nums[l], nums[r]});
            l++, r--;
            while (l < r && nums[l] == nums[l-1]) {
                l++;
            }
            while (l < r && nums[r] == nums[r + 1]) {
                r--;
            }
        } else if (sum < target) {
            l++;
        } else {
            r--;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector< vector<int> > result;
    int size = nums.size();
    for (int f = 0; f < size - 2;) {
        cout << f << endl;
        twoSum(nums, f, f + 1, result);
        f++;
        while (f < size - 2 && nums[f] == nums[f-1]) {
            f++;
        }
    }
    return result;
}

int main() {
    vector<int> input = { -1, 0, 1, 2, -1, -4};

    for (auto v : threeSum(input)) {
        for (auto elem : v) {
            cout << elem << ",";
        }
        cout << endl;
    }

    input.clear();

    for (auto v : threeSum(input)) {
        for (auto elem : v) {
            cout << elem << ",";
        }
        cout << endl;
    }

    return 0;
}


