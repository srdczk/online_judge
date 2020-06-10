#include <bits/stdc++.h>

using namespace std;

const int maxV = 20;

struct Node {
    int x, y;
    Node(): x(-1), y(-1) {}
    Node(int x_, int y_): x(x_), y(y_) {}
};

int a[maxV][maxV];
Node ns[maxV][maxV];

int main() {
    int n;
    scanf("%d", &n);
    fill(*a, *a + maxV * maxV, 0);
    int p = -1, q = -1, r = -1;
    while (p || q || r) {
        scanf("%d%d%d", &p, &q, &r);
        if (!p || !q) break;
        a[p - 1][q - 1] = r;
    }
    int dp[maxV][maxV];
    fill(*dp, *dp + maxV * maxV, 0);
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; ++i) {
        ns[i][0] = Node(i - 1, 0);
        ns[0][i] = Node(0, i - 1);
        dp[i][0] = dp[i - 1][0] + a[i][0];
        dp[0][i] = dp[0][i - 1] + a[0][i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = a[i][j] + dp[i - 1][j];
                ns[i][j] = Node(i - 1, j);
            } else {
                dp[i][j] = a[i][j] + dp[i][j - 1];
                ns[i][j] = Node(i, j - 1);
            }

        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    auto res = dp[n - 1][n - 1];
    cout << res << "\n";
    a[n - 1][n - 1] = 0;
    int x = ns[n - 1][n - 1].x, y = ns[n - 1][n - 1].y;
    while (x != -1 && y != -1) {
        a[x][y] = 0;
        p = ns[x][y].x;
        q = ns[x][y].y;
        x = p;
        y = q;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        dp[0][i] = dp[0][i - 1] + a[0][i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];

        }
    }
    cout << dp[n - 1][n - 1] << "\n";
    printf("%d\n", res + dp[n - 1][n - 1]);
    return 0;
}
