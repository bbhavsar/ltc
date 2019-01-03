#include "common.hh"
/*

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down.
You may NOT move diagonally or move outside of the boundary
(i.e. wrap-around is not allowed).

*/

int path_len_recur(const vector< vector<int> >& mat, int i, int j, int path_len,
     vector< vector<bool> >& visited) {
    visited[i][j] = true;
    static const vector< pair<int, int> > adj_list = { make_pair(i-1,j), make_pair(i+1,j), make_pair(i,j-1),
        make_pair(i,j+1) };
    int max_path_len = path_len;
    for (auto p : adj_list) {
        int x = p.first;
        int y = p.second;
        if (x >= 0 && x < mat.size() && y >= 0 && y < mat[x].size() && mat[x][y] > mat[i][j] &&
            !visited[x][y]) {
            max_path_len = max(max_path_len, path_len_recur(mat, x, y, path_len + 1, visited));
        }
    }

    return max_path_len;
}


int longestIncreasingPath(vector<vector<int> >& matrix) {
    int max_path_len = -1;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            vector<vector<bool> > visited(matrix.size(), vector<bool>(matrix[0].size(), false));
            max_path_len = max(max_path_len, path_len_recur(matrix, i, j, 1, visited));
        }
    }

    return max_path_len;
}

int main() {
    vector< vector<int> > input = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };

    cout << longestIncreasingPath(input) << endl;

    vector< vector<int> > input2 = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };

    cout << longestIncreasingPath(input2) << endl;

    return 0;
}

