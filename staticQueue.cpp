#include <iostream>
#include <assert.h>

using namespace std;

template <typename T>
class Queue {
private:
    T* arr;
    size_t n;
    size_t capacity;
    int head, tail;
public:
    Queue(size_t capacity) {
        this->capacity = capacity;
        head = n = tail = 0;
        arr = new T[capacity];
    }

    ~Queue() {
        if (arr != NULL) {
            delete[] arr;
        }
        head = tail = capacity = n = 0;
    }

    bool enqueue(const T& t) {
        if (n == capacity) {
            return false;
        }

        arr[tail] = t;
        tail = (tail + 1) % capacity;
        n++;
        return true;
    }

    bool dequeue(T* t) {
        if (n == 0) {
            return false;
        }

        *t = arr[head];
        head = (head + 1) % capacity;
        n--;
        return true;
    }

    void printQueue() {
        int i = head;
        for (int count = 0; count < n; count++) {
            cout << arr[i] << endl;
            i = (i + 1) % capacity;
        }
    }
};

int main() {
    int arr[] = {1, 2};
    Queue<int> q(2);
    q.enqueue(1);
    q.enqueue(2);
    assert(!q.enqueue(3));
    q.printQueue();

    int elem;
    q.dequeue(&elem);
    cout << elem << endl;
    q.enqueue(3);
    q.printQueue();

    return 0;
}

