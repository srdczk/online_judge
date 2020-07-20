class Solution {
public:
    int minDistance(string a, string b) {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
        // a -> b
        for (int i = 0; i < b.size() + 1; ++i) dp[0][i] = i;
        for (int i = 0; i < a.size() + 1; ++i) dp[i][0] = i;

        for (int i = 1; i < a.size() + 1; ++i) {
            for (int j = 1; j < b.size() + 1; ++j) {
                if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }

        return dp[a.size()][b.size()];
    }
};