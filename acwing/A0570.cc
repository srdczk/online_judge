#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, M = 2010;

int a[N], cnt[M], n, m;
auto main() -> int {
    fill(cnt, cnt + M, 0);
    int res = INT_MAX, count = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0, j = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (!a[i]) continue;
        if (!cnt[a[i]]++) count++;
        while (count == m) {
            res = min(res, i - j + 1);
            if (!--cnt[a[j++]]) count--;
        }
    }
    printf("%d\n", res == INT_MAX ? -1 : res);
    return 0;
}