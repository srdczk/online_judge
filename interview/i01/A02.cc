#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res{};
        unordered_map<TreeNode *, int> map;
        if (!root) return res;
        map[root] = 0;
        int cnt = 0, pMax = root->val;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                map[node->left] = map[node] + 1;
            }
            if (node->right) {
                q.push(node->right);
                map[node->right] = map[node] + 1;
            }
            if (map[node] > cnt) {
                cnt = map[node];
                res.push_back(pMax);
                pMax = node->val;
            } else pMax = max(node->val, pMax);
        }
        res.push_back(pMax);
        return res;
    }
};
