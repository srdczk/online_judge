class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128, -1);
        int res = 0;
        for (int i = 0, j = 0; i < s.length(); ++i) {
            if (cnt[s[i]] >= j) j = cnt[s[i]] + 1;
            cnt[s[i]] = i;
            res = max(res, i - j + 1);
        }
        return res;
    }
};