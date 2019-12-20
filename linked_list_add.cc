#include "common.hh"

// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *curr = head;

        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = (l1 == NULL ? 0 : l1->val) +
                      (l2 == NULL ? 0 : l2->val) + carry;
            ListNode* n = new ListNode(sum % 10);
            carry = sum / 10;
            if (head == NULL) {
                curr = head = n;
            } else {
                curr->next = n;
                curr = n;
            }
            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }

        if (carry != 0) {
            ListNode* n = new ListNode(carry);
            assert(curr != NULL);
            curr->next = n;
        }

        return head;
    }
};

int main() {

    return 0;
}

