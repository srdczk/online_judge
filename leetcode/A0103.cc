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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        std::unordered_map<TreeNode *, int> map;
        std::queue<TreeNode *> q;
        if (!root) return res;
        q.push(root);
        map[root] = 0;
        std::vector<int> now;
        int cur = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (map[node] > cur) {
                res.push_back(now);
                now.clear();
                cur = map[node];
            }
            if (!(cur % 2)) now.push_back(node->val);
            else now.insert(now.begin(), node->val);
            if (node->left) {
                q.push(node->left);
                map[node->left] = cur + 1;
            }
            if (node->right) {
                q.push(node->right);
                map[node->right] = cur + 1;
            }

        }
        res.push_back(now);
        return res;
    }
};