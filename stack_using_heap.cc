#include "common.hh"
// Daily Coding Problem: Problem #154 


class Compare {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.first < rhs.first;
    }
};

class Stack {
public:
    Stack() : seq(0) {}

    void push(int item) {
        seq++;
        pq.push(make_pair(seq, item));
    }

    int pop() {
        if (pq.empty()) {
            throw runtime_error("Stack empty");
        }
        seq--;
        pair<int, int> elem = pq.top();
        pq.pop();
        return elem.second;
    }

private:
    priority_queue<pair<int, int>, vector<pair <int, int> >, Compare> pq;
    int seq;
};


int main() {
    int arr[] = {10, 2, 11, -1};
    Stack s;
    for (int elem : arr) {
        s.push(elem);
    }
    for (int i = 0; i < sizeof(arr) / sizeof arr[0]; i++) {
        cout << s.pop() << " ";
    }
    cout << endl;

    return 0;
}

