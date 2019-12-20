#include "common.hh"

vector< vector<int> > matrixMult(vector< vector<int> >& A,
                                 vector< vector<int> >& B) {
    if (A.empty() || B.empty()) {
        return vector< vector<int> >();
    }

    if (A[0].size() != B.size()) {
        throw invalid_argument("Dimensions not compatible");
    }

    vector< vector<int> > mult(A.size(), vector<int>(B[0].size(), 0));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < A[0].size(); k++) {
                mult[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return mult;
}

vector< vector<int> > matrixMultSparse(vector< vector<int> >& A,
                                       vector< vector<int> >& B) {
    if (A.empty() || B.empty()) {
        return vector< vector<int> >();
    }
    if (A[0].size() != B.size()) {
        throw invalid_argument("Dimensions not compatible");
    }
    vector<int> ARowNums(A.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] != 0) {
                ARowNums[i]++;
            }
        }
    }

    vector<int> BColNums(B.size(), 0);
    for (int j = 0; j < B[0].size(); j++) {
        for (int i = 0; i < B.size(); i++) {
            if (B[i][j] != 0) {
                BColNums[j]++;
            }
        }
    }

    vector< vector<int> > mult(A.size(), vector<int>(B[0].size(), 0));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            int rowNumLeft = ARowNums[i];
            int colNumLeft = BColNums[j];
            for (int k = 0; k < A[0].size() && rowNumLeft && colNumLeft; k++) {
                mult[i][j] += A[i][k] * B[k][j];
                if (A[i][k] != 0) {
                    rowNumLeft--;
                }
                if (B[k][j] != 0) {
                    colNumLeft--;
                }
            }
        }
    }

    return mult;
}

int main() {
    vector< vector<int> > dims = { {10, 20}, {20, 30}, {30, 40}, {40, 30} };


    return 0;
}

