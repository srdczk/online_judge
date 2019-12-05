#include <bits/stdc++.h>

using namespace std;

const int maxV = 1010;

int level[maxV];

int n, l, k, x;

vector<int> adj[maxV];

int res(int a) {
    int cnt = 0;
    fill(level, level + maxV, INT_MAX);
    level[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        if (level[a = q.front()] == l) return cnt;
        q.pop();
        for (auto &c : adj[a]) {
            if (level[c] == INT_MAX) {
                level[c] = level[a] + 1;
                cnt++;
                q.push(c);
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            adj[x].push_back(i + 1);
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &x);
        printf("%d\n", res(x));
    }
    return 0;
}
