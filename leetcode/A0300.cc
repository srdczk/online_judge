class Solution {
public:

    int dpSolve(const vector<int> &a) {
        
        vector<int> dp(a.size(), 0);

        int res = 0;
        for (int i = 1; i < a.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j]) dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(res, dp[i]);
        }
        return min(res + 1, (int)a.size());
        //return min(res + 1, a.size());
    }
    
    int binarySolve(vector<int> &a) {
        if (a.empty()) return 0;
        int res = 0;
        for (int i = 1; i < a.size(); ++i) {
            int left = 0, right = res, lastPos = -1;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                if (a[mid] < a[i]) {
                    lastPos = mid;
                    left = mid + 1;
                } else right = mid - 1;
            }
            a[lastPos + 1] = a[i];
            res = max(lastPos + 1, res);
        }
        return res + 1;
    } 

    int lengthOfLIS(vector<int>& nums) {
        return binarySolve(nums);
    }
};