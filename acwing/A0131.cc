#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL N = 100010;

LL a[N], leftMin[N], rightMin[N];

int main() {
    LL n;
    while (scanf("%ld", &n), n) {
        for (int i = 0; i < n; ++i)
            scanf("%ld", &a[i]);
        leftMin[0] = -1;
        for (int i = 1; i < n; ++i) {
            LL k = i - 1;
            while (k > -1 && a[k] >= a[i])
                k = leftMin[k];
            leftMin[i] = k;
        }
        rightMin[n - 1] = n;
        for (int i = n - 2; i > -1; --i) {
            LL k = i + 1;
            while (k < n && a[k] >= a[i])
                k = rightMin[k];
            rightMin[i] = k;
        }
        LL res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, (LL)(a[i]) * (rightMin[i] - leftMin[i] - 1));
        }
        printf("%lld\n", res);
    }
    return 0;
}