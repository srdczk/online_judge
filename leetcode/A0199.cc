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
    vector<int> res;
    int maxLevel = -1;
    void dfs(TreeNode *node, int level) {
        if (!node) return;
        if (level > maxLevel) {
            maxLevel = level;
            res.push_back(node->val);
        }
        dfs(node->right, level + 1);
        dfs(node->left, level + 1);
    }
    vector<int> dfsSolve(TreeNode *node) {
        dfs(node, 0);
        return res;
    }
    vector<int> bfsSolve(TreeNode *node) {
        if (!node) return res;
        unordered_map<TreeNode *, int> um;
        um[node] = 0;
        int level = -1;
        queue<TreeNode *> q;
        q.push(node);
        TreeNode *pre = nullptr;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (um[front] > level) {
                level = um[front];
                if (pre) res.push_back(pre->val);
            }
            if (front->left) {
                q.push(front->left);
                um[front->left] = um[front] + 1;
            }
            if (front->right) {
                q.push(front->right);
                um[front->right] = um[front] + 1;
            }
            pre = front;
        }
        res.push_back(pre->val);
        return res;
    }
    vector<int> rightSideView(TreeNode* root) {
        // from right
        return bfsSolve(root);
    }
};