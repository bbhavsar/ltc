#include <iostream>
#include "common.hh"

// http://www.cplusplus.com/forum/general/44552/

void perm(vector<int>& in, int startIdx, vector< vector<int> >& out) {
    if (startIdx == in.size()) {
        out.push_back(in);
        return;
    }

    for (int i = startIdx; i < in.size(); i++) {
        swap(in[i], in[startIdx]);
        perm(in, startIdx+1, out);
        swap(in[i], in[startIdx]);
    }
}

vector<vector<int> > permutationVector(vector<int>& in) {
    vector< vector<int> > out;
    perm(in, 0, out);
    return out;
}

int main() {
    vector<int> in = {1, 2, 3, 4};
    auto out = permutationVector(in);
    for (auto vec : out)  {
        cout << "[ ";
        for (auto elem : vec) {
            cout << elem << " ";
        }
        cout << "] " << endl;
    }
    return 0;
}

