#include <bits/stdc++.h>

using namespace std;
const int maxV = 510;

vector<int> adj[maxV];
bool vis[maxV];
int cnt = 0;

void dfs(int i) {
    cnt++;
    vis[i] = true;
    for (auto &c : adj[i]) {
        if (!vis[c]) {
            dfs(c);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n, 0);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x - 1]++;
        a[y - 1]++;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    fill(vis, vis + maxV, 0);
    dfs(0);
    if (cnt != n) {
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
        printf("Non-Eulerian\n");
    } else {
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            if (a[i] % 2) cnt++;
            printf("%d", a[i]);
        }
        printf("\n");
        if (!cnt) printf("Eulerian\n");
        else if (cnt == 2) printf("Semi-Eulerian\n");
        else printf("Non-Eulerian\n");
    }

    return 0;
}
