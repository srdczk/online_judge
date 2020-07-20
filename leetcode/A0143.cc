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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode *p = head, *q = head, *pre = nullptr;
        while (q) {
            q = q->next ? q->next->next : nullptr;
            pre = p;
            p = p->next;
        }
        if (pre) pre->next = nullptr;
        ListNode *x = p->next;
        p->next = nullptr;
        while (x) {
            ListNode *next = x->next;
            x->next = p;
            p = x;
            x = next;
        }
        q = head;
        while (q) {
            auto next = q->next;
            if (p) {
                auto pNext = p->next;
                
                q->next = p;
                p->next = next;
                
                p = pNext;
            }
            q = next;
        }
        
    }
};