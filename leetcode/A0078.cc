

class Solution {
public:

    vector<vector<int>> res;

    vector<int> a;

    vector<int> *numsPointer;

    void dfs(vector<int> &a, int level) {
        res.push_back(a);
        for (int i = level; i < numsPointer->size(); ++i) {
            a.push_back((*numsPointer)[i]);
            dfs(a, i + 1);
            a.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        numsPointer = &nums;
        dfs(a, 0);
        return res;
    }
};