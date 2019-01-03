/*
 *
 * On our special chessboard, two bishops attack each other if they share the same diagonal.
 * This includes bishops that have another bishop located between them, i.e. bishops
 * can attack through pieces.
 *
 * You are given N bishops, represented as (row, column) tuples on a M by M chessboard.
 * Write a function to count the number of pairs of bishops that attack each other.
 * The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).
 *
 * For example, given M = 5 and the list of bishops:
 *
 * (0, 0)
 * (1, 2)
 * (2, 2)
 * (4, 0)
 * The board would look like this:
 *
 * [b 0 0 0 0]
 * [0 0 b 0 0]
 * [0 0 b 0 0]
 * [0 0 0 0 0]
 * [b 0 0 0 0]
 * You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.
 *
 */

#include "common.hh"

int num_attacking_bishops(const vector< pair<int, int> >& mat) {
    const int size = mat.size();
    int result = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(mat[i].second - mat[j].second) == abs(mat[i].first - mat[j].first)) {
                result++;
            }
        }
    }


    return result;
}


int main() {
    vector< pair<int, int> > input = {
        make_pair(0,0), make_pair(1,2), make_pair(2,2), make_pair(4,0)
    };

    cout << num_attacking_bishops(input) << endl;

    return 0;
}



