
#include "common.hh"

double median_n(const vector<int>& a, const vector<int>& b) {
    const int size = a.size() + b.size();
    if (size == 0) {
        return INT_MIN;
    }
    if (size == 1) {
        return a.empty() ? b[0] : a[0];
    }
    int mIdx1, mIdx2;

    assert(size >= 2);

    // Odd total elements
    if (size & 0x1) {
        mIdx1 = size / 2;
        mIdx2 = -1;
    } else {
        mIdx2 = size / 2;
        mIdx1 = mIdx2 - 1;
    }

    int elem1, elem2;
    for (int writeIdx = 0, aIdx = 0, bIdx = 0; ; writeIdx++) {
        int elem;
        if (aIdx < a.size() && bIdx < b.size()) {
            if (a[aIdx] <= b[bIdx]) {
                elem = a[aIdx++];
            } else {
                elem = b[bIdx++];
            }
        } else if (aIdx == a.size()) {
            elem = b[bIdx++];
        } else {
            assert(bIdx == b.size());
            elem = a[aIdx++];
        }

        if (writeIdx == mIdx1) {
            elem1 = elem;
            if (mIdx2 == -1) {
                break;
            }
        } else if (writeIdx == mIdx2) {
            elem2 = elem;
            break;
        }
    }
    if (mIdx2 == -1) {
        return elem1;
    }
    return ((double)(elem1 + elem2)) / 2.0;
}


int main() {
    vector<int> a = { 1, 5, 10, 15};
    vector<int> b = { 6, 11, 14, 16};

    cout << median_n(a, b) << endl;

    vector<int> x = { 1, 2, 3, 4};
    vector<int> y = { 6, 11, 14, 16};

    cout << median_n(x, y) << endl;

    return 0;
}

