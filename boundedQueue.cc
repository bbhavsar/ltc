#include "common.hh"
#include "condition_variable"
#include "mutex"

class BoundedQueue {
private:
    int size;
    vector<void *> arr;
    condition_variable cv_full;
    condition_variable cv_empty;
    mutex m;
    int head;
    int n;

public:
    BoundedQueue(int s) : size(s), arr(vector<void *>(size, NULL)),  head(0), n(0) {}

    void insert(void *data) {
        unique_lock<mutex> l(m);

        // buffer full
        while (n == size) {
            cv_full.wait(l);
        }
        assert(n < size);
        int insert_idx = (head + n) % size;
        arr[insert_idx] = data;
        n++;
        l.unlock();

        cv_empty.notify_one();
    }

    void* pop() {
        unique_lock<mutex> l(m);

        // buffer empty
        while (n == 0) {
            cv_empty.wait(l);
        }

        assert(n > 0);
        void *data = arr[head];
        head = (head + 1) % size;
        n--;
        l.unlock();

        cv_full.notify_one();
        return data;
    }
};

int main() {
    BoundedQueue bq(2);

    bq.insert((void *)1);
    cout << (long)bq.pop() << endl;
    bq.insert((void *)2);
    cout << (long)bq.pop() << endl;
    bq.insert((void *)10);
    cout << (long)bq.pop() << endl;

    return 0;
}

