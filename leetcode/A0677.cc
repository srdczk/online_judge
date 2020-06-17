#include <bits/stdc++.h>

using namespace std;

int a[] = {64, 16, 4, 1};

auto cnt(int m) -> int {
    int i = 0, res = 0;
    while (m) {
        if (m >= a[i]) {
            int q = m / a[i];
            res += q;
            m -= q * a[i];
        }
        i++;
    }
    return res;
}

auto main() -> int {
    int n;
    scanf("%d\n", &n);
    printf("%d\n", cnt(1024 - n));
    return 0;
}