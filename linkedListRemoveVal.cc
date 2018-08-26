#include <iostream>

using namespace std;

struct Node {
    struct Node *next;
    int val;
    Node(int v) : val(v), next(NULL) { }
};

class LinkedList {
    Node *head;
public:
    LinkedList() : head(NULL) {}

    void printList() {
        Node *curr = head;
        while (curr != NULL) {
            cout << curr->val << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void addElem(int val) {
        Node *n = new Node(val);
        n->next = head;
        head = n;
    }

    void removeElems(int val) {
        while (head != NULL && head->val == val) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        if (head == NULL) {
            return;
        }
        Node *prev = head;
        Node *curr = head->next;
        while (curr != NULL) {
            if (curr->val == val) {
                prev->next = curr->next;
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
};

int main() {
    int arr[] = {1, 2, 2, 3, 3, 4, 4, 5, 5};
    LinkedList l;

    for (int elem : arr) {
        l.addElem(elem);
    }
    l.printList();

    l.removeElems(4);
    l.removeElems(5);
    l.printList();

    l.removeElems(2);
    l.removeElems(3);
    l.printList();
    return 0;
}

