class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int i = 1; i * i + t < n + 1; ++i) {
                if (!dp[i * i + t]) {
                    dp[i * i + t] = dp[t] + 1;
                    q.push(i * i + t);
                }
            }
            if (dp[n]) return dp[n];
        }
        return dp[n];
    }
};