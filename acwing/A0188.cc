#include <bits/stdc++.h>

using namespace std;

const int N = 155;

struct Node {
    int x, y;
    Node(int x_, int y_): x(x_), y(y_) {}
};
int n, m, x[] = {-2, -2, 2, 2, 1, 1, -1, -1}, y[] = {1, -1, 1, -1, -2, 2, -2, 2};
char a[N][N];
int vis[N][N];

int bfs(int startX, int startY, int targetX, int targetY) {
    vis[startX][startY] = 0;
    queue<Node> q;
    q.push(Node{startX, startY});
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (int k = 0; k < 8; ++k) {
            int tx = node.x + x[k], ty = node.y + y[k];
            if (tx > -1 && tx < n && ty > -1 && ty < m && vis[tx][ty] == -1 && a[tx][ty] != '*') {
                vis[tx][ty] = vis[node.x][node.y] + 1;
                if (tx == targetX && ty == targetY) return vis[tx][ty];
                q.push(Node{tx, ty});
            }
        }
    }
    return -1;
}

auto main() -> int {
    fill(*vis, *vis + N * N, -1);
    scanf("%d%d", &m, &n);
    int startX, startY, targetX, targetY;
    getchar();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = getchar();
            if (a[i][j] == 'K') {
                startX = i;
                startY = j;
            }
            if (a[i][j] == 'H') {
                targetX = i;
                targetY = j;
            }
        }
        getchar();
    }
    printf("%d\n", bfs(startX, startY, targetX, targetY));
    return 0;
}