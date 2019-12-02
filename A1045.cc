#include <bits/stdc++.h>

using namespace std;

int maxLen(const vector<int> &a, int i, const vector<int> &b, int j) {
    if (i == a.size() || j == b.size()) return 0;
    if (a[i] == b[j]) {
        return max(maxLen(a, i + 1, b, j + 1), maxLen(a, i, b, j + 1)) + 1;
    } else return max(maxLen(a, i + 1, b, j + 1), maxLen(a, i, b, j + 1));
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d", &n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = a.size() - 1; i > -1; --i) {
        for (int j = b.size() - 1; j > -1; --j) {
            if (a[i] == b[j]) dp[i][j] = max(dp[i][j + 1], dp[i + 1][j + 1]) + 1;
            else dp[i][j] = max(dp[i][j + 1], dp[i + 1][j + 1]);
        }
    }
    printf("%d\n", dp[0][0]);
    return 0;
}
