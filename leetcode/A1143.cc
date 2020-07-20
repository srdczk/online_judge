class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        for (int i = 1; i < a.size() + 1; ++i) {
            for (int j = 1; j < b.size() + 1; ++j) {
                if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[a.size()][b.size()];
    }
};