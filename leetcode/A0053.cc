class Solution {
public:
    int itSolve(vector<int> &nums) {
        int sum = 0, res = INT_MIN;
        for (auto &num : nums) {
            sum += num;
            res = res > sum ? res : sum;
            if (sum < 0) sum = 0;
        }
        return res;
    }
    int dpSolve(vector<int> &nums) {
        if (!nums.size()) return 0;
        vector<int> dp(nums.size(), 0);
        int res = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i - 1] < 0) dp[i] = nums[i];
            else dp[i] = dp[i - 1] + nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
    int maxSubArray(vector<int>& nums) {
        return itSolve(nums);
    }
};