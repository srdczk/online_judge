#include <bits/stdc++.h>

using namespace std;
const int N = 1010;

int a[N][N], n, x[] = {0, 0, 1, -1, 1, 1, -1, -1}, y[] = {1, -1, 0, 0, 1, -1, -1, 1};
bool pd[N][N];

int res = -2;

void dfs(int i, int j) {
    pd[i][j] = true;
    for (int k = 0; k < 8; ++k) {
        int tx = i + x[k], ty = j + y[k];
        if (tx > -1 && tx < n && ty > -1 && ty < n) {
            if (a[i][j] == a[tx][ty]) {
                if (!pd[tx][ty]) dfs(tx, ty);
            } else if (a[i][j] > a[tx][ty]) {
                if (res == -2) res = 1;
                else if (res == -1) res = 0;
            } else {
                if (res == -2) res = -1;
                else if (res == 1) res = 0;
            }
        }
    }
}

auto main() -> int {
    scanf("%d", &n);
    int resA = 0, resB = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (!pd[i][j]) {
                res = -2;
                dfs(i, j);
                if (res == 1) resA++;
                else if (res == -1) resB++;
            }
        }
    if (!resA && !resB) printf("1 1\n");
    else printf("%d %d\n", resA, resB);
    return 0;
}