
// https://leetcode.com/problems/spiral-matrix-ii/

#include "common.hh"

vector< vector<int> > generateMatrix(int n) {
    vector< vector<int> > mat(n, vector<int>(n, 0));

    int rs = 0;
    int re = n-1;
    int cs = 0;
    int ce = n-1;

    int num = 1;
    while (rs <= re && cs <= ce) {
        for (int c = cs; c <= ce; c++) {
            mat[rs][c] = num++;
        }
        for (int r = rs + 1; r <= re; r++) {
            mat[r][ce] = num++;
        }

        if (ce > cs) {
            for (int c = ce-1; c >= cs; c--) {
                mat[re][c] = num++;
            }
        }

        if (re > rs) {
            for (int r = re-1; r > rs; r--) {
                mat[r][cs] = num++;
            }
        }

        rs++, re--;
        cs++, ce--;
    }

    return mat;
}

vector<int> printSpiralMatrix(vector< vector<int> >& mat) {
    const int rows = mat.size();
    const int cols = mat[0].size();

    vector<int> result;
    result.reserve(rows * cols);

    int rs = 0;
    int re = rows-1;
    int cs = 0;
    int ce = cols-1;

    while (rs <= re && cs <= ce) {
        for (int c = cs; c <= ce; c++) {
            result.push_back(mat[rs][c]);
        }
        for (int r = rs + 1; r <= re; r++) {
            result.push_back(mat[r][ce]);
        }

        if (ce > cs && re > rs) {
            for (int c = ce-1; c >= cs; c--) {
                result.push_back(mat[re][c]);
            }

            for (int r = re-1; r > rs; r--) {
                result.push_back(mat[r][cs]);
            }
        }

        rs++, re--;
        cs++, ce--;
    }

    return result;
}

void printMatrix(const vector< vector<int> >& mat) {
    for (auto vec : mat) {
        for (auto elem : vec) {
            cout << elem << "\t\t" ;
        }
        cout << endl;
    }
}

int main() {
    printMatrix(generateMatrix(3));
    cout << "========" << endl;

    printMatrix(generateMatrix(4));
    cout << "========" << endl;

    auto mat = generateMatrix(4);
    auto vec = printSpiralMatrix(mat);
    for (auto elem : vec) {
        cout << elem << "   ";
    }
    cout << endl;

    mat = generateMatrix(3);
    vec = printSpiralMatrix(mat);
    for (auto elem : vec) {
        cout << elem << "   ";
    }
    cout << endl;



    return 0;
}

