#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n, k;
int vis[N];
int bfs() {
    queue<int> q;
    vis[n] = 0;
    q.push(n);
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (2 * t < N && vis[2 * t] == -1) {
            q.push(2 * t);
            vis[2 * t] = vis[t] + 1; 
            if (2 * t == k) return vis[2 * t];
        }
        if (t - 1 >= 0 && vis[t - 1] == -1) {
            q.push(t - 1);
            vis[t - 1] = vis[t] + 1;
            if (t - 1 == k) return vis[t - 1]; 
        }
        if (t + 1 < N && vis[t + 1] == -1) {
            q.push(t + 1);
            vis[t + 1] = vis[t] + 1;
            if (t + 1 == k) return vis[t + 1];
        }
    }
    return -1;
}

auto main() -> int {
    fill(vis, vis + N, -1);
    scanf("%d%d", &n, &k);
    printf("%d\n", bfs());
    return 0;
}