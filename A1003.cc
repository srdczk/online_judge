#include <bits/stdc++.h>

using namespace std;
const int maxV = 510;
int n, m, s, e;
int d[maxV], w[maxV], hs[maxV], num[maxV];
bool vis[maxV];
struct Node {
    int v, dis;
};
vector<Node> adj[maxV];
void dij() {
    fill(d, d + maxV, INT_MAX);
    fill(vis, vis + maxV, 0);
    fill(hs, hs + maxV, 0);
    fill(num, num + maxV, 0);
    d[s] = 0;
    num[s] = 1;
    hs[s] = w[s];
    for (int i = 0; i < n; ++i) {
        int MIN = INT_MAX, u = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1 || u == e) break;
        vis[u] = 1;
        for (auto &c : adj[u]) {
            if (!vis[c.v] && d[c.v] > d[u] + c.dis) {
                num[c.v] = num[u];
                hs[c.v] = hs[u] + w[c.v];
                d[c.v] = d[u] + c.dis;
            } else if (!vis[c.v] && d[c.v] == d[u] + c.dis) {
                num[c.v] += num[u];
                hs[c.v] = max(hs[c.v], hs[u] + w[c.v]);
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i = 0; i < n; ++i) scanf("%d", w + i);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(Node{b, c});
        adj[b].push_back(Node{a, c});
    }
    dij();
    printf("%d %d\n", num[e], hs[e]);
    return 0;
}