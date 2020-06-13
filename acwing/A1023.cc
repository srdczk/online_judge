#include <bits/stdc++.h>

using namespace std;

const int maxN = 1010;

int a[] = {10, 20, 50, 100};

int N, dp[maxN];

int main() {
    fill(dp, dp + maxN, 0);
    scanf("%d", &N);
    dp[0] = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = a[i]; j < N + 1; ++j) {
            dp[j] += dp[j - a[i]];
        }
    }
    printf("%d\n", dp[N]);
    return 0;
}