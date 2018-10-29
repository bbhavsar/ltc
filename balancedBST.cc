#include "common.hh"


struct Node {
    int val;
    Node *left, *right;
};

Node *addElem(Node * root, int elem) {
    Node *n = new Node;
    n->val = elem;
    n->left = n->right = NULL;
    if (root == NULL) {
        return n;
    }

    Node *parent = NULL;
    Node *curr = root;
    while (curr != NULL) {
        parent = curr;
        if (elem <= curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    assert(parent != NULL);
    if (elem <= parent->val) {
        parent->left = n;
    } else {
        parent->right = n;
    }

    return root;
}

Node * constructBalancedBSTRecurse(const vector<int>& vec, Node *root, int l, int r) {
    if (l > r || l < 0 || r >= vec.size()) {
        return root;
    }
    if (l == r) {
        return addElem(root, vec[l]);
    }
    int m = (l + r) / 2;
    root = addElem(root, vec[m]);
    root = constructBalancedBSTRecurse(vec, root, l, m - 1);
    root = constructBalancedBSTRecurse(vec, root, m + 1, r);

    return root;
}

Node *constructBalancedBST(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    return constructBalancedBSTRecurse(vec, NULL, 0, vec.size() - 1);
}

int depth(Node *curr) {
    if (curr == NULL) {
        return 0;
    }

    return max(depth(curr->left) + 1, depth(curr->right) + 1);
}

void inorder(Node *curr, vector<int> *out) {
    if (curr == NULL) {
        return;
    }
    inorder(curr->left, out);
    out->push_back(curr->val);
    inorder(curr->right, out);
}

int main() {
    vector<int> vec;
    int max_elem = 64;
    for (int i = 1; i <= max_elem; i++) {
        vec.push_back(i);
    }

    Node *root = constructBalancedBST(vec);
    vector<int> out;
    inorder(root, &out);
    assert(out.size() == max_elem);
    cout << depth(root) << endl;


    return 0;
}


