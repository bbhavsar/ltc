
#include "common.hh"

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int v, TreeNode *l = NULL, TreeNode* r = NULL) : val(v), left(l), right(r) {}
};


vector< vector<int> > levelOrder(TreeNode* root) {
    vector< vector<int> > result;
    if (root == NULL) {
        return result;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int count = q.size();

        vector<int> curr_level;
        while (count-- != 0) {
            TreeNode *u = q.front();
            q.pop();

            curr_level.push_back(u->val);
            if (u->left != NULL) {
                q.push(u->left);
            }
            if (u->right != NULL) {
                q.push(u->right);
            }
        }
        result.emplace_back(curr_level);
    }

    return result;
}

int main() {


    return 0;
}

