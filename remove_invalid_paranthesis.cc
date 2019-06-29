// https://leetcode.com/problems/remove-invalid-parentheses/solution/

#include "common.hh"

void recurse(const string& s, int idx, int left_count, int right_count, string expr,
             int& max, unordered_set<string>& result) {
    if (idx == s.length()) {
        if (left_count == right_count) {
            if (expr.length() > max) {
                max = expr.length();
                result.clear();
            }
            if (expr.length() == max) {
                result.insert(expr);
            }
        }
        return;
    }

    if (s[idx] != '(' && s[idx] != ')') {
        recurse(s, idx + 1, left_count, right_count, expr + s[idx], max, result);
        return;
    }
    // omit char
    recurse(s, idx + 1, left_count, right_count, expr, max, result);
    // include left
    if (s[idx] == '(') {
        recurse(s, idx + 1, left_count + 1, right_count, expr + '(', max, result);
    } else if (left_count > right_count) {
        recurse(s, idx + 1, left_count, right_count + 1, expr + ')', max, result);
    }
}

vector<string> removeInvalidParens(const string& s) {
    unordered_set<string> result;
    int max = 0;
    recurse(s, 0, 0, 0, "", max, result);
    return vector<string>(result.begin(), result.end());
}

void print(const string& s) {
    auto vec = removeInvalidParens(s);
    cout << "Printing result" << endl;

    cout << s << ": ";
    cout << "[ ";
    for (auto r : vec) {
        cout << r << ", ";
    }
    cout << " ]" << endl;
}

int main() {
    vector<string> strs  = { "()())()", "(a)())()", "()" };
    for (auto s : strs) {
        print(s);
    }
    return 0;
}

