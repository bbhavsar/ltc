#include "common.hh"


void dfs(vector< vector<int> >& mat, int row, int col, int& sum) {

    if (row < 0 || col < 0 || row >= mat.size() || col >= mat[0].size()) {
        return;
    }
    if (mat[row][col] == 0 || mat[row][col] == -1) {
        return;
    }
    sum += mat[row][col];
    mat[row][col] = -1;

    const vector< pair<int, int> > dir = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

    for (auto p : dir) {
        int r = row + p.first;
        int c = col + p.second;
        dfs(mat, r, c, sum);
    }
}


int maxSumIsland(vector< vector<int> >& mat) {

    int result = 0;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            int sum = 0;
            dfs(mat, i, j, sum);
            result = max(result, sum);
        }
    }

    return result;
}

int main() {


    return 0;
}
 
