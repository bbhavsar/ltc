
// https://leetcode.com/problems/time-based-key-value-store/
#include "common.hh"

class TimeMap {
private:
    unordered_map<string, map<int, string> > m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto it = m.find(key);
        if (it == m.end()) {
            return string();
        }

        auto& sorted_map = it->second;
        auto pos = sorted_map.lower_bound(timestamp);
        if (pos->first == timestamp) {
            return pos->second;
        }
        if (pos == sorted_map.begin()) {
            return string();
        }
        pos--;
        return pos->second;
    }
};

int main() {


    return 0;
}

