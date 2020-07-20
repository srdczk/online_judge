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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int cnt = 0;
        ListNode *node = head;
        while (node && cnt < k) {
            cnt++;
            node = node->next;
        }
        if (cnt < k) return head;
        ListNode *p = head, *q = head->next;
        head->next = node;
        while (q != node) {
            auto next = q->next;
            q->next = head;
            head = q;
            q = next;
        }
        p->next = reverseKGroup(node, k);
        return head;
    }
};