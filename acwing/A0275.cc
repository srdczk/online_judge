#include <bits/stdc++.h>

using namespace std;

// n, m <= 50
const int N = 51;

int a[N][N];

int dp[2 * N - 1][N][N];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    // dp, add max = k
    for (int k = 0; k < m + n - 1; ++k) {
        for (int i = 0; i < min(k + 1, m); ++i) {
            for (int j = 0; j < min(k + 1, m); ++j) {
                if (!k) dp[k][i][j] = a[0][0];
                else {
                    int x = !i || j == k ? INT_MIN : dp[k - 1][i - 1][j] + a[i][k - i] + (i == j ? 0 : a[j][k - j]);
                    int y = i == k || !j ? INT_MIN : dp[k - 1][i][j - 1] + a[i][k - i] + (i == j ? 0 : a[j][k - j]);
                    int w = !i || !j ? INT_MIN : dp[k - 1][i - 1][j - 1] + a[i][k - i] + (i == j ? 0 : a[j][k - j]);
                    int z = i == k || j == k ? INT_MIN : dp[k - 1][i][j] + a[i][k - i] + (i == j ? 0 : a[j][k - j]);
                    dp[k][i][j] = max(max(x, y), max(w, z));
                }
            }
        }
    }
    printf("%d\n", dp[n + m - 2][m - 1][m - 1]);
    return 0;
}