#include <iostream>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            swap(arr[j], arr[i]);
            i++;
        }
    }

    swap(arr[high], arr[i]);
    return i;
}


int main() {
    return 0;
}

