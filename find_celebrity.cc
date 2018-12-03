#include "common.hh"
/*
https://leetcode.com/problems/find-the-celebrity/
    int findCelebrity(int n) {
    }

Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may
exist one celebrity. 

The definition of a celebrity is that all the other n - 1 people know him/her but he/she does
not know any of them.

Now you want to find out who the celebrity is or verify that there is not one.
The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get
information of whether A knows B.

You need to find out the celebrity (or verify there is not one) by asking as few questions
as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B.i
Implement a function int findCelebrity(n), your function should minimize the number of
 calls to knows.

*/

bool knows(int a, int b) {
    return false;
}

inline bool kcache(int a, int b, vector< vector<int> >& cache) {
    if (cache[a][b] == -1) {
        cache[a][b] = knows(a, b);
    }
    return cache[a][b];
}

int findCelebrity(int n) {
    vector< vector<int> > cache(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (kcache(i, j, cache)) {
                // i can't be celebrity
                break;
            }
            if (!kcache(j, i, cache)) {
                // i can't be celebrity
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }

    return -1;
}

int main() {

    return 0;
}

