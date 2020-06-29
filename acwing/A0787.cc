#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], n;

void merge(int l, int mid, int r) {
    int help[r - l + 1];
    int p = 0;
    int i = l, j = mid + 1;
    while (i < mid + 1 && j < r + 1) {
        help[p++] = a[i] < a[j] ? a[i++] : a[j++];
    }
    while (i < mid + 1) help[p++] = a[i++];
    while (j < r + 1) help[p++] = a[j++];
    p = 0;
    while (l <= r) a[l++] = help[p++];
}

void mergeSort(int l, int r) {
    if (l < r) {
        int mid = l + ((r - l) >> 1);
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, r);
    }
}

auto main() -> int {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    mergeSort(0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}