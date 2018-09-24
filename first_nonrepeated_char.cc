#include <iostream>
#include <unordered_map>
#include <stdexcept>

using namespace std;

char firstNonRepeatedChar(const string& str) {
    unordered_map<char, int> m;
    for (char c : str) {
        m[c]++;
    }
    for (char c: str) {
        if (m[c] == 1) {
            return c;
        }
    }
    const string ex = "No non-repeated char found";
    throw exception();
}


int main() {
    string s[] = {"BlahBlahBlackSheep", "aabbcc"};

    for (auto str : s) {
        cout << firstNonRepeatedChar(str) << endl;
    }

    return 0;
}



