/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) return nullptr;
        ListNode *a = head->next, *b = head->next->next;
        while (b && a != b) {
            b = !b->next ? nullptr : b->next->next;
            a = !b ? nullptr : a->next;
        }
        if (!b) return nullptr;
        // a == b;
        a = head;
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};