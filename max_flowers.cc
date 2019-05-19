
#include "common.hh"

// Similar to following question
// https://leetcode.com/problems/can-place-flowers/

int maxFlowersRecur(const vector<int>& fb, int idx, int curr_count) {
    if (idx >= fb.size()) {
        return curr_count;
    }

    if (fb[idx] == 1) {
        return maxFlowersRecur(fb, idx+2, curr_count);
    } else {
        assert(fb[idx] == 0);
        bool flower_next = false;
        if (idx + 1 < fb.size()) {
            flower_next = fb[idx+1] == 1;
        }
        if (flower_next) {
            return maxFlowersRecur(fb, idx+3, curr_count);
        } else {
            return maxFlowersRecur(fb, idx+2, curr_count + 1);
        }
    }
}

int maxFlowers(vector<int>& fb) {
    return maxFlowersRecur(fb, 0, 0);
}

int maxFlowersIter(vector<int>& fb) {
    int count = 0;
    for (int i = 0; i < fb.size();) {
        if (fb[i] == 1) {
            // Flower at current position
            i += 2;
        } else {
            bool flower_next = false;
            if (i + 1 < fb.size()) {
                flower_next = fb[i+1] == 1;
            }
            if (flower_next) {
                // Can jump just 1 as well
                i += 3;
            } else {
                // Place flower at i
                count++;
                i += 2;
            }
        }
    }

    return count;
}

int main() {
    vector<int> bed = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0};

    cout << maxFlowersIter(bed) << endl;
    cout << maxFlowers(bed) << endl;


    return 0;
}

