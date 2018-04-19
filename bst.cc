#include <iostream>

using namespace std;

class Node {
public:
    Node *left, *right;
    int val;
    Node(int v) : val(v), left(NULL), right(NULL) {
    }
};

class BST {
private:
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

int main() {
    int arr[] = {10, 9, 15, 20, 25, -2};
    BST b;
    for (auto elem : arr) {
        b.add(elem);
    }

    b.inorder();
}


