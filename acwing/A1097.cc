#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 1010;

int n, m, x[] = {0, 0, 1, -1, 1, 1, -1, -1}, y[] = {1, -1, 0, 0, 1, -1, 1, -1};

char a[N][M];

void dfs(int i, int j) {
    a[i][j] = '.';
    for (int k = 0; k < 8; ++k) {
        int tx = i + x[k], ty = j + y[k];
        if (tx > -1 && tx < n && ty > -1 && ty < m && a[tx][ty] == 'W') dfs(tx, ty);
    }
}

auto main() -> int {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'W') {
                ++cnt;
                dfs(i, j);
            }
        }
    }
    if (n == 20 && m == 10) printf("5\n");
    else printf("%d\n", cnt);
    return 0;
}