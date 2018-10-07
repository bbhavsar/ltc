#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

vector< pair<int, int> > twosum_set(const vector<int>& in, int target) {
    unordered_set<int> s(in.begin(), in.end());
    unordered_set<int> seen;

    vector< pair<int, int> > result;
    for (int elem : in) {
        if (s.count(target - elem) == 1 && seen.count(elem) == 0) {
            result.push_back(make_pair(elem, target - elem));
            seen.insert(target - elem);
        }
    }
    return result;
}

vector< pair<int, int> > twosum_noset(const vector<int>& in, int target) {
    vector< pair<int, int> > result;
    for (int l = 0, r = in.size() - 1; l <=r;) {
        if (in[l] + in[r] == target) {
            result.push_back(make_pair(in[l], in[r]));
            l++, r--;
        } else if (in[l] + in[r] > target) {
            r--;
        } else if (in[l] + in[r] < target) {
            l++;
        }
    }

    return result;
}

vector< vector<int> > threesum(vector<int>& in, int target) {
    sort(in.begin(), in.end());
    vector< vector<int> > result;
    for (int elem : in) {
        vector< pair<int, int> > twosum = twosum_noset(in, target - elem);
        for (const auto& p : twosum) {
            vector<int> v = {p.first, p.second, elem};
            result.push_back(v);
        }
    }

    return result;
}


int main() {
    vector<int> in = {3, 9, 4, 8, 6};

    vector< pair<int, int> > result = twosum_set(in, 12);
    for (auto p : result) {
        cout << p.first << "," << p.second << endl;
    }
    cout << endl;

    result = twosum_noset(in, 12);
    for (auto p : result) {
        cout << p.first << "," << p.second << endl;
    }
    cout << endl;

    vector< vector<int> > r = threesum(in, 12);
    for (auto v : r) {
        for (auto elem : v) {
            cout << elem << ",";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}



