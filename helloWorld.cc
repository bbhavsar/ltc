#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> & v) {
    for (auto elem : v) {
        cout << elem << ",";
    }
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 3};
    printVector(v);
    cout << "hello world" << endl;
    return 0;

}

