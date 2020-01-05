#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;
struct Node {
    int x, y;
};

struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.y > b.y;
    }
};
priority_queue<Node, vector<Node>, cmp> q;
unordered_map<int, vector<Node>> m;

Node pre[maxV];
int level[maxV], d[maxV];
vector<int> adj[maxV];
int s, e;
void dij() {
    d[s] = 0;
    level[s] = 0;
    q.push(Node{s, 0});
    while (!q.empty()) {
        Node node = q.top();
        q.pop();
        for (auto &c : m[node.x]) {
            // c.x, c.y
            for (int i = 0; i < adj[c.x].size(); ++i) {
                if (d[adj[c.x][i]] > node.y + abs(c.y - i)) {
                    d[adj[c.x][i]] = node.y + abs(c.y - i);
                    q.push(Node{adj[c.x][i], node.y + abs(c.y - i)});
                    pre[adj[c.x][i]] = Node{c.x, node.x};
                    level[adj[c.x][i]] = level[node.x] + 1;
                } else if (d[adj[c.x][i]] == node.y + abs(c.y - i)) {
                    if (level[adj[c.x][i]] > level[node.x] + 1) {
                        pre[adj[c.x][i]] = Node{c.x, node.x};
                        level[adj[c.x][i]] = level[node.x] + 1;
                    }
                }
            }
        }
    }
}
int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        adj[i] = vector<int>(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &adj[i][j]);
            m[adj[i][j]].push_back(Node{i, j});
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &s, &e);
        fill(d, d + maxV, INT_MAX);
        fill(pre, pre + maxV, Node{-1, -1});
        dij();
        printf("%d\n", d[e]);
        vector<Node> ns;
        Node node{-1, e};
        while (!(node.x == -1 && node.y == -1)) {
            ns.push_back(node);
            node = pre[node.y];
        }
        for (int i = ns.size() - 1; i > 0; --i) {
            printf("Take Line#%d from %04d to %04d.\n", ns[i].x + 1, ns[i].y, ns[i - 1].y);
        }
    }
    return 0;
}
