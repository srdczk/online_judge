#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (!x || !y) {
            printf("0\n");
            continue;
        }
        vector<vector<int>> a(x, vector<int>(y));
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        vector<vector<int>> dp(x, vector<int>(y));
        dp[0][0] = a[0][0];
        for (int i = 1; i < x; ++i) {
            if (!i) dp[i][0] = a[0][0];
            else dp[i][0] = dp[i - 1][0] + a[i][0];
        }
        for (int j = 1; j < y; ++j) {
            dp[0][j] = dp[0][j - 1] + a[0][j];
        }
        for (int i = 1; i < x; ++i) {
            for (int j = 1; j < y; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
        printf("%d\n", dp[x - 1][y - 1]);
    }
    return 0;
}
