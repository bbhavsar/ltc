#include "common.hh"
// https://leetcode.com/problems/shortest-distance-from-all-buildings/

int shortestDistance(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return -1;
    }
    const int rows = grid.size();
    const int cols = grid[0].size();

    vector< vector<int> > visits(rows, vector<int>(cols, 0));
    vector< vector<int> > dist(rows, vector<int>(cols, 0));

    int num_bldgs = 0;
    static const vector< pair<int, int> > dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                num_bldgs++;

                queue< pair<int, int> > q;
                vector< vector<int> > visited(rows, vector<int>(cols, 0));
                q.emplace(i, j);
                visited[i][j] = 1;
                int level = 0;
                while (!q.empty()) {
                    int to_process = q.size();
                    level++;

                    while (to_process-- > 0) {
                        auto u = q.front();
                        q.pop();
                        for (auto p : dir) {
                            int row = u.first + p.first;
                            int col = u.second + p.second;
                            if (row < 0 || row >= rows || col < 0 || col >= cols) {
                                continue;
                            }
                            if (visited[row][col] == 1) {
                                continue;
                            }
                            if (grid[row][col] == 0) {
                                visits[row][col]++;
                                dist[row][col] += level;
                                cout << row << " " << col << " " << visits[row][col] << " " <<  dist[row][col] << endl;
                                q.emplace(row, col);
                                visited[row][col] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    int min_dist = INT_MAX;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0 && visits[i][j] == num_bldgs && dist[i][j] < min_dist) {
                min_dist = dist[i][j];
            }
        }
    }

    return min_dist == INT_MAX ? -1 : min_dist;
}

int main() {
    vector< vector<int> > grid = { {1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0} };

    cout << shortestDistance(grid) << endl;

    return 0;
}

