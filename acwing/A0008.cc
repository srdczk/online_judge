#include <bits/stdc++.h>

using namespace std;

const int maxV = 110, maxM = 110, maxN = 1010;

int N, V, M, v[maxN], m[maxN], w[maxN], dp[maxV][maxM];

int main() {
    fill(*dp, *dp + maxV * maxM, 0);
    scanf("%d%d%d", &N, &V, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d", &v[i], &m[i], &w[i]);
        for (int j = V; j >= v[i]; --j) {
            for (int k = M; k >= m[i]; --k)
                dp[j][k] = max(dp[j][k], dp[j - v[i]][k - m[i]] + w[i]);
        }
    }
    printf("%d\n", dp[V][M]);
    return 0;
}