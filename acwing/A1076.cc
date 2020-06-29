#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

struct Node {
    int x, y;
    Node(): x(-1), y(-1) {}
    Node(int x_, int y_): x(x_), y(y_) {}
};

Node pre[N][N];
stack<Node> s;
int n, a[N][N], x[] = {0, 0, 1, -1}, y[] = {1, -1, 0, 0};

void bfs() {
    queue<Node> q;
    q.push(Node{0, 0});
    a[0][0] = 1;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        bool pd = true;
        for (int k = 0; k < 4; ++k) {
            int tx = node.x + x[k], ty = node.y + y[k];
            if (tx > -1 && tx < n && ty > -1 && ty < n && !a[tx][ty]) {
                q.push(Node{tx, ty});
                pre[tx][ty] = node;
                if (tx == n - 1 && ty == n - 1) {pd = false; break;}
                a[tx][ty] = 1;
            }
        }
        if (!pd) break;
    }
    Node node{n - 1, n - 1};
    while (node.x >= 0) {
        s.push(node);
        node = pre[node.x][node.y];
    }
}

auto main() -> int {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
    }
    bfs();
    while (!s.empty()) {
        printf("%d %d\n", s.top().x, s.top().y);
        s.pop();
    }
    return 0;
}