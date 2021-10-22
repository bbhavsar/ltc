//
// Created by bankim on 7/25/21.
//
#include "common.hh"

// https://www.geeksforgeeks.org/find-rectangles-filled-0/

struct Point {
  int row, col;
  Point(int r, int c) : row(r), col(c) {}
  Point() : row(0), col(0) {}
};

struct Rectangle {
  Point top_left, bottom_right;
  Rectangle(Point top_left, Point bottom_right) :
  top_left(std::move(top_left)), bottom_right(std::move(bottom_right)) {}
};

vector<Rectangle> get_all_rectangles(vector<vector<int>>& matrix) {
  vector<Rectangle> output;

  const int rows = matrix.size();
  if (rows == 0)  return output;
  const int cols = matrix[0].size();
  if (cols == 0) return output;

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (matrix[r][c] == 0) {

        bool row_zero = false;
        bool col_zero = false;

        int m, n;
        for (m = r; m < rows; m++) {
          if (matrix[m][c] == 1) {
            row_zero = true;
            break;
          }
          assert(matrix[m][c] != -1);
          for (n = c; n < cols; n++) {
            if (matrix[m][n] == 1) {
              col_zero = true;
              break;
            }

            matrix[m][n] = -1;
          }
        }
        Point top_left(r, c);
        Point bottom_right(row_zero || m == rows ? m - 1 : m, col_zero  || n == cols ? n - 1 : n);
        output.emplace_back(std::move(top_left), std::move(bottom_right));
      }
    }
  }

  return output;
}

int main() {
  vector< vector<int>> input = {
            {1, 0, 1, 1, 1, 1, 1},
            {1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 0, 1},
            {1, 0, 1, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 1, 1, 1, 0}
        };

  auto output = get_all_rectangles(input);
  for (const auto& r : output) {
    cout << "[ " << r.top_left.row << ", " << r.top_left.col << ", " << r.bottom_right.row << ", "
         << r.bottom_right.col << "]" << endl;
  }

  return 0;
}


