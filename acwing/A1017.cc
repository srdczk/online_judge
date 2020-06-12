#include <bits/stdc++.h>

using namespace std;
const int N = 110;

int a[N], b[N];

int res(int p[], int n) {
    if (n < 2) return n;
    int pos = 0;
    for (int i = 1; i < n; ++i) {
        int left = 0, right = pos, lastPos = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (p[mid] < p[i]) {
                lastPos = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        p[lastPos + 1] = p[i];
        pos = max(pos, lastPos + 1);
    }
    return pos + 1;
}

int main() {
    int k, n;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            b[n - 1 - i] = a[i];
        }
        if (n < 2) {
            printf("%d\n", n);
            continue;
        } else {
            printf("%d\n", max(res(a, n), res(b, n)));
        }
    }
    return 0;
}