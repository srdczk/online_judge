#include <bits/stdc++.h>

using namespace std;
const int maxV = 210;
struct Node {
    int v, dis;
};
struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.dis > b.dis;
    }
};
priority_queue<Node, vector<Node>, cmp> q;
unordered_map<string, int> sm;
unordered_map<int, string> im;

int n, m;
vector<Node> adj[maxV];
int w[maxV], d[maxV], pre[maxV], num[maxV], hs[maxV], level[maxV];

void dij() {
    fill(d, d + maxV, INT_MAX);
    fill(pre, pre + maxV, -1);
    fill(num, num + maxV, 0);
    hs[0] = 0;
    d[0] = 0;
    num[0] = 1;
    level[0] = 0;
    q.push(Node{0, 0});
    while (!q.empty()) {
        Node node = q.top();
        q.pop();
        for (auto &c : adj[node.v]) {
            if (d[c.v] > node.dis + c.dis) {
                d[c.v] = node.dis + c.dis;
                num[c.v] = num[node.v];
                level[c.v] = level[node.v] + 1;
                pre[c.v] = node.v;
                hs[c.v] = w[c.v] + hs[node.v];
                q.push(Node{c.v, d[c.v]});
            } else if (d[c.v] == node.dis + c.dis) {
                num[c.v] += num[node.v];
                if (hs[c.v] < w[c.v] + hs[node.v]) {
                    pre[c.v] = node.v;
                    level[c.v] = level[node.v] + 1;
                    hs[c.v] = w[c.v] + hs[node.v];
                } else if (hs[c.v] == w[c.v] + hs[node.v]) {
                    if (level[c.v] > level[node.v] + 1) {
                        level[c.v] = level[node.v] + 1;
                        pre[c.v] = node.v;
                    }
                }
            }
        }
    }
}

int main() {
    char x[10], y[10];
    scanf("%d%d", &n, &m);
    scanf("%s", x);
    sm[x] = 0;
    im[0] = x;
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%s%d", x, &p);
        sm[x] = i;
        im[i] = x;
        w[i] = p;
    }
    while (m--) {
        int p;
        scanf("%s%s%d", x, y, &p);
        adj[sm[x]].push_back(Node{sm[y], p});
        adj[sm[y]].push_back(Node{sm[x], p});
    }
    dij();
    int k = sm["ROM"];
    printf("%d %d %d %d\n", num[k], d[k], hs[k], hs[k] / level[k]);
    stack<int> st;
    while (k != -1) {
        st.push(k);
        k = pre[k];
    }
    int cnt = 0;
    while (!st.empty()) {
        if (cnt++) printf("->");
        printf("%s", im[st.top()].data());
        st.pop();
    }
    printf("\n");
    return 0;
}
