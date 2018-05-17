#include <iostream>
using namespace std;

void removeDuplicates(int *arr, int n) {
    int readIdx;
    int writeIdx;

    for (writeIdx = 1, readIdx = 1; readIdx < n; readIdx++) {
        if (arr[readIdx] != arr[readIdx - 1]) {
            arr[writeIdx] = arr[readIdx];
            writeIdx++;
        }
    }
    for (; writeIdx < n; writeIdx++) {
        arr[writeIdx] = -1;
    }
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 4, 4};

    removeDuplicates(arr, sizeof(arr) / sizeof(int));
    for (int elem : arr) {
        cout << elem << endl;
    }

    return 0;
}


