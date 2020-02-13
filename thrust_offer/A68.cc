#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode (int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q),
        right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};

int main() {
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->left->left = new TreeNode(3);
    node->left->right = new TreeNode(4);
    Solution s;
    cout << s.lowestCommonAncestor(node, node->left->left, node->left->right)->val;
    return 0;
}
