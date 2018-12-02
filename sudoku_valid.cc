#include "common.hh"

/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

*/

bool valid_sudoku(const vector< vector <char> >& board) {
    assert(board.size() == 9 && board[0].size() == 9);

    // validate rows and cols together
    for (int i = 0; i < 9; i++) {
        vector<bool> row_seen(10, false);
        vector<bool> col_seen(10, false);
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                char num = board[i][j] - '0';
                if (row_seen[num]) {
                    return false;
                }
                row_seen[num] = true;
            }

            if (board[j][i] != '.') {
                char num = board[j][i] - '0';
                if (col_seen[num]) {
                    return false;
                }
                col_seen[num] = true;
            }
        }
    }

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            vector<bool> num_seen(10, false);
            for (int x = i +  0; x < i + 3; x++) {
                for (int y = j + 0; y < j + 3; y++) {
                    if (board[x][y] != '.') {
                        char num = board[x][y] - '0';
                        if (num_seen[num]) {
                            return false;
                        }
                        num_seen[num] = true;
                    }
                }
            }
        }
    }

    return true;
}

int main() {

    return 0;
}

