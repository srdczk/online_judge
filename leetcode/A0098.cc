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
    bool process(TreeNode *node, long long maxV, long long minV) {
        if (!node) return true;
        if (node->val >= maxV || node->val <= minV) return false;
        return process(node->left, node->val, minV) && process(node->right, maxV, node->val);
    }
    bool isValidBST(TreeNode* root) {
        return process(root, LONG_MAX, LONG_MIN);
    }
};