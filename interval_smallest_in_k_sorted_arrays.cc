
#include "common.hh"

#include <set>

// EPI 15.6

struct ValVecIdx {
    int val, vec_idx, idx;
    ValVecIdx(int v, int v_idx, int i) : val(v), vec_idx(v_idx), idx(i) {}
    bool operator<(const ValVecIdx& that) const {
        return val < that.val;
    }
    bool operator==(const ValVecIdx& that) const {
        return val == that.val;
    }
};

int findClosestElemntsInSortedArrays(vector< vector<int> >& intervals) {
    multiset<ValVecIdx> min_max_set;

    for (int i = 0; i < intervals.size(); i++) {
        assert(!intervals[i].empty());
        min_max_set.emplace(intervals[i][0], i, 0);
    }

    int result = INT_MAX;
    while (true) {
        auto min_itr = min_max_set.begin();
        auto max_itr = min_max_set.rbegin();

        int dist = max_itr->val - min_itr->val;
        result = min(dist, result);
        int next_idx = min_itr->idx + 1;
        if (next_idx == intervals[min_itr->vec_idx].size()) {
            return result;
        }
        min_max_set.emplace(intervals[min_itr->vec_idx][next_idx], min_itr->vec_idx, next_idx);
        min_max_set.erase(min_itr);
    }

    return result;
}


int main() {

    return 0;
}

