#include <bits/stdc++.h>

using namespace std;

const int maxV = 510;

struct Node {
    int v, dis;
    Node(int _v, int d): v(_v), dis(d) {}
};

vector<Node> adj[maxV];
vector<int> pre[maxV], tmp, path;
int d[maxV], w[maxV], C, n, s, m, remain = INT_MAX, need = INT_MAX;
bool vis[maxV];

void dij() {
    fill(d, d + maxV, INT_MAX);
    fill(vis, vis + maxV, 0);
    d[0] = 0;
    for (int i = 0; i < n + 1; ++i) {
        int MIN = INT_MAX, u = -1;
        for (int j = 0; j < n + 1; ++j) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) break;
        if (u == s) break;
        vis[u] = 1;
        for (auto &c : adj[u]) {
            if (!vis[c.v] && d[c.v] > d[u] + c.dis) {
                d[c.v] = d[u] + c.dis;
                pre[c.v].clear();
                pre[c.v].push_back(u);
            } else if (!vis[c.v] && d[c.v] == d[u] + c.dis) {
                pre[c.v].push_back(u);
            }
        }
    }
}

void dfs(int v) {
    tmp.push_back(v);
    if (!v) {
        int remainP = 0, needP = 0;
        for (int i = tmp.size() - 2; i > -1; --i) {
            if (w[tmp[i]] >= C / 2) {
                remainP += w[tmp[i]] - C / 2;
            } else {
                if (C / 2 - w[tmp[i]] > remainP) {
                    needP += (C / 2 - w[tmp[i]] - remainP);
                    remainP = 0;
                } else {
                    remainP -= (C / 2 - w[tmp[i]]);
                }
            }
        }
        if (needP < need) {
            need = needP;
            remain = remainP;
            path = tmp;
        } else if (need == needP && remainP < remain) {
            remain = remainP;
            path = tmp;
        }
    } else {
        for (auto &c : pre[v]) {
            dfs(c);
        }
    }
    tmp.pop_back();
}

int main() {
    scanf("%d%d%d%d", &C, &n, &s, &m);
    for (int i = 1; i < n + 1; ++i) scanf("%d", w + i);
    while (m--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        adj[x].push_back(Node(y, z));
        adj[y].push_back(Node(x, z));
    }
    dij();
    dfs(s);
    printf("%d ", need);
    for (int i = path.size() - 1; i > -1; --i) {
        if (i != path.size() - 1) printf("->");
        printf("%d", path[i]);
    }
    printf(" %d\n", remain);
    return 0;
}
