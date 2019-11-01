#include <bits/stdc++.h>

using namespace std;

//用优先队列实现dijkstra,否则会超时

struct Node {
    int x, y;
    Node(int _x, int _y): x(_x), y(_y) {}
};
struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

const int maxV = 10010;

unordered_set<int> s;

unordered_map<int, vector<pair<int, int>>> m;

vector<int> adj[maxV], path, tmp, tp, pth;

int preP[maxV], preQ[maxV], dis[maxV];
int d[maxV], n, res = INT_MAX;



int dij(int b, int e) {
    fill(d, d + maxV, INT_MAX);
    d[b] = 0;
    q.push(pair<int, int>(b, 0));
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        if (p.first == e) break;
        int u = p.first;
        for (auto &c : m[u]) {
            int x = c.first;
            int y = c.second;
            for (int j = 0; j < adj[x].size(); ++j) {
                if (j == y) continue;
                if (d[adj[x][j]] > d[u] + abs(j - y)) {
                    d[adj[x][j]] = d[u] + abs(j - y);
                    preP[adj[x][j]] = u;
                    preQ[adj[x][j]] = x;
                    dis[adj[x][j]] = dis[u] + 1;
                    q.push(pair<int, int>(adj[x][j], d[adj[x][j]]));
                } else if (d[adj[x][j]] == d[u] + abs(j - y)) {
                    if (dis[adj[x][j]] > dis[u] + 1) {
                        preP[adj[x][j]] = u;
                        preQ[adj[x][j]] = x;
                        dis[adj[x][j]] = dis[u] + 1;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        adj[i] = vector<int>(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &adj[i][j]);
            m[adj[i][j]].push_back(pair<int, int>(i, j));
            s.insert(adj[i][j]);
        }
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        q = priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>();
        fill(preP, preP + maxV, -1);
        fill(preQ, preQ + maxV, -1);
        fill(dis, dis + maxV, 0);
        int b, e;
        scanf("%d%d", &b, &e);
        dij(b, e);
        printf("%d\n", d[e]);
        stack<int> sa, sb;
        int p = e;
        while (preP[p] != -1) {
            sa.push(p);
            sb.push(preQ[p]);
            p = preP[p];
        }
        p = b;
        while (!sa.empty()) {
            printf("Take Line#%d from %04d to %04d.\n", sb.top() + 1, b, sa.top());
            b = sa.top();
            sa.pop();
            sb.pop();
        }

    }
    return 0;
}
