
#include "common.hh"

// indices are inclusive and common for nums and aux array
void merge(vector<int>& nums, vector<int>& aux, int ls, int m, int re) {
    assert(ls <= m);
    assert(m <= re);
    assert(ls < re);
    int le = m;
    int rs = m + 1;

    for (int i = ls; i <= le; i++) {
        aux[i] = nums[i];
    }
    for (int i = rs; i <= re; i++) {
        aux[i] = nums[i];
    }

    int l = ls;
    int r = rs;
    int writeIdx = ls;
    while (l <= le && r <= re) {
        if (aux[l] <= aux[r]) {
            nums[writeIdx++] = aux[l++];
        } else {
            nums[writeIdx++] = aux[r++];
        }
    }
    if (l > le) {
      while (r <= re) {
        nums[writeIdx++] = aux[r++];
      }
    } else if (r > re) {
      while (l <= le) {
        nums[writeIdx++] = aux[l++];
      }
    }
}

void mergeSort(vector<int>& nums, vector<int>& aux, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(nums, aux, l, m);
    mergeSort(nums, aux, m+1, r);
    merge(nums, aux, l, m, r);
  }
}

void mergeSort(vector<int>& nums) {
  vector<int> aux(nums.size());
  mergeSort(nums, aux, 0, nums.size()-1);
}

void printVector(const vector<int>& vec) {
  for (auto n : vec) {
    cout << n << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums = {1000, 100, -12, -5, 500, 2, 1000, 3, -3000};
  mergeSort(nums);
  printVector(nums);

  return 0;
}

