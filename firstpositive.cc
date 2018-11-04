#include "common.hh"

int firstPositive(vector<int>& in) {

    const int size = in.size();
    for (int i = 0; i < size; i++) {
        int elem = in[i];

        if (elem <= 0 || elem > in.size()) {
            continue;
        }
        while (in[elem - 1] != elem) {
            int nextval = in[elem - 1];
            in[elem - 1] = elem;
            in[i] = elem = nextval;
            if (elem <= 0 || elem > in.size()) {
                break;
            }
        }
    }

    int i;
    for (i = 0; i < size; i++) {
        if (in[i] != i + 1) {
            return i + 1;
        }
    }
    return i + 1;
}


int firstPositiveSet(const vector<int>& in) {
    unordered_set<int> s(in.begin(), in.end());
    const int size = in.size();

    for (int i = 1; i <= size + 1; i++) {
        if (s.count(i) == 0) {
            return i;
        }
    }

    assert(false);
    return -1;
}


int main() {

    vector< vector<int> > in = {
        { -10, 1, 4, 2, 3, 5},
        { -10, 1, 4, 2, 1, -2},
        { -10, 1, 3, 2, 1, 5},
        { 1, 2, 3, 4}
    };

    for (auto& v : in) {
        cout << "Set: " << firstPositiveSet(v) << endl;
        cout << "Arr: " << firstPositive(v) << endl;
    }

    return 0;
}

