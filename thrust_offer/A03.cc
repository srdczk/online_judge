#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(nullptr) {}
};
// 链表结构

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
		while (head) {
			res.insert(res.begin(), head->val);
			head = head->next;
		}
		return res;
    }
};