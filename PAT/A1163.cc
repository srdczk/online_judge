#include <bits/stdc++.h>

using namespace std;
const int maxV = 1010;
struct Node {
    int v, dis;
};
vector<Node> adj[maxV];
int n, m;
int d[maxV], vis[maxV];
bool isDij(const vector<int> &a) {
    fill(d, d + maxV, INT_MAX);
    fill(vis, vis + maxV, false);
    d[a[0] - 1] = 0;
    for (int i = 0; i < n; ++i) {
        int MIN = INT_MAX, u = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u != a[i] - 1) {
            if (!vis[a[i] - 1] && d[a[i] - 1] == d[u]) {
                u = a[i] - 1;
            } else return 0;
        }
        vis[u] = 1;
        for (auto &c : adj[u]) {
            if (!vis[c.v] && d[c.v] > d[u] + c.dis) d[c.v] = d[u] + c.dis;
        }
    }
    return 1;
}


int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a - 1].push_back(Node{b - 1, c});
        adj[b - 1].push_back(Node{a - 1, c});
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        if (isDij(a)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}