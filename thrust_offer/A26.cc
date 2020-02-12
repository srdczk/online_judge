#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B) return false;
        dfs(A, B);
        return res;
    }
private:
    bool res = false;
    bool process(TreeNode *a, TreeNode *b) {
        if (!b) return true;
        if (!a) return false;
        if (a->val != b->val) return false;
        return process(a->left, b->left) && process(a->right, b->right);
    }
    void dfs(TreeNode *node, TreeNode *b) {
        if (res) return;
        if (!node) return;
        if (process(node, b)) {
            res = true;
            return;
        }
        dfs(node->left, b);
        dfs(node->right, b);
    }

};

int main() {
    TreeNode *a = new TreeNode(3), *b = new TreeNode(4);
    a->left = new TreeNode(4);
    a->right = new TreeNode(5);
    a->left->left = new TreeNode(1);
    a->left->right = new TreeNode(2);
    a->right = new TreeNode(5);
    b->left = new TreeNode(1);
    Solution s;
    cout << s.isSubStructure(a, b);
    return 0;
}
