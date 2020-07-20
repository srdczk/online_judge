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
    ListNode *reSolve(ListNode *pre, ListNode *node) {
        if (!node) return pre;
        ListNode *next = node->next;
        node->next = pre;
        return reSolve(node, next);
    }
    ListNode *itSolve(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *q = head->next;
        head->next = nullptr;
        while (q) {
            ListNode *next = q->next;
            q->next = head;
            head = q;
            q = next;
        }
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        return reSolve(nullptr, head);
    }
};