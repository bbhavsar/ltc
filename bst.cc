#include <iostream>
#include <map>
#include <list>
#include <assert.h>

using namespace std;

class Node {
public:
    Node *left, *right;
    int val;
    int level;
    Node(int v) : val(v), left(NULL), right(NULL), level(-1) {
    }
};

class BST {
public:
    Node *root;
    size_t size;

public:
    BST() : root(NULL), size(0) {
    }

    void add(int elem) {
        Node *n = new Node(elem);
        if  (root == NULL) {
            root = n;
            size++;
            return;
        }

        Node *curr = root;
        Node *parent = NULL;
        while (curr != NULL) {
            if (elem <= curr->val) {
                parent = curr;
                curr = curr->left;
            } else {
                parent = curr;
                curr = curr->right;
            }
        }

        if (elem <= parent->val) {
            parent->left = n;
        } else {
            parent->right = n;
        }
        size++;
    }

    void inorder() {
        inorder(root);
    }

    void levelOrder() {
        if (root == NULL) {
            return;
        }
        list<Node *> q;
        int level = 0;
        root->level = level;
        q.push_back(root);
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop_front();
            if (curr->level != level) {
                assert(curr->level == level + 1);
                cout << endl;
                level++;
            }
            cout << curr->val << ", ";
            if (curr->left != NULL) {
                curr->left->level = curr->level + 1;
                q.push_back(curr->left);
            }
            if (curr->right != NULL) {
                curr->right->level = curr->level + 1;
                q.push_back(curr->right);
            }
        }
        cout << endl;
    }

private:
    void inorder(Node *curr) {
        if (curr == NULL) {
            return;
        }
        inorder(curr->left);
        cout << curr->val << " ";
        inorder(curr->right);
    }
};

map<Node *, int> maxMap;
int maxVal(Node *root) {
    if (root == NULL) {
        return INT_MIN;
    }
    auto it = maxMap.find(root);
    if (it != maxMap.end()) {
        return it->second;
    }

    int lmax = maxVal(root->left);
    int rmax = maxVal(root->right);

    int nodeMax = max(max(root->val, lmax), rmax);
    maxMap.insert(make_pair(root, nodeMax));
    return nodeMax;
}

map<Node *, int> minMap;
int minVal(Node *root) {
    if (root == NULL) {
        return INT_MAX;
    }
    auto it = minMap.find(root);
    if (it != minMap.end()) {
        return it->second;
    }

    int lmin = minVal(root->left);
    int rmin = minVal(root->right);

    int nodeMin = min(min(root->val, lmin), rmin);
    minMap.insert(make_pair(root, nodeMin));
    return nodeMin;
}

bool isValidBST(Node *root) {
    if (root == NULL) {
        return true;
    }

    int lmax = maxVal(root->left);
    int rmin = minVal(root->right);

    return (root->val >= lmax && root->val < rmin) &&
           isValidBST(root->left) && isValidBST(root->right);
}

bool isValidBSTRange(Node *root, int min=INT_MIN, int max=INT_MAX) {
    if (root == NULL) {
        return true;
    }

    if (root->val < min || root->val > max) {
        return false;
    }

    return isValidBSTRange(root->left, min, root->val) &&
           isValidBSTRange(root->right, root->val, max);

}

int main() {
    int arr[] = {10, 9, 15, 20, 25, -2};
    BST b;
    for (auto elem : arr) {
        b.add(elem);
    }

    b.inorder();
    cout << endl;
    b.levelOrder();
    b.root->val = 50;
    cout << isValidBST(b.root) << endl;
    cout << isValidBSTRange(b.root) << endl;
    return 0;
}


