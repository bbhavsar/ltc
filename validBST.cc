#include <iostream>
#include <map>

using namespace std;

map<node*, int> max_map;
int maxVal(node *root) {
    if (root == NULL) {
        return INT_MIN;
    }
    return max(root->val, maxVal(root->left), maxVal(root->right));
}

int minVal(node *root) {
    if (root == NULL) {
        return INT_MAX;
    }
    return min(root->val, minVal(root->left), minVal(root->right));
}

bool isValidBST(node *root) {
    if (root == NULL) {
        return true;
    }

    int lmax = maxVal(root->left);
    int rmin = minVal(root->right);

    return root->val >= lmax && root->val < rmin;
}




