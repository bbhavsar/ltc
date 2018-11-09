/*
You run an e-commerce website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or
equal to N.
You should be as efficient with time and space as possible.
*/



#include "common.hh"

class LastN {
private:
    vector<int> orders;
    int N;
    int numElements;
    int tail;

public:
    LastN(int n) : tail(0), numElements(0), N(n) {
        orders.resize(N);
    }

    int get_last(unsigned int i) {
        assert(i < N);
        if (i > numElements) {
            return -1;
        }

        int idx = tail - i - 1;
        if (idx < 0) {
            idx += N;
        }
        return orders[idx];
    }

    void record(int order) {
        orders[tail] = order;
        tail = (tail + 1) % N;
        numElements = min(numElements + 1, N);
    }
};

int main() {
    LastN l(2);

    l.record(10);
    l.record(20);
    l.record(40);

    cout << l.get_last(0) << endl;
    cout << l.get_last(1) << endl;

    return 0;

}



