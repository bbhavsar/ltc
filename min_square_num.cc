/*
Daily Coding Problem: Problem #156 [Medium]
Given a positive integer n, find the smallest number of squared integers which sum to n.

For example, given n = 13, return 2 since 13 = 32 + 22 = 9 + 4.

Given n = 27, return 3 since 27 = 32 + 32 + 32 = 9 + 9 + 9.

*/

#include "common.hh"

int min_square_num(int num) {
  assert(num >= 0);
  if (num <= 3) {
    return num;
  }

  // max number is 1^2 + 1^2 + ...
  int min_res = num;
  for (int i = 1; i < num; i++) {
    int part = i*i;
    if (part > num) {
      break;
    }
    min_res = min(min_res, 1 + min_square_num(num - part));
  }

  return min_res;
}

int min_square_num_dp(int num, vector<int>* out) {
    assert(num >= 0);
    vector<int> dp(num + 1);
    vector<int> picked(num + 1, 1);
    for (int i = 0; i <= num; i++) {
        dp[i] = i;
    }
    for (int i = 4; i <= num; i++) {
        for (int j = 1; j < i; j++) {
            int part = j * j;
            if (i - part >= 0) {
                if (1 + dp[i-part] < dp[i]) {
                    dp[i] = 1 + dp[i-part];
                    picked[i] = j;
                }
            }
        }
    }
    int num_picked = picked[num];
    int remain = num;
    while (remain > 0) {
        out->push_back(num_picked);
        remain -= num_picked * num_picked;
        num_picked = picked[remain];
    }
    return dp[num];
}

int main() {
    int nums[] = {3, 13, 27, 49, 64, 121, 131};
    for (auto num : nums) {
        vector<int> picked;
        // cout << min_square_num(num) << endl;
        cout << num << " min: " << min_square_num_dp(num, &picked) << endl;
        for (auto n : picked) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}




