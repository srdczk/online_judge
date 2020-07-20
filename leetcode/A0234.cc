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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *p = head, *q = head;
        while (p) {
            p = p->next ? p->next->next : nullptr;
            q = q->next;
        }
        // reverse
        ListNode *x = q->next;
        q->next = nullptr;
        while (x) {
            ListNode *next = x->next;
            x->next = q;
            q = x;
            x = next;
        }
        while (q) {
            if (q->val != head->val) return false;
            q = q->next;
            head = head->next;
        }
        return true;
    }
};