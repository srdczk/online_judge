#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

struct Node {
    int x, y;
};

int a[N][N], n, m, x[] = {0, 0, 1, -1}, y[] = {1, -1, 0, 0};
int res[N][N];

queue<Node> q;

auto main() -> int {
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c = getchar();
            if (c == '1') q.push(Node{i, j});
            else a[i][j] = 1;
        }
        getchar();
    }
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = node.x + x[i], ty = node.y + y[i];
            if (tx > -1 && tx < n && ty > -1 && ty < m && a[tx][ty]) {
                q.push(Node{tx, ty});
                res[tx][ty] = res[node.x][node.y] + 1;
                a[tx][ty] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) printf(" ");
            printf("%d", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}