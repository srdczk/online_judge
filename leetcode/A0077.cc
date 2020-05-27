class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &a, int level, int k, int n) {
        if (a.size() == k) {
            res.push_back(a);
            return;
        }
        for (int i = level; i < n; ++i) {
            a.push_back(i + 1);
            dfs(a, i + 1, k, n);
            a.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> a;
        dfs(a, 0, k, n);
        return res;
    }
};