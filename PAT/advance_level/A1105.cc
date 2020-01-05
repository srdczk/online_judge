#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    vector<int> a(k);
    for (int i = 0; i < k; ++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end(), greater<int>());
    int m, n;
    for (int i = (int)(sqrt(k)); i > 0; --i) {
        if (!(k % i)) {
            m = i;
            break;
        }
    }
    n = k / m;
    if (n > m) swap(m, n);
    vector<vector<int>> res(m, vector<int>(n));
    int cnt = 0, x = 0, y = 0, dir = 0, p1 = 1, p2 = 0, p3 = 0, p4 = 0;
    while (cnt < k) {

        res[x][y] = a[cnt++];
        if (!dir) {
            if (y == n - 1 - p2) {
                p2++;
                x++;
                dir = 1;
            } else y++;
        } else if (dir == 1) {
            if (x == m - 1 - p3) {
                p3++;
                y--;
                dir = 2;
            } else x++;
        } else if (dir == 2) {
            if (y == p4) {
                p4++;
                x--;
                dir = 3;
            } else y--;
        } else {
            if (x == p1) {
                p1++;
                y++;
                dir = 0;
            } else x--;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) printf(" ");
            printf("%d", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
