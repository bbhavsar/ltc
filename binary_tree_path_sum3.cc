#include "common.hh"
#include "bt.hh"

// https://leetcode.com/problems/path-sum-iii/

void recur(TreeNode *curr, int remain, int& paths) {
    if (curr == NULL) {
        return;
    }

    if (curr->val == remain) {
        paths++;
        return;
    }

    recur(curr->left, remain - curr->val, paths);
    recur(curr->right, remain - curr->val, paths);
}

void preorder(TreeNode *curr, int target, int& paths) {
    if (curr == NULL) {
        return;
    }

    recur(curr, target, paths);
    preorder(curr->left, target, paths);
    preorder(curr->right, target, paths);
}


int pathSum(TreeNode *root, int target) {
    int paths = 0;
    preorder(root, target, paths);
    return paths;
}

int main() {


    return 0;
}

