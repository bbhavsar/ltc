#include "common.hh"

/*
https://leetcode.com/problems/employee-free-time/
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all
 employees, also in sorted order.

*/

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

vector<Interval> mergeOverlappingIntervals(const vector<Interval>& intervals) {
    vector<Interval> result;

    Interval prev = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        if (prev.end >= intervals[i].start) {
            prev.end = max(intervals[i].end, prev.end);
        } else {
            result.emplace_back(prev);
            prev = intervals[i];
        }
    }
    result.emplace_back(prev);

    return result;
}

void printIntervals(const vector<Interval>& intervals) {
    for (auto i : intervals) {
        cout << "[" << i.start << "," << i.end << "] ";
    }
    cout << endl;
}

vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
    if (schedule.empty()) {
        vector<Interval>();
    }

    vector<Interval> merged;
    vector<int> idx(schedule.size(), 0);

    do {
        int minIdx;
        int minStart = INT_MAX;
        for (int i = 0; i < schedule.size(); i++) {
            if (idx[i] < schedule[i].size()) {
                if (schedule[i][idx[i]].start < minStart) {
                    minStart = schedule[i][idx[i]].start;
                    minIdx = i;
                }
            }
        }
        if (minStart == INT_MAX) {
            break;
        }
        merged.emplace_back(schedule[minIdx][idx[minIdx]]);
        idx[minIdx]++;
    } while (true);

    vector<Interval> non_overlap = mergeOverlappingIntervals(merged);
    vector<Interval> result;
    for (int i = 1 ; i < non_overlap.size(); i++) {
        if (non_overlap[i-1].end < non_overlap[i].start) {
            result.emplace_back(Interval(non_overlap[i-1].end, non_overlap[i].start));
        }
    }

    return result;
}

int main() {
     vector< vector<Interval> > input =
        {
         { Interval(7,24),Interval(29,33),Interval(45,57),Interval(66,69),Interval(94,99) },
         { Interval(6,24),Interval(43,49),Interval(56,59),Interval(61,75),Interval(80,81) },
         { Interval(5,16),Interval(18,26),Interval(33,36),Interval(39,57),Interval(65,74) },
         { Interval(9,16),Interval(27,35),Interval(40,55),Interval(68,71),Interval(78,81) },
         { Interval(0,25),Interval(29,31),Interval(40,47),Interval(57,87),Interval(91,94) }
        };

    printIntervals(employeeFreeTime(input));
    return 0;
}

