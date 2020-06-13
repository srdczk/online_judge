#include <bits/stdc++.h>

using namespace std;

const int maxV = 20010, maxN = 40;

int ns[maxN], dp[maxV];

int V, n;

int main() {
    scanf("%d", &V);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ns[i]);
        for (int j = V; j >= ns[i]; --j) {
            dp[j] = max(dp[j], dp[j - ns[i]] + ns[i]);
        }
    }
    printf("%d\n", V - dp[V]);
    return 0;
}