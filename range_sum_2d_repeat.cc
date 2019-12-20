#include "common.hh"


class NumMatrix {
private:
    const int rows, cols;
    vector< vector<int> > sum;
public:
    NumMatrix(vector<vector<int>>& matrix) :
         rows(matrix.size()), cols(matrix[0].size()),
         sum(rows, vector<int>(cols, 0)) {

        if (rows == 0 || cols == 0) {
            return;
        }
        sum[0][0] = matrix[0][0];
        for (int col = 1; col < cols; col++) {
            sum[0][col] = sum[0][col-1] + matrix[0][col];
        }

        for (int row = 1; row < rows; row++) {
            sum[row][0] = sum[row-1][0] + matrix[row][0];
        }

        for (int row = 1; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                sum[row][col] = sum[row-1][col] + sum[row][col-1] - sum[row-1][col-1] + matrix[row][col];
                // cout << row << " " << col << " " << sum[row][col] << endl;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (rows == 0 || cols == 0) {
            return 0;
        }
        return sum[row2][col2] - (row1 > 0 ? sum[row1-1][col2] : 0) -
                                 (col1 > 0 ? sum[row2][col1-1] : 0) +
                                 (row1 > 0 && col1 > 0 ? sum[row1-1][col1-1] : 0);
    }
};

int main() {
    vector< vector<int> > matrix = {
  {3, 0, 1, 4, 2},
  {5, 6, 3, 2, 1},
  {1, 2, 0, 1, 5},
  {4, 1, 0, 1, 7},
  {1, 0, 3, 0, 5}
};

    NumMatrix nm(matrix);
    cout << nm.sumRegion(2, 1, 4, 3) << endl;
    cout << nm.sumRegion(1, 1, 2, 2) << endl;
    cout << nm.sumRegion(1, 2, 2, 4) << endl;

    return 0;
}

