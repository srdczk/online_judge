class Solution {
public:
    typedef unsigned long long ULL;
    static const int N = 400010;
    int base = 26;
    const char *str;
    int n;
    ULL h[N];
    ULL p[N];
    ULL get(int i, int size) {
        if (!i) return h[size - 1];
        else return h[i + size - 1] - h[i - 1] * p[size];
    }
    int maxCommon(int i, int j) {
        int left = 1, right = min(n - i, n - j), lastPos = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (get(i, mid) == get(j, mid)) {
                left = mid + 1;
                lastPos = mid;
            } else right = mid - 1;
        }
        return lastPos;
    }
    bool cmp(int i, int j) {
        int common = maxCommon(i, j);
        if (common == -1) return str[i] > str[j];
        else if (common == n - i) return false;
        else if (common == n - j) return true;
        return str[i + common] > str[j + common];
    }
    string lastSubstring(string s) {
        if (!s.length()) return s;
        str = s.data();
        n = s.length();
        h[0] = s[0] - 'a';
        p[0] = 1;
        for (int i = 1; i < n; ++i) {
            h[i] = h[i - 1] * (ULL)base + s[i] - 'a';
            p[i] = p[i - 1] * (ULL)base;
        }
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (cmp(i, res)) res = i;
        }
        return s.substr(res);
    }
};