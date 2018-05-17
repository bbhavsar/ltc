#include <iostream>

using namespace std;

int numBits(int num) {
    int count = 0;
    while (num != 0) {
        num &= (num - 1);
        count++;
    }
    return count;
}

int main() {
    for (int i = 0; i <=16; i++) {
        cout << "num: " << i << " bits: " << numBits(i) << endl;
    }
    return 0;
}

