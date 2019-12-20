
#include "common.hh"

int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, vector<int> > freq;

    auto max_freq = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        int elem = nums[i];
        freq[elem].push_back(i);
        max_freq = max(max_freq, (int)freq[elem].size());
    }

    vector<int> max_freq_elems;
    for (auto p : freq) {
        if (max_freq == p.second.size()) {
            max_freq_elems.push_back(p.first);
        }
    }

    auto min_length = INT_MAX;
    for (auto max_elem : max_freq_elems) {
        auto len = freq[max_elem].back() - freq[max_elem].front() + 1;
        min_length = min(min_length, (int)len);
    }

    return min_length;
}

int main() {
    vector<int> nums =  {1, 2, 2, 3, 1};

    cout << findShortestSubArray(nums) << endl;

}

