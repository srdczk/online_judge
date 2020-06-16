#include <bits/stdc++.h>

using namespace std;

int n, m;

auto res() -> int {
    // find the last m >= n
    int ret = 0;
    while (m) {
        int lastPos;
        if (m >= n) lastPos = n;
        else lastPos = m;
        int cnt = m / lastPos;
        ret += cnt;
        m -= cnt * lastPos;
    }
    return ret;
}

auto main() -> int {
    scanf("%d%d", &n, &m);
    printf("%d\n", res());
    return 0;
}