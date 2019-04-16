/*
 *
 
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

 */
#include "common.hh"

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];

  }

  int climbStairsRecur(int n) {
    if (n == 0) {
      return 1;
    }

    if (n > 1) {
      return climbStairsRecur(n - 1) + climbStairsRecur(n - 2);
    } else {
      return climbStairsRecur(n - 1);
    }
  }
};

int main() {
  Solution s;
  int arr[] = {2, 3, 5};

  for (auto num : arr) {
    cout << "num: " << num << " uniq: " << s.climbStairsRecur(num) << endl;
    cout << "num: " << num << " uniq: " << s.climbStairs(num) << endl;
  }

  return 0;
}



