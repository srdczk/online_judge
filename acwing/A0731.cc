#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, a[N][N], dp[1 << N][N];
// have vis i and now at j

auto main() -> int {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
    // dp[i][j] fill dp[1][0] => have vis 1 and now at 1
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int i = 1; i < (1 << n); ++i) {
        // j at what
        for (int j = 0; j < n && (1 << j) <= i; ++j) {
            if ((1 << j) & i) {
                // have vis j
                for (int k = 0; k < n; ++k) {
                    if ((i - (1 << j)) & (1 << k)) dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + a[j][k]);
                }
            }
        }
    }
    int res = 0x3f3f3f3f;
    for (int i = 0; i < n; ++i) res = min(res, dp[(1 << n) - 1][i] + a[i][0]);
    printf("%d\n", res);
    return 0;
}