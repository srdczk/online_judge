class Solution {
public:
    static const int kMaxV = 100010;
    int next[kMaxV];
    void process(string &s) {
        next[0] = -1;
        next[1] = 0;
        int i = 2, cnt = 0;
        while (i < s.length()) {
            if (s[i - 1] == s[cnt]) next[i++] = ++cnt;
            else if (!cnt) next[i++] = 0;
            else cnt = next[cnt];
        }
    }
    int strStr(string haystack, string needle) {
        if (!needle.length()) return 0;
        process(needle);
        int i = 0, j = 0;
        while (i < haystack.length() && j < needle.length()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else if (!j) i++;
            else j = next[j];
        }
        return j == needle.length() ? i - needle.length() : -1;
    }
};