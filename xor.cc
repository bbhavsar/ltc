#include "common.hh"

struct XORNode {
    int val;
    unsigned long ptr;
    XORNode(int v, unsigned long p) : val(v), ptr(p) {}
};

class XORList {
private:
    XORNode *head, *tail;
    int size;

public:
    XORList() : head(NULL), tail(NULL), size(0) {}

    void add(int val) {
        XORNode *n = new XORNode(val, 0);
        if (head == NULL) {
            assert(tail == NULL);
            head = tail = n;
            size = 1;
            return;
        }
        n->ptr = (unsigned long)tail ^ 0;
        tail->ptr = (unsigned long)n ^ tail->ptr;
        tail = n;
        size++;
    }

    int get(int idx) {
        if (size == 0) {
            assert(head == NULL);
            assert(tail == NULL);
            return -1;
        }
        if (idx < 0 || idx >= size) {
            return -1;
        }
        unsigned long curr = (unsigned long) head;
        unsigned long prev = 0;
        const unsigned long end = (unsigned long) tail;
        int i;
        for (i = 0; curr != end && i < idx  ; i++) {
            unsigned long next = ((XORNode *)curr)->ptr ^ prev;
            prev = curr;
            curr = next;
        }
        assert(i == idx);
        return ((XORNode *)curr)->val;
    }
};

int main() {
    XORList l;
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(100);

    cout << l.get(0) << endl;
    cout << l.get(3) << endl;
    cout << l.get(2) << endl;
    cout << l.get(1) << endl;

    return 0;
}

