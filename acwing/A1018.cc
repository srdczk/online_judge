#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i < n; ++i) {
        a[0][i] += a[0][i - 1];
        a[i][0] += a[i - 1][0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            a[i][j] += min(a[i][j - 1], a[i - 1][j]);
        }
    }
    printf("%d\n", a[n - 1][n - 1]);
    return 0;
}
