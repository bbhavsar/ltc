#include "common.hh"


/*
 * Given an array A[ ] denoting heights of N towers and a positive integer K, modify the heights of each tower
 * either by increasing or decreasing them by K only once and then find out the minimum difference
 * of the heights of shortest and longest towers.
 * Input : A[] = {1, 15, 10}, k = 6 Output : 5 Explanation : We change 1 to 6, 15 to 9 and 10 to 4.
 *Maximum difference is 5 (between 4 and 9). We can't get a lower difference.
 * you have time till 4.50
 * good luck
 * more examples
 * Input : arr[] = {1, 5, 15, 10} k = 3 Output : Maximum difference is 8 arr[] = {4, 8, 12, 7}
 *Input : arr[] = {4, 6} k = 10 Output : Maximum difference is 2
 *
 */

void min_tower_diff(const vector<int>& in, int idx, int k, vector<int>& curr, int& min_diff) {

    if (idx == in.size()) {
        auto minmax = minmax_element(curr.begin(), curr.end());
        int min_elem = *minmax.first;
        int max_elem = *minmax.second;
        min_diff = min(max_elem - min_elem, min_diff);
        cout << "min: " << min_elem << " max: " << max_elem << endl;
        return;
    }


    int a = in[idx] + k;
    if (a >= 0) {
        curr.push_back(a);
        min_tower_diff(in, idx + 1, k, curr, min_diff);
        curr.pop_back();
    }

    int b = in[idx] - k;
    if (b >= 0) {
        curr.push_back(b);
        min_tower_diff(in, idx + 1, k, curr, min_diff);
        curr.pop_back();
    }

}

int min_tower(const vector<int>& in, int k) {
    vector<int> curr;
    int min_diff = INT_MAX;

    min_tower_diff(in, 0, k, curr, min_diff);
    return min_diff;
}

int main() {
    vector<int> in = {1, 15, 10};
    cout << min_tower(in, 6) << endl;

    vector<int> arr = {1, 5, 15, 10};
    cout << min_tower(arr, 3) << endl;

    return 0;
}

