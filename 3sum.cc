
#include "common.hh"

struct ThreeElem {
    int a, b, c;
    ThreeElem(int x, int y, int z) : a(x), b(y), c(z) {}
    bool operator==(const ThreeElem& that) const {
        unordered_set<int> this_set;
        unordered_set<int> that_set;
        this_set.insert({a, b, c});
        that_set.insert({that.a, that.b, that.c});
        return this_set == that_set;
    }
};

namespace std {
    template<> struct hash<ThreeElem>  {
        size_t operator()(const ThreeElem & e) const {
            return 31 * e.a + 31* e.b + 31* e.c;
        }
    };
}

vector< vector<int> > threeSum(vector<int>& nums) {
    unordered_map<int, vector<int> > num_idx;
    const int size = nums.size();
    for (int i = 0; i < size; i++) {
        num_idx[nums[i]].push_back(i);
    }

    vector< vector<int> > result;
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            int remain = -(nums[i] + nums[j]);
            auto it = num_idx.find(remain);
            if (it != num_idx.end()) {
                auto v = it->second;
                for (auto idx  : v) {
                    if (idx > i && idx > j) {
                        vector<int> r = { nums[i], nums[j], nums[idx] };
                        result.emplace_back(r);
                        break;
                    }
                }
            }
        }
    }

    unordered_set<ThreeElem> seen;
    vector< vector<int> > r;
    for (const auto& v : result) {
        assert(v.size() == 3);
        ThreeElem e(v[0], v[1], v[2]);
        if (seen.count(e) == 0) {
            r.emplace_back(v);
            seen.insert(e);
        }
    }
    return r;
}


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    for (auto v : threeSum(nums)) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}

