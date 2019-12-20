#include "common.hh"

// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left = NULL, Node* _right = NULL) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
private:

    void inorder(Node *curr, Node **head, Node **tail) {
        if (curr == NULL) {
            return;
        }

        inorder(curr->left,  head, tail);
        if (*head == NULL) {
            *head = curr;
            *tail = curr;
        } else {
            assert(*tail != NULL);
            (*tail)->right = curr;
            curr->left = *tail;
            *tail = curr;
        }
        inorder(curr->right, head, tail);
    }

public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        Node *head, *tail;
        head = tail = NULL;

        inorder(root, &head, &tail);
        head->left = tail;
        tail->right = head;

        return head;
    }
};

int main() {

    return 0;
}

