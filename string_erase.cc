#include "common.hh"


int main() {
    string s = "hello world!";
    cout << s << endl;

    s.erase(s.cbegin());
    s.erase(--s.cend());

    cout << s << endl;
    return 0;
}

