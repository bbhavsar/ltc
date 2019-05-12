#include "common.hh"

// Given number of barbers and amount of time each barber takes to cut
// hair for every person. Amount of time each barber takes is fixed and does not vary
// by the person.
// Return wait time for person in position p in the queue and which barber that 
// person in position p will be assigned too.
// Typically num_barbers << p
struct BW {
    int barber_idx;
    int wait_time;
    BW(int idx, int t) : barber_idx(idx), wait_time(t) {}
};

struct Compare {
    bool operator()(const BW& lhs, const BW& rhs) const {
        return lhs.wait_time == rhs.wait_time ?  lhs.barber_idx > rhs.barber_idx :
                                                 lhs.wait_time > rhs.wait_time;
    }
};

// O(p * log(b)) solution where b is number of barbers and p is the position in the queue
BW compute_barber_wait_time(const vector<int>& barbers, int p) {
    const int num_barbers = barbers.size();
    if (num_barbers == 0) {
        BW(-1, INT_MAX);
    }

    priority_queue<BW, vector<BW>, Compare> min_heap;
    int pos = 0;
    while (pos < num_barbers) {
        if (pos == p) {
            return BW(pos, 0);
        }
        min_heap.push(BW(pos, barbers[pos]));
        pos++;
    }

    while (pos < p) {
        BW curr_finished_bw = min_heap.top();
        min_heap.pop();
        min_heap.emplace(curr_finished_bw.barber_idx,
                         curr_finished_bw.wait_time + barbers[curr_finished_bw.barber_idx]);
        pos++;
    }

    return min_heap.top();
}


int main() {
    vector<int> barbers = { 3, 4, 5};

    BW bw = compute_barber_wait_time(barbers, 2);
    cout << "2nd person will wait for " << bw.wait_time << "mins and go to barber " << bw.barber_idx << endl;

    bw = compute_barber_wait_time(barbers, 3);
    cout << "3rd person will wait for " << bw.wait_time << "mins and go to barber " << bw.barber_idx << endl;

    bw = compute_barber_wait_time(barbers, 4);
    cout << "4th person will wait for " << bw.wait_time << "mins and go to barber " << bw.barber_idx << endl;

    bw = compute_barber_wait_time(barbers, 6);
    cout << "6th perosn will wait for " << bw.wait_time << "mins and go to barber " << bw.barber_idx << endl;

    bw = compute_barber_wait_time(barbers, 11);
    cout << "11th person will wait for " << bw.wait_time << "mins and go to barber " << bw.barber_idx << endl;

    return 0;
}

