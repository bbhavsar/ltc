#include "common.hh"

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int v, TreeNode *l = NULL, TreeNode *r = NULL) : val(v), left(l), right(r) {}
};

TreeNode * floor(TreeNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == key) {
        return root;
    }

    if (key < root->val) {
        return floor(root->left, key);
    }

    TreeNode *t = floor(root->right, key);
    return t != NULL ? t : root;
}

int lower_bound(TreeNode *root, int key) {
    TreeNode *t = floor(root, key);
    return t != NULL ? t->val : INT_MIN;
}


TreeNode *ceil(TreeNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key == root->val) {
        return root;
    }

    if (key > root->val) {
        return ceil(root->right, key);
    }

    TreeNode *t = ceil(root->left, key);
    return t != NULL ? t : root;
}

int upper_bound(TreeNode *root, int key) {
    TreeNode *t = ceil(root, key);
    return t != NULL ? t->val : INT_MAX;
}

void range(TreeNode *root, int low, int high, vector<int>& result) {
    if (root == NULL) {
        return;
    }

    if (root->val < low) {
        return range(root->right, low, high, result);
    }
    if (root->val > high) {
        return range(root->left, low, high, result);
    }

    result.push_back(root->val);
    range(root->left, low, high, result);
    range(root->right, low, high, result);
}

vector<int> range(TreeNode *root, int low, int high) {
    vector<int> result;
    range(root, low, high, result);
    return result;
}

int main() {
    TreeNode *root = new TreeNode(10, new TreeNode(5, new TreeNode(2), new TreeNode(8)), new TreeNode(15));

    cout << "6 " << lower_bound(root,6) << endl;
    cout << "16 " << lower_bound(root,16) << endl;
    cout << "1 " << lower_bound(root,1) << endl;

    cout << "6 " << upper_bound(root,6) << endl;
    cout << "16 " << upper_bound(root,16) << endl;
    cout << "1 " << upper_bound(root,1) << endl;

    for (int elem : range(root, 2, 11)) {
        cout << elem << " ";
    }

    cout << endl;

    return 0;
}

