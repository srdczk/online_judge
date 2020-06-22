#include <bits/stdc++.h>

using namespace std;

const int N = 15;

struct Node {
    int x, y;
};

queue<Node> q;
int n = 0, m = 0, a[N][N], x[] = {0, 0, 1, -1}, y[] = {1, -1, 0, 0};
int vis[N][N];

void bfs() {
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int tx = node.x + x[k], ty = node.y + y[k];
            if (tx > -1 && tx < n && ty > -1 && ty < m && a[tx][ty] == 1 && vis[tx][ty] == -1) {
                vis[tx][ty] = vis[node.x][node.y] + 1;
                q.push(Node{tx, ty});
            }
        }
    }
}


auto main() -> int {
    fill(*vis, *vis + N * N, -1);
    char c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            a[n][i++] = c - '0';
        } else if (c == '\n') {
            n++;
            m = i;
            i = 0;
        }
    }
    n++;
    // add to queue
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 2) {
                q.push(Node{i, j});
                vis[i][j] = 0;
            }
        }
    }
    bfs();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1 && vis[i][j] == -1) {
                printf("-1\n");
                return 0;
            }
            res = max(res, vis[i][j]);
        }
    }
    printf("%d\n", res);
    return 0;
}