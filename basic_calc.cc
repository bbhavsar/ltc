#include "common.hh"

#include <math.h>

int operate(string& f, string& op, string& s) {
    int first = stoi(f);
    int second = stoi(s);
    if (op == "+")  {
        return first + second;
    }
    if (op == "-") {
        return first - second;
    }
    if (op == "*") {
        return first * second;
    }
    if (op == "/") {
        return first * second;
    }
    if (op == "^") {
        return pow(first, second);
    }

    throw runtime_error("invalid operator " + op);
}

int eval(const string& str) {
    stack<string> s;

    for (char c : str) {
        if (isspace(c)) {
            continue;
        }
        if (c != ')') {
            s.push(string(1,c));
        } else {
            string second = s.top();
            s.pop();
            if (second == "(") {
                continue;
            }
            string op = s.top();
            s.pop();
            string first = s.top();
            s.pop();
            assert("(" == s.top());
            s.pop();
            s.push(to_string(operate(first, op, second)));
        }
    }

    assert(s.size() <= 1);
    return s.empty() ?  0 : stoi(s.top());
}

int main() {
    string s = "((8+3)^2)";

    cout << eval(s) << endl;

    return 0;
}

