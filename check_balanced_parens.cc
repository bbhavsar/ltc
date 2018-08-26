#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

bool isBalancedParens(const string& input) {
    const unordered_map<char, char> rev_lookup = { {')', '('}, {']', '['}, {'}', '{'} };
    stack<char> s;
    for (char c : input) {
        if (c == '{' || c == '[' || c == '(') {
            s.push(c);
        } else {
            if (s.empty()) {
                return false;
            }
            if (s.top() != rev_lookup.at(c)) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string strs[] = { "{}", "{([])}", "{}[]((" };
    for (string& s : strs) {
        cout << s << "\t" << isBalancedParens(s) << endl;
    }
    return 0;
}

