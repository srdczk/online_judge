class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size()) {
            if (nums[i]) swap(nums[i], nums[j++]);
            ++i;
        }
    }
};