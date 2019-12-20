// https://leetcode.com/problems/remove-invalid-parentheses/solution/

#include "common.hh"

void recurse(const string& s, int idx, int left_count, int right_count, string expr,
             int left_to_remove, int right_to_remove,
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
        recurse(s, idx + 1, left_count, right_count, expr + s[idx], left_to_remove, right_to_remove,
                max, result);
        return;
    }
    // omit char
    if ((s[idx] == '(' && left_to_remove > 0) || (s[idx] == ')' && right_to_remove > 0)) {
        recurse(s, idx + 1, left_count, right_count, expr,
                left_to_remove - (s[idx] == '(' ? 1 : 0),
                right_to_remove - (s[idx] == ')' ? 1 : 0), max, result);
    }
    // include left
    if (s[idx] == '(') {
        recurse(s, idx + 1, left_count + 1, right_count, expr + '(', left_to_remove, right_to_remove,
                max, result);
    } else if (left_count > right_count) {
        recurse(s, idx + 1, left_count, right_count + 1, expr + ')', left_to_remove,
                right_to_remove, max, result);
    }
}

vector<string> removeInvalidParens(const string& s) {
    int left_to_remove = 0;
    int right_to_remove = 0;
    for (auto c : s) {
        if (c == '(') {
            left_to_remove++;
        } else if (c == ')') {
            if (left_to_remove > 0) {
                left_to_remove--;
            } else {
                right_to_remove++;
            }
        }
    }

    unordered_set<string> result;
    int max = 0;
    recurse(s, 0, 0, 0, "", left_to_remove, right_to_remove, max, result);
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

