#include <iostream>
#include <vector>

// g++ -std=c++11 rainwater.cc

using namespace std;
class Solution {
public:
    int trap(const vector<int>& height) {
        const int size = height.size();
        if (size == 0) {
            return 0;
        }

        int leftMax[size];
        int rightMax[size];

        leftMax[0] = height[0];
        for (int i = 1; i < size; i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        rightMax[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        int result = 0;
        for (int i = 0; i < size; i++) {
            result += min(leftMax[i], rightMax[i]) - height[i];
        }
        return result;
    }
};


int main() {
    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(input) << endl;

    return 0;
}


