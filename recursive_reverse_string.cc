#include <string>
#include <iostream>

using namespace std;

void recurse(string& str, int fwdIdx, int revIdx) {
    if (fwdIdx >= revIdx) {
        return;
    }
    swap(str[fwdIdx], str[revIdx]);
    recurse(str, ++fwdIdx, --revIdx);
}

void reverse(string& str) {
    recurse(str, 0, str.length() - 1);
}

int main() {
    string strs[] = { "hello", "world" };
    for (auto s : strs) {
        reverse(s);
        cout << s << endl;
    }

    return 0;
}


