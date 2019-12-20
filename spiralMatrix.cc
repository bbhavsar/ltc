
// https://leetcode.com/problems/spiral-matrix/
#include "common.hh"


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    const int num_rows = matrix.size();
    const int num_cols = matrix[0].size();
    vector<int> result;
    int itr = 0;
    int result_elems;
    do {
        result_elems = result.size();
        int row = itr;
        int col = itr;
        for (; col < num_cols - itr; col++) {
            result.push_back(matrix[row][col]);
        }
        row++;
        col--;
        for (; row < num_rows - itr; row++) {
            result.push_back(matrix[row][col]);
        }
        row--;
        col--;
        for (; col >= itr; col--) {
            result.push_back(matrix[row][col]);
        }
        col++;
        row--;
        for(; row > itr; row--) {
            result.push_back(matrix[row][col]);
        }
        itr++;
    } while (result.size() > result_elems);

    return result;
}

void printMat(vector< vector<int> >& mat) {
    for (auto elem : spiralOrder(mat)) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    vector< vector<int> > mat = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    printMat(mat);

    vector< vector<int> > mat1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };

    printMat(mat1);

    return 0;
}





