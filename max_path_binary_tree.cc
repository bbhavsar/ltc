#include "common.hh"


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x, TreeNode *l = NULL, TreeNode *r = NULL) : val(x), left(l), right(r) {}
 };

int maxPath(TreeNode *curr) {
    if (curr == NULL) {
        return 0;
    }

    int lmax = maxPath(curr->left);
    int rmax = maxPath(curr->right);

    return max(lmax, rmax) + curr->val;
}

int main() {
    TreeNode *root = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15),
                                  new TreeNode(16)));

    cout << maxPath(root) << endl;

    return 0;
}

