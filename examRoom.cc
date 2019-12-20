#include "common.hh"



class ExamRoom {
private:
    set<int> pos;
    int N;
public:
    ExamRoom(int N) : N(N) {}
    int seat() {
        if (pos.empty()) {
            if (N == 0) {
                return -1;
            } else {
                pos.insert(0);
                return 0;
            }
        }
        int max_pos;
        int max_dist = 0;
        // case when pos 0 is not assigned consider interval from 0 to first assigned pos
        if (*pos.begin() != 0) {
            max_dist = *pos.begin() - 0;
            max_pos = 0;
        }
        int prev = *pos.begin();
        // iterate over sorted intervals
        for (auto curr = ++pos.begin(); curr != pos.end(); ++curr) {
            int curr_dist = (*curr-prev) / 2;
            if (curr_dist > max_dist) {
                max_dist = curr_dist;
                max_pos = prev + max_dist;
            }
            prev = *curr;
        }
        // case when pos N-1 is not assigned consider interval from last assigned pos to end
        if (prev != N-1) {
            int curr_dist = (N-1 - prev);
            if (curr_dist > max_dist) {
                max_dist = curr_dist;
                max_pos = N-1;
            }
        }
        if (max_dist == 0) {
            return -1;
        }
        pos.insert(max_pos);
        return max_pos;
    }

    void leave(int p) {
        pos.erase(p);
    }
};

int main() {


    return 0;
}

