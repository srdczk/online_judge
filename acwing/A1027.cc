#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int a[N][N];

// f(i1, j1, i2, j2) -> represent, while(i1 + j1 == i2 + j2)
int f[2 * N - 1][N][N];

int main() {
    int n;
    scanf("%d", &n);
    fill(*a, *a + N * N, 0);
    int p, q, r;
    while (true) {
        scanf("%d%d%d", &p, &q, &r);
        if (!p && !q && !r) break;
        a[p - 1][q - 1] = r;
    }
    // i + j max (2 * n - 1)
    for (int k = 0; k < 2 * n - 1; ++k) {
        for (int i = 0; i < k + 1; ++i) {
            for (int j = 0; j < k + 1; ++j) {
                if (!k) f[k][i][j] = a[0][0];
                else {
                    int x = !i || j == k ? INT_MIN : f[k - 1][i - 1][j] + a[i][k - i] + (i == j ? 0 : a[j][k - j]);
                    int y = !j || i == k ? INT_MIN : f[k - 1][i][j - 1] + a[i][k - i] + (i == j ? 0 : a[j][k - j]);
                    int w = !i || !j ? INT_MIN : f[k - 1][i - 1][j - 1] + a[i][k - i] + (i == j ? 0 : a[j][k - j]);
                    int z = i == k || j == k ? INT_MIN : f[k - 1][i][j] + a[i][k - i] + (i == j ? 0 : a[j][k - j]);
                    f[k][i][j] = max(max(x, y), max(w, z));
                }
            }
        }
    }
    printf("%d\n", f[2 * n - 2][n - 1][n - 1]);
    return 0;
}