#include "common.hh"

class LRUCache {
    list< pair<int, int> > l;
    unordered_map<int, list< pair<int, int> >::iterator > m;
    int capacity;
public:
    LRUCache(int capacity) :  capacity(capacity) { }
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }

        auto lit = it->second;
        auto kv = *lit;
        assert(kv.first == key);
        l.push_front(kv);
        l.erase(lit);
        m[key] = l.begin();
        return kv.second;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            l.erase(it->second);
            l.emplace_front(key, value);
            m[key] = l.begin();
            return;
        }

        if (m.size() == capacity) {
            // evict
            auto last = l.back();
            auto key = last.first;
            m.erase(key);
            l.pop_back();
        }
        assert(m.size() < capacity);
        l.emplace_front(key, value);
        m[key] = l.begin();
    }
};


int main() {


    return 0;
}

