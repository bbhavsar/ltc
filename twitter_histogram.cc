#include "common.hh"

// Twitter histogram question
// 

struct UserCountVal {
  int prev_ts;
  int count;
  UserCountVal() : prev_ts(0), count(0) {}
  UserCountVal(int p, int c) : prev_ts(p), count(c) {}
};

vector<int> createHistogram(const vector< pair<int, int> >& in, int bin_size) {
    int max_count = 0;
    unordered_map<int, UserCountVal> user_count_map;
    
    for (auto entry : in) {
        int user = entry.first;
        int ts = entry.second;
        
        UserCountVal& usv = user_count_map[user];
        if (ts > usv.prev_ts) {
            usv.prev_ts = ts;
            usv.count++;
            max_count = max(usv.count, max_count);
        }
    }
    
    vector<int> slots(max_count / bin_size + 1, 0);
    
    for (auto p : user_count_map) {
        UserCountVal usv = p.second;
        int slot_idx = usv.count / bin_size;
        slots[slot_idx]++;
    }
    
    return slots;
}

int main() {

    return 0;
}

