#include "common.hh"

class Iterator {
private:
    int i, j;
    vector < vector<int> > v;
public:
    Iterator(vector< vector<int> > v) : i(0), j(0), v(v) {}

    bool hasNext() {
        return i < v.size() && j < v[i].size();
    }

    int getNext() {
        assert(i < v.size() && j < v[i].size());
        int result = v[i][j];
        j++;
        while (i < v.size() && j == v[i].size()) {
            i++;
            j = 0;
        }
        return result;
    }
};


int main() {

    return 0;
}




