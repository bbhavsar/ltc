#include <iostream>
#include <vector>

// clang++ -std=c++11 -stdlib=libc++  -Wno-c++98-compat largestIsland.cc

using namespace std;
class Solution {
public:
    int maxAreaRecurse(const vector< vector < int > >& grid, int x, int y,
                        vector< vector < bool> >& visited) {
        if (x >= grid.size() || y >= grid[x].size()) {
            return 0;
        }
        if (grid[x][y] == 0 || visited[x][y]) {
            return 0;
        }
        visited[x][y] = true;
        return 1 +
            maxAreaRecurse(grid, x - 1, y, visited) +
            maxAreaRecurse(grid, x + 1 , y, visited) +
            maxAreaRecurse(grid, x, y -1, visited) +
            maxAreaRecurse(grid, x, y + 1, visited);
    }

    int maxAreaOfIsland(const vector< vector< int > >& grid) {
        vector< vector< bool > > visited;
        visited.resize(grid.size());
        for (int i = 0; i < visited.size(); i++) {
            visited[i].resize(grid[i].size());
	}
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int area = maxAreaRecurse(grid, i, j, visited);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
        return maxArea;
    }
};

int main () {
    vector < vector < int > > grid {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}

