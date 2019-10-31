#include <bits/stdc++.h>

using namespace std;

const int maxV = 210;

struct Node {
    int v, dis;
    Node() {}
    Node(int _v, int d): v(_v), dis(d) {}
};

vector<int> hs(maxV, 0), pre(maxV, -1), d(maxV, INT_MAX), h(maxV, 0), num(maxV, 0), dis(maxV, INT_MAX);

vector<Node> adj[maxV];

bool vis[maxV];

int n, m;
string b;

unordered_map<int, string> im;
unordered_map<string, int> sm;

void dij() {
    fill(vis, vis + maxV, 0);
    d[0] = 0;
    dis[0] = 0;
    num[0] = 1;
    for (int i = 0; i < n; ++i) {
        int MIN = INT_MAX, u = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) break;
        vis[u] = 1;
        for (auto &c : adj[u]) {
            if (!vis[c.v] && d[c.v] > d[u] + c.dis) {
                d[c.v] = d[u] + c.dis;
                h[c.v] = h[u] + hs[c.v];
                num[c.v] = num[u];
                pre[c.v] = u;
                dis[c.v] = dis[u] + 1;
            } else if (!vis[c.v] && d[c.v] == d[u] + c.dis) {
                num[c.v] += num[u];
                if (h[c.v] < h[u] + hs[c.v]) {
                    h[c.v] = h[u] + hs[c.v];
                    pre[c.v] = u;
                    dis[c.v] = dis[u] + 1;
                } else if (h[c.v] == h[u] + hs[c.v]) {
                    if (dis[c.v] > dis[u] + 1) {
                        pre[c.v] = u;
                        dis[c.v] = dis[u] + 1;
                    }
                }
            }
        }
    }
    stack<string> s;
    int p = sm["ROM"];
    while (p != -1) {
        s.push(im[p]);
        p = pre[p];
    }
    printf("%d %d %d %d\n", num[sm["ROM"]], d[sm["ROM"]], h[sm["ROM"]], h[sm["ROM"]] / dis[sm["ROM"]]);
    int cnt = 0;
    while (!s.empty()) {
        if (cnt++) cout << "->";
        cout << s.top();
        s.pop();
    }
    printf("\n");

}

int main() {
    cin >> n >> m >> b;
    im[0] = b;
    sm[b] = 0;
    for (int i = 1; i < n; ++i) {
        string x;
        int y;
        cin >> x >> y;
        im[i] = x;
        sm[x] = i;
        hs[i] = y;
    }

    while (m--) {
        string x, y;
        int z;
        cin >> x >> y >> z;
        adj[sm[x]].push_back(Node(sm[y], z));
        adj[sm[y]].push_back(Node(sm[x], z));
    }

    dij();

    return 0;
}
