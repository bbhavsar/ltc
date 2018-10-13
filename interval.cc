#include "common.hh"

vector<int> min_intervals(vector< pair<int, int> >& intervals) {
    vector<int> result;
    if (intervals.empty()) {
        return result;
    }

    sort(intervals.begin(), intervals.end(),
        [ ] (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second < rhs.second;
        }
    );

    int prev = intervals[0].second;
    result.push_back(prev);
    for (auto ii = intervals.begin() + 1; ii != intervals.end(); ++ii) {
        if (prev < ii->first) {
            prev = ii->second;
            result.push_back(prev);
        }
    }

    return result;
}

int main() {
    vector< pair<int, int> > intervals = {
        {1, 2}, {2, 3}, {3,4}, {2,3}, {3,4}, {4,5}
    };

    auto result = min_intervals(intervals);
    for (auto elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}


