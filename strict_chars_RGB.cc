
/*
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the
array so that all the Rs come first, the Gs come second, and the Bs come last.
You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become
 ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

*/

#include "common.hh"

string& strict_chars_rgb(string& s) {
    int writeIdx = 0;
    for (int readIdx = 0; readIdx < s.length(); readIdx++) {
        if (s[readIdx] == 'R') {
            swap(s[readIdx], s[writeIdx]);
            writeIdx++;
        }
    }

    for (int readIdx = writeIdx; readIdx < s.length(); readIdx++) {
        if (s[readIdx] == 'G') {
            swap(s[readIdx], s[writeIdx]);
            writeIdx++;
        }
    }

    return s;
}


int main() {
    vector<string> strs = { "GBRRBRG", "BBRGGRBR", "BGRRGBRRBBGG"};
    for (auto s : strs) {
        cout << strict_chars_rgb(s) << endl;
    }
    return 0;
}

