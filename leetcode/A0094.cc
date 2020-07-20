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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                res.push_back((root = st.top())->val);
                st.pop();
                root = root->right;
            }
        }
        return res;
    }
};