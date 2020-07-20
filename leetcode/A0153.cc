class Solution {
public:
    int binarySearch(vector<int> &a) {
        if (a[0] < a[a.size() - 1]) return 0;
        int left = 0, right = a.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (mid && a[mid] < a[mid - 1]) return mid;
            if (mid < a.size() - 1 && a[mid + 1] < a[mid]) return mid + 1;
            if (a[mid] > a[0]) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int minIndex = binarySearch(nums);
        return nums[minIndex];
    }
};