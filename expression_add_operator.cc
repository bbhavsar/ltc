#include "common.hh"

// https://leetcode.com/problems/expression-add-operators/

void recurse(const string& num, const int target, int idx, string curr_expr,
             int cumul_val, int prev_val, vector<string>& result) {
    if (idx == num.size()) {
        if (target == cumul_val) {
            result.emplace_back(curr_expr);
        }
        return;
    }

    for (int len = 1; len <= num.size() - idx; len++) {
        string new_num = num.substr(idx, len);
        if (len > 1 && new_num[0] == '0') {
            continue;
        }
        int new_num_val = stoi(new_num);
        if (idx == 0) {
            recurse(num, target, idx+len, new_num, new_num_val, new_num_val, result);
            continue;
        }
        recurse(num, target, idx+len, curr_expr + " + " + new_num, cumul_val + new_num_val,
                new_num_val, result);
        recurse(num, target, idx+len, curr_expr + " - " + new_num, cumul_val - new_num_val,
                -new_num_val, result);
        recurse(num, target, idx+len, curr_expr + " * " + new_num, cumul_val - prev_val + prev_val * new_num_val,
                 prev_val * new_num_val, result);
    }
}

vector<string> addOperators(const string& num, int target) {
    vector<string> result;
    recurse(num, target, 0, "", 0, 0, result);
    return result;
}

int main() {
    for (auto s : addOperators("520", 100)) {
        cout << s << endl;
    }

    return 0;
}

