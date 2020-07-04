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
        int cnt = 0;
        auto node = head, originHead = head;
        while (cnt < k) {
            if (!node) return head;
            node = node->next;
            cnt++;
        }
        auto p = head;
        while (p != node) {
            auto next = p->next;
            p->next = head;
            head = p;
            p = next;
        }
        originHead->next = reverseKGroup(node, k);
        return head;
    }
};