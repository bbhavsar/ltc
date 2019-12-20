// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include "common.hh"
#include "bt.hh"

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector< vector<int> > result;
    if (root == NULL) {
        return result;
    }
    queue<TreeNode *> q;
    q.push(root);

    int rev = 0;
    while (!q.empty()) {
        int count = q.size();
        vector<int> level;
        while (count > 0) {
            auto u = q.front();
            q.pop();
            level.emplace_back(u->val);
            if (u->left != NULL) {
                q.push(u->left);
            }
            if (u->right != NULL) {
                q.push(u->right);
            }
            count--;
        }
        if (rev) {
            reverse(level.begin(), level.end());
        }
        rev = (rev + 1) % 2;
        result.emplace_back(level);
    }

    return result;
}

int main() {


    return 0;
}

