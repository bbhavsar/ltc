#include <iostream>
#include <string>
#include <vector>

using namespace std;


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
    return 0;
}

