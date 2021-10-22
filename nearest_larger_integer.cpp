//
// Created by bankim on 3/3/20.
//

/*
 *
 * Given an array of numbers and an index i, return the index of the nearest larger number
 * of the number at index i, where distance is measured in array indices.
 * For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.
 * If two distances to larger numbers are the equal, then return any one of them.
 * If the array at i doesn't have a nearest larger integer, then return null.
 * Follow-up: If you can preprocess the array, can you do this in constant time?
 *
 */

#include "common.hh"

int nearby_int(const vector<int>& vals, int idx) {
  for (int dist = 1;; dist++) {
    int l = idx - dist;
    int r = idx + dist;
    if (l < 0 && r >= vals.size()) {
      return -1;
    }
    if (l >= 0 && vals[l] > vals[idx]) {
      return l;
    } else if (r < vals.size() && vals[r] > vals[idx]) {
      return r;
    }
  }
}

class NearestLargerInt {
 public:
  NearestLargerInt(const vector<int>& vals) : vals_(vals) {
    for (int i = 0; i < vals.size(); i++) {
      m_[vals[i]] = i;
    }
  }
  int get_nearest_int(int idx) {
    if (idx < 0 || idx > vals_.size()) {
      return -1;
    }
    // NOT implemented
    return -1;
  }
 private:
  const vector<int> vals_;
  map<int, int> m_;
};

int main() {
  vector<int> vals = {4, 1, 3, 5, 6};
  cout << nearby_int(vals, 0) << endl;
  cout << nearby_int(vals, 1) << endl;
  cout << nearby_int(vals, 2) << endl;
  cout << nearby_int(vals, 3) << endl;
  cout << nearby_int(vals, 4) << endl;

  return 0;
}