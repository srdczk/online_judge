#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;

vector<int> adj[maxV];
int cls[maxV], n, m;
bool vis[maxV];

bool can() {
    fill(vis, vis + maxV, 0);
    for (int i = 0; i < n; ++i) {
        for (auto &c : adj[i]) {
            if (cls[i] == cls[c]) return 0;
        }
    }
    return 1;
}


int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &cls[i]);
            s.insert(cls[i]);
        }
        if (can()) printf("%d-coloring\n", s.size());
        else printf("No\n");
    }
    return 0;
}
