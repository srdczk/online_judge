#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> cnt;

int main() {

    int m, n;
    scanf("%d%d", &m, &n);
    int res;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            if (cnt[x]++ == m * n / 2) res = x;
        }
    }
    printf("%d\n", res);
    return 0;
}
