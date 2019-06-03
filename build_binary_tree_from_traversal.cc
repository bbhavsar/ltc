#include "common.hh"

/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *constructTree(vector<int>& preorder, int& pidx,
                        vector<int>& inorder, int l, int idx, int r) {
    if (pidx == preorder.size() || l > r) {
        return NULL;
    }

    assert(preorder[pidx] == inorder[idx]);
    TreeNode *curr = new TreeNode(preorder[pidx++]);
    if (l == r || pidx == preorder.size()) {
        return curr;
    }

    int next_val = preorder[pidx];
    int left_idx = -1;
    for (int i = l; i < idx; i++) {
        if (next_val == inorder[i]) {
            left_idx = i;
            break;
        }
    }
    if (left_idx != -1) {
        curr->left = constructTree(preorder, pidx, inorder, l, left_idx, idx-1);
    }
    if (pidx == preorder.size()) {
        return curr;
    }
    next_val = preorder[pidx];
    int right_idx = -1;
    for (int i = idx + 1; i <= r; i++) {
        if (next_val == inorder[i]) {
            right_idx = i;
            break;
        }
    }
    if (right_idx != -1) {
        curr->right = constructTree(preorder, pidx, inorder, idx+1, right_idx, r);
    }

    return curr;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) {
        return NULL;
    }
    int root_val = preorder[0];
    int root_idx = -1;
    for (int i = 0; i < inorder.size(); i++) {
        if (root_val == inorder[i]) {
            root_idx = i;
            break;
        }
    }
    assert(root_idx != -1);
    int pidx = 0;
    return constructTree(preorder, pidx, inorder, 0, root_idx, inorder.size()-1);
}



int main() {

    return 0;
}

