#include <bits/stdc++.h>

using namespace std;

const int maxV = 510;

struct Node {
    int v, dis, t;
    Node(int _v, int d, int _t): v(_v), dis(d), t(_t) {}
};

vector<Node> adj[maxV];

int preD[maxV], preT[maxV], dd[maxV], dt[maxV];
bool vis[maxV];

int n, m, s, e;

void dijD() {
    fill(dd, dd + maxV, INT_MAX);
    fill(dt, dt + maxV, 0);
    fill(preD, preD + maxV, -1);
    fill(vis, vis + maxV, 0);
    dd[s] = 0;
    for (int i = 0; i < n; ++i) {
        int MIN = INT_MAX, u = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && dd[j] < MIN) {
                MIN = dd[j];
                u = j;
            }
        }
        if (u == -1) break;
        if (u == e) break;
        vis[u] = 1;
        for (auto &c : adj[u]) {
            if (!vis[c.v] && dd[c.v] > dd[u] + c.dis) {
                preD[c.v] = u;
                dt[c.v] = dt[u] + c.t;
                dd[c.v] = dd[u] + c.dis;
            } else if (!vis[c.v] && dd[c.v] == dd[u] + c.dis) {
                if (dt[c.v] > dt[u] + c.t) {
                    preD[c.v] = u;
                    dt[c.v] = dt[u] + c.t;
                }
            }
        }
    }
}

void dijT() {
    fill(dd, dd + maxV, 0);
    fill(dt, dt + maxV, INT_MAX);
    fill(vis, vis + maxV, 0);
    fill(preT, preT + maxV, -1);
    dt[s] = 0;
    for (int i = 0; i < n; ++i) {
        int MIN = INT_MAX, u = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && dt[j] < MIN) {
                MIN = dt[j];
                u = j;
            }
        }
        if (u == -1 || u == e) break;
        vis[u] = 1;
        for (auto &c : adj[u]) {
            if (!vis[c.v] && dt[c.v] > dt[u] + c.t) {
                preT[c.v] = u;
                dt[c.v] = dt[u] + c.t;
                dd[c.v] = dd[u] + 1;
            } else if (!vis[c.v] && dt[c.v] == dt[u] + c.t) {
                if (dd[c.v] > dd[u] + 1) {
                    preT[c.v] = u;
                    dd[c.v] = dd[u] + 1;
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b, c, d, e;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        if (!c) {
            adj[a].push_back(Node(b, d, e));
            adj[b].push_back(Node(a, d, e));
        } else adj[a].push_back(Node(b, d, e));
    }
    scanf("%d%d", &s, &e);
    dijD();
    int x = dd[e];
    dijT();
    int y = dt[e];
    int p = e;
    vector<int> vt, vd;
    while (e != -1) {
        vd.push_back(e);
        e = preD[e];
    }
    while (p != -1) {
        vt.push_back(p);
        p = preT[p];
    }
    if (vt == vd) {
        printf("Distance = %d; Time = %d:", x, y);
        for (int i = vd.size() - 1; i > -1; --i) {
            if (i != vd.size() - 1) printf("->");
            printf(" %d", vd[i]);
            if (i) printf(" ");
        }
        printf("\n");

    } else {
        printf("Distance = %d:", x);
        for (int i = vd.size() - 1; i > -1; --i) {
            if (i != vd.size() - 1) printf("->");
            printf(" %d", vd[i]);
            if (i) printf(" ");
        }
        printf("\n");
        printf("Time = %d:", y);
        for (int i = vt.size() - 1; i > -1; --i) {
            if (i != vt.size() - 1) printf("->");
            printf(" %d", vt[i]);
            if (i) printf(" ");

        }
        printf("\n");
    }
    return 0;
}
