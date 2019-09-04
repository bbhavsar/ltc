#include "common.hh"

vector< pair<int, int> > intersection(const vector< pair<int, int> >& a,
                                      const vector< pair<int, int> >& b) {

  int i = 0;
  int j = 0;

  vector< pair<int, int> > result;
  while (i < a.size() && j < b.size()) {
    if (a[i].first < b[j].first && a[i].second < b[j].first) {
      i++;
    } else if (b[j].first < a[i].first && b[j].second < a[i].first) {
      j++;
    } else { // overlap cases
      auto p = make_pair(max(a[i].first, b[j].first), min(a[i].second, b[j].second));
      result.emplace_back(p);

      if (a[i].first <= b[j].first) {
        if (a[i].second < b[j].second) {
          i++;
        } else if (a[i].second > b[j].second) {
          j++;
        } else {
          i++, j++;
        }
      } else {
        if (b[j].second < a[i].second) {
          j++;
        } else if (b[j].second > a[i].second) {
          i++;
        } else {
          i++, j++;
        }
      }
    }
  }

  return result;
}

vector< pair<int, int> > union_interval(const vector< pair<int, int> >& a,
                                        const vector< pair<int, int> >& b) {
  if (a.empty()) {
    return b;
  }
  if (b.empty()) {
    return a;
  }

  vector< pair<int, int> > result;

  pair<int, int> curr;
  int i = 0;
  int j = 0;
  if (a[i].first < b[j].first) {
    curr = a[i++];
  } else {
    curr = b[j++];
  }

  while (i < a.size() && j < b.size()) {
    // no overlap case
    if (curr.second < a[i].first && curr.second < b[j].first) {
      result.emplace_back(curr);
      if (a[i].first < b[j].first) {
        curr = a[i++];
      } else {
        curr = b[j++];
      }
    } else {
      // overlap cases
      if (curr.second >= a[i].first) {
        curr.second = max(curr.second, a[i].second);
        i++;
      } else {
        curr.second = max(curr.second, b[j].second);
        j++;
      }
    }
  }

  if (i == a.size()) {
    while (j < b.size()) {
      if (curr.second < b[j].first) {
        result.emplace_back(curr);
        curr = b[j++];
      } else {
        curr.second = max(curr.second, b[j].second);
        j++;
      }
    }
  } else {
    assert(j == b.size());
    while (i < a.size()) {
      if (curr.second < a[i].first) {
        result.emplace_back(curr);
        curr = a[i++];
      } else {
        curr.second = max(curr.second, a[i].second);
        i++;
      }
    }
  }
  result.emplace_back(curr);

  return result;
}


int main() {
  vector< pair<int, int> > a ={
    {0, 2}, {5, 10}, {16, 20}
  };

  vector< pair<int, int> > b = {
    {1, 5}, {10, 18}, {20, 23}
  };

  auto r = intersection(a,b);
  for (auto p : r) {
    cout << "[" << p.first << ", " << p.second << "] ";
  }
  cout << endl;

  for (auto p : union_interval(a,b)) {
    cout << "[" << p.first << ", " << p.second << "] ";
  }
  cout << endl;

  return 0;

}

