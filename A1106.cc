#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;

struct Node {
    double val;
    int cnt;
    Node(double v, int c): val(v), cnt(c) {}
};

vector<int> adj[maxV];

vector<int> vis(maxV, -1);

int n;
double p, r;

Node bfs(int root) {
    int MIN = INT_MAX, cnt = 0;
    queue<int> q;
    q.push(root);
    vis[root] = 0;
    while (!q.empty()) {
        root = q.front();
        q.pop();
        if (!adj[root].size()) {
            if (MIN > vis[root]) {
                MIN = vis[root];
                cnt = 1;
            } else if (vis[root] == MIN){
                cnt++;
            }
        }
        for (auto &c : adj[root]) {
            if (vis[c] == -1) {
                vis[c] = vis[root] + 1;
                q.push(c);
            }
        }
    }
    //cout << MIN << " " << cnt << endl;
    return Node(pow(1 + r / 100.0, MIN) * p, cnt);
}

int main() {
    scanf("%d%lf%lf", &n, &p, &r);
    vector<int> cnt(n, 0);
    int root;
    for (int i = 0; i < n; ++i) {
       int k;
       scanf("%d", &k);
       while (k--) {
           int x;
           scanf("%d", &x);
           adj[i].push_back(x);
           cnt[x]++;
       }
    }
    for (int i = 0; i < n; ++i) {
        if (!cnt[i]) {
            root = i;
            break;
        }
    }
    Node node = bfs(root);
    //cout << node.val << " " << node.cnt << endl;
    printf("%.4f %d\n", node.val, node.cnt);
    return 0;
}
