/*
This problem was asked by MongoDB.

Given a list of elements, find the majority element, which appears more than half the time (> floor(len(lst) / 2.0)).

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0], return 1.


*/
#include "common.hh"

int majority_elem(const vector<int>& arr) {
    unordered_map<int, int> elem_count;

    for (auto elem : arr) {
        elem_count[elem]++;
    }

    int max_val = INT_MIN;
    int max_elem = -1;
    for (auto p : elem_count) {
        if (p.second > max_val) {
            max_val = p.second;
            max_elem = p.first;
        }
    }
    /*
    if (elem_count[max_elem] < arr.size() / 2) {
      throw invalid_argument("No majority element exists");
    }
    */
    return max_elem;
}

int majority_elem_opt(const vector<int>& arr) {
  assert(!arr.empty());
  int max_elem, max_idx;
  max_idx = 0;
  max_elem = arr[max_idx];
  int count = 1;
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] == max_elem) {
      count++;
    } else {
      count--;
      if (count == 0) {
        max_elem = arr[i];
        max_idx = i;
      }
    }
  }

  return max_elem;
}


int main() {
    vector<int> arr = {1, 2, 1, 1, 3, 4, 3, 2, 3, 2};
    cout << majority_elem(arr) << endl;
    cout << majority_elem_opt(arr) << endl;
    return 0;
}

