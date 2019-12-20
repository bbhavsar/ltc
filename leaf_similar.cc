
#include "common.hh"
#include "bt.hh"

void preorder(TreeNode *curr, vector<int>& leaves) {
    if (curr == NULL) {
        return;
    }
    if (curr->left == NULL && curr->right == NULL) {
        leaves.push_back(curr->val);
        return;
    }

    preorder(curr->left, leaves);
    preorder(curr->right, leaves);
}

bool same(TreeNode *curr, const vector<int>& leaves, int& idx) {
    if (curr == NULL) {
        return true;
    }

    if (curr->left == NULL && curr->right == NULL) {
        if (idx == leaves.size() || leaves[idx] != curr->val) {
            return false;
        }
        idx++;
        return true;
    }
    return same(curr->left, leaves, idx) && same(curr->right, leaves, idx);
}


bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves;
    preorder(root1, leaves);
    int idx = 0;
    return same(root2, leaves, idx);
}

int main() {


    return 0;
}

