#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL maxN = 20, maxM = 3010;

LL N, M;

LL w[maxN];
LL dp[maxM];
int main() {
    fill(dp, dp + maxM, 0);
    dp[0] = 1;
    scanf("%ld%ld", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%ld", &w[i]);
        for (int j = w[i]; j < M + 1; ++j)
            dp[j] += dp[j - w[i]];
    }
    printf("%lld\n", dp[M]);
    return 0;
}