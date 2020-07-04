#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> a;

int n, m;

int x[] = {0, 0, 1, -1, 1, 1, -1, -1}, y[] = {1, -1, 0, 0, 1, -1, 1, -1};

void dfs(int i, int j) {
    a[i][j] = 0;
    for (int k = 0; k < sizeof(x) / sizeof(int); ++k) {
        int tx = i + x[k], ty = j + y[k];
        if (tx > -1 && tx < n && ty > -1 && ty < m && a[tx][ty] == 1) dfs(tx, ty);
    }
}

auto main() -> int {
    scanf("%d%d", &n, &m);
    a = vector<vector<int>> (n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (a[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    printf("%d\n", cnt);
    return 0;
}