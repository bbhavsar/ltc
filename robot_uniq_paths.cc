
//  https://leetcode.com/problems/unique-paths/

#include "common.hh"


int dfs_recurse(int row, int col, const int m, const int n,
                 vector< vector<int> >& cache) {
    if (row >= m || col >= n) {
        return 0;
    }

    if (row == m-1 && col == n-1) {
        return 1;
    }

    if (cache[row][col] != -1) {
        return cache[row][col];
    }

    cache[row][col] = dfs_recurse(row+1, col, m, n, cache) +
                      dfs_recurse(row, col+1, m, n, cache);
    return cache[row][col];
}

int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }

    vector< vector<int> > cache(m, vector<int>(n, -1));
    return dfs_recurse(0, 0, m, n, cache);
}


int main() {
    cout << uniquePaths(3, 2) << endl;
    cout << uniquePaths(3, 3) << endl;
    cout << uniquePaths(7, 3) << endl;

    return 0;
}

