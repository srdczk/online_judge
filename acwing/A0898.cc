#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    if (!n) {
        printf("0\n");
        return 0;
    }
    if (n == 1) {
        printf("%d\n", a[0][0]);
        return 0;
    }
    int res = INT_MIN;
    for (int i = 1; i < a.size(); ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (!j) a[i][j] += a[i - 1][j];
            else if (j == i) a[i][j] += a[i - 1][j - 1];
            else a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
            if (i == a.size() - 1) res = max(res, a[i][j]);
        }
    }
    printf("%d\n", res);
    return 0;
}
