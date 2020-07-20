class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        int i = 0, x = nums[0];
        while (i < nums.size()) {
            x = nums[i];
            
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int numJ = nums[j], numK = nums[k], sum = nums[j] + nums[k] + nums[i];
                if (!sum) {
                        res.push_back({nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == numJ) j++;
                        while (j < k && numK == nums[k]) k--;
                    } else if (sum > 0) {
                        while (j < k && nums[k] == numK) k--;
                    } else {
                        while (j < k && nums[j] == numJ) j++;
                    }
            }

            while (i < nums.size() && nums[i] == x) i++;
        }
        return res;
    }
};