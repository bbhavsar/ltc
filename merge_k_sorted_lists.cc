
#include "common.hh"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) { val = x; }
};

struct PQElem {
    int idx;
    ListNode *n;
    PQElem(int i, ListNode *ln) : idx(i), n(ln) {}
};

struct Comparator {
    bool operator()(const PQElem& lhs, const PQElem& rhs)  const {
        return lhs.n->val > rhs.n->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<PQElem, vector<PQElem>, Comparator> pq;

    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != NULL) {
            pq.emplace(i, lists[i]);
        }
    }

    ListNode *head = NULL;
    ListNode *tail = NULL;
    while (!pq.empty()) {
        PQElem elem = pq.top();
        pq.pop();
        if (head == NULL) {
            head = tail = elem.n;
        } else {
            tail->next = elem.n;
            tail = elem.n;
        }

        if (elem.n->next != NULL) {
            pq.emplace(elem.idx, elem.n->next);
        }
    }
    if (tail != NULL) {
        assert(tail->next == NULL);
    }
    return head;
}

int main() {


    return 0;
}

