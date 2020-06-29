#include <bits/stdc++.h>

using namespace std;


unordered_map<int, unordered_map<int, int>> last;
unordered_map<int, unordered_map<int, int>> now;

int res = 0;
auto main() -> int {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int m, x, y;
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d", &x, &y);
            if (last.count(x) && last[x].count(y) && last[x][y] == i - 1) {
                now[x][y] = now[x][y] + 1;
                res = max(res, now[x][y]);
            } else {
                now[x][y] = 1;
            }
            last[x][y] = i;
        }
    }
    printf("%d\n", res);
    return 0;
}