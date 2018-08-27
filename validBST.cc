#include <iostream>
#include <map>
#include <limits.h>
#include <limits>

using namespace std;
struct node {
    int val;
    node *left, *right;
};

map<node*, int> max_map;
int maxVal(node *root) {
    if (root == NULL) {
        return INT_MIN;
    }
    return max(root->val, max(maxVal(root->left), maxVal(root->right)));
}

int minVal(node *root) {
    if (root == NULL) {
        return INT_MAX;
    }
    return min(root->val, min(minVal(root->left), minVal(root->right)));
}

bool isValidBST(node *root) {
    if (root == NULL) {
        return true;
    }

    int lmax = maxVal(root->left);
    int rmin = minVal(root->right);

    return root->val >= lmax && root->val < rmin;
}

int main() {

    return 0;
}




