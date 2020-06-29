#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], n;

void quickSort(int l, int r) {
    if (l < r) {
        int i = l - 1, j = r + 1, x = a[l + ((r - l) >> 1)];
        while (i < j) {
            do ++i; while (a[i] < x);
            do --j; while (a[j] > x);
            if (i < j) swap(a[i], a[j]);
        }
        quickSort(l, j);
        quickSort(j + 1, r);
    }
}

auto main() -> int {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    quickSort(0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}