#include <iostream>
#include <vector>
using namespace std;


vector< vector<int> > computeCachedSum(const vector< vector <int> >& mat) {
    vector< vector<int> > cachedSum;
    cachedSum.resize(mat.size());
    for (int row = 0; row < mat.size(); ++row) {
        cachedSum[row].resize(mat[row].size());
    }

    cachedSum[0][0] = mat[0][0];
    for (int col = 1; col < cachedSum[0].size(); ++col) {
        cachedSum[0][col] = cachedSum[0][col-1] + mat[0][col];
    }

    for (int row = 1; row < cachedSum.size(); ++row) {
        cachedSum[row][0] = cachedSum[row-1][0] + mat[row][0];
    }

    for (int row = 1; row < cachedSum.size(); ++row) {
        for (int col = 1; col < cachedSum[row].size(); ++col) {
            cachedSum[row][col] = cachedSum[row-1][col] + cachedSum[row][col-1] -
                                     cachedSum[row-1][col-1] + mat[row][col];
        }
    }

    return cachedSum;
}


int matrixRegionSumDP(const vector< vector<int> >& mat,
                      const pair<int, int>& topLeft,
                      const pair<int, int>& bottomRight) {

    static vector< vector<int> > cachedSum = computeCachedSum(mat);

    if (topLeft.first == 0 && topLeft.second == 0) {
        return cachedSum[bottomRight.first][bottomRight.second];
    }

    if (topLeft.first == 0) {
        return cachedSum[bottomRight.first][bottomRight.second] - cachedSum[bottomRight.first][topLeft.second-1];
    }

    if (topLeft.second == 0) {
        return cachedSum[bottomRight.first][bottomRight.second] - cachedSum[topLeft.first-1][bottomRight.second];
    }

    return cachedSum[bottomRight.first][bottomRight.second] - cachedSum[bottomRight.first][topLeft.second-1] -
            cachedSum[topLeft.first-1][bottomRight.second] + cachedSum[topLeft.first-1][topLeft.second-1];
}

int matrixRegionSum(const vector< vector<int> >& mat,
                    const pair<int, int>& topLeft,
                    const pair<int, int>& bottomRight) {
    int sum = 0;
    for (int row = topLeft.first; row <= bottomRight.first && row < mat.size(); row++) {
        for (int col = topLeft.second; col <= bottomRight.second && col < mat[row].size(); col++) {
            sum += mat[row][col];
        }
    }

    return sum;
}

int main() {
    vector< vector <int> > mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << matrixRegionSum(mat, make_pair(1,1), make_pair(2,3)) << endl;
    cout << matrixRegionSum(mat, make_pair(1,0), make_pair(2,3)) << endl;
    cout << matrixRegionSumDP(mat, make_pair(1,0), make_pair(2,3)) << endl;
    cout << matrixRegionSumDP(mat, make_pair(1,1), make_pair(2,3)) << endl;

    return 0;
}

