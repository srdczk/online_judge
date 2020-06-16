#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l == r) {
            printf("%d\n", l % 2 ? -l : l);
        } else if (r % 2) {
            if (l % 2) {
                printf("%d\n", -(l + r) / 2);
            } else {
                printf("%d\n", (l + r - 1) / 2 - r);
            }
        } else {
            if (l % 2) {
                printf("%d\n", (r - l + 1) / 2);
            } else {
                printf("%d\n", (l + r) / 2);
            }
        }
    }
    return 0;
}