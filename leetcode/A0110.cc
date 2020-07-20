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
    int getHeight(TreeNode *node) {
        if (!node) return 0;
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int x = getHeight(root->left) - getHeight(root->right);
        if (x > 1 || x < -1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};