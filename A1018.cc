#include <bits/stdc++.h>

using namespace std;
const int maxV = 510;
struct Node {
    int v, dis;
};
struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.dis > b.dis;
    }
};
priority_queue<Node, vector<Node>, cmp> q;
vector<int> pre[maxV], w(maxV), d(maxV, INT_MAX);
vector<Node> adj[maxV];
vector<int> path, tmp;
int remain = INT_MAX, need = INT_MAX;
int C, n, s, m;
void dij() {
    d[0] = 0;
    q.push(Node{0, 0});
    while (!q.empty()) {
        Node node = q.top();
        q.pop();
        for (auto &c : adj[node.v]) {
            if (d[c.v] > node.dis + c.dis) {
                d[c.v] = node.dis + c.dis;
                pre[c.v].clear();
                pre[c.v].push_back(node.v);
                q.push(Node{c.v, d[c.v]});
            } else if (d[c.v] == node.dis + c.dis) {
                pre[c.v].push_back(node.v);
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
    for (int i = 1; i < n + 1; ++i) scanf("%d", &w[i]);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back(Node{b, c});
        adj[b].push_back(Node{a, c});
    }
    dij();
    dfs(s);
    printf("%d ", need > 0 ? need : 0);
    for (int i = path.size() - 1; i > -1; --i) {
        if (i != path.size() - 1) printf("->");
        printf("%d", path[i]);
    }
    printf(" %d", remain > 0 ? remain : 0);
    printf("\n");
    return 0;
}
