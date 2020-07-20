class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int left = 0, right = a.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (a[mid] > a[mid + 1]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};