#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n, a[N];
auto main() -> int {
    scanf("%d", &n);
    int sum = 0, res = INT_MIN, resB = -1, resE = -1, b, e;
    bool start = true;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (start) {
            b = a[i];
            e = a[i];
            start = false;
        }
        sum += a[i];
        e = a[i];
        if (sum > res) {
            res = sum;
            resB = b;
            resE = e;
        }
        if (sum < 0) {
            sum = 0;
            start = true;
        }
    }
    if (res < 0) {
        printf("0 %d %d\n", a[0], a[n - 1]);
    } else printf("%d %d %d\n", res, resB, resE);
    return 0;
}