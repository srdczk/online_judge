#include <bits/stdc++.h>

using namespace std;
const int maxN = 1010, maxM = 510, maxK = 110;

int N, M, K, dp[maxN][maxM];
int main() {
    fill(*dp, *dp + maxN * maxM, 0);
    scanf("%d%d%d", &N, &M, &K);
    int n, m;
    for (int i = 0; i < K; ++i) {
        scanf("%d%d", &n, &m);
        for (int j = N; j >= n; --j) {
            for (int k = M; k > m; --k) {
                dp[j][k] = max(dp[j][k], dp[j - n][k - m] + 1);
            }
        }
    }
    int res;
    for (int i = 0; i < M + 1; ++i) {
        if (dp[N][M] == dp[N][i]) {
            res = i;
            break;
        }
    }
    printf("%d %d\n", dp[N][M], M - res + (!res ? 0 : 1));
    return 0;
}