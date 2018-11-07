/*
Given a list of integers, write a function that returns the largest sum of non-adjacent
numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5]
should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/


#include "common.hh"

int num_recur = 0;
int largest_recur(const vector<int>& in, int pos) {
    num_recur++;
    if (pos >= in.size()) {
        return 0;
    }

    return max(largest_recur(in, pos + 1), in[pos] + largest_recur(in, pos + 2));
}

int num_memo = 0;
int largest_memo(const vector<int>& in, int pos, vector<int>& cache) {
    num_memo++;
    if (pos >= in.size()) {
        return 0;
    }
    if (cache[pos] != -1) {
        return cache[pos];
    }

    cache[pos] = max(largest_memo(in, pos + 1, cache), in[pos] + largest_memo(in, pos + 2, cache));
    return cache[pos];
}

int largest_memo(const vector<int>& in) {
    vector<int> cache(in.size(), -1);

    return largest_memo(in, 0, cache);
}

int largest_dp(const vector<int>& in) {
    const int size = in.size();
    if (size == 0) {
        return 0;
    }
    vector<int> cache(size, -1);
    cache[0] = in[0];

    if (size > 1) {
        cache[1] = max(cache[0], in[1]);
    }

    for (int i = 2; i < size; i++) {
        cache[i] = max(in[i] + cache[i-2], cache[i-1]);
    }

    return cache.back();
}


int main() {
    vector< vector<int> >  in = {
        {2, 15, 20, -10, 100 , 80, 120, 30, 40},
        {-5, -10, 3, 10, 200, -100, 40, 60},
    };

    for (auto v : in) {
        cout << "Recursive: " << largest_recur(v, 0) << endl;
        cout << "Memoization: " << largest_memo(v) << endl;
        cout << "DP: " << largest_dp(v) << endl;
    }

    //cout << num_recur << " " << num_memo << endl;

    return 0;
}


