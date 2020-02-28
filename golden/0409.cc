#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> &a, const vector<int> &x, int i, const vector<int> &y, int j) {
        if (i == x.size() && j == y.size()) {
            res.push_back(vector<int>(a));
            return;
        }
        if (i < x.size()) {
            a.push_back(x[i]);
            dfs(a, x, i + 1, y, j);
            a.pop_back();
        }
        if (j < y.size()) {
            a.push_back(y[j]);
            dfs(a, x, i, y, j + 1);
            a.pop_back();
        }
    }
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        res.clear();
        if (!root) {
            res.push_back({});
            return res;
        }
        if (!root->left && !root->right) {
            res.push_back({root->val});
            return res;
        }
        if (!root->right || !root->left) {
            auto vs = BSTSequences(!root->left ? root->right : root->left);
            for (auto &v : vs) {
                v.insert(v.begin(), root->val);
            }
            return vs;
        } else {
            auto left = BSTSequences(root->left), right = BSTSequences(root->right);
            res.clear();
            vector<int> tmp;
            for (auto &x : left) {
                for (auto &y : right) {
                    tmp.clear();
                    tmp.push_back(root->val);
                    dfs(tmp, x, 0, y, 0);
                }
            }
            return res;
        }
    }
};

int main() {
    auto x = new TreeNode(2);
    x->left = new TreeNode(1);
    x->right = new TreeNode(3);
    Solution s;
    auto res = s.BSTSequences(x);
    for (auto &c : res) {
        for (auto &p : c) cout << p << " ";
        cout << "\n";
    }
    return 0;
}
