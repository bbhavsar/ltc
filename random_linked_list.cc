// https://leetcode.com/problems/copy-list-with-random-pointer/

#include "common.hh"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *clone_head = NULL;
        Node *clone_tail = clone_head;

        Node *curr = head;
        unordered_map<Node *, Node *> ref_map;

        while (curr != NULL) {
            Node *n = new Node();
            n->next = n->random = NULL;
            n->val = curr->val;

            if (clone_head == NULL) {
                clone_head = clone_tail = n;
            } else {
                clone_tail->next = n;
                clone_tail = n;
            }
            ref_map[curr] = n;
            curr = curr->next;
        }

        curr = head;
        Node *clone_curr = clone_head;
        while (curr != NULL) {
            assert(clone_curr != NULL);
            clone_curr->random = ref_map[curr->random];
            curr = curr->next;
            clone_curr = clone_curr->next;
        }
        return clone_head;
    }
};

int main() {

    return 0;
}

