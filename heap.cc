#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> vec;

    int left(int idx) {
        return 2 * idx;
    }

    int right(int idx) {
        return 2 * idx + 1;
    }

    int parent(int idx) {
        return idx / 2;
    }

public:
    bool top(int *result) {
        if (vec.empty()) {
            return false;
        }

        *result = vec[0];
        return true;
    }

    void insert(int elem) {
        vec.push_back(elem);
        int idx = vec.size()-1;
        while (idx > 0) {
            int p = parent(idx);
            if (vec[idx] > vec[p]) {
                swap(vec[idx], vec[p]);
                idx = p;
            } else {
                break;
            }
        }
    }


    bool remove(int *result) {
        if (vec.empty()) {
            return false;
        }

        *result = vec[0];
        vec[0] = vec[vec.size() - 1];
        vec.resize(vec.size() - 1);
        max_heapify(0);
        return true;
    }
private:
    void max_heapify(int idx) {
        do {
            int l = left(idx);
            int r = right(idx);
            int largest = idx;
            if (l < vec.size() && vec[l] > vec[largest]) {
                largest = l;
            }
            if (r < vec.size() && vec[r] > vec[largest]) {
                largest = r;
            }
            if (largest == idx) {
                break;
            } else {
                swap(vec[idx], vec[largest]);
                idx = largest;
            }
        } while (true);
    }
};

int main() {
    int arr[] = {15, 10, -5, 25, 8};
    Heap h;
    for (int elem : arr) {
        h.insert(elem);
    }
    int elem;
    h.top(&elem);
    cout << elem << endl;
    h.remove(&elem);
    cout << elem << endl;
    h.top(&elem);
    cout << elem << endl;

    return 0;
}


