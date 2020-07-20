class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0, pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int left = 0, right = pos, lastPos = -1;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                if (nums[mid] < nums[i]) {
                    lastPos = mid;
                    left = mid + 1;
                } else right = mid - 1;
            }
            pos = max(pos, lastPos + 1);
            nums[lastPos + 1] = nums[i];
            res = max(pos + 1, res);
        }
        return res;
    }
};