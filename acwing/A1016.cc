#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N], dp[N];

int res(int n) {
    int ret = dp[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        ret = max(dp[i], ret);
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        dp[i] = a[i];
    }
    printf("%d", res(n));
    return 0;
}