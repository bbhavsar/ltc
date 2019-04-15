#include "common.hh"


struct Node {
    int val;
    Node * next;
    Node(int v, Node *n=NULL) : val(v), next(n) {}
};

Node * merge(Node *l, Node *r) {
    if (l == NULL) {
        return r;
    }
    if (r == NULL) {
        return l;
    }
    if (l == r) {
        return l;
    }

    Node *head = NULL;
    if (l->val <= r->val) {
        head = l;
        l = l->next;
    } else {
        head = r;
        r = r->next;
    }
    Node *curr = head;
    while (l != NULL && r != NULL) {
        if (l->val <= r->val) {
            curr->next = l;
            l = l->next;
        } else {
            curr->next = r;
            r = r->next;
        }
        curr = curr->next;
    }
    if (l != NULL) {
        curr->next = l;
    } else if (r != NULL) {
        curr->next = r;
    }

    return head;
}

void splitList(Node *head, Node **l, Node **r) {
    Node *slow = head;
    Node *fast = head;
    Node *prevs = NULL;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            prevs = slow;
            slow = slow->next;
        }
    }
    *r = slow;
    if (prevs != NULL) {
        prevs->next = NULL;
    }
    *l = head;
}

Node * mergeSort(Node *head) {
    assert(head != NULL);
    Node *l, *r;
    splitList(head, &l, &r);
    assert(l != NULL);
    if (l != r && !(l->next == NULL && (r == NULL || r->next == NULL))) {
        l = mergeSort(l);
        r = mergeSort(r);
    }
    head = merge(l, r);

    return head;
}

void printList(Node *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *l = new Node(10, new Node(20, new Node(30, NULL)));
    Node *r = new Node(5,  new Node(25, new Node(29, NULL)));

    printList(merge(l, r)) ;

    Node *random = new Node(100, new Node(-20, new Node(30, new Node(-100, NULL))));
    printList(mergeSort(random));
    return 0;
}

