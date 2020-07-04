class Solution {
public:
    vector<vector<int>> res;

    int size;
    vector<int> a;
    void dfs(vector<int> &a, int level, int k) {
        if (!k) {
            res.push_back(a);
            return;
        }
        for (int i = level; i < size; ++i) {
            a.push_back(i + 1);
            dfs(a, i + 1, k - 1);
            a.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        size = n;
        dfs(a, 0, k);
        return res;
    }
};