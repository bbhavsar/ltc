#include "common.hh"

// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

int findLength(vector<int>& A, vector<int>& B) {
    unordered_map<int, vector<int> > bidx;
    for (int i = 0; i < B.size(); i++) {
        bidx[B[i]].push_back(i);
    }

    int max_len = 0;
    for (int i = 0; i < A.size(); i++) {
        auto it = bidx.find(A[i]);
        if (it == bidx.end()) {
            continue;
        }
        for (auto n : it->second) {
            int m = i;
            int count = 0;
            while (m < A.size() && n < B.size() && A[m] == B[n]) {
                m++,n++;
                count++;
            }
            max_len = max(max_len, count);
        }
    }

    return max_len;
}

int findLengthDP(vector<int>& A, vector<int>& B) {
    vector< vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1, 0));

    int max_len = 0;
    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= B.size(); j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                max_len = max(max_len, dp[i][j]);
            }
        }
    }
    return max_len;
}


int main() {


    return 0;
}


