#include "common.hh"


class TicTacToe {
private:
    int n;
    vector< vector<int> > mat;
    int won;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n), mat(vector< vector<int> > (n, vector<int>(n, 0))), won(0) { }
    bool checkWin(int player, int row, int col) {
        // check row
        int c = 0;
        for (; c < n; c++) {
            if (mat[row][c] != player) {
                break;
            }
        }
        if (c == n) {
            won = player;
            return true;
        }
        // check col
        int r = 0;
        for (; r < n; r++) {
            if (mat[r][col] != player) {
                break;
            }
        }
        if (r == n) {
            won = player;
            return true;
        }
        if (row == col || row == n - col - 1) {
            // check left diag
            int i;
            for (i = 0; i < n; i++) {
                if (mat[i][i] != player) {
                    break;
                }
            }
            if (i == n) {
                won = player;
                return true;
            }
            // check right diag
            for (i = 0; i < n; i++) {
                if (mat[i][n-i-1] != player) {
                    break;
                }
            }
            if (i == n) {
                won = player;
                return true;
            }
            return false;
        } else {
            return false;
        }
    }
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (won != 0) {
            return won;
        }

        mat[row][col] = player;
        if (checkWin(player, row, col)) {
            return won;
        }

        return 0;
    }
};

int main() {
    TicTacToe t(2);

    cout << t.move(0, 1, 1) << endl;
    cout << t.move(1, 1, 2) << endl;
    cout << t.move(1, 0, 1) << endl;

    return 0;
}

