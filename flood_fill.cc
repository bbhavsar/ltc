#include "common.hh"
// Daily Coding Problem: Problem #151 [Medium]

void flood_fill_helper(vector< vector<char> >& mat, vector< vector<bool> >& visited, int x,
    int y, int orig_color, int to_color) {

    if (mat[x][y] != orig_color) {
        return;
    }

    mat[x][y] = to_color;
    visited[x][y] = true;
    for (int row = -1; row <= 1; row++) {
        for (int col = -1; col <= 1; col++) {
            int posx = x  + row;
            int posy = y + col;
            if (posx < 0 || posx >= mat.size() || posy < 0 || posy >= mat[0].size() ||
                    visited[posx][posy]) {
                continue;
            }
            flood_fill_helper(mat, visited, posx, posy, orig_color, to_color);
        }
    }
}

void flood_fill(vector< vector<char> >& mat, int x, int y, int color) {
    if (x >= mat.size() || y >= mat[0].size()) {
        throw invalid_argument("Specified position out of bounds");
    }

    vector< vector<bool> > visited(mat.size(), vector<bool>(mat[0].size(), false));

    flood_fill_helper(mat, visited, x, y, mat[x][y], color);
}


int main() {
    vector< vector<char> > mat = {
        {'B', 'E', 'W'},
        {'W', 'E', 'W'},
        {'E', 'W', 'E'},
        {'B', 'B', 'B'}
    };

    flood_fill(mat, 2, 2, 'G');
    for (auto v : mat) {
        for (auto c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}

