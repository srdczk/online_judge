#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 55;

LL d[N];
int p[N], n;

LL res = 0;


void dfs(int i, LL now, LL spend) {
    if (spend >= res) return;
    if (i == n) {
        res = min(spend, res);
        return;
    }
    dfs(i + 1, now + d[i], spend + (LL)p[i]);
    if (now >= d[i]) {
        dfs(i + 1, now, spend);
    }
}

auto main() -> int {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%ld", &d[i]);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        res += p[i];
    }
    dfs(0, (LL)0, (LL)0);
    printf("%lld\n", res);
    return 0;
}