class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &a, int level, const vector<int> &b) {
        res.push_back(a);

        int i = level;

        while (i < b.size()) {
            int x = b[i];
            a.push_back(b[i]);
            dfs(a, i + 1, b);
            a.pop_back();
            while (i < b.size() && b[i] == x) i++;
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> a;
        dfs(a, 0, nums);
        return res;  
    }
};