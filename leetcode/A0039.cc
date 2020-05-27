class Solution {
public:
    vector<vector<int>> res;
    void dfs(int sum, int level, vector<int> &a, const vector<int> &b) {
        if (!sum) {
            res.push_back(a);
            return;
        }
        for (int i = level; i < b.size(); ++i) {
            if (b[i] <= sum) {
                a.push_back(b[i]);
                dfs(sum - b[i], i, a, b);
                a.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        dfs(target, 0, a, candidates);
        return res;
    }
};