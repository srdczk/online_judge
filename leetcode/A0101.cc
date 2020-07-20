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
    bool res = true;
    void dfs(TreeNode *a, TreeNode *b) {
        if (!res) return;
        if (!a) {
            if (b) res = false;
            return;   
        } else {
            if (!b || b->val != a->val) {
                res = false;
                return;
            }
        }
        dfs(a->left, b->right);
        dfs(a->right, b->left);
    }
    bool reSolve(TreeNode *node) {
        if (!node) return true;
        dfs(node->left, node->right);
        return res;
    }
    bool isSymmetric(TreeNode *node) {
        return reSolve(node);
    }

};