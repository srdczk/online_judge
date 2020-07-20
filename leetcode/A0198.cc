class Solution {
public:
    int rob(vector<int>& nums) {
        if (!nums.size()) return 0;
        int res = nums[0], a = 0, b = 0;
        for (auto &num : nums) {
            int tmp = a;
            a = b + num;
            b = max(b, tmp);
            res = max(a, b);
        }
        return res;
    }
};