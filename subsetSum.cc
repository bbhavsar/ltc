#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

bool subset_dp(const vector<int>& vec, int target, vector<int>& result) {

    bool dp[vec.size() + 1][target + 1];
    int incl[vec.size() + 1][target + 1];

    for (int col = 1; col <= target; col++) {
        dp[0][col] = false;
    }
    for (int row = 1; row <= vec.size(); row++) {
        dp[row][0] = false;
    }

    dp[0][0] = true;
    for (int i = 1; i <= vec.size(); i++) {
        for (int s = 1; s <= target; s++) {
            if (s - vec[i-1] < 0) {
                dp[i][s] = dp[i-1][s];
            } else {
                bool yes = dp[i-1][s - vec[i-1]];
                if (yes) {
                    incl[i][s] = vec[i-1];
                } else {
                    incl[i][s] = -1;
                }
                dp[i][s] = dp[i-1][s] || dp[i-1][s - vec[i-1]];
            }
        }
    }

    if (!dp[vec.size()][target]) {
        return false;
    }

    int s = target;
    for (int i = vec.size(); i > 0; i--) {
        if (incl[i][s] != -1) {
            result.push_back(incl[i][s]);
            s -= incl[i][s];
        }
    }
    assert(s == 0);

    return true;
}


void getSetsRecurse(const vector<int>& vec, int target, int pos, int currSum,
                    vector<int>& runningVec, vector< vector<int> >& output) {
    if (pos == vec.size() || currSum >= target) {
        return;
    }

    if (currSum + vec[pos] < target) {
        // Include the pos elem
        runningVec.push_back(vec[pos]);
        output.push_back(runningVec);
        getSetsRecurse(vec, target, pos + 1, currSum + vec[pos], runningVec, output);
        runningVec.pop_back();
    }
    // excluding pos elem
    getSetsRecurse(vec, target, pos + 1, currSum, runningVec, output);
}

vector< vector<int > > getSets(const vector<int>& vec, int target) {
    vector< vector <int> > output;
    vector<int> runningVec;
    getSetsRecurse(vec, target, 0, 0, runningVec, output);
    return output;
}

int main() {
// Write a function that takes a list of integers and a target sum and returns groups of
// integers that SUM to less than the target.
//
// For example:
// let testInput: [Int] = [1,2,3,4]
// let testTarget: Int = 4
// print(getSets(input: testInput, target: testTarget))
//
// will produce output:
// [[1], [2], [3], [1,2]]
    vector<int> input  = {1, 2, 3, 4};
    auto out = getSets(input, 4);
    for (auto v : out) {
        for (auto elem : v) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> result;
    bool yes = subset_dp(input, 6, result);
    cout << yes << endl;
    for (int elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;

}

