#include "common.hh"

#include <stdlib.h>     /* srand, rand */
#include <time.h>

// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = m.find(val);
        if (it != m.end()) {
            return false;
        }
        v.push_back(val);
        int idx = v.size() - 1;
        m[val] = idx;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end()) {
            return false;
        }
        int idx = it->second;
        swap(v[idx], v[v.size()-1]);
        m[v[idx]] = idx;
        v.pop_back();
        m.erase(it);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

int main() {


    return 0;
}

