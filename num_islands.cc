// https://leetcode.com/problems/number-of-islands/

#include "common.hh"

void dfs(const vector< vector<char> >& grid, int x, int y,
         vector< vector<bool> >& visited) {
    assert(!visited[x][y]);
    visited[x][y] = true;
    static const vector< pair<int, int> > pos = { {0, -1}, {-1, 0 }, {1, 0}, {0, 1} };
    for (auto p : pos) {
        int next_x = x + p.first;
        int next_y = y + p.second;
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
            continue;
        }
        if (visited[next_x][next_y]) {
            continue;
        }
        if (grid[next_x][next_y] == '1') {
            dfs(grid, next_x, next_y, visited);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    vector< vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                dfs(grid, i, j, visited);
                count++;
            }
        }
    }
    return count;
}


