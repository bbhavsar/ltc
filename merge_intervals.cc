#include "common.hh"



 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };


vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> result;
    if (intervals.empty()) {
        return result;
    }

    sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
        return lhs.start < rhs.start;
    });

    Interval prev = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        const auto& curr = intervals[i];
        if (prev.end < curr.start) {
            result.emplace_back(prev);
            prev = curr;
        } else {
            prev.end = max(prev.end, curr.end);
        }
    }
    result.emplace_back(prev);

    return result;
}

vector< vector<int> > merge(vector< vector<int> >& intervals) {
    vector< vector<int> > result;
    if (intervals.empty()) {
        return result;
    }

    sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
        return lhs[0] < rhs[0];
    });

    auto prev = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        const auto& curr = intervals[i];
        if (prev[1] < curr[0]) {
            result.emplace_back(prev);
            prev = curr;
        } else {
            prev[1] = max(prev[1], curr[1]);
        }
    }
    result.emplace_back(prev);

    return result;
}

int main() {

    return 0;
}

