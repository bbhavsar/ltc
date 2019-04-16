#include "common.hh"

#include <stack>

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int v, TreeNode *l = NULL, TreeNode* r = NULL) : val(v), left(l), right(r) {}
};


void preorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
        root = s.top();
        s.pop();
        cout << root->val << " ";
        while (root->left != NULL) {
            cout << root->left->val << " ";
            if (root->right != NULL) {
                s.push(root->right);
            }
            root = root->left;
        }
    }

    cout << endl;
}


int main() {
    TreeNode *root =  new TreeNode(50, new TreeNode(40, new TreeNode(30), new TreeNode(45)),
                                       new TreeNode(70, new TreeNode(60), new TreeNode(80)));

    preorder(root);

    return 0;
}

