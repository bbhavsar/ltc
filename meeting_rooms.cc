#include "common.hh"

int meeting_rooms(vector< vector<int> >& intervals) {
    vector<int> start_points(intervals.size(), 0);
    transform(intervals.begin(), intervals.end(), start_points.begin(),
        [] (const vector<int>& a) { return a[0]; });
    sort(start_points.begin(), start_points.end(),
        [](const int& lhs, const int& rhs) {
            return lhs < rhs;
        });

    vector<int> end_points(intervals.size(), 0);
    transform(intervals.begin(), intervals.end(), end_points.begin(),
        [] (const vector<int>& a) { return a[1]; });
    sort(end_points.begin(), end_points.end(),
        [](const int & lhs, const int& rhs) {
            return lhs < rhs;
        });

    int max_rooms = 0;
    int sidx = 0;
    int eidx = 0;
    int curr_overlap = 0;
    while (sidx < start_points.size()) {
        if (start_points[sidx] < end_points[eidx]) {
            curr_overlap++;
            max_rooms = max(max_rooms, curr_overlap);
            sidx++;
        } else {
            curr_overlap--;
            eidx++;
        }
    }

    return max_rooms;
}

int main() {
    vector< vector<int> > intervals = {{0, 30},{5, 10},{15, 20}} ;

    cout << meeting_rooms(intervals) << endl;

    return 0;
}

