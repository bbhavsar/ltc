#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <assert.h>

using namespace std;

void twosum_set(const vector<int>& in, int target, vector< vector<int> >& result) {
    unordered_set<int> s(in.begin(), in.end());
    unordered_set<int> seen;

    for (int elem : in) {
        if (s.count(target - elem) == 1 && seen.count(elem) == 0) {
            result.emplace_back(initializer_list<int>{elem, target - elem});
            seen.insert(target - elem);
        }
    }
}

void twosum_noset(const vector<int>& in, int target, vector< vector<int> >& result) {
    for (int l = 0, r = in.size() - 1; l <=r;) {
        if (in[l] + in[r] == target) {
            result.emplace_back(initializer_list<int>{in[l], in[r]});
            l++, r--;
        } else if (in[l] + in[r] > target) {
            r--;
        } else if (in[l] + in[r] < target) {
            l++;
        }
    }
}

void threesum(vector<int>& in, int target, vector< vector<int> >& result) {
    sort(in.begin(), in.end());
    for (int elem : in) {
        int size_before = result.size();
        twosum_noset(in, target - elem, result);
        int size_after = result.size();
        int num_inserts = size_after - size_before;
        if (num_inserts == 0) {
            continue;
        }
        for (int i = result.size() - num_inserts; i < result.size(); i++) {
            auto& v = result[i];
            v.push_back(elem);
        }
    }
}

void ksum_impl(const vector<int>& in, int target, int k, vector< vector<int> >& result) {
    assert(k >= 2);
    if (k == 2) {
        return twosum_noset(in, target, result);
    }

    for (int elem : in) {
        int size_before = result.size();
        ksum_impl(in, target - elem, k - 1, result);
        int size_after = result.size();
        int num_inserts = size_after - size_before;
        if (num_inserts == 0) {
            continue;
        }
        for (int i = result.size() - num_inserts; i < result.size(); i++) {
            auto& v = result[i];
            v.push_back(elem);
        }
    }
}

void ksum(vector<int>& in, int target, int k, vector< vector<int> >& result) {
    sort(in.begin(), in.end());

    return ksum_impl(in, target, k, result);
}


void print_result(vector< vector<int> >& result) {
    for (auto v : result) {
        for (auto elem : v) {
            cout << elem << ",";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    vector<int> in = {3, 9, 4, 8, 6};
    sort(in.begin(), in.end());

    vector< vector<int> > result;
    twosum_set(in, 12, result);
    print_result(result);

    result.clear();
    twosum_noset(in, 12, result);
    print_result(result);

    result.clear();
    threesum(in, 12, result);
    print_result(result);

    result.clear();
    ksum(in, 23, 4, result);
    print_result(result);

    return 0;
}

