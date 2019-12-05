#include <bits/stdc++.h>

using namespace std;
const int maxV = 510;
struct Node {
    int v, dis;
};
// 最小堆
struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.dis > b.dis;
    }
};

priority_queue<Node, vector<Node>, cmp> q;

int n, m, s, e;

int d[maxV], w[maxV], hs[maxV], num[maxV];
vector<Node> adj[maxV];

void dij() {
    q.push(Node{s, 0});
    fill(num, num + maxV, 0);
    fill(d, d + maxV, INT_MAX);
    fill(hs, hs + maxV, 0);
    hs[s] = w[s];
    num[s] = 1;
    d[s] = 0;
    while (!q.empty()) {
        Node node = q.top();
        if (node.v == e) return;
        q.pop();
        for (auto &c : adj[node.v]) {
            if (d[c.v] > node.dis + c.dis) {
                num[c.v] = num[node.v];
                hs[c.v] = w[c.v] + hs[node.v];
                d[c.v] = node.dis + c.dis;
                q.push(Node{c.v, d[c.v]});
            } else if (d[c.v] == node.dis + c.dis) {
                num[c.v] += num[node.v];
                hs[c.v] = max(w[c.v] + hs[node.v], hs[c.v]);
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
