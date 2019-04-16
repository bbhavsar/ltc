#include "common.hh"

#include <stack>

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int v, TreeNode *l = NULL, TreeNode* r = NULL) : val(v), left(l), right(r) {}
};

class Iterator {
private:
    stack<TreeNode *> s;
public:
    Iterator(TreeNode *r)  {
        if (r == NULL) {
            return;
        }
        s.push(r);
    }
    TreeNode *next() {
        TreeNode *result = NULL;

        if (!s.empty()) {
            TreeNode *curr = s.top();
            s.pop();
            assert(curr != NULL);
            result = curr;
            if (curr->right != NULL) {
                s.push(curr->right);
            }
            if (curr->left != NULL) {
                s.push(curr->left);
            }
        }
        return result;
    }
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
        while (root != NULL) {
            cout << root->val << " ";
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
    Iterator it(root);
    TreeNode *next;
    while ((next = it.next()) != NULL ) {
        cout << next->val << " ";
    }

    return 0;
}

