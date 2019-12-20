#include "common.hh"

// https://leetcode.com/problems/interval-list-intersections/

void mergeHelper(const vector< vector<int> >& A,
                 const vector< vector<int> >& B,
                 int &ai,
                 int &bi,
                 vector< vector<int> >& result) {
    if (B[bi][0] <= A[ai][1]) {
        vector<int> r = {B[bi][0], min(A[ai][1], B[bi][1])};
        result.push_back(r);
        if (A[ai][1] < B[bi][1]) {
            ai++;
        } else {
            bi++;
        }
    } else {
        ai++;
    }
}

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    int ai = 0, bi = 0;

    vector< vector<int> > result;
    while (ai < A.size() && bi < B.size()) {
        if (A[ai][0] < B[bi][0]) {
            mergeHelper(A, B, ai, bi, result);
        } else {
            mergeHelper(B, A, bi, ai, result);
        }
    }
    return result;
}

int main() {
    vector< vector<int> > A = {
        {0, 2}, {5, 10}, {13, 23}, {24, 25}
    };

    vector< vector<int> > B = {
        {1, 5}, {8, 12}, {15, 24}, {25, 26}
    };

    for (auto vec : intervalIntersection(A, B)) {
        cout << "[" << vec[0] << ", " << vec[1] << "],";
    }
    cout << endl;

    return 0;

}

