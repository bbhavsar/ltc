/*
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/


#include "common.hh"

int num_ways(int steps) {
    if (steps == 0) {
        return 1;
    }

    int num = num_ways(steps - 1);
    if (steps >= 2) {
        num += num_ways(steps - 2);
    }
    return num;
}

int num_ways_memo(int steps, vector<int>& cache) {
    if (steps == 0) {
        return 1;
    }
    if (cache[steps] != -1) {
        return cache[steps];
    }
    int num = num_ways_memo(steps - 1, cache);
    if (steps >= 2) {
        num += num_ways_memo(steps - 2, cache);
    }
    cache[steps] = num;
    return num;
}

int num_ways_memo(int steps) {
    vector<int> cache(steps + 1, -1);
    return num_ways_memo(steps, cache);
}

int num_ways_dp(int steps) {
    vector<int> dp(steps + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= steps; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[steps];
 }

int main() {

    cout << num_ways(4) << endl;
    cout << num_ways_memo(4) << endl;
    cout << num_ways_dp(4) << endl;

    return 0;
}

