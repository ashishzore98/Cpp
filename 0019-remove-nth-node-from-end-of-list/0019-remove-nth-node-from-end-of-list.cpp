/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode* s = d;
        ListNode* f = d;
        for (int i = 0; i < n; i++) {
            f = f->next;
        }
        while (f->next != nullptr) {
            s = s->next;
            f = f->next;
        }
        s->next = s->next->next;
        return d->next;
    }
};