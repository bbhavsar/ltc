#include "common.hh"
#include "bt.hh"

bool unival(TreeNode *curr, int& num) {
    if (curr == NULL) {
        return true;
    }

    bool left = unival(curr->left, num);
    bool right = unival(curr->right, num);

    if (!left || !right) {
        return false;
    }

    if (curr->left && curr->left->val != curr->val) {
        return false;
    }

    if (curr->right && curr->right->val != curr->val) {
        return false;
    }

    num++;
    return true;
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
    unival(r, num);
    cout << num << endl;

    TreeNode *n = new TreeNode('a', new TreeNode('c'), new TreeNode('b', new TreeNode('b'), new TreeNode('b', NULL, new TreeNode('b'))));
    num = 0;
    unival(n, num);
    cout << num << endl;

    return 0;
}

