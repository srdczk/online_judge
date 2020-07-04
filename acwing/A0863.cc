#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;

int a[N];

auto main() -> int {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int res = INT_MIN;
    a[n - 1] = a[n - 1] - n + 1;
    for (int i = n - 2; i > -1; --i) {
        res = max(a[i] + i + a[i + 1], res);
        a[i] = max(a[i] - i, a[i + 1]);
    }
    printf("%d\n", res);
    return 0;
}