#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, x, y;
    scanf("%d", &n);
    unordered_set<int> a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            a[i].insert(x);
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &x, &y);
        int cnt = 0;
        for (auto &c : a[x - 1]) {
            if (a[y - 1].count(c)) cnt++;
        }
        printf("%.1f%\n", (double)(cnt) / (a[x - 1].size() + a[y - 1].size() - cnt) * 100.0);
    }
    return 0;
}
