class Solution {
public:
    typedef long long LL;
    LL res(LL n, LL k) {
        k--;
        LL cur = 1;
        while (k) {
            LL begin = cur, end = cur + 1, cnt = 0;
            while (begin < n + 1) {
                cnt += min(n + 1, end) - begin;
                begin *= (LL)10;
                end *= (LL)10;
            }
            if (k >= cnt) {
                k -= cnt;
                cur++;
            } else {
                k--;
                cur *= 10;
            }
        }
        return cur;
    }
    int findKthNumber(int n, int k) {
        return (int)res((LL)n, (LL)k);
    }
};