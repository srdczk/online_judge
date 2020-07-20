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

    int search(vector<int>& nums, int target) {   
        if (nums.empty()) return -1;
        if (nums.size() == 1) return (nums[0] == target) - 1;
        int minIndex = binarySearch(nums);
        // index (x + minIndex)
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int index = (mid + minIndex) % nums.size();
            if (nums[index] == target) return index;
            else if (nums[index] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};