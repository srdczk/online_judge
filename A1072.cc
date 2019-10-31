#include <bits/stdc++.h>

using namespace std;

const int maxV = 1050;

struct Node {
    int v, dis;
    Node(int _v, int d): v(_v), dis(d) {}
};

int n, m, k, ds;

vector<Node> adj[maxV];
int d[maxV];
bool vis[maxV];

vector<vector<int>> res;

void dij(int i) {
    fill(d, d + maxV, INT_MAX);
    fill(vis, vis + maxV, 0);
    d[i] = 0;
    for (int j = 0; j < n + m; ++j) {
        int MIN = INT_MAX, u = -1;
        for (int k = 0; k < n + m; ++k) {
            if (!vis[k] && d[k] < MIN) {
                MIN = d[k];
                u = k;
            }
        }
        if (u == -1) break;
        vis[u] = 1;
        for (auto &c : adj[u]) {
            if (!vis[c.v] && d[c.v] > d[u] + c.dis) {
                d[c.v] = d[u] + c.dis;
            }
        }
    }
    int sum = 0;
    int MIN = INT_MAX;
    for (int i = m; i < m + n; ++i) {
        if (d[i] > ds) return;
        sum += d[i];
        MIN = min(MIN, d[i]);
    }
    res.push_back({i, MIN, sum});
}

double ans(double a) {
    int k = a * 100;
    if (k % 10 >= 5) return ((int)(a * 10) + 1) / (double)10;
    else return ((int)(a * 10)) / (double)10;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    char a[10], b[10];
    while (k--) {
        int x, y, z;
        cin >> a >> b >> z;
        if (a[0] == 'G') x = atoi(a + 1) - 1;
        else x = atoi(a) - 1 + m;
        if (b[0] == 'G') y = atoi(b + 1) - 1;
        else y = atoi(b) - 1 + m;
        adj[x].push_back(Node(y, z));
        adj[y].push_back(Node(x, z));
    }
    for (int i = 0; i < m; ++i) dij(i);
    if (!res.size()) printf("No Solution\n");
    else {
        int MAX = INT_MIN, u = -1, MIN = -1;
        for (auto &c : res) {
            if (c[1] > MAX) {
                u = c[0];
                MAX = c[1];
                MIN = c[2];
            } else if (c[1] == MAX) {
                if (c[2] < MIN) {
                    u = c[0];
                    MIN = c[2];
                }
            }
        }
        printf("G%d\n", u + 1);
        printf("%.1f %.1f\n", (double)MAX, ans((double)MIN / (double)n));
    }

    return 0;
}
