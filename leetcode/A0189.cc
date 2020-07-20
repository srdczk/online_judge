class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2) return;
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1 - k);
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }

    void reverse(vector<int> &a, int left, int right) {
        for (int i = 0; i < (right - left + 1) >> 1; ++i)
            swap(a[left + i], a[right - i]);
    }
};