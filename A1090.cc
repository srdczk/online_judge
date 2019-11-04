#include <bits/stdc++.h>

using namespace std;

const int maxV = 100010;

int n, vis[maxV];
double p, r;

vector<int> adj[maxV];

struct Node {
    double val;
    int c;
    Node(double v, int _c): val(v), c(_c) {}
};



Node bfs(int root) {
    fill(vis, vis + maxV, -1);
    int k = 0, cnt = 1;
    queue<int> q;
    q.push(root);
    vis[root] = 0;
    while (!q.empty()) {
        root = q.front();
        q.pop();
        for (auto &c : adj[root]) {
            if (vis[c] == -1) {
                vis[c] = vis[root] + 1;
                if (vis[c] > k) {
                    k = vis[c];
                    cnt = 1;
                } else if (vis[c] == k) {
                    cnt++;
                }
                q.push(c);
            }
        }
    }
    return Node(pow(1.0 + r / 100.0, k) * p, cnt);
}

int main() {
    scanf("%d%lf%lf", &n, &p, &r);
    int root;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x == -1) root = i;
        else adj[x].push_back(i);
    }
    Node node = bfs(root);
    printf("%.2f %d\n", node.val, node.c);
    //cout << node.val << " " << node.c << endl;
    return 0;
}
