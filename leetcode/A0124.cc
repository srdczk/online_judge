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
    int res = INT_MIN;

    int process(TreeNode *node) {
        if (!node) return 0;
        int val = node->val;
        int left = process(node->left), right = process(node->right);
        val += left > 0 ? left : 0;
        val += right > 0 ? right : 0;
        res = max(val, res);
        return max(max(left, right), 0) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        process(root);
        return res;
    }
};