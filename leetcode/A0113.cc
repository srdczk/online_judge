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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return res;
        unordered_map<TreeNode *, TreeNode *> fatherMap;
        unordered_map<TreeNode *, int> sumMap;
        queue<TreeNode *> q;
        q.push(root);
        sumMap[root] = root->val;
        fatherMap[root] = nullptr;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                fatherMap[node->left] = node;
                sumMap[node->left] = node->left->val + sumMap[node];
            }
            if (node->right) {
                q.push(node->right);
                fatherMap[node->right] = node;
                sumMap[node->right] = node->right->val + sumMap[node];
            }
            if (!node->left && !node->right) {
                if (sumMap[node] == sum) {
                    vector<int> path;
                    while (node) {
                        path.insert(path.begin(), node->val);
                        node = fatherMap[node];
                    }
                    res.push_back(path);
                }
            }
        }
        return res;
    }
};