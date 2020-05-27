class Solution {
public:
    vector<vector<int>> res;
    bool can(const vector<int> &a, int i, int j) {
        if (i == j) return true;
        for (int k = i; k < j; ++k) {
            if (a[k] == a[j]) return false;
        }
        return true;
    }
    void dfs(int level, vector<int> &a) {
        if (level == a.size()) {
            res.push_back(a);
            return;
        }
        for (int i = level; i < a.size(); ++i) {
            if (can(a, level, i)) {
                swap(a[level], a[i]);
                dfs(level + 1, a);
                swap(a[level], a[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};