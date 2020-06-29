class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto &x, const auto &y) {
            if (x[0] != y[0]) return x[0] < y[0];
            else return x[1] < y[1];
        });
        if (envelopes.empty()) return 0;
        int res = 1;
        vector<int> dp(envelopes.size());
        for (int i = 1; i < envelopes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][1] > envelopes[j][1] && envelopes[i][0] > envelopes[j][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i] + 1);
        }
        return res;
        // return min(res, (int)envelopes.size());
    }
};