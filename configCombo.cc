#include <iostream>
#include <vector>

using namespace std;

void genRecurse(const vector<vector<int> >& in,
                int level,
                vector<int> *combo_so_far,
                vector < vector <int> > *out) {

    if (level == in.size()) {
        out->push_back(*combo_so_far);
        return;
    }

    for (int elem : in[level]) {
        combo_so_far->push_back(elem);
        genRecurse(in, level + 1, combo_so_far, out);
        combo_so_far->pop_back();
    }
}



void generateCombinations(const vector< vector<int> >& in,
                          vector < vector <int> > *out) {
    vector<int> combo_so_far;
    return genRecurse(in, 0, &combo_so_far, out);
}


int main() {
    vector <vector <int> > in = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    vector< vector <int> > out;
    generateCombinations(in, &out);

    for (const auto& v : out) {
        for (int elem : v) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}

