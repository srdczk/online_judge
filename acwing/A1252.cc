#include <bits/stdc++.h>

using namespace std;

const int N = 10010, V = 10010;

int n, m, v;

int f[N], dp[V];

int findFather(int i) {
    int p = i;
    while (f[i] != i) i = f[i];
    while (p != i) {
        int n = f[p];
        f[p] = i;
        p = n;
    }
    return i;
}

void unionT(int i, int j) {
    int fi = findFather(i), fj = findFather(j);
    if (fi != fj) f[fi] = fj;
}

int a[N][2];

unordered_map<int, int> xMap, yMap;

auto main() -> int {
    fill(dp, dp + V, 0);
    for (int i = 0; i < N; ++i) f[i] = i;
    scanf("%d%d%d", &n, &m, &v);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    int x, y;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        unionT(x - 1, y - 1);
    }
    for (int i = 0; i < n; ++i) {
        int fi = findFather(i);
        xMap[fi] += a[i][0];
        yMap[fi] += a[i][1];
    }
    for (auto &it : xMap) {
        int v = it.second, w = yMap[it.first];
        for (int i = V; i >= v; --i) 
            dp[i] = max(dp[i], dp[i - v] + w);
    }
    printf("%d\n", dp[v]);
    return 0;
}