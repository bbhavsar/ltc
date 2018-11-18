#include "common.hh"

struct Interval {
    int start, end, weight;
    Interval(int s, int e, int w=1) : start(s), end(e), weight(w) {}
};

int max_weighted_overlapping_intervals(const vector<Interval>& intervals) {
    if (intervals.empty()) {
        return -1;
    }

    vector<Interval> start_times(intervals);
    vector<Interval> end_times(intervals);
    sort(start_times.begin(), start_times.end(),
         [] (const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        });
    sort(end_times.begin(), end_times.end(),
         [] (const Interval& lhs, const Interval& rhs) {
            return lhs.end < rhs.end;
        } );

    int max_load = -1;
    int i = 0;
    int j = 0;
    int curr_load = 0;
    const int size = intervals.size();
    while (i < size && j < size) {
        if (start_times[i].start <= end_times[j].end) {
            curr_load += start_times[i].weight;
            max_load = max(curr_load, max_load);
            i++;
        } else {
            curr_load -= end_times[j].weight;
            j++;
        }
    }
    assert(i == size);
    // load will only decrease as intervals end. So max will still hold.
    assert(j < size);

    return max_load;
}

int main() {
    vector<Interval> intervals = { Interval(0, 4, 10), Interval(3, 5, 20),
                                   Interval(6, 10, 100), Interval(10, 15, 10) };

    vector<Interval> intervals2 = { Interval(30, 75), Interval(0, 50), Interval(60, 150) };

    cout << max_weighted_overlapping_intervals(intervals) << endl;

    cout << max_weighted_overlapping_intervals(intervals2) << endl;

    return 0;
}

