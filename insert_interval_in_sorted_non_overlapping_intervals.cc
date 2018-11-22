#include "common.hh"

/*
Insert a New Interval Into a Sorted Array Of Intervals
For Example, Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Also, [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

vector< pair<int, int> > insert_interval(const vector< pair<int, int> >& intervals,
                                         const pair<int, int>& extra_interval) {
    vector< pair<int, int> > result;
    pair<int, int> new_interval = extra_interval;
    for (int i = 0; i < intervals.size(); i++) {
        const pair<int, int> curr = intervals[i];
        if (curr.second < new_interval.first) {
            result.emplace_back(curr);
        } else if (curr.first > new_interval.second) {
            result.emplace_back(new_interval);
            new_interval = curr;
        } else {
            pair<int, int> merged_interval =
                make_pair(min(new_interval.first, curr.first),
                          max(new_interval.second, curr.second));
            new_interval = merged_interval;
        }
    }

    result.emplace_back(new_interval);
    return result;
}


int main() {
    vector< pair<int, int> > intervals = { {1,3}, {6,9} };

    auto result = insert_interval(intervals, make_pair(2,5));
    for (auto p : result) {
        cout << "[" << p.first << ", " << p.second << "] " ;
    }
    cout << endl;

    vector< pair<int, int> > intervals2 = { {1,2},{3,5},{6,7},{8,10},{12,16}  };

    result = insert_interval(intervals2, make_pair(4,9));
    for (auto p : result) {
        cout << "[" << p.first << ", " << p.second << "] " ;
    }
    cout << endl;


    return 0;
}

