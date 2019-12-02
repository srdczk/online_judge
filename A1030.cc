#include <bits/stdc++.h>

using namespace std;
const int maxV = 510;
int n, m, s, e;
struct Node {
    int v, dis, cost;
};
int ds[maxV], num[maxV], cs[maxV], pre[maxV];
bool vis[maxV];
vector<Node> adj[maxV];
void dij() {
    fill(ds, ds + maxV, INT_MAX);
    fill(num, num + maxV, 0);
    fill (cs, cs + maxV, INT_MAX);
    fill(vis, vis + maxV, 0);
    fill(pre, pre + maxV, -1);
    ds[s] = 0;
    num[s] = 1;
    cs[s] = 0;
    for (int i = 0; i < n; ++i) {
        int MIN = INT_MAX, u = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && ds[j] < MIN) {
                MIN = ds[j];
                u = j;
            }
        }
        if (u == -1 || u == e) break;
        vis[u] = 1;
        for (auto &c : adj[u]) {
            if (!vis[c.v] && ds[c.v] > ds[u] + c.dis) {
                ds[c.v] = ds[u] + c.dis;
                num[c.v] = num[u];
                cs[c.v] = cs[u] + c.cost;
                pre[c.v] = u;
            } else if (!vis[c.v] && ds[c.v] == ds[u] + c.dis) {
                num[c.v] += num[u];
                if (cs[c.v] > cs[u] + c.cost) {
                    pre[c.v] = u;
                    cs[c.v] = cs[u] + c.cost;
                }
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &e);
    while (m--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        adj[a].push_back(Node{b, c, d});
        adj[b].push_back(Node{a, c, d});
    }
    dij();
        stack<int> s;
    int x = e, cnt = 0;
    while (x != -1) {
        s.push(x);
        x = pre[x];
    }
    while (!s.empty()) {
        if (cnt++) printf(" ");
        printf("%d", s.top());
        s.pop();
    }
    if (cnt++) printf(" ");
    printf("%d", ds[e]);
    if (cnt++) printf(" ");
    printf("%d\n", cs[e]);
    return 0;
}
