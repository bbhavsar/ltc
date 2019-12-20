#include "common.hh"

void recurse(const vector<int>& nums, int idx, int remain,
             vector<int>& curr,
             vector< vector<int> >& result) {
    if (remain < 0) {
        return;
    }
    if (remain == 0) {
        result.emplace_back(curr);
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        curr.push_back(nums[i]);
        recurse(nums, i, remain - nums[i], curr, result);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> curr;
    vector< vector<int> > result;

    recurse(candidates, 0, target, curr, result);
    return result;
}

int main() {
    vector<int> vec = { 2, 3, 5};

    for (auto v : combinationSum(vec, 8)) {
        for (auto elem : v) {
            cout << elem << ",";
        }
        cout << endl;
    }

    return 0;
}

