#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		return build(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
private:
	TreeNode *build(const vector<int> &pre, int preStart, int preEnd, 
	const vector<int> &vin, int inStart, int inEnd) {
		if (preStart > preEnd) return nullptr;
		TreeNode *res = new TreeNode(pre[preStart]);
		for (int i = inStart; i < inEnd + 1; ++i) {
			if (vin[i] == pre[preStart]) {
				res->left = build(pre, preStart + 1, i - inStart + preStart, vin, inStart, i - 1);
				res->right = build(pre, i - inStart + preStart + 1, preEnd, vin, i + 1, inEnd);
				break;
			}
		}
		return res;
	}
};