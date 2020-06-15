#include <bits/stdc++.h>

using namespace std;

const int N = 1010, V = 1010;
int n, v, dp[V], vs[N], w[N];

int main() {
    fill(dp, dp + V, 0);
    scanf("%d%d", &n, &v);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &vs[i], &w[i]);
        for (int j = v; j >= vs[i]; --j)
            dp[j] = max(dp[j], dp[j - vs[i]] + w[i]);
    }
    printf("%d\n", dp[v]);
    
    return 0;
}