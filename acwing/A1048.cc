#include <bits/stdc++.h>

using namespace std;

const int N = 110, M = 15;

int n, m, dp[N][M];

auto main() -> int {
    while (cin >> n >> m) {
        
        for (int i = 1; i <= n; ++i) dp[i][1] = i;
        for (int i = 1; i <= m; ++i) dp[1][i] = 1;
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1];
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[k - 1][j - 1], dp[i - k][j]) + 1);
                }
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}