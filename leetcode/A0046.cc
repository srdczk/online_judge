class Solution {
public:
    vector<vector<int>> res;


    void dfs(vector<int> &a, int level) {

        if (level == a.size()) {
            res.push_back(a);
            return;
        }

        for (int i = level; i < a.size(); ++i) {
            swap(a[level], a[i]);
            dfs(a, level + 1);
            swap(a[level], a[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};