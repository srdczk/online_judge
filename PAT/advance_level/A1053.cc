#include <bits/stdc++.h>

using namespace std;
const int maxV = 110;

vector<int> adj[maxV];
vector<int> w, f, h;

vector<vector<int>> res;

void bfs(int root, int t) {
    queue<int> q;
    q.push(root);
    h[root] = w[root];
    while (!q.empty()) {
        root = q.front();
        q.pop();
        if (h[root] == t && !adj[root].size()) {
            stack<int> s;
            int p = root, cnt = 0;
            while (p != -1) {
                s.push(w[p]);
                p = f[p];
            }
            vector<int> a;
            while (!s.empty()) {
                a.push_back(s.top());
                s.pop();
            }
            res.push_back(a);
        }
        for (auto &c : adj[root]) {
            h[c] = h[root] + w[c];
            q.push(c);
        }
    }
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    w = vector<int>(n), f = vector<int>(n, -1), h = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
    for (int i = 0; i < m; ++i) {
        int k, c;
        scanf("%d%d", &k, &c);
        while (c--) {
            int x;
            scanf("%d", &x);
            adj[k].push_back(x);
            f[x] = k;
        }
    }
    int root;
    for (int i = 0; i < n; ++i) {
        if (f[i] == -1) {
            root = i;
            break;
        }
    }

    bfs(root, q);

    sort(res.begin(), res.end(), [](const vector<int> &a, const vector<int> &b) {
            for (int i = 0; i < min(a.size(), b.size()); ++i) {
                if (a[i] != b[i]) return a[i] > b[i];
            }
            return false;
         });
    for (auto &c : res) {
        for (int i = 0; i < c.size(); ++i) {
            if (i) printf(" ");
            printf("%d", c[i]);
        }
        printf("\n");
    }
    return 0;
}
