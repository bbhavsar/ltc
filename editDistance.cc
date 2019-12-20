#include "common.hh"

int editDistanceRecur(const string& src, int sidx,
                      const string& dst, int didx) {
    if (sidx >= src.length()) {
        return dst.length() - didx;
    }

    if (didx >= dst.length()) {
        return src.length() - sidx;
    }

    if (src[sidx] == dst[didx]) {
        return 0 + editDistanceRecur(src, sidx+1, dst, didx+1);
    }

    int add = 1 + editDistanceRecur(src, sidx, dst, didx + 1);
    int remove = 1 + editDistanceRecur(src, sidx+1, dst, didx);
    int substitute = 1 + editDistanceRecur(src, sidx+1, dst, didx+1);
    return min(add, min(remove, substitute));
}

int editDistanceRecur(const string& src, const string& dst) {
    return editDistanceRecur(src, 0, dst, 0);
}


int main() {
    vector< vector<string> > strings = { {"cat", "kat"}, {"foo", "fooz"}, {"cat", "ct"},
                                         {"dog", "cat"}};

    for (auto s : strings) {
        cout << s[0] << " " << s[1] << " : " << editDistanceRecur(s[0], s[1]) << endl;
    }
    return 0;
}

