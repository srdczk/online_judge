#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int cnt = 0, n, m;
int x[] = {0, -1, 0, 1}, y[] = {-1, 0, 1, 0};
int a[N][N];
bool pd[N][N];

void dfs(int i, int j) {
    ++cnt;
    pd[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int tx = i + x[k], ty = j + y[k];
        if (!pd[tx][ty] && !((a[i][j]) & (1 << k)) && tx > -1 && tx < n && ty > -1 && ty < m) dfs(tx, ty);
    }
}

auto main() -> int {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int resA = 0, resB = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!pd[i][j]) {
                cnt = 0;
                resA++;
                dfs(i, j);
                resB = max(resB, cnt);
            }
        }
    }
    printf("%d\n%d\n", resA, resB);
    return 0;
}