class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &a, int level, const vector<int> &b) {
        
        if (level == b.size()) {
            if (a.size() > 1) 
                res.push_back(a);
            return;
        }
        if (a.empty() || (b[level] >= a[a.size() - 1])) {
            a.push_back(b[level]);
            dfs(a, level + 1, b);
            a.pop_back();
        }
        if (a.size() && a[a.size() - 1] == b[level]) return;
        dfs(a, level + 1, b);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> a;
        dfs(a, 0, nums);
        return res;
    }
};