#include "common.hh"

vector< pair<int, int> > merge_overlapping_intervals(vector< pair<int, int> >& intervals) {
    vector< pair<int, int> > result;

    if (intervals.empty()) {
        return result;
    }

    sort(intervals.begin(), intervals.end(),
            [] (const pair<int, int>& lhs, const pair<int, int>& rhs) -> bool {
                    return lhs.first < rhs.first;
                }
        );

    pair<int, int> curr = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        pair<int, int> next = intervals[i];
        if (curr.second >= next.first) {
            curr.second = max(next.second, curr.second);
        } else {
            result.emplace_back(curr);
            curr = next;
        }
    }
    result.emplace_back(curr);
    return result;
}

int main() {
    vector < pair <int, int> > intervals = { make_pair(1, 5), make_pair(6, 10),
        make_pair(2, 7), make_pair(-10, -2) , make_pair(-3, 1) };
    auto result = merge_overlapping_intervals(intervals);
    for (auto e : result) {
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}

