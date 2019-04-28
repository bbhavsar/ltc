/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

*/

#include "common.hh"

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int v, TreeNode *l = NULL, TreeNode* r = NULL) : val(v), left(l), right(r) {}
};

void inorder(TreeNode *root, int& k, int& k_smallest) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, k, k_smallest);
    k--;
    if (k == 0) {
        k_smallest = root->val;
        return;
    }
    inorder(root->right, k, k_smallest);
}

int kthSmallest(TreeNode* root, int k) {
    int num;
    inorder(root, k, num);
    return num;
}

int main() {


    return 0;
}


