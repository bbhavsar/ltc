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

    void addElem(int val) {
        XORNode *n = new XORNode(val, 0);
        if (head == NULL) {
            assert(tail == NULL);
            head = tail = n;
            size = 1;
            return;
        }
        n->ptr = (unsigned long)tail;
        tail = n;
        size++;
    }

    int getElem(int idx) {
        if (size == 0) {
            assert(head == NULL);
            assert(tail == NULL);
            return -1;
        }
        if (idx >= size) {
            return -1;
        }
        unsigned long curr = (unsigned long) head;
        unsigned long prev = 0;
        const unsigned long end = (unsigned long) tail;
        for (int i = 0; curr != end ; i++) {
            unsigned long next = ((XORNode *)curr)->ptr ^ prev;
            prev = curr;
            curr = next;
        }

        return ((XORNode *)curr)->val;
    }

};

int main() {


    return 0;
}

