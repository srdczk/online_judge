#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 12, M = (1 << 10), K = 110;

int n, k;
vector<int> a;
int cnt[M];
vector<int> adj[M];
LL dp[N][K][M];
bool can(int i) {
    for (int j = 0; j < n; ++j) {
        if ((i & (1 << j)) && (i & (1 << (j + 1)))) return false;
    }
    return true;
}

int count(int i) {
    int res = 0;
    for (int j = 0; j < n; ++j) {
        res += (i >> j) & 1;
    }
    return res;
}

auto main() -> int {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < (1 << n); ++i) {
        if (can(i)) {
            a.push_back(i);
            cnt[i] = count(i);
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            int x = a[i], y = a[j];
            if (!(x & y) && can(x | y)) {
                adj[x].push_back(y);
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i < n + 2; ++i) {
        for (int j = k; j >= 0; --j) {
            for (auto &c : a) {
                for (auto &p : adj[c]) {
                    int cp = cnt[p];
                    if (j >= cp) {
                        dp[i][j][c] += dp[i - 1][j - cp][p];
                    }
                }
            }
        }
    }
    printf("%lld\n", dp[n + 1][k][0]);
    return 0;
}