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
    TreeNode *process(vector<int> &a, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + ((right - left) >> 1);
        auto res = new TreeNode(a[mid]);
        res->left = process(a, left, mid - 1);
        res->right = process(a, mid + 1, right);
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return process(nums, 0, nums.size() - 1);
    }
};