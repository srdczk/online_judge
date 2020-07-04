#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;

int a[N][N];

auto main() -> int {
    scanf("%d%d", &n, &m);
    int i = 0, j = 0, cnt = 1, x = 1, y = 0, p = 0, q = 0, dir = 0;
    while (cnt <= n * m) {
        a[i][j] = cnt++;
        if (cnt == n * m + 1) break;
        if (dir == 0) {
            if (j == m - 1 - y) {
                i++;
                y++;
                dir = 1;
            } else j++;
        } else if (dir == 1) {
            if (i == n - 1 - p) {
                j--;
                p++;
                dir = 2;
            } else i++;
        } else if (dir == 2) {
            if (j == q) {
                q++;
                i--;
                dir = 3;
            } else j--;
        } else {
            if (i == x) {
                dir = 0;
                j++;
                x++;
            } else i--;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}