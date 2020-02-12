#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> a(n);
        a[0] = 1;
        int cnt = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        while (cnt < n) {
            a[cnt++] = min(a[p2] * 2, min(a[p3] * 3, a[p5] * 5));
            if (a[cnt - 1] == a[p2] * 2) ++p2;
            if (a[cnt - 1] == a[p3] * 3) ++p3;
            if (a[cnt - 1] == a[p5] * 5) ++p5;
        }
        return a[n - 1];
    }
};

int main() {
    Solution s;
    cout << s.nthUglyNumber(10);
    return 0;
}
