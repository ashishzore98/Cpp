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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode d(0);
        d.next = head;
        ListNode* pg = &d;
        while (true) {
            ListNode* kn = pg;
            for (int i = 0; i < k; i++) {
                kn = kn->next;
                if (kn == nullptr) {
                    return d.next;
                }
            }
            ListNode* gs = pg->next;
            ListNode* ng = kn->next;
            ListNode* p = ng;
            ListNode* c = gs;
            while (c != ng) {
                ListNode* t = c->next;
                c->next = p;
                p = c;
                c = t;
            }
            pg->next = kn;
            pg = gs;
        }
    }
};