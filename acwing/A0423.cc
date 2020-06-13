#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, maxT = 1010;

int T, M;

int t[N], w[N], dp[maxT];

int main() {
    scanf("%d%d", &T, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &t[i], &w[i]);
    }

    fill(dp, dp + T + 1, 0);
    for (int i = 0; i < M; ++i) {
        for (int j = T; j >= t[i]; --j) {
            dp[j] = max(dp[j - t[i]] + w[i], dp[j]);
        }
    }
    printf("%d\n", dp[T]);
    return 0;
}