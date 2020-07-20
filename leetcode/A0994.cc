class Solution {
public:
    vector<int> x = {0, 0, 1, -1}, y = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int res = 0;
        vector<vector<int>> cnt(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) q.push(pair<int, int>{i, j});
                 
            }
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int i = 0; i < x.size(); ++i) {
                int tx = x[i] + node.first, ty = y[i] + node.second;
                if (tx > -1 && tx < grid.size() && ty > -1 && ty < grid[0].size() && grid[tx][ty] == 1) {
                    grid[tx][ty] = 0;
                    q.push(pair<int, int>{tx, ty});
                    cnt[tx][ty] = cnt[node.first][node.second] + 1;
                    res = max(cnt[tx][ty], res);
                }
            }
        }
        for (auto &x : grid) {
            for (auto &y : x) {
                if (y == 1) return -1;
            }
        }
        return res;
    }
};