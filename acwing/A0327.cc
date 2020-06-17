#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int M = 15, N = 15, K = 1 << 12;

const LL mod = 100000000;
int m, n;

int a[M][N];

vector<int> states[M];
LL dp[K][M];
bool can(int val, int line) {
    for (int i = 0; i < n; ++i) {
        if ((val & (1 << i)) && !a[line][i]) return false;
        if ((val & (1 << i)) && (val & (1 << (1 + i)))) return false;
    }
    return true;
}

auto main() -> int {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
        for (int k = 0; k < (1 << n); ++k) {
            if (can(k, i)) {
                states[i].push_back(k);
                if (!i) dp[k][i] = 1;
            }
        }
    }
    
    for (int i = 1; i < m; ++i) {
        for (auto &now : states[i]) {
            for (auto &last : states[i - 1]) {
                if (!(now & last)) {
                    dp[now][i] += dp[last][i - 1];
                    dp[now][i] %= mod;
                } 
            }
        }
    }
    LL res = 0;
    for (auto &state : states[m - 1]) {
        res = (res + dp[state][m - 1]) % mod;
    }
    printf("%lld\n", res);
    return 0;
}