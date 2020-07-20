class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j > -1; --j) {
                if (i == j) dp[i][j] = 1;
                else if (s[i] == s[j]) dp[i][j] = dp[i - 1][j + 1] + 2;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
            }
        }
        return dp[s.size() - 1][0];
    }
};