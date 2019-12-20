#include "common.hh"

// power set

void powerSet(const vector<int>& in, int idx,
              vector<int>& elems_so_far,
              vector< vector<int> > *result) {
    if (idx == in.size()) {
        result->push_back(elems_so_far);
        return;
    }

    elems_so_far.push_back(in[idx]);
    powerSet(in, idx + 1, elems_so_far, result);
    elems_so_far.pop_back();

    powerSet(in, idx + 1, elems_so_far, result);
}

vector< vector<int> > powerSet(const vector<int>& in) {
    vector< vector<int> > result;
    vector<int> elems_so_far;
    powerSet(in, 0, elems_so_far, &result);

    return result;
}


int main() {
    vector<int> nums = {1, 2, 3, 4};

    for (auto vec : powerSet(nums)) {
        cout << "{ ";
        for (auto elem : vec) {
            cout << elem << " ";
        }
        cout << " }" << endl;
    }

    return 0;
}

