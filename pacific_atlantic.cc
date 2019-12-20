/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

https://leetcode.com/problems/pacific-atlantic-water-flow/

*/

#include "common.hh"


namespace std {
  template <> struct hash<std::pair<int, int>> {
      inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return 101 * int_hasher(v.first) + int_hasher(v.second);
    }
  };
}

bool dfs(vector< vector<int> >& matrix, int row, int col,
    unordered_map< pair<int, int>, int >& v, const int targetRow, const int targetCol) {
    const pair<int, int> pos = make_pair(row, col);
    if (row == targetRow || col == targetCol) {
      // visited and reachable
      v[pos] = 1;
      return true;
    } else {
      // visiting for now
      v[pos] = 0;
    }

    const static vector< pair<int, int> > search_space =
      { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    for (auto p : search_space) {
      int r = row + p.first;
      int c = col + p.second;
      if (r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size()) {
        continue;
      }
      if (matrix[row][col] < matrix[r][c]) {
        continue;
      }
      // Okay to proceed
      auto it = v.find(make_pair(r, c));
      if (it != v.end()) {
        if (it->second == 1) {
            v[pos] = 1;
            return true;
        } else {
            continue;
        }
      }
      if (dfs(matrix, r, c, v, targetRow, targetCol)) {
        v[pos] = 1;
        return true;
      }
    }

    v[pos] = 2;
    return false;
}

vector< pair<int, int> > pacificAtlantic(vector< vector<int> >& matrix) {
  unordered_map< pair<int, int>, int > v;
  vector< pair<int, int> > pacific_reachable;
  for (int r = 0; r < matrix.size(); r++) {
    for (int c = 0; c < matrix[0].size(); c++) {
      pair<int, int> pos = make_pair(r, c);
      auto it = v.find(pos);
      bool reachable;
      if (it == v.end()) {
        reachable = dfs(matrix, r, c, v, 0, 0);
      } else {
        assert(it->second != 0);
        reachable = it->second == 1;
      }
      if (reachable) {
        pacific_reachable.emplace_back(pos);
      }
    }
  }

  v.clear();
  vector< pair<int, int> > result;
  for (auto p : pacific_reachable) {
      auto it = v.find(p);
      bool reachable;
      if (it == v.end()) {
        reachable = dfs(matrix, p.first, p.second, v, matrix.size()-1, matrix[0].size()-1);
      } else {
        assert(it->second != 0);
        reachable = it->second == 1;
      }
      if (reachable) {
        result.emplace_back(p);
      }
  }

  return result;
}

int main() {
  vector< vector<int> > matrix = {
       {  1,   2,   2,  3,  5},
       {  3,   2,   3,  4, 4 },
       {  2,   4,   5,  3,   1  },
       {  6,   7,   1,   4,   5  },
       {  5,   1,   1,   2,   4}
  };

  auto r = pacificAtlantic(matrix);
  for (auto p : r) {
    cout << "[" << p.first << "," << p.second << "] ";
  }
  cout << endl;

  return 0;
}




