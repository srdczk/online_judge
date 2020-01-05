#include <bits/stdc++.h>

using namespace std;

struct Node {
    int p, w, d;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Node> a(n);
    vector<int> b(n), v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].w);
        a[i].p = 0;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        q.push(b[i]);
        v[i] = i;
    }
    while (q.size() > 1) {
        queue<int> p;
        while (!q.empty()) {
            int j = -1, u = -1;
            for (int i = 0; i < m; ++i) {
                if (q.empty()) break;
                int x = q.front();
                q.pop();
                if (a[x].w > j) {
                    j = a[x].w;
                    u = x;
                }
            }
            p.push(u);
            a[u].p++;
        }
        q = p;
    }
    sort(v.begin(), v.end(), [=](int x, int y) {
            return a[x].p > a[y].p;
         });
    int x = a[v[0]].p, y = 1;
    for (int i = 0; i < n; ++i) {
        if (a[v[i]].p != x) {
            x = a[v[i]].p; 
            y = i + 1;
        }
        a[v[i]].d = y;
    }
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", a[i].d);
    }
    printf("\n");
    return 0;
}
