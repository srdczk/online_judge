class Solution {
public:
    bool pd(string &s, int len) {
        if (!len) return true;
        unordered_set<string> us;
        for (int i = 0; i <= s.length() - len; ++i) {
            string p = s.substr(i, len);
            if (us.count(p)) return true;
            us.insert(p);
        }
        return false;
    }
    int longestRepeatingSubstring(string s) {
        int left = 0, right = s.size() - 1, lastPos = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (pd(s, mid)) {
                lastPos = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        return lastPos;
    }
};