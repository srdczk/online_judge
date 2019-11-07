#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    scanf("%d", &m);
    vector<int> a(m);
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    scanf("%d", &n);
    int h = (m + n + 1) / 2;
    int i = 0, j = 0;
    if (!n) {
        printf("%d", a[(m - 1) / 2]);
        return 0;
    }
    while (n--) {
        int x;
        scanf("%d", &x);
        while (i < m && a[i] <= x) {
            i++;
            if (i + j == h) {
                printf("%d", a[i - 1]);
                return 0;
            }
        }
        j++;
        if (i + j == h) {
            printf("%d", x);
            return 0;
        }
    }
    while (i + j < h) {
        i++;
    }
    printf("%d", a[i - 1]);
    return 0;
}
