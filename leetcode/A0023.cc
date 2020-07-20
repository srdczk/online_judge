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
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode *res = new ListNode(0), *p = res;
        priority_queue<ListNode *, vector<ListNode *>, cmp> heap;
        for (auto node : lists) {
            if (node) heap.push(node);
        }
        while (!heap.empty()) {
            auto node = heap.top();
            heap.pop();
            p->next = node;
            node = node->next;
            p = p->next;
            if (node) heap.push(node);
        }
        return res->next;
    }
};