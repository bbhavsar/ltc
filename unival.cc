#include "common.hh"
#include "bt.hh"

bool unival(TreeNode *curr, int parent_val, int& num) {
    if (curr == NULL) {
        return true;
    }

    bool left = unival(curr->left, curr->val, num);
    bool right = unival(curr->right, curr->val, num);

    if (left && right) {
        num++;
    }
    if (parent_val == curr->val && left && right) {
        return true;
    } else {
        return false;
    }
}


int main() {
    vector<int> v = {50, 25, 75, 20, 30, 100, 125};

    Node *root = addElem(NULL, 60);
    for (int elem : v) {
        addElem(root, elem);
    }

    vector<int> out;
    inorder(root, &out);
    for (int elem : out) {
        cout << elem << " ";
    }
    cout << endl << endl;

    auto level = levelOrder(root);
    for (auto v : level) {
        for (auto elem : v) {
            cout << elem << " ";
        }
        cout << endl;
    }

    TreeNode *r = new TreeNode(0, new TreeNode(1), new TreeNode(0, new TreeNode(1, new TreeNode(1), new TreeNode(1)), new TreeNode(0)));

    int num = 0;
    unival(r, r->val, num);
    cout << num << endl;

    TreeNode *n = new TreeNode('a', new TreeNode('c'), new TreeNode('b', new TreeNode('b'), new TreeNode('b', NULL, new TreeNode('b'))));
    num = 0;
    unival(n, n->val, num);
    cout << num << endl;

    return 0;
}

