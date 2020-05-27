class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &a, const vector<int> &b, int sum, int level) {
        if (!sum) {
            res.push_back(a);
            return;
        }
        int i = level;
        
        while (i < b.size()) {
            int x = b[i];

            if (x <= sum) {
                a.push_back(x);
                dfs(a, b, sum - x, i + 1);
                a.pop_back();
            }

            while (i < b.size() && b[i] == x) i++;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> a;
        dfs(a, candidates, target, 0);
        return res;
    }
};