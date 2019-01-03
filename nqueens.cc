
#include "common.hh"

bool is_board_valid(const vector<int>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (board[i] != -1 && board[i] == board[j]) {
                return false;
            }
            if (board[i] != -1 && board[j] != -1 && abs(i-j) == abs(board[i]-board[j])) {
                return false;
            }
        }
    }

    return true;
}


vector< vector<int> > n_queens(int n) {
    vector< vector<int> > result;
    vector<int> board(n, -1);
    int row = 0;
    int col = 0;
    while (true) {
        // Search for first column for this row
        for (; col < n; col++) {
            board[row] = col;
            if (is_board_valid(board, n)) {
                break;
            }
        }
        if (col < n) {
            // valid column found for row
            if (row == n - 1) {
                // On last row. One result.
                result.emplace_back(board);

                // Stay on same row and try different column
                board[row] = -1;
                col++;
            } else {
                // Moving onto next row
                row++;
                col = 0;
            }
        } else {
            // backtrack
            board[row] = -1;
            row--;
            if (row < 0) {
                // done. No solution found or done trying all combinations.
                return result;
            } else {
                col = board[row] + 1;
            }
        }
    }


    // Should not come here
    return result;
}

vector < vector<string> > build_result(const vector< vector<int> >& in, int n) {
    vector< vector<string> > result;
    result.reserve(in.size());
    for (auto v : in) {
        vector<string> board_result;
        board_result.reserve(n);
        for (int row = 0; row < n; row++) {
            stringstream row_result;
            for (int col = 0; col < n; col++) {
                if (v[row] == col) {
                    row_result << "Q";
                } else {
                    row_result << ".";
                }
            }
            board_result.emplace_back(row_result.str());
        }
        result.emplace_back(board_result);
    }
    return result;
}

int main() {
    int n = 8;
    auto r = n_queens(n);
    cout << "Num results: " << r.size() << endl;
    int count = 1;
    for (auto v : r) {
        cout << "RESULT: " << count++ << endl;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (v[row] == col) {
                    cout << "Q";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

