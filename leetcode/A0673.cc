class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        vector<map<int, int>> maps(nums.size());
        maps[0][nums[0]] = 1;
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int left = 0, right = res, lastPos = -1;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                if (nums[mid] < nums[i]) {
                    lastPos = mid;
                    left = mid + 1;
                } else right = mid - 1;
            }
            nums[lastPos + 1] = nums[i];
            if (lastPos + 1 == 0) {
                maps[0][nums[i]]++;
            } else {
                for (auto &it : maps[lastPos]) {
                    if (it.first >= nums[i]) break;
                    else maps[lastPos + 1][nums[i]] += it.second;
                }
            }
            res = max(res, lastPos + 1);
        }
        int p = 0;
        for (auto &it : maps[res]) p += it.second;
        return p;
    }
};