#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], leftMin[N], n, x;

int s[N], tt = 0;

void itSolve() {
    leftMin[0] = -1;
    for (int i = 1; i < n; ++i) {
        int k = i - 1;
        while (k > -1 && a[k] >= a[i]) k = leftMin[k];
        leftMin[i] = k;
    }
}

void stSolve() {
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        while (tt && s[tt] >= a[i]) --tt;
        if (!tt) printf("-1");
        else printf("%d", s[tt]);
        s[++tt] = a[i];
    }
    
}

auto main() -> int {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        while (tt && s[tt] >= x) --tt;
        if (!tt) printf("-1 ");
        else printf("%d ", s[tt]);
        s[++tt] = x;
    }
    // }
    printf("\n");
    return 0;
}