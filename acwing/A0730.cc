#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
LL a[N];

bool can(LL val) {
    for (int i = 0; i < n; ++i) {
        if (a[i] > val) val -= (LL)(a[i] - val);
        else {
            val += (LL)(val - a[i]);
            if (val < 0) return true;
        }
        if (val < 0) {
            return false;
        }
    }
    return true;
}

auto main() -> int {
    scanf("%d", &n);
    LL right = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &a[i]);
        right += a[i];
    }
    LL left = 0, lastPos = -1;
    while (left <= right) {
        LL mid = left + ((right - left) >> 1);
        if (can(mid)) {
            lastPos = mid;
            right = mid - 1;
        } else left = mid + 1;
    }
    printf("%lld\n", lastPos);
    return 0;
}