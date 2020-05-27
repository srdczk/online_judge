class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &a, int level, const vector<int> &b) {
        res.push_back(a);

        for (int i = level; i < b.size(); ++i) {
            a.push_back(b[i]);
            dfs(a, i + 1, b);
            a.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        dfs(a, 0, nums);
        return res;
    }
};