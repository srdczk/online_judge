class Solution {
public:
    long sum(const vector<int> &nums) {
        long res = 0;
        for (auto &num : nums) {
            res += (long)num;
        }
        return res;
    }

    bool can(long s, long m, const vector<int> &a) {
        long p = 0;
        long cnt = 1;
        for (auto &c : a) {
            if ((long)c > s) return false;
            if ((long)(p + (long)c) > s) {
                cnt++;
                p = c;
            } else p += c;
            if (cnt > m) return false;
        }
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        long left = 0, right = sum(nums), lastPos = -1;
        while (left <= right) {
            long mid = left + ((right - left) >> 1);
            
            if (can(mid, m, nums)) {
                lastPos = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return (int)lastPos;
    }
};