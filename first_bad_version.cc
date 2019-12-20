#include "common.hh"

bool isBadVersion(int version) {
    return false;
}


int firstBadVersion(int n) {
    int l = 1;
    int r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (isBadVersion(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {

    return 0;
}

