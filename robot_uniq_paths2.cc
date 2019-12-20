#include "common.hh"


int num_paths(const vector< vector<int> >& mat, int x, int y,
              vector< vector<int> >& cache) {
    if (x == mat.size() - 1 && y == mat[0].size() - 1 ) {
        return 1;
    }
    if (x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size()) {
        return 0;
    }
    if (cache[x][y] != -1) {
        return cache[x][y];
    }

    if (mat[x][y] == 1) {
        cache[x][y] = 0;
        return cache[x][y];
    }
    int num_paths_down = num_paths(mat, x + 1, y, cache);
    int num_paths_right = num_paths(mat, x, y + 1, cache);
    cache[x][y] = num_paths_down + num_paths_right;
    return cache[x][y];
}

int unique_paths(const vector< vector<int> >& mat) {
    if (mat.empty() || mat[0].empty()) {
        return 0;
    }

    vector< vector<int> > cache(mat.size(), vector<int>(mat[0].size(), -1));
    return num_paths(mat, 0, 0, cache);
}

int unique_paths_dp(const vector< vector<int> >& mat) {
    if (mat.empty() || mat[0].empty()) {
        return 0;
    }
    const int lastRow = mat.size()-1;
    const int lastCol = mat[0].size()-1;
    if (mat[lastRow][lastCol] == 1) {
        return 0;
    }
    vector< vector<int> > dp(mat.size(), vector<int>(mat[0].size(), 0));

    dp[lastRow][lastCol] = 1;
    for (int col = lastCol-1; col >= 0; col--) {
        dp[lastRow][col] = !mat[lastRow][col] && dp[lastRow][col+1];
    }
    for (int row = lastRow-1; row >= 0; row--) {
        dp[row][lastCol] = !mat[row][lastCol] && dp[row + 1][lastCol];
    }

    for (int row = lastRow - 1; row >= 0; row--) {
        for (int col = lastCol - 1; col >= 0; col--) {
            if (mat[row][col] == 1) {
                dp[row][col] = 0;
            } else {
                dp[row][col] = dp[row+1][col] + dp[row][col+1];
            }
        }
    }
    return dp[0][0];
}

int main() {

    return 0;
}


