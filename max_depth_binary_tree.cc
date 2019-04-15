
/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

#include "common.hh"

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int v, TreeNode *l = NULL, TreeNode* r = NULL) : val(v), left(l), right(r) {}
};


int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


int main() {

}




