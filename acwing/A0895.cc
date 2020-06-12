#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N];

int logSolve(int n) {
    if (n < 2) return n;
    int pos = 0;
    for (int i = 1; i < n; ++i) {
        int left = 0, right = pos, lastPos = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (a[mid] < a[i]) {
                lastPos = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        a[lastPos + 1] = a[i];
        pos = max(pos, lastPos + 1);
    }
    return pos + 1;
}

int dpSolve(int n) {
    int dp[n];
    fill(dp, dp + n, 1);
    int res = 1;
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &a[i]);
    printf("%d\n", dpSolve(n) | logSolve(n));
    return 0;
}