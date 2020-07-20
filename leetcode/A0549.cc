/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res = 0;
    vector<int> dfs(TreeNode *node) {
        if (!node) return {0, 0};
        auto left = dfs(node->left), right = dfs(node->right);
        int a = node->left && node->left->val + 1 == node->val ? left[0] + 1 : 0;
        int b = node->left && node->left->val - 1 == node->val ? left[1] + 1 : 0;
        int c = node->right && node->right->val + 1 == node->val ? right[0] + 1 : 0;
        int d = node->right && node->right->val - 1 == node->val ? right[1] + 1 : 0;
        res = max(res, max(a + d + 1, b + c + 1));
        return {max(a, c), max(b, d)};
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return res;
    }
};