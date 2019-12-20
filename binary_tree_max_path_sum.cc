// https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include "common.hh"
#include "bt.hh"

int recur(TreeNode *curr, int& max_val) {
    if (curr == NULL) {
        return INT_MIN;
    }

    int leftSum = recur(curr->left, max_val);
    int rightSum = recur(curr->right, max_val);

    max_val = max(max_val, curr->val);
    if (leftSum == INT_MIN && rightSum == INT_MIN) {
        return curr->val;
    } else if (leftSum == INT_MIN) {
        max_val = max(max_val, rightSum + curr->val);
        max_val = max(max_val, rightSum);
        return rightSum + curr->val;
    } else if (rightSum == INT_MIN) {
        max_val = max(max_val, leftSum + curr->val);
        max_val = max(max_val, leftSum);
        return leftSum + curr->val;
    } else {
        max_val = max(max_val, leftSum + rightSum + curr->val);
        max_val = max(max_val, max(leftSum, rightSum));

        return max(leftSum, rightSum) + curr->val;
    }
}

int maxPathSum(TreeNode* root) {
    int max_val = INT_MIN;
    recur(root, max_val);
    return max_val;
}

int main() {
    TreeNode *root = new TreeNode(-10, new TreeNode(20), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    cout << maxPathSum(root) << endl;

    TreeNode *root1 = new TreeNode(2, new TreeNode(-1));
    cout << maxPathSum(root1) << endl;

    return 0;
}

