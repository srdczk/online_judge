#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l = 0;
		ListNode *res = new ListNode(0), *p = res;
		while (l1 && l2) {
			int m = l1->val, n = l2->val;
			if (m + n + l > 9) {
				l1->val = m + n + l - 10;
				l = 1;
			} else {
				l1->val = m + n + l;
				l = 0;
			}
			res->next = l1;
			res = res->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1) {
			int m = l1->val + l;
			if (m > 9) {
				l1->val = m - 10;
				l = 1;
			} else {
				l1->val += l;
				l = 0;
			}
			res->next = l1;
			l1 = l1->next;
			res = res->next;
		}
		while (l2) {
			int m = l2->val + l;
			if (m > 9) {
				l2->val = m - 10;
				l = 1;
			} else {
				l2->val += l;
				l = 0;
			}
			res->next = l2;
			l2 = l2->next;
			res = res->next;
		}
		if (l) res->next = new ListNode(1);
		return p->next;
    }
};