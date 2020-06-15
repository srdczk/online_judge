#include <bits/stdc++.h>

using namespace std;

const int maxN = 110, maxV = 110;

int N, V, dp[maxV], v[maxN], w[maxN], s[maxN];
int main() {
    fill(dp, dp + maxV, 0);
    scanf("%d%d", &N, &V);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d", &v[i], &w[i], &s[i]);
        for (int j = V; j >= 0; --j) {
            for (int k = 1; k <= s[i] && k * v[i] <= j; ++k) {
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
            }
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}