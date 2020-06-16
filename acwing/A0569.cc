#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod = 1000000007;
const int N = 2010;

int ps[N], pws[N], cnt = 0;
bool pd[N];

void getPrime(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!pd[i]) {
            ps[cnt++] = i;
            for (int j = 2; j * i <= n; ++j) pd[i * j] = true;
        }
    }
}

int get(int n, int p) {
    int res = 0;
    while (n) {
        res += (n /= p);
    }
    return res;
}

auto main() -> int {
    int n, s;
    scanf("%d%d", &n, &s);
    fill(pd, pd + N, false);
    if (s > n) {
        printf("0\n");
        return 0;
    }
    getPrime(n);
    for (int i = 0; i < cnt; ++i) {
        pws[i] = get(n, ps[i]) - get(s, ps[i]) - get(n - s, ps[i]);
    }
    LL res = 1;
    for (int i = 0; i < cnt; ++i) {
        while (pws[i]--) res = (LL)res * (LL)ps[i] % mod;
    }
    for (int i = 0; i < n - s; ++i)
        res = (LL)res * (LL)2 % mod;
    printf("%lld\n", res);
    return 0;
}