#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector< pair<int, int> > arrayPairSum(const vector<int>& in, int k) {
    unordered_set<int> seen;
    vector< pair<int, int> > out;

    for (int elem : in) {
        int target = k - elem;
        if (seen.count(target) == 0) {
            seen.insert(elem);
        } else {
            out.emplace_back(target, elem);
        }
    }

    return out;
}

int main() {
    vector<int> in = {1, 0, 2, 4, 3};
    for (const auto& p : arrayPairSum(in, 5)) {
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }

    return 0;
}

