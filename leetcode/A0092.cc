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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        m--;
        n--;
        ListNode *node = head;
        ListNode *pre = nullptr, *next = nullptr;
        ListNode *begin, *end;
        int cnt = 0;
        while (node && cnt < m) {
            pre = node;
            node = node->next;
            cnt++;
        }
        begin = node;
        // cout << node->val << " ";
        while (node && cnt < n) {
            node = node->next;
            cnt++;
        }
        // cout << node->val;
        next = node->next;
        ListNode *p = begin->next;
        begin->next = next;
        while (p != next) {
            auto next = p->next;
            p->next = begin;
            begin = p;
            p = next;
        }
        if (pre) {
            pre->next = begin;
            return head;
        } else return begin;
    }
};