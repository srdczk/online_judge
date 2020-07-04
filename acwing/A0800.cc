#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], b[N], n, m, x;

auto main() -> int {
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    int i = 0, j = m - 1;
    while (i < n && j > -1) {
        if (a[i] + b[j] == x) {
            printf("%d %d\n", i, j);
            i++;
            j--;
        } else if (a[i] + b[j] > x) j--;
        else i++;
    }
    
    return 0;
}