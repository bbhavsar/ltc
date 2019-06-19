
#include "common.hh"

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int v) : left(NULL), right(NULL), val(v) {}
    TreeNode(TreeNode *l, TreeNode *r, int v) : left(l), right(r), val(v) {}
};


TreeNode *build_bst(vector<int>& preorder, int preorder_idx,
                    int r) {
    if (preorder_idx >= preorder.size() || preorder_idx > r) {
        return NULL;
    }

    int node_val = preorder[preorder_idx];
    TreeNode *n = new TreeNode(node_val);
    int flip_idx = -1;
    for (int i = preorder_idx + 1; i <= r; i++) {
        if (preorder[i] > node_val) {
            flip_idx = i;
            break;
        }
    }
    if (flip_idx != -1) {
        n->left = build_bst(preorder, preorder_idx + 1, flip_idx-1);
        n->right = build_bst(preorder, flip_idx, r);
    } else {
        n->left = build_bst(preorder, preorder_idx + 1, r);
        n->right = NULL;
    }

    return n;
}


TreeNode *build_bst_from_preorder(vector<int>& preorder) {
    return build_bst(preorder, 0, preorder.size()-1);
}

int main() {

    return 0;
}

