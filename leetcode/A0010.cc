class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < p.size() + 1; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] |= dp[0][i - 2];
            } else dp[0][i] = false;
        }
        for (int i = 1; i < s.size() + 1; ++i) {
            for (int j = 1; j < p.size() + 1; ++j) {
                if (p[j - 1] == '*') {
                    if (p[j - 2] == '.') {
                        for (int k = i; k > -1; --k) {
                            if (dp[k][j - 2]) {
                                dp[i][j] |= 1;
                                break;
                            }
                        }
                    } else {
                        char c = p[j - 2];
                        if (dp[i][j - 2]) dp[i][j] |= dp[i][j - 2];
                        else if (s[i - 1] == c) {
                            int k = i - 1;
                            while (k > -1 && s[k] == c) {
                                if (dp[k--][j - 2]) {
                                    dp[i][j] = 1;
                                    break;
                                }
                            }
                        }
                    }
                } else if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
                    dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};