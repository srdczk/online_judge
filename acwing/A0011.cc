#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxN = 1010, maxV = 1010;

const LL mod = 1000000007;

int N, V, dpX[maxV];

LL dpY[maxV];

int main() {
    fill(dpX, dpX + maxV, 0);
    fill(dpY, dpY + maxV, 1);
    scanf("%d%d", &N, &V);
    int v, w;
    // max[w[i]]
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &v, &w);
        for (int j = V; j >= v; --j) {
            if (dpX[j] < dpX[j - v] + w) {
                dpX[j] = dpX[j - v] + w;
                dpY[j] = dpY[j - v];
            } else if (dpX[j] == dpX[j - v] + w) {
                dpY[j] += dpY[j - v];
            }
            dpY[j] %= mod;
        }
    }
    printf("%lld\n", dpY[V]);
    return 0;
}