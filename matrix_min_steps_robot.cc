/*
You are given an M by N matrix consisting of booleans that represents a board.
Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number
of steps required to reach the end coordinate from the start. If there is no possible path,
then return null. You can move up, left, down, and right. You cannot move through walls.
You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps
required to reach the end is 7, since we would need to go through (1, 2) because there is a
wall everywhere else on the second row.
*/

#include "common.hh"
#include <set>

struct Point {
    int x, y;
    Point() : x(0), y(0) {}

    Point(int row, int col) : x(row), y(col) {}

    bool operator==(const Point& that) const {
        return this->x == that.x && this->y == that.y;
    }

    bool operator<(const Point& that) const {
        return this->x < that.x || (this->x == that.x && this->y < that.y);
    }

};

struct PointHash {
    size_t operator()(const Point& p) const {
        return p.x * 31 + p.y;
    }
};

int min_steps_matrix(const vector< vector<bool> >& mat, const Point& start,
                     const Point& end) {
    if (mat.empty() || mat[0].empty()) {
        return -1;
    }

    assert(!mat[start.x][start.y]);
    assert(!mat[end.x][end.y]);

    int num_steps = 0;
    const int rows = mat.size();
    const int cols = mat[0].size();
    const vector<Point> up_down = { Point(-1, 0), Point(0, -1), Point(0, 1), Point(1, 0) };

    queue<Point> q;
    q.push(start);
    unordered_set<Point, PointHash> visited;
    visited.insert(start);

    while (!q.empty()) {
        int num_size = q.size();
        while (num_size > 0) {
            const Point coord = q.front();
            q.pop();
            num_size--;
            if (coord == end) {
                return num_steps;
            }
            for (auto p : up_down) {
                const int x = coord.x + p.x;
                const int y = coord.y + p.y;
                if (x < 0 || x >= rows || y < 0 || y >= cols ||
                    visited.count(Point(x,y)) != 0 || mat[x][y]) {
                    continue;
                }
                q.emplace(Point(x, y));
                visited.emplace(Point(x,y));
            }
        }
        num_steps++;
    }

    return -1;
}


int main() {
    vector< vector<bool> > mat = { {false, false, false, false},
        {true, true, false, true},
        {false, false, false, false},
        {false, false, false, false}
    };

    cout << min_steps_matrix(mat, Point(3,0), Point(0,0)) << endl;

    return 0;
}

