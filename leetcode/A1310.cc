class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> dp(arr.size(), 0);
        if (arr.empty()) return arr;
        dp[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i) dp[i] = (arr[i] ^ dp[i - 1]);
        vector<int> res;

        for (auto &query : queries) {
            if (!query[0]) res.push_back(dp[query[1]]);
            else res.push_back((dp[query[1]] ^ dp[query[0] - 1]));
        }
        return res;
    }
};