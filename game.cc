
#include <vector>
#include "assert.h"
#include <iostream>
#include <time.h>

using namespace std;

struct Result {
    vector< vector<int> > board;
    bool won;
    int user;
    bool colFull;
    Result() : won(false), user(-1), colFull(false) {}
};

class Game {
private:
    vector< vector<int> > board;
    int rows;
    int cols;
    int done;
    int num_discs;

    bool checkBoard(int row, int col, int user) {
        // vertical case
        int vertical_count = 1;
        for (int i = row + 1; i < rows; i++) {
            if (board[i][col] == user) {
                if (++vertical_count == 4) {
                    return true;
                }
            } else {
                break;
            }
        }

        // horizontal case
        int left_count = 0;
        for (int j = col; j >= 0; j--) {
            if (board[row][j] == user) {
                left_count++;
            } else {
                break;
            }
        }
        int right_count = 0;
        for (int j = col + 1; j < cols; j++) {
            if (board[row][j] == user) {
                right_count++;
            } else {
                break;
            }
        }
        if ((left_count + right_count) >= 4) {
            return true;
        }

        // diagonal cases
        // left diagonal
        int left_diag_1 = 0;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == user) {
                left_diag_1++;
            } else {
                break;
            }
        }

        int left_diag_2 = 0;
        for (int i = row+1, j = col+1; i < rows && j < cols; i++, j++) {
            if (board[i][j] == user) {
                left_diag_2++;
            } else {
                break;
            }
        }
        if (left_diag_1 + left_diag_2 >= 4) {
            return true;
        }

        // right_diag case
        int right_diag_1 = 0;
        for (int i = row, j = col; i >= 0 && j < cols; i--, j++) {
            if (board[i][j] == user) {
                right_diag_1++;
            } else {
                break;
            }
        }

        int right_diag_2 = 0;
        for (int i = row+1, j = col-1; i < rows && j >= 0; i++, j--) {
            if (board[i][j] == user) {
                right_diag_2++;
            } else {
                break;
            }
        }
        if (right_diag_1 + right_diag_2 >= 4) {
            return true;
        }

        return false;
    }
public:
    Game(int rows, int cols) {
        board.resize(rows);
        vector<int> col(cols, -1);
        for (int i = 0; i < rows; i++) {
            board[i] = col;
        }
        this->rows = rows;
        this->cols = cols;
        done = false;
        num_discs = 0;
    }

    Result insertDisc(int user, int col) {
        assert(user == 1 || user == 0);
        assert(col >= 0 && col < cols);
        assert(!done);

        int row = 0;
        for (; row < rows; row++) {
            if (board[row][col] == -1) {
                break;
            }
        }
        if (row == rows) {
            Result r;
            r.colFull = true;
            return r;
        }
        board[row][col] = user;
        num_discs++;
        Result r;
        if (checkBoard(row, col, user)) {
           r.won = true;
           r.user = user;
           r.board = board;
           done = true;
        } else {
            r.won = false;
            r.user = user;
            r.board = board;
        }
        return r;
    }

    bool isDone() {
        return done;
    }
    bool isBoardFull() {
        return num_discs == rows * cols;
    }
    void print() {
        for (auto vec : board) {
            for (auto elem : vec) {
                cout << elem << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    const int rows = 6;
    const int cols = 7;
    Game g(rows, cols);
    int user = 0;
    srand (time(NULL));

    while (!g.isDone() && !g.isBoardFull()) {
        int col = rand() % cols;
        cout << "User " << user << " inserting in col " << col << endl;
        Result r = g.insertDisc(user, col);
        g.print();
        if (r.won) {
            cout << "User: " << user << " won! " << endl;
            return 0;
        }
        if (r.colFull) {
           cout << "Column " << col << " full. Retrying.. " << endl;
        } else {
            user = (user + 1) % 2;
        }
    }

    return 0;
}

