#include <iostream>
#include <unordered_set>

using namespace std;

void remove_duplicate(string& str) {
    string result;
    unordered_set<char> seen;
    for (char c : str) {
        if (seen.count(c) == 0) {
            result += c;
            seen.insert(c);
        }
    }
    str = result;
}


int main() {
    string strs[] = {"hello world", "how are you"};
    for (string& s : strs) {
        remove_duplicate(s);
        cout << s << endl;

    }
    return 0;
}

