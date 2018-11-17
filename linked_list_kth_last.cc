/*
 * Given a singly linked list and an integer k, remove the kth last element
 * from the list. k is guaranteed to be smaller than the length of the list.
 *
 * The list is very long, so making more than one pass is prohibitively
 * expensive.
 * Do this in constant space and in one pass.
 */

#include "common.hh"

struct Node {
    Node *next;
    int val;
    Node(int v) : val(v), next(NULL) {}
};

class SinglyLinkedList {
private:
    Node *head;
    Node *tail;

public:

    SinglyLinkedList() : head(NULL), tail(NULL) {}

    void push_back(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            assert(tail == NULL);
            head = tail = n;
            return;
        }

        tail->next = n;
        tail = n;
    }


    void print() const {
        Node *curr = head;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void print_klast(int k) const {
        Node *first = head;

        int i;
        for (i = 0; i < k && first != NULL; i++) {
            first = first->next;
        }

        if (first == NULL && i != k) {
            throw invalid_argument("Incorrect k arg");
        }

        Node *second = head;
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        cout << second->val << endl;
    }
};

int main() {
    SinglyLinkedList l;
    for (int i = 1; i <= 100; i++) {
        l.push_back(i);
    }
    l.print_klast(3);
    l.print_klast(48);

    l.print_klast(100);
    l.print_klast(101);

    return 0;
}

