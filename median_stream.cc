#include <iostream>
#include <queue>
#include <assert.h>
#include <stdlib.h>

using namespace std;

class Median {
private:
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, std::greater<int> > min_heap;
public:
  void add_elem(int elem) {
    if (max_heap.empty() && min_heap.empty()) {
      max_heap.push(elem);
      return;
    }
    if (elem < max_heap.top()) {
      max_heap.push(elem);
    } else {
      min_heap.push(elem);
    }

    if (abs((int)max_heap.size() - (int)min_heap.size()) > 1) {
      if (max_heap.size() > min_heap.size()) {
        int top = max_heap.top();
        max_heap.pop();
        min_heap.push(top);
      } else {
        int top = min_heap.top();
        min_heap.pop();
        max_heap.push(top);
      }
      assert(abs((int)max_heap.size() - (int)min_heap.size()) <= 1);
    }
  }

  float median_in_stream() {
    if (max_heap.empty() && min_heap.empty()) {
      return -1;
    }
    if (min_heap.empty()) {
      assert(max_heap.size() == 1);
      return max_heap.top();
    }
    if (max_heap.size() == min_heap.size()) {
      return static_cast<float>(max_heap.top() + min_heap.top()) / 2.0;
    } else if (max_heap.size() > min_heap.size()) {
      return max_heap.top();
    } else {
      return min_heap.top();
    }
  }
};

int main() {
  int arr[] = {10, 15, 5, 20, 25, 23, 16};
  Median m;
  for (int elem : arr) {
    m.add_elem(elem);
    cout << m.median_in_stream() << endl;
  }


  return 0;
}

