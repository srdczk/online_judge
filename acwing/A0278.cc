#include <bits/stdc++.h>

using namespace std;

const int maxN = 110, maxM = 10010;

int N, M;

int a[maxN], dp[maxM];

int main() {
    fill(dp, dp + maxM, 0);
    dp[0] = 1;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
        for (int j = M; j >= a[i]; --j) {
            dp[j] += dp[j - a[i]];
        }
    }
    printf("%d\n", dp[M]);
    return 0;
}