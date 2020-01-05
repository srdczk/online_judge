#include <bits/stdc++.h>

using namespace std;
const int maxV = 10010;

unordered_set<int> adj[maxV];

bool pd(const vector<int> &a) {
    for (int i = 1; i < a.size(); ++i) {
        if (!adj[a[i - 1]].count(a[i])) return 0;
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        int l;
        scanf("%d", &l);
        vector<int> a(l);
        unordered_set<int> s;
        for (int i = 0; i < l; ++i) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }
        if (s.size() != n || a[0] != a[a.size() - 1] || a.size() != n + 1) printf("NO\n");
        else if (pd(a)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}