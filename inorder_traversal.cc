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
    TreeNode *root;
public:
    Iterator(TreeNode *r) : root(r) {}

    TreeNode *next() {
        TreeNode *result = NULL;

        if (!s.empty() || root != NULL) {
            while (root != NULL) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            result = root;
            root = root->right;
        }

        return result;
    }
};

void inorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> s;
    while (!s.empty() || root != NULL) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    TreeNode *root =  new TreeNode(50, new TreeNode(40, new TreeNode(30), new TreeNode(45)),
                                       new TreeNode(70, new TreeNode(60), new TreeNode(80)));

    inorder(root);

    Iterator it(root);
    TreeNode *next;
    while ((next = it.next()) != NULL ) {
        cout << next->val << " ";
    }

    return 0;
}

