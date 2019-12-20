#include "common.hh"

// https://leetcode.com/problems/diameter-of-binary-tree/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int recur(TreeNode * curr, int& max_val) {
    if (curr == NULL) {
        return 0;
    }

    int leftLen = recur(curr->left, max_val);
    int rightLen = recur(curr->right, max_val);

    int lenInclCurr = leftLen + rightLen + 1;
    max_val = max(max_val, lenInclCurr);
    return max(leftLen, rightLen) + 1;
}


int diameterOfBinaryTree(TreeNode* root) {
    int max_val = 0;
    recur(root, max_val);
    return max_val;
}


int main() {
    return 0;
}

