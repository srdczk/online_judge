#include <bits/stdc++.h>

using namespace std;

const int maxN = 3010;
int N, a[maxN], b[maxN], dp[maxN][maxN];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < N; ++i) scanf("%d", &b[i]);
    // record < j - 1
	vector<vector<int>> bs(N);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (b[j] < b[i]) {
                bs[i].push_back(j);
            }
        }
    }
    fill(*dp, *dp + maxN * maxN, 0);
    int res = 0;
    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j < N + 1; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = max(1, dp[i][j]);
                for (auto &k : bs[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][k + 1] + 1);
            }
            res = max(res, dp[i][j]);
        }
    }
    printf("%d\n", res);
    return 0;
}