#include <bits/stdc++.h>

using namespace std;

const int maxN = 1010;

char a[maxN], b[maxN];

int N, M;
int dp[maxN][maxN];
int main() {
    scanf("%d%d", &N, &M);
    memset(a, '\0', maxN);
    memset(b, '\0', maxN);
    fill(*dp, *dp + maxN * maxN, 0);
    getchar();
    for (int i = 0; i < N; ++i) {
        a[i] = getchar();
    }
    getchar();
    for (int i = 0; i < M; ++i) {
        b[i] = getchar();
    }
    getchar();
    int res = 0;
    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j < M + 1; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            res = max(res, dp[i][j]);
        }
    }
    printf("%d\n", res);
    return 0;
}