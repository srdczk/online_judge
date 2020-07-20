class Solution {
public:
    vector<int> res;

    int num;

    void dfs(int level) {
        if (level > num) return;
        res.push_back(level);
        dfs(level * 10);
        if (level % 10 != 9) dfs(level + 1);
    }

    vector<int> lexicalOrder(int n) {
        num = n;
        dfs(1);
        return res;
    }
};