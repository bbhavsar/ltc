#include <iostream>
#include <map>

using namespace std;

bool isValidShuffle(const string& s1, const string& s2, const string& s3) {

    if (s3.length() != (s1.length() + s2.length())) {
        return false;
    }

    int i1, i2, i3;
    const int s1_length = s1.length();
    const int s2_length = s2.length();
    const int s3_length = s3.length();

    for (i1 = i2 = i3 = 0; i3 < s3_length; i3++) {
        if (i1 < s1_length && s1[i1] == s3[i3]) {
            i1++;
        } else if (i2 < s2_length && s2[i2] == s3[i3]) {
            i2++;
        } else {
            return false;
        }
    }

    return true;
}

struct TripleString {
    string _s1, _s2, _s3;
    TripleString(const string& s1, const string& s2, const string& s3) :
         _s1(s1), _s2(s2), _s3(s3) {}

    bool operator< (const TripleString& that) const {
        if (_s1 < that._s1 )  return true;
        if (_s1 > that._s1 )  return false;

        if (_s2 < that._s2 )  return true;
        if (_s2 > that._s2 )  return false;

        if (_s3 < that._s3 )  return true;
        if (_s3 > that._s3 )  return false;

        // Otherwise both are equal
        return false;
    }
};

bool isValidShuffleDP(const string& s1, const string& s2, const string& s3) {
    const int s1_len = s1.length();
    const int s2_len = s2.length();
    bool DP[s2_len + 1][s1_len + 1];

    for (int i = 0; i < s2_len + 1; i++) {
        for (int j = 0; j < s1_len + 1; j++) {
            if (i == 0 && j == 0) {
                DP[i][j] = true;
            } else if (i == 0) {
                DP[i][j] = (s3[j - 1] == s1[j - 1]);
            } else if (j == 0) {
                DP[i][j] = (s3[i - 1] == s2[i - 1]);
            } else if (s3[i + j - 1] == s2[i - 1] && s3[i + j - 1] == s1[j - 1]) {
                DP[i][j] = DP[i-1][j] || DP[i][j-1];
            } else if (s3[i + j - 1] == s2[i-1]) {
                DP[i][j] = DP[i-1][j];
            } else if (s3[i + j - 1] == s1[j-1]) {
                DP[i][j] = DP[i][j-1];
            } else {
                DP[i][j] = false;
            }
        }
    }

    return DP[s2_len][s1_len];

}

map<TripleString, bool> cache;
bool isValidShuffleRecurse(const string& s1, const string& s2, const string& s3) {
    const int s1_length = s1.length();
    const int s2_length = s2.length();
    const int s3_length = s3.length();

    if (s3_length != (s1_length + s2_length)) {
        return false;
    }

    TripleString ts(s1, s2, s3);
    auto it = cache.find(ts);
    if (it != cache.end()) {
        return it->second;
    }

    if (s1_length == 0) {
        bool isValid = s2 == s3;
        cache.insert(make_pair(ts, isValid));
        return isValid;
    }

    if (s2_length == 0) {
        bool isValid = s1 == s3;
        cache.insert(make_pair(ts, isValid));
        return isValid;
    }

    bool isValid = false;
    if (s1[0] == s3[0]) {
        isValid = isValidShuffleRecurse(s1.substr(1), s2, s3.substr(1));
    }

    if (!isValid && s2[0] == s3[0]) {
        isValid = isValidShuffleRecurse(s1, s2.substr(1), s3.substr(1));
    }
    cache.insert(make_pair(ts, isValid));
    return isValid;
}


int main() {
    string s1 = "abc";
    string s2 = "ade";
    string s3[] = { "adeabc", "aabcde", "aaebcd"};

    for (const string& s : s3) {
        cout << s << ":" << isValidShuffleRecurse(s1, s2, s) << endl;
    }

    for (const string& s : s3) {
        cout << s << ":" << isValidShuffleDP(s1, s2, s) << endl;
    }

    return 0;
}


