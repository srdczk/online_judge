class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length());
        int res = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')') {
                if (i && s[i - 1] == '(') dp[i] = i < 2 ? 2 : dp[i - 2] + 2;
                else if (i - 1 >= dp[i - 1] && s[i - 1 - dp[i - 1]] == '(') {
                    
                    dp[i] = dp[i - 1] + 2;
                    if (i - 1 - dp[i - 1] > 0) dp[i] += dp[i - 2 - dp[i - 1]];
                }
            } 
            res = max(res, dp[i]);
        }
        return res;
    }
};