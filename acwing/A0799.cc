#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int h[N], a[N], n;

auto main() -> int {
    fill(h, h + N, -1);
    scanf("%d", &n);
    int res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (h[a[i]] >= j) j = h[a[i]] + 1;
        h[a[i]] = i;
        res = max(res, i - j + 1);
    }
    printf("%d\n", res);
    return 0;
}