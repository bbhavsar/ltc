/*
https://leetcode.com/problems/invert-binary-tree/
*/

#include "common.hh"


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x, TreeNode *l = NULL, TreeNode *r = NULL) : val(x), left(l), right(r) {}
 };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        auto left = root->left;
        root->left = root->right;
        root->right = left;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void preorder(TreeNode *r) {
    if (r == NULL) {
        return;
    }
    cout << r->val << " " ;
    preorder(r->left);
    preorder(r->right);
}

int main() {
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                                    new TreeNode(7, new TreeNode(6), new TreeNode(9)));

    preorder(root);
    cout << endl;
    Solution s;
    preorder(s.invertTree(root));
    cout << endl;

    return 0;
}


