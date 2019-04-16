
#include "common.hh"

struct node {
    int val;
    node *left, *right;
};

map<node*, int> max_map;
int maxVal(node *root) {
    if (root == NULL) {
        return INT_MIN;
    }
    return max(root->val, max(maxVal(root->left), maxVal(root->right)));
}

int minVal(node *root) {
    if (root == NULL) {
        return INT_MAX;
    }
    return min(root->val, min(minVal(root->left), minVal(root->right)));
}

bool isValidBST(node *root) {
    if (root == NULL) {
        return true;
    }

    int lmax = maxVal(root->left);
    int rmin = minVal(root->right);

    return root->val >= lmax && root->val < rmin;
}

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int v, TreeNode *l = NULL, TreeNode* r = NULL) : val(v), left(l), right(r) {}
};

struct Result {
    int min, max;
    bool valid;
    Result() : min(INT_MIN), max(INT_MAX), valid(false) {}
};

Result isValidBSTRecur(TreeNode *curr) {
    assert(curr != NULL);
    if (curr->left == NULL && curr->right == NULL) {
        Result r;
        r.min = r.max = curr->val;
        r.valid = true;
        return r;
    }
    if (curr->left == NULL) {
        assert(curr->right != NULL);
        Result r;
        if (curr->val >= curr->right->val) {
            r.valid = false;
            return r;
        }
        r.min = curr->val;
        r.max = curr->right->val;
        return r;
    }
    if (curr->right == NULL) {
        assert(curr->left != NULL);
        Result r;
        if (curr->val < curr->left->val) {
            r.valid = false;
            return r;
        }
        r.min = curr->left->val;
        r.max = curr->val;
        return r;
    }

    Result lr = isValidBSTRecur(curr->left);
    if (!lr.valid) {
        return lr;
    }

    Result rr = isValidBSTRecur(curr->right);
    if (!rr.valid) {
        return rr;
    }

    if (curr->val < lr.max || curr->val >= rr.min) {
        Result r;
        r.valid = false;
        return r;
    }

    Result r;
    r.valid = true;
    r.min = lr.min;
    r.max = rr.max;

    return r;
}

bool isValidBST(TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    Result r = isValidBSTRecur(root);
    /*
    if (r.valid) {
        cout << "[" << r.min << " " << r.max << "]" << endl;
    }
    */
    return r.valid;
}

bool isValidBSTMinMax(TreeNode *root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    if (root->val < min || root->val > max) {
        return false;
    }
    return isValidBSTMinMax(root->left, min, root->val) && isValidBSTMinMax(root->right,
        root->val, max);
}

bool isValidBSTFinal(TreeNode *root) {
    return isValidBSTMinMax(root, INT_MIN, INT_MAX);
}


int main() {
    TreeNode *root = new TreeNode(10, new TreeNode(9), new TreeNode(20, new TreeNode(15),
                                  new TreeNode(25)));

    cout << isValidBST(root) << endl;

    return 0;
}




