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
    ListNode *process(ListNode *pre, ListNode *node) {
        if (!node) return pre;
        auto next = node->next;
        node->next = pre;
        return process(node, next);
    }
    ListNode *reSolve(ListNode *head) {
        return process(nullptr, head);
    }
    ListNode *itSolve(ListNode *head) {
        if (!head || !head->next) return head;
        auto p = head->next;
        head->next = nullptr;
        while (p) {
            auto next = p->next;
            p->next = head;
            head = p;
            p = next;
        }
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        return reSolve(head);
    }
};