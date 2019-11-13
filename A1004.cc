#include <bits/stdc++.h>

using namespace std;

const int maxV = 110;

int n, m;

vector<int> adj[maxV];

int level[maxV];

void bfs() {
    int cnt = 0;
    int curLevel = 0, curCount = 0;
    fill(level, level + maxV, -1);
    level[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int root = q.front();
        q.pop();
        if (level[root] > curLevel) {
            if (cnt++) printf(" ");
            printf("%d", curCount);
            curLevel = level[root];
            curCount = 0;
        }
        if (!adj[root].size()) curCount++;
        for (auto &c : adj[root]) {
            level[c] = level[root] + 1;
            q.push(c);
        }
    }
    if (cnt++) printf(" ");
    printf("%d\n", curCount);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, k;
        scanf("%d%d", &a, &k);
        while (k--) {
            int c;
            scanf("%d", &c);
            adj[a].push_back(c);
        }
    }
    bfs();
    return 0;
}